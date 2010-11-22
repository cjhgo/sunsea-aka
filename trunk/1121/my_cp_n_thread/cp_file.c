/*
 * =====================================================================================
 *
 *       Filename:  copy_file.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2010年11月21日 16时21分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zsx (), zsx_happy@126.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define N 1024

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
int count = 0;
char cp_from[N] = {0};
char cp_to[N] = {0};

/* 打开文件 */
void open_file(FILE **fp1, FILE **fp2)
{
	*fp1 = fopen(cp_from, "r");
	if(NULL == *fp1)
	{
		printf("open file %s error\n", cp_from);
		exit(1);
	}

	*fp2 = fopen(cp_to, "r+");
	if(NULL == *fp2)
	{
		printf("open file %s error\n", cp_to);
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

/* 输出线程id */
void printid(void)
{
	pthread_t tid;

	tid = pthread_self();

	printf("Thread id: %u\n", (unsigned int)tid);

	return;
}

/* 获取文件指针偏移量 */
int do_count(void)
{
	int n;

	pthread_mutex_lock(&count_mutex);
	count = count + N;
	n = count - N;
	pthread_mutex_unlock(&count_mutex);

	return n;
}

/* 拷贝函数 */
void my_copy(FILE **fp1, FILE **fp2)
{
	int ret = -1; 
	int n;
	char buf[N] = {0};

	while(ret != 0)
	{
//		printid();
	
		n = do_count();

		fseek(*fp1, n, 0);
		fseek(*fp2, n, 0);

		memset(buf, 0, sizeof(buf));
		ret = fread(buf, 1, N, *fp1);
		fwrite(buf, ret, 1, *fp2);
	}

	return;
}

void *thr_fn(void *arg)
{
	FILE *fp1;
	FILE *fp2;

	open_file(&fp1, &fp2);

	my_copy(&fp1, &fp2);

	close_file(&fp1, &fp2);

	return;
}

/* 创建一个线程 */
void create_thread(pthread_t *ntid)
{
	int err;

	err = pthread_create(ntid, NULL, thr_fn, NULL);
	if(err != 0)
	{
		fprintf(stderr, "error: %d: %s", err, strerror(err));
		exit(0);
	}

	return;
}

/* 创建一个文件，存放拷贝来的内容 */
void create_file(void)
{
	FILE *fp;
	fp = fopen(cp_to, "w");
	if(NULL == fp)
	{
		printf("create file %s error\n", cp_to);
		exit(1);
	}

	fclose(fp);

	return;
}

int main(int argc, char* argv[])
{
	int err;
	int i, n; 
	pthread_t *ntid;
	
	printf("How many threads do you want to create?\nn = "); 
	scanf("%d", &n);

	printf("Please input a file:\ncp_from = "); 
	scanf("%s", cp_from);

	printf("Please input a file:\ncp_to = "); 
	scanf("%s", cp_to);

	/* 创建一个文件，存放拷贝来的内容 */
	create_file();

	/* 循环创建指定个数个线程 */
	ntid = (pthread_t *)malloc(sizeof(pthread_t) * n);

	for(i = 0; i < n; i++)
	{
		create_thread(ntid + i);
	}
	printf("You create %d threads.\n", n); 
	printf("Please wait for a moment....\n"); 

	/* 等待每个线程结束 */
	for(i = 0; i < n; i++)
	{
		pthread_join(*(ntid + i), NULL);
	}

	printf("Copy finish!\n"); 

	/* 释放空间 */
	free(ntid);

	return 0; 
}
