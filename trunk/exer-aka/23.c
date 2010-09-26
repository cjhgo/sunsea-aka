#include <stdio.h> 

int main(int argc, char* argv[])
{
	int n,res = 0;
	int i; 

	scanf("%d",&n);

	for(i = 5; i <= n; i *= 5)
		res += n / i;
	printf("%d\n",res);
	
	return 0; 
}
