%{
int chars = 0;
int words = 0;
int lines = 0;
%}

%%

"zhy" {
}

[a-zA-Z]+ {
	words++;
	chars+= strlen(yytext);
}

\n {
	chars++;
	lines++;
}

. {
	chars++;
}

%%

int main(){
	char *fname = "wc.flex";
	FILE *f = 0;
	if(!(f = fopen(fname,"r")))printf("Read Error");
	yyrestart(f);
	yylex();
	printf("lines :%8d----words:%8d----chars:%8d \n",lines,words,chars);
	return 0;
}
