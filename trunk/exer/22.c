#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int i;

	for (i = 1;i <= 200;i++)
	{
		if(i % 3 != 0)
			printf("%d\n",i); 
	}


	return 0; 
}


