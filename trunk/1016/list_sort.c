#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE, *PNODE;

//创建节点
PNODE create_node(void)
{
	PNODE new;

	new = malloc(sizeof(NODE));
	if(NULL == new)
	{
		perror("malloc error!");
		exit(0);
	}

	return new;
}

//遍历链表
void traverse_list(PNODE head)
{
	PNODE p;

	p = head->next;

	while(NULL != p)
	{
		printf("data = %d\n", p->data); 
		p = p->next;
	}

	return;
}

//每次都插入在首位值，即头节点之后的位置
PNODE insert_first(PNODE head, PNODE new)
{
	new->next = head->next;
	head->next = new;
	
	return head;
}

//排序
void list_sort(PNODE head, int len)
{
	PNODE p, q, tmpp, tmpq, list;
	int i, j;
	PNODE tmp;

	for(i = 0, list = head; i < len-1; i++)
	{ 
		for(j = 0, tmpp = list; j < len-i-1; j++, tmpp = tmpp->next)
		{
			p = tmpp->next;
			q = p->next;
			if(NULL != q->next)
			{
				tmpq = q->next;
			}
			else
				tmpq = NULL;
			
			if(p->data > q->data)
			{
				tmpp->next = q;
				q->next = p;
				p->next = tmpq;
			
				tmp = p;
				p = q;
				q = tmp;
			}
		}
	}

	return;
}

int main(int argc, char* argv[])
{
	int i;
	int a[10] = {43, 12, -34, 55, 14, 0, -99, 78, 65, 11};
	PNODE head, first, new, p;

	head = create_node();
	
	//初始化，赋初值
	for(i = 9; i >= 0; i--)
	{
		new = create_node();
		new->data = a[i];
		new->next = NULL;
		head = insert_first(head, new);
		
	}	

	//打印
	traverse_list(head);

	//排序
	printf("=================================\n"); 
	list_sort(head, 10);
	traverse_list(head);

	return 0; 
}
