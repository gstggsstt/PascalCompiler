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
#define YYLAST   366

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  275

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
     310,   314,   316,   320,   322,   326,   330,   334,   338,   342,
     345,   348,   350,   354,   356,   358,   360,   362,   364,   366,
     368,   370,   374,   378,   380,   382,   386,   388,   390,   392,
     394,   398,   400,   404,   408,   411,   414,   418,   422,   426,
     428,   432,   436,   438,   442,   444,   448,   452,   454,   458,
     460,   462,   464,   466,   468,   470,   474,   476,   478,   480,
     484,   486,   488,   490,   492,   496,   498,   500,   502,   504,
     506,   508,   510,   512,   514,   518,   520,   522,   524,   526,
     528,   530,   532,   536,   538,   541
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
  "val_para_list", "routine_body", "compound_stmt", "stmt_list", "stmt",
  "non_label_stmt", "assign_stmt", "left_value", "proc_stmt", "sys_proc",
  "if_stmt", "else_clause", "repeat_stmt", "while_stmt", "for_stmt",
  "direction", "case_stmt", "case_expr_list", "case_expr", "goto_stmt",
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

#define YYPACT_NINF (-189)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -49,   -60,    30,  -189,    38,  -189,    43,    40,    52,  -189,
    -189,  -189,  -189,  -189,    45,    54,   182,    79,    56,    60,
      61,  -189,  -189,     6,  -189,    69,    73,     6,  -189,     6,
     143,   145,   259,  -189,   162,  -189,  -189,   144,  -189,   171,
    -189,  -189,  -189,  -189,  -189,  -189,    55,   165,   167,    60,
    -189,   104,    16,     6,     6,     6,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
     174,  -189,  -189,   140,    11,     4,  -189,   181,   172,  -189,
      32,   202,   294,     6,   240,     6,     6,   125,  -189,     6,
       6,   190,    55,    95,  -189,  -189,    53,   104,  -189,   128,
     133,    16,  -189,   199,  -189,   201,   308,  -189,  -189,     6,
       6,   139,     6,     6,     6,     6,     6,     6,   -12,     6,
       6,     6,     6,     6,     6,     6,     6,     6,   228,     6,
     228,   210,  -189,   323,    99,   315,  -189,   323,   102,   323,
    -189,   206,   104,    55,  -189,  -189,  -189,  -189,   213,   104,
     209,   226,   212,  -189,  -189,  -189,  -189,   168,    95,  -189,
     236,   236,  -189,  -189,  -189,  -189,  -189,   113,   335,  -189,
      11,    11,    11,    11,    11,    11,   230,   231,   159,  -189,
       4,     4,     4,  -189,  -189,  -189,  -189,   127,   126,   195,
     323,  -189,  -189,  -189,     6,  -189,  -189,     6,  -189,   129,
     237,   153,   -29,  -189,   103,   176,    55,  -189,  -189,   243,
       7,   246,  -189,   250,    40,   252,  -189,  -189,   228,   228,
    -189,  -189,  -189,  -189,  -189,     6,   228,  -189,   323,   323,
    -189,    81,   254,  -189,  -189,    95,  -189,  -189,  -189,  -189,
     104,   258,    21,  -189,   264,   267,   153,  -189,  -189,  -189,
     271,   277,   301,  -189,    55,  -189,   232,   279,   258,  -189,
      19,   153,   153,  -189,  -189,  -189,   228,  -189,    95,  -189,
    -189,  -189,  -189,  -189,  -189
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     7,     0,     1,     0,     0,     9,     3,
       2,    70,     4,    67,     0,    20,     0,     0,     8,     0,
      46,    91,    92,     0,    68,     0,     0,     0,    70,     0,
       0,     0,    86,    75,     0,    72,    73,     0,    74,    88,
      76,    77,    78,    79,    80,    81,     0,     0,     0,    19,
      22,     0,    54,     0,     0,     0,    16,    17,    18,   135,
     136,   137,   138,   139,   140,   141,   142,    12,    13,    14,
     125,   129,    15,     0,   115,   119,   124,   127,     0,   106,
       0,     0,     0,     0,     0,   145,     0,     0,    69,     0,
       0,     0,     0,     0,    21,    44,     0,    45,    48,     0,
       0,     6,    52,     0,    53,     0,     0,   132,   131,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,    71,   144,     0,     0,    85,    82,     0,   108,
      11,     0,     0,     0,    34,    36,    37,    35,     0,     0,
      28,     0,     0,    24,    27,    25,    26,     0,     0,    47,
       0,     0,    50,    51,     7,     7,   130,     0,     0,   134,
     114,   109,   110,   111,   112,   113,     0,     0,     0,   103,
     116,   117,   118,   120,   121,   122,   123,     0,     0,    95,
      96,    97,    90,    87,     0,    84,    89,     0,    10,     0,
       0,     0,     0,    41,     0,     0,     0,    23,    43,     0,
       0,     0,    58,     0,     0,     0,   126,   133,     0,     0,
     101,   102,   128,   100,    99,     0,     0,    93,   143,   107,
      29,     0,     0,    39,    40,     0,    33,    30,    49,    60,
       0,    66,     0,    62,     0,     0,     0,    55,     5,    57,
       0,     0,     0,    94,     0,    31,     0,     0,    65,    59,
       0,     0,     0,    56,   105,   104,     0,    32,     0,    42,
      61,    63,    64,    98,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -189,  -189,  -189,  -189,   135,   289,  -189,  -189,  -189,   -46,
    -189,  -189,  -189,   245,  -150,  -188,  -189,  -189,  -189,  -189,
     105,  -139,  -189,  -189,   204,  -189,   203,  -189,   205,  -189,
     147,  -189,    51,  -189,  -189,    91,    -5,   300,  -124,   251,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,   173,  -189,  -189,   -22,   249,    85,   -33,  -189,
     -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,   213,   214,     8,    15,    18,    71,
      72,    20,    49,    50,   152,   153,   154,   155,   156,   202,
     203,    96,    52,    97,    98,   101,   102,   103,   104,   105,
     211,   242,   243,   244,   245,    12,    33,    16,    34,    35,
      36,    37,    38,    39,    40,   227,    41,    42,    43,   225,
      44,   178,   179,    45,   138,   133,    74,    75,    76,    77,
     134
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,    73,    13,   199,   189,    80,   191,    82,   209,    53,
     204,   239,     1,   232,     4,    56,    57,    58,   122,   123,
     124,   107,   108,   233,    54,   259,    55,   167,   119,   120,
       5,   106,   260,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,   187,    95,   141,   151,   125,     9,
     131,   112,    10,   113,   114,   115,   116,   117,   263,    67,
      68,    69,   176,   204,   135,   157,   158,   137,   139,   121,
      99,   241,   177,   271,   272,   240,   100,    67,    68,    69,
      70,    95,    56,    57,    58,   257,    11,   240,   168,   183,
     184,   185,   186,    95,   250,   251,   128,   200,   142,   254,
      14,   258,   253,   193,    46,   188,   196,   190,    56,    57,
      58,   194,   151,   143,   197,   157,   235,   216,   274,    17,
      19,   241,    56,    57,    58,   194,    67,    68,    69,    51,
      47,   222,   177,   230,    48,   144,   145,   146,   147,   194,
     148,   157,   273,    78,    79,   112,    83,   113,   114,   115,
     116,   117,    67,    68,    69,   151,   142,   149,    84,   112,
     237,   113,   114,   115,   116,   117,    67,    68,    69,   150,
      89,   143,   228,    88,    90,   229,   223,   109,    95,   110,
      56,    57,    58,   111,   126,   255,    56,    57,    58,   151,
      92,   224,    93,   144,   145,   146,   147,   118,   127,   136,
     151,   140,   160,   252,   180,   181,   182,   161,   267,    13,
     164,   220,   165,   169,   192,   151,   151,   198,   201,   205,
      21,    22,   151,   207,    67,    68,    69,   150,    11,    23,
      67,    68,    69,   176,    24,    25,   206,    26,    27,   210,
      21,    22,   208,   218,   219,    28,   226,   231,    11,    23,
     236,    29,    30,    31,   238,    25,    32,    26,    27,   246,
     256,   247,    85,   249,    86,    28,    21,    22,    87,   129,
     157,    29,    30,    31,    11,    23,    32,   261,    21,    22,
     262,    25,   264,    26,    27,   -83,    11,    23,   265,   268,
     269,    28,     7,    25,    94,    26,    27,    29,    30,    31,
     215,   159,    32,    28,   162,   248,   163,   234,   212,    29,
      30,   270,   166,   112,    32,   113,   114,   115,   116,   117,
     112,   195,   113,   114,   115,   116,   117,   112,    81,   113,
     114,   115,   116,   117,   112,   132,   113,   114,   115,   116,
     117,   217,   112,   130,   113,   114,   115,   116,   117,     0,
     266,   221,     0,     0,   112,     0,   113,   114,   115,   116,
     117,   170,   171,   172,   173,   174,   175
};

