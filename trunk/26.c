#include <stdio.h> 
 
int main(int argc, char* argv[])
{
	int x;
	int i,j,k,n;

	n = 4*3*2;
	printf("n = %d\n",n); 
	for(i = 1; i <= 2;i++)
	{
		for(j = i+1; j <= 3; j++)
		{
			for(k = j+1; k <= 4; k++)
			{
				printf("%d\n",100*i + 10*j + k); 
				printf("%d\n",100*i + 10*k + j); 
				printf("%d\n",100*j + 10*i + k); 
				printf("%d\n",100*j + 10*k + i); 
				printf("%d\n",100*k + 10*i + j); 
				printf("%d\n",100*k + 10*j + i); 
			}
		
		}
	
	}
	return 0; 
}
