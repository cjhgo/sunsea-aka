/*
 * =====================================================================================
 *
 *       Filename:  helloworld.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday, September 29, 2011 06:58:18 HKT
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sunsea1026@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <linux/kernel.h>
#include <linux/module.h>

static int __init helloworld_init(void)
{
	printk("hello world!\n");

	return 0;
}

static void __exit helloworld_exit(void)
{
	printk("GoodBye curel world!\n");
}

module_init(helloworld_init);
module_exit(helloworld_exit);

MODULE_AUTHOR("sunsea");
MODULE_DESCRIPTION("module example");
MODULE_LICENSE("GPL");
