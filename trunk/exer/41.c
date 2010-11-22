#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
	char str[] = "I like programming!";
	int i = 0;
	int len, j;

	while(str[i] != '\0')     /* 思考一下为啥是 \0 呢？及其作用*/
	{
		printf("%c", str[i]);
		i++;
	}
		printf("\n");

//反向输出
	len = strlen(str);
	printf("len = %d\n",len);

	for(j = len; j >= 0; j--)
	{
		printf("%c",str[j]);
	}
	printf("\n"); 

//大写换小写，小写换大写
	for(i = 0; i <= len; i++)
	{
		if((str[i] >= 65)&&(str[i] <= 90))
		{
			str[i] = str[i] + 32;
		}
		else if((str[i] >= 97)&&(str[i] <= 122))
		{
			str[i] = str[i] - 32;
		}
		printf("%c",str[i]); 
	}
	printf("\n"); 
		
		return 0;
}

