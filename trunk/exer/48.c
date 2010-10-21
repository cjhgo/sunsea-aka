#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char s1[] = "zxcvasfdfgf";
	char s2[] = "zxctfdsa";
	int ptr;
	
	ptr = strncmp(s1, s2, 3);
	if(ptr > 0)
		printf("s1 > s2\n");
	else if(ptr = 0)
		printf("s1 = s2\n");
	else
		printf("s1 < s2\n");

	return 0; 
}
