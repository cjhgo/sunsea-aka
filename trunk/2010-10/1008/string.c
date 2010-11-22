#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void A_to_a(char str[]);
void a_to_A(char str[]);

int main(int argc, char* argv[])
{
	int i = 0;

	char str[] = "asdsfFS , &*(()sdfadsQEER --0FdafFSR";

	while('\0' != str[i])
	{
		printf("%c",str[i]); 
		i++;
	}
	printf("\n"); 

	A_to_a(str);
	i = 0;
	while('\0' != str[i])
	{
		printf("%c",str[i]); 
		i++;
	}
	printf("\n"); 
	
	a_to_A(str);
	i = 0;
	while('\0' != str[i])
	{
		printf("%c",str[i]); 
		i++;
	}
	printf("\n"); 

	return 0; 
}

void A_to_a(char str[])
{
	int i = 0;

	while('\0' != str[i])
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}

	return;
}

void a_to_A(char str[])
{
	int i = 0;

	while('\0' != str[i])
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}

	return;
}

