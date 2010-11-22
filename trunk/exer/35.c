#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int a[] = {5, -9, 32, 77, 63, -24, 14, 0, 21, 45};
	int max,min;
	int x, i = 0;
	int m, n;
	max = a[0];
	min = a[0];

	for(x = 0; x < 10; x++)
	{
		i++;
		if(max < a[x])
		{
			m = i - 1;
			max = a[x];
		}
		if(min > a[x])
		{
			n = i - 1;
			min = a[x];
		}
	}
	printf("the max is a[%d] = %d\n", m, max);
	printf("the min is a[%d] = %d\n", n, min);
}
