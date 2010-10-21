#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char * p = "1234567";
	char * q = "134";
	char * tmp;

	tmp = strstr(p, q);

	printf("tmp = %s\n", tmp); 
	
	return 0; 
}
