

#include <linux/module.h>

static int __init example_init(void);
static void __exit example_exit(void);


static int __init example_init(){

	pr_info("Example:_Module_init_executed\n");
	return 0;
}


static void __exit example_exit(){
	pr_info("Example:_Module_exit_executedn\n");
}


module_init(example_init);
module_exit(example_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Shiva_Kumar_Sammeta");
MODULE_DESCRIPTION("An example Module to load/unload");



