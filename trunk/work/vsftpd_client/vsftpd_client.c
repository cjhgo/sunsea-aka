/*
 * =====================================================================================
 *
 *       Filename:  vsftp_client.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011年06月09日 09时48分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sunsea (zsx), sunsea1026@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <arpa/inet.h>

#define	SERVER_PORT	21
#define ERRORNO	(-1) 

typedef struct ftp_host_info_s
{
	char	*user;
	char	*password;
	struct	sockaddr_in *s_in;
}ftp_host_info_t;


static void show_use_msg()
{
	printf("Usage:\n\tvsftpd_client [options] remote-host local-file remote-file\n\n");
	printf("options:\n"); 
	printf("\t-u, --username\t username to be used\n\n"); 
	printf("\t-p, --password\t password to be password\n\n"); 
	printf("example:\n"); 
	printf("\t./vsftpd_client -u sunsea -p 123456 192.168.254.100 test.txt test.txt\n\n"); 

	return;
}


/* 创建socket */
int xconnect(struct sockaddr_in *s_addr)
{
	int	s, ret;
	
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < -1)
	{
		printf("Error:create socket error!\n"); 

		return (ERRORNO); 
	}

	ret = connect(s, (struct sockaddr *)s_addr, sizeof(struct sockaddr));
	if (ret < 0)
	{
		printf("Error:connect error!\n"); 

		return (ERRORNO); 
	}

	return s;
}

/* ftp_cmd */
static int ftpcmd(const char *s1, const char *s2, FILE *stream, char *buf)
{

	if (s1)
	{
		fprintf(stream, (s2 ? "%s %s\r\n" : "%s %s\r\n" + 3), s1, s2);

		fflush(stream);
	}

	do
	{
		char	*buf_ptr;

		if (fgets(buf, 510, stream) == NULL)
		{
			printf("Error:fget() error!\n");

			return (ERRORNO); 
		}
		buf_ptr = strstr(buf, "\r\n");
		if (buf_ptr)
		{
			*buf_ptr = '\0';
		}
	}while (! isdigit(buf[0]) || buf[3] != ' ');

	return atoi(buf);
}

/* 登录ftp服务器 */
static FILE *ftp_login(ftp_host_info_t *server)
{
	FILE	*control_stream;
	char	buf[512];


	/* 创建socket */
	control_stream = fdopen(xconnect(server->s_in), "r+");
	if (control_stream == NULL)
	{
		printf("Error:create socket error!\n");

		return NULL; 
	}

	/* 建立连接 */
	memset(buf, 0, sizeof(buf));
	if (ftpcmd(NULL, NULL, control_stream, buf) != 220)
	{
		printf("Error:create link error!\n"); 

		return NULL;
	}
	printf("%s\n", buf);

	/* 提交用户名 */
	switch(ftpcmd("USER", server->user, control_stream, buf))
	{
		case 230:		//用户已登录，继续执行
			printf("%s\n", buf); 
			break;
		case 331:		//用户名正确需要密码
			printf("%s\n", buf); 
			memset(buf, 0, sizeof(buf));
			if (ftpcmd("PASS", server->password, control_stream, buf) != 230)
			{
				printf("Error:password error!\n"); 
				
				exit(-1);
			}
			printf("%s\n", buf); 

			break;
		default:
			printf("Error: login error!\n"); 
			break;
	}

	memset(buf, 0, sizeof(buf));
	ftpcmd("TYPE I", NULL, control_stream, buf);
	printf("%s\n", buf); 

	return control_stream;
}

/* 建立数据连接 */
static int xconnect_ftpdata(ftp_host_info_t *server, const char *buf)
{
	char	*buf_ptr;
	unsigned	short port_num;

	buf_ptr = strrchr(buf, ',');
	*buf_ptr = '\0';
	port_num = atoi(buf_ptr + 1);

	buf_ptr = strrchr(buf, ',');
	*buf_ptr = '\0';
	port_num += atoi(buf_ptr + 1) * 256;

	server->s_in->sin_port = htons(port_num);

	return (xconnect(server->s_in));
}

/* 拷贝到本地文件 */
static int copy_to_local(int fd_data, int fd_local, int filesize)
{
	char	buffer[4096];
	int	ret = 1;
	int	seek_size = 0;

	while (ret != 0)
	{
		lseek(fd_data, seek_size, 0);
		lseek(fd_local, seek_size, 0);
		memset(buffer, 0, sizeof(buffer));
		ret = read(fd_data, buffer, sizeof(buffer));
		write(fd_local, buffer, ret);

		seek_size += ret;
	}

	return 0; 
}

