#include <stdio.h>

int sum(int n)
{
	if(n == 0)
		return 0;
	else
		return n + sum(n-1);
}

int main(int argc, char *argv[])
{
	int n;
	
	printf("Please input a number:");
	scanf("%d", &n);
	printf("1+2+…+%d = %d\n", n, sum(n));
	
	return 0;
}

