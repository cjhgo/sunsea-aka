#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int i,j,k;

	for(i = 1;i <= 4;i++)
	{
		for(j = 0;j < 2*i-1;j++)
		{
			printf("*");		
					
		}
		printf("\n");
	}

	for(i = 1;i <= 4;i++)
	{
		for(k = 6;k > 2*i-1;k--)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;

}
