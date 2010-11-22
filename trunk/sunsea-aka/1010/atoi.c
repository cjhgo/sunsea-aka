//atoi.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

my_atoi(char *p, int *x ) 
{
	int i = 0;
	char c;

	while(c = *p++)
	{
		i = i * 10 + c - '0';
	}
	
	*x = i;

	return;
}

int main(int argc, char* argv[])
{
	int x, y;

	my_atoi("234214", &x);

	printf("%d\n", x); 

	return 0;
}
