#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int * p;
	int i, len;
	int a[5];

	p = a;

	printf("please input ....\n"); 
	for(i = 0; i < 5; i++)
	{
		scanf("%d",&p[i]);
	}

	for(i = 0; i < 5; i++)
	{
		printf("%d  ",p[i]);
	}
	printf("\n"); 

	return 0; 
}
