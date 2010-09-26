#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{
	int a[] = {1,2,3,4,5};
	int b[] = {4,5,7,8,9};
	int sum[5];
	int cha[5];
	
	int i;
	int * p;
	int * q;
	int * r;
	int * t;

	p = a;
	q = b;
	r = sum;
	t = cha;

	for(i = 0; i < 5; i++)
	{
		r[i] = p[i] + q[i];
		t[i] = p[i] - q[i];
	}

	for(i = 0; i < 5; i++)
	{
		printf("%d ",r[i]);
	//	printf("%d\n",t[i]);
	}
	
	return 0; 
}
