#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int a[] = {1,2,3,4,5,6};
	int *p, i;

	p = a;
	for(i = 5;i >= 0; i--)
	{
	
		printf("%d  ",p[i]);

	}
	printf("\n");




}
