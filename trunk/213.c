#include <stdio.h>
#include <stdlib.h>

int add(int a,int b)
{
	int v;
	v = a + b;
	printf("%d + %d = %d\n",a,b,v);
	return;
}

int sub(int a,int b)
{
	int v;
	v = a - b;
	printf("%d - %d = %d\n",a,b,v);
	return;
}

int mul(int a,int b)
{
	int v;
	v = a * b;
	printf("%d * %d = %d\n",a,b,v);
	return;
}

int divd(int a,int b)
{
	int v;
	v = a / b;
	printf("%d / %d = %d\n",a,b,v);
	return;
}

int mod(int a,int b)
{
	int v;
	v = a % b;
	printf("%d %% %d = %d\n",a,b,v);
	return;
}
int main(int argc, char* argv[])
{
	int a,b,c;

	printf("please input ....\n");
	scanf("%d%d",&a,&b);
	printf("what do you do ?(1 add,2 sub,3 mul,4 div,5 mod)\n"); 
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			add(a,b);
			break;
		case 2:
			sub(a,b);
			break;
		case 3:
			mul(a,b);
			break;
		case 4:
			divd(a,b);
			break;
		case 5:
			mod(a,b);
			break;
	}

	return 0; 
}
