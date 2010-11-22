/*
 * =====================================================================================
 *
 *       Filename:  err.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2010年11月20日 11时17分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zsx (), zsx_happy@126.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE *fp;

	fp = fopen("1.c", "r");
	if(NULL == fp)
	{
		fprintf(stderr, "error\n");
	}

	return 0; 
}
