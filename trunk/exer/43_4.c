#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char my_strncpy(char *s1, const char *s2, int n)
{
	int i;
	if(n > strlen(s2))
		return 1;
	else
	{
		for(i = 0; i < n; i++)
		{
			*s1 = *s2;
			s1++;
			s2++;
		}

	}

	return *s1;
}

int main(int argc, char* argv[])
{
	char s1[] = "zxcvbnm";
	char s2[] = "123456";

	my_strncpy(s1, s2, 4);

	printf("%s\n",s1);
	printf("%s\n",s2);

	return 0; 
}
