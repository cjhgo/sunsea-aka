#include <stdio.h>
#include <string.h>

void parse_chr(char *s , char dst[4][6])
{

	int i = 0 ;
	char *tmp = s;
	printf("44444444444\n"); 
	while (tmp = strchr(s ,' '))
	{
	//	tmp = '\0';
		strcpy(dst[i],s);
		tmp++;
		s = tmp;
		i++ ;
	}
	printf("333333333333333333\n"); 
	strcpy(dst[i],s);
	return ;

}
int main (int argc ,char *argv[])
{

	char s[] = "I  like the game!";
	char dst[4][6] = {"\0"};
	int i;

	printf("111111111\n"); 
	parse_chr(s,dst);
	printf("22222222\n"); 
	for(i=0; i < 4 ; i++)
		printf ("dst[%d]=%s\n",i,dst);

	printf ("\n");
	return 0;

}
