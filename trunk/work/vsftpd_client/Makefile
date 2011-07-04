OBJS=vsftpd_client.o
CC=gcc
#CC=arm-linux-gcc
CFLAGS= -g -Wall
EXEC=vsftpd_client

$(EXEC):$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $@

clean:
	$(RM) *.o $(EXEC)
v:
	vim vsftpd_client.c
