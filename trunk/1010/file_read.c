#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE *fp;

	if((fp = fopen("test11.txt", "r")) == NULL)
	{
		perror("test.txt\n");
		exit(1);
	}



	fclsoe(fp);

	return 0; 
}
