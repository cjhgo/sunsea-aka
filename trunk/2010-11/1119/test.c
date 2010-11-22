#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	printf("11111111111\n");

	printf("argc = %d\n", argc);

	printf("argv[0] = %s\n", argv[0]);
	printf("argv[1] = %s\n", argv[1]);
	printf("argv[2] = %s\n", argv[2]);
	printf("argv[3] = %s\n", argv[3]);

	printf("envp[0] = %s\n", envp[0]); 
	printf("envp[1] = %s\n", envp[1]); 
	printf("envp[2] = %s\n", envp[2]); 
	printf("envp[3] = %s\n", envp[3]); 
	
	return 0;
}
