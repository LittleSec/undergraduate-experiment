%{

#include <stdio.h> 
#define LT			1
#define	LE			2
#define GT			3
#define	GE			4
#define	EQ			5
#define NE			6

#define DOUBLE		7
#define FLOAT		8

#define IF			16
#define ELSE		17
#define WHILE		18
#define	DO			19
#define ID          20
#define NUMBER      21
#define RELOP       22

#define NEWLINE     23
#define ERRORCHAR   24

#define COPY		25
#define SEMICOLON	26
#define BRACKET		27
#define OP			28

#define STRING		29
#define SPACE		30

%}

 
delim		[ \t\n]
ws			{delim}+
letter_		[A-Za-z_]
digit		[0-9]
id			{letter_}({letter_}|{digit})*
number		{digit}+(\.{digit}+)?(E[+-]?{digit}+)?
string		\"(\\.|[^\n\\\"])*\"

/* 状态（或条件）定义可以定义在这里 
 * INITIAL是一个默认的状态，不需要定义
 */
%s COMMENT1
%s COMMENT2

%%

<INITIAL>"/*"				{BEGIN COMMENT1;}
<COMMENT1>"*/"				{BEGIN INITIAL;}
<COMMENT1>.|\n				{;}

<INITIAL>"//"				{BEGIN COMMENT2;}
<COMMENT2>\n				{BEGIN INITIAL;}
<COMMENT2>.|\n				{;}

 /* ECHO是一个宏，相当于 fprintf(yyout, "%s", yytext)*/

<INITIAL>{ws}	        {return (SPACE);}
<INITIAL>while			{return (WHILE);}
<INITIAL>do		        {return (DO);}
<INITIAL>if		        {return (IF);}
<INITIAL>else		    {return (ELSE);}
<INITIAL>double		    {return (DOUBLE);}
<INITIAL>float		    {return (FLOAT);}
<INITIAL>{id}	        {return (ID);}
<INITIAL>{number}	    {return (NUMBER);}
<INITIAL>{string}		{return (STRING);}

<INITIAL>"<"	        {return (RELOP);}
<INITIAL>"<="	        {return (RELOP);}
<INITIAL>"=="	        {return (RELOP);}
<INITIAL>"!="	        {return (RELOP);}
<INITIAL>">"	        {return (RELOP);}
<INITIAL>">="	        {return (RELOP);}

<INITIAL>"="			{return (COPY);}
<INITIAL>";"			{return (SEMICOLON);}

<INITIAL>"("	        {return (BRACKET);}
<INITIAL>")"	        {return (BRACKET);}
<INITIAL>"{"	        {return (BRACKET);}
<INITIAL>"}"	        {return (BRACKET);}

<INITIAL>"+"	        {return (OP);}
<INITIAL>"-"	        {return (OP);}
<INITIAL>"*"	        {return (OP);}
<INITIAL>"/"	        {return (OP);}

<INITIAL>.				{return ERRORCHAR;}

 
%%

int yywrap (){
  return 1;
}

FILE* writeout(int c, FILE *newout){
  switch(c){
  	case SPACE: fprintf(newout, "%s", yytext);break;
  	case ERRORCHAR: fprintf(newout, "%s", yytext);break;
  	case RELOP: fprintf(newout, "%s", yytext);break;  	  
    case WHILE: fprintf(newout, "%s", yytext);break;
    case DO: fprintf(newout, "%s", yytext);break;
    case IF: fprintf(newout, "%s", yytext);break;
    case FLOAT: fprintf(newout, "%s", "double");break;
    case DOUBLE: fprintf(newout, "%s", yytext);break;
    case ELSE: fprintf(newout, "%s", yytext);break;
    case NUMBER: fprintf(newout, "%s", yytext);break;
    case ID: fprintf(newout, "%s", yytext);break;
    case NEWLINE: fprintf(newout, "\n", yytext);break;
    case COPY: fprintf(newout, "%s", yytext);break;
    case SEMICOLON: fprintf(newout, "%s", yytext);break;
    case BRACKET: fprintf(newout, "%s", yytext);break;
    case OP: fprintf(newout, "%s", yytext);break;
    case STRING: fprintf(newout, "%s", yytext);break;
    default:break;
  }
  return newout;
}


int main (int argc, char ** argv){
	int c;
	if (argc>=2){
	  if ((yyin = fopen(argv[1], "r")) == NULL){
	    printf("Can't open file %s\n", argv[1]);
	    return 1;
	  }
	  if (argc>=3){
	    yyout=fopen(argv[2], "w");
	  }
	}
	
	FILE *newout;
	if((newout = fopen("newout.c", "w")) == NULL){
	    printf("Can't open file %s\n", "newout.c");
	    return 1;
	}
	
	while (c = yylex())
		newout = writeout(c, newout);

	if(argc>=2){
	  fclose(yyin);
	  if (argc>=3) fclose(newout);
	}
	return 0;
}
