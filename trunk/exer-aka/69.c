#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort(int *p)
{	
	int i,t;
	int *min;
	min = p;

//	printf("%d  \n",min);
	for(i = 0; i < (sizeof(p) / sizeof(int)); i++ )
	{
		if(*min > p[i])
		{
			t = *min;
			*min = p[i];
			p[i] = t;		
		}	
	}


	for(i = 0; i < 8; i++)
	{
		printf("%d  ",p[i]);
	}
	printf("\n");

	return *p;
}

int main(int argc, char* argv[])
{
	int a[] = {5,42,4,8,6,11,2,65};
	int i;
	printf("%d\n",a[0]);

	for(i = 0; i < 8; i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	
	sort(a);
	for(i = 0; i < 8; i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");

	return 0;
}
