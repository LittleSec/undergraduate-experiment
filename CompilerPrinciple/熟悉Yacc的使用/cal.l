%{
#include "cal.tab.h"
int yywrap(void){ return 1; }
%}

delim		[ \t]
ws			{delim}+
digit		[0-9]
number		{digit}+

%%
{number}    {sscanf(yytext, "%lf", &yylval); return NUMBER;}
not			{return NOT;}
"||"		{return OR;}
"&&"		{return AND;}
"+"			{return ADD;}
"-"			{return SUB;}
"*" 		{return MUL;}
"/" 		{return DIV;}
">" 		{return GT;}
"<" 		{return LT;}
"==" 		{return EQ;}
"("			{return LPAREN;}
")"			{return RPAREN;}
{ws}		{;}
"\n"		{return ENTER;}

%%