newpara.out : hello_fn.o main.o
	gcc hello_fn.o main.o
hello_fn.o : hello_fn.c hello.h
	gcc hello_fn.c hello.h
main.c : main.c hello.h
	gcc main.c hello.h


