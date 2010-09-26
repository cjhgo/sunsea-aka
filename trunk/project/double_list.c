/* 项目名称：双向链表基本操作
 *
 * 项目成员：
 *
 * 项目功能：
 * 	创建节点、在末尾添加节点、正向遍历、反向遍历、删除节点
 *
 * */

#include <stdio.h> 
#include <stdlib.h> 

typedef struct node
{
	int data;
	struct node *next;
	struct node *prior;
}NODE, *PNODE;

PNODE create_node(void);
PNODE add_to_list(PNODE pHead, int val);
void delect_node(PNODE pHead, int *pVal);
void traverse_list_right(PNODE pHead);
void traverse_list_left(PNODE pHead);

int main(int argc, char* argv[]) 
{
	PNODE pHead;

	pHead = NULL;
	printf("1111111111\n"); 	
	pHead->next = add_to_list(pHead, 11);
	printf("22222222222\n"); 
	pHead->next = add_to_list(pHead, 22);
	pHead->next = add_to_list(pHead, 33);
	pHead->next = add_to_list(pHead, 44);
	traverse_list_right(pHead);
	printf("\n"); 
	traverse_list_left(pHead);
	printf("\n"); 

	return 0; 
}

PNODE create_node(void)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL == pNew)
	{
		printf("malloc errror!\n"); 
		exit(-1);
	}
	pNew->next = NULL;
	pNew->prior = NULL;

	return pNew;
}

PNODE add_to_list(PNODE pHead, int val)
{
	PNODE p = NULL;
//	p->prior = NULL;
	PNODE pNew = create_node();

	pNew->data = val;

	p->next = pNew;
	pNew->prior = p;
	pNew->next = NULL;
	p = pNew;	
	
	return pNew;
}

void traverse_list_right(PNODE pHead)
{
	PNODE p;
	
	p = pHead->next;
	while(NULL != p)
	{
		printf("%d  ",p->data);
		p = p->next;
	}

	return;
}
void traverse_list_left(PNODE pHead)
{
	PNODE p,last;
	last = pHead->next;
	while(NULL != last)
	{
		last =last->next;
	}
	
	p = last;
	while(NULL != p)
	{
		printf("%d  ",p->data);
		p = p->prior;
	}

	return;
}












