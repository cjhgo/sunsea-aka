#include <stdio.h> 

int getbits(unsigned x,int p,int n)
{
	if((p > 31)||(p-n+1 < 0))
	{
		printf("error,we'll return the original number!\n"); 
		return x;
	}
	return (x >> (p+1-n)&~(~0<<n));
}

int main(int argc, char* argv[]) 
{
	unsigned x;
	int p,n;
	printf("please input unsigned x, int p,n\n");
	scanf("%u %d %d",&x,&p,&n);
	printf("getbits(0x%x,%d,%d) = 0x%x\n",x,p,n,getbits(x,p,n));

	return 0; 
}
