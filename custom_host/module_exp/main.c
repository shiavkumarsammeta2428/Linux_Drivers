

#include <linux/module.h>

static int __init module_init_example();
static void __exit module_exit_example();


static int __init  module_init_example(){

	printk("Example:_Module_init_executed\n");
	return 0;
}


static void __exit module_exit_example(){
	printf("Example:_Module_exit_executedn\n");
}


module_init(module_init_example);
module_exit(module_exit_example);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Shiva_Kumar_Sammeta");
MODULE_DESCRIPTION("An example Module to load/unload");



