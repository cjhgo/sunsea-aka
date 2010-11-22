/*
 * 名称：步步递近网络蜘蛛（一）
 *
 * 版本：v1.0
 * 
 * 作者：张双喜
 *
 * 日期：2010.10.17
 *
 * 功能：从一段字符串中，找出合法的网址（在html中语法表达中正确的网址）
 *
 * 过程设计：
 * 	根据html语法规则进行筛选出网址
 * 	1、函数：my_strncmp(char *p, char *q, int n)
 * 	   功能：自己模拟实现库函数strncmp
 * 	
 * 	2、函数：judge_anmark(char **p)
 * 	   功能：判断是不是"<a "或"  <a "，如果是，则进行下一步操作；
 *		如果不是，返回NULL；
 *
 * 	3、函数：judge_href(char **p)
 * 	   功能：判断是不是"  href"，如果是，则进行下一步操作；
 * 	   	如果不是，返回NULL；
 *
 * 	4、函数：judge_equal_mark(char **p)
 * 	   功能：判断是不是"  ="，如果是，则进行下一步操作；
 * 	   	如果不是，返回NULL；
 *
 * 	5、函数：judge_http(char **p)
 * 	   功能：判断是不是"  http"，如果是，则进行下一步操作；
 * 	   	如果不是，返回NULL；
 *
 * 	6、函数：link(char **p)
 * 	   功能：调用2、3、4、5函数，找到正确的网址
 *
 *	7、函数：pritnf_link(char *p)
 *	   功能：打印网址
 *	   备注：到网址结尾时，要对结尾进行处理，否则会一块把后面的a>等其他信息也打印出来
 *	
 * update 1
 *
 *	版本：v2.0
 *
 *	作者：张双喜
 *
 *	日期：2010.10.17
 *
 *	改进：
 *		1、对网址结尾处理过程，由原来在printf_link()中转到一个独立的函数judge_end()中
 *		
 *		2、新增加了单链表，用于存放处理好的网址
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	struct node * next;
}NODE, * PNODE;

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
char * judge_mark(char **p)
{
	while(' ' == **p)
	{
		(*p)++;
	}
	
	if(0 == my_strncmp(*p, "<a ", 3))
	{
		*p = *p + 3;

		return *p;
	}
	else
	{
		return NULL;
	}
}

//判断是否满足****  href
char * judge_href(char **p)
{
	while(' ' == **p)
	{
		(*p)++;
	}
	if(0 == my_strncmp(*p, "href", 4))
	{
		*p = *p + 4;
		return *p;
	}
	else
	{
		return NULL;
	}
}

//判断是否满足***  =
char * judge_equal_mark(char **p)
{
	while(' ' == **p)
	{
		(*p)++;
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
char * judge_http(char **p)
{
	while((' ' == **p) || ('\"' == **p) || ('\'' == **p))
	{
		(*p)++;
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
PNODE judge_end(char **p)
{
	PNODE head ,tmp, new;

	tmp = create_node();
	tmp->next = NULL;

	head = tmp;

	if(NULL != *p)
	{
		while((**p != '\"') && (**p != '\'') && (**p != '>') && (**p != '\0') && (**p != ' '))
		{
			new = create_node();
			new->data = **p;
			new->next = NULL;
			tmp = insert_list(tmp, new);
		
			(*p)++;
		}
	}

	return head;
}

//功能：生成网址
PNODE link (char **p ,int *flag)
{
	PNODE head = NULL;
	char * ret;

	*flag = 0;
	ret = judge_mark(p);

	if(NULL != ret)
	{
		ret = judge_href(&ret);
	}

	if(NULL != ret)
	{
		ret = judge_equal_mark(&ret);
	}

	if(NULL != ret)
	{
		ret = judge_http(&ret);
	}

	if(NULL != ret)
	{
		*flag = 1;
		head = judge_end(&ret);
	}

	return head;
}

//打印网址
void printf_link(PNODE head, int *flag)
{
	PNODE p;

	if(*flag)
	{
		p = head->next;
		while(NULL != p)
		{
			printf("%c", p->data); 
			p = p->next;
		}
		printf("\n"); 
	}

	return;
}

int main(int argc, char* argv[])
{
	int flag = 0;

	char *s1 = "      <a     href   =  \"http://www.akaedu.org\"> ok </a>";
	char *s2 = "  <a  href =    http://www.akaedu.org  ";
	char *s3 = "< a  href =    http://www.akaedu.org";
	char *s4 = "<a      href=\"        http://www.akaedu.\"org";

	PNODE head = NULL;

	head = link(&s1, &flag);
	printf_link(head, &flag);

	head = link(&s2, &flag);
	printf_link(head, &flag);

	head = link(&s3, &flag);
	printf_link(head, &flag);

	head = link(&s4, &flag);
	printf_link(head, &flag);

	return 0; 
}
