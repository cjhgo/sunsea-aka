#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char str[4] = {'a','b','c','d'};
	char * p = str;
	int *q = str;

	printf("%x,%d,%c\n",p,p,p);
	printf("%x,%d,%c\n",q,q,q);
	printf("%x,%d,%c\n",*p,*p,*p);
	printf("%x,%d,%c\n",*q,*q,*q);


	return 0; 
}
