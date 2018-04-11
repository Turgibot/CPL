/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "cpm.y" /* yacc.c:339  */

#include <malloc.h>
#include <stdio.h>
#include "shared.h"
#include "errors.h"
#include "symboles.h"
#include "code_gen.h"
extern int yylex();
extern int yyparse();
char *myout;

#line 78 "cpm.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "cpm.tab.h".  */
#ifndef YY_YY_CPM_TAB_H_INCLUDED
# define YY_YY_CPM_TAB_H_INCLUDED
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
    num = 258,
    addop = 259,
    mulop = 260,
    orop = 261,
    andop = 262,
    assignop = 263,
    relop = 264,
    toop = 265,
    sentence = 266,
    id = 267,
    CASE = 268,
    CONST = 269,
    DEFAULT = 270,
    READ = 271,
    ELSE = 272,
    FOR = 273,
    IF = 274,
    STEPOP = 275,
    INT = 276,
    PROGRAM = 277,
    LOOP = 278,
    PRINT = 279,
    _BEGIN = 280,
    STRING = 281,
    FLOAT = 282,
    SWITCH = 283,
    END = 284,
    VAR = 285,
    WHILE = 286,
    WHEN = 287,
    BREAK = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "cpm.y" /* yacc.c:355  */


	struct parserTree{
		char *code;
		int type;
		char *head;
		char* label;
	}Ptree;

	struct declTree{
		char *code;
		int type;
		int count;
		char *label;
	}Dtree;

	struct number{
		int type;
		union {
			int ival;
			float fval;
		}val;
	}num;

	char sign1;
	char sign2 [3];
	char sign3 [4];
	char *strVal;

#line 182 "cpm.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CPM_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 199 "cpm.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   356

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  303

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,     2,     2,     2,     2,     2,
      37,    38,     2,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    36,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    79,    86,    96,   116,   146,   167,   173,
     173,   182,   188,   194,   199,   199,   208,   259,   259,   264,
     270,   280,   287,   292,   320,   320,   325,   325,   330,   335,
     340,   345,   353,   369,   369,   374,   374,   379,   379,   384,
     397,   446,   446,   451,   451,   456,   456,   461,   461,   469,
     527,   527,   532,   532,   540,   571,   571,   580,   580,   589,
     589,   600,   600,   607,   629,   629,   638,   638,   645,   645,
     654,   683,   683,   696,   696,   709,   709,   722,   722,   735,
     778,   778,   793,   793,   808,   816,   822,   822,   830,   830,
     840,   850,   850,   859,   859,   868,   868,   881,   914,   927,
     937,   965,   965,   975,   975,   985,   985,   995,   995,  1005,
    1015,  1015,  1023,  1034,  1174,  1197,  1212,  1237,  1250,  1257,
    1377,  1429,  1452,  1503,  1525,  1542,  1549
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "num", "addop", "mulop", "orop", "andop",
  "assignop", "relop", "toop", "sentence", "id", "CASE", "CONST",
  "DEFAULT", "READ", "ELSE", "FOR", "IF", "STEPOP", "INT", "PROGRAM",
  "LOOP", "PRINT", "_BEGIN", "STRING", "FLOAT", "SWITCH", "END", "VAR",
  "WHILE", "WHEN", "BREAK", "','", "':'", "';'", "'('", "')'", "'{'",
  "'}'", "'!'", "$accept", "PROGRAM_BLOCK", "DECLARATIONS", "DECLARLIST",
  "DECL", "$@1", "TYPE", "$@2", "CDECL", "$@3", "STMTLIST", "STMT", "$@4",
  "$@5", "WRITE_STMT", "$@6", "$@7", "$@8", "READ_STMT", "$@9", "$@10",
  "$@11", "$@12", "ASSIGNMENT_STMT", "$@13", "$@14", "CONTROL_STMT",
  "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23",
  "$@24", "$@25", "$@26", "$@27", "STMT_BLOCK", "$@28", "$@29",
  "SWITCH_ROLL", "$@30", "$@31", "$@32", "CHOICE", "CASES", "$@33", "$@34",
  "$@35", "$@36", "$@37", "STEP", "BOOLEXPR", "BOOLTERM", "BOOLFACTOR",
  "EXPRESSION", "TERM", "FACTOR", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    44,    58,    59,    40,    41,   123,
     125,    33
};
# endif

#define YYPACT_NINF -209

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-209)))

#define YYTABLE_NINF -112

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -11,    66,   129,    38,  -209,    94,    88,   163,   167,  -209,
     127,   145,  -209,   141,   163,   145,  -209,   196,   163,  -209,
    -209,  -209,   109,   149,   117,  -209,   148,    18,   126,   147,
     156,   162,    15,   165,  -209,   168,  -209,  -209,  -209,  -209,
    -209,  -209,  -209,   177,  -209,  -209,  -209,  -209,  -209,   198,
     190,    70,   195,   208,   199,   209,    12,   212,   204,   220,
    -209,   106,     9,   222,    17,   229,    16,  -209,   233,   226,
      93,  -209,   203,  -209,    93,    56,   237,  -209,   207,   247,
     238,    68,   217,   199,  -209,   218,    74,   250,  -209,    75,
     216,   252,   251,    93,   230,    21,  -209,  -209,  -209,   234,
       9,  -209,    84,    30,  -209,  -209,   128,   235,   239,    58,
    -209,   265,    32,  -209,    93,  -209,    93,   240,   272,   241,
     242,  -209,    93,    30,   277,   245,   244,    30,    30,   246,
     282,    30,    93,   246,   281,   278,    59,   253,  -209,    29,
     248,   287,   254,   255,   256,   289,    89,  -209,  -209,   280,
     290,  -209,  -209,  -209,  -209,  -209,   237,  -209,  -209,   295,
     261,   262,   263,    85,    30,    30,   246,   264,   250,   283,
     300,   246,  -209,   299,   288,   294,   303,   271,  -209,   273,
    -209,  -209,   160,   307,   274,   275,   256,  -209,   256,   256,
    -209,   280,  -209,  -209,  -209,  -209,   298,   310,   113,   118,
     301,  -209,   246,  -209,   302,   246,   309,   305,  -209,  -209,
    -209,  -209,   193,    63,   276,   160,   160,   160,  -209,  -209,
    -209,  -209,   312,   279,   298,   298,   298,   246,  -209,   246,
    -209,   304,   318,  -209,    65,  -209,  -209,  -209,   285,   286,
     291,   311,   246,   321,   292,   296,   297,  -209,  -209,   324,
     308,   306,  -209,  -209,  -209,   146,  -209,  -209,  -209,   325,
    -209,   246,   246,   246,   246,   313,   329,  -209,  -209,    92,
     164,   330,  -209,  -209,  -209,  -209,   256,   335,   314,   210,
     228,  -209,    36,  -209,  -209,   246,   256,   317,   319,   320,
    -209,   160,  -209,  -209,   160,   160,   160,   160,  -209,  -209,
    -209,  -209,  -209
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     1,     0,     0,     9,    19,    21,
       0,    14,     6,     0,     9,    14,     3,    86,     9,    11,
      13,    12,     0,     0,     0,     5,     0,     0,    41,    71,
      55,    80,     0,    91,     2,    64,    21,    20,    30,    29,
      22,    28,    31,     0,    84,     7,     8,    15,    10,     0,
      50,     0,    43,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,   126,    24,   125,     0,     0,   121,   123,    45,     0,
       0,     0,    73,     0,    57,     0,    59,   115,   117,     0,
       0,     0,     0,     0,     0,     0,    99,    98,    97,    93,
       0,    66,    68,     0,    88,    85,    86,    17,     0,     0,
      23,     0,     0,    52,     0,    49,     0,    47,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,     0,    61,
       0,     0,     0,    86,     0,     0,     0,     0,    35,     0,
      95,     0,     0,     0,    86,     0,     0,    89,    87,    19,
       0,    27,    51,    25,   124,    53,   120,   122,    40,     0,
       0,     0,     0,    75,     0,     0,    86,     0,   114,     0,
       0,    86,   116,   119,     0,     0,     0,     0,    39,     0,
      37,    32,     0,     0,     0,     0,    86,    63,    86,    86,
      16,    19,    48,    46,    44,    42,     0,     0,     0,     0,
       0,   118,    86,    62,     0,    86,     0,     0,    34,    36,
      38,   112,     0,     0,     0,     0,     0,     0,    67,    69,
      65,    18,     0,    77,     0,     0,     0,    86,    54,    86,
      56,     0,     0,   101,     0,   110,    21,    90,     0,     0,
       0,     0,    86,     0,     0,     0,     0,    58,    60,     0,
       0,     0,   103,    21,    21,    86,    96,    94,    92,     0,
      70,    86,    86,    86,    86,    82,     0,    21,    21,     0,
      86,     0,    78,    76,    74,    72,    86,     0,     0,    86,
      86,   105,     0,   113,    79,    86,    86,     0,     0,     0,
     107,     0,    83,    81,     0,     0,     0,     0,   100,   102,
     104,   106,   108
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -209,  -209,  -209,  -209,   114,  -209,   322,  -209,  -146,  -209,
     -36,  -128,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,
    -209,  -209,  -209,    72,  -209,  -209,  -209,  -209,  -209,  -209,
    -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,
    -138,  -209,  -209,  -209,  -209,  -209,  -209,   243,  -208,  -209,
    -209,  -209,  -209,  -209,   -35,   -62,   211,    10,   -47,   224,
     231
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     8,    12,    13,    22,    23,    16,   150,
      17,    37,   111,    69,    38,    93,   179,   210,    39,    53,
      79,   118,   159,    40,    70,   155,    41,    57,   126,   130,
     170,    65,   143,   145,    55,   124,   197,   243,    59,   277,
      42,    43,   147,    44,    63,   141,   183,    99,   214,   251,
     268,   289,   297,   254,   223,    86,    87,    88,    89,    76,
      77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,   169,   102,   190,    75,   174,   187,   238,   239,   240,
      96,     1,    97,    84,    95,    71,    60,   104,   101,    50,
      71,    98,   138,   109,    73,   114,    51,   112,    27,    73,
     180,   106,    28,    71,    29,    30,   114,   290,   200,    31,
      32,   146,    73,   204,    33,   221,   136,    35,   218,    74,
     219,   220,    61,    85,    74,    36,   105,   113,    85,   139,
     114,   163,   114,   114,   235,   181,   252,    74,     5,   121,
     154,    85,   291,    71,   228,    75,   122,   230,     3,   114,
     128,    72,    73,   298,   132,   173,   299,   300,   301,   302,
     128,   128,   115,   281,   152,   128,    71,   177,   236,   247,
     253,   248,   198,   199,    27,    73,     7,    74,    28,    71,
      29,    30,   129,     9,   260,    31,    32,    94,    73,   128,
      33,   196,   144,    35,   128,   282,    82,   189,    25,     4,
      74,    36,    45,   272,   273,   274,   275,   167,   284,    18,
      27,   172,    24,    74,    28,    46,    29,    30,   293,   225,
      47,    31,    32,    48,   226,   125,    33,   292,    27,    35,
      49,   211,    28,    52,    29,    30,    19,    36,   148,    31,
      32,    20,    21,   212,    33,   213,    27,    35,    67,    14,
      28,    15,    29,    30,    54,    36,  -109,    31,    32,   244,
     245,   246,    33,    56,   233,    35,   234,    10,    11,    58,
     255,   -26,    62,    36,  -111,    64,    68,    78,    27,    80,
      83,    81,    28,    90,    29,    30,    91,   269,   270,    31,
      32,    92,    27,   100,    33,    34,    28,    35,    29,    30,
     103,   279,   280,    31,    32,    36,   107,   108,    33,   110,
      27,    35,   116,   287,    28,   117,    29,    30,   119,    36,
     120,    31,    32,   123,   133,   127,    33,   131,    27,    35,
     134,   288,    28,   135,    29,    30,   153,    36,   137,    31,
      32,   149,   140,   160,    33,   151,   158,    35,   164,   161,
     162,   165,   166,   171,   175,    36,   176,   182,   184,   178,
     188,   191,   185,   186,    15,    36,   192,   193,   194,   195,
     202,   203,   201,   114,   206,   205,   207,   208,   215,   209,
     222,   224,   231,   216,   217,   232,   237,   242,   227,   229,
     241,   250,   261,   259,   249,   256,   257,   265,   266,   271,
     262,   258,   278,   283,   263,   264,   285,    26,   156,   168,
       0,   267,     0,   142,     0,     0,     0,   157,     0,     0,
       0,   276,   286,   294,     0,   295,   296
};

