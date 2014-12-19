%{
/****
	enum yytokentype {
		NUMBER = 258,
		ADD = 259,
		SUB = 260,
		MUL = 261,
		DIV = 262,
		ABS = 263,
		EOL = 264
	};
****/
//这里的内容代替了上面申请的枚举类型。。
#include "cal.tab.h"
	int yylval;
%}

%%
"+" {return ADD;}
"-" {return SUB;}
"*" {return MUL;}
"/" {return DIV;}
"|" {return ABS;}
[0-9]+ {yylval = atoi(yytext);return NUMBER ;}
\n {return EOL;}
[ \t] {/**忽略空白字符**/}
. {printf("Mystery character %c \n",*yytext);}
%%
/***
int main(int argc,char **argv){
	int tok;
	while(tok = yylex()){
		printf("%d",tok);
		if(tok == NUMBER) printf(" = %d \n",yylval);
		else printf("\n");
	}

}
***/
