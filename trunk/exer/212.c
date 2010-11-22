#include <stdio.h>

int main(void)
{
	int a=9, b=1;
	int temp;
	if(a > b)
	{
		//int temp = a;
		temp = a;
		a = b;
		b = temp;
	}
	printf("a=%d,b=%d,temp=%d\n", a, b, temp);
	return 0;
}

