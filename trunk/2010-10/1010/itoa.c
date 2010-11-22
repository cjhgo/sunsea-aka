//itoa.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1024

void itoa(int x, char * p)
{
	int i = 0;
	char s[N] = {0};

	while(x)
	{
		s[i] = (x % 10) + '0';
		x = x / 10;
		i++;
	}
	
	for(i--; i >= 0; i--)
	{
		*p++ = s[i];
	}	

	return;
}

int main(int argc, char* argv[])
{
	char p[N] = {0};
	
	itoa(12345, p);

	printf("%s\n", p); 

	return 0; 
}
