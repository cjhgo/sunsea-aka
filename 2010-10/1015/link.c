#include <stdio.h>
#include <malloc.h>

struct link
{
	int a;
	struct link *next;
};
/*
//每次插入的位置都是链表的第二个位置		1
void insert(struct link * head, struct link * new)
{

	new->next = head->next;
	head->next = new;

	return;
}
*/
/*
//每次插入的位置都是链表的第一个位置		2
void insert_head(struct link * head, struct link * new)
{
	new->next = head;

	return;
}
*/

//每次每次插入的位置都是链表的最后一个位置
void insert_end(struct link * head, struct link * new)
{

	head->next = new;
	new->next = NULL;

	return;
}

void delete(struct link * head)
{
	struct link *p;
	p = head;

	p->next = p->next->next;

	return;
}

int main(int argc, char* argv[])
{
	struct link *tmp;
	struct link * head;
	struct link *p, *q;
	int i;
	int val;

	head = malloc(sizeof(struct link));
	head->a = 1;
	head->next = NULL;
	p = head;
	for(i = 2; i < 101; i++)
	{
		tmp = malloc(sizeof(struct link));
		tmp->next = NULL;
		tmp->a = i;
//		insert(head, tmp);		//1
//		insert_head(head, tmp);		//2
//		head = tmp;			//2
		insert_end(p,tmp);		//3
		p = tmp;			//3
	}

	tmp = head;				//1  3
	for(;tmp != NULL;)
	{
		printf("num = %d\n", tmp->a);
		tmp = tmp->next;
	}

	printf("==================================\n"); 
//	tmp = delete_3(head, &val);
	
	p = head;
	while(p != p->next->next)
	{
		q = head;
		//判断是否把头删掉
		if(NULL == head)
		{
			head = q->next;
		}

		if(NULL == p->next)
		{
			p->next = head;
		}

		printf("1111111111\n"); 
		p = p->next;
		delete(p);
		free(p);
		printf("22222222222222222222\n"); 
		
	
		p = p->next;
		printf("3333333333333333333\n"); 
	}
//	p->next = NULL;
	printf("555555555555555\n"); 
	printf("while head  = %d\n", head->a); 
	
	
	tmp = head;				//1  3
	printf("4444444444444444\n"); 
	for(;tmp != NULL;)
	{
		printf("num = %d\n", tmp->a);
		tmp = tmp->next;
	}

	return 0; 
}
