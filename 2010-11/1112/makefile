main:five.o
	gcc five.o -o five -lm

five.o:five.c
	gcc -c five.c -o five.o

r:
	clear
	sudo ./five
v:
	vim five.c


c:
	-rm -f *.o
	-rm -f five

.PHONY:c r v
