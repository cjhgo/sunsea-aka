//统计一个自然数的二进制表示形式中有多少个 1

#include <stdio.h> 

int main(int argc, char* argv[])
{
	int num;
	int c = 0;
	int x;

	printf("please input ....\n"); 
	scanf("%d", &num);
	
	while(num != 0)
	{
		x = num % 2;
		if(x == 0)
			num = num / 2;
		else if(x == 1)
		{
			c++;
			num = num / 2;		
		}
	}
	printf("%d\n",c); 

	return 0; 
}
