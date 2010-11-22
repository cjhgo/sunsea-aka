/*
 * =====================================================================================
 *
 *       Filename:  a.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2010年11月19日 20时57分54秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zsx (), zsx_happy@126.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork");
	}
	if(pid > 0)
	{
		/* parent */
		while(1);
	}
	/* child */
	return 0;
}
