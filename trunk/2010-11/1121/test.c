#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int main(int argc, char* argv[])
{
	FILE *fp;
	int n;
	char buf[1024] = {0};

	fp = fopen("test.txt", "r");

	if(fp == NULL)
	{
		perror("error!");
		exit(1);
	}

	n = fread(buf, 1, 10, fp);

	printf("buf = %s\n", buf); 

	printf("n = %d\n", n);

	return 0; 
}
