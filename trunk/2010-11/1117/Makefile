OBJS=common.o computer.o draw.o fb_num.o get_win_table.o main.o mouse.o number.o player.o

all:gobang

gobang:$(OBJS)
	$(CC) -g -o gobang $(OBJS) -lm

c:
	rm *.o gobang -f

r:
	clear
	sudo ./gobang

.PHONY:c r
