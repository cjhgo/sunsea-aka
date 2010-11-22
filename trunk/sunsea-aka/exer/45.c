#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char str[])
{
	int c;

	while(*str != '\0')
	{
		c++;
		str++;
	}
	return c;

}

int main(int argc, char* argv[])
{
	char s[] = "zzzzzxcdssdaf";

	printf("%d\n",my_strlen(s));

	return 0;



}
