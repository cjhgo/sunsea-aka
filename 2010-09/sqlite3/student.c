/* 项目名称：用c语言动态操作sqilite3数据库
 *
 * 项目成员：张双喜
 *
 * 编译环境：gcc
 *
 * 项目功能：
 * 	1、动态创建表
 * 	2、动态实现对表的基本操作（增、删、改、查）
 * 	3、清空表数据、删除表（附加功能）
 *
 * 项目总结：
 * 	1、涉及的技术：
 * 		
 * 		1、int sqlite3_exec(sqlite3*, const char *sql, sqlite_callback, void*, char**);
 * 	　　　　　欲实现动态操作数据库，必须动态构造sql语句，构造sql语句可以用strcat函数，逐步拼接，直至完整构造出sql语句。
 * 		
 * 		2、欲实现简单菜单选项效果，须分离出实现每个子功能的函数，在switch中，选择的调用
 * 		
 * 		3、
 *
 * 	2、意外收获：
 * 		
 * 		1、想输入一条带有空格的字符串，不能用scanf函数，应为scanf函数遇到空格、换行、回车自动结束输入，所以scanf不能达到预期效果
 * 		　，解决该问题可以使用gets函数，但是gets是个危险函数，c语言不提倡使用，在使用gets函数前，一定要清空缓冲区，否则。会出现
 * 		　意想不到的输入结果，这就是先前没有清空缓冲区造成的。
 * 		
 * 		2、linux c 清空缓冲区的问题：
 * 			个人见解：
 * 				经测试，linux c 使用fflush(stdin)无法清空缓冲区，使用fflush(stdin)后，再使用gets函数，gets还是会从缓冲区中读取东西，
 * 				因为缓冲区经fflush(stdin)没有被清空；
 * 				经过在网上找资料，得知setbuf(stdin, NULL);这样一个函数，经测试，清理缓冲区成功。
 *
 * 			简言之：linux c 清空缓冲区的函数：setbuf(stdin, NULL);
 *
 * 	3、编程中问题及其解决方法：
 *
 * 		1、更新数据库update正确使用方法：
 * 			update table_name set name = 'new_name', sex = 'new_sex' where id = id_val;		//是正确的
 * 			上句中的,不能换成and，
 * 			即：
 * 			update table_name set name = 'new_name' and sex = 'new_sex' where id = id_val;		//是错误的
 *		
 *		2、字符串的问题：
 *			char * p = "hello world!";	//该字符串是只读的不能修改字符串，不能改写，不能strcat(p, "jack");
 *
 *			char str[] = "hello world!"	//这样可以通过指针或不通过指针对字符串进行任意操作
 *			char *p;
 *			p = str;
 *
 *		3、字符串清理零：
 *			char str[10];
 *
 *			memset(str, 0,sizeof(str));
 *
 * 
 *
 *
 * 	张双喜
 * 	v1.0
 * 	2010.9.29	14:39
 *
 * update 1
 * 	
 * 	1、增加了一个测试表test_table，解决了，每次对操作数据库必须首先建立一个表的bug
 * 	2、增加了确认退出功能
 *
 * 	张双喜
 * 	v2.0
 * 	2010.9.30	9:40
 * 		
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"

/*该结构体是方便对表内数据操作*/

typedef struct table_column
{
	char column_name[100];		//列名
	char column_type[200];		//列的数据类型
}COLUMN;

void db_create(sqlite3 * db, char * pTable_name, int column_num, COLUMN column[], int * create_flag);
int rscallback(void * p, int column, char ** column_val,char ** column_name);
void db_show(sqlite3 * db, char * pTable_name);
void db_insert(sqlite3 * db, char * pTable_name, int column_num, COLUMN column[], int * test_flag, int * create_flag);
void db_update(sqlite3 * db, char * pTable_name, int column_Num, COLUMN column[], int * test_flag, int * create_flag);
void db_delete(sqlite3 * db, char * pTable_name);
void db_empty(sqlite3 * db, char * pTable_name);
void db_drop(sqlite3 * db, char *pTable_name, int * test_flag, int * create_flag);
void db_test(sqlite3 * db, char * pTable_name, int ** test_flag);
void db_flag(sqlite3 * db, int * create_flag, int * test_flag, char * pTable_name);
void db_reset_table_name(sqlite3 * db, char * pTable_name);

