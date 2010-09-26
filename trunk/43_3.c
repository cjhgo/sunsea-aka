//4-3-3部分复制，例如从第3个字符开始复制    为什么会把所s1的内容清零？
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char strcpy_n(char *s1, const char *s2)
{
	while ( *(s2+2) != '\0')
	{
		*s1 = *(s2 + 2);
		s1++;
		s2++;
	}
	return *s1;
}


int main(int argc, char* argv[])
{
	char s1[] = "zxcvaaaaaaaaaaaaaaaaaabnm";
	char s2[] = "123456789";

	strcpy_n(s1,s2);

	printf("%s\n",s1);
	printf("%s\n",s2);


	return 0; 
}