static const yytype_int16 yycheck[] =
{
      36,   129,    64,   149,    51,   133,   144,   215,   216,   217,
       1,    22,     3,     1,    61,     3,     1,     1,     1,     1,
       3,    12,     1,    70,    12,     4,     8,    74,    12,    12,
       1,    67,    16,     3,    18,    19,     4,     1,   166,    23,
      24,   103,    12,   171,    28,   191,    93,    31,   186,    37,
     188,   189,    37,    41,    37,    39,    40,     1,    41,    38,
       4,   123,     4,     4,     1,    36,     1,    37,    30,     1,
      38,    41,    36,     3,   202,   122,     8,   205,    12,     4,
       6,    11,    12,   291,     9,   132,   294,   295,   296,   297,
       6,     6,    36,     1,    36,     6,     3,    38,    35,   227,
      35,   229,   164,   165,    12,    12,    12,    37,    16,     3,
      18,    19,    38,    25,   242,    23,    24,    11,    12,     6,
      28,    36,    38,    31,     6,    33,    54,    38,    14,     0,
      37,    39,    18,   261,   262,   263,   264,   127,   276,    12,
      12,   131,     1,    37,    16,    36,    18,    19,   286,    36,
       1,    23,    24,    36,    36,    83,    28,   285,    12,    31,
      12,     1,    16,    37,    18,    19,    21,    39,    40,    23,
      24,    26,    27,    13,    28,    15,    12,    31,     1,    12,
      16,    14,    18,    19,    37,    39,    40,    23,    24,   224,
     225,   226,    28,    37,     1,    31,     3,    34,    35,    37,
     236,    11,    37,    39,    40,    37,     8,    12,    12,     1,
       1,    12,    16,     1,    18,    19,    12,   253,   254,    23,
      24,     1,    12,     1,    28,    29,    16,    31,    18,    19,
       1,   267,   268,    23,    24,    39,     3,    11,    28,    36,
      12,    31,     5,    33,    16,    38,    18,    19,     1,    39,
      12,    23,    24,    36,    38,    37,    28,     7,    12,    31,
       8,    33,    16,    12,    18,    19,     1,    39,    38,    23,
      24,    36,    38,     1,    28,    36,    36,    31,     1,    38,
      38,    36,    38,     1,     3,    39,     8,    39,     1,    36,
       1,     1,    38,    38,    14,    39,     1,    36,    36,    36,
      17,     1,    38,     4,    10,    17,     3,    36,     1,    36,
      12,     1,     3,    39,    39,    10,    40,    38,    17,    17,
       8,     3,     1,    12,    20,    40,    40,     3,    20,     4,
      38,    40,     3,     3,    38,    38,     1,    15,   114,   128,
      -1,    35,    -1,   100,    -1,    -1,    -1,   116,    -1,    -1,
      -1,    38,    38,    36,    -1,    36,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    43,    12,     0,    30,    44,    12,    45,    25,
      34,    35,    46,    47,    12,    14,    50,    52,    12,    21,
      26,    27,    48,    49,     1,    46,    48,    12,    16,    18,
      19,    23,    24,    28,    29,    31,    39,    53,    56,    60,
      65,    68,    82,    83,    85,    46,    36,     1,    36,    12,
       1,     8,    37,    61,    37,    76,    37,    69,    37,    80,
       1,    37,    37,    86,    37,    73,    52,     1,     8,    55,
      66,     3,    11,    12,    37,   100,   101,   102,    12,    62,
       1,    12,    65,     1,     1,    41,    97,    98,    99,   100,
       1,    12,     1,    57,    11,   100,     1,     3,    12,    89,
       1,     1,    97,     1,     1,    40,    52,     3,    11,   100,
      36,    54,   100,     1,     4,    36,     5,    38,    63,     1,
      12,     1,     8,    36,    77,    65,    70,    37,     6,    38,
      71,     7,     9,    38,     8,    12,   100,    38,     1,    38,
      38,    87,    89,    74,    38,    75,    97,    84,    40,    36,
      51,    36,    36,     1,    38,    67,   101,   102,    36,    64,
       1,    38,    38,    97,     1,    36,    38,    99,    98,    53,
      72,     1,    99,   100,    53,     3,     8,    38,    36,    58,
       1,    36,    39,    88,     1,    38,    38,    82,     1,    38,
      50,     1,     1,    36,    36,    36,    36,    78,    97,    97,
      53,    38,    17,     1,    53,    17,    10,     3,    36,    36,
      59,     1,    13,    15,    90,     1,    39,    39,    82,    82,
      82,    50,    12,    96,     1,    36,    36,    17,    53,    17,
      53,     3,    10,     1,     3,     1,    35,    40,    90,    90,
      90,     8,    38,    79,    96,    96,    96,    53,    53,    20,
       3,    91,     1,    35,    95,    52,    40,    40,    40,    12,
      53,     1,    38,    38,    38,     3,    20,    35,    92,    52,
      52,     4,    53,    53,    53,    53,    38,    81,     3,    52,
      52,     1,    33,     3,    82,     1,    38,    33,    33,    93,
       1,    36,    53,    82,    36,    36,    36,    94,    90,    90,
      90,    90,    90
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    46,    47,
      46,    48,    48,    48,    49,    48,    50,    51,    50,    50,
      52,    52,    53,    53,    54,    53,    55,    53,    53,    53,
      53,    53,    56,    57,    56,    58,    56,    59,    56,    56,
      60,    61,    60,    62,    60,    63,    60,    64,    60,    65,
      66,    65,    67,    65,    68,    69,    68,    70,    68,    71,
      68,    72,    68,    68,    73,    68,    74,    68,    75,    68,
      68,    76,    68,    77,    68,    78,    68,    79,    68,    68,
      80,    68,    81,    68,    68,    82,    83,    82,    84,    82,
      85,    86,    85,    87,    85,    88,    85,    89,    89,    89,
      90,    91,    90,    92,    90,    93,    90,    94,    90,    90,
      95,    90,    90,    96,    97,    97,    98,    98,    99,    99,
     100,   100,   101,   101,   102,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     3,     0,     3,     2,     3,     3,     0,
       3,     1,     1,     1,     0,     2,     7,     0,     8,     0,
       2,     0,     1,     4,     0,     5,     0,     5,     1,     1,
       1,     1,     5,     0,     6,     0,     6,     0,     6,     5,
       5,     0,     6,     0,     6,     0,     6,     0,     6,     4,
       0,     5,     0,     5,     7,     0,     7,     0,     8,     0,
       8,     0,     6,     5,     0,     6,     0,     6,     0,     6,
       9,     0,    10,     0,    10,     0,    10,     0,    10,    11,
       0,    12,     0,    12,     1,     3,     0,     4,     0,     4,
       7,     0,     8,     0,     8,     0,     8,     1,     1,     1,
       7,     0,     8,     0,     8,     0,     8,     0,     8,     3,
       0,     4,     1,     5,     3,     1,     3,     1,     4,     3,
       3,     1,     3,     1,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 55 "cpm.y" /* yacc.c:1646  */
    {
	FILE* file;
	char names[] = "Guy Tordjman and Shimon Genish";

	freeAllSymbol();
	if(eCount==1)
	{
		file=fopen(myout,"w");
		fprintf(file,"#%s\n\n",names);
		fprintf(file,".data\n%s\n",(yyvsp[-3].Ptree).code);
		fprintf(file,"%s\n.text \n%s\n",(yyvsp[-1].Ptree).head,(yyvsp[-1].Ptree).code);
		printf("Compilation Complete Succesfuly.\n");
		fclose(file);
	}
	else
	{
		printf("Compilation Complete With %d Errors.\n",eCount-1);
	}

	eCount=0;
	free((yyvsp[-3].Ptree).code);
	free((yyvsp[-1].Ptree).code);
}
#line 1513 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 80 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code=StringCat((yyvsp[-1].Dtree).code,(yyvsp[0].Dtree).code);
	free((yyvsp[-1].Dtree).code);
	free((yyvsp[0].Dtree).code);
}
#line 1523 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 86 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code=strdup("");
}
#line 1531 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 97 "cpm.y" /* yacc.c:1646  */
    {
	sym* s=findSym((yyvsp[-1].strVal));
	char inst[100];
	if(s==NULL)
	{
		add2Sym((yyvsp[-1].strVal),(yyvsp[0].Dtree).type,(yyvsp[0].Dtree).count,(yyvsp[0].Dtree).label,0);
		sprintf(inst,"%s : .space %d\n",(yyvsp[0].Dtree).label,((yyvsp[0].Dtree).count+1)*4);
	}
	else
	{
		s->used=0;
		sprintf(inst,"'%s' is already defined.", (yyvsp[-1].strVal));
		SemanticError(inst);
		sprintf(inst,"%s : .space %d\n",(yyvsp[0].Dtree).label,((yyvsp[0].Dtree).count)*4);
	}
	(yyval.Dtree).code = StringCat((yyvsp[-2].Dtree).code,inst);
	free((yyvsp[-2].Dtree).code);
	free((yyvsp[0].Dtree).label);
}
#line 1555 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 117 "cpm.y" /* yacc.c:1646  */
    {
	sym* s=findSym((yyvsp[-1].strVal));
	char inst[100];
	if(s==NULL)
	{
		add2Sym((yyvsp[-1].strVal),(yyvsp[0].Dtree).type,(yyvsp[0].Dtree).count,(yyvsp[0].Dtree).label,0);
		sprintf(inst,"%s : .space %d\n",(yyvsp[0].Dtree).label,((yyvsp[0].Dtree).count+1)*4);
		(yyval.Dtree).code = strdup(inst);
		free((yyvsp[0].Dtree).label);

	}
	else
	{
		s->used=0;
		sprintf(inst,"'%s' is already defined.", (yyvsp[-1].strVal));
		SemanticError(inst);
		sprintf(inst,"%s : .space %d\n",(yyvsp[0].Dtree).label,((yyvsp[0].Dtree).count)*4);
		(yyval.Dtree).code = strdup(inst);
		free((yyvsp[0].Dtree).label);
	}
}
#line 1581 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 147 "cpm.y" /* yacc.c:1646  */
    {
	sym* s=findSym((yyvsp[-1].strVal));
	char inst[100];
	if(s==NULL)
	{
		add2Sym((yyvsp[-1].strVal),(yyvsp[0].Dtree).type,(yyvsp[0].Dtree).count,(yyvsp[0].Dtree).label,0);
		(yyval.Dtree).label=(yyvsp[0].Dtree).label;
		(yyval.Dtree).count=(yyvsp[0].Dtree).count+1;
		(yyval.Dtree).type=(yyvsp[0].Dtree).type;
	}
	else
	{
		s->used=0;
		(yyval.Dtree).label=(yyvsp[0].Dtree).label;
		(yyval.Dtree).count=(yyvsp[0].Dtree).count;
		(yyval.Dtree).type=(yyvsp[0].Dtree).type;
		sprintf(inst,"%s is already defined", (yyvsp[-1].strVal));
		SemanticError(inst);
	}
}
#line 1606 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 168 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Dtree).type=(yyvsp[-1].Dtree).type;
	(yyval.Dtree).count=0;
	(yyval.Dtree).label=(yyvsp[-1].Dtree).label
}
#line 1616 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 173 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ':'.");}
#line 1622 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 174 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Dtree).type=strdup("");
	(yyval.Dtree).count=0;
	(yyval.Dtree).label=strdup("")
}
#line 1632 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 183 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Dtree).label = newLabel();
	(yyval.Dtree).type = int_;
	(yyval.Dtree).count = 0;
}
#line 1642 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 189 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Dtree).label = newLabel();
	(yyval.Dtree).type = float_;
	(yyval.Dtree).count = 0;
}
#line 1652 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 194 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Dtree).label = newLabel();
	(yyval.Dtree).type = string;
	(yyval.Dtree).count = 0;
}
#line 1662 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 199 "cpm.y" /* yacc.c:1646  */
    { ParsingError("type is incorrect");}
