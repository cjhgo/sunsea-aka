#include "common.h"

void download_website(char *p)
{
	char website[N] = "wget -O temp_link.html ";
	char *convert = "iconv -f gbk -t utf8 temp_link.html > link.html";	//把源文件字符编码转化为utf-8

	strcat(website, p);

	system(website);
	system(convert);

	return;
}
