//实现一个整数的二进制输出

#include <stdio.h>

int main(int argc, char* argv[])
{
	int val;
	int i = 31;

	printf("please input ....\n"); 
	scanf("%d",&val);

	while(i)
	{
		if(val&(0x01<<i))
			break;
		i--;
	}
	printf("i = %d\n", i);	//判断出是i位数字，i从0开始
	printf("%#x\n",val); 
	for(; i >= 0; i--) 
		printf("%d",((val&(0x01<<i))>>i)&0x01); 
	printf("\n"); 
	return 0;
	
}
