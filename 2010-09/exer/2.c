#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char* argv[])
{
	int h;
	char i;
	float j;

	printf("a = %d,b = %x,c = %f\n",7,100,27);

	printf("d = %f\n",17.2365);

	printf("e = %s,f = %s,g = %s\n","%d","\'","\"");

	printf("int = %d,char = %d,float = %d\n",sizeof(h),sizeof(i),sizeof(j));
	return 0;
}
