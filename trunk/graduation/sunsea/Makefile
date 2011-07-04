# ##################################
# Name: 	 Makefile 
# Author: sunsea1026@gmail.com
# Date:  2011.03.25
# ##################################


CC=gcc				#编译器
CFLAGS=-g			#编译器参数
LIBS=-ljpeg -lm	-lpthread	#指明引用外部的库文件

PROGRAM=digital_frame		#生成的可执行文件

OBJS=digital_frame.o effects.o display_images.o mouse.o mouse_thread.o

all:$(PROGRAM)
	@echo ===============================================================
	@echo 可执行文件：$(PROGRAM)
	@echo 用      法：sudo ./$(PROGRAM)	
	@echo ===============================================================

$(PROGRAM):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	rm $(PROGRAM) *.o -rf

.PHONY:
	clean

r:
	clear
	sudo ./digital_frame
