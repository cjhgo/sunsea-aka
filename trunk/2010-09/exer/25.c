#include <stdio.h>
#include <stdlib.h>

int compare(int a,int b,int c)
{
	int temp;
	if(a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if(a > c)
	{
		temp = a;
		a = c;
		c = temp;
	}
	if(b > c)
	{
		temp = b;
		b = c;
		c = temp;
	}
	printf("%d %d %d\n",a,b,c); 
}

int main(int argc, char* argv[])
{
	int a,b,c;

	printf("please input ....\n");
	scanf("%d%d%d",&a,&b,&c);

	compare(a,b,c);
	
    return 0;

}
