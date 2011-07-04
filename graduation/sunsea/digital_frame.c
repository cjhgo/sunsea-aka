/*
 * =====================================================================================
 *
 *       Filename:  digital_frame.c
 *
 *    Description:  framebuffer下用libjeg库显示jpeg图片
 *
 *        Version:  1.0
 *        Created:  2011年03月21日 14时01分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sunsea1026@gmail.com  
 *
 * =====================================================================================
 */

#include "common.h"

//初始化fb0
void fb_init()
{
	//打开fb0设备文件
	fb_dev = open(FB_DEV, O_RDWR);
	if(fb_dev < 0)
	{
		printf("Error:open %s error\n", FB_DEV); 
		printf("Usage:[sudo ./digital_frame xxx.jpg]\n"); 
		exit(1);
	}

	//获取fb0参数
	ioctl(fb_dev, FBIOGET_VSCREENINFO, &fb_var);
	screen_w = fb_var.xres;
	screen_h = fb_var.yres;
	screen_bits = fb_var.bits_per_pixel;

//	printf("Framebuffer:%d * %d\n", screen_w, screen_h); 
//	printf("screen_bits:%d\n", screen_bits);

	fbmem = mmap(0, screen_w * screen_h * screen_bits / 8, PROT_READ | PROT_WRITE, MAP_SHARED, fb_dev, 0);

	return;
}

//判断图片格式
int judge_picture_mode(char *images_name)
{
	char header[8];

//	printf("picture = %s\n", images_name); 
	infile = fopen(images_name, "rb");
	if(infile == NULL)
	{
		printf("Error:open %s error!\n", images_name); 
		exit(1);
	}
 	memset(header, 0, sizeof(header));
	fread(&header, 8, 1, infile);
	fseek(infile, -8, 1);
	if((unsigned char)header[0] == 0xff)
	{
		return JPEG;
	}
	else if((unsigned char)header[0] == 0x89)
	{
		return PNG;
	}
	else if(0 == strncmp(header, "BM", 2))
	{
		return BMP;
	}
	else
	{
		return UNKNOWN;
	}
}

//插入到链表，每次插入到最后一个位置上
IMAGES_LIST *insert_to_list(IMAGES_LIST *images_tmp_head, IMAGES_LIST *images_new)
{
	images_tmp_head->next = images_new;
	images_new->next = NULL;

	images_tmp_head = images_new;

	return images_tmp_head;
}

//搜索所有图片，并存入链表中
void search_images()
{
	FILE *images_fd;
	char buffer[2048];
	char tmpbuf[IMAGES_NAME_SIZE];
	int i, j, id;
	system("ls images > images/images.txt");

	IMAGES_LIST *images_new, *images_tmp_head;
	images_head = (IMAGES_LIST *)malloc(sizeof(IMAGES_LIST));
	images_tmp_head = images_head;

	images_fd = fopen("images/images.txt", "rb");
	if(images_fd == NULL)
	{
		printf("Error:open images/images.txt error!\n"); 
		exit(1);
	}
	
	memset(buffer, 0, sizeof(buffer));
	fread(buffer, sizeof(buffer), 1, images_fd);

	i = 0;
	j = 0;
	id = 1;
	while(buffer[i] != '\0')
	{
		j = 0;
		memset(tmpbuf, 0, sizeof(tmpbuf));
		while(buffer[i] != '\n')
		{
			tmpbuf[j] = buffer[i];
			j++;
			i++;
		}
		images_new = (IMAGES_LIST *)malloc(sizeof(IMAGES_LIST));
		memset(images_new->images_name, 0, sizeof(images_new->images_name));
		strcpy(images_new->images_name, tmpbuf);
		images_new->images_id = id;
		id++;
		i += 1;

		images_tmp_head = insert_to_list(images_tmp_head, images_new);
	}

	return;
}

int main(int argc, char* argv[])
{
	int picture_mode;
	IMAGES_LIST *images_tmp;
	char images_name_path[IMAGES_NAME_PATH_SIZE];
	int i, j;
	char mouse_msg[10];
	int fd_mouse;
//	int x_old, y_old;
	pthread_t *ntid;

	ntid = (pthread_t *)malloc(sizeof(pthread_t));

	//fb0初始化
	fb_init();

	//搜索所有图片，并存入链表中
	search_images();

	printf("Are you want auto display, y or n?\n"); 
	scanf("%s", mouse_msg);
	if(0 == strcmp(mouse_msg, "y"))
	{
		mouse_control_switch = 0;
	}
	else if(0 == strcmp(mouse_msg, "n"))
	{
		mouse_control_switch = 1;
	}
	else
	{
		printf("Error: Please only input 'y' or 'n'!!!\n"); 
		exit(0);
	}

	if(mouse_control_switch == 0)
	{
		//打印所有图片名称，检查是否搜索正确
		images_tmp = images_head->next;
		while(images_tmp != NULL)
		{
			//判断图片格式
			memset(images_name_path, 0, sizeof(images_name_path));
			strcat(images_name_path, "images/");
			if(0 == strcmp(images_tmp->images_name, "images.txt"))
			{
				images_tmp = images_tmp->next;
				continue;
			}
			strcat(images_name_path, images_tmp->images_name);
			picture_mode = judge_picture_mode(images_name_path);
			switch(picture_mode)
			{
				case JPEG:
					printf("JPEG/JPG\n"); 
					display_jpeg();
					break;
				case PNG:
					printf("PNG\n"); 
	//				display_png();		//该功能未实现
					break;
				case BMP:
					printf("BMP\n"); 
					display_bmp();
					break;
				case UNKNOWN:
					printf("UNKNOWN\n"); 
					break;
				default:
					break;
			}
			images_tmp = images_tmp->next;
			sleep(1);
		}
	}
	
	if(mouse_control_switch == 1)
	{
		create_mouse_thread(ntid);
		
		//打印所有图片名称，检查是否搜索正确
		images_tmp = images_head->next;
		while(images_tmp != NULL)
		{
			if(click_switch == 0)
			{
				//判断图片格式
				memset(images_name_path, 0, sizeof(images_name_path));
				strcat(images_name_path, "images/");
				if(0 == strcmp(images_tmp->images_name, "images.txt"))
				{
					images_tmp = images_tmp->next;
					continue;
				}
				strcat(images_name_path, images_tmp->images_name);
				picture_mode = judge_picture_mode(images_name_path);
				switch(picture_mode)
				{
					case JPEG:
						printf("JPEG/JPG\n"); 
						display_jpeg();
						break;
					case PNG:
						printf("PNG\n"); 
		//				display_png();		//该功能未实现
						break;
					case BMP:
						printf("BMP\n"); 
						display_bmp();
						break;
					case UNKNOWN:
						printf("UNKNOWN\n"); 
						break;
					default:
						break;
				}
				images_tmp = images_tmp->next;
				sleep(1);
				click_switch = 1;
			}
		}
	}

	pthread_join(*ntid, NULL);

	free(ntid);
	fclose(infile);

	return 0; 
}
/* end of file*/
