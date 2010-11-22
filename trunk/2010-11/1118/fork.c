#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int id;
	
	id = fork();

	if(id < 0)
	{
		printf("error\n"); 
	}
	else if(id == 0)
	{
		printf("child , id = %d\n", getpid()); 
		printf("father, id = %d\n", getppid()); 
	}
	else
	{
		printf("father, id = %d\n", getppid()); 
		printf("----child, id = %d\n", id); 
	}

	return 0; 
}
