//1-5编写一个自己的大写转小写的函数 char A_to_a(char a); 并在主函数里调用测试验证。
//只限于字母转换
//如果输入的不是字母，增加判断处理使程序更加健壮
//



#include <stdio.h>
#include <stdlib.h>

char A_to_a(char a);
char a_to_A(char a);

int main(int argc, char* argv[])
{
	char A;
	
	printf("please input a big character:\n");
	scanf("%c",&A);
	if((A >= 65)&&(A <= 90))
		A_to_a(A);
	else if((A >= 97)&&(A <=122))
		a_to_A(A);
	else
		printf("error!\n"); 
	return 0; 

}

char A_to_a(char X)
{
	char a;
	a = X + 32;
	printf("%c\n",a); 
}

char a_to_A(char X)
{
	char a;
	a = X - 32 ;
	printf("%c\n",a); 
}
