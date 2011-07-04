源文件说明:
	1：digital_frame.c		//主文件
	2：display_images.c		//显示图片，bmp？jpeg？png？,png格式的图片未实现显示功能
	3：effects.c			//显示图片特效合集
	4：common.h			//公共内容
	5：Makefile			//Makefile文件

执行说明：
	由于需要使用linux的设备文件fb0，所有执行时需要管理员身份
	sudo ./digital_frame

缺陷说明：
	目前不支持png格式的显示

公共接口：
	picture_w, picture_h, picture_bits, picture_color, fbp, buffer, tmpbuf;
