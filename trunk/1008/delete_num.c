#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

char * delete_num(char str[]);

int main(int argc, char* argv[])
{
	int i = 0;

	char * pStr, * p;
	char str[] = "rweq25%^&sdgf235 sfdh3465432 ddas";
	
	pStr = str;
	printf("%s\n",pStr); 

	printf("%s\n", delete_num(str)); 

	return 0; 
}

char * delete_num(char str[])
{
	int i = 0;
	int j = 0;
	char * p;
	char string[100] = {0};
	
	p = string;
	while('\0' != str[i])
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			i++;
		}
		else
		{
			string[j] = str[i];
			i++;
			j++;
		}
	}
	p = string;
	
	return p; 
}

