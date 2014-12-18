%option noyywrap

%{
int num_lines = 0, num_chars = 0;
char *msg ="I am not clear !";
%}

%%
\n ++num_lines; ++num_chars;
. ++num_chars;

%%

int main(){
yylex();
printf("# of lines = %d, # of chars = %d\n, %s\n",num_lines,num_chars,msg);

return 0;

}
