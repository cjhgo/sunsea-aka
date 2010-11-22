#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{

	int i = 0;
	char * p = "hello world",*ptr;

	char str[] = "hello world";
	
	printf("%s\n",p);
	printf("%s\n",str);


	ptr = str;

	while( *ptr != '\0')
	{
		if( *ptr == 'h')
		{
			//*p = *p - 32;
			*ptr = 'H';
		}
		ptr++;
	}

	while(str[i] != '\0')
	{
		if(str[i] == 'h')
			str[i] = str[i] - 32;
		i++;
	}

	printf("%s\n",p);
	printf("%s\n",str);
	
	return 0; 
}
