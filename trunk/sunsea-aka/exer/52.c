//5-2用递归实现n！
//为什么不能return 0,必须的return 1;



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jc(int x)
{
	int v;

	if ( x == 0 )
		return 1;//要利用该返回值计算
	else
	{
		v = x * jc(x -1);
		return v;
	}
}

int main(int argc, char* argv[])
{
	int n;

	printf("please input ....\n");
	scanf("%d",&n);
	printf("%d! = %d\n",n,jc(n));

	return 0; 
}
