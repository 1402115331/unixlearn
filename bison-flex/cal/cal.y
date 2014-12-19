%{
#include <stdio.h>
%}


/**这里申请的token，bison会自动的为他们分配一个不重复的数字，我们可以在词法分析.flex里直接使用这些token值，而不必再自己定义其中的值**/
%token NUMBER
%token ADD SUB MUL DIV ABS
%token EOL

%%

calclist:/**空规则**/
   | calclist exp EOL {
		printf("= %d",$2);
	}
  ;
exp: factor  {$$ = $1 ;}
  | exp ADD factor {$$ = $1 + $3 ;}
  | exp SUB factor {$$ = $1 - $3 ;}
  ;

factor: term   { $$ = $1;}
  | factor MUL term {$$ = $1 * $3;}
  | factor DIV term {$$ = $1 / $3;}
  ;

term: NUMBER  {$$ = $1;}
  | ABS term { $$ = $2 >=0 ? $2 : - $2 ;}
  ;
%%
int main(int argc,char **argv){
	yyparse();
}
yyerror(char *s){
	fprintf(stderr,"error:%s\n",s);
}

