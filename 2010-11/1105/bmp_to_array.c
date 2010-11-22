#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int fd_bmp;
	FILE *fp;
	int ret_read;
	int ret_write;

	char buf[1025];

	fd_bmp = open("test.bmp", O_RDONLY);
	if(fd_bmp < 0)
	{
		printf("open test.bmp error!\n"); 
		return -1;
	}

	ret_read = read(fd_bmp, buf, 1024);

	fp = fopen("bmp.h", "w");
	if(NULL == fp)
	{
		printf("open bmp.h error!\n"); 
		return -1;
	}

	fwrite(buf, 1024, 1, fp);

	close(fd_bmp);
	fclose(fp);

	return 0; 
}
