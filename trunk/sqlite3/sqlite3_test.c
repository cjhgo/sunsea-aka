#include <stdio.h> 
#include <stdlib.h> 
#include "sqlite3.h"

int rscallback (void *p, int argc, char **argv, char **argvv)
{
	int i;

	*(int *)p = 0;

	for(i = 0; i < argc; i++)
	{
		printf("%s > \t%s\t\t",argvv[i],argv[i]); 
	}
	printf("\n"); 
	
	return 0; 

}

int main(int argc, char* argv[])
{
	sqlite3 * db;
	char * errmsg = NULL; 
	int result = 0;
	int empty = 1;

	result = sqlite3_open("test.db",&db);
	if(result != SQLITE_OK)
	{
		printf("open database error!\n"); 
		exit(1);
	}

	result = sqlite3_exec(db, "create table test_table(id integer primary key, name text);", NULL, NULL, &errmsg);
	if(result != SQLITE_OK)
	{
		printf("error:%d:%s\n",result, errmsg); 
		exit(1);
	}

/*	result = sqlite3_exec(db, "insert into test_table values (1, 'zhangsan');", NULL, NULL, &errmsg);
	if(result != SQLITE_OK)
	{
		printf("error:%d:%s\n",result, errmsg); 
		exit(1);
	}

	result = sqlite3_exec(db, "insert into test_table values (2, 'li');", NULL, NULL, &errmsg);
	if(result != SQLITE_OK)
	{
		printf("error:%d:%s\n",result, errmsg); 
		exit(1);
	}

	result = sqlite3_exec(db, "insert into test_table values (3, 'wangwu');", NULL, NULL, &errmsg);
	if(result != SQLITE_OK)
	{
		printf("error:%d:%s\n",result, errmsg); 
		exit(1);
	}
*/
	result = sqlite3_exec(db, "select * from test_table;", rscallback, &empty, &errmsg);
	if(empty)
	{
		printf("the table is empty!\n"); 
	}
	sqlite3_close(db);

	return 0; 
}
