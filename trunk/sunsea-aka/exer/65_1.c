#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcpy(char *s1,char *s2)
{
	char * p, * q;

	if(strlen(s1) < strlen(s2))
		return "can not copy";
	else
	{
		p = s1;
		q = s2;
		while(*q != '\0')
		{
			*p = *q;
			p++;
			q++;		
		}
	}
	return s1;
}

int main(int argc, char* argv[])
{
	char s1[] = "qwerty";
	char s2[] = "1234";
	char *c; 

	c = my_strcpy(s1, s2);
	
	printf("%s\n",c);

	return 0; 
}
