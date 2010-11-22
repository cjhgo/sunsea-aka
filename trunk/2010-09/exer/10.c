#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double myround(double x);

int main(int argc, char* argv[])
{
	double a;
	printf("please input a number:\n");
	scanf("%lf",&a);

	myround(a);

	return 0; 
}

double myround(double x)
{
	double y;

	y = x;

	if((x - (int)x) < (1/2.0))
	{
		y = floor(y);
	}
	else
		y = ceil(y);
	
	printf("%d\n",(int)y);
}
