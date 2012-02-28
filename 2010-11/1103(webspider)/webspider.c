#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include "sqlite3.h"

#define N 1025

typedef struct node
{
	char * data;
	struct node * next;
}NODE, * PNODE;

char buf[N];		//存放fread读出来的值
char link_temp[N];	//临时存放合法网址
char tmp_website[N];	//存放从数据库中取出的网址
int id;			//记录从数据库中取出的网址的id号
int id_for_page;	//为了找到存放page内容设计的变量

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
		(*p) = (*p) + 1;
		(*count) = (*count) + 1;
		while((' ' == **p) || ('\"' == **p) || ('\'' == **p))
		{
			(*p)++;
			(*count)++;
		}
		return (*p);
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
		(*count)++;
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
char * create_node_data(int *link_len)
{
	char * data;

	data = malloc((*link_len) * sizeof(char));

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
void judge_end(char **p, int *count, int *flag, int *link_len)
{
	int i = 0;
	PNODE new;

	if(NULL != *p)
	{
	//	while((**p != '\"') && (**p != '\'') && (**p != '>') && (**p != '\0') && (**p != ' ') && (**p != '\n'))
		while((**p != '\"') && ((**p) != '\'') && (**p != '\0') && (**p != '\n') && (**p != '?'))
		{
			link_temp[i++] = **p;
			(*p)++;
			(*count)++;
			(*link_len)++;
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
PNODE save_to_list(PNODE temp, char link_temp[], int *link_len)
{
	PNODE new;

	if('\0' != *link_temp)
	{
		new = create_node();
		(*link_len) = (*link_len) + 1;		//+1是为了给\0分配空间
		new->data = create_node_data(link_len);

		strcpy(new->data, link_temp);
		temp = insert_list(temp, new);
	}

	return temp;
}

//功能：生成网址
void link(char *p, int * count, int *flag, int *link_len)
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
/*
	if(NULL != ret)
	{
		ret = judge_http(&ret, count);
	}
*/
	if(NULL != ret)
	{
		judge_end(&ret, count, flag, link_len);
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
void get_every_link(PNODE temp, int *pos, int *count, int *ret_read_file, int *flag, int *link_len)
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
			link(&buf[i], count, flag, link_len);					//得到合法网址，并存到全局变量link_temp中

			if((*flag == 1) && ('\0' != *link_temp))
			{
				temp = save_to_list(temp, link_temp, link_len);		//把合法网址报存到链表结点中
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

void download_website(char *p)
{
	char website[N] = "wget -O temp_link.html ";
	char *convert = "iconv -f gbk -t utf8 temp_link.html > link.html";	//把源文件字符编码转化为utf-8

	strcat(website, p);

	system(website);
	system(convert);

	return;
}

//从数据库中取网址，放到全局变量tmp_website[N]中
int rscallback(void *p, int column, char **column_val, char **column_name)
{
	memset(tmp_website, 0, N);
	strcpy(tmp_website, column_val[1]);
	id = atoi(column_val[0]);

	return 0;
}

int other(char *p)
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

//释放整个链表
void free_list(PNODE head)
{
	PNODE p, p_current;

	p = head;
	p_current = p;
	p = p->next;
	free(p_current);

	while(NULL != p)
	{
		p_current = p;
		p = p->next;
		free(p_current->data);
		free(p_current);
	}

	return;
}

int main(int argc, char* argv[])
{
	int pos = 0;
	int count = 0;
	int ret_read_file = -1;
	int flag = 1;
	int i = 0;
	int j = 0;
	int link_len = 0;
	PNODE head, temp;
	printf("please input a website....\n"); 
	scanf("%s", tmp_website);

	while(j < 3)
	{
		//下载网址
		download_website(tmp_website);

		temp = create_node();
		temp->next = NULL;
		head = temp;
		
		pos = 0;
		count = 0;
		ret_read_file = -1;
		flag = 0;
		i = 0;
		link_len = 0;
		get_every_link(temp, &pos, &count, &ret_read_file, &flag, &link_len);			//循环读文件，得到每一个合法的网址,并存入链表中

		printf("Please wait for a moment, we are conducting a database operation....\n"); 

		do_database(head);			//包括打开数据库、创建表、从链表存入数据库、从数据库中取出网址、修改status，关闭数据库

//		printf_link(head);			//输出网址，直接打印链表即可，因为把合法链接连续的存入到了链表
		free_list(head);


		printf("id = %d\n", id); 
	}


	return 0; 
}
