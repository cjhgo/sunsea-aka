#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"

#define N 1025

typedef struct node
{
	char * data;
	struct node * next;
}NODE, * PNODE;

char buf[N];		//存放fread读出来的值
char link_temp[N];	//临时存放合法网址

//自己实现的strncmp函数
int my_strncmp(char *p, char *q, int n)
{
	int i = 0;
	int count = 0;

	for( i = 0; i < n; i++)
	{
		if(*(p+i) == *(q+i))
		{
			count++;
		}
	}

	if(count == n)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//判断是否满足"<a "
char * judge_mark_a(char **p, int *count)
{
	while((0 != my_strncmp(*p, "<a ", 3)) && ('\0' != (**p)))
	{
		(*p)++;
		(*count)++;
	}

	if('\0' != (**p))
	{
		*p = *p + 3;
		(*count) = (*count) + 3;
		return *p;
	}
	else
		return NULL;
}

//判断是否满足****  href
char * judge_href(char **p, int * count)
{
	while(0 != (my_strncmp(*p, "href", 4)) && ('\0' != **p))
	{
		(*p)++;
		(*count)++;
	}

	if('\0' != **p)
	{
		*p = *p + 4;
		(*count) = (*count) + 4;
		return *p;
	}
	
	else
		return NULL;
}

//判断是否满足***  =
char * judge_equal_mark(char **p, int * count)
{
	while(' ' == **p)
	{
		(*p)++;
		(*count)++;
	}

	if('=' == **p)
	{
		return (*p) + 1;
	}
	else
	{
		return NULL;
	}
}

//判断是否满足**  ["]  ['] http
char * judge_http(char **p, int *count)
{
	while((' ' == **p) || ('\"' == **p) || ('\'' == **p))
	{
		(*p)++;
		(*count)++;				//11111111111111111111111111111
	}

	if('h' == **p)
	{
		return *p;
	}
	else
	{
		return NULL;
	}
/*
	while(0 != strncmp(*p, "http", 4) && ('\0' != (**p)))
	{
		(*p)++;
		(*count)++;
	}
	if('\0' != (**p))
	{	
		return *p;
	}
	else
	{
		return NULL;
	}
*/
}

//创建结点
PNODE create_node(void)
{
	PNODE new;
	new = malloc(sizeof(NODE));
	if(NULL == new)
	{
		printf("error:\n"); 
		exit(0);
	}
	
	return new;
}

//创建结点数据域空间
char * create_node_data(int *count)
{
	char * data;

	data = malloc(*count * sizeof(char));

	return data;
}

//每次插入到最后一个位置
PNODE insert_list(PNODE tmp, PNODE new)
{
	tmp->next = new;
	new->next = NULL;
	tmp = new;

	return tmp;
}

//处理网址结束位置
void judge_end(char **p, int *count, int *flag)
{
	int i = 0;
	PNODE new;

	if(NULL != *p)
	{
	//	while((**p != '\"') && (**p != '\'') && (**p != '>') && (**p != '\0') && (**p != ' ') && (**p != '\n'))
		while((**p != '\"') && ((**p) != '\'') && (**p != '\0') && (**p != '\n'))
		{
			link_temp[i++] = **p;
			(*p)++;
			(*count)++;
			if('\0' == (**p))
			{
				*flag = 0;			//flag = 0代表是1024个最后一个网址 
			}
		}
	
//		link_temp[i] = '\n';
//		*count = *count + 1;
	}
	
	return;
}

//保存至链表
PNODE save_to_list(PNODE temp, char link_temp[], int *count)
{
	PNODE new;

	if('\0' != *link_temp)
	{
		new = create_node();
		new->data = create_node_data(count);

		strcpy(new->data, link_temp);
		temp = insert_list(temp, new);
	}	

	return temp;
}

//功能：生成网址
void link(char *p, int * count, int *flag)
{
	char * ret;

	ret = judge_mark_a(&p, count);

	if(NULL != ret)
	{
		ret = judge_href(&ret, count);
	}

	if(NULL != ret)
	{
		ret = judge_equal_mark(&ret, count);
	}

	if(NULL != ret)
	{
		ret = judge_http(&ret, count);
	}

	if(NULL != ret)
	{
		judge_end(&ret, count, flag);
	}

	return;
}

//打印网址
void printf_link(PNODE head)
{
	int num = 0;

	head = head->next;

	while(NULL != head)
	{
		printf("%s\n", head->data);
		head = head->next;
		num++;
	}
	printf("num:%d\n", num); 

	return;
}

//把文件的所有内容读取为一个字符串，即：把全部内容读到一个字符串中
void read_file(int * pos, int *ret_read_file)
{
	FILE *fp;

	if((fp = fopen("link.html", "r")) == NULL)
	{
		perror("link.html");
		exit(0);
	}

	memset(buf, '\0', N);

	fseek(fp, *pos, 0);
	*ret_read_file = fread(buf, 1024, 1, fp);

	fclose(fp);

	return;
}

//从所有文件中获取合法链接，并连续的存入到链表（一个结点存放一个合法网址）
void get_every_link(PNODE temp, int *pos, int *count, int *ret_read_file, int *flag)
{
	int i = 0;

	while(0 != *ret_read_file)
	{
		i = 0;
		*flag = 1;
		read_file(pos, ret_read_file);						//对所有文件读取1024个字节，放到buf中

		while('\0' != buf[i])
		{
			*count = 0;
			memset(link_temp, 0, N);
			link(&buf[i], count, flag);					//得到合法网址，并存到全局变量link_temp中

			if((*flag == 1) && ('\0' != *link_temp))
			{
				temp = save_to_list(temp, link_temp, count);		//把合法网址报存到链表结点中
			}
			i = i + (*count) + 1;
		}

		if(*count == 1024)
		{
			*pos = *pos + 1024;
		}
		else
			*pos = *pos + 1024 - *count;
	}

	return;
}

void download_website(void)
{
	char website[N] = "wget -O link.html www.qq.com";

	system(website);

	return;
}

void save_to_database(PNODE head)
{
	sqlite3 * db;
	int ret, count;
	int i = 0;
	char *errmsg = NULL;
	char *sql = NULL;
	char sql_page[N] = {0};
	char sql_domain[N] = {0};
	PNODE p;

	//打开数据库
	ret = sqlite3_open("webspider.db", &db);
	if(ret != SQLITE_OK)
	{
		perror("webspider.db");
		exit(0);
	}

	//创建表websites
	sql = sqlite3_mprintf("create table websites (id integer primary key, domain text, page text, status integer);");
	printf("sql:%s\n", sql); 
	ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
	sqlite3_free(sql);
	if(ret != SQLITE_OK)
	{
		perror("create table websites");
		exit(0);
	}

	//插入数据，即：插入网址
	p = head->next;
	while(NULL != p)
	{
		count = 0;
		i = 0;
		memset(sql_domain, 0 ,strlen(sql_domain));
		while((count != 3) && *(p->data) != '?' && (*(p->data) != '\0'))
		{
			if(*(p->data) == '/')
			{
				count++;
			}
			sql_domain[i++] = *(p->data);
			p->data++;
		}
		memset(sql_page, 0, strlen(sql_page));
		if(p->data != NULL)
		{
			strcpy(sql_page, p->data);
		}
		else
		{
			strcpy(sql_page, "\0"); 
		}

		sql = sqlite3_mprintf("insert into websites (domain, page, status) values (%Q, %Q, %d)", sql_domain, sql_page, 0);
		printf("sql:%s\n", sql); 
		ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
		sqlite3_free(sql);
		if(ret != SQLITE_OK)
		{
			perror("insert into websites");
			exit(0);
		}

		p = p->next;
	}

	sqlite3_close(db);
	
}

int main(int argc, char* argv[])
{
	int pos = 0;
	int count = 0;
	int ret_read_file = -1;
	int flag = 1;
	int i = 0;
	PNODE head, temp;

	//下载网址
	download_website();

	temp = create_node();
	temp->next = NULL;
	head = temp;
	
	get_every_link(temp, &pos, &count, &ret_read_file, &flag);			//循环读文件，得到每一个合法的网址,并存入链表中

	save_to_database(head);

//	printf_link(head);								//输出网址，直接打印链表即可，因为把合法链接连续的存入到了链表

	return 0; 
}
