#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strncmp(char *s1, char *s2, int n)
{
	int i;
	int ptr;
	for ( i = 0;i < n;i++)
	{
		if(s1[i] < s2[i])
			{
				ptr = -1;
				break;
			}
		else if(s1[i] = s2[i])
		{
			ptr = 0;
		
		}
		else
		{
			ptr = 1;
			break;
		}
	}
	return ptr;

	
}

int main(int argc, char* argv[])
{	
	int ptr;
	char s1[] = "zxcvbaddf";
	char s2[] = "zxvcxsd";

	ptr = my_strncmp(s1, s2, 3);

	if(ptr > 0)
		printf("s1 > s2\n");
	else if(ptr  = 0)
		printf("s1 = s2\n");
	else 
		printf("s1 < s2\n");

		return 0; 
}
