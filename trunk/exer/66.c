#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strstr(char *p, char *q)
{
	while(*p != '\0')
	{
		if(*p == *q)
		{
			return p;
		}
		p++;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	char s1[] = "zxcvbn";
	char s2[] = "rb";
	char *x;

	x = my_strstr(s1, s2);
	if(x == NULL)
	{
		printf("not found\n"); 
	}
	else
	{
		printf("%s\n",x); 
	}

	return 0; 
}
