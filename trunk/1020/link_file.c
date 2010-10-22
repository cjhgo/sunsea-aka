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
 *				while(循环条件)				//不断的对文件进行读取，注意每次读取的开始位置
 *				{
 *					fread(buf, 1024, 1, fp);	//读取1024个文件，存入buf[]
 *					get_string_from_1024();		//获取第一个\n前的内容，存入str[]
 *					link();				//对str[]中内容进行判断，如果事合法网址，并存入单链表中。
 *				}
 *			}
 *			说明：
 *				第一次得到合法网址存入单链表后，紧接着存入一个'\n'，'\n'的目的是使得打印时每一行显示一个网址。
 *				第二次得到合法网址，紧接着刚才'\n'存储，目的是使得所有合法网址都存入该链表中。
 *				往后的合法网址存储过程同上。
 *
 *	3、如何输出所有合法网址？
 *		1.printf_link()
 *			打印网址，即：打印链表，因为所有合法网址都顺序的存放在该链表中。
 *
 * 存在问题：
 *	该程序可能存在漏洞，将进行进一步修补
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

typedef struct node
{
	char data;
	struct node * next;
}NODE, * PNODE;

char buf[N] = {0};		//存放fread读出来的值
char str[N] = {0};		//存放从读出的1024个字节中解析出的第一行内容

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
	while((0 != my_strncmp(*p, "<a ", 3)) && ('\n' != (**p)) && ('\0' != (**p)))
	{
		(*p)++;
		(*count)++;
	}

	if(('\n' != (**p)) && '\0' != (**p))
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
	while(' ' == **p)
	{
		(*p)++;
		(*count)++;
	}

	if(0 == my_strncmp(*p, "href", 4))
	{
		*p = *p + 4;
		(*count) = (*count) + 3;
		return *p;
	}
	else
	{
		return NULL;
	}
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

//每次插入到最后一个位置
PNODE insert_list(PNODE tmp, PNODE new)
{
	tmp->next = new;
	new->next = NULL;
	tmp = new;

	return tmp;
}

//处理网址结束位置
PNODE judge_end(PNODE tmp, char **p, int *count)
{
	PNODE new;

	if(NULL != *p)
	{
		while((**p != '\"') && (**p != '\'') && (**p != '>') && (**p != '\0') && (**p != ' '))
		{
			new = create_node();
			new->data = **p;
			new->next = NULL;
			tmp = insert_list(tmp, new);
			
			(*count)++;		
			(*p)++;
		}

		new = create_node();
		new->data = '\n';
		new->next = NULL;

		tmp = insert_list(tmp, new);
	}
	
	return tmp;
}

//功能：生成网址
PNODE link(PNODE temp, char *p, int * count)
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
		temp = judge_end(temp, &ret, count);
	}

	return temp;
}

//打印网址
void printf_link(PNODE head)
{
	while(NULL != head)
	{
		printf("%c", head->data);
		head = head->next;
	}

	return;
}

//把文件的所有内容读取为一个字符串，即：把全部内容读到一个字符串中
void read_file(FILE *fp, int * pos)
{
	if((fp = fopen("link.html", "r")) == NULL)
	{
		perror("link.html");
		exit(0);
	}

	memset(buf, 0, N);
	fseek(fp, *pos, 0);
	fread(buf, 1024, 1, fp);
	
	fclose(fp);

	return;
}

//从读取的1024个字节获取一行内容，不管这一行有什么内容，只要是这一行的内容，都要获取到str[]中
void get_string_from_1024(char *p, int * pos)
{
	int i = 0;
	int len = 0;
	char * tmp;

	memset(str, 0, strlen(str));

	while('\n' != *p)
	{
		str[i++] = *p;
		p++;
	}
	
	return;
}

//从所有文件中获取合法链接，并连续的存入到链表
void get_every_link(FILE *fp, PNODE temp, int *pos, int * count)
{
	int i = 0;
	int len = 0;
	char t[N] = {0};
	char * tmp;

	tmp = t;
	*tmp = 'a';						//随意给定一个非'\0'字符，使得第一次可以进入循环
	
	while('\0' != *tmp)
	{
		memset(tmp, 0, strlen(tmp));

		read_file(fp, pos);				//对所有文件读取1024个字节，放到buf中
		get_string_from_1024(buf, pos);			//对刚才读取的1024个字节进行处理，即：把第一个\n前的值存入tmp中
		temp = link(temp, str, count);			//对刚才得到的字符串，也就是该处理的某一行内容进行处理，
		 						//处理包括判断是否是合法网址，如果是合法网址，并把网址连续的存入到链表中
		len = *count + 1;
		*pos = *pos + len;				//确定下次读文件开始的位置
	
		tmp = buf + *count + 1;				//用tmp判断是否读到文件结尾
	
		*count = 0;
	}

	return;
}

int main(int argc, char* argv[])
{
	FILE *fp;
	int count = 0;
	int pos = 0;
	PNODE head, temp;

	temp = create_node();
	temp->next = NULL;
	head = temp;
	
	get_every_link(fp, temp, &pos, &count);			//得到合法的网址

	printf_link(head);					//输出网址，直接打印链表即可，因为把合法链接连续的存入到了链表
	
	return 0; 
}
