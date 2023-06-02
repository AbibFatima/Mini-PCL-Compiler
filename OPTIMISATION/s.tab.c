
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "s.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TS.h"
#include "RS.h"
#include "RS.c"
#include "Quad.h"
#include "Quad.c"
#include "optimisation.h"
#include "optimisation.c"
#include "codeobjet.h"
#include "codeobjet.c"

int yylex();
int yyerror(char *);

extern FILE* yyin;
extern int ligne, col;

/** RS **/ 
int sauv_size;


/* La table des symboles */
int size=0 ;
char sauvVal[20];
char sauvType[20];
char sauvNature[20];

/*****/
char  *sauv_idf;
int nTemp=1;
char tempC[12]="";
char val[12]="";

/** IF ELSE BOUCLE WHILE FOR **/
int fin_pos , else_pos, sauv_debut_while, sauv_deb_for;
char sauv_pas_for[10];




/* Line 189 of yacc.c  */
#line 117 "s.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ENTIER = 258,
     REEL = 259,
     IDF = 260,
     AFF = 261,
     CODE = 262,
     VAR = 263,
     CONST = 264,
     STRUCT = 265,
     INTEGER = 266,
     FLOAT = 267,
     AND = 268,
     OR = 269,
     NOT = 270,
     GREATER = 271,
     LESS = 272,
     GREATEREQUAL = 273,
     LESSEQUAL = 274,
     EQUAL = 275,
     NOTEQUAL = 276,
     IF = 277,
     ELSE = 278,
     WHILE = 279,
     FOR = 280,
     COMMENT = 281,
     SUB = 282,
     ADD = 283,
     DIV = 284,
     MUL = 285
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 44 "s.y"

	char* nom;
	int ent;
	float reel;
	struct {	int type;
				char* res;
				float  val;
			}NT;



