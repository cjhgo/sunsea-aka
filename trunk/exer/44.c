#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toWord(char *p, char str[4][6])
{
	char *tmp = p;
	int i = 0;
	while(tmp = strchr(p, ' '))
	{
		*tmp = '\0';
		strcpy(str[i], p);
		tmp++;
		p = tmp;
		i++;
	}
	strcpy(str[i],p);
}

int main(int argc, char* argv[])
{
	int i;
	char s[] = "I like this game!";
	char str[4][6] ;
	
	toWord(s, str);
	for(i = 0; i < 4; i++)
	{
		printf("%s\n",str[i]); 
	
	}
	
	
	
	return 0;

}
