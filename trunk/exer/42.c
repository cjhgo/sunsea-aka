#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void squeeze(char s[],char c)
{
	while ( *s != '\0' )
	{
		if ( *s == c )
		{
			//strcpy(s,s+1);
			memmove(s,s+1,strlen(s));
		}
		s++;
	}
}

int main(int argc, char* argv[])
{
	char c;
	char s[] = "zxcvbzxcvb";
	int i = 0;

	printf("%s\n",s);	
	c = 'c';
	squeeze(s,c);
/*	
	while ( s[i] != '\0' )
	{
		if ( s[i] == c )
		{
			//strcpy(&s[i],&s[i+1]);
			memmove(&s[i],&s[i+1],strlen(&s[i]));
		}
		i++;
	}
*/
	printf("%s\n",s);	
	
	return 0; 
}
