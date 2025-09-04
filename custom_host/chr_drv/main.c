


#include <linux/module.h>

static int __init chr_drv_init(void);
static void __exit chr_drv_exit(void);



static int __init  chr_drv_init(){
	
	pr_info("Char_driver_Loaded\n");
	return 0;
}

static void __exit chr_drv_exit(){


	pr_info("Char_driver_Loaded\n");
}


module_init(chr_drv_init);
module_exit(chr_drv_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Shiva_Kumar_Sammeta");
MODULE_DESCRIPTION("A Sample Char Linux Driver");

