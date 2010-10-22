#include <stdio.h> 
#include <stdlib.h>

int num(int x);

int main(int argc, char* argv[]) 
{
	int a;
	printf("please input ....\n");	
	scanf("%d",&a);

	num(a);
	return 0; 
}
	
int num(int x)
{
	if(x >= 0)
	{
		printf("%d\n",x);
	}
	else
	{
		printf("%d\n",-x);
	}
	return ;
}

