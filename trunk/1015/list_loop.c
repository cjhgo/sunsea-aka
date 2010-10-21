#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int data;
	struct node * next;
}NODE, *PNODE;

PNODE insert(PNODE list, PNODE new)
{
	new->next = list;
	list = new;

	return new;
}

void delete(PNODE head)
{
	PNODE p;
	head = head->next;
	p = head->next;
	head->next = p->next;

	free(p);

	return; 
}

int main(int argc, char* argv[])
{
	int i;
	PNODE head, p;
	PNODE tmp;

	head = malloc(sizeof(NODE));
	head->data = 100;
	head->next = NULL;

	//初始化链表,增加１００个节点
	for(i = 99; i > 0; i--)
	{
		tmp = malloc(sizeof(NODE));
		tmp->data = i;
		tmp->next = NULL;
		head = insert(head, tmp);
	}

	//打印原来链表
	p = head;
	while(NULL != p)
	{
		printf("data = %d\n", p->data);
		p = p->next;
	}

	//首尾相连
	p = head;
	while(NULL != p->next)
	{
		p = p->next;
	}
	p->next = head;

	//开始删除
	p = head;
	while(p != p->next->next)
	{
		delete(p);
		p = p->next->next;
	}

	p->next->next = NULL;

	printf("============================\n"); 
	while(NULL != p)
	{
		printf("data = %d\n", p->data); 
		p = p->next;
	}

	return 0; 
}
