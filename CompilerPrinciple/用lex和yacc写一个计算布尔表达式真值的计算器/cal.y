%{	
#include <ctype.h>
#include <stdio.h>
int yylex();  
int yyerror();
%}

%token T F LPAREN RPAREN ENTER
%left OR 
%left AND
%right NOT

%%
 /* 这样写prog可以让分析器每次读入一行进行分析，下一行重新分析expr */
 
prog	: prog exprp		 
		| exprp		 
		;
		
exprp	: expr ENTER { 
		if($1) printf("true\n");
		else printf("false\n");}			 	
		;
		
expr  	: expr OR expr1 {$$ = $1 || $3;}
		| expr1
		;

expr1	:expr1 AND expr2 {$$ = $1 && $3;}
		|expr2
		;
		
expr2	: NOT expr2 {$$ = ! $2;}
		| LPAREN expr RPAREN {$$ = $2;}	
		| T {$$ = 1;}			
		| F	{$$ = 0;}			
		;
		
%%

int main()
{	
	yyparse();	
	return 0;
}