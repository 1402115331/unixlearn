#如果需要觉得command前面4个空格比较怪异或者想写到一行也可以使用分号
all :  main.o  	hello_fn.o
	gcc -o new.out main.o hello_fn.o
	@echo 正在编译模块。。。
hello_fn.o:hello.h
main.o: hello.h
.PHONY :clean 
clean: 
	-rm hello_fn.o main.o new.out
