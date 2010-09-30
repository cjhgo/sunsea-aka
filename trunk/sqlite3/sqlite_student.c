#include <stdio.h> 
#include <stdlib.h>
#include "sqlite3.h"

int rscallback(void * p, int column, char ** column_val, char ** column_name)
{
	int i;

	*(int *)p = 0;

	for(i = 0; i < column; i++)
	{
//		printf("  \t%s\t\t",  column_val[i]); 
		printf("%s > \t%s\t\t", column_name[i], column_val[i]); 
	}
	printf("\n"); 
	 
	return 0; 
}

int main(int argc, char* argv[])
{
	sqlite3 * db;
	int rc = 0;
	char * err = NULL;
	int empty = 1;

	rc = sqlite3_open("student.db", &db);
	if(rc != SQLITE_OK)
	{
		printf("open database error!\n"); 
		exit(1);
	}
	char (* name)[100];
	int i;

//	rc = sqlite3_key(db, "abc", 3);

/*	rc = sqlite3_exec(db, "create table student(id integer primary key autoincrement, name text, sex text, age integer);", NULL, NULL, &err);		//autoincrement 自动增长
	if(rc != SQLITE_OK)
	{
		printf("error:%d:%s\n",rc,err); 
		exit(1);
	}
*/
	rc = sqlite3_exec(db, "insert into student(name, sex, age) values('jack', 'm', 18);", NULL, NULL, &err);
	if(rc != SQLITE_OK)
	{
		printf("error:%d:%s\n",rc,err); 
		exit(1);
	}

	rc = sqlite3_exec(db, "insert into student(name, sex, age) values('lily', 'f', 16);", NULL, NULL, &err);
	if(rc != SQLITE_OK)
	{
		printf("error:%d:%s\n",rc,err); 
		exit(1);
	}

	rc = sqlite3_exec(db, "insert into student(name, sex, age) values('john', 'm', 20);", NULL, NULL, &err);
	if(rc != SQLITE_OK)
	{
		printf("error:%d:%s\n",rc,err); 
		exit(1);
	}

	rc = sqlite3_exec(db, "select * from student;", rscallback, &empty, &err);
	if(rc != SQLITE_OK)
	{
		printf("error:%d:%s\n",rc,err);
		exit(1);
	}

	if(empty)
	{
		printf("table is empty!\n");
	}

	printf("\nafter delete\n"); 
	rc = sqlite3_exec(db, "delete from student where id = 1;", NULL, NULL, &err);
	if(rc != SQLITE_OK)
	{
		printf("error:%d:%s\n",rc,err);
		exit(1);
	}

	rc = sqlite3_exec(db, "select * from student;", rscallback, &empty, &err);
	if(rc != SQLITE_OK)
	{
		printf("error:%d:%s\n",rc,err);
		exit(1);
	}

	printf("\nafter update\n"); 
	rc = sqlite3_exec(db, "select name from sqlite_master;",stdout, NULL, &err);
//	rc = sqlite3_exec(db, "update student set name = 'jack' where name = 'john';", NULL, NULL, &err);
	if(rc != SQLITE_OK)
	{
		printf("error:%d:%s\n",rc,err);
		exit(1);
	}
	for(i = 0; i < 100; i++)
		printf("%s\n",(*name)[i]); 

	rc = sqlite3_exec(db, "select * from student;", rscallback, &empty, &err);
	if(rc != SQLITE_OK)
	{
		printf("error:%d:%s\n",rc,err);
		exit(1);
	}

	return 0; 
}
