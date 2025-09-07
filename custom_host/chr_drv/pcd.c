 


#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/kdev_t.h>



#define MEM_SIZE 1024
#undef pr_fmt
#define pr_fmt(fmt) "%s : " fmt,__func__

char device_buffer[MEM_SIZE];


static int __init chr_drv_init(void);
static void __exit chr_drv_exit(void);

/* device number holds mJOR nd minor number */
dev_t device_number;


/*Cdev variable */
struct cdev pcd_cdev;


loff_t pcd_lseek (struct file *filp, loff_t off, int whence)
{
	pr_info("lseek requested \n");
	return 0;
}

ssize_t pcd_read (struct file *flip, char __user *buff, size_t count, loff_t *f_pos)
{
	pr_info("read requested for %zu bytes \n",count);
	return 0;
}

ssize_t pcd_write (struct file *filp, const char __user *buff, size_t count, loff_t *f_pos)
{
	pr_info("write requested for %zu bytes \n",count);
	return 0;
}

int pcd_open (struct inode *inode, struct file *filp)
{
	pr_info("open requested \n");
	return 0;
}

int pcd_release (struct inode *inode, struct file *filp)
{
	pr_info("release requested \n");
	return 0;
}

/*fileoperations variable of the driver*/
struct file_operations pcd_fops = {
	.read = pcd_read,
	.write = pcd_write,
	.open = pcd_open,
	.llseek = pcd_lseek,
	.release = pcd_release,
	.owner = THIS_MODULE,
};


struct class *class_pcd;
struct device *device_pcd;


static int __init  chr_drv_init(){
	

	/* 1. device number creation */
	alloc_chrdev_region(&device_number,0,2,"pcd_device");
	pr_info("Major : Minor = %d : %d \n",MAJOR(device_number),MINOR(device_number));
	
	/*2 . Cdev initiation for mapping device with VFS*/
	cdev_init(&pcd_cdev,&pcd_fops);
	pcd_cdev.owner = THIS_MODULE;

	/*mapping with VFS  */
	cdev_add(&pcd_cdev,device_number,1);

	/*3. create device class under /sys/class/<pcd_class> */
	class_pcd = class_create("pcd_class");

	/* 4. populating sysfs with device information.
		  This will create a sub-directory under /sys/class/pcd_class/<pcd_device> 
		  and a dev file in the sub-directory which contains the device info like
		  minor and major numbers and the devfile name under /dev/  */
	device_pcd = device_create(class_pcd,NULL,device_number,NULL,"pcd");

		pr_info("Char_driver_Loaded_successfully:\n");
	return 0;
}

static void __exit chr_drv_exit(){


	device_destroy(class_pcd,device_number);
	class_destroy(class_pcd);
	cdev_del(&pcd_cdev);
	unregister_chrdev_region(device_number,1);

	pr_info("Char_driver_Unloaded_successfully:\n");
}


module_init(chr_drv_init);
module_exit(chr_drv_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Shiva_Kumar_Sammeta");
MODULE_DESCRIPTION("A Sample Char Linux Driver");