#line 1668 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 200 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Dtree).label = strdup("");
	(yyval.Dtree).type = -1;
	(yyval.Dtree).count = 0;
}
#line 1678 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 209 "cpm.y" /* yacc.c:1646  */
    {
	sym* s;
	char inst[100];
	(yyval.Dtree).code=strdup("");
	if((yyvsp[-5].Dtree).type!=string)//string cant be const
	{
		s=findSym((yyvsp[-4].strVal));
		if(s==NULL)//check if it already exist
		{
			//if exist in sym table
			if((yyvsp[-2].num).type==int_ && (yyvsp[-5].Dtree).type==int_)
			{
				sprintf(inst,"%s : .word %d\n",(yyvsp[-5].Dtree).label,(yyvsp[-2].num).val.ival);
				s= add2Sym((yyvsp[-4].strVal),(yyvsp[-5].Dtree).type,(yyvsp[-5].Dtree).count,(yyvsp[-5].Dtree).label,1);
			}
			else if((yyvsp[-2].num).type==int_ && (yyvsp[-5].Dtree).type==float_)
			{
				sprintf(inst,"%s : .float %d\n",(yyvsp[-5].Dtree).label,(yyvsp[-2].num).val.ival);
				s= add2Sym((yyvsp[-4].strVal),(yyvsp[-5].Dtree).type,(yyvsp[-5].Dtree).count,(yyvsp[-5].Dtree).label,1);
			}
			else if((yyvsp[-2].num).type==float_ && (yyvsp[-5].Dtree).type==float_)
			{
				sprintf(inst,"%s : .float %f\n",(yyvsp[-5].Dtree).label,(yyvsp[-2].num).val.fval);
				s= add2Sym((yyvsp[-4].strVal),(yyvsp[-5].Dtree).type,(yyvsp[-5].Dtree).count,(yyvsp[-5].Dtree).label,1);
			}
			else
			{
				SemanticError("can't assign float into int var");
				sprintf(inst,"");
			}
			if(s!=NULL)
			{
				s->haveVal=1;
				s->used=0;
				free((yyval.Dtree).code);
				(yyval.Dtree).code=StringCat(inst,(yyvsp[0].Dtree).code);
			}
		}
		else
		{
			sprintf(inst,"%s is already defined", (yyvsp[-4].strVal));
			SemanticError(inst);
		}
	}
	else
	{
		SemanticError("string can't be const");
	}
	free((yyvsp[-5].Dtree).label);
}
#line 1733 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 259 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected: ';'");}
#line 1739 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 260 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Dtree).code=strdup("");
}
#line 1747 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 264 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Dtree).code =strdup("");
}
#line 1755 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 271 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code=StringCat((yyvsp[-1].Ptree).code,(yyvsp[0].Ptree).code);
	(yyval.Ptree).head=StringCat((yyvsp[-1].Ptree).head,(yyvsp[0].Ptree).head);
	free((yyvsp[-1].Ptree).head);
	free((yyvsp[-1].Ptree).code);
	free((yyvsp[0].Ptree).head);
	free((yyvsp[0].Ptree).code);
}
#line 1768 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 280 "cpm.y" /* yacc.c:1646  */
    {
(yyval.Ptree).code=strdup("");
(yyval.Ptree).head=strdup("");
}
#line 1777 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 288 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code = (yyvsp[0].Ptree).code;
	(yyval.Ptree).head=(yyvsp[0].Ptree).head;
}
#line 1786 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 293 "cpm.y" /* yacc.c:1646  */
    {
	sym* s=findSym((yyvsp[-3].strVal));
	char inst[200];
	char *label;
	(yyval.Ptree).head=strdup("");
	(yyval.Ptree).code=strdup("");
	if(s!=NULL)
	{
		if(s->type==string)
		{
			free((yyval.Ptree).head);free((yyval.Ptree).code);
			label=newLabel();
			sprintf(inst,"%s: .asciiz \"%s\"\n",label,(yyvsp[-1].strVal));
			(yyval.Ptree).head=strdup(inst);
			sprintf(inst,"la $s0,%s\nla $s1,%s\nsw $s0,%d($s1)\n",label,s->label,s->index*4);
			(yyval.Ptree).code=strdup(inst);
			free(label);
			s->haveVal=1;
		}
		else
		{
			sprintf(inst,"%s is a number, can't assign string in it",(yyvsp[-3].strVal));
			SemanticError(inst);

		}
	}
}
#line 1818 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 320 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected: ';'");}
#line 1824 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 321 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).head=strdup("");
	(yyval.Ptree).code=strdup("");
}
#line 1833 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 325 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected: ':='");}
#line 1839 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 326 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).head=strdup("");
	(yyval.Ptree).code=strdup("");
}
#line 1848 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 331 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code = (yyvsp[0].Ptree).code;
	(yyval.Ptree).head=(yyvsp[0].Ptree).head;
}
#line 1857 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 336 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code = (yyvsp[0].Ptree).code;
	(yyval.Ptree).head=(yyvsp[0].Ptree).head;
}
#line 1866 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 341 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code = (yyvsp[0].Ptree).code;
	(yyval.Ptree).head=(yyvsp[0].Ptree).head;
}
#line 1875 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 346 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code = (yyvsp[0].Ptree).code;
	(yyval.Ptree).head=(yyvsp[0].Ptree).head;
}
#line 1884 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 354 "cpm.y" /* yacc.c:1646  */
    {

	char inst[200];
	char* regT = getRegisterT();
	char* regF = getRegisterF();
	if((yyvsp[-2].Ptree).type==int_)
		sprintf(inst,"li $v0,1\nmove $a0,$t2\n syscall\n");
	else if ((yyvsp[-2].Ptree).type==float_)
		sprintf(inst,"li $v0,2\nmov.s $f12,$f2\n syscall\n");
	else if((yyvsp[-2].Ptree).type==string)
		sprintf(inst,"li $v0,4\nmove $a0,$t2\nsyscall\n");
	(yyval.Ptree).code=StringCat((yyvsp[-2].Ptree).code,inst);
	free((yyvsp[-2].Ptree).code);
	(yyval.Ptree).head=(yyvsp[-2].Ptree).head;
}
#line 1904 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 369 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected '('.");}
#line 1910 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 370 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 1919 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 374 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ')'.");}
#line 1925 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 375 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 1934 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 379 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ';'.");}
#line 1940 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 380 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 1949 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 385 "cpm.y" /* yacc.c:1646  */
    {
	char inst[200];
	char* label = newLabel();
	sprintf(inst,"%s: .asciiz \"%s\"\n",label,(yyvsp[-2].strVal));
	(yyval.Ptree).head=strdup(inst);
	sprintf(inst,"li $v0,4\nla $a0,%s\nsyscall\n",label);
	(yyval.Ptree).code=strdup(inst);
	free(label);
}
#line 1963 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 398 "cpm.y" /* yacc.c:1646  */
    {
	char inst[100];
	char* str,*tmp;
	int x=0;
	sym* s=findSym((yyvsp[-2].strVal));
	if(s!=NULL)
	{
		if(!s->constant)
		{
			if(s->type==int_)
				x=5;
			else if(s->type==float_)
				x=6;
			else
			{
				sprintf(inst,"'%s' is string type, can't read string from user!",(yyvsp[-2].strVal));
				SemanticError(inst);
			}
		}
		else
		{
			sprintf(inst,"'%s' is constant variable, can't change his value!",(yyvsp[-2].strVal));
			SemanticError(inst);
		}
		if(x)
		{
			s->haveVal = 1;
		}
	}
	if(x)
	{
		sprintf(inst,"li $v0,%d\nsyscall\n",x);
		tmp=StringCat("la $s0,",s->label);
		str=StringCat(inst,tmp);
		free(tmp);
		if(x==5)
			sprintf(inst,"\nsw $v0,%d($s0)\n",s->index*4);
		else if(x==6)
			sprintf(inst,"\nswc1 $f0,%d($s0)\n",s->index*4);
		tmp=str;
		str = StringCat(str,inst);
		free(tmp);
		(yyval.Ptree).code =str;
	}
	else
		(yyval.Ptree).code=strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 2016 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 446 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected '('.");}
#line 2022 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 447 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 2031 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 451 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected id.");}
#line 2037 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 452 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 2046 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 456 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ')'.");}
#line 2052 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 457 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 2061 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 461 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ';'.");}
#line 2067 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 462 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 2076 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 470 "cpm.y" /* yacc.c:1646  */
    {
	//check if id exist and not const and set that have value
	char inst[100];
	char* str,*tmp;
	sym* s=findSym((yyvsp[-3].strVal));
	if(s!=NULL)
	{
		if(!s->constant)
		{
			if(s->type==(yyvsp[-1].Ptree).type)
			{
				str= StringCat("la $s0,",s->label);
				if(s->type==float_)
					sprintf(inst,"\nswc1 $f2,%d($s0)\n",s->index*4);
				else
					sprintf(inst,"\nsw $t2,%d($s0)\n",s->index*4);
				tmp = StringCat(str,inst);
				(yyval.Ptree).code=StringCat((yyvsp[-1].Ptree).code,tmp);
				free(tmp);free(str);
				s->haveVal=1;
			}
			else if (s->type==float_) //first id float, second id int
			{
				str= StringCat("la $s0,",s->label);
				sprintf(inst,"\nmtc1 $t2, $f2\ncvt.s.w $f2, $f2\nswc1 $f2,%d($s0)\n",s->index*4);
				tmp = StringCat(str,inst);
				(yyval.Ptree).code=StringCat((yyvsp[-1].Ptree).code,tmp);
				free(tmp);free(str);
				s->haveVal=1;
			}
			else if(s->type==int_ && (yyvsp[-1].Ptree).type==float_)
			{
				sprintf(inst,"cannot assign (float) to identifier '%s'(int).", s->name);
				SemanticError(inst);
				(yyval.Ptree).code=StringCat((yyvsp[-1].Ptree).code,"");
			}
			else
			{
				sprintf(inst,"cannot assign to identifier '%s', types are not match.", s->name);
				SemanticError(inst);
				(yyval.Ptree).code=StringCat((yyvsp[-1].Ptree).code,"");
			}
		}
		else
		{
			sprintf(inst,"%s is declared as const, and cannot be override.",(yyvsp[-3].strVal));
			SemanticError(inst);
		}
	}
	else
	{
		sprintf(inst,"\nSemantic Error: identifier '%s' is undefined.", (yyvsp[-3].strVal));
		yyerror(inst);
		(yyval.Ptree).code=StringCat((yyvsp[-1].Ptree).code,"");
	}
	free((yyvsp[-1].Ptree).code);
	(yyval.Ptree).head=(yyvsp[-1].Ptree).head;
}
#line 2139 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 527 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ':='.");}
#line 2145 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 528 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 2154 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 532 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ';'.");}
#line 2160 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 533 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 2169 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 541 "cpm.y" /* yacc.c:1646  */
    {
	char *str,*tmp;
	char* labelFalse=newLabel();
	char* labelOut=newLabel();
	char inst[100];
	sprintf(inst,"beq $t1,$0,%s\n",labelFalse);
	str=StringCat(inst,(yyvsp[-2].Ptree).code);
	sprintf(inst,"j %s\n%s: ",labelOut,labelFalse);
	tmp=StringCat(str,inst);
	free(str);
	str=StringCat(tmp,(yyvsp[0].Ptree).code);
	free(tmp);
	sprintf(inst,"%s:\n",labelOut);
	(yyval.Ptree).code=StringCat(str,inst);
	free(str);
	str=StringCat((yyvsp[-4].Ptree).code,(yyval.Ptree).code);
	free((yyval.Ptree).code);
	free((yyvsp[-4].Ptree).code);
	(yyval.Ptree).code=str;
	free((yyvsp[-2].Ptree).code);
	free((yyvsp[0].Ptree).code);
	str=StringCat((yyvsp[-2].Ptree).head,(yyvsp[0].Ptree).head);
	free((yyvsp[0].Ptree).head);
	free((yyvsp[-2].Ptree).head);
	(yyval.Ptree).head=StringCat((yyvsp[-4].Ptree).head,str);
	free((yyvsp[-4].Ptree).head);
	free(str);
	free(labelFalse);
	free(labelOut);
}
#line 2204 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 571 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected '('.");}
#line 2210 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 572 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code=strdup("");
	(yyval.Ptree).head=strdup("");
	free((yyvsp[-2].Ptree).code);
	free((yyvsp[0].Ptree).code);
	free((yyvsp[-2].Ptree).head);
	free((yyvsp[0].Ptree).head);
}
#line 2223 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 580 "cpm.y" /* yacc.c:1646  */
    {ParsingError("IF statment expected an boolean expression.");}
