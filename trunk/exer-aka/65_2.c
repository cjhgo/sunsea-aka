#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat(char *s1,char *s2)
{
	char * p, * q;
	int n;

	p = s1;
	q = s2;
	while(*q != '\0')
	{
		n = strlen(s1);
		*(p + n) = *q;
		n++;
		q++;
	}
	return s1;
}

int main(int argc, char* argv[])
{
	char s1[20] = "qwerty";
	char s2[] = "1234";
	char *c; 

	c = my_strcat(s1, s2);
	
	printf("%s\n",c);

	return 0; 
}
