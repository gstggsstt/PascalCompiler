/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "/home/gster/CLionProjects/SPL/SPL.y"

	#include "ASTNode.h"
	#include <string>
	#include <iostream>
	// NBlock *programBlock; /* the top level root node of our final AST */

	extern int yylex();
	extern Program* program;
	void yyerror(const char *s) { std::cerr << s << std::endl; }

#line 81 "/home/gster/CLionProjects/SPL/parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_HOME_GSTER_CLIONPROJECTS_SPL_PARSER_HPP_INCLUDED
# define YY_YY_HOME_GSTER_CLIONPROJECTS_SPL_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LP = 258,
    RP = 259,
    LB = 260,
    RB = 261,
    LC = 262,
    RC = 263,
    DOT = 264,
    DOTDOT = 265,
    SEMI = 266,
    COMMA = 267,
    COLON = 268,
    MUL = 269,
    DIV = 270,
    MOD = 271,
    PLUS = 272,
    MINUS = 273,
    UNEQUAL = 274,
    NOT = 275,
    GE = 276,
    GT = 277,
    LE = 278,
    LT = 279,
    EQUAL = 280,
    ASSIGN = 281,
    FALSE = 282,
    MAXINT = 283,
    TRUE = 284,
    ABS = 285,
    CHR = 286,
    ODD = 287,
    ORD = 288,
    PRED = 289,
    SQR = 290,
    SQRT = 291,
    SUCC = 292,
    WRITE = 293,
    WRTIELN = 294,
    TYBOOLEAN = 295,
    TYCHAR = 296,
    TYINTEGER = 297,
    TYREAL = 298,
    AND = 299,
    ARRAY = 300,
    _BEGIN = 301,
    CASE = 302,
    CONST = 303,
    DO = 304,
    DOWNTO = 305,
    ELSE = 306,
    END = 307,
    FOR = 308,
    FUNCTION = 309,
    GOTO = 310,
    IF = 311,
    OF = 312,
    OR = 313,
    PACKED = 314,
    PROCEDURE = 315,
    PROGRAM = 316,
    RECORD = 317,
    REPEAT = 318,
    THEN = 319,
    TO = 320,
    TYPE = 321,
    UNTIL = 322,
    VAR = 323,
    WHILE = 324,
    READ = 325,
    INTEGER = 326,
    REAL = 327,
    CHAR = 328,
    NAME = 329
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "/home/gster/CLionProjects/SPL/SPL.y"

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
	SysFunc *sysfunc;
	SysFuncCallFactor *sysfunccallfactor;
	SysFuncFactor *sysfuncfactor;
	SysProc *sysproc;
	SysProcStmt *sysprocstmt;
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

#line 296 "/home/gster/CLionProjects/SPL/parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_GSTER_CLIONPROJECTS_SPL_PARSER_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   385

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  143
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  271

#define YYUNDEFTOK  2
#define YYMAXUTOK   329


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   167,   167,   170,   173,   176,   179,   183,   185,   186,
     189,   191,   195,   196,   197,   198,   201,   202,   203,   206,
     207,   210,   212,   216,   220,   221,   222,   225,   226,   227,
     228,   229,   230,   231,   234,   235,   236,   237,   240,   244,
     248,   250,   254,   258,   260,   264,   267,   270,   272,   276,
     280,   282,   284,   286,   289,   292,   296,   300,   304,   308,
     311,   314,   316,   320,   324,   326,   330,   334,   338,   341,
     344,   346,   350,   352,   354,   356,   358,   360,   362,   364,
     366,   370,   374,   376,   378,   382,   384,   386,   388,   390,
     394,   396,   400,   404,   407,   410,   414,   418,   422,   424,
     428,   432,   434,   438,   440,   444,   448,   450,   454,   456,
     458,   460,   462,   464,   466,   470,   472,   474,   476,   480,
     482,   484,   486,   488,   492,   494,   496,   498,   500,   502,
     504,   506,   508,   510,   514,   516,   518,   520,   522,   524,
     526,   528,   532,   534
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LP", "RP", "LB", "RB", "LC", "RC",
  "DOT", "DOTDOT", "SEMI", "COMMA", "COLON", "MUL", "DIV", "MOD", "PLUS",
  "MINUS", "UNEQUAL", "NOT", "GE", "GT", "LE", "LT", "EQUAL", "ASSIGN",
  "FALSE", "MAXINT", "TRUE", "ABS", "CHR", "ODD", "ORD", "PRED", "SQR",
  "SQRT", "SUCC", "WRITE", "WRTIELN", "TYBOOLEAN", "TYCHAR", "TYINTEGER",
  "TYREAL", "AND", "ARRAY", "_BEGIN", "CASE", "CONST", "DO", "DOWNTO",
  "ELSE", "END", "FOR", "FUNCTION", "GOTO", "IF", "OF", "OR", "PACKED",
  "PROCEDURE", "PROGRAM", "RECORD", "REPEAT", "THEN", "TO", "TYPE",
  "UNTIL", "VAR", "WHILE", "READ", "INTEGER", "REAL", "CHAR", "NAME",
  "$accept", "program", "program_head", "routine", "sub_routine",
  "routine_head", "label_part", "const_part", "const_expr_list",
  "const_value", "sys_con", "type_part", "type_decl_list",
  "type_definition", "type_decl", "simple_type_decl", "sys_type",
  "array_type_decl", "record_type_decl", "field_decl_list", "field_decl",
  "name_list", "var_part", "var_decl_list", "var_decl", "routine_part",
  "function_decl", "function_head", "procedure_decl", "procedure_head",
  "parameters", "para_decl_list", "para_type_list", "var_para_list",
  "routine_body", "compound_stmt", "stmt_list", "stmt", "non_label_stmt",
  "assign_stmt", "left_value", "proc_stmt", "sys_proc", "if_stmt",
  "else_clause", "repeat_stmt", "while_stmt", "for_stmt", "direction",
  "case_stmt", "case_expr_list", "case_expr", "goto_stmt",
  "expression_list", "expression", "expr", "term", "factor", "sys_func",
  "args_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329
};
# endif

