#直接在all后面写 $(wildcard *o 虽然能够转换成对应的名字，但是不能触发连锁反应)
#objects := $(wildcard *.oa)
#说明直接统配的结构是不能触发连锁反应的
objects := $(patsubst %.c,%.o,$(wildcard *.c))
all: $(objects)
	gcc -o new hello_fn.o main.o
hello_fn.o : hello.h
main.o : hello.h



.PHONY:clean
clean:
	rm *.o


