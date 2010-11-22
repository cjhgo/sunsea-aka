#include "common.h"

int main(int argc, char* argv[])
{
	int pos = 0;
	int count = 0;
	int ret_read_file = -1;
	int flag = 1;
	int i = 0;
	int j = 0;
	int link_len = 0;
	PNODE head, temp;
	printf("please input a website....\n"); 
	scanf("%s", tmp_website);

	while(j < 3)
	{
		//下载网址
		download_website(tmp_website);

		temp = create_node();
		temp->next = NULL;
		head = temp;
		
		pos = 0;
		count = 0;
		ret_read_file = -1;
		flag = 0;
		i = 0;
		link_len = 0;
		get_every_link(temp, &pos, &count, &ret_read_file, &flag, &link_len);			//循环读文件，得到每一个合法的网址,并存入链表中

		printf("Please wait for a moment, we are conducting a database operation....\n"); 

		do_database(head);			//包括打开数据库、创建表、从链表存入数据库、从数据库中取出网址、修改status，关闭数据库

//		printf_link(head);			//输出网址，直接打印链表即可，因为把合法链接连续的存入到了链表
		free_list(head);


		printf("id = %d\n", id); 
	}


	return 0; 
}
