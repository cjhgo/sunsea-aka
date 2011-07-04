/*
 * =====================================================================================
 *
 *       Filename:  mouse_thread.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011年05月07日 15时15分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <pthread.h>
#include "common.h"

int fd_mouse;
pthread_mutex_t click_mutex = PTHREAD_MUTEX_INITIALIZER;

void *thr_fn(void *arg)
{
	fd_mouse = open_mouse();
	cx = screen_w / 2;
	cy = screen_h / 2;

	while(1)
	{
		move_mouse(&fd_mouse);
		if(buf_mouse[0] & 0x1)
		{
			memset(buf_mouse, 0, 8);
			move_mouse(&fd_mouse);
			if((buf_mouse[0] & 0x1) == 0)
			{
				pthread_mutex_lock(&click_mutex);
				click_switch = 0;
				pthread_mutex_unlock(&click_mutex);
			}
		}
	}

	return;
}

/* 创建一个线程 */
void create_mouse_thread(pthread_t *ntid)
{
	int err;

	err = pthread_create(ntid, NULL, thr_fn, NULL);
	if(err != 0)
	{
		fprintf(stderr, "Error:%d:%s", err, strerror(err));
		exit(0);
	}

	return;
}
/* end of file */