#line 2229 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 581 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code=strdup("");
	(yyval.Ptree).head=strdup("");
	free((yyvsp[-2].Ptree).code);
	free((yyvsp[-2].Ptree).head);
	free((yyvsp[0].Ptree).code);
	free((yyvsp[0].Ptree).head);
}
#line 2242 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 589 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ')'.");}
#line 2248 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 590 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code=strdup("");
	(yyval.Ptree).head=strdup("");
	free((yyvsp[-2].Ptree).code);
	free((yyvsp[0].Ptree).code);
	free((yyvsp[-2].Ptree).head);
	free((yyvsp[0].Ptree).head);
	free((yyvsp[-5].Ptree).code);
	free((yyvsp[-5].Ptree).head);
}
#line 2263 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 600 "cpm.y" /* yacc.c:1646  */
    {ParsingError("IF statement expected statement.");}
#line 2269 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 601 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code=strdup("");
	(yyval.Ptree).head=strdup("");
	free((yyvsp[-3].Ptree).code);
	free((yyvsp[-3].Ptree).head);
}
#line 2280 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 608 "cpm.y" /* yacc.c:1646  */
    {
	char* loop=newLabel();
	char* out=newLabel();
	char* str,*tmp;
	char inst[100];
	sprintf(inst,"beq $t1,$0,%s\n",out);
	str=StringCat((yyvsp[-2].Ptree).code,inst);
	free((yyvsp[-2].Ptree).code);
	sprintf(inst,"%s: ",loop);
	tmp=StringCat(inst,str);
	free(str);
	str=StringCat(tmp,(yyvsp[0].Ptree).code);
	free(tmp);
	free((yyvsp[0].Ptree).code);
	sprintf(inst,"j %s\n%s: \n",loop,out);
	(yyval.Ptree).code=StringCat(str,inst);
	free(str);
	(yyval.Ptree).head=StringCat((yyvsp[-2].Ptree).head,(yyvsp[0].Ptree).head);
	free((yyvsp[-2].Ptree).head);
	free((yyvsp[0].Ptree).head);
}
#line 2306 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 629 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected '('.");}
#line 2312 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 630 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code=strdup("");
	(yyval.Ptree).head=strdup("");
	free((yyvsp[-2].Ptree).head);
	free((yyvsp[-2].Ptree).code);
	free((yyvsp[0].Ptree).head);
	free((yyvsp[0].Ptree).code);
}
#line 2325 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 638 "cpm.y" /* yacc.c:1646  */
    {ParsingError("WHILE statment expected an boolean expression.");}
