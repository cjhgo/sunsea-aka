#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"


char buf[100];

int rscallback (void *p, int column, char **column_val, char **column_name)
{
	int i = 0;
	for(i= 0; i < column; i++)
	{
		printf("%s  ", column_val[i]); 
	}
	strcpy(buf, column_val[1]);
	printf("\n"); 

	return 0; 
}

int main(int argc, char* argv[])
{
	sqlite3 *db;
	int ret;

	ret = sqlite3_open("1.db", &db);

	ret = sqlite3_exec(db, "create table qq (id integer primary key, name text, num integer)", NULL, NULL, NULL);

	ret = sqlite3_exec(db, "insert into qq (name, num) values ('jack', 1)", NULL, NULL,NULL);
	ret = sqlite3_exec(db, "insert into qq (name, num) values ('jim', 1)", NULL, NULL,NULL);
	ret = sqlite3_exec(db, "insert into qq (name ,num) values ('lili', 1)", NULL, NULL,NULL);
	ret = sqlite3_exec(db, "insert into qq (name, num) values ('lucy', 0)", NULL, NULL,NULL);
	ret = sqlite3_exec(db, "insert into qq (name, num) values ('susan', 0)", NULL, NULL,NULL);

	ret = sqlite3_exec(db, "select * from qq where num = 0 order by id asc limit 1;", rscallback, NULL, NULL);

	printf("buf = %s\n", buf); 
	sqlite3_close(db);

	return 0; 
}
