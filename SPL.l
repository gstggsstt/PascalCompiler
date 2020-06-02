%{
#include <cstdio>
#include <string>
#include "ASTNode.h"
#include "parser.hpp"
int line=1;
int column;
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
_BEGIN "begin"
CASE "case"
CONST "const"
DO "do"
DOWNTO "downto"
ELSE "else"
END "end"
FOR "for"
FUNCTION "function"
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
NAME [a-zA-Z][_a-zA-Z0-9]*
WS [ \t]+
NL \n
%x COMMENT QUOTE
%%
{LP} {
	column+=yyleng;
	return TOKEN(LP);
}
{RP} {
	column+=yyleng;
	return TOKEN(RP);
}
{LB} {
	column+=yyleng;
	return TOKEN(LB);
}
{RB} {
	column+=yyleng;
	return TOKEN(RB);
}
{RC} {
	column+=yyleng;
	return TOKEN(RC);
}
{DOT} {
	column+=yyleng;
	return TOKEN(DOT);
}
{DOTDOT} {
	column+=yyleng;
	return TOKEN(DOTDOT);
}
{SEMI} {
	column+=yyleng;
	return TOKEN(SEMI);
}
{COMMA} {
	column+=yyleng;
	return TOKEN(COMMA);
}
{COLON} {
	column+=yyleng;
	return TOKEN(COLON);
}
{MUL} {
	column+=yyleng;
	return TOKEN(MUL);
}
{DIV} {
	column+=yyleng;
	return TOKEN(DIV);
}
{MOD} {
	column+=yyleng;
	return TOKEN(MOD);
}
{PLUS} {
	column+=yyleng;
	return TOKEN(PLUS);
}
{MINUS} {
	column+=yyleng;
	return TOKEN(MINUS);
}
{UNEQUAL} {
	column+=yyleng;
	return TOKEN(UNEQUAL);
}
{NOT} {
	column+=yyleng;
	return TOKEN(NOT);
}
{GE} {
	column+=yyleng;
	return TOKEN(GE);
}
{GT} {
	column+=yyleng;
	return TOKEN(GT);
}
{LE} {
	column+=yyleng;
	return TOKEN(LE);
}
{LT} {
	column+=yyleng;
	return TOKEN(LT);
}
{EQUAL} {
	column+=yyleng;
	return TOKEN(EQUAL);
}
{ASSIGN} {
	column+=yyleng;
	return TOKEN(ASSIGN);
}
{FALSE} {
	column+=yyleng;
	return TOKEN(FALSE);
}
{MAXINT} {
	column+=yyleng;
	return TOKEN(MAXINT);
}
{TRUE} {
	column+=yyleng;
	return TOKEN(TRUE);
}
{ABS} {
	column+=yyleng;
	return TOKEN(ABS);
}
{CHR} {
	column+=yyleng;
	return TOKEN(CHR);
}
{ODD} {
	column+=yyleng;
	return TOKEN(ODD);
}
{ORD} {
	column+=yyleng;
	return TOKEN(ORD);
}
{PRED} {
	column+=yyleng;
	return TOKEN(PRED);
}
{SQR} {
	column+=yyleng;
	return TOKEN(SQR);
}
{SQRT} {
	column+=yyleng;
	return TOKEN(SQRT);
}
{SUCC} {
	column+=yyleng;
	return TOKEN(SUCC);
}
{WRITE} {
	column+=yyleng;
	return TOKEN(WRITE);
}
{WRTIELN} {
	column+=yyleng;
	return TOKEN(WRTIELN);
}
{TYBOOLEAN} {
	column+=yyleng;
	return TOKEN(TYBOOLEAN);
}
{TYCHAR} {
	column+=yyleng;
	return TOKEN(TYCHAR);
}
{TYINTEGER} {
	column+=yyleng;
	return TOKEN(TYINTEGER);
}
{TYREAL} {
	column+=yyleng;
	return TOKEN(TYREAL);
}
{AND} {
	column+=yyleng;
	return TOKEN(AND);
}
{ARRAY} {
	column+=yyleng;
	return TOKEN(ARRAY);
}
{_BEGIN} {
	column+=yyleng;
	return TOKEN(_BEGIN);
}
{CASE} {
	column+=yyleng;
	return TOKEN(CASE);
}
{CONST} {
	column+=yyleng;
	return TOKEN(CONST);
}
{DO} {
	column+=yyleng;
	return TOKEN(DO);
}
{DOWNTO} {
	column+=yyleng;
	return TOKEN(DOWNTO);
}
{ELSE} {
	column+=yyleng;
	return TOKEN(ELSE);
}
{END} {
	column+=yyleng;
	return TOKEN(END);
}
{FOR} {
	column+=yyleng;
	return TOKEN(FOR);
}
{FUNCTION} {
	column+=yyleng;
	return TOKEN(FUNCTION);
}
{GOTO} {
	column+=yyleng;
	return TOKEN(GOTO);
}
{IF} {
	column+=yyleng;
	return TOKEN(IF);
}
{OF} {
	column+=yyleng;
	return TOKEN(OF);
}
{OR} {
	column+=yyleng;
	return TOKEN(OR);
}
{PACKED} {
	column+=yyleng;
	return TOKEN(PACKED);
}
{PROCEDURE} {
	column+=yyleng;
	return TOKEN(PROCEDURE);
}
{PROGRAM} {
	column+=yyleng;
	return TOKEN(PROGRAM);
}
{RECORD} {
	column+=yyleng;
	return TOKEN(RECORD);
}
{REPEAT} {
	column+=yyleng;
	return TOKEN(REPEAT);
}
{THEN} {
	column+=yyleng;
	return TOKEN(THEN);
}
{TO} {
	column+=yyleng;
	return TOKEN(TO);
}
{TYPE} {
	column+=yyleng;
	return TOKEN(TYPE);
}
{UNTIL} {
	column+=yyleng;
	return TOKEN(UNTIL);
}
{VAR} {
	column+=yyleng;
	return TOKEN(VAR);
}
{WHILE} {
	column+=yyleng;
	return TOKEN(WHILE);
}
{READ} {
	column+=yyleng;
	return TOKEN(READ);
}
{LC} {
	column+=yyleng;
	printf("COMMENT\tEND\n");
	BEGIN(COMMENT);
}
<COMMENT>[^}]*
<COMMENT>{RC} {
	column+=yyleng;
	printf("COMMENT\tEND\n");
	BEGIN(INITIAL);
}
{INTEGER} {
	column+=yyleng;
	yylval.string = new std::string (yytext);
	return INTEGER;
}
{REAL} {
	column+=yyleng;
	yylval.string = new std::string (yytext);
	return REAL;
}
{CHAR} {
	column+=yyleng;
	yylval.string = new std::string (yytext);
	return CHAR;
}
{NAME} {
	column+=yyleng;
	yylval.string = new std::string (yytext);
	return NAME;
}
{WS} { column+=yyleng; }
{NL} {
	line++;
	column = 0;
}
%%
int yywrap()
{
	return 1;
}