/* Line 214 of yacc.c  */
#line 195 "s.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 207 "s.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNRULES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      16,    17,     2,     2,    18,     2,    13,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    11,    12,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    21,     2,    22,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    19,     2,    20,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    14,    15,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    15,    19,    23,    27,    31,    35,    38,
      39,    45,    46,    51,    56,    61,    67,    72,    73,    76,
      80,    82,    84,    86,    89,    90,    93,    95,    97,    99,
     101,   105,   112,   118,   121,   128,   131,   137,   143,   147,
     152,   163,   165,   167,   171,   175,   179,   183,   187,   191,
     194,   198,   202,   204,   206,   210,   214,   218,   222,   224,
     226,   228,   232
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,     5,    19,     8,    19,    43,    20,     7,
      19,    53,    20,    20,    -1,    50,    12,    43,    -1,    44,
      12,    43,    -1,    45,    12,    43,    -1,    48,    12,    43,
      -1,    47,    12,    43,    -1,    36,    43,    -1,    -1,    10,
      19,    49,    20,     5,    -1,    -1,    10,     5,    46,    51,
      -1,     9,     5,     6,     3,    -1,     9,     5,     6,     4,
      -1,    52,     5,    21,     3,    22,    -1,    52,     5,    18,
      49,    -1,    -1,    52,    51,    -1,     5,    18,    51,    -1,
       5,    -1,    14,    -1,    15,    -1,    54,    53,    -1,    -1,
      55,    12,    -1,    56,    -1,    59,    -1,    61,    -1,    36,
      -1,     5,     6,    66,    -1,     5,    21,     3,    22,     6,
      66,    -1,     5,    13,     5,     6,    66,    -1,    57,    20,
      -1,    57,    20,    33,    19,    53,    20,    -1,    58,    53,
      -1,    32,    16,    64,    17,    19,    -1,    60,    17,    19,
      53,    20,    -1,    34,    16,    64,    -1,    62,    19,    53,
      20,    -1,    35,    16,     5,    11,    63,    11,     3,    11,
      63,    17,    -1,     3,    -1,     5,    -1,    65,    31,    65,
      -1,    65,    30,    65,    -1,    65,    27,    65,    -1,    65,
      26,    65,    -1,    65,    28,    65,    -1,    65,    29,    65,
      -1,    25,    64,    -1,    64,    24,    64,    -1,    64,    23,
      64,    -1,    65,    -1,    66,    -1,    66,    38,    66,    -1,
      66,    37,    66,    -1,    66,    39,    66,    -1,    66,    40,
      66,    -1,     5,    -1,     3,    -1,     4,    -1,    16,    66,
      17,    -1,     5,    13,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    71,    72,    73,    74,    75,    76,    77,
      82,    93,    93,    95,   105,   117,   130,   140,   143,   146,
     155,   168,   169,   173,   174,   177,   178,   179,   180,   181,
     185,   200,   208,   220,   224,   230,   238,   245,   251,   260,
     270,   280,   281,   285,   292,   299,   306,   313,   320,   327,
     334,   341,   348,   351,   355,   369,   382,   396,   410,   416,
     421,   426,   430
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENTIER", "REEL", "IDF", "AFF", "CODE",
  "VAR", "CONST", "STRUCT", "':'", "';'", "'.'", "INTEGER", "FLOAT", "'('",
  "')'", "','", "'{'", "'}'", "'['", "']'", "AND", "OR", "NOT", "GREATER",
  "LESS", "GREATEREQUAL", "LESSEQUAL", "EQUAL", "NOTEQUAL", "IF", "ELSE",
  "WHILE", "FOR", "COMMENT", "SUB", "ADD", "DIV", "MUL", "$accept", "s",
  "DECLARATION", "DECLARATION_Struct", "DECLARATION_Struct_Var", "$@1",
  "DECLARATION_Const", "DECLARATION_Tableau", "declarStructFields",
  "DECLARATION_Variables", "liste_idf", "TYPE", "Instructions", "Inst",
  "Inst_AFF", "Inst_IF", "A", "B", "Inst_WHILE", "DEBUT_WHILE", "Inst_FOR",
  "DEBUT_FOR", "INIT", "Condition", "EXP_AR", "expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    58,    59,    46,   266,   267,    40,    41,    44,   123,
     125,    91,    93,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    43,    43,    43,    43,
      44,    46,    45,    47,    47,    48,    49,    49,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    54,    54,    54,
      55,    55,    55,    56,    56,    57,    58,    59,    60,    61,
      62,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    66,    66,    66,    66,    66,    66,
      66,    66,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    11,     3,     3,     3,     3,     3,     2,     0,
       5,     0,     4,     4,     4,     5,     4,     0,     2,     3,
       1,     1,     1,     2,     0,     2,     1,     1,     1,     1,
       3,     6,     5,     2,     6,     2,     5,     5,     3,     4,
      10,     1,     1,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     1,     1,     3,     3,     3,     3,     1,     1,
       1,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     9,     0,     0,    21,
      22,     9,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    17,     8,     0,     9,     9,     9,     9,     9,    20,
      18,     0,     0,     0,     0,     0,     4,     5,     7,     6,
       3,     0,     0,    13,    14,    20,    12,     0,     0,    24,
      19,     0,    10,    17,     0,     0,     0,     0,    29,     0,
      24,     0,    26,     0,    24,    27,     0,    28,     0,    15,
      16,     0,     0,     0,     0,     0,     0,     0,    23,    25,
      33,    35,     0,    24,    59,    60,    58,     0,    30,     0,
       0,     0,     0,    52,    53,    38,     0,     2,     0,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,     0,    39,    62,    61,    55,    54,    56,    57,    32,
       0,    36,    51,    50,    46,    45,    47,    48,    44,    43,
      41,    42,     0,     0,    37,    31,     0,    34,     0,     0,
       0,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    12,    13,    14,    32,    15,    16,    33,    17,
      30,    18,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   142,    92,    93,    94
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -71
static const yytype_int16 yypact[] =
{
      54,     1,    63,    44,   -71,    71,    15,    67,    -2,   -71,
     -71,    15,    74,    79,    83,    84,    85,    86,    94,    95,
     -71,    12,   -71,    93,    15,    15,    15,    15,    15,    55,
     -71,    28,    97,    87,    98,    89,   -71,   -71,   -71,   -71,
     -71,    97,   101,   -71,   -71,    88,   -71,   100,    91,    11,
     -71,    90,   -71,    12,    56,    99,   102,   103,   -71,    96,
      11,   105,   -71,   104,    11,   -71,   106,   -71,    92,   -71,
     -71,     6,   108,   107,     3,     3,   109,   110,   -71,   -71,
     111,   -71,   112,    11,   -71,   -71,   113,     6,   -25,   114,
     115,     3,    51,    52,   -25,    47,   116,   -71,   117,    11,
     118,   120,    27,     6,     6,     6,     6,     6,   122,    47,
     121,     3,     3,     6,     6,     6,     6,     6,     6,    45,
      11,   119,   -71,   -71,   -71,    53,    53,   -71,   -71,   -25,
       6,   -71,   123,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   124,   125,   -71,   -25,   126,   -71,   130,    45,
     129,   -71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,    29,   -71,   -71,   -71,   -71,   -71,    68,   -71,
      17,   -20,   -60,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -27,   -70,   -29,   -69
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      78,    34,    88,    20,    81,    95,    84,    85,    86,    84,
      85,    86,   103,   104,   105,   106,    54,    21,   102,    87,
       3,   109,    87,   100,     7,     8,     9,    10,    91,     9,
      10,    43,    44,    34,   125,   126,   127,   128,   129,   121,
      22,   132,   133,    55,   124,    56,    57,    58,   140,    46,
     141,    11,     5,    36,    37,    38,    39,    40,    50,     1,
     143,   145,    71,     4,   103,   104,   105,   106,   110,    72,
     111,   112,    19,    41,   111,   112,    42,    73,   113,   114,
     115,   116,   117,   118,   134,   135,   136,   137,   138,   139,
       6,    24,   105,   106,    23,    25,    26,    27,    28,    29,
      35,    31,    45,    48,    51,    52,    41,    47,    49,    53,
      90,    83,    69,    89,    96,    74,    77,    79,    75,    76,
     107,    70,   150,    82,    80,   123,   101,   119,   130,   148,
      97,    99,     0,     0,     0,   146,   120,   108,   122,   144,
     131,   149,     0,     0,    98,   147,   151,   112
};

