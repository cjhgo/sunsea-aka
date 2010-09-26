#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415926

int main(int argc, char* argv[])
{
	int r = 10;
	float length = 0.0,area = 0.0;

	length = 2*PI*r;
	area = PI*r*r;
	printf("%f\n",PI);
	printf("length = %f,area = %f\n",length,area);


}
