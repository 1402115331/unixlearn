%%
"=" {printf("opt_eq"); return 800;}
"+" {printf("opt_plus\n");return 801;}
"-" {printf("opt_minus\n");return 802;}
"*" {printf("times\n");}
"/" { printf("opt_div\n");}
"|" {printf("opt_abs\n");}
[0-9]+ { printf("number %s\n",yytext);}
\n {printf("NewLine\n");}
[ \t] {}
. {printf("Mystery character\n");}
%%
int main(){
int tok;
	while(tok = yylex()){
		printf("\n%d\n",tok);
	}

}
