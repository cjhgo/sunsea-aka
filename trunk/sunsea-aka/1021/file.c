#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int main(int argc, char* argv[])
{
	FILE *fp;
	char buf[100] = {0};
	int ret;
	int i = 0;
	char str[100] = {0};
	int len = 0;

	if((fp = fopen("test.txt", "r")) == NULL)
	{
		perror("test.txt");
		exit(0);
	}

	ret = fread(buf, 100, 1, fp);
	printf("%s\n", buf); 

	printf("~~~~~~~~~~~~~~~~~~~~~~~\n"); 
	while('\n' != buf[i])
	{
		str[i] = buf[i];
		i++;
	}
	len = strlen(str);
	printf("str:%s\n", str); 
	printf("len:%d\n", len); 
	printf("===================\n"); 

	i = 0;
	while('\n' != buf[i])
	{
		str[i] = buf[len + i];
		i++;
	}
	printf("str:%s\n", str); 
	printf("len:%d\n", len); 
	printf("===================\n"); 

	fclose(fp);

	return 0; 
}
