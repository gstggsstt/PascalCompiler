%{
	#include "ASTNode.h"
	#include <string>
	#include <iostream>
	// NBlock *programBlock; /* the top level root node of our final AST */

	extern int line;
	extern int column;
	extern int yylex();
	extern Program* program;
	void yyerror(const char *s)
	{
		std::cerr << "Error at " << line << ":" << column << std::endl;
		std::cerr << s << std::endl;
	}
%}

%union {
	ASTNode *astnode;
	ArgsList *argslist;
	ArrayType *arraytype;
	AssignStmt *assignstmt;
	CalcExpr *calcexpr;
	CallFactor *callfactor;
	CallProcStmt *callprocstmt;
	CaseExpr *caseexpr;
	CaseExprList *caseexprlist;
	CaseStmt *casestmt;
	CompoundStmt *compoundstmt;
	ConstCharValue *constcharvalue;
	ConstExprList *constexprlist;
	ConstFactor *constfactor;
	ConstIntValue *constintvalue;
	ConstPart *constpart;
	ConstRealValue *constrealvalue;
	ConstValue *constvalue;
	ConstValueCaseExpr *constvaluecaseexpr;
	CustomType *customtype;
	Direction *direction;
	ElseClause *elseclause;
	EnumType *enumtype;
	Expr *expr;
	Expression *expression;
	ExpressionList *expressionlist;
	Factor *factor;
	FieldDecl *fielddecl;
	FieldDeclList *fielddecllist;
	ForStmt *forstmt;
	Function *function;
	FunctionHead *functionhead;
	GotoStmt *gotostmt;
	IfStmt *ifstmt;
	IndexFactor *indexfactor;
	IndexLeftValue *indexleftvalue;
	LabelPart *labelpart;
	LeftValue *leftvalue;
	MemberFactor *memberfactor;
	MemberLeftValue *memberleftvalue;
	NameCaseExpr *namecaseexpr;
	NameFactor *namefactor;
	NameLeftValue *nameleftvalue;
	NameList *namelist;
	NameProcStmt *nameprocstmt;
	ParaDeclList *paradecllist;
	ParaTypeList *paratypelist;
	Parameters *parameters;
	ParenthesesFactor *parenthesesfactor;
	ProcStmt *procstmt;
	Procedure *procedure;
	ProcedureHead *procedurehead;
	Program *program;
	ProgramHead *programhead;
	RangeType *rangetype;
	ReadProcStmt *readprocstmt;
	RecordType *recordtype;
	RepeatStmt *repeatstmt;
	Routine *routine;
	RoutineBody *routinebody;
	RoutineDecl *routinedecl;
	RoutineHead *routinehead;
	RoutinePart *routinepart;
	SimpleType *simpletype;
	Stmt *stmt;
	StmtList *stmtlist;
	SysCallProcStmt *syscallprocstmt;
	SysFuncCallFactor *sysfunccallfactor;
	SysFuncFactor *sysfuncfactor;
	SysType *systype;
	Term *term;
	TypeDecl *typedecl;
	TypeDeclList *typedecllist;
	TypeDefinition *typedefinition;
	TypePart *typepart;
	VarDecl *vardecl;
	VarDeclList *vardecllist;
	VarParaList *varparalist;
	VarPart *varpart;
	WhileStmt *whilestmt;
	int token;
	std::string *string;
}

%token<token> LP RP LB RB LC RC DOT DOTDOT SEMI COMMA COLON MUL DIV
%token<token> MOD PLUS MINUS UNEQUAL NOT GE GT LE LT EQUAL ASSIGN FALSE MAXINT
%token<token> TRUE ABS CHR ODD ORD PRED SQR SQRT SUCC WRITE WRTIELN TYBOOLEAN
%token<token> TYCHAR TYINTEGER TYREAL AND ARRAY _BEGIN CASE CONST
%token<token> DO DOWNTO ELSE END FOR FUNCTION GOTO IF OF OR PACKED PROCEDURE PROGRAM
%token<token> RECORD REPEAT THEN TO TYPE UNTIL VAR WHILE READ
%token<string> INTEGER REAL CHAR NAME

