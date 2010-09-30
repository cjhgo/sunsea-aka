#include <stdio.h> 
#include <stdlib.h>
#include "sqlite3.h"

int LoadMyInfo( void * para, int n_column, char ** column_value, char ** column_name );

int main( int argc, char**argv[])
{
	sqlite3 * db = NULL; // 声明sqlite 关键结构指针
	int result;
	char * errmsg = NULL;

	// 打开数据库
	// 需要传入 db 这个指针的指针，因为 sqlite3_open 函数要为这个指针分配内存，还要让db 指针指向这个内存区
	result = sqlite3_open("test.db", &db);

	if( result != SQLITE_OK )

	{
		//数据库打开失败
		return -1;
	}
	//数据库操作代码
	//创建一个测试表，表名叫 MyTable_1 ，有2 个字段： ID 和 name 。其中ID 是一个自动增加的类型，以后insert 时可以不去指定这个字段，它会自己从0 开始增加
	result = sqlite3_exec( db ,"create table MyTable_1( ID integer primary key autoincrement, name nvarchar(32) );" , NULL, NULL, &errmsg );
	if(result != SQLITE_OK )

	{
		printf( " 创建表失败，错误码:%d ，错误原因:%s\n " , result, errmsg );
	}

	//插入一些记录
	result = sqlite3_exec( db, " insert into MyTable_1( name ) values ( ' 走路 ' ); " , 0, 0, &errmsg );
	if(result != SQLITE_OK )
	{
		printf( " 插入记录失败，错误码:%d ，错误原因:%s\n " , result, errmsg );
	}
         
	result = sqlite3_exec( db, " insert into MyTable_1( name ) values ( ' 骑单车 ' ); " , 0, 0, &errmsg );
	if(result != SQLITE_OK )
	{
		printf( " 插入记录失败，错误码:%d ，错误原因:%s\n " , result, errmsg );
	}
           
	result = sqlite3_exec( db, " insert into MyTable_1( name ) values ( ' 坐汽车 ' ); " , 0, 0, &errmsg );
	if(result != SQLITE_OK )
	{
		printf( " 插入记录失败，错误码:%d ，错误原因:%s\n " , result, errmsg );
	}
                  
	//开始查询数据库
	result = sqlite3_exec( db, " select * from MyTable_1;" , LoadMyInfo, NULL, &errmsg );
             
	//关闭数据库
	sqlite3_close( db );
	return 0;
}

int LoadMyInfo( void * para, int n_column, char ** column_value, char ** column_name )

{
	//para 是你在 sqlite3_exec 里传入的 void * 参数
	// 通过para 参数，你可以传入一些特殊的指针（比如类指针、结构指针），然后在这里面强制转换成对应的类型（这里面是void* 类型，必须强制转换成你的类型才可用）。然后操作这些数据
	//n_column 是这一条记录有多少个字段 ( 即这条记录有多少列)
	// char ** column_value 是个关键值，查出来的数据都保存在这里，它实际上是个1 维数组（不要以为是2 维数组），每一个元素都是一个 char * 值，是一个字段内容（用字符串来表示，以\0 结尾）
	//char ** column_name 跟 column_value 是对应的，表示这个字段的字段名称
	       
	// 这里，我不使用 para 参数。忽略它的存在.
	                     
	int i;
	printf( "记录包含 %d 个字段\n " , n_column );
	for( i = 0 ; i < n_column; i ++ )
	{
		printf( " 字段名:%s  \t > 字段值:%s\n " ,  column_name[i], column_value[i] );
	}
	printf( " -----------------------------------\n " );         
	
	return 0;
}
