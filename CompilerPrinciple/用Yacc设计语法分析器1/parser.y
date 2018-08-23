%{
#include <stdio.h>
#include "util.h" 
#include "errormsg.h"

int yylex(void); /* function prototype */

/* 该函数显示错误信息s，显示时包含了错误发生的位置。*/
void yyerror(char *s)
{
	EM_error(EM_tokPos, "%s", s);
}


%}


 /* 定义属性值栈的类型 */
%union {
	int ival;
	double fval;
	string sval;
}

 /* 定义各个终结符，以及他们的属性值的类型 */
%token <sval> ID /* id */
%token <ival> INT  /*整型数*/
%token <fval> FLOAT /*浮点数*/
%token INTEGER REAL  /*两种类型名：整型、实型*/
%token 
  COMMA COLON SEMICOLON LPAREN RPAREN PERIOD /* 符号 , : ; ( ) . */
  PROGRAM BEGINN END VAR IF WHILE DO   /* 关键字：PROGRAM BEGIN END VAR IF WHILE DO */
  THEN ELSE /* 关键字：THEN ELSE */
  ASSIGN EQ NEQ LT LE GT GE /* 符号 :=	 =  <>  <  <=  >  >= */
  PLUS MINUS TIMES DIVIDE /* 符号 + = * / */
%start program /* 开始符号为program */

%debug /* 允许跟踪错误 */

%%
 /* 文法：program--> PROGRAM ID; vardec BEGIN stmts END. 
  *       vardec-->   VAR declist 
  *       declist-->  ID:INTEGER;
  *       stmts--> ID := exp
  *       exp--> INT
  *
  * 实验7需要修改这个文法
  */

program	:	PROGRAM ID SEMICOLON block
			; /* 程序 */
			
block	:	vardec BEGINN stmtslist END PERIOD
			; /* 分程序 */
			
vardec 	: 	VAR declist
			; /* 变量说明 */
			
declist : 	idlist COLON type SEMICOLON declist_other_part
			; /* 变量说明表 */

declist_other_part : declist
			|
			;
			
type	:	INTEGER
			| REAL
			; /* 类型 */
			
idlist	:	ID
			| ID COMMA idlist
			; /* 变量表 */
			
stmtslist:	stmts
			| stmts SEMICOLON stmtslist
			; /* 语句表 */

stmts	:	asstmts
			| constmts
			| whilestmts
			| comstmts
			; /* 语句 */

asstmts	:	ID ASSIGN aritexp
			; /* 赋值语句 */

constmts:	IF relaexp THEN stmts ELSE stmts
			; /* 条件语句 */
			
whilestmts:	WHILE relaexp DO stmts
			; /* WHILE语句 */
			
comstmts:	BEGINN stmtslist END
			; /* 复合语句 */
			
aritexp	:	term
			| aritexp PLUS term
			| aritexp MINUS term
			; /* 算术表达式 */

term	:	factor
			| term TIMES factor
			| term DIVIDE factor
			; /* 项 */

factor	:	ID
			| constant
			| LPAREN aritexp RPAREN
			; /* 因式 */
			
relaexp	:	aritexp LT aritexp
			| aritexp LE aritexp
			| aritexp GT aritexp
			| aritexp GE aritexp
			| aritexp EQ aritexp
			| aritexp NEQ aritexp
			; /* 关系表达式 */
			
constant:	INT
			| FLOAT
			; /* 常量 */