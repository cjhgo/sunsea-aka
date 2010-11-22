#include <stdio.h> 
#include <string.h> 

int main(int argc, char* argv[])

{
	char s[111];
	char t[123];

	scanf("%s",s);
	printf("%s\n",s);
	
	fflush(stdin);
	gets(t);
	printf("%s\n",t); 
	
	return 0; 
}
