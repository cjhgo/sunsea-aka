#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int a[5];
	int odd = 0,even = 0;
	int i;

	printf("please input five numbers:\n");

	for (i = 0;i < 5;i++)
	{
		scanf("%d",&a[i]);
		printf("%d ",a[i]);
	}
		printf("\n"); 
	for(i = 0;i < 5;i++)
	{
		if(a[i] % 2 == 0)
			even++;
		else
			odd++;
	}
	
	printf("奇数个数= %d,偶数个数= %d\n",odd,even);

	return 0;

}
