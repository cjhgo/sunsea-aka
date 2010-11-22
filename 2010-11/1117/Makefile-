main:main.o common.o fb_num.o get_win_table.o mouse.o draw.o computer.o player.o number.o
	gcc main.o common.o fb_num.o get_win_table.o mouse.o draw.o computer.o player.o number.o -o gobang -lm

main.o:
	gcc -c main.c -o main.o

common.o:common.c
	gcc -c common.c -o common.o

fb_num.o:fb_num.c
	gcc -c fb_num.c -o fb_num.o

get_win_table.o:get_win_table.c
	gcc -c get_win_table.c -o get_win_table.o

mouse.o:mouse.c
	gcc -c mouse.c -o mouse.o

draw.o:draw.c
	gcc -c draw.c -o draw.o

computer.o:computer.c
	gcc -c computer.c -o computer.o

player.o:player.c
	gcc -c player.c -o player.o

number.o:number.c
	gcc -c number.c -o number.o

r:
	clear
	sudo ./gobang

c:
	rm -f *.o
	rm -f gobang

.PHONY:c r
