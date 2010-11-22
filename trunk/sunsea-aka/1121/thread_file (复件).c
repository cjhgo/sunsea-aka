/*
 * =====================================================================================
 *
 *       Filename:  thread_file.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2010年11月20日 12时08分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zsx (), zsx_happy@126.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define N 5

int count = 0;

/* 引入互斥量，并对其进行初始化 */
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

/* do_count */
int do_count(void)
{
	int n;

	pthread_mutex_lock(&counter_mutex);

	count = count + N;

	n = count -N;

	pthread_mutex_unlock(&counter_mutex);

	return n;
}

/* 对文件读写操作 */
void my_copy(const char *s, FILE **fp1, FILE **fp2)
{
	int ret = -1;
	int n;
	pthread_t tid;
	char buf[N];

	while(ret != 0)
	{
		tid = pthread_self();
		printf("%s id: %u, has done!\n", s, (unsigned int)tid); 

		n = do_count();

		fseek(*fp1, n, SEEK_SET);
		fseek(*fp2, n, SEEK_SET);

		memset(buf, '\0', sizeof(buf));
		ret = fread(buf, 1, N, *fp1);
 		fwrite(buf, 1, ret, *fp2);
	}

	return;
}

/* 打开文件 */
void open_file(FILE **fp1, FILE **fp2)
{
	*fp1 = fopen("1", "rb");
	*fp2 = fopen("2", "rb+");

	if(NULL == *fp1)
	{
		perror("open file 1");
		exit(1);
	}
	if(NULL == *fp2)
	{
		perror("open file 2");
		exit(1);
	}

	return;
}

/* 关闭文件 */
void close_file(FILE **fp1, FILE **fp2)
{
	fclose(*fp1);
	fclose(*fp2);

	return;
}

/* 新线程使用的函数 */
void *thr_fn(void *arg)
{
	FILE *fp1;
	FILE *fp2;

	open_file(&fp1, &fp2);

	my_copy(arg, &fp1, &fp2);

	close_file(&fp1, &fp2);

	return NULL;
}

/* 主函数 */
int main(int argc, char* argv[])
{
	int err;
	FILE *fp;
	pthread_t ntid1, ntid2, ntid3;

	fp = fopen("2", "w");
	if(NULL == fp)
	{
		perror("create file 2 error!");
		exit(1);
	}

	fclose(fp);
	
	/* new thread 1 */
 	err = pthread_create(&ntid1, NULL, thr_fn, "thread 1");
	if(err != 0)
	{
		fprintf(stderr, "can't create new thread 1: %s", strerror(err));
		exit(1);
	}
 
	/* new thread 2 */
  	err = pthread_create(&ntid2, NULL, thr_fn, "thread 2");
	if(err != 0)
	{
		fprintf(stderr, "can't create new thread 2: %s", strerror(err));
		exit(1);
	}

	/* new thread 3 */
    	err = pthread_create(&ntid3, NULL, thr_fn, "thread 3");
	if(err != 0)
	{
		fprintf(stderr, "can't create new thread 3: %s", strerror(err));
		exit(1);
	}

	pthread_join(ntid1, NULL);
	pthread_join(ntid2, NULL);
	pthread_join(ntid3, NULL);

	printf("copy finish!\n"); 

	return 0; 
}
