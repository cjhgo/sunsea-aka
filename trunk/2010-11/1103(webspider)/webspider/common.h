#ifndef __COMMON_H
#define __COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include "sqlite3.h"

#define N 1025

typedef struct node
{
	char *data;
	struct node *next;
}NODE, *PNODE;

char buf[N];		//存放fread读出来的值
char link_temp[N];	//临时存放合法网址
char tmp_website[N];	//存放从数据库中取出的网址
int id;			//记录从数据库中取出的网址的id号
int id_for_page;	//为了找到存放page内容设计的变量

#endif
