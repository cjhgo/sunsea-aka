#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *p, int n)
{
	int i, j, temp;

	for( i = 0; i < n - 1; i++)
	{
		for( j = 0;j < n-1-i; j++)
		{
			if(p[j] > p[j+1])
			{
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;			
			}
		}	
	}
	return;
}

void select_sort(int *p, int n)
{
	int i, j,k;
	int temp;
	for(i = 0;i < n-1; i++)
	{
		k = i;
		for(j = i+1; j < n; j++)
		{
			if(p[k] > p[j])
				k = j;
		}
		temp = p[i];
		p[i] = p[k];
		p[k] = temp;
	}
	return;

}

int main(int argc, char* argv[])
{
	int a[] = {5, -9, 32, 77, 63, -24, 14, 0, 21, 45};
	int b[] = {5, -9, 32, 77, 63, -24, 14, 0, 21, 45};
	int i;
	
	bubble_sort(a, 10);

	for(i = 0; i < 10; i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n"); 

	select_sort(b, 10);

	for(i = 0; i < 10; i++)
	{
		printf("%d  ",b[i]);
	}
	printf("\n"); 

	return 0; 
}
