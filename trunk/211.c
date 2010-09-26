#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int a[3][3] = {{4,5,8},{2,7,1},{3,9,6}};
	int min;
	int i,j;
	int m,n;
	
	min = a[0][0];
	for(i = 0;i < 3;i++)
	{
		for(j = 0;j < 3;j++)
		{
			if(a[i][j] < min)
			{
				min = a[i][j];
				m = i;
				n = j;
			}
		
		}
	}
	printf("i = %d,j = %d\n",m,n);
	printf("min = %d\n",min);

	return 0; 
}