int main(int argc, char* argv[])
{
	sqlite3 * db;
	int empty = 1;
	int ret = 0;
	int create_flag = 1;
	int test_flag = 1;
	int test_flag_create = 1;
	char c = 'n';
	char * errmsg = NULL;
	int choice = -1;
	char table_name[20];
	char * pTable_name;
	int column_num;
	int i;
	COLUMN column[10];
	pTable_name = table_name;
	strcpy(pTable_name, "test_table");

	ret = sqlite3_open("student.db", &db);
	if(ret != SQLITE_OK)
	{
		perror("slqite3_open");
		exit(1);
	}

	while(choice != 0)
	{
		printf("please input your choise:\n"); 
		printf("------------------------------------------------------------------\n");
		printf("|0.exit|1.create|2.show|3.insert|4.update|5.delete|6.empty|7.drop|\n"); 
		printf("------------------------------------------------------------------\n"); 
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 0:
					printf("you choise leave, y or n?\n"); 
					setbuf(stdin, NULL);
					scanf("%c", &c);
					setbuf(stdin, NULL);
					if(c == 'y')
					{
						if(test_flag == 0)
						{
							db_drop(db, "test_table", &test_flag, &create_flag);
						}
						
						printf("goodbye!\n"); 

						sqlite3_close(db);

						return 0;
					}
					else
					{
						choice = -1;
					}

					break;
					
			case 1:
					printf("we will create a table for you, please input the name of your table:\n"); 
					scanf("%s",pTable_name);
					printf("please input the number of column:\n"); 
					scanf("%d", &column_num);
					printf("please input column_name column_type:\n"); 

					for(i = 0; i < column_num; i++)
					{
						scanf("%s %s", column[i].column_name, column[i].column_type);						
					}

					db_create(db, table_name, column_num, column, &create_flag);
					break;
			case 2:
					db_flag(db, &create_flag, &test_flag, table_name);
					db_show(db, table_name);
					break;
			       
			case 3:
					db_flag(db, &create_flag, &test_flag, table_name);
					db_insert(db, table_name, column_num, column, &test_flag, &create_flag);
					break;
			case 4:
					db_flag(db, &create_flag, &test_flag, table_name);
					db_update(db, table_name, column_num, column, &test_flag, &create_flag);
					break;
			case 5:
					db_flag(db, &create_flag, &test_flag, table_name);
					db_delete(db, table_name);
					break;
			case 6:
					db_flag(db, &create_flag, &test_flag, table_name);
					db_empty(db, table_name);
					break;
			case 7:
					db_flag(db, &create_flag, &test_flag, table_name);
					db_drop(db, table_name, &test_flag, &create_flag);
					break;
			default:
					printf("your choice is not exist!\n"); 
					break;
	
		}
		
	}

	sqlite3_close(db);

	return 0; 
}

void db_flag(sqlite3 * db, int * create_flag, int * test_flag, char * pTable_name)
{
	if(create_flag)
	{
		if(*test_flag)
		{
			db_test(db, pTable_name, &test_flag);
		}
		
	}

	return;
}

void db_test(sqlite3 * db, char * pTable_name, int ** test_flag)
{
	int ret;
	char * errmsg;

	**test_flag = 0;

	printf("because you have not create a table,so we create a test_table table for you!\n"); 
	ret = sqlite3_exec(db, "create table test_table (id integer primary key autoincrement, name text, sex text, age integer);", NULL, NULL, &errmsg);
	if(ret != SQLITE_OK)
	{
		printf("error:%d:%s\n", ret, errmsg); 
		exit(1);
	}
	ret = sqlite3_exec(db, "insert into test_table (name, sex, age) values ('zsx', 'm', 23);",NULL ,NULL, &errmsg);
	if(ret != SQLITE_OK)
	{
		printf("error:%d:%s\n", ret, errmsg);
		exit(1);
	}

	return;
}

void db_create(sqlite3 * db, char * pTable_name, int column_num, COLUMN column[], int * create_flag)
{
	int ret, i;
	char * errmsg = NULL;
	char sql[200];
	char * pSql;

	*create_flag = 0;
	
	pSql = sql;

	strcpy(pSql, "create table ");
	
	strcat(pSql, pTable_name);
	
	strcat(pSql, "(");

	strcat(pSql, column[0].column_name);
	strcat(pSql, " ");
	strcat(pSql, column[0].column_type);
	strcat(pSql, " primary key autoincrement");
	strcat(pSql, ", ");

	for(i = 1; i < column_num-1; i++)
	{
		strcat(pSql, column[i].column_name);
		strcat(pSql, " ");
		strcat(pSql, column[i].column_type);
		strcat(pSql, ", ");
	}

	strcat(pSql, column[column_num-1].column_name);
	strcat(pSql, " ");
	strcat(pSql, column[column_num-1].column_type);
	strcat(pSql, ");");

	printf("\nsqlite > %s\n\n",pSql);

	ret = sqlite3_exec(db, pSql, NULL, NULL, &errmsg);
	if(ret != SQLITE_OK)
	{
		 printf("error:%d:%s\n", ret, errmsg); 
		 exit(1);
	}
	
	return; 
}

