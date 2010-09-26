#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char str1[] = "zxcvbnm";
	char str2[] = "asdfghjkl";
	
	printf("%s\n",str1);
	printf("%s\n",str2);
	
	strcpy(str2,str1);
	//memmove(str1,str2,strlen(str1));

	printf("%s\n",str2);
}
