#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cut_num(char *s)
{
	while(*s != '\0')
	{
		if((*s >= 48)&&(*s <= 57))
		{	
			memmove(s,s+1,strlen(s));
			s--;
		}
		s++;
	}
	return *s;
}


int main(int argc, char* argv[])
{
	char s1[] = "www.163.com";
	char s2[] = "You will go to Room 3189 to stay for 12 hours.";

	cut_num(s1);
	cut_num(s2);

	printf("%s\n",s1);
	printf("%s\n",s2);


	return 0; 
}
