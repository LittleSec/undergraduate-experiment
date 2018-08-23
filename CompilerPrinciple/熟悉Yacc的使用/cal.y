%{	
#include <ctype.h>
#include <stdio.h>
int yylex();  
int yyerror();
#define YYSTYPE double
%}

%token LPAREN RPAREN ENTER
%token  NUMBER
%left GT LT EQ
%left  ADD SUB
%left  MUL DIV
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
expr  : expr LT expr {if($1 < $3)$$ = 1;else $$ = 0;}
		| expr GT expr {if($1 > $3)$$ = 1;else $$ = 0;}
		| expr EQ expr {if($1 == $3)$$ = 1;else $$ = 0;}
		| expr ADD expr {$$ = $1 + $3; }
		| expr SUB expr	{$$ = $1 - $3; }
		| expr MUL expr	{$$ = $1 * $3; }
		| expr DIV expr {$$ = $1 / $3; }
		| expr AND expr {$$ = $1 && $3;}	
		| expr OR expr	{$$ = $1 || $3;}
		| NOT expr %prec NOT{$$ = ! $2;}			
		| LPAREN expr RPAREN {$$ = $2;}	
		| NUMBER {$$ = $1;}		
		;
		
%%

int main()
{	
	yyparse();	
	return 0;
}