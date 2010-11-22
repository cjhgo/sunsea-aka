/*
 * =====================================================================================
 *
 *       Filename:  thread1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2010年11月20日 10时18分46秒
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
#include <string.h> 
#include <stdlib.h> 
int i = 1;

void *add(void *arg)
{
//	int i = 1;

	while(i < 10)
	{
		i = i + 1;
		printf("%s i = %d\n",(char *)arg, i); 
	}


	return NULL;
}


int main(int argc, char* argv[])
{
	int err;
	pthread_t ntid;

	err = pthread_create(&ntid, NULL, add, "new thread: ");
	if(err != 0)
	{
		fprintf(stderr, "can't create thread: %s\n", strerror(err));
		exit(1);
	}

	add("main thread:");


	sleep(1);


	return 0; 

}
