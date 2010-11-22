#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char *s = "zxcvbnmasdfg";
	char *a = "as";
	char *p;
	int n;

	n  = strlen(a);
	p = strstr(s,"as");

	if(p)
		printf("%s\n",strstr(s,"as"));
	else 
		printf("not found\n");

	return 0; 
}
