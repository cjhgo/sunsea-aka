/*
 判断是不是回文数
 */
#include <stdio.h> 
#define N 1024

void itoa(int * p, char * pStr)
{
	char str[N] = {0};
	int i;

	while(*p)
	{
		Str = *p % 10 + '0';
		*p = *p / 10;
	}
	
	i = strlen(str);

	for(;, i >= 0; i--)
	{
		*pStr++ = str[i];
	}

	return;

}

int judge(int * p)
{
	char * pStr;


	return 0; 
}

int main(int argc, char* argv[])
{
	int num;
	int x;
	char ** pStr;
	char str[N] = {0};

	*pStr = str;

	printf("please input....\n");
	scanf("%d", &num);


	itoa(&num, &pStr);

	printf("%s\n", *pStr); 

/*	x = judge(&num);
	if(1 == x)
	{
		printf("该%d是回文数！\n", num); 
	}
	else
	{
		printf("该%d不是回文数！\n", num); 
	}
*/	
	return 0; 
}
