本例写了一个实数算术表达式的计算器。可以计算实数的加减乘除，可识别负数和括号。无论输入为
整数还是实数，通通识别为实数。

输入输出：键盘输入一行算术表达式，以换行结束，屏幕输出计算结果。

词法分析程序yylex()是用C语言写的函数。
语法分析规则中使用的文法为无二义的算术表达式文法。

注意：
makefile中 gcc -o cal0 cal.tab.c -ly ，-ly必须在最后，否则可能出现重复定义main函数等错误。
需要加-ly的原因为，cal.y中没有定义yyerror函数，需要使用库中的定义。
-o cal0 表示为gcc的输出文件命名（此时，输出文件为cal0.exe而非默认的a.exe）

