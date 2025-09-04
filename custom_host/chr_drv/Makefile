obj-m := main.o


KERN_DIR = /home/shiva/Linux_Drivers/kernel_src/WSL2-Linux-Kernel


all:	
	make -C $(KERN_DIR)  M=$(PWD) modules

clean:
	make -C $(KERN_DIR)  M=$(PWD) clean

help:
	make -C $(KERN_DIR)  M=$(PWD) help
