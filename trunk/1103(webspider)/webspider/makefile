main:main.o do_database.o download.o file_to_list.o my_strncmp.o free_list.o
	gcc main.o do_database.o download.o file_to_list.o my_strncmp.o free_list.o -o webspider -lsqlite3

main.o:main.c common.h
	gcc -c main.c -o main.o

do_database.o:do_database.c common.h
	gcc -c do_database.c -o do_database.o 

download.o:download.c common.h
	gcc -c download.c -o download.o

file_to_list.o:file_to_list.c common.h
	gcc -c file_to_list.c -o file_to_list.o

my_strncmp.o:my_strncmp.c common.h
	gcc -c my_strncmp.c -o my_strncmp.o

free_list.o:free_list.c common.h
	gcc -c free_list.c -o free_list.o

clean:
	-rm main.o do_database.o download.o file_to_list.o my_strncmp.o free_list.o webspider
.PHONY:clean
