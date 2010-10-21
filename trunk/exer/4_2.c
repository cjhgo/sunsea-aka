#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char a,b;
	printf("please input a big character\n");
	scanf("%c",&a);
	b = a + 32;
	printf("the samll character is:%c\n",b);

	return 0; 
}
