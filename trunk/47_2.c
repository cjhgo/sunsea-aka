#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char my_strcat(char *s1, char *s2)
{
	int n;
	int i = 0;
	n = strlen(s1);

	while( s2[i] != '\0')
	{
		s1[n++] = s2[i];
		i++;
		
	}
	
	return *s1;

}

int main(int argc, char* argv[])
{
	char s1[20] = "1245";
	char s2[] = "asd";

	my_strcat(s1,s2);
	printf("%s\n",s1);

	return 0; 
}
