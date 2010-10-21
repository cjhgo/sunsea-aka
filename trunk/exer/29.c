#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char str[] = "I like this game!";
	char *p;

	p = str;
	printf("%s\n",p); 
	while(*p != '\0')
	{
		if(*p == 'e')
			*p = 'E';
		p++;	
	}
	
	printf("%s\n",str); //打印p为什么不行,因为p指向'\0'了

	return 0; 
}
