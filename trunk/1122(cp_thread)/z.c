/*
 * =====================================================================================
 *
 *       Filename:  z.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2010年11月20日 08时51分04秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zsx (), zsx_happy@126.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	pid_t pid = fork();

	if(pid  < 0)
	{
		perror("fork");
		exit(1);
	}
	if(pid > 0)
	{
		/* parent */
		while(1);
	}
	/* child */
	return 0; 
}
