#include <stdio.h>
#include <malloc.h>

int main(int argc, char* argv[])
{
	char * buf;
	int i;
	char a[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

	buf = malloc(sizeof(10 * sizeof(char)));

	for(i = 0; i < 9; i++)
	{
		*buf = a[i];
		buf++;
	}

	buf = buf - 9;
	for(i = 0; i < 9; i++)
	{
		printf("%c  ", *(buf + i)); 
	}
	printf("\n"); 


	printf("buf = %s\n", buf);

	return 0; 
	
}
