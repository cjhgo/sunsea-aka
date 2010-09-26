#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int a[] = {1,2,3,5,6,7,8,9,0,11,22,33,44,55,66};
	int b[15];
	int *p,*pa,i,j, tmp;

	pa = a;
	p = b;

	for(i = 0;i < 15 -1; i++)
	{
		for(j = 0; j < 15-1-i; j++)
		{
			if(pa[j] > pa[j+1])
			{
				tmp = pa[j];
				pa[j] = pa[j+1];
				pa[j+1] = tmp;
			}
		}
	
	}
	for(i = 0;i < 15; i++)
	{
		if(pa[i] % 2 == 1)
		{
			*p = pa[i];
			p++;
		}
	}
	for(i = 0;i < 15; i++)
	{
		if(pa[i] % 2 ==0)
		{
			*p = pa[i];
			p++;		
		}
	}

	for(i = 0;i < 15; i++)
	{
		printf("%d  ",b[i]);
	
	}
	printf("\n"); 

	return 0; 
}
