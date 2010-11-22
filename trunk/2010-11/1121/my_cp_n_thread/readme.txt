程序功能：
	多线程拷贝文件
	线程个数自己确定

说明：
	1、编译
		make

	2、运行
		make r(或者./my_cp)

	3、提示输入需要创建线程的个数
		假如需要创建5个，输入：5

	4、提示复制哪个文件
		假如需要复制test_old.txt，输入：test_old.txt

	5、提示复制到的哪个新文件
		假如需要复制到test_new.txt，输入：test_old_txt

程序运行范例：

	How many threads do you want to create?
	n = 3
	Please input a file:
	cp_from = test.jpg
	Please input a file:
	cp_to = my.jpg
	You create 3 threads.
	Please wait for a moment....
	Copy finish!