%type<program> program
%type<programhead> program_head
%type<routine> routine sub_routine
%type<routinehead> routine_head
%type<labelpart> label_part
%type<constpart> const_part
%type<constexprlist> const_expr_list
%type<constvalue> const_value sys_con
%type<typepart> type_part
%type<typedecllist> type_decl_list
%type<typedefinition> type_definition
%type<typedecl> type_decl
%type<simpletype> simple_type_decl
%type<systype> sys_type
%type<arraytype> array_type_decl
%type<recordtype> record_type_decl
%type<fielddecllist> field_decl_list
%type<fielddecl> field_decl
%type<namelist> name_list
%type<varpart> var_part
%type<vardecllist> var_decl_list
%type<vardecl> var_decl
%type<routinepart> routine_part
%type<routinedecl> function_decl procedure_decl
%type<functionhead> function_head
%type<procedurehead> procedure_head
%type<parameters> parameters
%type<paradecllist> para_decl_list
%type<paratypelist> para_type_list
%type<varparalist> var_para_list val_para_list
%type<routinebody> routine_body
%type<compoundstmt> compound_stmt
%type<stmtlist> stmt_list
%type<stmt> stmt non_label_stmt
%type<assignstmt> assign_stmt
%type<leftvalue> left_value
%type<procstmt> proc_stmt
%type<ifstmt> if_stmt
%type<elseclause> else_clause
%type<repeatstmt> repeat_stmt
%type<whilestmt> while_stmt
%type<forstmt> for_stmt
%type<direction> direction
%type<casestmt> case_stmt
%type<caseexprlist> case_expr_list
%type<caseexpr> case_expr
%type<gotostmt> goto_stmt
%type<expressionlist> expression_list
%type<expression> expression
%type<expr> expr
%type<term> term
%type<factor> factor
%type<argslist> args_list
%type<string> sys_func sys_proc

%start program

%%
program : program_head routine DOT { ::program = new Program($1, $2); }
		;

program_head : PROGRAM NAME SEMI { $$ = new ProgramHead(*$2); }
			 ;

routine : routine_head routine_body { $$ = new Routine($1, $2); }
		;

sub_routine : routine_head routine_body { $$ = new Routine($1, $2); }
			;

routine_head : label_part const_part type_part var_part routine_part
			 { $$ = new RoutineHead($1, $2, $3, $4, $5); }
			 ;

label_part : { $$ = new LabelPart(); };

const_part : CONST const_expr_list { $$ = new ConstPart($2); }
		   | { $$ = new ConstPart(new ConstExprList()); }
		   ;

const_expr_list : const_expr_list NAME ASSIGN const_value SEMI
				{ $$ = $1; $$->pushBack(new ConstValueDecl(*$2, $4)); }
				| NAME ASSIGN const_value SEMI
				{ $$ = new ConstExprList(); $$->pushBack(new ConstValueDecl(*$1, $3)); }
				;

const_value : INTEGER { $$ = new ConstIntValue(*$1); }
			| REAL    { $$ = new ConstRealValue(*$1); }
			| CHAR    { $$ = new ConstCharValue(*$1); }
			| sys_con { $$ = $1; }
			;

sys_con : FALSE  { $$ = new ConstIntValue("0"); }
		| MAXINT { $$ = new ConstIntValue("2147483647"); }
		| TRUE   { $$ = new ConstIntValue("1"); }
		;

type_part : TYPE type_decl_list  { $$ = $2; }
		  | { $$ = new TypePart(); }
		  ;

type_decl_list : type_decl_list type_definition
			   { $$ = $1; $$->pushBack($2); }
			   | type_definition
			   { $$ = new TypeDeclList(); $$->pushBack($1); }
			   ;

type_definition : NAME EQUAL type_decl SEMI
				{ $$ = new TypeDefinition(*$1, $3); }
				;

type_decl : simple_type_decl { $$ = $1; }
		  | array_type_decl  { $$ = $1; }
		  | record_type_decl { $$ = $1; }
		  ;

simple_type_decl : sys_type { $$ = $1; }
				 | NAME  { $$ = new CustomType(*$1, std::string("Custom")); }
				 | LP name_list RP { $$ = new EnumType($2, "Enum"); }
				 | const_value DOTDOT const_value { $$ = new RangeType($1, $3, "Range"); }
				 | MINUS const_value DOTDOT const_value { $$ = new RangeType($2->setNeg(), $4, "Range"); }
				 | MINUS const_value DOTDOT MINUS const_value { $$ = new RangeType($2->setNeg(), $5->setNeg(), "Range"); }
				 | NAME DOTDOT NAME { $$ = new NamedRangeType(*$1, *$3, "NamedRange"); }
				 ;

sys_type : TYBOOLEAN { $$ = new SysType("bool"); }
		 | TYREAL    { $$ = new SysType("real"); }
		 | TYCHAR    { $$ = new SysType("char"); }
		 | TYINTEGER { $$ = new SysType("int"); }
		 ;

array_type_decl : ARRAY LB simple_type_decl RB OF type_decl
				{ $$ = new ArrayType($3, $6); }
				;

record_type_decl : RECORD field_decl_list END
				 { $$ = new RecordType($2); }
				 ;