int rscallback(void * p, int column, char ** column_val,char ** column_name)
{
	int i;
	*(int *)p = 0;

	for(i = 0; i < column; i++)
	{
		printf("%s > %s\t\t",column_name[i], column_val[i]);
	}
	printf("\n"); 
	return 0; 
}

void db_show(sqlite3 * db, char * pTable_name)
{
	int ret = 0;
	char * errmsg = NULL;
	int empty = 1;
	char sql[200];
	char * pSql;

	pSql = sql;

	strcpy(pSql, "select * from ");
	strcat(pSql, pTable_name);
	strcat(pSql, ";");
	printf("\nsqlite > %s\n\n", pSql); 

	ret = sqlite3_exec(db, pSql, rscallback, &empty, &errmsg);
	if(ret != SQLITE_OK)
	{
		printf("error:%d:%s\n", ret, errmsg);
		exit(1);
	}

	if(empty)
	{
		printf("the table is empty!\n"); 
	}

	printf("\n"); 
	return; 
}

void db_insert(sqlite3 * db, char * pTable_name, int column_num, COLUMN column[], int * test_flag, int * create_flag)
{
	int ret = 0;
	char * errmsg = NULL;
	char sql[200];
	char * pSql;
	char tmp[20];
	int i;
	char test_val[100];

	pSql = sql;
	strcpy(pSql, "insert into ");
	strcat(pSql, pTable_name);
	strcat(pSql, "(");

	if((*test_flag == 0) && (*create_flag))
	{
		strcat(pSql, " name, ");
		strcat(pSql, "sex, ");
		strcat(pSql, "age ) ");
		strcat(pSql, "values (");

		printf("please input name:\n"); 
		scanf("%s", test_val);
		strcat(pSql, " \'");
		strcat(pSql, test_val);
		strcat(pSql, "\', ");
		printf("please input sex:\n"); 
		scanf("%s", test_val);
		strcat(pSql, "\'");
		strcat(pSql, test_val);
		strcat(pSql,"\', ");
		printf("please input age:\n");
		scanf("%s",test_val);
		strcat(pSql,test_val);
		strcat(pSql, ");");
	}
	if(*create_flag == 0)
	{
		for(i = 1; i < column_num-1; i++)
		{
			strcat(pSql, column[i].column_name);
			strcat(pSql, ", ");
		}

		strcat(pSql, column[column_num-1].column_name);
		strcat(pSql, ") ");
		strcat(pSql, "values(");
		for(i = 1; i < column_num-1; i++)
		{
			printf("please input %s\n",column[i].column_name);
			if(strcmp(column[i].column_type,"text") == 0)
			{
				strcat(pSql, "\'");
				memset(tmp, 0, sizeof(tmp));
				scanf("%s",tmp);
				strcat(pSql, tmp);
				strcat(pSql,"\'");
				strcat(pSql, ",");
			}
			else
			{
				memset(tmp,0,sizeof(tmp));
				scanf("%s",tmp);
				strcat(pSql, tmp);
				strcat(pSql,",");
				strcat(pSql," ");
			}
		}
		printf("please input %s\n",column[column_num-1].column_name);
		if(strcmp(column[column_num-1].column_type, "text") == 0)
		{
			scanf("%s",tmp);
			strcat(pSql, "\'");
			strcat(pSql, tmp);
			strcat(pSql, "\'");
			strcat(pSql, ");");
		}
		else
		{
			scanf("%s",tmp);
			strcat(pSql, tmp);
			strcat(pSql, ");");
		}
	}
	printf("\nsqlite > %s\n\n", pSql); 
  
	ret = sqlite3_exec(db, pSql, NULL, NULL, &errmsg);
	if(ret != SQLITE_OK)
	{
		printf("error:%d:%s\n", ret, errmsg);
		exit(1);
	}

	return;
}

