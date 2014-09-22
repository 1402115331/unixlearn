new:hello_fn.o main.o
	gcc  main.o  hello_fn.o
hello_fn.o:hello_fn.c hello.h
	gcc -c  hello_fn.c 
main.o:hello_fn.o main.c hello.h
	gcc -c main.c

clean: 
	 rm hello_fn.o main.o a.out
