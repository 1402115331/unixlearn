ifneq ($(KERNELRELEASE),)   
mymodule-objs := hello_module.o
obj-m := hello_module.o
else
PWD := $(shell pwd)
KVER ?= $(shell uname -r)
KDIR := /lib/modules/$(KVER)/build
all:
	$(MAKE) -C $(KDIR) M=$(PWD)
endif
##这里的内容解释了c语言究竟是怎么样加载数据的，java通过加载器加载指定位置的数据，c是通过makefile加载指定位置的数据的。。。