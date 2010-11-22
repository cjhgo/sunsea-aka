#include <stdio.h> 

static char buff[256];
static char * string;
int main()
{
	printf("please input a string: ");
	gets(string);
	printf("\nyour string is: %s\n", string); 
}
