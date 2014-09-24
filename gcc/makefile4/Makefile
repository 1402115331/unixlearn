#wildcard 是把当前目录和子目录sub下的.c全部展开
src=$(wildcard *.c ./sub/*.c)
#notdir 是去掉所有的路径信息只保留文件名
dir=$(notdir $(src))
#指定把dir里的内容全部从.c退换成.o
obj=$(patsubst %.c,%.o,$(dir))

test=$(wildcard *.o)

all:
	@echo $(src)
	@echo $(dir)
	@echo $(obj)
	@echo $(test)
	@echo end

#通过打印信息发现 wildcard是不可能通配到.o文件的，因为makefile连锁之前根本就不存在.o,所以只能通配.c 但是我们需要的是.o,因为只有.o才能触发连锁反应，而.c是无论如何也不会触发连锁反应的，所以 patsubst就是批量更改字符串的意思，我们通过通配获得原始的数据,然后再对这个原始的数据修改成我们想要的.o
