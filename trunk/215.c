#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isprime(int x)
{
	int sq,i;
	if(x <= 1)
		return 0;
	sq = (int)sqrt(x);
	
	for(i = 2;i <= sq;i++)
	{
		if(x % i == 0)
		{
		break;
		}
	}
	if(i <= sq)
		return 0;
	else
		return 1;
	
}

int main(int argc, char* argv[])
{
	int pnPrimeList[100] = {0};
	int ntotal = 0;
	int i,j;
	for(i = 0;i <= 100;i++)
	{
		if(1 == isprime(i))
		{
			pnPrimeList[ntotal] = i;
			ntotal++;
		}
	
	}
	for(j = 0;j < ntotal;j++)
	{
		printf("%d ",pnPrimeList[j]);
	}
	printf("\ntotal number = %d\n",ntotal);
	return 0;
}
