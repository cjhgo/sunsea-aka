#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <errno.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <jpeglib.h>
#include <jerror.h>


int print_screen(short *buf,int width,int height);
void draw_hline(short *buffer,int x,int y,int maxy,int maxx);

char *fb_addr;
unsigned int    fb_width;
unsigned int    fb_height;
unsigned int    fb_depth;
unsigned fb_size;

unsigned short PIXELRGB888TO565(unsigned char red, unsigned char green, unsigned char blue)
{
	unsigned short  B = (blue >> 3) & 0x001F;
	unsigned short  G = ((green >> 3) << 5) & 0x07E0;
	unsigned short  R = ((red >> 3) << 11) & 0xF800;

	return (unsigned short) (R | G | B);
}

int draw_pixel(void *fbmem, int width, int height, int x, int y, unsigned short color)
{
	if ((x > width) || (y > height))
		return -1;

	unsigned short *dst = ((unsigned short *) fbmem + y * width + x);

	*dst = color;
	return (0);
}


int main(int argc, char *argv[])
{
	int screen_fbd=0;
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;
	FILE           *infile;
	struct fb_fix_screeninfo fb_fix;
	struct fb_var_screeninfo fb_var;
	char *env=NULL;
	unsigned char  *buffer;
	unsigned char  *fbmem;
	short *color_white;
	unsigned short  color;
	unsigned int    x;
	unsigned int    y;
	if ((infile = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "open %s failed\n", argv[1]);
		exit(-1);
	}

	if(!(env = getenv("FRAMEBUFFER")))
	{
		env = "/dev/fb0";
	}

	screen_fbd = open(env, O_RDWR);

	if(screen_fbd < 0)
	{
		return 0;
	}

	if(ioctl(screen_fbd, FBIOGET_VSCREENINFO, &fb_var) == -1)
	{
		close(screen_fbd);
		return 0;
	}
	fb_width = fb_var.xres;
	fb_height = fb_var.yres;
	fb_depth = fb_var.bits_per_pixel;

	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);

	jpeg_stdio_src(&cinfo, infile);
	jpeg_read_header(&cinfo, TRUE);
	jpeg_start_decompress(&cinfo);
	if ((cinfo.output_width > fb_width) ||(cinfo.output_height > fb_height))
	{
		return (-1);
	}

	fbmem = mmap(0, fb_width * fb_height, PROT_READ | PROT_WRITE, MAP_SHARED, screen_fbd, 0);
	buffer = (unsigned char *) malloc(cinfo.output_width * cinfo.output_components);
	y = 0;

	while (cinfo.output_scanline < cinfo.output_height)
	{
		jpeg_read_scanlines(&cinfo, &buffer, 1);
		if (fb_depth == 16)
		{
			for (x = 0; x < cinfo.output_width; x++)
			{
				color = PIXELRGB888TO565(buffer[x * 3], buffer[x * 3 + 1], buffer[x * 3 + 2]);
				draw_pixel(fbmem, fb_width, fb_height, x, y, color);
			}
		}
		y++;
	}
	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);

	free(buffer);
	return 0;
}
