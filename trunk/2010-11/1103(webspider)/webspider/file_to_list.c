#include "common.h"

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

