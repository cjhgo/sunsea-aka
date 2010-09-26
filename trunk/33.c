#include <stdio.h>
#define SIZE 10

int main(int argc, char * argv[])
{
	int a [SIZE] = {0},  i = 0;
	int m = 0,n = 9,temp;
	for(i  =  0;  i  <  SIZE;  i++)
	{
		a[i] = i  + 10; 
		printf("a[%d] =  %d\n", i, a[i]);
	}

	printf("\n"); 

	while(m < n)
	{
		temp = a[m];
		a[m] = a[n];
		a[n] = temp;
		m++;
		--n;
	}
	for(i = 0; i < SIZE; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}



	return 0;
}

