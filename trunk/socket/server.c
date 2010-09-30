/*
 * 服务端
 *
 * */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <errno.h> 
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h> 
#include <sys/wait.h> 

int main(int argc, char* argv[]) 
{
	int sockfd, new_fd;

	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;

	int sin_size;

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket");
		exit(1);
	}

	printf("%d\n",sockfd); 

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(6000);
//	my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	my_addr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(my_addr.sin_zero), 8);

	if(bind(sockfd,(struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("bind");
		exit(1);
	}

	if(listen(sockfd, 100) == -1)
	{
		perror("listen");
		exit(1);
	}
	printf("listen....\n"); 

	while(1)
	{
		sin_size = sizeof(struct sockaddr_in);
		if((new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1)
		{
			perror("accept");
			continue;
		}
	
		printf("server: got connection from %s", inet_ntoa(their_addr.sin_addr));
	/*	if(!fock())
		{
			if(send(new_fd, "Hello,world!", 14, 0) == -1)
				perror("send");
			close(new_fd);
			exit(0);
		}
	*/	
		close(new_fd);
		waitpid(-1, NULL, WNOHANG) > 0;
	}










	return 0; 
}
