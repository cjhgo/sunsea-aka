/*
 * 名称：步步递近网络蜘蛛（二）
 *
 * 版本：v3.0
 * 
 * 作者：张双喜
 *
 * 日期：2010.10.18
 *
 * 功能：从文件中读一个字符串，再从字符串中找出合法的网址（在html中语法表达中正确的网址）
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

//从文件中得到一个字符串
char * get_string(void)
{
	FILE * fp;
	char * pStr;
	char str[1024] = {0};
	int flag = 0;
	PNODE head = NULL;

	pStr = str;

	if((fp = fopen("link.txt", "r")) == NULL)
	{
		perror("link.txt");
		exit(0);
	}

	fgets(pStr, 1024, fp);


	fclose(fp);

	return pStr;
}

int main(int argc, char* argv[])
{
	int flag = 0;
	PNODE head = NULL;
	char * tmp;

	tmp = get_string();
	head = link(&tmp, &flag);
	printf_link(head, &flag);

	return 0; 
}
