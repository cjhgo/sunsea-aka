#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[], char *envp[])
{
	char buf[10] = {0};
	int id;

	while(1)
	{
//		printf("please input a command:\n");
		scanf("%s", buf);

		if(strcmp("ls", buf) == 0)
		{
			id = fork();
			if(0 == id)
			{
				if(execle("/bin/ls","-a", "-a",  NULL, envp) < 0);
				{
					perror("ls");
				}
			}
		}
		else if(strcmp("ping", buf) == 0)
		{
			id = fork();
			if(0 == id)
			{
				if(execl("/bin/ping", "ping baidu", "www.baidu.com", NULL) < 0);
				{
					perror("ping");
				}
			}
		}
		else if(strcmp("hell", buf) == 0)
		{
			id = fork();
			if(0 == id)
			{
				execl("hell", "11111111111hello world", NULL);
			}
		}
		else
		{
			printf("'%s', the command is not exist!\n", buf);
			exit(0);
		}
	}
	
	return 0;
	
}
