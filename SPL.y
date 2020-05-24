%{
    #include "node.h"
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    // NBlock *programBlock; /* the top level root node of our final AST */

    extern int yylex();
    void yyerror(const char *s) { std::printf("Error: %s\n", s);std::exit(1); }
    /*Union is the set of all possible class*/
%}

%union {
    Node *node;
    int token;
    std:string *string;
}

%token<token> LP RP LB RB LC RC DOT DOTDOT SEMI COMMA COLON MUL DIV
%token<token> MOD PLUS MINUS UNEQUAL NOT GE GT LE LT EQUAL ASSIGN FALSE MAXINT
%token<token> TRUE ABS CHR ODD ORD PRED SQR SQRT SUCC WRITE WRTIELN TYBOOLEAN
%token<token> TYCHAR TYINTEGER TYREAL AND ARRAY BEGIN CASE CONST DIV
%token<token> DO DOWNTO ELSE END FOR FUCNTION GOTO IF OF OR PACKED PROCEDURE PROGRAM
%token<token> RECORD REPEAT THEN TO TYPE UNTIL VAR WHILE READ
%token<string> INTEGER REAL CHAR ID

%type<token> sys_con
%type<token> sys_func
%type<token> sys_proc
%type<token> sys_type

%start program

%%
program : program_head routine DOT { $$ = new Program(f1, f2); }
        ;

program_head : PROGRAM ID SEMI
             ;

routine : routine_head routine_body
        ;

sub_routine : routine_head routine_body
            ;

routine_head : label_part const_part type_part var_part routine_part
             ;

label_part : ;

const_part : CONST const_expr_list
           |
           ;

const_expr_list : const_expr_list ID EQUAL const_value SEMI
                | NAME EQUAL const_value SEMI
                ;

const_value : INTEGER
            | REAL
            | CHAR
            | sys_con
            ;

sys_con : FALSE
        | MAXINT
        | TRUE
        ;

type_part : TYPE type_decl_list
          |
          ;

type_decl_list : type_decl_list type_definition
               | type_definition
               ;

type_definition : ID EQUAL type_decl SEMI
                ;

type_decl : simple_type_decl
          | array_type_decl
          | record_type_decl
          ;

simple_type_decl : sys_type
                 | NAME
                 | LP name_list RP
                 | const_value DOTDOT const_value
                 | MINUS const_value DOTDOT const_value
                 | MINUS const_value DOTDOT MINUS const_value
                 | NAME DOTDOT NAME
                 ;

sys_type : TYBOOLEAN
         | TYREAL
         | TYCHAR
         | TYINTEGER
         ;

array_type_decl : ARRAY LB simple_type_decl RB OF type_decl
                ;

record_type_decl : RECORD field_decl_list END
                 ;

field_decl_list : field_decl_list field_decl
                | field_decl
                ;

field_decl : name_list COLON type_decl SEMI
           ;

name_list : name_list COMMA ID
          | ID
          ;

var_part : VAR var_decl_list
         |
         ;

var_decl_list : var_decl_list var_decl
              | var_decl
              ;

var_decl : name_list COLON type_decl SEMI
         ;

routine_part : routine_part function_decl
             | routine_part procedure_decl
             | function_decl
             | procedure_decl
             |
             ;

function_decl : function_head SEMI sub_routine SEMI
              ;

function_head : FUNCTION ID parameters COLON simple_type_decl
              ;

procedure_decl : procedure_head SEMI sub_routine SEMI
                ;

procedure_head : PROCEDURE NAME parameters
                ;

parameters : LP para_decl_list RP
            |
            ;

para_decl_list : para_decl_list SEMI para_type_list
                | para_type_list
                ;

para_type_list : var_para_list COLON simple_type_decl
                | val_para_list COLON simple_type_decl
                ;

var_para_list : VAR name_list
              ;

val_para_list : name_list
              ;

routine_body : compound_stmt
             ;

compound_stmt : BEGIN stmt_list END
              ;

stmt_list : stmt_list stmt SEMI
          |
          ;

stmt : INTEGER COLON non_label_stmt
     | non_label_stmt
     ;

non_label_stmt : assign_stmt
               | proc_stmt
               | compound_stmt
               | if_stmt
               | repeat_stmt
               | while_stmt
               | for_stmt
               | case_stmt
               | goto_stmt
               ;

assign_stmt : ID ASSIGN expression
            | ID LB expression RB ASSIGN expression
            | ID DOT ID ASSIGN expression
            ;

proc_stmt : ID
          | ID LP args_list RP
          | sys_proc
          | sys_proc LP expression_list RP
          | READ LP factor RP
          ;

sys_proc : WRITE
         | WRTIELN
         ;

if_stmt : IF expression THEN stmt else_clause
        ;

else_clause : ELSE stmt
            |
            ;

repeat_stmt : REPEAT stmt_list UNTIL expression
            ;

while_stmt : WHILE expression DO stmt
           ;

for_stmt : FOR ID ASSIGN expression direction expression DO stmt
         ;

direction : TO
          | DOWNTO
          ;

case_stmt : CASE expression OF case_expr_list END
          ;

case_expr_list : case_expr_list case_expr
               | case_expr
               ;

case_expr : const_value COLON stmt SEMI
          | ID COLON stmt SEMI
          ;

goto_stmt : GOTO INTEGER
          ;

expression_list : expression_list COMMA expression
                | expression
                ;

expression : expression GE expr
           | expression GT expr
           | expression LE expr
           | expression LT expr
           | expression EQUAL expr
           | expression UNEQUAL expr
           | expr
           ;

expr : expr PLUS term
     | expr MINUS term
     | expr OR term
     | term
     ;

term : term MUL factor
     | term DIV factor
     | term MOD factor
     | term AND factor
     | factor
     ;

factor : ID
       | ID LP args_list RP
       | sys_func
       | sys_func LP args_list RP
       | const_value
       | LP expression RP
       | NOT factor
       | MINUS factor
       | ID LB expression RB
       | ID DOT ID
       ;

sys_func : ABS
         | CHR
         | ODD
         | ORD
         | PRED
         | SQR
         | SQRT
         | SUCC
         ;

args_list : args_list COMMA expression
          | expression
          ;
