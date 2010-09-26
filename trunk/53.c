#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fib(int n)
{
	int v;

	if(n < 0 )
	{
		printf("error\n");
		return;
	}
	else if((n == 0)||(n == 1))
	{
		v = 1;
		return v;
	}
	else
	{
		v = fib(n - 1) + fib(n -2);
		return v;
	}

}


int main(int argc, char* argv[])
{
	
	int n,v;

	printf("please input ....\n");
	scanf("%d",&n);
	
	v = fib(n);
	printf("Fibonacci的第%d项 = %d\n",n ,v);


	return 0; 
}
