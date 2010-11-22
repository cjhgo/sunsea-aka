#include "common.h"

//判断特殊类型
int other (char *p)
{
	char *s1 = "+";
	char *s2 = "clickurl";
	char *s3 = "javascript";
	char *s4 = "\\";

	while('\0' != *p)
	{
		if((0 == my_strncmp(p, s1, 1)) || (0 == my_strncmp(p, s2, 8)) || (0 == my_strncmp(p, s3, 10)) || (0 == my_strncmp(p, s4, 1)))
		{
			break;
		}

		p++;
	}
	if('\0' == *p)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//从数据库中取网址，放到全局变量tmp_website[N]中
int rscallback(void *p, int column, char **column_val, char **column_name)
{
	memset(tmp_website, 0, N);
	strcpy(tmp_website, column_val[1]);
	id = atoi(column_val[0]);

	return 0;
}

//对数据库操作，包括打开数据库、创建表、插入数据库、关闭数据库
void do_database(PNODE head)
{
	sqlite3 * db;
	int ret;
	int i = 0;
	char *errmsg = NULL;
	char *sql = NULL;
	char *pdata;
	char website[N] = {0};
	PNODE p;

	//打开数据库
	ret = sqlite3_open("webspider.db", &db);
	if(ret != SQLITE_OK)
	{
		perror("webspider.db");
		exit(0);
	}

	//创建表websites
	sql = sqlite3_mprintf("create table websites (id integer primary key, website text unique, status integer);");
	ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
	sqlite3_free(sql);
/*	if(ret != SQLITE_OK)
	{
		printf("error:%d:%s\n", ret, errmsg); 
		exit(0);
	}
*/
	//插入数据
	p = head->next;
	while(NULL != p)
	{
		pdata = p->data;				//保存p->data首地址
		//判断网址是否含有域名
		while('\0' != *(p->data))
		{
			if((0 == my_strncmp(p->data, "http", 4)) || (0 == my_strncmp(p->data, "https", 5)))
			{
				break;
			}
			else
			{
				(p->data)++;
			}
		}
		//没有找到http，即没有域名，就需要手动添加域名
		if('\0' == *(p->data))
		{
			if(0 == other(pdata))
			{
				memset(website, 0, sizeof(website));
			//	strcat(website, "http://");
				strcat(website, tmp_website);
		//		strcat(website, "/");
				strcat(website, pdata);
			}
		}
		//找到http了，即网址中包含域名，直接把网址复制到website，存入数据库中
		else
		{
			memset(website, 0, strlen(website));
			strcpy(website, pdata);
		}
		p->data = pdata;		//把p->data复位，因为下面要释放p->data的空间

		printf("website=%s\n", website); 
		if('\0' != *website)
		{
		sql = sqlite3_mprintf("insert into websites (website, status) values (%Q, 0)", website);
		ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
		sqlite3_free(sql);
/*		if(ret != SQLITE_OK)
		{
			printf("warning:%d:%s\n", ret, errmsg); 
		}
*/
		}
		p = p->next;

	}

	sql = sqlite3_mprintf("select * from websites where status = 0 order by id asc limit 1;");
	ret = sqlite3_exec(db, sql, rscallback, NULL, &errmsg);
	sqlite3_free(sql);
	if(ret != SQLITE_OK)
	{
		printf("error:%d:%s\n", ret, errmsg); 
		exit(0);
	}

	sql = sqlite3_mprintf("update websites set status = 1 where id = %d", id);
	ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
	sqlite3_free(sql);
	if(ret != SQLITE_OK)
	{
		printf("error:%d:%s\n", ret, errmsg); 
		exit(0);
	}

	sqlite3_close(db);
}
