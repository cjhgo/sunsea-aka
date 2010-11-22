#include <stdio.h>
#include <string.h>
#define N 1024

void swap_str(char **p, char **q)
{
	char * tmp;

	tmp = *p;
	*p = *q;
	*q = tmp;

	return; 
}

int main(int argc, char* argv[])
{
/*	char str1[N] = "hello world!";
	char str2[N] = "abcd";
	char *p;
	char *q;

	p = str1;
	q = str2;
*/
	char *p = "hello world";
	char *q = "abcd";

	printf("%s\n",p);
	printf("%s\n",q);
	printf("\n"); 

	swap_str(&p, &q);

	printf("%s\n",p);
	printf("%s\n",q);

	return 0; 
}