field_decl_list : field_decl_list field_decl
				{ $$ = $1; $$->pushBack($2); }
				| field_decl
				{ $$ = new FieldDeclList(); $$->pushBack($1); }
				;

field_decl : name_list COLON type_decl SEMI
		   { $$ = new FieldDecl($1, $3); }
		   ;

name_list : name_list COMMA NAME
		  { $$ = $1; $$->pushBack(*$3); }
		  | NAME
		  { $$ = new NameList(); $$->pushBack(*$1); }
		  ;

var_part : VAR var_decl_list
		 { $$ = $2; }
		 |
		 { $$ = new VarDeclList(); }
		 ;

var_decl_list : var_decl_list var_decl
			  { $$ = $1; $$->pushBack($2); }
			  | var_decl
			  { $$ = new VarDeclList(); $$->pushBack($1); }
			  ;

var_decl : name_list COLON type_decl SEMI
		 { $$ = new VarDecl($1, $3); }
		 ;

routine_part : routine_part function_decl
			 { $$ = $1; $$->pushBack($2); }
			 | routine_part procedure_decl
			 { $$ = $1; $$->pushBack($2); }
			 | function_decl
			 { $$ = new RoutinePart(); $$->pushBack($1); }
			 | procedure_decl
			 { $$ = new RoutinePart(); $$->pushBack($1); }
			 |
			 { $$ = new RoutinePart(); }
			 ;

function_decl : function_head SEMI sub_routine SEMI
			  { $$ = new Function($1, $3); }
			  ;

function_head : FUNCTION NAME parameters COLON simple_type_decl
			  { $$ = new FunctionHead(*$2, $3, $5); }
			  ;

procedure_decl : procedure_head SEMI sub_routine SEMI
			   { $$ = new Procedure($1, $3); }
 			   ;

procedure_head : PROCEDURE NAME parameters
			   { $$ = new ProcedureHead(*$2, $3); }
 			   ;

parameters : LP para_decl_list RP
		   { $$ = $2; }
 		   | LP RP
 		   { $$ = new ParaDeclList(); }
 		   ;

para_decl_list : para_decl_list SEMI para_type_list
			   { $$ = $1; $$->pushBack($3); }
 			   | para_type_list
			   { $$ = new ParaDeclList(); $$->pushBack($1); }
 			   ;

para_type_list : var_para_list COLON simple_type_decl
			   { $$ = new ParaTypeList($1, $3); }
			   | val_para_list COLON simple_type_decl
			   { $$ = new ParaTypeList($1, $3); }
 			   ;

var_para_list : VAR name_list
			  { $$ = $2; $$->ref = true; }
			  ;

val_para_list : name_list
		{ $$ = $1; $$->ref = false; }
		;

routine_body : compound_stmt
			 { $$ = $1; }
			 ;

compound_stmt : _BEGIN stmt_list END
			  { $$ = $2; }
			  ;

stmt_list : stmt_list stmt SEMI
		  { $$ = $1; $$->pushBack($2); }
		  |
		  { $$ = new StmtList(); }
		  ;

stmt : NAME COLON non_label_stmt
	 { $$ = $3; $$->addLabel(*$1); }
	 | non_label_stmt
	 { $$ = $1; }
	 ;

non_label_stmt : assign_stmt
			   { $$ = $1; }
			   | proc_stmt
			   { $$ = $1; }
			   | compound_stmt
			   { $$ = $1; }
			   | if_stmt
			   { $$ = $1; }
			   | repeat_stmt
			   { $$ = $1; }
			   | while_stmt
			   { $$ = $1; }
			   | for_stmt
			   { $$ = $1; }
			   | case_stmt
			   { $$ = $1; }
			   | goto_stmt
			   { $$ = $1; }
			   |
			   { $$ = new Stmt(); }
			   ;

assign_stmt : left_value ASSIGN expression
			{ $$ = new AssignStmt($1, $3); }
			;

left_value : NAME
		   { $$ = new NameLeftValue(*$1); }
		   | NAME LB expression RB
		   { $$ = new IndexLeftValue(*$1, $3); }
		   | NAME DOT NAME
		   { $$ = new MemberLeftValue(*$1, *$3); }
		   ;

proc_stmt : NAME
		  { $$ = new NameProcStmt(*$1); }
		  | NAME LP args_list RP
		  { $$ = new CallProcStmt(*$1, $3); }
		  | sys_proc LP RP
		  { $$ = new SysCallProcStmt(*$1, new ExpressionList()); }
		  | sys_proc LP expression_list RP
		  { $$ = new SysCallProcStmt(*$1, $3); }
		  | READ LP left_value RP
		  { $$ = new ReadProcStmt($3); }
		  ;

sys_proc : WRITE
		 { $$ = new std::string("write"); }
		 | WRTIELN
		 { $$ = new std::string("writeln"); }
		 ;

