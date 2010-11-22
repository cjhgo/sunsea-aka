#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char *c = "12aa34";
	int val = 6;
	
	val = atoi(c);

	printf("%d\n", val); 

	return 0;
}
