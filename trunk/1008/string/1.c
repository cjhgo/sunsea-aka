#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int i = 0;
	int n;

	printf("argc = %d\n", argc); 
	while(argv[i] != NULL)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}

	n = atoi(argv[1]);
	printf("n = %d\n", n);

	return 0; 
}
