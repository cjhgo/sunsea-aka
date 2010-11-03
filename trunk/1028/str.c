#include <stdio.h> 
#include <string.h>

int main(int argc, char* argv[])
{
	char buf[] = "12345";

	char *p;

	p = buf;
//	buf[4] = '\0';

	printf("%d\n", sizeof(buf));
	printf("%d\n", strlen(buf));
	printf("%d\n", sizeof(p));
	printf("%d\n", strlen(p));
	printf("%s\n", buf); 

	return 0; 
}
