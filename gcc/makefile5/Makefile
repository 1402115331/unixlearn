#makefile的方法调用不同于普通的调用普通的就是吧参数放在括号里，但是对于makefile则是把函数名和函数参数依次放在$()里，原来这里因为要和exec交互的需要完全是按照exec的要求来写的，区别是用$()来表示这是一个exec执行函数
#听说VPATH可以指定make的搜索目录，但是求证没有成功
VPATH=.:./file
objects:=$(patsubst %.c,%.o,$(wildcard *.c))
obj=a.o b.o c.o
#all:$(objects)
#	gcc -o new $(objects)
#三段式的每个部分都可以用空格连接，对于target的目标连接如下，表示这是两个目标，可以通过$@在command里区分当前执行的具体是哪一个target，这就是把三段式分开写的整合模式
one two:
	@echo $@
#发现静态模式其实就是把之前的$(patsubst %.c,%.o wildcard(obj))的写法换成了这种表达更简洁，使用更方便的写法
simple:$(objects)
$(obj):%.o: %.c
#$(obj):%.c: %.o
	@echo $(obj)
	@echo $<
	@echo $@
#好像makefile也可以使用管道符号，待验证
test:a.c
	@set -e 
	@echo @<
	@echo nametest > @<
	@echo @<
