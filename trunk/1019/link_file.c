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

#define N 1024

typedef struct node
{
	char data;
	struct node * next;
}NODE, * PNODE;

char buf[N] = {0};
char str[N] = {0};

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
PNODE judge_end(PNODE tmp, char **p)
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
PNODE link(PNODE tmp, char **p ,int *flag)
{
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
		tmp = judge_end(tmp, &ret);
	}

	return tmp;
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
char * get_all_file(void)
{
	FILE * fp;

	if((fp = fopen("link.html", "r")) == NULL)
	{
		perror("link.html");
		exit(0);
	}

	fread(buf, 1024, 1, fp);

	fclose(fp);

	return buf;
}

//获取一行内容，不管这一行有什么内容，只要是这一行的内容，都要获取到
char * get_string(char *p)
{
	int i = 0;

	while('\n' != *p)
	{
		str[i++] = *p;
		p++;
	}

	return str;
}

//从所有文件中获取合法链接，并连续的存入到链表
void get_every_link(char * all_file, PNODE temp, int * flag)
{
	char * tmp;
	int len = 0;
	while('\0' != *all_file)
	{
		tmp = get_string(all_file);
		len = strlen(tmp) + 1;
		temp = link(temp, &tmp, flag);
		all_file = all_file + len;
		memset(tmp, 0, strlen(tmp));
	}

	return;
}

int main(int argc, char* argv[])
{
	int flag = 0;
	char * all_file;

	PNODE head, temp;

	temp = create_node();
	temp->next = NULL;
	head = temp;

	all_file = get_all_file();		//把文件中的内容全部读取到tmp中
	get_every_link(all_file, temp, &flag);	//得到每一个合法网址，并存入到链表中
	printf_link(head);			//输出网址，直接打印链表即可，因为把合法链接连续的存入到了链表
	
	return 0; 
}
