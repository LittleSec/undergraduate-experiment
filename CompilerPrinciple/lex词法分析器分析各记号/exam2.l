%{

#include <stdio.h> 
#define LT					1
#define	LE					2
#define GT					3
#define	GE					4
#define	EQ					5
#define NE					6

#define IF					16
#define ELSE				17
#define WHILE				18
#define	DO					19
#define ID          20
#define NUMBER      21
#define RELOP       22

#define NEWLINE     23
#define ERRORCHAR   24

#define COPY				25
#define SEMICOLON		26
#define BRACKET			27
#define OP					28

%}

 
delim		[ \t \n]
ws			{delim}+
letter_	[A-Za-z_]
digit		[0-9]
id			{letter_}({letter_}|{digit})*
number	{digit}+(\.{digit}+)?(E[+-]?{digit}+)?

/* 状态（或条件）定义可以定义在这里 
 * INITIAL是一个默认的状态，不需要定义
 */
%s COMMENT1
%s COMMENT2

%%

<INITIAL>"/*"						{BEGIN COMMENT1;}
<COMMENT1>"*/"					{BEGIN INITIAL;}
<COMMENT1>.|\n					{;}

<INITIAL>"//"						{BEGIN COMMENT2;}
<COMMENT2>\n						{BEGIN INITIAL;}
<COMMENT2>.|\n					{;}

 /* ECHO是一个宏，相当于 fprintf(yyout, "%s", yytext)*/

<INITIAL>{ws}	          {;}
<INITIAL>while					{return (WHILE);}
<INITIAL>do		          {return (DO);}
<INITIAL>if		          {return (IF);}
<INITIAL>else		        {return (ELSE);}
<INITIAL>{id}	          {return (ID);}

<INITIAL>{number}	      {return (NUMBER);}
<INITIAL>"<"	          {return (RELOP);}
<INITIAL>"<="	          {return (RELOP);}
<INITIAL>"=="	          {return (RELOP);}
<INITIAL>"!="	          {return (RELOP);}
<INITIAL>">"	          {return (RELOP);}
<INITIAL>">="	          {return (RELOP);}

<INITIAL>"="						{return (COPY);}
<INITIAL>";"						{return (SEMICOLON);}

<INITIAL>"("	          {return (BRACKET);}
<INITIAL>")"	          {return (BRACKET);}
<INITIAL>"{"	          {return (BRACKET);}
<INITIAL>"}"	          {return (BRACKET);}

<INITIAL>"+"	          {return (OP);}
<INITIAL>"-"	          {return (OP);}
<INITIAL>"*"	          {return (OP);}
<INITIAL>"/"	          {return (OP);}

<INITIAL>.							{return ERRORCHAR;}

 
%%

int yywrap (){
  return 1;
}

void writeout(int c){
  switch(c){
  	case ERRORCHAR: fprintf(yyout, "(ERRORCHAR, \"%s\") ", yytext);break;
  	case RELOP: fprintf(yyout, "(RELOP, \"%s\") ", yytext);break;  	  
    case WHILE: fprintf(yyout, "(WHILE, \"%s\") ", yytext);break;
    case DO: fprintf(yyout, "(DO, \"%s\") ", yytext);break;
    case IF: fprintf(yyout, "(IF, \"%s\") ", yytext);break;
    case ELSE: fprintf(yyout, "(ELSE, \"%s\") ", yytext);break;
    case NUMBER: fprintf(yyout, "(NUM, \"%s\") ", yytext);break;
    case ID: fprintf(yyout, "(ID, \"%s\") ", yytext);break;
    case NEWLINE: fprintf(yyout, "\n");break;
    case COPY: fprintf(yyout, "(COPY, \"%s\") ", yytext);break;
    case SEMICOLON: fprintf(yyout, "(SEMICOLON, \"%s\") ", yytext);break;
    case BRACKET: fprintf(yyout, "(BRACKET, \"%s\") ", yytext);break;
    case OP: fprintf(yyout, "(OP, \"%s\") ", yytext);break;
    default:break;
  }
  return;
}


int main (int argc, char ** argv){
	int c,j=0;
	if (argc>=2){
	  if ((yyin = fopen(argv[1], "r")) == NULL){
	    printf("Can't open file %s\n", argv[1]);
	    return 1;
	  }
	  if (argc>=3){
	    yyout=fopen(argv[2], "w");
	  }
	}

	while (c = yylex()){
		writeout(c);
		j++;
		if (j%5 == 0) writeout(NEWLINE);
	}
	if(argc>=2){
	  fclose(yyin);
	  if (argc>=3) fclose(yyout);
	}
	return 0;
}
