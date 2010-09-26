#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcpy(char *s1, const char *s2)
{
	while ( *s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	return s1;
}

int main(int argc, char* argv[])
{
	char s1[] = "1233455";
	char s2[] = "sdfsdf";

	my_strcpy(s1,s2);

	printf("%s\n",s1);
	printf("%s\n",s2); 

	return 0; 
}
