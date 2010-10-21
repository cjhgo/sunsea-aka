#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 

/*
 * 函数名：my_strncmp
 * 参数：char *pStr1 , char *pStr2, int n
 * 返回类型：int
 *
 * 版本：v1.0
 * 日期：2010.10.14
 *
 * */
int my_strncmp(char *pStr1, char *pStr2, int n)
{
	int i = 0;
	int count = 0;

	while(i < n)
	{
		if(*(pStr1 + i) == *(pStr2 + i))
		{
			i++;
			count++;
		}
		else
			i++;
	}
	if(n == count)
	{
		return 0;
	}
	else
		return -1;
}

/*
 * 函数名：search
 * 参数：char str[], char *p
 * 返回类型：int
 *
 * 版本：v1.0
 * 日期：2010.10.14
 *
 * */
int search (char str[], char *p)
{
	int count = 0;
	int i = 0;
	int n;
	
	while('\0' != str[i])
	{
		if(0 == my_strncmp(str+i, p, strlen(p)))
		{
			count++;
		}

		i++;
	}

	return count;
}

int main(int argc, char* argv[]) 
{
	char str[] = "hello world";
	char *key = "hell";
	int ret;
	
	ret = search (str, key);
	if(0 == ret)
	{
		printf("The key is not exist!\n"); 
		exit(0);
	}
	printf("ret = %d\n", ret); 

	return 0; 
}
