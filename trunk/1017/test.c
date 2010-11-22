#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char *p = "asd";
	printf("%s\n", p);
	strcpy(p, "123");

	printf("%s\n", p);
	return 0; 
}
