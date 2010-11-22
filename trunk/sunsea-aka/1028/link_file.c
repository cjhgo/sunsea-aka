/*
 * 名称：步步递近网络蜘蛛（二）
 *
 * 版本：v2.0
 * 
 * 作者：张双喜
 *
 * 日期：2010.10.21
 *
 * 功能：从文件中读取合法的网址（在html中语法表达中正确的网址），并把所有网址存入在链表中,最后打印所有合法网址。
 *
 * 设计思想：
 *	1、如何查找网址？
 *		1.参考版本v1.0，即：可以成功读取程序中定义的字符串中合法网址
 *
 *	2、如何获取合法网址？
 *		1.fread(buf, 1024, 1, fp)
 *			从文件中一次读取1024个字节内容，存入buf[]，其中这1024个字节内容可能包括合法的网址、非法的网址、换行符号\n、空格等其他符号
 *		2.get_string_from_1024()
 *			对1024个字符进行解析，即：把第一次出现\n前的内容存入str[]中,然后对str[]中的内容进行是否是合法网址判断，
 *			如果是合法网址，把该网址存入单链表
 *		3.get_every_link()
 *			获取每一个网址
 *			该函数框架大致如下：
 *			get_every_link()
 *			{
 *				while()					//条件：read_file的返回值
 *				{
 *					read_file();
 *					while()				//条件：1024个是否是末尾
 *					{
 *						link();			//找出一个网址
 *						save_to_list();		//保存到链表
 *					}
 *				}
 *			}
 *			说明：
 *				链表中一个结点存放一个合法的网址
 *
 *	3、如何输出所有合法网址？
 *		1.printf_link()
 *			打印网址，即：打印链表，因为所有合法网址都顺序的存放在该链表中。
 *
 * update 1
 * 	修正了原来链表中一个结点只存放一个字符的问题，现在修正为一个结点存放一个字符串
 *
 * 	还存在的问题：
 * 		fread读文件时效率太低，因为在buf中如果出现了合法网址，就要从这个合法网址开始下一次读文件，每次读文件时可能会重复读很多内容，从而导致效率偏低
 *
 *	版本：v2.1
 *
 * 	作者：张双喜
 *
 * 	日期：2010.10.22
 *
 * update 2
 * 	修正了v2.1版本效率低的问题
 * 	修正了注释不恰当的问题
 *
 * 	版本：v2.2
 *
 * 	作者：张双喜
 *
 * 	日期：2010.10.27
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	
		link_temp[i] = '\n';
		*count = *count + 1;
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
		printf("%s", head->data);
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

int main(int argc, char* argv[])
{
	int pos = 0;
	int count = 0;
	int ret_read_file = -1;
	int flag = 1;
	int i = 0;
	PNODE head, temp;

	temp = create_node();
	temp->next = NULL;
	head = temp;
	
	get_every_link(temp, &pos, &count, &ret_read_file, &flag);			//循环读文件，得到每一个合法的网址,并存入链表中

	printf_link(head);								//输出网址，直接打印链表即可，因为把合法链接连续的存入到了链表

	return 0; 
}
