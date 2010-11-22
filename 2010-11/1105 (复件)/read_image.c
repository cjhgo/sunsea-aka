#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <linux/fb.h>


int main(int argc, char* argv[])
{
	int fd;
	int *fbmem;
	int screen_size;
	int w, h, bits;
	struct fb_var_screeninfo fb_var;

	fd = open("/dev/fb0", O_RDWR);
	if(fd < 0)
	{
		printf("Error:open framebuffer fail!\n"); 
		exit(0);
	}

	ioctl(fd, FBIOGET_VSCREENINFO, &fb_var);
	w = fb_var.xres;
	h = fb_var.yres;
	bits = fb_var.bits_per_pixel;
	printf("Framebuffer:%d * %d\n", w, h); 
	printf("Bits:%d\n", bits);

	screen_size = w * h * sizeof(int);
	fbmem = mmap(0, screen_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	return 0; 
}

int showbmp(char *bmp, int x, int y)
{
	unsigned int size, pos = 0x36;
	char *tp;
	char tmp[4];

	struct fb_cmap cmap;
	int fp_bmp;
	long height, width;
	int bmp_len;
	int i;

	fp_bmp = open("bg.bmp", O_RDONLY);
	if(-1 == fp_bmp)
	{
		printf("Error:open bg.bmp fail!\n"); 
		exit(0);
	}

	lseek(fp_bmp, 18, SEEK_SET);
	read(fp_bmp, (void *)&width, sizeof(long));
	read(fp_bmp, (void *)&height, sizeof(long));
	printf("bmp_width = %ld\n", width);
	printf("bmp_height = %ld\n", height); 

	if((x + width) > SCREEN_WIDTH || (y + height) > SCREEN_HEIGHT)
	{
		printf("beyond the bound of screen!\n"); 
		exit(0);
	}

	lseek(fp_bmp, pos, SEEK_SET);
	memset(&cmap, 0 ,sizeof(struct fb_cmap));
	cmap.start = 0;
	cmap.len = 256;

	cmap.red = calloc(256, sizeof(char) * 2);
	if(cmap.red == NULL)
	{
		printf("memery fault!\n"); 
		free(cmap.red);
		exit(0);
	}
	cmap.green = calloc(256, sizeof(char) * 2);
	if(cmap.green == NULL)
	{
		printf("memery fault!\n"); 
		free(cmap.green);
		exit(0);
	}
	cmap.blue = calloc(256, sizeof(char) * 2);
	if(cmap.blue == NULL)
	{
		printf("memery fault!\n"); 
		free(cmap.blue);
		exit(0);
	}

	for(size = 0; size < 256; size++)
	{
		read(fp_bmp, &tmp, 4);
		cmap.blue[size] = tmp[0] << 8;
		cmap.green[size] = tmp[1] << 8;
		cmap.red[size] = tmp[2] << 8;
	}

	if(ioctl(con, FBIOPUTCMAP, &cmap) < 0)
	{
		printf("FBIOPUTCMAP ERROR!\n"); 
		free(cmap.red);
		free(cmap.green);
		free(cmap.blue);

		close(fp_bmp);
		exit(0);
	}

	if(width%4)
	{
		bmp_len = width&(-3);
		bmp_len += 4;
	}
	else
		bmp_len = width;

	printf("bmp_len = %d\n", bmp_len);
	lseek(fp_bmp, pos+1024, SEEK_SET);

	tp = malloc(bmp_len);
	if(!tp)
	{
		printf("no enough memory\n"); 
		exit(0);
	}

	for(size = 0; size < height; size++);
	{
		read(fp_bmp, tp, bmp_len);
		memcpy(lcd_base + x + (y +height - size) * LINE_OFFSET, tp, width);

	}
	free(tp);
	free(cmap.red);
	free(cmao.green);
	free(cmap.blue);

	close(fp_bmp);

	return 0; 
}
