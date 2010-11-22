/*
 * =====================================================================================
 *
 *       Filename:  buf.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2010年11月20日 23时32分44秒
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

int main(int argc, char* argv[])
{
	char buf[100] = "qwer";

	int i, j;

	i = sizeof(buf);
	j = strlen(buf);

	printf("i = %d\n", i); 
	printf("j = %d\n", j);

	return 0; 
}
