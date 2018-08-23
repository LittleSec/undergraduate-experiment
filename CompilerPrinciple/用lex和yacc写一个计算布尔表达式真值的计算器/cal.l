%{
#include "cal.tab.h"
int yywrap(void){  return 1;}
%}

delim		[ \t]
ws			{delim}+


%%
false   {return F;}
true    {return T;}
"||"	{return OR;}
"&&"	{return AND;}
"!"		{return NOT;}
"("		{return LPAREN;}
")"		{return RPAREN;}
{ws}	{;}
"\n"	{return ENTER;}
.		{printf("\nLEX:ERROR! c=%s\n", yytext);}

%%