void db_update(sqlite3 * db, char * pTable_name, int column_num, COLUMN column[], int * test_flag, int * create_flag)
{
	int ret = 0;
	char * errmsg = NULL;
	char sql[200];
	char * pSql;
	char new_val[20];
	char  new_id[3];
	int i;
	char test_val[100];
	

	pSql = sql;
	strcpy(pSql, "update ");
	strcat(pSql, pTable_name);
	strcat(pSql, " set ");

	if((*test_flag == 0) && (*create_flag))
	{
		strcat(pSql, "name = ");
		printf("please input a new name:\n");
		scanf("%s",test_val);
		strcat(pSql,"\'");
		strcat(pSql,test_val);
		strcat(pSql, "\', sex = ");
		printf("please input a new sex: \n");
		scanf("%s", test_val);
		strcat(pSql, "\'");
		strcat(pSql, test_val);
		strcat(pSql, "\', age = ");
		printf("please input a new age:\n");
		scanf("%s",test_val);
		strcat(pSql,test_val);
		strcat(pSql, " where id = ");
		printf("please input a id that you want to change:\n"); 
		scanf("%s",test_val);
		strcat(pSql, test_val);
		strcat(pSql, ";");	
	}
	if(*create_flag == 0)
	{
		for(i = 1; i < column_num-1; i++)
		{
			strcat(pSql, column[i].column_name);
			strcat(pSql, " = ");
			if(strcmp(column[i].column_type, "text") ==0)
			{
				strcat(pSql, "\'");
				memset(new_val, 0, sizeof(new_val));
				printf("please input a new %s\n", column[i].column_name); 
				scanf("%s",new_val);
				strcat(pSql, new_val);
				strcat(pSql, "\'");
				strcat(pSql, " , ");
			}
			else
			{
				memset(new_val, 0, sizeof(new_val));
				printf("please input a new %s\n", column[i].column_name); 
				scanf("%s",new_val);
				strcat(pSql, new_val);
				strcat(pSql, " , ");
			}
		}

		strcat(pSql, column[i].column_name);
		strcat(pSql, " = ");

		if(strcmp(column[column_num-1].column_type, "text") ==0)
		{
			strcat(pSql, "\'");
			memset(new_val, 0, sizeof(new_val));
			printf("please input a new %s\n", column[i].column_name); 
			scanf("%s",new_val);
			strcat(pSql, new_val);
			strcat(pSql, "\'");
			strcat(pSql, " ");
		}
		else
		{
			memset(new_val, 0, sizeof(new_val));
			printf("please input a new %s\n", column[i].column_name); 
			scanf("%s",new_val);
			strcat(pSql, new_val);
			strcat(pSql, " ");
		}

		strcat(pSql, "where id = ");
		printf("please input the id that you want to change its value:\n"); 
		scanf("%s",new_id);
		strcat(pSql, new_id);
		strcat(pSql, ";");
	}
	printf("sqlite > %s\n\n",pSql); 
	 
	ret = sqlite3_exec(db, pSql, NULL, NULL, &errmsg);
	if(ret != SQLITE_OK)
	{
		printf("error:%d:%s\n", ret, errmsg);
		exit(1);
	}

	return;
	
}

void db_delete(sqlite3 * db, char * pTable_name)
{
	int ret = 0;
	char * errmsg = NULL;
	char sql[200];
	char * pSql;
	char tmp_name[20];
	char tmp_id[3];
	

	pSql = sql;
	strcpy(pSql, "delete from ");
	strcat(pSql, pTable_name);
	strcat(pSql, " where id = ");
	printf("please input a id that you want to delete:\n"); 
	scanf("%s",tmp_id);
	strcat(pSql, tmp_id);
	strcat(pSql, ";");

	printf("\nsqlite > %s\n\n",pSql); 
	 
	ret = sqlite3_exec(db, pSql, NULL, NULL, &errmsg);
	if(ret != SQLITE_OK)
	{
		printf("error:%d:%s\n", ret, errmsg);
		exit(1);
	}

	return;
}

void db_empty(sqlite3 * db, char * pTable_name)
{
	int ret = 0;
	char * errmsg = NULL;
	char sql[200];
	char * pSql;


	pSql = sql;
	strcpy(pSql, "delete from ");
	strcat(pSql, pTable_name);
	strcat(pSql,";");

	printf("\nsqlite > %s\n\n",pSql); 

	ret = sqlite3_exec(db, pSql, NULL, NULL, &errmsg);
	if(ret != SQLITE_OK)
	{
		printf("error:%d:%s\n", ret, errmsg); 
		exit(1);
	}

	return;
}
	
void db_drop(sqlite3 * db, char * pTable_name, int * test_flag, int * create_flag)
{
	int ret = 0;
	char * errmsg = NULL;
	char sql[200];
	char * pSql;


	pSql = sql;
	strcpy(pSql, "drop table ");
	strcat(pSql, pTable_name);
	strcat(pSql,";");

	if(*test_flag)
	{
		printf("\nsqlite > %s\n\n",pSql); 
	}

	if(*create_flag == 0)
	{
		printf("\nsqlite > %s\n\n",pSql); 
	}

	ret = sqlite3_exec(db, pSql, NULL, NULL, &errmsg);
	if(ret != SQLITE_OK)
	{
		printf("error:%d:%s\n", ret, errmsg); 
		exit(1);
	}

	return;
}