static const yytype_int16 yycheck[] =
{
      46,    23,     7,   142,   128,    27,   130,    29,   158,     3,
     149,     4,    61,   201,    74,    27,    28,    29,    14,    15,
      16,    54,    55,    52,    18,     4,    20,   109,    17,    18,
       0,    53,    11,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,   126,    74,    92,    93,    44,    11,
      83,    19,     9,    21,    22,    23,    24,    25,   246,    71,
      72,    73,    74,   202,    86,    12,    13,    89,    90,    58,
      54,   210,   118,   261,   262,    68,    60,    71,    72,    73,
      74,    74,    27,    28,    29,   235,    46,    68,   110,   122,
     123,   124,   125,    74,   218,   219,    64,   143,     3,    18,
      48,   240,   226,     4,    25,   127,     4,   129,    27,    28,
      29,    12,   158,    18,    12,    12,    13,     4,   268,    74,
      66,   260,    27,    28,    29,    12,    71,    72,    73,    68,
      74,     4,   178,     4,    74,    40,    41,    42,    43,    12,
      45,    12,   266,    74,    71,    19,     3,    21,    22,    23,
      24,    25,    71,    72,    73,   201,     3,    62,    13,    19,
     206,    21,    22,    23,    24,    25,    71,    72,    73,    74,
      26,    18,   194,    11,     3,   197,    50,     3,    74,     5,
      27,    28,    29,     9,     3,   231,    27,    28,    29,   235,
      25,    65,    25,    40,    41,    42,    43,    57,    26,    74,
     246,    11,    74,   225,   119,   120,   121,    74,   254,   214,
      11,    52,    11,    74,     4,   261,   262,    11,     5,    10,
      38,    39,   268,    11,    71,    72,    73,    74,    46,    47,
      71,    72,    73,    74,    52,    53,    10,    55,    56,     3,
      38,    39,    74,    13,    13,    63,    51,    10,    46,    47,
      74,    69,    70,    71,    11,    53,    74,    55,    56,    13,
       6,    11,     3,    11,     5,    63,    38,    39,     9,    67,
      12,    69,    70,    71,    46,    47,    74,    13,    38,    39,
      13,    53,    11,    55,    56,    26,    46,    47,    11,    57,
      11,    63,     3,    53,    49,    55,    56,    69,    70,    71,
     165,    97,    74,    63,   101,   214,   101,   202,   161,    69,
      70,   260,     4,    19,    74,    21,    22,    23,    24,    25,
      19,     6,    21,    22,    23,    24,    25,    19,    28,    21,
      22,    23,    24,    25,    19,    84,    21,    22,    23,    24,
      25,     6,    19,    49,    21,    22,    23,    24,    25,    -1,
      49,   178,    -1,    -1,    19,    -1,    21,    22,    23,    24,
      25,   112,   113,   114,   115,   116,   117
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    76,    77,    74,     0,    78,    80,    81,    11,
       9,    46,   110,   111,    48,    82,   112,    74,    83,    66,
      86,    38,    39,    47,    52,    53,    55,    56,    63,    69,
      70,    71,    74,   111,   113,   114,   115,   116,   117,   118,
     119,   121,   122,   123,   125,   128,    25,    74,    74,    87,
      88,    68,    97,     3,    18,    20,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    71,    72,    73,
      74,    84,    85,   130,   131,   132,   133,   134,    74,    71,
     130,   112,   130,     3,    13,     3,     5,     9,    11,    26,
       3,    84,    25,    25,    88,    74,    96,    98,    99,    54,
      60,   100,   101,   102,   103,   104,   130,   133,   133,     3,
       5,     9,    19,    21,    22,    23,    24,    25,    57,    17,
      18,    58,    14,    15,    16,    44,     3,    26,    64,    67,
      49,   133,   114,   130,   135,   130,    74,   130,   129,   130,
      11,    84,     3,    18,    40,    41,    42,    43,    45,    62,
      74,    84,    89,    90,    91,    92,    93,    12,    13,    99,
      74,    74,   101,   103,    11,    11,     4,   135,   130,    74,
     131,   131,   131,   131,   131,   131,    74,    84,   126,   127,
     132,   132,   132,   133,   133,   133,   133,   135,   130,   113,
     130,   113,     4,     4,    12,     6,     4,    12,    11,    96,
      84,     5,    94,    95,    96,    10,    10,    11,    74,    89,
       3,   105,   105,    79,    80,    79,     4,     6,    13,    13,
      52,   127,     4,    50,    65,   124,    51,   120,   130,   130,
       4,    10,    90,    52,    95,    13,    74,    84,    11,     4,
      68,    96,   106,   107,   108,   109,    13,    11,   110,    11,
     113,   113,   130,   113,    18,    84,     6,    89,    96,     4,
      11,    13,    13,    90,    11,    11,    49,    84,    57,    11,
     107,    90,    90,   113,    89
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
     105,   106,   106,   107,   107,   108,   109,   110,   111,   112,
     112,   113,   113,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   115,   116,   116,   116,   117,   117,   117,   117,
     117,   118,   118,   119,   120,   120,   121,   122,   123,   124,
     124,   125,   126,   126,   127,   127,   128,   129,   129,   130,
     130,   130,   130,   130,   130,   130,   131,   131,   131,   131,
     132,   132,   132,   132,   132,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   134,   134,   134,   134,   134,
     134,   134,   134,   135,   135,   135
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
       2,     3,     1,     3,     3,     2,     1,     1,     3,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     4,     3,     1,     4,     1,     4,
       4,     1,     1,     5,     2,     0,     4,     4,     8,     1,
       1,     5,     2,     1,     4,     4,     2,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     1,     4,     1,     4,     1,
       3,     2,     2,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     0
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
#line 1700 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 3:
#line 170 "/home/gster/CLionProjects/SPL/SPL.y"
                                 { (yyval.programhead) = new ProgramHead(*(yyvsp[-1].string)); }
#line 1706 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 4:
#line 173 "/home/gster/CLionProjects/SPL/SPL.y"
                                    { (yyval.routine) = new Routine((yyvsp[-1].routinehead), (yyvsp[0].routinebody)); }
#line 1712 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 5:
#line 176 "/home/gster/CLionProjects/SPL/SPL.y"
                                        { (yyval.routine) = new Routine((yyvsp[-1].routinehead), (yyvsp[0].routinebody)); }
#line 1718 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 6:
#line 180 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.routinehead) = new RoutineHead((yyvsp[-4].labelpart), (yyvsp[-3].constpart), (yyvsp[-2].typepart), (yyvsp[-1].varpart), (yyvsp[0].routinepart)); }
#line 1724 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 7:
#line 183 "/home/gster/CLionProjects/SPL/SPL.y"
             { (yyval.labelpart) = new LabelPart(); }
#line 1730 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 8:
#line 185 "/home/gster/CLionProjects/SPL/SPL.y"
                                   { (yyval.constpart) = new ConstPart((yyvsp[0].constexprlist)); }
#line 1736 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 9:
#line 186 "/home/gster/CLionProjects/SPL/SPL.y"
                     { (yyval.constpart) = new ConstPart(new ConstExprList()); }
#line 1742 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 10:
#line 190 "/home/gster/CLionProjects/SPL/SPL.y"
                                { (yyval.constexprlist) = (yyvsp[-4].constexprlist); (yyval.constexprlist)->pushBack(new ConstValueDecl(*(yyvsp[-3].string), (yyvsp[-1].constvalue))); }
#line 1748 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 11:
#line 192 "/home/gster/CLionProjects/SPL/SPL.y"
                                { (yyval.constexprlist) = new ConstExprList(); (yyval.constexprlist)->pushBack(new ConstValueDecl(*(yyvsp[-3].string), (yyvsp[-1].constvalue))); }
#line 1754 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 12:
#line 195 "/home/gster/CLionProjects/SPL/SPL.y"
                      { (yyval.constvalue) = new ConstIntValue(*(yyvsp[0].string)); }
#line 1760 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 13:
#line 196 "/home/gster/CLionProjects/SPL/SPL.y"
                                  { (yyval.constvalue) = new ConstRealValue(*(yyvsp[0].string)); }
#line 1766 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 14:
#line 197 "/home/gster/CLionProjects/SPL/SPL.y"
                                  { (yyval.constvalue) = new ConstCharValue(*(yyvsp[0].string)); }
#line 1772 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 15:
#line 198 "/home/gster/CLionProjects/SPL/SPL.y"
                                  { (yyval.constvalue) = (yyvsp[0].constvalue); }
#line 1778 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 16:
#line 201 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.constvalue) = new ConstIntValue("0"); }
#line 1784 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 17:
#line 202 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.constvalue) = new ConstIntValue("2147483647"); }
#line 1790 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 18:
#line 203 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.constvalue) = new ConstIntValue("1"); }
#line 1796 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 19:
#line 206 "/home/gster/CLionProjects/SPL/SPL.y"
                                 { (yyval.typepart) = (yyvsp[0].typedecllist); }
#line 1802 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 20:
#line 207 "/home/gster/CLionProjects/SPL/SPL.y"
                    { (yyval.typepart) = new TypePart(); }
#line 1808 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 21:
#line 211 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.typedecllist) = (yyvsp[-1].typedecllist); (yyval.typedecllist)->pushBack((yyvsp[0].typedefinition)); }
#line 1814 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 22:
#line 213 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.typedecllist) = new TypeDeclList(); (yyval.typedecllist)->pushBack((yyvsp[0].typedefinition)); }
#line 1820 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 23:
#line 217 "/home/gster/CLionProjects/SPL/SPL.y"
                                { (yyval.typedefinition) = new TypeDefinition(*(yyvsp[-3].string), (yyvsp[-1].typedecl)); }
#line 1826 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 24:
#line 220 "/home/gster/CLionProjects/SPL/SPL.y"
                             { (yyval.typedecl) = (yyvsp[0].simpletype); }
#line 1832 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 25:
#line 221 "/home/gster/CLionProjects/SPL/SPL.y"
                                     { (yyval.typedecl) = (yyvsp[0].arraytype); }
#line 1838 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 26:
#line 222 "/home/gster/CLionProjects/SPL/SPL.y"
                                     { (yyval.typedecl) = (yyvsp[0].recordtype); }
#line 1844 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 27:
#line 225 "/home/gster/CLionProjects/SPL/SPL.y"
                            { (yyval.simpletype) = (yyvsp[0].systype); }
#line 1850 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 28:
#line 226 "/home/gster/CLionProjects/SPL/SPL.y"
                                         { (yyval.simpletype) = new CustomType(*(yyvsp[0].string), std::string("Custom")); }
#line 1856 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 29:
#line 227 "/home/gster/CLionProjects/SPL/SPL.y"
                                                   { (yyval.simpletype) = new EnumType((yyvsp[-1].namelist), "Enum"); }
#line 1862 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 30:
#line 228 "/home/gster/CLionProjects/SPL/SPL.y"
                                                                  { (yyval.simpletype) = new RangeType((yyvsp[-2].constvalue), (yyvsp[0].constvalue), "Range"); }
#line 1868 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 31:
#line 229 "/home/gster/CLionProjects/SPL/SPL.y"
                                                                        { (yyval.simpletype) = new RangeType((yyvsp[-2].constvalue)->setNeg(), (yyvsp[0].constvalue), "Range"); }
#line 1874 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 32:
#line 230 "/home/gster/CLionProjects/SPL/SPL.y"
                                                                              { (yyval.simpletype) = new RangeType((yyvsp[-3].constvalue)->setNeg(), (yyvsp[0].constvalue)->setNeg(), "Range"); }
#line 1880 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 33:
#line 231 "/home/gster/CLionProjects/SPL/SPL.y"
                                                    { (yyval.simpletype) = new NamedRangeType(*(yyvsp[-2].string), *(yyvsp[0].string), "NamedRange"); }
#line 1886 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 34:
#line 234 "/home/gster/CLionProjects/SPL/SPL.y"
                     { (yyval.systype) = new SysType("bool"); }
#line 1892 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 35:
#line 235 "/home/gster/CLionProjects/SPL/SPL.y"
                             { (yyval.systype) = new SysType("real"); }
#line 1898 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 36:
#line 236 "/home/gster/CLionProjects/SPL/SPL.y"
                             { (yyval.systype) = new SysType("char"); }
#line 1904 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 37:
#line 237 "/home/gster/CLionProjects/SPL/SPL.y"
                             { (yyval.systype) = new SysType("int"); }
#line 1910 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 38:
#line 241 "/home/gster/CLionProjects/SPL/SPL.y"
                                { (yyval.arraytype) = new ArrayType((yyvsp[-3].simpletype), (yyvsp[0].typedecl)); }
#line 1916 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 39:
#line 245 "/home/gster/CLionProjects/SPL/SPL.y"
                                 { (yyval.recordtype) = new RecordType((yyvsp[-1].fielddecllist)); }
#line 1922 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 40:
#line 249 "/home/gster/CLionProjects/SPL/SPL.y"
                                { (yyval.fielddecllist) = (yyvsp[-1].fielddecllist); (yyval.fielddecllist)->pushBack((yyvsp[0].fielddecl)); }
#line 1928 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 41:
#line 251 "/home/gster/CLionProjects/SPL/SPL.y"
                                { (yyval.fielddecllist) = new FieldDeclList(); (yyval.fielddecllist)->pushBack((yyvsp[0].fielddecl)); }
#line 1934 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 42:
#line 255 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.fielddecl) = new FieldDecl((yyvsp[-3].namelist), (yyvsp[-1].typedecl)); }
#line 1940 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 43:
#line 259 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.namelist) = (yyvsp[-2].namelist); (yyval.namelist)->pushBack(*(yyvsp[0].string)); }
#line 1946 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 44:
#line 261 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.namelist) = new NameList(); (yyval.namelist)->pushBack(*(yyvsp[0].string)); }
#line 1952 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 45:
#line 265 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.varpart) = (yyvsp[0].vardecllist); }
#line 1958 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 46:
#line 267 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.varpart) = new VarDeclList(); }
#line 1964 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 47:
#line 271 "/home/gster/CLionProjects/SPL/SPL.y"
                          { (yyval.vardecllist) = (yyvsp[-1].vardecllist); (yyval.vardecllist)->pushBack((yyvsp[0].vardecl)); }
#line 1970 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 48:
#line 273 "/home/gster/CLionProjects/SPL/SPL.y"
                          { (yyval.vardecllist) = new VarDeclList(); (yyval.vardecllist)->pushBack((yyvsp[0].vardecl)); }
#line 1976 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 49:
#line 277 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.vardecl) = new VarDecl((yyvsp[-3].namelist), (yyvsp[-1].typedecl)); }
#line 1982 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 50:
#line 281 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.routinepart) = (yyvsp[-1].routinepart); (yyval.routinepart)->pushBack((yyvsp[0].routinedecl)); }
#line 1988 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 51:
#line 283 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.routinepart) = (yyvsp[-1].routinepart); (yyval.routinepart)->pushBack((yyvsp[0].routinedecl)); }
#line 1994 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 52:
#line 285 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.routinepart) = new RoutinePart(); (yyval.routinepart)->pushBack((yyvsp[0].routinedecl)); }
#line 2000 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 53:
#line 287 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.routinepart) = new RoutinePart(); (yyval.routinepart)->pushBack((yyvsp[0].routinedecl)); }
#line 2006 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 54:
#line 289 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.routinepart) = new RoutinePart(); }
#line 2012 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 55:
#line 293 "/home/gster/CLionProjects/SPL/SPL.y"
                          { (yyval.routinedecl) = new Function((yyvsp[-3].functionhead), (yyvsp[-1].routine)); }
#line 2018 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 56:
#line 297 "/home/gster/CLionProjects/SPL/SPL.y"
                          { (yyval.functionhead) = new FunctionHead(*(yyvsp[-3].string), (yyvsp[-2].parameters), (yyvsp[0].simpletype)); }
#line 2024 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 57:
#line 301 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.routinedecl) = new Procedure((yyvsp[-3].procedurehead), (yyvsp[-1].routine)); }
#line 2030 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 58:
#line 305 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.procedurehead) = new ProcedureHead(*(yyvsp[-1].string), (yyvsp[0].parameters)); }
#line 2036 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 59:
#line 309 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.parameters) = (yyvsp[-1].paradecllist); }
#line 2042 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 60:
#line 311 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.parameters) = new ParaDeclList(); }
#line 2048 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 61:
#line 315 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.paradecllist) = (yyvsp[-2].paradecllist); (yyval.paradecllist)->pushBack((yyvsp[0].paratypelist)); }
#line 2054 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 62:
#line 317 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.paradecllist) = new ParaDeclList(); (yyval.paradecllist)->pushBack((yyvsp[0].paratypelist)); }
#line 2060 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 63:
#line 321 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.paratypelist) = new ParaTypeList((yyvsp[-2].varparalist), (yyvsp[0].simpletype)); }
#line 2066 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 64:
#line 323 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.paratypelist) = new ParaTypeList((yyvsp[-2].varparalist), (yyvsp[0].simpletype)); }
#line 2072 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 65:
#line 327 "/home/gster/CLionProjects/SPL/SPL.y"
                          { (yyval.varparalist) = (yyvsp[0].namelist); (yyval.varparalist)->ref = true; }
#line 2078 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 66:
#line 331 "/home/gster/CLionProjects/SPL/SPL.y"
                { (yyval.varparalist) = (yyvsp[0].namelist); (yyval.varparalist)->ref = false; }
#line 2084 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 67:
#line 335 "/home/gster/CLionProjects/SPL/SPL.y"
                         { (yyval.routinebody) = (yyvsp[0].compoundstmt); }
#line 2090 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 68:
#line 339 "/home/gster/CLionProjects/SPL/SPL.y"
                          { (yyval.compoundstmt) = (yyvsp[-1].stmtlist); }
#line 2096 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 69:
#line 343 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.stmtlist) = (yyvsp[-2].stmtlist); (yyval.stmtlist)->pushBack((yyvsp[-1].stmt)); }
#line 2102 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 70:
#line 345 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.stmtlist) = new StmtList(); }
#line 2108 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 71:
#line 349 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.stmt) = (yyvsp[0].stmt); (yyval.stmt)->addLabel(*(yyvsp[-2].string)); }
#line 2114 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 72:
#line 351 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2120 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 73:
#line 355 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].assignstmt); }
#line 2126 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 74:
#line 357 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].procstmt); }
#line 2132 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 75:
#line 359 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].compoundstmt); }
#line 2138 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 76:
#line 361 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].ifstmt); }
#line 2144 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 77:
#line 363 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].repeatstmt); }
#line 2150 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 78:
#line 365 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].whilestmt); }
#line 2156 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 79:
#line 367 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].forstmt); }
#line 2162 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 80:
#line 369 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].casestmt); }
#line 2168 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 81:
#line 371 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.stmt) = (yyvsp[0].gotostmt); }
#line 2174 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 82:
#line 375 "/home/gster/CLionProjects/SPL/SPL.y"
                        { (yyval.assignstmt) = new AssignStmt((yyvsp[-2].leftvalue), (yyvsp[0].expression)); }
#line 2180 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 83:
#line 379 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.leftvalue) = new NameLeftValue(*(yyvsp[0].string)); }
#line 2186 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 84:
#line 381 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.leftvalue) = new IndexLeftValue(*(yyvsp[-3].string), (yyvsp[-1].expression)); }
#line 2192 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 85:
#line 383 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.leftvalue) = new MemberLeftValue(*(yyvsp[-2].string), *(yyvsp[0].string)); }
#line 2198 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 86:
#line 387 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.procstmt) = new NameProcStmt(*(yyvsp[0].string)); }
#line 2204 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 87:
#line 389 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.procstmt) = new CallProcStmt(*(yyvsp[-3].string), (yyvsp[-1].argslist)); }
#line 2210 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 88:
#line 391 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.procstmt) = new SysProcStmt((yyvsp[0].sysproc)); }
#line 2216 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 89:
#line 393 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.procstmt) = new SysCallProcStmt((yyvsp[-3].sysproc), (yyvsp[-1].expressionlist)); }
#line 2222 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 90:
#line 395 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.procstmt) = new ReadProcStmt((yyvsp[-1].factor)); }
#line 2228 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 91:
#line 399 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysproc) = new SysProc("write"); }
#line 2234 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 92:
#line 401 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysproc) = new SysProc("writeln"); }
#line 2240 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 93:
#line 405 "/home/gster/CLionProjects/SPL/SPL.y"
                { (yyval.ifstmt) = new IfStmt((yyvsp[-3].expression), (yyvsp[-1].stmt), (yyvsp[0].elseclause)); }
#line 2246 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 94:
#line 409 "/home/gster/CLionProjects/SPL/SPL.y"
                        { (yyval.elseclause) = new ElseClause((yyvsp[0].stmt)); }
#line 2252 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 95:
#line 411 "/home/gster/CLionProjects/SPL/SPL.y"
                        { (yyval.elseclause) = new ElseClause(); }
#line 2258 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 96:
#line 415 "/home/gster/CLionProjects/SPL/SPL.y"
                        { (yyval.repeatstmt) = new RepeatStmt((yyvsp[-2].stmtlist), (yyvsp[0].expression)); }
#line 2264 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 97:
#line 419 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.whilestmt) = new WhileStmt((yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 2270 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 98:
#line 423 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.forstmt) = new ForStmt(*(yyvsp[-6].string), (yyvsp[-4].expression), (yyvsp[-3].direction), (yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 2276 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 99:
#line 427 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.direction) = new Direction("to"); }
#line 2282 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 100:
#line 429 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.direction) = new Direction("downto"); }
#line 2288 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 101:
#line 433 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.casestmt) = new CaseStmt((yyvsp[-3].expression), (yyvsp[-1].caseexprlist)); }
#line 2294 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 102:
#line 437 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.caseexprlist) = (yyvsp[-1].caseexprlist); (yyval.caseexprlist)->pushBack((yyvsp[0].caseexpr)); }
#line 2300 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 103:
#line 439 "/home/gster/CLionProjects/SPL/SPL.y"
                           { (yyval.caseexprlist) = new CaseExprList(); (yyval.caseexprlist)->pushBack((yyvsp[0].caseexpr)); }
#line 2306 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 104:
#line 443 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.caseexpr) = new ConstValueCaseExpr((yyvsp[-3].constvalue), (yyvsp[-1].stmt)); }
#line 2312 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 105:
#line 445 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.caseexpr) = new NameCaseExpr(*(yyvsp[-3].string), (yyvsp[-1].stmt)); }
#line 2318 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 106:
#line 449 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.gotostmt) = new GotoStmt(*(yyvsp[0].string)); }
#line 2324 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 107:
#line 453 "/home/gster/CLionProjects/SPL/SPL.y"
                                { (yyval.expressionlist) = (yyvsp[-2].expressionlist); (yyval.expressionlist)->pushBack((yyvsp[0].expression)); }
#line 2330 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 108:
#line 455 "/home/gster/CLionProjects/SPL/SPL.y"
                                { (yyval.expressionlist) = new ExpressionList(); (yyval.expressionlist)->pushBack((yyvsp[0].expression)); }
#line 2336 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 109:
#line 459 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.expression) = new CalcExpr((yyvsp[-2].expression), (yyvsp[0].expr), ">="); }
#line 2342 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 110:
#line 461 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.expression) = new CalcExpr((yyvsp[-2].expression), (yyvsp[0].expr), ">"); }
#line 2348 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 111:
#line 463 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.expression) = new CalcExpr((yyvsp[-2].expression), (yyvsp[0].expr), "<="); }
#line 2354 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 112:
#line 465 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.expression) = new CalcExpr((yyvsp[-2].expression), (yyvsp[0].expr), "<"); }
#line 2360 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 113:
#line 467 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.expression) = new CalcExpr((yyvsp[-2].expression), (yyvsp[0].expr), "="); }
#line 2366 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 114:
#line 469 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.expression) = new CalcExpr((yyvsp[-2].expression), (yyvsp[0].expr), "<>"); }
#line 2372 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 115:
#line 471 "/home/gster/CLionProjects/SPL/SPL.y"
                   { (yyval.expression) = (yyvsp[0].expr); }
#line 2378 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 116:
#line 475 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.expr) = new CalcExpr((yyvsp[-2].expr), (yyvsp[0].term), "+"); }
#line 2384 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 117:
#line 477 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.expr) = new CalcExpr((yyvsp[-2].expr), (yyvsp[0].term), "-"); }
#line 2390 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 118:
#line 479 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.expr) = new BinaryExpr((yyvsp[-2].expr), (yyvsp[0].term), "or"); }
#line 2396 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 119:
#line 481 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.expr) = (yyvsp[0].term); }
#line 2402 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 120:
#line 485 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.term) = new CalcExpr((yyvsp[-2].term), (yyvsp[0].factor), "*"); }
#line 2408 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 121:
#line 487 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.term) = new CalcExpr((yyvsp[-2].term), (yyvsp[0].factor), "/"); }
#line 2414 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 122:
#line 489 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.term) = new CalcExpr((yyvsp[-2].term), (yyvsp[0].factor), "mod"); }
#line 2420 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 123:
#line 491 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.term) = new BinaryExpr((yyvsp[-2].term), (yyvsp[0].factor), "and"); }
#line 2426 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 124:
#line 493 "/home/gster/CLionProjects/SPL/SPL.y"
         { (yyval.term) = (yyvsp[0].factor); }
#line 2432 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 125:
#line 497 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = new NameFactor(*(yyvsp[0].string)); }
#line 2438 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 126:
#line 499 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = new CallFactor(*(yyvsp[-3].string), (yyvsp[-1].argslist)); }
#line 2444 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 127:
#line 501 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = new SysFuncFactor((yyvsp[0].sysfunc)); }
#line 2450 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 128:
#line 503 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = new SysFuncCallFactor((yyvsp[-3].sysfunc), (yyvsp[-1].argslist)); }
#line 2456 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 129:
#line 505 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = new ConstFactor((yyvsp[0].constvalue)); }
#line 2462 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 130:
#line 507 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = new ParenthesesFactor((yyvsp[-1].expression)); }
#line 2468 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 131:
#line 509 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = (yyvsp[0].factor); (yyval.factor)->setNot(); }
#line 2474 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 132:
#line 511 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = (yyvsp[0].factor); (yyval.factor)->setNeg(); }
#line 2480 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 133:
#line 513 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = new IndexFactor(*(yyvsp[-3].string), (yyvsp[-1].expression)); }
#line 2486 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 134:
#line 515 "/home/gster/CLionProjects/SPL/SPL.y"
           { (yyval.factor) = new MemberFactor(*(yyvsp[-2].string), *(yyvsp[0].string)); }
#line 2492 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 135:
#line 519 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysfunc) = new SysFunc("abs"); }
#line 2498 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 136:
#line 521 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysfunc) = new SysFunc("chr"); }
#line 2504 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 137:
#line 523 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysfunc) = new SysFunc("odd"); }
#line 2510 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 138:
#line 525 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysfunc) = new SysFunc("ord"); }
#line 2516 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 139:
#line 527 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysfunc) = new SysFunc("pred"); }
#line 2522 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 140:
#line 529 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysfunc) = new SysFunc("sqr"); }
#line 2528 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 141:
#line 531 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysfunc) = new SysFunc("sqrt"); }
#line 2534 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 142:
#line 533 "/home/gster/CLionProjects/SPL/SPL.y"
                 { (yyval.sysfunc) = new SysFunc("succ"); }
#line 2540 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 143:
#line 537 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.argslist) = (yyvsp[-2].argslist); (yyval.argslist)->pushBack((yyvsp[0].expression)); }
#line 2546 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 144:
#line 539 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.argslist) = new ArgsList(); (yyval.argslist)->pushBack((yyvsp[0].expression)); }
#line 2552 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;

  case 145:
#line 541 "/home/gster/CLionProjects/SPL/SPL.y"
                  { (yyval.argslist) = new ArgsList(); }
#line 2558 "/home/gster/CLionProjects/SPL/parser.cpp"
    break;


#line 2562 "/home/gster/CLionProjects/SPL/parser.cpp"

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
