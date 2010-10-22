#include <stdio.h>
#define SIZE 10

int main(int argc, char * argv[])
{
	int a [SIZE] = {0},  i = 0;
	int sum = 0;
	for(i  =  0;  i  <  SIZE;  i++)
	{
		a[i] = i  + 10; 
		sum += a[i];
		printf("a[%d] =  %d\n", i, a[i]);
	}
	printf("sum = %d\n",sum);
	
 
}