#define YYPACT_NINF (-190)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-83)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,   -52,    73,  -190,    65,  -190,    79,    45,    55,  -190,
    -190,  -190,  -190,  -190,    31,    47,   207,    93,    52,    56,
      61,  -190,  -190,     6,  -190,    63,    81,     6,  -190,     6,
     133,   137,    22,  -190,   142,  -190,  -190,   128,  -190,   153,
    -190,  -190,  -190,  -190,  -190,  -190,    71,   134,   136,    56,
    -190,    84,    42,     6,     6,     6,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
     122,  -190,  -190,    35,    -7,   101,  -190,   163,   141,  -190,
     215,   227,   319,     6,   265,     6,     6,    88,  -190,     6,
       6,   158,    71,   106,  -190,  -190,    37,    84,  -190,    96,
      97,    42,  -190,   164,  -190,   173,   333,  -190,  -190,     6,
       6,   100,     6,     6,     6,     6,     6,     6,   -10,     6,
       6,     6,     6,     6,     6,     6,     6,     6,   253,     6,
     253,   186,  -190,   348,    16,   340,  -190,   348,    17,   348,
    -190,   180,    84,    71,  -190,  -190,  -190,  -190,   187,    84,
     183,   189,   190,  -190,  -190,  -190,  -190,   126,   106,  -190,
     199,   199,  -190,  -190,  -190,  -190,  -190,    62,   360,  -190,
      -7,    -7,    -7,    -7,    -7,    -7,   192,   194,   159,  -190,
     101,   101,   101,  -190,  -190,  -190,  -190,    78,   193,   152,
     348,  -190,  -190,  -190,     6,  -190,  -190,     6,  -190,    83,
     200,   154,   -29,  -190,    40,   146,    71,  -190,  -190,   198,
      54,   208,  -190,   211,    45,   212,  -190,  -190,   253,   253,
    -190,  -190,  -190,  -190,  -190,     6,   253,  -190,   348,   348,
    -190,    92,   218,  -190,  -190,   106,  -190,  -190,  -190,    84,
     217,   103,  -190,   222,   154,  -190,  -190,  -190,   230,   231,
     326,  -190,    71,  -190,   204,   233,   217,  -190,    54,   154,
    -190,  -190,  -190,   253,  -190,   106,  -190,  -190,  -190,  -190,
    -190
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     7,     0,     1,     0,     0,     9,     3,
       2,    69,     4,    66,     0,    20,     0,     0,     8,     0,
      46,    90,    91,     0,    67,     0,     0,     0,    69,     0,
       0,     0,    85,    74,     0,    71,    72,     0,    73,    87,
      75,    76,    77,    78,    79,    80,     0,     0,     0,    19,
      22,     0,    54,     0,     0,     0,    16,    17,    18,   134,
     135,   136,   137,   138,   139,   140,   141,    12,    13,    14,
     124,   128,    15,     0,   114,   118,   123,   126,     0,   105,
       0,     0,     0,     0,     0,     0,     0,     0,    68,     0,
       0,     0,     0,     0,    21,    44,     0,    45,    48,     0,
       0,     6,    52,     0,    53,     0,     0,   131,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,   143,     0,     0,    84,    81,     0,   107,
      11,     0,     0,     0,    34,    36,    37,    35,     0,     0,
      28,     0,     0,    24,    27,    25,    26,     0,     0,    47,
      60,    60,    50,    51,     7,     7,   129,     0,     0,   133,
     113,   108,   109,   110,   111,   112,     0,     0,     0,   102,
     115,   116,   117,   119,   120,   121,   122,     0,     0,    94,
      95,    96,    89,    86,     0,    83,    88,     0,    10,     0,
       0,     0,     0,    41,     0,     0,     0,    23,    43,     0,
       0,     0,    58,     0,     0,     0,   125,   132,     0,     0,
     100,   101,   127,    99,    98,     0,     0,    92,   142,   106,
      29,     0,     0,    39,    40,     0,    33,    30,    49,     0,
      65,     0,    62,     0,     0,    55,     5,    57,     0,     0,
       0,    93,     0,    31,     0,     0,    64,    59,     0,     0,
      56,   104,   103,     0,    32,     0,    42,    61,    63,    97,
      38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -190,  -190,  -190,  -190,    90,   254,  -190,  -190,  -190,   -46,
    -190,  -190,  -190,   219,  -154,  -189,  -190,  -190,  -190,  -190,
      67,  -135,  -190,  -190,   167,  -190,   155,  -190,   166,  -190,
     110,  -190,    14,  -190,    70,    -6,   247,  -125,   201,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,   108,  -190,  -190,   -21,   135,    20,   -39,  -190,   -96
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,   213,   214,     8,    15,    18,    71,
      72,    20,    49,    50,   152,   153,   154,   155,   156,   202,
     203,    96,    52,    97,    98,   101,   102,   103,   104,   105,
     211,   241,   242,   243,    12,    33,    16,    34,    35,    36,
      37,    38,    39,    40,   227,    41,    42,    43,   225,    44,
     178,   179,    45,   138,   133,    74,    75,    76,    77,   134
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,    13,    73,   189,   209,   191,    80,   199,    82,    53,
     119,   120,   232,   167,   204,   107,   108,    56,    57,    58,
     193,   196,     4,   233,    54,    85,    55,    86,   194,   197,
     187,    87,   106,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,   131,    95,   141,   151,   -82,   157,
     158,   121,   157,   235,   112,   260,   113,   114,   115,   116,
     117,    67,    68,    69,   176,   135,   216,   204,   137,   139,
     268,     1,   177,     5,   194,   240,     9,    67,    68,    69,
      70,   255,   222,   183,   184,   185,   186,   230,    10,   168,
     194,    11,   118,   248,   249,   157,    99,   200,    56,    57,
      58,   251,   100,    14,   256,    17,   188,   257,   190,   142,
     252,   270,   151,    19,   258,   122,   123,   124,    46,    56,
      57,    58,   239,   240,   143,   109,    47,   110,    95,    51,
      48,   111,   177,    56,    57,    58,    83,    78,   269,   180,
     181,   182,    67,    68,    69,   125,   144,   145,   146,   147,
      84,   148,    79,    88,    89,   151,    90,   142,    95,    92,
     237,    93,   136,    67,    68,    69,   126,   127,   149,   140,
     160,   161,   143,   228,   169,   164,   229,    67,    68,    69,
     150,    56,    57,    58,   165,   253,    56,    57,    58,   151,
     192,   198,   201,   205,   144,   145,   146,   147,   151,   206,
     208,   207,   210,   226,   250,   218,   264,   219,    13,   238,
     231,   220,   112,   151,   113,   114,   115,   116,   117,   151,
     236,   244,   245,   247,   254,    67,    68,    69,   150,   157,
      67,    68,    69,   176,   112,   259,   113,   114,   115,   116,
     117,   261,   262,   223,   266,    21,    22,   170,   171,   172,
     173,   174,   175,    11,    23,   215,   162,     7,   224,    24,
      25,   265,    26,    27,   159,    21,    22,   163,    94,   234,
      28,   212,   267,    11,    23,    81,    29,    30,    31,   128,
      25,    32,    26,    27,   246,   132,   221,     0,     0,     0,
      28,    21,    22,     0,   129,     0,    29,    30,    31,    11,
      23,    32,     0,    21,    22,     0,    25,     0,    26,    27,
       0,    11,    23,     0,     0,     0,    28,     0,    25,     0,
      26,    27,    29,    30,    31,     0,     0,    32,    28,     0,
       0,     0,     0,     0,    29,    30,     0,   166,   112,    32,
     113,   114,   115,   116,   117,   112,   195,   113,   114,   115,
     116,   117,   112,     0,   113,   114,   115,   116,   117,   112,
       0,   113,   114,   115,   116,   117,   217,   112,   130,   113,
     114,   115,   116,   117,     0,   263,     0,     0,     0,   112,
       0,   113,   114,   115,   116,   117
};

