%{
#include <stdio.h>
#include <cstring>
int line;
#define TOKEN(t) (yylval.token = t)
%}
LP "("
RP ")"
LB "["
RB "]"
LC "{"
RC "}"
DOT "."
DOTDOT ".."
SEMI ";"
COMMA ","
COLON ":"
MUL "*"
DIV "/"
MOD "mod"
PLUS "+"
MINUS "-"
UNEQUAL "<>"
NOT "not"
GE ">="
GT ">"
LE "<="
LT "<"
EQUAL "="
ASSIGN ":="
FALSE "false"
MAXINT "maxint"
TRUE "true"
ABS "abs"
CHR "chr"
ODD "odd"
ORD "ord"
PRED "pred"
SQR "sqr"
SQRT "sqrt"
SUCC "succ"
WRITE "write"
WRTIELN "writeln"
TYBOOLEAN "boolean"
TYCHAR "char"
TYINTEGER "integer"
TYREAL "real"
AND "and"
ARRAY "array"
BEGIN "begin"
CASE "case"
CONST "const"
DIV "div"
DO "do"
DOWNTO "downto"
ELSE "else"
END "end"
FOR "for"
FUCNTION "function"
GOTO "goto"
IF "if"
OF "of"
OR "or"
PACKED "packed"
PROCEDURE "procedure"
PROGRAM "program"
RECORD "record"
REPEAT "repeat"
THEN "then"
TO "to"
TYPE "type"
UNTIL "until"
VAR "var"
WHILE "while"
READ "read"
INTEGER [0-9]+
REAL [0-9]+\.[0-9]+
CHAR \'.\'
ID [a-zA-Z][_a-zA-Z0-9]*
WS [ \t]+
NL \n
%x COMMENT QUOTE
%%
{LP} {
	return TOKEN(LP);
}
{RP} {
	return TOKEN(RP);
}
{LB} {
	return TOKEN(LB);
}
{RB} {
	return TOKEN(RB);
}
{RC} {
	return TOKEN(RC);
}
{DOT} {
	return TOKEN(DOT);
}
{DOTDOT} {
	return TOKEN(DOTDOT);
}
{SEMI} {
	return TOKEN(SEMI);
}
{COMMA} {
	return TOKEN(COMMA);
}
{COLON} {
	return TOKEN(COLON);
}
{MUL} {
	return TOKEN(MUL);
}
{DIV} {
	return TOKEN(DIV);
}
{MOD} {
	return TOKEN(MOD);
}
{PLUS} {
	return TOKEN(PLUS);
}
{MINUS} {
	return TOKEN(MINUS);
}
{UNEQUAL} {
	return TOKEN(UNEQUAL);
}
{NOT} {
	return TOKEN(NOT);
}
{GE} {
	return TOKEN(GE);
}
{GT} {
	return TOKEN(GT);
}
{LE} {
	return TOKEN(LE);
}
{LT} {
	return TOKEN(LT);
}
{EQUAL} {
	return TOKEN(EQUAL);
}
{ASSIGN} {
	return TOKEN(ASSIGN);
}
{FALSE} {
	return TOKEN(FALSE);
}
{MAXINT} {
	return TOKEN(MAXINT);
}
{TRUE} {
	return TOKEN(TRUE);
}
{ABS} {
	return TOKEN(ABS);
}
{CHR} {
	return TOKEN(CHR);
}
{ODD} {
	return TOKEN(ODD);
}
{ORD} {
	return TOKEN(ORD);
}
{PRED} {
	return TOKEN(PRED);
}
{SQR} {
	return TOKEN(SQR);
}
{SQRT} {
	return TOKEN(SQRT);
}
{SUCC} {
	return TOKEN(SUCC);
}
{WRITE} {
	return TOKEN(WRITE);
}
{WRTIELN} {
	return TOKEN(WRTIELN);
}
{TYBOOLEAN} {
	return TOKEN(TYBOOLEAN);
}
{TYCHAR} {
	return TOKEN(TYCHAR);
}
{TYINTEGER} {
	return TOKEN(TYINTEGER);
}
{TYREAL} {
	return TOKEN(TYREAL);
}
{AND} {
	return TOKEN(AND);
}
{ARRAY} {
	return TOKEN(ARRAY);
}
{BEGIN} {
	return TOKEN(BEGIN);
}
{CASE} {
	return TOKEN(CASE);
}
{CONST} {
	return TOKEN(CONST);
}
{DIV} {
	return TOKEN(DIV);
}
{DO} {
	return TOKEN(DO);
}
{DOWNTO} {
	return TOKEN(DOWNTO);
}
{ELSE} {
	return TOKEN(ELSE);
}
{END} {
	return TOKEN(END);
}
{FOR} {
	return TOKEN(FOR);
}
{FUCNTION} {
	return TOKEN(FUCNTION);
}
{GOTO} {
	return TOKEN(GOTO);
}
{IF} {
	return TOKEN(IF);
}
{OF} {
	return TOKEN(OF);
}
{OR} {
	return TOKEN(OR);
}
{PACKED} {
	return TOKEN(PACKED);
}
{PROCEDURE} {
	return TOKEN(PROCEDURE);
}
{PROGRAM} {
	return TOKEN(PROGRAM);
}
{RECORD} {
	return TOKEN(RECORD);
}
{REPEAT} {
	return TOKEN(REPEAT);
}
{THEN} {
	return TOKEN(THEN);
}
{TO} {
	return TOKEN(TO);
}
{TYPE} {
	return TOKEN(TYPE);
}
{UNTIL} {
	return TOKEN(UNTIL);
}
{VAR} {
	return TOKEN(VAR);
}
{WHILE} {
	return TOKEN(WHILE);
}
{READ} {
	return TOKEN(READ);
}
{LC} {
	printf("COMMENT\tEND\n");
	BEGIN(COMMENT);
}
<COMMENT>[^}]*
<COMMENT>{RC} {
	printf("COMMENT\tEND\n");
	BEGIN(INITIAL);
}
{INTEGER} {
	yylval.string = new std:string (yytext,yyleng);
	return INTEGER;
}
{REAL} {
	yylval.string = new std:string (yytext,yyleng);
	return REAL;
}
{CHAR} {
	yylval.string = new std:string (yytext,yyleng);
	return CHAR;
}
{ID} {
	yylval.string = new std:string (yytext,yyleng);
	return ID;
}
{WS} { }
{NL} {
	line++;
}
%%
int yywrap()
{
	return 1;
}
int main()
{
	yylex();
	return 0;
}

/*
SYS_CON "false"|"maxint"|"true"
SYS_FUNC "abs"|"chr"|"odd"|"ord"|"pred"|"sqr"|"sqrt"|"succ"
SYS_PROC "write"|"writeln"
SYS_TYPE "boolean"|"char"|"integer"|"real"
*/