static const yytype_int16 yycheck[] =
{
      60,    21,    71,     5,    64,    75,     3,     4,     5,     3,
       4,     5,    37,    38,    39,    40,     5,    19,    87,    16,
      19,    91,    16,    83,     9,    10,    14,    15,    25,    14,
      15,     3,     4,    53,   103,   104,   105,   106,   107,    99,
      11,   111,   112,    32,    17,    34,    35,    36,     3,    32,
       5,    36,     8,    24,    25,    26,    27,    28,    41,     5,
     120,   130,     6,     0,    37,    38,    39,    40,    17,    13,
      23,    24,     5,    18,    23,    24,    21,    21,    26,    27,
      28,    29,    30,    31,   113,   114,   115,   116,   117,   118,
      19,    12,    39,    40,    20,    12,    12,    12,    12,     5,
       7,     6,     5,     5,     3,     5,    18,    20,    19,    18,
       3,    19,    22,     5,     5,    16,    20,    12,    16,    16,
       6,    53,   149,    17,    20,     5,    13,    11,     6,     3,
      20,    19,    -1,    -1,    -1,    11,    19,    22,    20,    20,
      19,    11,    -1,    -1,    33,    20,    17,    24
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    42,    19,     0,     8,    19,     9,    10,    14,
      15,    36,    43,    44,    45,    47,    48,    50,    52,     5,
       5,    19,    43,    20,    12,    12,    12,    12,    12,     5,
      51,     6,    46,    49,    52,     7,    43,    43,    43,    43,
      43,    18,    21,     3,     4,     5,    51,    20,     5,    19,
      51,     3,     5,    18,     5,    32,    34,    35,    36,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    22,
      49,     6,    13,    21,    16,    16,    16,    20,    53,    12,
      20,    53,    17,    19,     3,     4,     5,    16,    66,     5,
       3,    25,    64,    65,    66,    64,     5,    20,    33,    19,
      53,    13,    66,    37,    38,    39,    40,     6,    22,    64,
      17,    23,    24,    26,    27,    28,    29,    30,    31,    11,
      19,    53,    20,     5,    17,    66,    66,    66,    66,    66,
       6,    19,    64,    64,    65,    65,    65,    65,    65,    65,
       3,     5,    63,    53,    20,    66,    11,    20,     3,    11,
      63,    17
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 67 "s.y"
    { printf ("\nprogramme syntaxiquement juste.\n");YYACCEPT ;;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 82 "s.y"
    { 
															if(doubleDec((yyvsp[(5) - (5)].nom))==1){
																yyerror("Erreur semantique Double declaration");
															} else {
																strcpy(sauvType," ");
																inserer_type((yyvsp[(5) - (5)].nom),sauvType);
																inserer_nature((yyvsp[(5) - (5)].nom),"Structure");
															}
					;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 93 "s.y"
    {strcpy(sauvType,(yyvsp[(2) - (2)].nom)); strcpy(sauvNature,"Structure"); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 95 "s.y"
    {
											if(doubleDec((yyvsp[(2) - (4)].nom))==1){
												yyerror("Erreur semantique Double declaration");
											} else { 	
												inserer_nature((yyvsp[(2) - (4)].nom),"Constante");
												sprintf(sauvVal,"%d",(yyvsp[(4) - (4)].ent));
												inserer_valeur((yyvsp[(2) - (4)].nom),sauvVal);
												inserer_type((yyvsp[(2) - (4)].nom),"INTEGER");
											}
					;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 105 "s.y"
    {
											if(doubleDec((yyvsp[(2) - (4)].nom))==1){
												yyerror("Erreur semantique Double declaration");
											} else { 	
												inserer_nature((yyvsp[(2) - (4)].nom),"Constante");
												sprintf(sauvVal,"%f",(yyvsp[(4) - (4)].reel));
												inserer_valeur((yyvsp[(2) - (4)].nom),sauvVal);
												inserer_type((yyvsp[(2) - (4)].nom),"FLOAT");
											}
					;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 117 "s.y"
    {
													if(doubleDec((yyvsp[(2) - (5)].nom))==1){
														yyerror("Erreur semantique Double declaration");
													} else {
														inserer_type((yyvsp[(2) - (5)].nom),sauvType);
														inserer_nature((yyvsp[(2) - (5)].nom),"Tableau");
														inserer_size((yyvsp[(2) - (5)].nom),(yyvsp[(4) - (5)].ent));
														sauv_size = (yyvsp[(4) - (5)].ent);
													}
					;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 130 "s.y"
    { 	
															if(doubleDec((yyvsp[(2) - (4)].nom))==1){
																	yyerror("Erreur semantique Double declaration");
															} else {
																	inserer_type((yyvsp[(2) - (4)].nom),sauvType);
																	inserer_nature((yyvsp[(2) - (4)].nom),"Variable");
															}
														;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 146 "s.y"
    { 
								empiler_Str(&sauv_var,strdup((yyvsp[(1) - (3)].nom)));
								if(doubleDec((yyvsp[(1) - (3)].nom))==1){
									yyerror("Erreur semantique Double declaration");
								} else { 
							        inserer_nature((yyvsp[(1) - (3)].nom),"Variable");
									inserer_type((yyvsp[(1) - (3)].nom),sauvType);      
								}
							;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 155 "s.y"
    { 	
						empiler_Str(&sauv_var,strdup((yyvsp[(1) - (1)].nom)));
						if(doubleDec((yyvsp[(1) - (1)].nom))==1){
								yyerror("Erreur semantique Double declaration");
						} else { 
						        inserer_nature((yyvsp[(1) - (1)].nom),"Variable");
								inserer_type((yyvsp[(1) - (1)].nom),sauvType);
						}
					;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 168 "s.y"
    { strcpy(sauvType,"INTEGER"); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 169 "s.y"
    { strcpy(sauvType,"FLOAT"); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 185 "s.y"
    {
									dec((yyvsp[(1) - (3)].nom)); 
									modifConstante((yyvsp[(1) - (3)].nom));
									
									if (typeIdf((yyvsp[(1) - (3)].nom))!=(yyvsp[(3) - (3)].NT).type) 
										{
											if (typeIdf((yyvsp[(1) - (3)].nom)) != 2)  yyerror("erreur semantique incompatibilite des types affectation."); 
										}				
									
									quad (":=",(yyvsp[(3) - (3)].NT).res,"",(yyvsp[(1) - (3)].nom));
									
									sprintf(sauvVal,"%f",(yyvsp[(3) - (3)].NT).val);
									inserer_valeur((yyvsp[(1) - (3)].nom),sauvVal);

								;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 200 "s.y"
    {
									decTab((yyvsp[(1) - (6)].nom));
									modifConstante((yyvsp[(1) - (6)].nom));
									if (typeIdf((yyvsp[(1) - (6)].nom))!=(yyvsp[(6) - (6)].NT).type) 
										yyerror("erreur semantique incompatibilite des types affectation."); 
									if (((yyvsp[(3) - (6)].ent)) > sauv_size)
									    yyerror("erreur semantique depassement de la taille du tableau."); 
								;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 208 "s.y"
    { 
				                            if (decStruct((yyvsp[(1) - (5)].nom)) == 0) yyerror("erreur semantique structure n'existe pas ."); 
											else {
												dec((yyvsp[(3) - (5)].nom));
												modifConstante((yyvsp[(3) - (5)].nom));	 
                                                if (typeIdf((yyvsp[(3) - (5)].nom))!=(yyvsp[(5) - (5)].NT).type)  
													yyerror("erreur semantique incompatibilite des types affectation.");
											}							 
			;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 220 "s.y"
    {	
					indq--; 
					fin_pos = depiler_qc(&pile1);
				;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 224 "s.y"
    {
											fin_pos = depiler_qc(&pile1); 
											q[fin_pos].op1= ToSTR(indq);
										;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 230 "s.y"
    { 
						else_pos = depiler_qc(&pile1); 
						q[else_pos].op1= ToSTR(indq+1); 
						empiler_qc(&pile1, indq); 
						quad("BR","","","");
					;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 238 "s.y"
    {
						empiler_qc(&pile1, indq); 
						quad("BZ","",strdup((yyvsp[(3) - (5)].NT).res),"");   //BNZ ?????????
					;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 245 "s.y"
    {
									quad("BR",ToSTR(sauv_debut_while),"",""); 
									q[sauv_debut_while].op1= ToSTR(indq); 
			;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 251 "s.y"
    { 
							empiler_qc(&pile2,indq); 
							sauv_debut_while= depiler_qc(&pile2); 	
							quad("BZ","",strdup((yyvsp[(3) - (3)].NT).res),"");
			;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 260 "s.y"
    { 
           					sauv_idf = depiler(&sauv_var); 
							quad("+",strdup(sauv_idf),strdup(sauv_pas_for),strdup(sauv_idf)); 
           					sauv_deb_for = depiler_qc(&pileFOR); 
							quad("BR",ToSTR(sauv_deb_for),"",""); 
							q[sauv_deb_for].op1= ToSTR(indq); 
         	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 270 "s.y"
    { 
            				dec((yyvsp[(3) - (10)].nom)); 
							quad("=",(yyvsp[(5) - (10)].NT).res,"",(yyvsp[(3) - (10)].nom)); 
							empiler_qc(&pileFOR,indq); 
							quad("BG","",(yyvsp[(3) - (10)].nom),(yyvsp[(9) - (10)].NT).res); 
							empiler_Str(&sauv_var, (yyvsp[(3) - (10)].nom));
							sprintf(sauv_pas_for,"%d",(yyvsp[(7) - (10)].ent));
        	;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 280 "s.y"
    { (yyval.NT).res = ToSTR((yyvsp[(1) - (1)].ent)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 281 "s.y"
    { (yyval.NT).res = strdup((yyvsp[(1) - (1)].nom));  dec((yyvsp[(1) - (1)].nom)); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 285 "s.y"
    {
								sprintf(tempC, "T%d",nTemp);
								nTemp++;
								(yyval.NT).res=strdup(tempC);
								tempC[0]='\0'; 
								createQuadCompare(1,(yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res,(yyval.NT).res);
							;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 292 "s.y"
    {
								sprintf(tempC, "T%d",nTemp);
								nTemp++;
								(yyval.NT).res=strdup(tempC);
								tempC[0]='\0'; 
								createQuadCompare(2,(yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res,(yyval.NT).res);
							;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 299 "s.y"
    {
								sprintf(tempC, "T%d",nTemp);
								nTemp++;
								(yyval.NT).res=strdup(tempC);
								tempC[0]='\0'; 
								createQuadCompare(3,(yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res,(yyval.NT).res);
							;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 306 "s.y"
    { 
								sprintf(tempC, "T%d",nTemp);
								nTemp++;
								(yyval.NT).res=strdup(tempC);
								tempC[0]='\0'; 
								createQuadCompare(4,(yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res,(yyval.NT).res);
							;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 313 "s.y"
    {
								sprintf(tempC, "T%d",nTemp);
								nTemp++;
								(yyval.NT).res=strdup(tempC);
								tempC[0]='\0'; 
								createQuadCompare(5,(yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res,(yyval.NT).res);
							;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 320 "s.y"
    {
								sprintf(tempC, "T%d",nTemp);
								nTemp++;
								(yyval.NT).res=strdup(tempC);
								tempC[0]='\0'; 
								createQuadCompare(6,(yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res,(yyval.NT).res);
							;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 327 "s.y"
    {
							sprintf(tempC, "T%d",nTemp);
							nTemp++;
							(yyval.NT).res=strdup(tempC);
							tempC[0]='\0'; 
							createQuadLogic(1,(yyvsp[(2) - (2)].NT).res,NULL,(yyval.NT).res);
						;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 334 "s.y"
    {
										sprintf(tempC, "T%d",nTemp);
										nTemp++;
										(yyval.NT).res=strdup(tempC);
										tempC[0]='\0'; 
										createQuadLogic(2,(yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res,(yyval.NT).res);
									;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 341 "s.y"
    {
											sprintf(tempC, "T%d",nTemp);
											nTemp++;
											(yyval.NT).res=strdup(tempC);
											tempC[0]='\0'; 
											createQuadLogic (3,(yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res,(yyval.NT).res);
										;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 351 "s.y"
    { (yyval.NT).res = (yyvsp[(1) - (1)].NT).res; ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 355 "s.y"
    { 
										if ((yyvsp[(1) - (3)].NT).type!=(yyvsp[(3) - (3)].NT).type) 
											yyerror ("erreur semantique incompatibilite des types"); 
										sprintf(tempC, "T%d",nTemp);
										nTemp++;
										
										(yyval.NT).res=strdup(tempC);	
										tempC[0]='\0'; 
										quad ("+",(yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res,(yyval.NT).res);
										float resultat = (yyvsp[(1) - (3)].NT).val + (yyvsp[(3) - (3)].NT).val;
										(yyval.NT).type = (yyvsp[(1) - (3)].NT).type;
                                        (yyval.NT).val = resultat;
										//printf("Resultat de l'addition : %.2f\n", resultat);
									;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 369 "s.y"
    { 
									if ((yyvsp[(1) - (3)].NT).type!=(yyvsp[(3) - (3)].NT).type) 
										yyerror ("erreur semantique incompatibilite des types"); 
									sprintf(tempC, "T%d",nTemp);
									nTemp++;
									(yyval.NT).res=strdup(tempC);	
									tempC[0]='\0'; 
									quad ("-",(yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res,(yyval.NT).res);
									float resultat = (yyvsp[(1) - (3)].NT).val - (yyvsp[(3) - (3)].NT).val;
									(yyval.NT).type = (yyvsp[(1) - (3)].NT).type;
                                    (yyval.NT).val = resultat;
									//printf("Resultat de la soustraction : %.2f\n", resultat);
								;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 382 "s.y"
    {   if ((yyvsp[(3) - (3)].NT).val==0) {yyerror("erreur semantique division sur 0") ;}
									if ((yyvsp[(1) - (3)].NT).type!=(yyvsp[(3) - (3)].NT).type) 
										yyerror ("erreur semantique incompatibilite des types"); 
									sprintf(tempC, "T%d",nTemp);
									nTemp++;
									(yyval.NT).res=strdup(tempC);	
									tempC[0]='\0'; 
									quad ("/",(yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res,(yyval.NT).res);
									float resultat = (yyvsp[(1) - (3)].NT).val / (yyvsp[(3) - (3)].NT).val;
									(yyval.NT).type = (yyvsp[(1) - (3)].NT).type;
                                    (yyval.NT).val = resultat;
									//printf("Resultat de la division : %.2f\n", resultat);
									
								;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 396 "s.y"
    { 
									if ((yyvsp[(1) - (3)].NT).type!=(yyvsp[(3) - (3)].NT).type) 
										yyerror ("erreur semantique incompatibilite des types"); 
									sprintf(tempC, "T%d",nTemp);
									nTemp++;
									(yyval.NT).res=strdup(tempC);	
									tempC[0]='\0'; 
									quad ("*",(yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res,(yyval.NT).res);
									float resultat = (yyvsp[(1) - (3)].NT).val * (yyvsp[(3) - (3)].NT).val;
									(yyval.NT).type = (yyvsp[(1) - (3)].NT).type;
                                    (yyval.NT).val = resultat;
									//printf("Resultat de la multiplication : %.2f\n", resultat);

								;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 410 "s.y"
    { 
			dec((yyvsp[(1) - (1)].nom)); 
			(yyval.NT).type=typeIdf((yyvsp[(1) - (1)].nom)); 
			(yyval.NT).res=strdup((yyvsp[(1) - (1)].nom));      
			(yyval.NT).val=1;
		;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 416 "s.y"
    { 
				(yyval.NT).type=1;
				sprintf(val, "%d",(yyvsp[(1) - (1)].ent)); (yyval.NT).res=strdup(val); 
				(yyval.NT).val=(yyvsp[(1) - (1)].ent); 
			;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 421 "s.y"
    { 
				(yyval.NT).type=2; 
				sprintf(val, "%f",(yyvsp[(1) - (1)].reel)); (yyval.NT).res=strdup(val);  
				(yyval.NT).val=(yyvsp[(1) - (1)].reel);    
			;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 426 "s.y"
    { 
			(yyval.NT).type=(yyvsp[(2) - (3)].NT).type; 
			(yyval.NT).res=(yyvsp[(2) - (3)].NT).res; 
		;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 430 "s.y"
    { 
			if (decStruct((yyvsp[(1) - (3)].nom)) == 0 ) yyerror ("erreur semantique structure n'existe pas"); 
			else dec((yyvsp[(3) - (3)].nom)); 	
		;}
    break;



/* Line 1455 of yacc.c  */
#line 2069 "s.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 435 "s.y"

int yyerror (char* msg){
    printf ("%s : ligne %d, colonne %d \n",msg,ligne,col); 
	exit (0);
	return 1;
}

int main (){ 
    yyin = fopen("test.txt", "r");
    yyparse();
	
	//printf("\n------------------ LA TABLE DES SYMBOLES ----------------------\n");
	//afficherTS();
	printf("\n------------------ LES QUADRUPLETS AVANT OPTIMISATION ----------------------\n");
	afficherQuad();
	//optimiser les quadruplets
	optimisation();
	printf("\n------------------LES QUADRUPLETS APRES OPTIMISATION----------------------\n");
	afficherQuad();
	printf("\n------------------ GENERATION DU CODE OBJET ----------------------\n");
	assembler();

    fclose (yyin);
}
