CC = gcc -g

TARGET = jpegtool

OBJS = jpeg.o capture.o

all: $(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $@ $^ -ljpeg

.PHONY:clean

clean:
	rm *.o $(TARGET) -f
cleanobj:
	rm *.o 
