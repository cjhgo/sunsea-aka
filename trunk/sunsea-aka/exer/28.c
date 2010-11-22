//统计一下某字符串中某指定字符出现的次数

#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char str[] = "zxcvbnmzxcvbnmzzz";
	char *p;
	int count = 0;

	p = str;
	while(*p != '\0')
	{
		if(*p == 'z')
			count++;
		p++;	
	}

	printf("z 的个数：%d\n",count); 

	return 0;

}
