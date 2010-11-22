main:five.o
	gcc five.o -o five

five.o:five.c
	gcc -c five.c -o five.o

run:
	sudo ./five

clean:
	-rm -f *.o
	-rm -f five

.PHONY:clean run
