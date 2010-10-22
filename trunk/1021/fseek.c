#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE *fp;
	char buf[100] = {0};

	fp = fopen("1.txt", "r");
	printf("11111111111\n"); 

	fseek(fp, 30, 0);

	fread(buf, 10, 1, fp);
	
	printf("%s\n", buf); 

	fclose(fp);

	return 0; 
}
