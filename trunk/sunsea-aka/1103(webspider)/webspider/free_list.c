#include "common.h"

//释放整个链表
void free_list(PNODE head)
{
	PNODE p, p_current;

	p = head;
	p_current = p;
	p = p->next;
	free(p_current);

	while(NULL != p)
	{
		p_current = p;
		p = p->next;
		free(p_current->data);
		free(p_current);
	}

	return;
}