#line 2331 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 639 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code=strdup("");
	(yyval.Ptree).head=strdup("");
	free((yyvsp[0].Ptree).head);
	free((yyvsp[0].Ptree).code);
}
#line 2342 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 645 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ')'.");}
#line 2348 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 646 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code=strdup("");
	(yyval.Ptree).head=strdup("");
	free((yyvsp[-3].Ptree).head);
	free((yyvsp[-3].Ptree).code);
	free((yyvsp[0].Ptree).head);
	free((yyvsp[0].Ptree).code);
}
#line 2361 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 655 "cpm.y" /* yacc.c:1646  */
    {
	char* loop=newLabel();
	char* out=newLabel();
	char* str,*tmp;
	char inst[100];
	sprintf(inst,"beq $t1,$0,%s\n",out);
	str=StringCat((yyvsp[-4].Ptree).code,inst);free((yyvsp[-4].Ptree).code);
	sprintf(inst,"%s: ",loop);
	tmp=StringCat(inst,str);free(str);
	str=StringCat(tmp,(yyvsp[0].Ptree).code);
	free(tmp);
	free((yyvsp[0].Ptree).code);
	tmp=StringCat(str,(yyvsp[-2].Ptree).code);free((yyvsp[-2].Ptree).code);free(str);
	sprintf(inst,"j %s\n%s: \n",loop,out);
	str=StringCat(tmp,inst);free(tmp);
	(yyval.Ptree).code=StringCat((yyvsp[-6].Ptree).code,str);
	free(str);
	free((yyvsp[-6].Ptree).code);
	str=StringCat((yyvsp[-6].Ptree).head,(yyvsp[-4].Ptree).head);
	free((yyvsp[-6].Ptree).head);
	free((yyvsp[-4].Ptree).head);
	tmp=StringCat((yyvsp[-2].Ptree).head,(yyvsp[0].Ptree).head);
	free((yyvsp[-2].Ptree).head);
	free((yyvsp[0].Ptree).head);
	(yyval.Ptree).head=StringCat(str,tmp);
	free(str);
	free(tmp);
}
#line 2394 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 683 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected '('.");}
#line 2400 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 684 "cpm.y" /* yacc.c:1646  */
    {
	free((yyvsp[-6].Ptree).code);
	free((yyvsp[-4].Ptree).code);
	free((yyvsp[-2].Ptree).code);
	free((yyvsp[0].Ptree).code);
	free((yyvsp[-6].Ptree).head);
	free((yyvsp[-4].Ptree).head);
	free((yyvsp[-2].Ptree).head);
	free((yyvsp[0].Ptree).head);
	(yyval.Ptree).code=strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 2417 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 696 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ';'.");}
#line 2423 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 697 "cpm.y" /* yacc.c:1646  */
    {
	free((yyvsp[-7].Ptree).code);
	free((yyvsp[-4].Ptree).code);
	free((yyvsp[-2].Ptree).code);
	free((yyvsp[0].Ptree).code);
	free((yyvsp[-7].Ptree).head);
	free((yyvsp[-4].Ptree).head);
	free((yyvsp[-2].Ptree).head);
	free((yyvsp[0].Ptree).head);
	(yyval.Ptree).code=strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 2440 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 709 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ';'.");}
#line 2446 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 710 "cpm.y" /* yacc.c:1646  */
    {
	free((yyvsp[-7].Ptree).code);
	free((yyvsp[-5].Ptree).code);
	free((yyvsp[-2].Ptree).code);
	free((yyvsp[0].Ptree).code);
	free((yyvsp[-7].Ptree).head);
	free((yyvsp[-5].Ptree).head);
	free((yyvsp[-2].Ptree).head);
	free((yyvsp[0].Ptree).head);
	(yyval.Ptree).code=strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 2463 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 722 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ')'.");}
#line 2469 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 723 "cpm.y" /* yacc.c:1646  */
    {
	free((yyvsp[-7].Ptree).code);
	free((yyvsp[-5].Ptree).code);
	free((yyvsp[-3].Ptree).code);
	free((yyvsp[0].Ptree).code);
	free((yyvsp[-7].Ptree).head);
	free((yyvsp[-5].Ptree).head);
	free((yyvsp[-3].Ptree).head);
	free((yyvsp[0].Ptree).head);
	(yyval.Ptree).code=strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 2486 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 736 "cpm.y" /* yacc.c:1646  */
    {
	char *data, *str;
	char inst1[100];
	char inst2[100];
	char inst3[200];
	char* t0= getRegister();
	char *t1= getRegister();
	char* t2= getRegister();
	char* t3= getRegister();
	char* label=newLabel();
	char* loopLbl=newLabel();
	char* outLbl=newLabel();

	sym* s = findSym((yyvsp[-8].strVal));
	if(s != NULL){
		if(s->type == int_){
			int sval= (yyvsp[-6].num).val.ival;
			int end_val= (yyvsp[-4].num).val.ival;
			int step_val = (yyvsp[-2].num).val.ival;
			sprintf(inst1,"\nli %s,%d\nsw %s, %s\nli %s,%d\nli %s,%d\nslt %s,%s,%s\n",t0,sval,t0,(yyvsp[-8].strVal),t1,end_val,t2,step_val,t3,t0,t1);
			sprintf(inst2,"\nbeq %s,1,%s\nmul %s,%s,-1\nj %s\n%s:\nadd %s,%s,%s",t3,label,t2,t2,loopLbl,label,t3,t0,t2);
			sprintf(inst2,"\n%s:\n%s\nadd %s,%s,%s\nsw %s, %s\nbeq %s,%s,%s\nj %s\n%s:\n",loopLbl,(yyvsp[0].Ptree).code,t0,t0,t2,t0,(yyvsp[-8].strVal),t0,t1,outLbl,loopLbl,outLbl);
		}
		else{

		}
	}
	else{
	}
	str = StringCat(inst1,inst2);
	data = StringCat(str,inst3);
	(yyval.Ptree).code = strdup(data);
	(yyval.Ptree).head = strdup((yyvsp[0].Ptree).head);
	free((yyvsp[0].Ptree).head);
	free((yyvsp[0].Ptree).code);
	free(label);
	free(loopLbl);
	free(outLbl):
	free(str);
	free(data);

}
#line 2533 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 778 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected '('.");}
#line 2539 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 779 "cpm.y" /* yacc.c:1646  */
    {
	free((yyvsp[-8].strVal).code);
	free((yyvsp[-7].sign2).code);
	free((yyvsp[-6].num).code);
	free((yyvsp[-4].num).code);
	free((yyvsp[0].Ptree).code);
	free((yyvsp[-8].strVal).head);
	free((yyvsp[-7].sign2).head);
	free((yyvsp[-6].num).head);
	free((yyvsp[-4].num).head);
	free((yyvsp[0].Ptree).head);
	(yyval.Ptree).code=strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 2558 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 793 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ')'.");}
#line 2564 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 794 "cpm.y" /* yacc.c:1646  */
    {
	free((yyvsp[-9].strVal).code);
	free((yyvsp[-7].num).code);
	free((yyvsp[-5].num).code);
	free((yyvsp[-3].num).code);
	free((yyvsp[0].Ptree).code);
	free((yyvsp[-9].strVal).head);
	free((yyvsp[-7].num).head);
	free((yyvsp[-5].num).head);
	free((yyvsp[-3].num).head);
	free((yyvsp[0].Ptree).head);
	(yyval.Ptree).code=strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 2583 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 809 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code=(yyvsp[0].Ptree).code;
	(yyval.Ptree).head=(yyvsp[0].Ptree).head;
}
#line 2592 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 817 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code =(yyvsp[-1].Ptree).code;
	(yyval.Ptree).head=(yyvsp[-1].Ptree).head;
}
#line 2601 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 822 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected '{'.");}
#line 2607 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 823 "cpm.y" /* yacc.c:1646  */
    {
	free((yyvsp[-1].Ptree).code);
	free((yyvsp[-1].Ptree).head);
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head = strdup("");
}
#line 2618 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 830 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected '}'.");}
#line 2624 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 831 "cpm.y" /* yacc.c:1646  */
    {
	free((yyvsp[-2].Ptree).code);
	free((yyvsp[-2].Ptree).head);
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head = strdup("");
}
#line 2635 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 841 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code=StringCat((yyvsp[-4].Ptree).code,(yyvsp[-1].Ptree).code);
	free((yyvsp[-4].Ptree).code);
	free((yyvsp[-1].Ptree).code);
	(yyval.Ptree).head = StringCat((yyvsp[-4].Ptree).head,(yyvsp[-1].Ptree).head);
	free((yyvsp[-4].Ptree).head);
	free((yyvsp[-1].Ptree).head);
	free((yyvsp[-1].Ptree).label);
}
#line 2649 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 850 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected '('.");}
#line 2655 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 851 "cpm.y" /* yacc.c:1646  */
    {
	free((yyvsp[-4].Ptree).code);
	free((yyvsp[-1].Ptree).code);
	free((yyvsp[-4].Ptree).head);
	free((yyvsp[-1].Ptree).head);
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head = strdup("");
}
#line 2668 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 859 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ')'.");}
#line 2674 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 860 "cpm.y" /* yacc.c:1646  */
    {
	free((yyvsp[-5].Ptree).code);
	free((yyvsp[-1].Ptree).code);
	free((yyvsp[-5].Ptree).head);
	free((yyvsp[-1].Ptree).head);
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head = strdup("");
}
#line 2687 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 868 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected '{'.");}
#line 2693 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 869 "cpm.y" /* yacc.c:1646  */
    {
	free((yyvsp[-5].Ptree).code);
	free((yyvsp[-1].Ptree).code);
	free((yyvsp[-5].Ptree).head);
	free((yyvsp[-1].Ptree).head);
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head = strdup("");
}
#line 2706 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 882 "cpm.y" /* yacc.c:1646  */
    {
	sym* s = findSym((yyvsp[0].strVal));
	char inst[150];
	sprintf(inst,"");
	if(s!=NULL)
	{
		if(s->haveVal)
		{
			if(s->type==int_)
				sprintf(inst,"la $s0,%s\nlw $s1,%d($s0)\n",s->label,s->index*4);
			else
				SemanticError("swicth choice can't be only int");
		}
		else
		{
			sprintf(inst,"'%s' has no value.",(yyvsp[0].strVal));
			SemanticError(inst);
			sprintf(inst,"");
		}


	}
	else
	{
		sprintf(inst,"'%s' has not define.",(yyvsp[0].strVal));
		SemanticError(inst);
		sprintf(inst,"");
	}
	free((yyvsp[0].strVal));
	(yyval.Ptree).code=strdup(inst);
	(yyval.Ptree).head=strdup("");
}
#line 2743 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 915 "cpm.y" /* yacc.c:1646  */
    {
	char inst[100];
	if((yyvsp[0].num).type==int_)
		sprintf(inst,"li $s1,%d\n",(yyvsp[0].num).val.ival);
	else
	{
		sprintf(inst,"");
		SemanticError("swicth choice can't be only int");
	}
	(yyval.Ptree).code = strdup(inst);
	(yyval.Ptree).head=strdup("");
}
#line 2760 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 928 "cpm.y" /* yacc.c:1646  */
    {
	ParsingError("expected id or number.");
	(yyval.Ptree).code=strdup("");
	(yyval.Ptree).head=strdup("");
}
#line 2770 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 938 "cpm.y" /* yacc.c:1646  */
    {
	char* str,*tmp;
	char inst[100];
	char* next=newLabel();
	char* out=(yyvsp[0].Ptree).label;
	(yyval.Ptree).label=out;
	if((yyvsp[-5].num).type==int_)
	{
		sprintf(inst,"li $t1,%d\nbne $s1,$t1,%s\n",(yyvsp[-5].num).val.ival,next);
		str=StringCat(inst,(yyvsp[-3].Ptree).code);
		free((yyvsp[-3].Ptree).code);
		sprintf(inst,"j %s\n%s: ",out,next);
		tmp=StringCat(str,inst);
		free(str);
		(yyval.Ptree).code=StringCat(tmp,(yyvsp[0].Ptree).code);
		free((yyvsp[0].Ptree).code);
		free(tmp);
	}
	else
	{
		SemanticError("case works only with int numbers");
	}
	free(next);
	(yyval.Ptree).head=StringCat((yyvsp[-3].Ptree).head,(yyvsp[0].Ptree).head);
	free((yyvsp[-3].Ptree).head);
	free((yyvsp[0].Ptree).head);
}
#line 2802 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 965 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected num.");}
#line 2808 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 966 "cpm.y" /* yacc.c:1646  */
    {
	free((yyvsp[-3].Ptree).code);
	free((yyvsp[0].Ptree).code);
	free((yyvsp[-3].Ptree).head);
	free((yyvsp[0].Ptree).head);
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head = strdup("");
	(yyval.Ptree).label=strdup("");
}
#line 2822 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 975 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ':'.");}
#line 2828 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 976 "cpm.y" /* yacc.c:1646  */
    {
	free((yyvsp[-3].Ptree).code);
	free((yyvsp[0].Ptree).code);
	free((yyvsp[-3].Ptree).head);
	free((yyvsp[0].Ptree).head);
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head = strdup("");
	(yyval.Ptree).label=strdup("");
}
#line 2842 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 985 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected 'break'.");}
#line 2848 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 986 "cpm.y" /* yacc.c:1646  */
    {
	free((yyvsp[-4].Ptree).code);
	free((yyvsp[0].Ptree).code);
	free((yyvsp[-4].Ptree).head);
	free((yyvsp[0].Ptree).head);
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head = strdup("");
	(yyval.Ptree).label=strdup("");
}
#line 2862 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 995 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ';'.");}
#line 2868 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 996 "cpm.y" /* yacc.c:1646  */
    {
	free((yyvsp[-4].Ptree).code);
	free((yyvsp[0].Ptree).code);
	free((yyvsp[-4].Ptree).head);
	free((yyvsp[0].Ptree).head);
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head = strdup("");
	(yyval.Ptree).label=strdup("");
}
#line 2882 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1006 "cpm.y" /* yacc.c:1646  */
    {
	char* out=newLabel();
	char* str=StringCat((yyvsp[0].Ptree).code,out);
	free((yyvsp[0].Ptree).code);
	(yyval.Ptree).code = StringCat(str,": \n");
	free(str);
	(yyval.Ptree).label=out;
	(yyval.Ptree).head=(yyvsp[0].Ptree).head;
}
#line 2896 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1015 "cpm.y" /* yacc.c:1646  */
    {ParsingError("expected ':'.");}
#line 2902 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1016 "cpm.y" /* yacc.c:1646  */
    {
	free((yyvsp[0].Ptree).code);
	free((yyvsp[0].Ptree).head);
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head = strdup("");
	(yyval.Ptree).label=strdup("");
}
#line 2914 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1024 "cpm.y" /* yacc.c:1646  */
    {
	ParsingError("switch case must have default case.");
	(yyval.Ptree).code = strdup("");
	(yyval.Ptree).head = strdup("");
	(yyval.Ptree).label=strdup("");
}
#line 2925 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1035 "cpm.y" /* yacc.c:1646  */
    {
	sym* s1=findSym((yyvsp[-4].strVal));
	sym* s2=findSym((yyvsp[-2].strVal));
	char inst[200];
	char* str,*tmp,*head;
	char* label;
	(yyval.Ptree).head=strdup("");
	(yyval.Ptree).code=strdup("");
	if(s1!=NULL)//check if id2 has a value and id1 not a const
	{
		if(s2!=NULL)
		{
			if(!s1->constant)
			{
				if(s2->haveVal)
				{
					if(s2->type!=string)//0 has the value of the number
					{
						if(s1->type!=string)
						{
							 label=newLabel();

							 sprintf(inst,"la $s0,%s\n",s2->label);
							 if((yyvsp[0].num).type==float_)
							 {
							 	sprintf(inst,"%s: .float %f\n",label,(yyvsp[0].num).val.fval);
							 	free((yyval.Ptree).head);(yyval.Ptree).head=strdup(inst);
							 	sprintf(inst,"l.s $f0,%s\n",label);

							 }
							 else
							 {
							 	sprintf(inst,"li $t0,%d\n",(yyvsp[0].num).val.ival);

							 }
							 (yyval.Ptree).type=float_;
							 str=strdup(inst);
							 if(s2->type==float_)
							 {
							 	sprintf(inst,"lwc1 $f1,%d($s0)\n",s2->index*4);
							 	tmp=StringCat(str,inst);free(str);
							 	sprintf(inst,"");
							 	if((yyvsp[0].num).type==int_)
							 	{
							 		sprintf(inst,"mtc1 $t0, $f0\ncvt.s.w $f0, $f0");
							 	}
							 	str=StringCat(tmp,inst);free(tmp);
							 	tmp=StringCat(str,"add.s $f2,$f1,$f0\n");free(str);
							 }
							 else
							 {
							 	sprintf(inst,"lw $t1,%d($s0)\n",s2->index*4);
							 	tmp=StringCat(str,inst);free(str);
							 	sprintf(inst,"");
							 	if((yyvsp[0].num).type==float_)
							 	{
							 		sprintf(inst,"mtc1 $t1, $f1\ncvt.s.w $f1, $f1");
							 		str=StringCat(tmp,inst);free(tmp);
							 		tmp=StringCat(str,"add.s $f2,$f1,$f0\n");free(str);
							 	}
							 	else
							 	{
									(yyval.Ptree).type=int_;
							 		str=StringCat(tmp,"add $t2,$t1,$t0\n");free(tmp);
							 		tmp=str;
							 	}
							}
							sprintf(inst,"la $s0,%s\n",s1->label);
							str=StringCat(tmp,inst);free(tmp);
							if(s1->type==float_)
							{
								if((yyval.Ptree).type==int_)
									sprintf(inst,"mtc1 $t2, $f2\ncvt.s.w $f2, $f2");
								else
									sprintf(inst,"");
								tmp=StringCat(str,inst);free(str);
								sprintf(inst,"swc1 $f2,%d($s0)\n",s2->index*4);
								free((yyval.Ptree).code);
								(yyval.Ptree).code=StringCat(tmp,inst);
							}
							else
							{
								tmp=str;
								if((yyval.Ptree).type==int_)
								{
									sprintf(inst,"sw $t2,%d($s0)\n",s2->index*4);
									free((yyval.Ptree).code);
									(yyval.Ptree).code=StringCat(tmp,inst);
								}
								else
									SemanticError("Can't assign float expretion in int value");

							}
							free(tmp);
						}
						else
						{
							sprintf(inst,"'%s' is string,can't make math on strings.",(yyvsp[-4].strVal));
							SemanticError(inst);
						}
					}
					else
					{
						sprintf(inst,"'%s' is string,can't make math on strings.",(yyvsp[-2].strVal));
						SemanticError(inst);
					}
				}
				else
				{
					sprintf(inst,"'%s' was not initialized.",(yyvsp[-2].strVal));
					SemanticError(inst);
				}
			}
			else
			{
				sprintf(inst,"'%s' is declerd const and can not be override.",(yyvsp[-4].strVal));
				SemanticError(inst);
			}
		}
		else
		{
			sprintf(inst,"'%s' is undefined",(yyvsp[-2].strVal));
			SemanticError(inst);
		}
	}
	else
	{
		sprintf(inst,"'%s' is undefined",(yyvsp[-4].strVal));
		SemanticError(inst);
	}
	free((yyvsp[-4].strVal));
	free((yyvsp[-2].strVal));
}
#line 3063 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1175 "cpm.y" /* yacc.c:1646  */
    {
	char inst[200];
	char* labelTrue=newLabel();
	char* labelOut=newLabel();
	char* str1;
	char* str2=StringCat("\nbne $t2,$0,",labelTrue);
	sprintf(inst,"bne $t1,$0,%s\n",labelTrue);
	(yyval.Ptree).code=StringCat((yyvsp[-2].Ptree).code,inst);
	free((yyvsp[-2].Ptree).code);
	str1=(yyval.Ptree).code;
	(yyval.Ptree).code=StringCat(str1,(yyvsp[0].Ptree).code);
	free(str1);free((yyvsp[0].Ptree).code);
	str1=(yyval.Ptree).code;
	(yyval.Ptree).code=StringCat(str1,str2);
	free(str1);free(str2);
	str1=(yyval.Ptree).code;
	sprintf(inst,"\nli $t1,0\nj %s\n%s: li $t1,1\n%s:\n",labelOut,labelTrue,labelOut);
	(yyval.Ptree).code=StringCat(str1,inst);
	free(str1);
	(yyval.Ptree).head=StringCat((yyvsp[-2].Ptree).head,(yyvsp[0].Ptree).head);
	free((yyvsp[0].Ptree).head);
}
#line 3090 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1198 "cpm.y" /* yacc.c:1646  */
    {
	Code c={(yyvsp[0].Ptree).code,int_,(yyvsp[0].Ptree).head};
	t1 = getRegister();
	t2 = getRegister();
	c = moveCode(c,t2,t1);
	(yyval.Ptree).code=c.code;
	(yyval.Ptree).type=c.type;
	(yyval.Ptree).head=c.head;
}
#line 3104 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1213 "cpm.y" /* yacc.c:1646  */
    {
	char inst[200];
	char* labelFalse=newLabel();
	char* labelOut=newLabel();
	char* str1=StringCat("beq $t2,$0,",labelFalse);
	str1=StringCat(str1,"\n");
	char* str2=StringCat("\nbeq $t3,$0,",labelFalse);
	(yyval.Ptree).code=StringCat((yyvsp[-2].Ptree).code,str1);
	free((yyvsp[-2].Ptree).code);
	free(str1);
	str1=(yyval.Ptree).code;
	(yyval.Ptree).code=StringCat(str1,(yyvsp[0].Ptree).code);
	free(str1);
	free((yyvsp[0].Ptree).code);
	str1=(yyval.Ptree).code;
	(yyval.Ptree).code=StringCat(str1,str2);
	free(str1);free(str2);
	str1=(yyval.Ptree).code;
	sprintf(inst,"\nli $t2,1\nj %s\n%s: li $t2,0\n%s:\n",labelOut,labelFalse,labelOut);
	(yyval.Ptree).code=StringCat(str1,inst);
	free(str1);
	(yyval.Ptree).head=StringCat((yyvsp[-2].Ptree).head,(yyvsp[0].Ptree).head);
	free((yyvsp[0].Ptree).head);
}
#line 3133 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1238 "cpm.y" /* yacc.c:1646  */
    {
	Code c={(yyvsp[0].Ptree).code,int_,(yyvsp[0].Ptree).head};
	t1 = getRegister();
	t2 = getRegister();
	c = moveCode(c,t2,t1);
	(yyval.Ptree).code=c.code;
	(yyval.Ptree).type=c.type;
	(yyval.Ptree).head=c.head;
}
#line 3147 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1251 "cpm.y" /* yacc.c:1646  */
    {
	(yyval.Ptree).code=StringCat((yyvsp[-1].Ptree).code,"li $t2,1\nsub $t3,$t2,$t3\n"); // $t3 =1- $t3
	free((yyvsp[-1].Ptree).code);
	(yyval.Ptree).head=(yyvsp[-1].Ptree).head;
}
#line 3157 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1258 "cpm.y" /* yacc.c:1646  */
    {
	//add string case and float case
	char* str,*tmp;
	char* labelTrue,*labelOut;
	char inst[150];
	labelTrue=newLabel();
	labelOut=newLabel();
	if((yyvsp[-2].Ptree).type==int_ && (yyvsp[0].Ptree).type==int_)
	{
		str=strdup("move $t3,$t2\n");
		tmp=StringCat((yyvsp[-2].Ptree).code,str);
		free(str);
		str=StringCat(tmp,(yyvsp[0].Ptree).code);
		free(tmp);
		//t3 has the value of $1, t2 has the value of $3
		if(strcmp((yyvsp[-1].sign2),"<")==0)
			tmp=strdup("slt $t2,$t3,$t2\nbgtz $t2,");
		else if(strcmp((yyvsp[-1].sign2),">")==0)
			tmp=strdup("slt $t2,$t2,$t3\nbgtz $t2,");
		else if(strcmp((yyvsp[-1].sign2),"<=")==0)
			tmp=strdup("sub $t2,$t2,$t3\nbgez $t2,");
		else if(strcmp((yyvsp[-1].sign2),">=")==0)
			tmp=strdup("sub $t2,$t3,$t2\nbgez $t2,");
		else if(strcmp((yyvsp[-1].sign2),"==")==0)
			tmp=strdup("beq $t3,$t2,");
		else if(strcmp((yyvsp[-1].sign2),"!=")==0)
			tmp=strdup("bne $t3,$t2,");
		sprintf(inst,"%s\nli $t3,0\nj %s\n%s: li $t3,1\n%s:\n",labelTrue,labelOut,labelTrue,labelOut);
		(yyval.Ptree).code=tmp;
		tmp=StringCat(tmp,inst);
		free((yyval.Ptree).code);
		(yyval.Ptree).code=StringCat(str,tmp);
		free(str);free(tmp);
	}
	else if((yyvsp[-2].Ptree).type==string || (yyvsp[0].Ptree).type==string)
	{
		if((yyvsp[-2].Ptree).type==(yyvsp[0].Ptree).type)
		{
			str=strdup("move $t3,$t2\n");
			tmp=StringCat((yyvsp[-2].Ptree).code,str);
			free(str);
			str=StringCat(tmp,(yyvsp[0].Ptree).code);
			free(tmp);
			//t3 has the value of $1, t2 has the value of $3
			if(strcmp((yyvsp[-1].sign2),"==")==0)
				tmp=StringCat("beq $t3,$t2,",labelTrue);
			else if(strcmp((yyvsp[-1].sign2),"!=")==0)
				tmp=StringCat("bne $t3,$t2,",labelTrue);
			else
			{
				sprintf(inst,"can't make %s between string",(yyvsp[-1].sign2));
				SemanticError(inst);
				sprintf(inst,"");
				tmp=strdup("");
				(yyval.Ptree).code=strdup("");
			}
			//can not check string for the other relop
			sprintf(inst,"\nli $t3,0\nj %s\n%s: li $t3,1\n%s:\n",labelOut,labelTrue,labelOut);
			(yyval.Ptree).code=tmp;
			tmp=StringCat(tmp,inst);
			free((yyval.Ptree).code);
			(yyval.Ptree).code=StringCat(str,tmp);
			free(str);free(tmp);
		}
		else
		{
			SemanticError("can't compare number with string");
			(yyval.Ptree).code=strdup("");
		}
	}
	else if((yyvsp[-2].Ptree).type==float_ || (yyvsp[0].Ptree).type==float_)
	{
		if((yyvsp[-2].Ptree).type==float_)
			str=strdup("mov.s $f3,$f2\n");
		else //int
			str=strdup("mtc1 $t2,$f3\n");
		tmp=StringCat((yyvsp[-2].Ptree).code,str);
		free(str);
		str=StringCat(tmp,(yyvsp[0].Ptree).code);
		free(tmp);
		if((yyvsp[0].Ptree).type==int_)
		{
			tmp=str;
			str=StringCat(str,"mtc1 $t2,$f2\n");
			free(tmp);
		}
		//str code,temp free
		//f3 has the value of $1, f2 has the value of $2
		if(strcmp((yyvsp[-1].sign2),"<")==0)
			tmp=strdup("c.lt.s $f3,$f2\nbc1t ");
		else if(strcmp((yyvsp[-1].sign2),">")==0)
			tmp=strdup("c.lt.s $f2,$f3\nbc1t ");
		else if(strcmp((yyvsp[-1].sign2),"<=")==0)
			tmp=strdup("c.le.s $f3,$f2\nbc1t ");
		else if(strcmp((yyvsp[-1].sign2),">=")==0)
			tmp=strdup("c.le.s $f2,$f3\nbc1t ");
		else if(strcmp((yyvsp[-1].sign2),"==")==0)
			tmp=strdup("c.eq.s $f3,$f2\nbc1t ");
		else if(strcmp((yyvsp[-1].sign2),"!=")==0)
			tmp=strdup("c.eq.s $f3,$f2\nbc1f ");
		sprintf(inst,"%s\nli $t3,0\nj %s\n%s: li $t3,1\n%s:\n",labelTrue,labelOut,labelTrue,labelOut);
		(yyval.Ptree).code=tmp;
		tmp=StringCat(tmp,inst);
		free((yyval.Ptree).code);
		(yyval.Ptree).code=StringCat(str,tmp);
		free(str);free(tmp);
	}
	(yyval.Ptree).head=StringCat((yyvsp[-2].Ptree).head,(yyvsp[0].Ptree).head);
	free((yyvsp[-2].Ptree).head);free((yyvsp[0].Ptree).head);
	free((yyvsp[-2].Ptree).code);free((yyvsp[0].Ptree).code);
	free(labelTrue);
	free(labelOut);
}
#line 3275 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1378 "cpm.y" /* yacc.c:1646  */
    {
	char* str,*tmp;
	if((yyvsp[-2].Ptree).type==int_ && (yyvsp[0].Ptree).type==int_ )
	{
		if((yyvsp[-1].sign1) =='+')
			str=strdup("add $t2,$t2,$t1\n");
		else
			str=strdup("sub $t2,$t2,$t1\n");
		(yyval.Ptree).type= (yyvsp[-2].Ptree).type;
	}
	else if ((yyvsp[-2].Ptree).type==float_ && (yyvsp[0].Ptree).type==float_)//two floats
	{
		if((yyvsp[-1].sign1) =='+')
			str=strdup("add.s $f2,$f2,$f1\n");
		else
			str=strdup("sub.s $f2,$f2,$f1\n");
		(yyval.Ptree).type=(yyvsp[-2].Ptree).type;
	}
	else if((yyvsp[-2].Ptree).type==float_ && (yyvsp[0].Ptree).type==int_)
	{
		if((yyvsp[-1].sign1) =='+')
			str=strdup("mtc1 $t1, $f1\ncvt.s.w $f1, $f1\nadd.s $f2,$f1,$f2\n");
		else
			str=strdup("mtc1 $t1, $f1\ncvt.s.w $f1, $f1\nsub.s $f2,$f2,$f1\n");
		(yyval.Ptree).type=(yyvsp[-2].Ptree).type;

	}
	else if((yyvsp[-2].Ptree).type==int_ && (yyvsp[0].Ptree).type==float_)
	{
		if((yyvsp[-1].sign1) =='+')
			str=strdup("mtc1 $t2, $f2\ncvt.s.w $f2, $f2\nadd.s $f2,$f2,$f1\n");
		else
			str=strdup("mtc1 $t2, $f2\ncvt.s.w $f2, $f2\nsub.s $f2,$f2,$f1\n");
		(yyval.Ptree).type=(yyvsp[0].Ptree).type;
	}
	else
	{
		SemanticError("cannot calculate");
		str=strdup("");
		(yyval.Ptree).type=string;
	}
	tmp = StringCat((yyvsp[-2].Ptree).code,(yyvsp[0].Ptree).code);
	(yyval.Ptree).code = StringCat(tmp,str);
	free(tmp);
	free(str);
	free((yyvsp[-2].Ptree).code);
	free((yyvsp[0].Ptree).code);
	(yyval.Ptree).head=StringCat((yyvsp[-2].Ptree).head,(yyvsp[0].Ptree).head);
	free((yyvsp[-2].Ptree).head);
	free((yyvsp[0].Ptree).head);
}
#line 3331 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1430 "cpm.y" /* yacc.c:1646  */
    {
	Code c={(yyvsp[0].Ptree).code,(yyvsp[0].Ptree).type,(yyvsp[0].Ptree).head};
	if((yyvsp[0].Ptree).type==int_){
		t1 = getRegister();
		t2 = getRegister();
		c = moveCode(c,t2,t1);
	}else
	if((yyvsp[0].Ptree).type==float_){
		f1 = getFPRegister();
		f2 = getFPRegister();
		c = moveCode(c,t2,t1);
	}
	(yyval.Ptree).code=c.code;
	(yyval.Ptree).type=c.type;
	(yyval.Ptree).head=c.head;
}
#line 3352 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1453 "cpm.y" /* yacc.c:1646  */
    {
	char* str,*tmp;
	if((yyvsp[-2].Ptree).type==int_ && (yyvsp[0].Ptree).type==int_ )
	{
		if((yyvsp[-1].sign1) =='*')
			str=strdup("mul $t1,$t1,$t0\n");
		else
			str=strdup("div $t1,$t0\nmflo $t1\n");
		(yyval.Ptree).type= (yyvsp[-2].Ptree).type;
	}
	else if ((yyvsp[-2].Ptree).type==float_ && (yyvsp[0].Ptree).type==float_)
	{
		if((yyvsp[-1].sign1) =='*')
			str=strdup("mul.s $f1,$f1,$f0\n");
		else
			str=strdup("div.s $f1,$f1,$f0\n");
		(yyval.Ptree).type=(yyvsp[-2].Ptree).type;
	}
	else if((yyvsp[-2].Ptree).type==float_ && (yyvsp[0].Ptree).type==int_)
	{
		if((yyvsp[-1].sign1) =='*')
			str=strdup("mtc1 $t0, $f2\ncvt.s.w $f2, $f2\nmul.s $f1,$f0,$f2\n");
		else
			str=strdup("mtc1 $t0, $f2\ncvt.s.w $f2, $f2\ndiv.s $f1,$f0,$f2\n");
		(yyval.Ptree).type=(yyvsp[-2].Ptree).type;
	}
	else if((yyvsp[-2].Ptree).type==int_ && (yyvsp[0].Ptree).type==float_)
	{
		if((yyvsp[-1].sign1) =='*')
			str=strdup("mtc1 $t1, $f2\ncvt.s.w $f2, $f2\nmul.s $f1,$f2,$f0\n");
		else
			str=strdup("mtc1 $t1, $f2\ncvt.s.w $f2, $f2\ndiv.s $f1,$f2,$f0\n");
		(yyval.Ptree).type=(yyvsp[0].Ptree).type;
	}
	else
	{
		SemanticError("cannot make multiplay string");
		str=strdup("");
		(yyval.Ptree).type=string;
	}
	tmp = StringCat((yyvsp[-2].Ptree).code,(yyvsp[0].Ptree).code);
	(yyval.Ptree).code = StringCat(tmp,str);
	free(tmp);
	free(str);
	free((yyvsp[-2].Ptree).code);
	free((yyvsp[0].Ptree).code);
	(yyval.Ptree).head=StringCat((yyvsp[-2].Ptree).head,(yyvsp[0].Ptree).head);
	free((yyvsp[-2].Ptree).head);
	free((yyvsp[0].Ptree).head);
}
#line 3407 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1504 "cpm.y" /* yacc.c:1646  */
    {
	Code c={(yyvsp[0].Ptree).code,(yyvsp[0].Ptree).type,(yyvsp[0].Ptree).head};
	if((yyvsp[0].Ptree).type==int_){
		t1 = getRegister();
		t2 = getRegister();
		c = moveCode(c,t2,t1);
	}else
	if((yyvsp[0].Ptree).type==float_){
		f1 = getFPRegister();
		f2 = getFPRegister();
		c = moveCode(c,t2,t1);
	}
	(yyval.Ptree).code=c.code;
	(yyval.Ptree).type=c.type;
	(yyval.Ptree).head=c.head;
}
#line 3428 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1526 "cpm.y" /* yacc.c:1646  */
    {
	Code c={(yyvsp[-1].Ptree).code,(yyvsp[-1].Ptree).type,(yyvsp[-1].Ptree).head};
	if((yyvsp[-1].Ptree).type==int_){
		t1 = getRegister();
		t2 = getRegister();
		c = moveCode(c,t2,t1);
	}else
	if((yyvsp[-1].Ptree).type==float_){
		f1 = getFPRegister();
		f2 = getFPRegister();
		c = moveCode(c,t2,t1);
	}
	(yyval.Ptree).code=c.code;
	(yyval.Ptree).type=c.type;
	(yyval.Ptree).head=c.head;
}
#line 3449 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1543 "cpm.y" /* yacc.c:1646  */
    {
	Code c=idCode((yyvsp[0].strVal));
	(yyval.Ptree).code = c.code;
	(yyval.Ptree).head = c.head;
	(yyval.Ptree).type =c.type;
}
#line 3460 "cpm.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1550 "cpm.y" /* yacc.c:1646  */
    {
	Number n ={(yyvsp[0].num).type,(yyvsp[0].num).val.ival};
	Code c= numberCode(n);
	(yyval.Ptree).code = c.code;
	(yyval.Ptree).head = c.head;
	(yyval.Ptree).type =c.type;
}
#line 3472 "cpm.tab.c" /* yacc.c:1646  */
    break;


#line 3476 "cpm.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 1557 "cpm.y" /* yacc.c:1906  */

