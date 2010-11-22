#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int a[] = {100,11,2,13,3,5,19,11,7,13,91,19,3};
	int tmp;
	int i,j;

	for(i = 0; i < 13; i++)
	{
		tmp = a[i];
		for(j = i+1; j < 13; j++)
		{
			if(tmp == a[j])
				a[j] = -1;
		}
	
	}

	for(i = 0;i < 13; i++)
	{
		if(a[i] != -1)
			printf("%d  ",a[i]); 
	}
	printf("\n"); 

	return 0; 
}
