OBJS=cp_file.o

all:my_cp

my_cp:$(OBJS)
	$(CC) -o my_cp $(OBJS) -lpthread

r:
	./my_cp

c:
	rm *.o my_cp -f

.PHONY:c r
