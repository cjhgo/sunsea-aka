/使用库函数strtok将I like this game！字符串依据空格拆分成4个单词并存入str[4][6]数组并输出结果（%s）（查man手册学习strtok用法）

//未能实现把分割后的单词存入数组

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char s[] = "I like this game!";
	char *p;
	char *buff = s;
	int i;

	p = strtok(buff, " ");
	while(p !=NULL)
	{
		printf("%s  ",p);
		p = strtok(NULL, " ");//为什么需要这句
	}
	while(p != NULL)
		printf("%s  \n",*p); 

	printf("\n"); 
	return 0; 
}
