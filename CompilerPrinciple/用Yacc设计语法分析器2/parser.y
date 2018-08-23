%{
#include <stdio.h>
#include "ast.h" //该文件定义了抽象语法树（分析树）的数据结构
#include "errormsg.h"
#define YYDEBUG 1 
/* 允许跟踪错误，与%debug功能相同 */

int yylex(void); /* function prototype */

/* 该函数显示错误信息s，显示时包含了错误发生的位置。*/
void yyerror(char *s)
{
 EM_error(EM_tokPos, "%s", s);
}

/* 存放抽象语法树中 "程序" 数据结构的变量 */
a_prog program = NULL;

%}


 /* 定义属性值栈的类型，最后一个实验可能需要修改此处  */
%union {
	int ival;
	double fval;
	string sval;
  a_exp exp;
  a_stm_list stms;
  a_prog prog;
  a_dec_list decl;
  a_bexp bexp;
  a_var_list varl;
  a_stm stm;
}

 /* 定义各个终结符，以及他们的属性值的类型，最后一个实验可能需要修改此处 */
%token <sval> ID /* id */
%token <ival> INT  /*整型数*/
%token <fval> FLOAT /*浮点数*/
%token INTEGER REAL  /*两种类型名：整型、实型*/
%token 
  COMMA COLON SEMICOLON LPAREN RPAREN PERIOD /* 符号 , : ; ( ) . */
  PROGRAM BEGINN END VAR IF WHILE DO   /* 关键字：PROGRAM BEGIN END VAR IF WHILE Do */
  /* 想想为什么不声明为BEGIN？ */
  THEN ELSE /* 关键字：THEN ELSE */
  ASSIGN EQ NEQ LT LE GT GE /* 符号 :=	 =  <>  <  <=  >  >= */
  PLUS MINUS TIMES DIVIDE /* 符号 + = * / */
%start program

  /* 定义各个非终结符的属性值类型，最后一个实验可能需要修改此处  */
%type <prog> program
%type <decl> declist vardec declist_other_part
%type <stms> stmtslist
%type <exp> factor term aritexp constant
%type <bexp> relaexp
%type <varl> idlist
%type <stm> whilestmts ifstmts asstmts comstmts stmts



%%
 /* 文法：program--> PROGRAM ID; vardec BEGIN stmts END. 
  *       vardec-->   VAR declist 
  *       declist-->  ID:INTEGER;
  *       stmts--> ID := exp
  *       exp--> INT
  *
  * 最后一个实验需要修改这个文法
  */
program	:	PROGRAM ID SEMICOLON vardec BEGINN stmtslist END PERIOD
				{program = A_Prog(EM_tokPos, $2, $4, $6);}
			; /* 程序 分程序*/
			
vardec 	: 	VAR declist {$$ = $2;}
			; /* 变量说明 */
			
declist : 	idlist COLON INTEGER SEMICOLON declist_other_part
				{$$ = A_DecList(A_VarDec(EM_tokPos, $1, T_int), $5);}
			| idlist COLON REAL SEMICOLON declist_other_part
				{$$ = A_DecList(A_VarDec(EM_tokPos, $1, T_real), $5);}
			; /* 变量说明表 */

declist_other_part : declist
			| {$$ = NULL;}
			;
			
idlist	:	ID {$$ = A_VarList(A_Id(EM_tokPos, $1), NULL);}
			| ID COMMA idlist {$$ = A_VarList(A_Id(EM_tokPos, $1), $3);}
			; /* 变量表 */
			
stmtslist:	stmts {$$ = A_StmList($1, NULL);}
			| stmts SEMICOLON stmtslist {$$ = A_StmList($1, $3);}
			; /* 语句表 */

stmts	:	asstmts
			| ifstmts
			| whilestmts
			| comstmts
			; /* 语句 */

asstmts	:	ID ASSIGN aritexp
				{$$ = A_Assign(EM_tokPos, A_Id(EM_tokPos, $1), $3);}
			; /* 赋值语句 */

ifstmts:	IF relaexp THEN stmts ELSE stmts
				{$$ = A_If(EM_tokPos, $2, $4, $6);}
			; /* 条件语句 */
			
whilestmts:	WHILE relaexp DO stmts
				{$$ = A_While(EM_tokPos, $2, $4);}
			; /* WHILE语句 */
			
comstmts:	BEGINN stmtslist END
				{$$ = A_Seq(EM_tokPos, $2);}
			; /* 复合语句 */
			
aritexp	:	term
			| aritexp PLUS term {$$ = A_OpExp(EM_tokPos, A_plusOp, $1, $3);}
			| aritexp MINUS term {$$ = A_OpExp(EM_tokPos, A_minusOp, $1, $3);}
			; /* 算术表达式 */

term	:	factor
			| term TIMES factor {$$ = A_OpExp(EM_tokPos, A_timesOp, $1, $3);}
			| term DIVIDE factor {$$ = A_OpExp(EM_tokPos, A_divideOp, $1, $3);}
			; /* 项 */

factor	:	ID {$$ = A_VarExp(EM_tokPos, A_Id(EM_tokPos, $1));}
			| constant
			| LPAREN aritexp RPAREN {$$ = $2;}
			; /* 因式 */
			
relaexp	:	aritexp LT aritexp {$$ = A_BExp(EM_tokPos, A_ltOp, $1, $3);}
			| aritexp LE aritexp {$$ = A_BExp(EM_tokPos, A_leOp, $1, $3);}
			| aritexp GT aritexp {$$ = A_BExp(EM_tokPos, A_gtOp, $1, $3);}
			| aritexp GE aritexp {$$ = A_BExp(EM_tokPos, A_geOp, $1, $3);}
			| aritexp EQ aritexp {$$ = A_BExp(EM_tokPos, A_eqOp, $1, $3);}
			| aritexp NEQ aritexp {$$ = A_BExp(EM_tokPos, A_neqOp, $1, $3);}
			; /* 关系表达式 */
			
constant:	INT {$$ = A_IntExp(EM_tokPos, $1);}
			| FLOAT {$$ = A_RealExp(EM_tokPos, $1);}
			;