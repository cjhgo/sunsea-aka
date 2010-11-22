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

#define N 1024

FILE *fp1;
FILE *fp2;
int count = 0;

/* 引入互斥量，并对其进行初始化 */
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

/* 对文件读写操作 */
int my_copy(const char *s, FILE *fp1_, FILE *fp2_)
{
	int ret = -1;
	pthread_t tid;
	char buf[N];

	memset(buf, '\0', sizeof(buf));
	ret = fread(buf, N, 1, fp1_);
//	fwrite(buf, strlen(buf), 1, fp2_);		//读文本文件
	fwrite(buf, N, 1, fp2_);			//读图片,sizeof(buf) == N

	tid = pthread_self();
	printf("%s id: %u, has done!\n", s, (unsigned int)tid); 
//	printf("buf = %s\n", buf); 

	return ret;
}

/* 新线程使用的函数 */
void *thr_fn(void *arg)
{
	FILE *fp1_;
	FILE *fp2_;
	int ret = -1;

	while(ret != 0)
	{
		fp1_ = fp1;
		fp2_ = fp2;

		pthread_mutex_lock(&counter_mutex);
	
		count = count + N;

		pthread_mutex_unlock(&counter_mutex);

		fseek(fp1_, count - N, 0);
		fseek(fp2_, count - N, 0);
		
		ret = my_copy(arg, fp1_, fp2_);
	}

	return NULL;
}

/* 主函数 */
int main(int argc, char* argv[])
{
	int ret;
	int err;
	pthread_t ntid1, ntid2, ntid3;

	fp1 = fopen("1", "rb");
	fp2 = fopen("2", "wb");

	/* 判断是否打开成功 */
	if(NULL == fp1)
	{
		perror("open 1");
	}
	if(NULL == fp2)
	{
		perror("open 2");
	}
 	
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
  /* 	err = pthread_create(&ntid3, NULL, thr_fn, "thread 3");
	if(err != 0)
	{
		fprintf(stderr, "can't create new thread 3: %s", strerror(err));
		exit(1);
	}
*/
	pthread_join(ntid1, NULL);
	pthread_join(ntid2, NULL);
//	pthread_join(ntid3, NULL);


	fclose(fp1);
	fclose(fp2);

	return 0; 
}
