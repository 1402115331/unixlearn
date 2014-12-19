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
	int totalchars = 0;
	int totallines = 0;
	int totalwords = 0;
	char *fnames[] = {"wc.flex","wcfile.flex"};
	int i=0;
	for(;i < 2;i++){
		FILE *f = fopen(fnames[i],"r");
		if(!f)printf("Read Error");
		yyrestart(f);
		yylex();
		fclose(f);
		printf("lines :%8d----words:%8d----chars:%8d \n",lines,words,chars);
		totalchars += chars; chars = 0;
		totallines += lines; lines = 0;
		totalwords += words; words = 0;
	}
		printf("TOTAL lines :%8d----words:%8d----chars:%8d \n",totallines,totalwords,totalchars);
	return 0;


}
