#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char s1[20] = "123456";
	char s2[] = "zxcvbn";

	strcat(s1, s2);


	printf("%s\n",s1);

	return 0; 
}