/* 下载文件 */
static int download_file(ftp_host_info_t *server, FILE *control_stream, char *local_path, char *server_path)
{
	char	buf[512];
	int	ret;
	unsigned long	filesize = 0;
	int	fd_data;
	int	fd_local;

	/* 进入被动模式 */
	ret = ftpcmd("PASV", NULL, control_stream, buf);
	printf("%s\n", buf); 
	if (ret != 227)
	{
		printf("Error:PASV error!\n"); 

		return (ERRORNO); 
	}

	/* 建立数据连接 */
	fd_data = xconnect_ftpdata(server, buf);

	/* 获取文件大小 */
	ret = ftpcmd("SIZE", server_path, control_stream, buf);
	printf("%s\n", buf);
	if (ret == 213)
	{
		filesize = strtoul(buf + 4, NULL, 0);
	}

	/* 确定文件开始位置 */
	memset(buf, 0, sizeof(buf));
	sprintf(buf, "REST %ld", (long)0);
	ret = ftpcmd(buf, NULL, control_stream, buf);
	printf("%s\n", buf);
	if (ret != 350)
	{
		printf("Error:download file start position error\n"); 

		return (ERRORNO); 
	}

	/* 开始下载文件 */ 
	memset(buf, 0, sizeof(buf));
	ret = ftpcmd("RETR", server_path, control_stream, buf);
	printf("%s\n", buf); 

	/* 创建本地文件 */
	fd_local = open(local_path, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (fd_local == -1)
	{
		printf("Error:create local file error!\n"); 
		exit(-1);
	}

	/* 拷贝到刚才创建的文件中去 */
	if (filesize)
	{
		ret = copy_to_local(fd_data, fd_local, filesize);
		if (ret != 0)
		{
			printf("Error:copy to local file error!\n"); 

			return (ERRORNO); 
		}
	}
	close(fd_local);

	memset(buf, 0, sizeof(buf));
	ret = ftpcmd(NULL, NULL, control_stream, buf);
	printf("%s\n", buf); 
	if (ret != 226)
	{
		printf("Error:226 error!\n"); 

		return (ERRORNO); 
	}

	return 0; 
}

/* 退出ftp服务器 */
static int ftp_quit(FILE *control_stream)
{
	int	ret;
	char	buf[512];

	memset(buf, 0, sizeof(buf));
	ret = ftpcmd("QUIT", NULL, control_stream, buf);
	printf("%s\n", buf);

	return 0; 
}

int main(int argc, char* argv[])
{
	FILE	*control_stream;
	char	ftp_server_ip[16];
	int	ret;
	char	local_path[1024];
	char	server_path[1024];

	struct	sockaddr_in s_in;
	ftp_host_info_t	*server;

	if (argc != 8)
	{
		show_use_msg();

		return (ERRORNO); 
	}

	server = (ftp_host_info_t *)malloc(sizeof(ftp_host_info_t));
	if (server == NULL)
	{
		printf("Error: malloc error!\n"); 

		return (ERRORNO); 
	}

	server->user = argv[2];
	server->password = argv[4];

	if (sizeof(argv[5]) > 16)
	{
		printf("Error:IP error\n"); 
		return (ERRORNO); 
	}
	memset(ftp_server_ip, 0, sizeof(ftp_server_ip));
	strcpy(ftp_server_ip, argv[5]);

	memset(local_path, 0, sizeof(local_path));
	memset(server_path, 0, sizeof(server_path));
	strcpy(local_path, argv[6]);
	strcpy(server_path, argv[7]);

	/* 初始化数据 */
	server->s_in = &s_in;
	memset(server->s_in, 0, sizeof(struct sockaddr_in));
	server->s_in->sin_family = AF_INET;
	inet_pton(AF_INET, ftp_server_ip, &(server->s_in->sin_addr));
	server->s_in->sin_port = htons(SERVER_PORT);


	/* 登录ftp服务器 */
	control_stream = ftp_login(server);
	if (control_stream == NULL)
	{
		printf("Error:login error!\n"); 

		return (ERRORNO); 
	}

	/* 下载文件 */
	ret = download_file(server, control_stream, local_path, server_path);
	if (ret)
	{
		printf("Error:download file error!\n"); 

		return (ERRORNO); 
	}


	/* 退出服务器 */
	ret = ftp_quit(control_stream);
	if (ret)
	{
		printf("Error:ftp quit error!\n");

		return (ERRORNO); 
	}

	fclose(control_stream);
	free(server);

	return 0; 
}