static const yytype_int16 yycheck[] =
{
      46,     7,    23,   128,   158,   130,    27,   142,    29,     3,
      17,    18,   201,   109,   149,    54,    55,    27,    28,    29,
       4,     4,    74,    52,    18,     3,    20,     5,    12,    12,
     126,     9,    53,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    83,    74,    92,    93,    26,    12,
      13,    58,    12,    13,    19,   244,    21,    22,    23,    24,
      25,    71,    72,    73,    74,    86,     4,   202,    89,    90,
     259,    61,   118,     0,    12,   210,    11,    71,    72,    73,
      74,   235,     4,   122,   123,   124,   125,     4,     9,   110,
      12,    46,    57,   218,   219,    12,    54,   143,    27,    28,
      29,   226,    60,    48,   239,    74,   127,     4,   129,     3,
      18,   265,   158,    66,    11,    14,    15,    16,    25,    27,
      28,    29,    68,   258,    18,     3,    74,     5,    74,    68,
      74,     9,   178,    27,    28,    29,     3,    74,   263,   119,
     120,   121,    71,    72,    73,    44,    40,    41,    42,    43,
      13,    45,    71,    11,    26,   201,     3,     3,    74,    25,
     206,    25,    74,    71,    72,    73,     3,    26,    62,    11,
      74,    74,    18,   194,    74,    11,   197,    71,    72,    73,
      74,    27,    28,    29,    11,   231,    27,    28,    29,   235,
       4,    11,     5,    10,    40,    41,    42,    43,   244,    10,
      74,    11,     3,    51,   225,    13,   252,    13,   214,    11,
      10,    52,    19,   259,    21,    22,    23,    24,    25,   265,
      74,    13,    11,    11,     6,    71,    72,    73,    74,    12,
      71,    72,    73,    74,    19,    13,    21,    22,    23,    24,
      25,    11,    11,    50,    11,    38,    39,   112,   113,   114,
     115,   116,   117,    46,    47,   165,   101,     3,    65,    52,
      53,    57,    55,    56,    97,    38,    39,   101,    49,   202,
      63,   161,   258,    46,    47,    28,    69,    70,    71,    64,
      53,    74,    55,    56,   214,    84,   178,    -1,    -1,    -1,
      63,    38,    39,    -1,    67,    -1,    69,    70,    71,    46,
      47,    74,    -1,    38,    39,    -1,    53,    -1,    55,    56,
      -1,    46,    47,    -1,    -1,    -1,    63,    -1,    53,    -1,
      55,    56,    69,    70,    71,    -1,    -1,    74,    63,    -1,
      -1,    -1,    -1,    -1,    69,    70,    -1,     4,    19,    74,
      21,    22,    23,    24,    25,    19,     6,    21,    22,    23,
      24,    25,    19,    -1,    21,    22,    23,    24,    25,    19,
      -1,    21,    22,    23,    24,    25,     6,    19,    49,    21,
      22,    23,    24,    25,    -1,    49,    -1,    -1,    -1,    19,
      -1,    21,    22,    23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    76,    77,    74,     0,    78,    80,    81,    11,
       9,    46,   109,   110,    48,    82,   111,    74,    83,    66,
      86,    38,    39,    47,    52,    53,    55,    56,    63,    69,
      70,    71,    74,   110,   112,   113,   114,   115,   116,   117,
     118,   120,   121,   122,   124,   127,    25,    74,    74,    87,
      88,    68,    97,     3,    18,    20,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    71,    72,    73,
      74,    84,    85,   129,   130,   131,   132,   133,    74,    71,
     129,   111,   129,     3,    13,     3,     5,     9,    11,    26,
       3,    84,    25,    25,    88,    74,    96,    98,    99,    54,
      60,   100,   101,   102,   103,   104,   129,   132,   132,     3,
       5,     9,    19,    21,    22,    23,    24,    25,    57,    17,
      18,    58,    14,    15,    16,    44,     3,    26,    64,    67,
      49,   132,   113,   129,   134,   129,    74,   129,   128,   129,
      11,    84,     3,    18,    40,    41,    42,    43,    45,    62,
      74,    84,    89,    90,    91,    92,    93,    12,    13,    99,
      74,    74,   101,   103,    11,    11,     4,   134,   129,    74,
     130,   130,   130,   130,   130,   130,    74,    84,   125,   126,
     131,   131,   131,   132,   132,   132,   132,   134,   129,   112,
     129,   112,     4,     4,    12,     6,     4,    12,    11,    96,
      84,     5,    94,    95,    96,    10,    10,    11,    74,    89,
       3,   105,   105,    79,    80,    79,     4,     6,    13,    13,
      52,   126,     4,    50,    65,   123,    51,   119,   129,   129,
       4,    10,    90,    52,    95,    13,    74,    84,    11,    68,
      96,   106,   107,   108,    13,    11,   109,    11,   112,   112,
     129,   112,    18,    84,     6,    89,    96,     4,    11,    13,
      90,    11,    11,    49,    84,    57,    11,   107,    90,   112,
      89
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    77,    78,    79,    80,    81,    82,    82,
      83,    83,    84,    84,    84,    84,    85,    85,    85,    86,
      86,    87,    87,    88,    89,    89,    89,    90,    90,    90,
      90,    90,    90,    90,    91,    91,    91,    91,    92,    93,
      94,    94,    95,    96,    96,    97,    97,    98,    98,    99,
     100,   100,   100,   100,   100,   101,   102,   103,   104,   105,
     105,   106,   106,   107,   108,   108,   109,   110,   111,   111,
     112,   112,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   114,   115,   115,   115,   116,   116,   116,   116,   116,
     117,   117,   118,   119,   119,   120,   121,   122,   123,   123,
     124,   125,   125,   126,   126,   127,   128,   128,   129,   129,
     129,   129,   129,   129,   129,   130,   130,   130,   130,   131,
     131,   131,   131,   131,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   133,   133,   133,   133,   133,   133,
     133,   133,   134,   134
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     2,     2,     5,     0,     2,     0,
       5,     4,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     2,     1,     4,     1,     1,     1,     1,     1,     3,
       3,     4,     5,     3,     1,     1,     1,     1,     6,     3,
       2,     1,     4,     3,     1,     2,     0,     2,     1,     4,
       2,     2,     1,     1,     0,     4,     5,     4,     3,     3,
       0,     3,     1,     3,     2,     1,     1,     3,     3,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     4,     3,     1,     4,     1,     4,     4,
       1,     1,     5,     2,     0,     4,     4,     8,     1,     1,
       5,     2,     1,     4,     4,     2,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     3,     1,     1,     4,     1,     4,     1,     3,
       2,     2,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 167 "/home/gster/CLionProjects/SPL/SPL.y"
                                   { ::program = new Program((yyvsp[-2].programhead), (yyvsp[-1].routine)); }
#line 1702 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 3:
#line 170 "/home/gster/CLionProjects/SPL/SPL.y"
                                 { (yyval.programhead) = new ProgramHead(*(yyvsp[-1].string)); }
#line 1708 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 4:
#line 173 "/home/gster/CLionProjects/SPL/SPL.y"
                                    { (yyval.routine) = new Routine((yyvsp[-1].routinehead), (yyvsp[0].routinebody)); }
#line 1714 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 5:
#line 176 "/home/gster/CLionProjects/SPL/SPL.y"
                                        { (yyval.routine) = new Routine((yyvsp[-1].routinehead), (yyvsp[0].routinebody)); }
#line 1720 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 6:
#line 180 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.routinehead) = new RoutineHead((yyvsp[-4].labelpart), (yyvsp[-3].constpart), (yyvsp[-2].typepart), (yyvsp[-1].varpart), (yyvsp[0].routinepart)); }
#line 1726 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 7:
#line 183 "/home/gster/CLionProjects/SPL/SPL.y"
             { (yyval.labelpart) = new LabelPart(); }
#line 1732 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 8:
#line 185 "/home/gster/CLionProjects/SPL/SPL.y"
                                   { (yyval.constpart) = new ConstPart((yyvsp[0].constexprlist)); }
#line 1738 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 9:
#line 186 "/home/gster/CLionProjects/SPL/SPL.y"
                     { (yyval.constpart) = new ConstPart(new ConstExprList()); }
#line 1744 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 10:
#line 190 "/home/gster/CLionProjects/SPL/SPL.y"
                                { (yyval.constexprlist) = (yyvsp[-4].constexprlist); (yyval.constexprlist)->pushBack(new ConstValueDecl(*(yyvsp[-3].string), (yyvsp[-1].constvalue))); }
#line 1750 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 11:
#line 192 "/home/gster/CLionProjects/SPL/SPL.y"
                                { (yyval.constexprlist) = new ConstExprList(); (yyval.constexprlist)->pushBack(new ConstValueDecl(*(yyvsp[-3].string), (yyvsp[-1].constvalue))); }
#line 1756 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 12:
#line 195 "/home/gster/CLionProjects/SPL/SPL.y"
                      { (yyval.constvalue) = new ConstIntValue(*(yyvsp[0].string)); }
#line 1762 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 13:
#line 196 "/home/gster/CLionProjects/SPL/SPL.y"
                                  { (yyval.constvalue) = new ConstRealValue(*(yyvsp[0].string)); }
#line 1768 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 14:
#line 197 "/home/gster/CLionProjects/SPL/SPL.y"
                                  { (yyval.constvalue) = new ConstCharValue(*(yyvsp[0].string)); }
#line 1774 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 15:
#line 198 "/home/gster/CLionProjects/SPL/SPL.y"
                                  { (yyval.constvalue) = (yyvsp[0].constvalue); }
#line 1780 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 16:
#line 201 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.constvalue) = new ConstIntValue("0"); }
#line 1786 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 17:
#line 202 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.constvalue) = new ConstIntValue("2147483647"); }
#line 1792 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 18:
#line 203 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.constvalue) = new ConstIntValue("1"); }
#line 1798 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 19:
#line 206 "/home/gster/CLionProjects/SPL/SPL.y"
                                 { (yyval.typepart) = (yyvsp[0].typedecllist); }
#line 1804 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 20:
#line 207 "/home/gster/CLionProjects/SPL/SPL.y"
                    { (yyval.typepart) = new TypePart(); }
#line 1810 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 21:
#line 211 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.typedecllist) = (yyvsp[-1].typedecllist); (yyval.typedecllist)->pushBack((yyvsp[0].typedefinition)); }
#line 1816 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 22:
#line 213 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.typedecllist) = new TypeDeclList(); (yyval.typedecllist)->pushBack((yyvsp[0].typedefinition)); }
#line 1822 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 23:
#line 217 "/home/gster/CLionProjects/SPL/SPL.y"
                                { (yyval.typedefinition) = new TypeDefinition(*(yyvsp[-3].string), (yyvsp[-1].typedecl)); }
#line 1828 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 24:
#line 220 "/home/gster/CLionProjects/SPL/SPL.y"
                             { (yyval.typedecl) = (yyvsp[0].simpletype); }
#line 1834 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 25:
#line 221 "/home/gster/CLionProjects/SPL/SPL.y"
                                     { (yyval.typedecl) = (yyvsp[0].arraytype); }
#line 1840 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 26:
#line 222 "/home/gster/CLionProjects/SPL/SPL.y"
                                     { (yyval.typedecl) = (yyvsp[0].recordtype); }
#line 1846 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 27:
#line 225 "/home/gster/CLionProjects/SPL/SPL.y"
                            { (yyval.simpletype) = (yyvsp[0].systype); }
#line 1852 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 28:
#line 226 "/home/gster/CLionProjects/SPL/SPL.y"
                                         { (yyval.simpletype) = new CustomType(*(yyvsp[0].string)); }
#line 1858 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 29:
#line 227 "/home/gster/CLionProjects/SPL/SPL.y"
                                                   { (yyval.simpletype) = new EnumType((yyvsp[-1].namelist)); }
#line 1864 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 30:
#line 228 "/home/gster/CLionProjects/SPL/SPL.y"
                                                                  { (yyval.simpletype) = new RangeType((yyvsp[-2].constvalue), (yyvsp[0].constvalue)); }
#line 1870 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 31:
#line 229 "/home/gster/CLionProjects/SPL/SPL.y"
                                                                        { (yyval.simpletype) = new RangeType((yyvsp[-2].constvalue)->setNeg(), (yyvsp[0].constvalue)); }
#line 1876 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 32:
#line 230 "/home/gster/CLionProjects/SPL/SPL.y"
                                                                              { (yyval.simpletype) = new RangeType((yyvsp[-3].constvalue)->setNeg(), (yyvsp[0].constvalue)->setNeg()); }
#line 1882 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 33:
#line 231 "/home/gster/CLionProjects/SPL/SPL.y"
                                                    { (yyval.simpletype) = new NamedRangeType(*(yyvsp[-2].string), *(yyvsp[0].string)); }
#line 1888 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 34:
#line 234 "/home/gster/CLionProjects/SPL/SPL.y"
                     { (yyval.systype) = new SysType("bool"); }
#line 1894 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 35:
#line 235 "/home/gster/CLionProjects/SPL/SPL.y"
                             { (yyval.systype) = new SysType("real"); }
#line 1900 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 36:
#line 236 "/home/gster/CLionProjects/SPL/SPL.y"
                             { (yyval.systype) = new SysType("char"); }
#line 1906 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 37:
#line 237 "/home/gster/CLionProjects/SPL/SPL.y"
                             { (yyval.systype) = new SysType("int"); }
#line 1912 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 38:
#line 241 "/home/gster/CLionProjects/SPL/SPL.y"
                                { (yyval.arraytype) = new ArrayType((yyvsp[-3].simpletype), (yyvsp[0].typedecl)); }
#line 1918 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 39:
#line 245 "/home/gster/CLionProjects/SPL/SPL.y"
                                 { (yyval.recordtype) = new RecordType((yyvsp[-1].fielddecllist)); }
#line 1924 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 40:
#line 249 "/home/gster/CLionProjects/SPL/SPL.y"
                                { (yyval.fielddecllist) = (yyvsp[-1].fielddecllist); (yyval.fielddecllist)->pushBack((yyvsp[0].fielddecl)); }
#line 1930 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 41:
#line 251 "/home/gster/CLionProjects/SPL/SPL.y"
                                { (yyval.fielddecllist) = new FieldDeclList(); (yyval.fielddecllist)->pushBack((yyvsp[0].fielddecl)); }
#line 1936 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 42:
#line 255 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.fielddecl) = new FieldDecl((yyvsp[-3].namelist), (yyvsp[-1].typedecl)); }
#line 1942 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 43:
#line 259 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.namelist) = (yyvsp[-2].namelist); (yyval.namelist)->pushBack(*(yyvsp[0].string)); }
#line 1948 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 44:
#line 261 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.namelist) = new NameList(); (yyval.namelist)->pushBack(*(yyvsp[0].string)); }
#line 1954 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 45:
#line 265 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.varpart) = (yyvsp[0].vardecllist); }
#line 1960 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 46:
#line 267 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.varpart) = new VarDeclList(); }
#line 1966 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 47:
#line 271 "/home/gster/CLionProjects/SPL/SPL.y"
                          { (yyval.vardecllist) = (yyvsp[-1].vardecllist); (yyval.vardecllist)->pushBack((yyvsp[0].vardecl)); }
#line 1972 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 48:
#line 273 "/home/gster/CLionProjects/SPL/SPL.y"
                          { (yyval.vardecllist) = new VarDeclList(); (yyval.vardecllist)->pushBack((yyvsp[0].vardecl)); }
#line 1978 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 49:
#line 277 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.vardecl) = new VarDecl((yyvsp[-3].namelist), (yyvsp[-1].typedecl)); }
#line 1984 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 50:
#line 281 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.routinepart) = (yyvsp[-1].routinepart); (yyval.routinepart)->pushBack((yyvsp[0].routinedecl)); }
#line 1990 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 51:
#line 283 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.routinepart) = (yyvsp[-1].routinepart); (yyval.routinepart)->pushBack((yyvsp[0].routinedecl)); }
#line 1996 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 52:
#line 285 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.routinepart) = new RoutinePart(); (yyval.routinepart)->pushBack((yyvsp[0].routinedecl)); }
#line 2002 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 53:
#line 287 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.routinepart) = new RoutinePart(); (yyval.routinepart)->pushBack((yyvsp[0].routinedecl)); }
#line 2008 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 54:
#line 289 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.routinepart) = new RoutinePart(); }
#line 2014 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 55:
#line 293 "/home/gster/CLionProjects/SPL/SPL.y"
                          { (yyval.routinedecl) = new Function((yyvsp[-3].functionhead), (yyvsp[-1].routine)); }
#line 2020 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 56:
#line 297 "/home/gster/CLionProjects/SPL/SPL.y"
                          { (yyval.functionhead) = new FunctionHead(*(yyvsp[-3].string), (yyvsp[-2].parameters), (yyvsp[0].simpletype)); }
#line 2026 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 57:
#line 301 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.routinedecl) = new Procedure((yyvsp[-3].procedurehead), (yyvsp[-1].routine)); }
#line 2032 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 58:
#line 305 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.procedurehead) = new ProcedureHead(*(yyvsp[-1].string), (yyvsp[0].parameters)); }
#line 2038 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 59:
#line 309 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.parameters) = (yyvsp[-1].paradecllist); }
#line 2044 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 60:
#line 311 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.parameters) = new ParaDeclList(); }
#line 2050 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 61:
#line 315 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.paradecllist) = (yyvsp[-2].paradecllist); (yyval.paradecllist)->pushBack((yyvsp[0].paratypelist)); }
#line 2056 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 62:
#line 317 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.paradecllist) = new ParaDeclList(); (yyval.paradecllist)->pushBack((yyvsp[0].paratypelist)); }
#line 2062 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 63:
#line 321 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.paratypelist) = new ParaTypeList((yyvsp[-2].varparalist), (yyvsp[0].simpletype)); }
#line 2068 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 64:
#line 325 "/home/gster/CLionProjects/SPL/SPL.y"
                          { (yyval.varparalist) = (yyvsp[0].namelist); }
#line 2074 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 65:
#line 327 "/home/gster/CLionProjects/SPL/SPL.y"
                          { (yyval.varparalist) = (yyvsp[0].namelist); (yyval.varparalist)->ref = true;}
#line 2080 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 66:
#line 331 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.routinebody) = (yyvsp[0].compoundstmt); }
#line 2086 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 67:
#line 335 "/home/gster/CLionProjects/SPL/SPL.y"
                          { (yyval.compoundstmt) = (yyvsp[-1].stmtlist); }
#line 2092 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 68:
#line 339 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.stmtlist) = (yyvsp[-2].stmtlist); (yyval.stmtlist)->pushBack((yyvsp[-1].stmt)); }
#line 2098 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 69:
#line 341 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.stmtlist) = new StmtList(); }
#line 2104 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 70:
#line 345 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.stmt) = (yyvsp[0].stmt); (yyval.stmt)->addLabel(*(yyvsp[-2].string)); }
#line 2110 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 71:
#line 347 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2116 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 72:
#line 351 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].assignstmt); }
#line 2122 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 73:
#line 353 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].procstmt); }
#line 2128 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 74:
#line 355 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].compoundstmt); }
#line 2134 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 75:
#line 357 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].ifstmt); }
#line 2140 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 76:
#line 359 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].repeatstmt); }
#line 2146 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 77:
#line 361 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].whilestmt); }
#line 2152 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 78:
#line 363 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].forstmt); }
#line 2158 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 79:
#line 365 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].casestmt); }
#line 2164 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 80:
#line 367 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].gotostmt); }
#line 2170 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 81:
#line 371 "/home/gster/CLionProjects/SPL/SPL.y"
                        { (yyval.assignstmt) = new AssignStmt((yyvsp[-2].leftvalue), (yyvsp[0].expression)); }
#line 2176 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 82:
#line 375 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.leftvalue) = new NameLeftValue(*(yyvsp[0].string)); }
#line 2182 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 83:
#line 377 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.leftvalue) = new IndexLeftValue(*(yyvsp[-3].string), (yyvsp[-1].expression)); }
#line 2188 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 84:
#line 379 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.leftvalue) = new MemberLeftValue(*(yyvsp[-2].string), *(yyvsp[0].string)); }
#line 2194 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 85:
#line 383 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.procstmt) = new NameProcStmt(*(yyvsp[0].string)); }
#line 2200 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 86:
#line 385 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.procstmt) = new CallProcStmt(*(yyvsp[-3].string), (yyvsp[-1].argslist)); }
#line 2206 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 87:
#line 387 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.procstmt) = new SysProcStmt((yyvsp[0].sysproc)); }
#line 2212 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 88:
#line 389 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.procstmt) = new SysCallProcStmt((yyvsp[-3].sysproc), (yyvsp[-1].expressionlist)); }
#line 2218 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 89:
#line 391 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.procstmt) = new ReadProcStmt((yyvsp[-1].factor)); }
#line 2224 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 90:
#line 395 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysproc) = new SysProc("write"); }
#line 2230 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 91:
#line 397 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysproc) = new SysProc("writeln"); }
#line 2236 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 92:
#line 401 "/home/gster/CLionProjects/SPL/SPL.y"
                { (yyval.ifstmt) = new IfStmt((yyvsp[-3].expression), (yyvsp[-1].stmt), (yyvsp[0].elseclause)); }
#line 2242 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 93:
#line 405 "/home/gster/CLionProjects/SPL/SPL.y"
                        { (yyval.elseclause) = new ElseClause((yyvsp[0].stmt)); }
#line 2248 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 94:
#line 407 "/home/gster/CLionProjects/SPL/SPL.y"
                        { (yyval.elseclause) = new ElseClause(); }
#line 2254 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 95:
#line 411 "/home/gster/CLionProjects/SPL/SPL.y"
                        { (yyval.repeatstmt) = new RepeatStmt((yyvsp[-2].stmtlist), (yyvsp[0].expression)); }
#line 2260 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 96:
#line 415 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.whilestmt) = new WhileStmt((yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 2266 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 97:
#line 419 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.forstmt) = new ForStmt(*(yyvsp[-6].string), (yyvsp[-4].expression), (yyvsp[-3].direction), (yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 2272 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 98:
#line 423 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.direction) = new Direction("to"); }
#line 2278 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 99:
#line 425 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.direction) = new Direction("downto"); }
#line 2284 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 100:
#line 429 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.casestmt) = new CaseStmt((yyvsp[-3].expression), (yyvsp[-1].caseexprlist)); }
#line 2290 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 101:
#line 433 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.caseexprlist) = (yyvsp[-1].caseexprlist); (yyval.caseexprlist)->pushBack((yyvsp[0].caseexpr)); }
#line 2296 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 102:
#line 435 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.caseexprlist) = new CaseExprList(); (yyval.caseexprlist)->pushBack((yyvsp[0].caseexpr)); }
#line 2302 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 103:
#line 439 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.caseexpr) = new ConstValueCaseExpr((yyvsp[-3].constvalue), (yyvsp[-1].stmt)); }
#line 2308 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 104:
#line 441 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.caseexpr) = new NameCaseExpr(*(yyvsp[-3].string), (yyvsp[-1].stmt)); }
#line 2314 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 105:
#line 445 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.gotostmt) = new GotoStmt(*(yyvsp[0].string)); }
#line 2320 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 106:
#line 449 "/home/gster/CLionProjects/SPL/SPL.y"
                                { (yyval.expressionlist) = (yyvsp[-2].expressionlist); (yyval.expressionlist)->pushBack((yyvsp[0].expression)); }
#line 2326 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 107:
#line 451 "/home/gster/CLionProjects/SPL/SPL.y"
                                { (yyval.expressionlist) = new ExpressionList(); (yyval.expressionlist)->pushBack((yyvsp[0].expression)); }
#line 2332 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 108:
#line 455 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.expression) = new CalcExpr((yyvsp[-2].expression), (yyvsp[0].expr), ">="); }
#line 2338 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 109:
#line 457 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.expression) = new CalcExpr((yyvsp[-2].expression), (yyvsp[0].expr), ">"); }
#line 2344 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 110:
#line 459 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.expression) = new CalcExpr((yyvsp[-2].expression), (yyvsp[0].expr), "<="); }
#line 2350 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 111:
#line 461 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.expression) = new CalcExpr((yyvsp[-2].expression), (yyvsp[0].expr), "<"); }
#line 2356 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 112:
#line 463 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.expression) = new CalcExpr((yyvsp[-2].expression), (yyvsp[0].expr), "="); }
#line 2362 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 113:
#line 465 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.expression) = new CalcExpr((yyvsp[-2].expression), (yyvsp[0].expr), "<>"); }
#line 2368 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 114:
#line 467 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.expression) = (yyvsp[0].expr); }
#line 2374 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 115:
#line 471 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.expr) = new CalcExpr((yyvsp[-2].expr), (yyvsp[0].term), "+"); }
#line 2380 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 116:
#line 473 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.expr) = new CalcExpr((yyvsp[-2].expr), (yyvsp[0].term), "-"); }
#line 2386 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 117:
#line 475 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.expr) = new BinaryExpr((yyvsp[-2].expr), (yyvsp[0].term), "or"); }
#line 2392 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 118:
#line 477 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.expr) = (yyvsp[0].term); }
#line 2398 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 119:
#line 481 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.term) = new CalcExpr((yyvsp[-2].term), (yyvsp[0].factor), "*"); }
#line 2404 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 120:
#line 483 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.term) = new CalcExpr((yyvsp[-2].term), (yyvsp[0].factor), "/"); }
#line 2410 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 121:
#line 485 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.term) = new CalcExpr((yyvsp[-2].term), (yyvsp[0].factor), "mod"); }
#line 2416 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 122:
#line 487 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.term) = new BinaryExpr((yyvsp[-2].term), (yyvsp[0].factor), "and"); }
#line 2422 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 123:
#line 489 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.term) = (yyvsp[0].factor); }
#line 2428 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 124:
#line 493 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = new NameFactor(*(yyvsp[0].string)); }
#line 2434 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 125:
#line 495 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = new CallFactor(*(yyvsp[-3].string), (yyvsp[-1].argslist)); }
#line 2440 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 126:
#line 497 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = new SysFuncFactor((yyvsp[0].sysfunc)); }
#line 2446 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 127:
#line 499 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = new SysFuncCallFactor((yyvsp[-3].sysfunc), (yyvsp[-1].argslist)); }
#line 2452 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 128:
#line 501 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = new ConstFactor((yyvsp[0].constvalue)); }
#line 2458 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 129:
#line 503 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = new ParenthesesFactor((yyvsp[-1].expression)); }
#line 2464 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 130:
#line 505 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = (yyvsp[0].factor); (yyval.factor)->setNot(); }
#line 2470 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 131:
#line 507 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = (yyvsp[0].factor); (yyval.factor)->setNeg(); }
#line 2476 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 132:
#line 509 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = new IndexFactor(*(yyvsp[-3].string), (yyvsp[-1].expression)); }
#line 2482 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 133:
#line 511 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = new MemberFactor(*(yyvsp[-2].string), *(yyvsp[0].string)); }
#line 2488 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 134:
#line 515 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysfunc) = new SysFunc("abs"); }
#line 2494 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 135:
#line 517 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysfunc) = new SysFunc("chr"); }
#line 2500 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 136:
#line 519 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysfunc) = new SysFunc("odd"); }
#line 2506 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 137:
#line 521 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysfunc) = new SysFunc("ord"); }
#line 2512 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 138:
#line 523 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysfunc) = new SysFunc("pred"); }
#line 2518 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 139:
#line 525 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysfunc) = new SysFunc("sqr"); }
#line 2524 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 140:
#line 527 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysfunc) = new SysFunc("sqrt"); }
#line 2530 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 141:
#line 529 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysfunc) = new SysFunc("succ"); }
#line 2536 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 142:
#line 533 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.argslist) = (yyvsp[-2].argslist); (yyval.argslist)->pushBack((yyvsp[0].expression)); }
#line 2542 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 143:
#line 535 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.argslist) = new ArgsList(); (yyval.argslist)->pushBack((yyvsp[0].expression)); }
#line 2548 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;


#line 2552 "/home/gster/CLionProjects/SPL/parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