if_stmt : IF expression THEN stmt else_clause
		{ $$ = new IfStmt($2, $4, $5); }
		;

else_clause : ELSE stmt
			{ $$ = new ElseClause($2); }
			|
			{ $$ = new ElseClause(); }
			;

repeat_stmt : REPEAT stmt_list UNTIL expression
			{ $$ = new RepeatStmt($2, $4); }
			;

while_stmt : WHILE expression DO stmt
		   { $$ = new WhileStmt($2, $4); }
		   ;

for_stmt : FOR NAME ASSIGN expression direction expression DO stmt
		 { $$ = new ForStmt(*$2, $4, $5, $6, $8); }
		 ;

direction : TO
		  { $$ = new Direction("to"); }
		  | DOWNTO
		  { $$ = new Direction("downto"); }
		  ;

case_stmt : CASE expression OF case_expr_list END
		  { $$ = new CaseStmt($2, $4); }
		  ;

case_expr_list : case_expr_list case_expr
			   { $$ = $1; $$->pushBack($2); }
			   | case_expr
			   { $$ = new CaseExprList(); $$->pushBack($1); }
			   ;

case_expr : const_value COLON stmt SEMI
		  { $$ = new ConstValueCaseExpr($1, $3); }
		  | NAME COLON stmt SEMI
		  { $$ = new NameCaseExpr(*$1, $3); }
		  ;

goto_stmt : GOTO NAME
		  { $$ = new GotoStmt(*$2); }
		  ;

expression_list : expression_list COMMA expression
				{ $$ = $1; $$->pushBack($3); }
				| expression
				{ $$ = new ExpressionList(); $$->pushBack($1); }
				;

expression : expression GE expr
		   { $$ = new CalcExpr($1, $3, ">="); }
		   | expression GT expr
		   { $$ = new CalcExpr($1, $3, ">"); }
		   | expression LE expr
		   { $$ = new CalcExpr($1, $3, "<="); }
		   | expression LT expr
		   { $$ = new CalcExpr($1, $3, "<"); }
		   | expression EQUAL expr
		   { $$ = new CalcExpr($1, $3, "="); }
		   | expression UNEQUAL expr
		   { $$ = new CalcExpr($1, $3, "<>"); }
		   | expr
		   { $$ = $1; }
		   ;

expr : expr PLUS term
	 { $$ = new CalcExpr($1, $3, "+"); }
	 | expr MINUS term
	 { $$ = new CalcExpr($1, $3, "-"); }
	 | expr OR term
	 { $$ = new BinaryExpr($1, $3, "or"); }
	 | term
	 { $$ = $1; }
	 ;

term : term MUL factor
	 { $$ = new CalcExpr($1, $3, "*"); }
	 | term DIV factor
	 { $$ = new CalcExpr($1, $3, "/"); }
	 | term MOD factor
	 { $$ = new CalcExpr($1, $3, "mod"); }
	 | term AND factor
	 { $$ = new BinaryExpr($1, $3, "and"); }
	 | factor
	 { $$ = $1; }
	 ;

factor : NAME
	   { $$ = new NameFactor(*$1); }
	   | NAME LP args_list RP
	   { $$ = new CallFactor(*$1, $3); }
	   | sys_func
	   { $$ = new SysFuncFactor(*$1); }
	   | sys_func LP args_list RP
	   { $$ = new SysFuncCallFactor(*$1, $3); }
	   | const_value
	   { $$ = new ConstFactor($1); }
	   | LP expression RP
	   { $$ = new ParenthesesFactor($2); }
	   | NOT factor
	   { $$ = $2; $$->setNot(); }
	   | MINUS factor
	   { $$ = $2; $$->setNeg(); }
	   | NAME LB expression RB
	   { $$ = new IndexFactor(*$1, $3); }
	   | NAME DOT NAME
	   { $$ = new MemberFactor(*$1, *$3); }
	   ;

sys_func : ABS
		 { $$ = new std::string("abs"); }
		 | CHR
		 { $$ = new std::string("chr"); }
		 | ODD
		 { $$ = new std::string("odd"); }
		 | ORD
		 { $$ = new std::string("ord"); }
		 | PRED
		 { $$ = new std::string("pred"); }
		 | SQR
		 { $$ = new std::string("sqr"); }
		 | SQRT
		 { $$ = new std::string("sqrt"); }
		 | SUCC
		 { $$ = new std::string("succ"); }
		 ;

args_list : args_list COMMA expression
		  { $$ = $1; $$->pushBack($3); }
		  | expression
		  { $$ = new ArgsList(); $$->pushBack($1); }
		  |
		  { $$ = new ArgsList(); }
		  ;
