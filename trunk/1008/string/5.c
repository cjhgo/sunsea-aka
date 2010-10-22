#include <stdio.h>
#include <stdlib.h>

int power(int n)
{
	return n*n;
}

int main(int argc, char* argv[])
{
	int n1;
	int n2;

	if(2 != argc)
	{
		printf("Usage:please input a number!\n"); 
	}

	n1 = atoi(argv[1]);
	printf("please input a number:\n"); 
	scanf("%d",&n2);
	printf("%d * %d = %d\n", n1, n1, power(n1)); 
	printf("%d * %d = %d\n", n2, n2, power(n2)); 

	return 0; 
}
