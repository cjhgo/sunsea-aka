/*
 * =====================================================================================
 *
 *       Filename:  file.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2010年11月18日 17时19分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zsx (), zsx_happy@126.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h> 
#include <fcntl.h>
#include <unistd.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int fd;

int main(int argc, char* argv[]) 
{
	int fd;
	if ((fd = creat("file.hole", O_RDWR)) < 0)
		printf("create error\n");
	if(write(fd, buf1, 10) != 10)
		printf("buf1 error\n"); 
	if(lseek(fd, 100, SEEK_SET) == -1)
		printf("lseek error\n"); 
	if(write(fd, buf2, 10) != 10)
		printf("buf2 error\n"); 

	return 0; 
}
