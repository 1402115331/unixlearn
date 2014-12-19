
cal : cal cal.y
	bison -d cal.y
	flex cal.flex
	cc -o $@ cal.tab.h  lex.yy.c -lfl

clean :
	rm cal cal.tab.h lex.yy.c
