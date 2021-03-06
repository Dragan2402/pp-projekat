
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
#line 1 "micko.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;

  int fun_idx = -1;
  int current_class_idx = -1;
  int current_instance_idx= -1;
  int instance_declaration_arg_counter = 0;

  int fcall_idx = -1;
  int instance_index=-1;
  int lab_num = -1;
  int return_count=0;
  int* parameter_map_function[128];


  int arguments_array[128];
  int* parameter_map[128];
  int arg_counter = 0;
  int arg_position = 1;
  int isClass = 0;
  int attributes_counter=0;
  FILE *output;


/* Line 189 of yacc.c  */
#line 115 "micko.tab.c"

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
     _TYPE = 258,
     _IF = 259,
     _ELSE = 260,
     _RETURN = 261,
     _CLASS = 262,
     _NEW = 263,
     _ID = 264,
     _INT_NUMBER = 265,
     _UINT_NUMBER = 266,
     _LPAREN = 267,
     _RPAREN = 268,
     _LBRACKET = 269,
     _RBRACKET = 270,
     _ASSIGN = 271,
     _SEMICOLON = 272,
     _DOT = 273,
     _COMMA = 274,
     _AROP = 275,
     _RELOP = 276,
     ONLY_IF = 277
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 42 "micko.y"

  int i;
  char *s;



/* Line 214 of yacc.c  */
#line 180 "micko.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 192 "micko.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   115

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  23
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNRULES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     5,    10,    11,    13,    15,    18,
      19,    20,    30,    31,    34,    35,    40,    41,    43,    45,
      48,    49,    50,    60,    61,    63,    65,    69,    72,    73,
      76,    81,    82,    90,    91,    93,    95,    99,   102,   103,
     109,   110,   113,   117,   118,   121,   123,   125,   127,   129,
     131,   133,   134,   140,   141,   142,   143,   144,   145,   161,
     162,   164,   166,   170,   172,   176,   181,   183,   187,   189,
     193,   195,   197,   201,   203,   205,   206,   212,   213,   215,
     217,   221,   223,   225,   229,   230,   231,   239,   243,   247
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      24,     0,    -1,    -1,    -1,    25,    27,    26,    36,    -1,
      -1,    28,    -1,    29,    -1,    28,    29,    -1,    -1,    -1,
       7,     9,    30,    14,    32,    37,    31,    35,    15,    -1,
      -1,    32,    33,    -1,    -1,     3,     9,    34,    17,    -1,
      -1,    36,    -1,    45,    -1,    36,    45,    -1,    -1,    -1,
       9,    38,    12,    40,    13,    14,    43,    39,    15,    -1,
      -1,    41,    -1,    42,    -1,    41,    19,    42,    -1,     3,
       9,    -1,    -1,    43,    44,    -1,     9,    16,     9,    17,
      -1,    -1,     3,     9,    46,    12,    47,    13,    50,    -1,
      -1,    48,    -1,    49,    -1,    48,    19,    49,    -1,     3,
       9,    -1,    -1,    14,    52,    51,    54,    15,    -1,    -1,
      52,    53,    -1,     3,     9,    17,    -1,    -1,    54,    55,
      -1,    67,    -1,    56,    -1,    68,    -1,    77,    -1,    58,
      -1,    82,    -1,    -1,     9,    57,    18,    72,    17,    -1,
      -1,    -1,    -1,    -1,    -1,     7,     9,    59,     9,    60,
      16,     8,     9,    61,    12,    62,    64,    63,    13,    17,
      -1,    -1,    65,    -1,    66,    -1,    65,    19,    66,    -1,
      69,    -1,    14,    54,    15,    -1,     9,    16,    69,    17,
      -1,    70,    -1,    69,    20,    70,    -1,    71,    -1,     9,
      18,    72,    -1,     9,    -1,    72,    -1,    12,    69,    13,
      -1,    10,    -1,    11,    -1,    -1,     9,    73,    12,    74,
      13,    -1,    -1,    75,    -1,    76,    -1,    75,    19,    76,
      -1,    69,    -1,    78,    -1,    78,     5,    55,    -1,    -1,
      -1,     4,    12,    79,    81,    80,    13,    55,    -1,    69,
      21,    69,    -1,     6,    69,    17,    -1,     6,    17,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    78,    78,    85,    87,    91,    92,    96,
     108,    96,   118,   120,   124,   124,   154,   156,   159,   160,
     164,   177,   164,   186,   188,   192,   193,   197,   233,   235,
     238,   261,   260,   321,   322,   326,   327,   331,   367,   366,
     377,   379,   383,   417,   419,   423,   424,   425,   426,   427,
     428,   432,   432,   440,   445,   454,   461,   462,   440,   483,
     485,   489,   490,   494,   505,   509,   544,   546,   565,   566,
     577,   595,   601,   606,   609,   615,   614,   655,   658,   663,
     664,   668,   691,   694,   700,   705,   699,   718,   728,   738
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_TYPE", "_IF", "_ELSE", "_RETURN",
  "_CLASS", "_NEW", "_ID", "_INT_NUMBER", "_UINT_NUMBER", "_LPAREN",
  "_RPAREN", "_LBRACKET", "_RBRACKET", "_ASSIGN", "_SEMICOLON", "_DOT",
  "_COMMA", "_AROP", "_RELOP", "ONLY_IF", "$accept", "program", "$@1",
  "$@2", "classes_list", "classes_existing_list", "class", "$@3", "$@4",
  "attributes_list", "attribute", "$@5", "functions_list", "function_list",
  "constructor", "$@6", "$@7", "constructor_parameters",
  "constructor_existing_parameters", "constructor_parameter",
  "attribute_assign_list", "attribute_assign", "function", "$@8",
  "parameter_list", "parameters", "parameter", "body", "$@9",
  "variable_list", "variable", "statement_list", "statement",
  "class_function", "$@10", "class_declaration", "$@11", "$@12", "$@13",
  "$@14", "$@15", "class_argument_list", "class_arguments",
  "class_argument", "compound_statement", "assignment_statement",
  "num_exp", "exp", "literal", "function_call", "$@16", "argument_list",
  "arguments", "argument", "if_statement", "if_part", "@17", "$@18",
  "rel_exp", "return_statement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    23,    25,    26,    24,    27,    27,    28,    28,    30,
      31,    29,    32,    32,    34,    33,    35,    35,    36,    36,
      38,    39,    37,    40,    40,    41,    41,    42,    43,    43,
      44,    46,    45,    47,    47,    48,    48,    49,    51,    50,
      52,    52,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    57,    56,    59,    60,    61,    62,    63,    58,    64,
      64,    65,    65,    66,    67,    68,    69,    69,    70,    70,
      70,    70,    70,    71,    71,    73,    72,    74,    74,    75,
      75,    76,    77,    77,    79,    80,    78,    81,    82,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     4,     0,     1,     1,     2,     0,
       0,     9,     0,     2,     0,     4,     0,     1,     1,     2,
       0,     0,     9,     0,     1,     1,     3,     2,     0,     2,
       4,     0,     7,     0,     1,     1,     3,     2,     0,     5,
       0,     2,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     0,     5,     0,     0,     0,     0,     0,    15,     0,
       1,     1,     3,     1,     3,     4,     1,     3,     1,     3,
       1,     1,     3,     1,     1,     0,     5,     0,     1,     1,
       3,     1,     1,     3,     0,     0,     7,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,     0,     3,     6,     7,     9,     0,
       8,     0,     0,     4,    18,    12,    31,    19,     0,     0,
       0,    20,    13,    10,    33,    14,     0,    16,     0,     0,
      34,    35,     0,    23,     0,    17,    37,     0,     0,    15,
       0,     0,    24,    25,    11,    40,    32,    36,    27,     0,
       0,    38,    28,    26,     0,    43,    41,    21,     0,     0,
       0,     0,    29,    42,     0,     0,     0,    51,    43,    39,
      44,    46,    49,    45,    47,    48,    82,    50,     0,    22,
      84,    70,    73,    74,     0,    89,     0,    66,    68,    71,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,     0,     0,     0,     0,    64,    83,    30,     0,    85,
      75,    69,    77,    72,    67,    54,    65,     0,     0,     0,
      81,     0,    78,    79,     0,    52,    87,     0,    76,     0,
       0,    86,    80,     0,    55,     0,    56,    59,    57,    60,
      61,    63,     0,     0,     0,    62,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     9,     5,     6,     7,    11,    27,    18,
      22,    32,    34,    13,    23,    26,    61,    41,    42,    43,
      57,    62,    14,    19,    29,    30,    31,    46,    55,    51,
      56,    59,    70,    71,    92,    72,   102,   124,   135,   137,
     142,   138,   139,   140,    73,    74,   120,    87,    88,    89,
      98,   121,   122,   123,    75,    76,    96,   119,   109,    77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -94
static const yytype_int8 yypact[] =
{
     -94,    40,    35,   -94,    32,   -94,    35,   -94,   -94,    41,
     -94,    36,    43,    41,   -94,   -94,   -94,   -94,    24,    44,
      46,   -94,   -94,   -94,    54,   -94,    47,    41,    49,    48,
      45,   -94,    50,    57,    51,    41,   -94,    55,    54,   -94,
      53,    52,    56,   -94,   -94,   -94,   -94,   -94,   -94,    59,
      57,    60,   -94,   -94,    61,   -94,   -94,    62,    63,    -1,
      58,    64,   -94,   -94,    65,    26,    67,    66,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,    76,   -94,    74,   -94,
     -94,    27,   -94,   -94,    37,   -94,    12,   -94,   -94,   -94,
     -94,    37,    68,     3,    16,    70,    37,    75,    73,    -9,
     -94,    37,    79,    34,    75,   -94,   -94,   -94,    -5,   -94,
     -94,   -94,    37,   -94,   -94,   -94,   -94,    72,    37,    77,
      71,    80,    78,   -94,    82,   -94,    71,    16,   -94,    37,
      84,   -94,   -94,    85,   -94,    83,   -94,    37,   -94,    81,
     -94,    71,    86,    37,    87,   -94,   -94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   -94,   -94,   -94,   -94,    90,   -94,   -94,   -94,
     -94,   -94,   -94,    88,   -94,   -94,   -94,   -94,   -94,    18,
     -94,   -94,   -11,   -94,   -94,   -94,    69,   -94,   -94,   -94,
     -94,    33,   -93,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -41,   -94,   -94,   -65,     2,   -94,   -76,
     -94,   -94,   -94,   -24,   -94,   -94,   -94,   -94,   -94,   -94
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -76
static const yytype_int16 yytable[] =
{
      86,   106,    17,    64,   113,    65,    66,    64,    67,    65,
      66,   101,    67,    68,    69,   101,   118,    68,   105,    99,
      64,   111,    65,    66,    17,    67,   103,    20,   117,   100,
      68,   108,   101,    21,   131,    81,    82,    83,    84,   -75,
       3,     8,     4,    85,    12,    97,    81,    82,    83,    84,
      15,   116,    16,   126,   101,    25,    24,    28,    36,    33,
      40,    37,    48,    54,    38,    49,    44,    39,    53,    45,
      58,    60,   141,    52,    78,    50,    90,    80,   141,    79,
      63,    94,    91,    95,   110,   112,   104,   107,   115,   125,
     127,   101,   133,   128,   134,   136,    10,   129,   130,   144,
     143,    93,   145,   114,   146,   132,     0,    47,     0,     0,
       0,     0,     0,     0,     0,    35
};

static const yytype_int16 yycheck[] =
{
      65,    94,    13,     4,    13,     6,     7,     4,     9,     6,
       7,    20,     9,    14,    15,    20,    21,    14,    15,    84,
       4,    97,     6,     7,    35,     9,    91,     3,   104,    17,
      14,    96,    20,     9,   127,     9,    10,    11,    12,    12,
       0,     9,     7,    17,     3,    18,     9,    10,    11,    12,
      14,    17,     9,   118,    20,     9,    12,     3,     9,    12,
       3,    13,     9,     3,    19,    13,    15,    17,    50,    14,
       9,     9,   137,    14,    16,    19,     9,    12,   143,    15,
      17,     5,    16,     9,     9,    12,    18,    17,     9,    17,
      13,    20,     8,    13,     9,    12,     6,    19,    16,    13,
      19,    68,   143,   101,    17,   129,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    25,     0,     7,    27,    28,    29,     9,    26,
      29,    30,     3,    36,    45,    14,     9,    45,    32,    46,
       3,     9,    33,    37,    12,     9,    38,    31,     3,    47,
      48,    49,    34,    12,    35,    36,     9,    13,    19,    17,
       3,    40,    41,    42,    15,    14,    50,    49,     9,    13,
      19,    52,    14,    42,     3,    51,    53,    43,     9,    54,
       9,    39,    44,    17,     4,     6,     7,     9,    14,    15,
      55,    56,    58,    67,    68,    77,    78,    82,    16,    15,
      12,     9,    10,    11,    12,    17,    69,    70,    71,    72,
       9,    16,    57,    54,     5,     9,    79,    18,    73,    69,
      17,    20,    59,    69,    18,    15,    55,    17,    69,    81,
       9,    72,    12,    13,    70,     9,    17,    72,    21,    80,
      69,    74,    75,    76,    60,    17,    69,    13,    13,    19,
      16,    55,    76,     8,     9,    61,    12,    62,    64,    65,
      66,    69,    63,    19,    13,    66,    17
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
#line 78 "micko.y"
    { isClass=1; ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 78 "micko.y"
    { isClass=0; ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 79 "micko.y"
    {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 96 "micko.y"
    {
        
        current_class_idx = lookup_symbol((yyvsp[(2) - (2)].s), CLAS);
        if(current_class_idx == NO_INDEX){
          current_class_idx = insert_symbol((yyvsp[(2) - (2)].s), CLAS, NO_TYPE, 0, NO_ATR,NO_ATR);
          int* param_types = (int*) malloc(sizeof(int)*128);
          parameter_map[current_class_idx] = param_types;
          }
        else 
          err("redefinition of class '%s'", (yyvsp[(2) - (2)].s));
        attributes_counter=0;
  ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 108 "micko.y"
    { 
       if( arg_counter != get_atr1(current_class_idx)){
        err("Invalid number of arguments in constructor, arguments '%d', attributes '%d'",arg_counter,attributes_counter);
       }
       
     ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 113 "micko.y"
    {
      arg_counter=0;
      attributes_counter=0;
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 124 "micko.y"
    {
      {
        if((yyvsp[(1) - (2)].i) == VOID)
          err("attribute '%s' cannot be void",(yyvsp[(2) - (2)].s));
        int atr_idx = lookup_symbol((yyvsp[(2) - (2)].s), ATR);
        if(atr_idx == NO_INDEX){
          int idx=insert_symbol((yyvsp[(2) - (2)].s), ATR, (yyvsp[(1) - (2)].i), attributes_counter, NO_ATR,current_class_idx);
          code("\n%s:\n\t\tWORD\t1",(yyvsp[(2) - (2)].s));
          attributes_counter = get_atr1(current_class_idx);
          int* param_types = parameter_map[current_class_idx];
          param_types[attributes_counter] = (yyvsp[(1) - (2)].i);
          attributes_counter += 1;
          set_atr1(current_class_idx, attributes_counter); 
           }
        else 
         if(get_atr3(atr_idx)==current_class_idx){
           err("redefinition of '%s'", (yyvsp[(2) - (2)].s));
          }else{
            int idx=insert_symbol((yyvsp[(2) - (2)].s), ATR, (yyvsp[(1) - (2)].i), attributes_counter, NO_ATR,current_class_idx);
            code("\n%s:\n\t\tWORD\t1", (yyvsp[(2) - (2)].s));
            attributes_counter = get_atr1(current_class_idx);
            int* param_types = parameter_map[current_class_idx];
            param_types[attributes_counter] = (yyvsp[(1) - (2)].i);
            attributes_counter += 1;
            set_atr1(current_class_idx, attributes_counter); 
          }
      }

  ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 164 "micko.y"
    {
    char* class_name = get_name(current_class_idx);
    char* id = (yyvsp[(1) - (1)].s);
    int ret = strcmp(class_name,id);
    if (ret < 0 ){
      err("Inavlid constructor name '%s', class name '%s'",(yyvsp[(1) - (1)].s),get_name(current_class_idx));
    }
    arg_counter = 0 ;
    arg_position=1;
    code("\n%s:", (yyvsp[(1) - (1)].s));
    code("\n\t\tPUSH\t%%14");
    code("\n\t\tMOV \t%%15,%%14");
    
  ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 177 "micko.y"
    {  
    code("\n\t\tJMP \t@%s_exit", (yyvsp[(1) - (7)].s));  
    code("\n@%s_exit:", (yyvsp[(1) - (7)].s));
    code("\n\t\tMOV \t%%14,%%15");
    code("\n\t\tPOP \t%%14");
    code("\n\t\tRET");
    clear_symbols(get_last_element() - arg_counter +1);
  ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 198 "micko.y"
    {
      if((yyvsp[(1) - (2)].i) == VOID)
          err("attribute '%s' cannot be void",(yyvsp[(2) - (2)].s));
      if(lookup_symbol((yyvsp[(2) - (2)].s), PAR) != -1){
        err("Redefinition of parameter %s ", (yyvsp[(2) - (2)].s));
      }else{
        int indx_atr=lookup_symbol((yyvsp[(2) - (2)].s),ATR);
        if(indx_atr != NO_INDEX){
          if(get_atr3(indx_atr) == current_class_idx){
            err("Redefinition of attribute %s ", (yyvsp[(2) - (2)].s));
          }else{
            int* param_types = parameter_map[current_class_idx];
            if(param_types[arg_counter] != (yyvsp[(1) - (2)].i)){
              err("inavlid constructor parameter, paramtere type '%d', attribute type '%d'", (yyvsp[(1) - (2)].i), param_types[arg_counter]);
            }
            insert_symbol((yyvsp[(2) - (2)].s), PAR, (yyvsp[(1) - (2)].i), arg_position , NO_ATR,current_class_idx);
            ++arg_position;
            ++arg_counter;

          }
        }else{
          int* param_types = parameter_map[current_class_idx];
          if(param_types[arg_counter] != (yyvsp[(1) - (2)].i)){
            err("inavlid constructor parameter, paramtere type '%d', attribute type '%d'",(yyvsp[(1) - (2)].i),param_types[arg_counter]);
          }
          insert_symbol((yyvsp[(2) - (2)].s), PAR, (yyvsp[(1) - (2)].i), arg_position, NO_ATR,current_class_idx);
          ++arg_position;
          ++arg_counter;

        }
      }
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 239 "micko.y"
    {
      int idx = lookup_symbol((yyvsp[(1) - (4)].s), ATR);
      if(idx == NO_INDEX)
        err("unknown attribute '%s' in class", (yyvsp[(1) - (4)].s));
      else{
        if(get_atr3(idx) == current_class_idx){
          int idx_par = lookup_symbol((yyvsp[(3) - (4)].s),PAR);
          if(get_type(idx) != get_type(idx_par))
            err("incompatible types in assignment of attribute");
          if(get_atr3(idx_par)!=current_class_idx)
            err("parametar '%s' not from this class",(yyvsp[(3) - (4)].s));
          gen_mov(idx_par, idx);
        }else{
          err("unknown attribute '%s' in class", (yyvsp[(1) - (4)].s));
        }
      }
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 261 "micko.y"
    {
        if (isClass==0){
            fun_idx = lookup_symbol((yyvsp[(2) - (2)].s), FUN);
            if(fun_idx == NO_INDEX){
              int* param_types = (int*) malloc(sizeof(int)*128);
              fun_idx = insert_symbol((yyvsp[(2) - (2)].s), FUN, (yyvsp[(1) - (2)].i), NO_ATR, NO_ATR,NO_ATR);
              parameter_map_function[fun_idx] = param_types;
            }
            else
              if(get_atr3(fun_idx) == NO_ATR){
                int* param_types = (int*) malloc(sizeof(int)*128);
                fun_idx = insert_symbol((yyvsp[(2) - (2)].s), FUN, (yyvsp[(1) - (2)].i), NO_ATR, NO_ATR,NO_ATR);
                parameter_map_function[fun_idx] = param_types;

              }else{
                err("redefinition of function '%s'", (yyvsp[(2) - (2)].s));
                }

            code("\n%s:", (yyvsp[(2) - (2)].s));
            code("\n\t\tPUSH\t%%14");
            code("\n\t\tMOV \t%%15,%%14");
        }
        else{
            fun_idx = lookup_symbol((yyvsp[(2) - (2)].s), FUN);
            if(fun_idx == NO_INDEX){
              int* param_types = (int*) malloc(sizeof(int)*128);
              fun_idx = insert_symbol((yyvsp[(2) - (2)].s), FUN, (yyvsp[(1) - (2)].i), NO_ATR, NO_ATR,current_class_idx);   
              parameter_map_function[fun_idx] = param_types;
            }
            else {
              if(get_atr3(fun_idx) == current_class_idx){
                err("redefinition of function '%s' in class '%s", (yyvsp[(2) - (2)].s), get_name(current_class_idx));
              }else{
                  int* param_types = (int*) malloc(sizeof(int)*128);
                  fun_idx = insert_symbol((yyvsp[(2) - (2)].s), FUN, (yyvsp[(1) - (2)].i), NO_ATR, NO_ATR,current_class_idx);
                  parameter_map_function[fun_idx] = param_types;
              }
            }
            code("\n%s:", (yyvsp[(2) - (2)].s));
            code("\n\t\tPUSH\t%%14");
            code("\n\t\tMOV \t%%15,%%14");
            arg_position=1;
        }
      ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 306 "micko.y"
    {
        if( (return_count == 0) && (get_type(fun_idx) != VOID) )
          warn("Function should return a value");
        return_count = 0;
        clear_symbols(fun_idx + 1);
        var_num = 0;
        
        code("\n@%s_exit:", (yyvsp[(2) - (7)].s));
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 321 "micko.y"
    { set_atr1(fun_idx, 0); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 332 "micko.y"
    {

        
        if(isClass==0){
          if(lookup_symbol((yyvsp[(2) - (2)].s), PAR) != -1){
            err("Redefinition of parameter %s ", (yyvsp[(2) - (2)].s));
          }
          insert_symbol((yyvsp[(2) - (2)].s), PAR, (yyvsp[(1) - (2)].i), arg_position, NO_ATR,NO_ATR);
          int num_params = get_atr1(fun_idx);

          int* param_types = parameter_map_function[fun_idx];
          param_types[num_params] = (yyvsp[(1) - (2)].i);
          num_params += 1;
          arg_position +=1;
          set_atr1(fun_idx, num_params);
        }else{
        if(lookup_symbol((yyvsp[(2) - (2)].s), PAR) != -1){
          err("Redefinition of parameter %s ", (yyvsp[(2) - (2)].s));
          }
        int idx = insert_symbol((yyvsp[(2) - (2)].s), PAR, (yyvsp[(1) - (2)].i), arg_position, NO_ATR,current_class_idx);
        int num_params = get_atr1(fun_idx);

        int* param_types = parameter_map_function[fun_idx];
        param_types[num_params] = (yyvsp[(1) - (2)].i);
        num_params += 1;

        arg_position +=1;
        set_atr1(fun_idx, num_params);
        }
        
      ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 367 "micko.y"
    {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
      ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 384 "micko.y"
    {
        if((yyvsp[(1) - (3)].i) == VOID)
          err("variable '%s' cannot have type void",(yyvsp[(2) - (3)].s));
        if (isClass==0){
          int var_indx = lookup_symbol((yyvsp[(2) - (3)].s), VAR|PAR);
          if(var_indx == NO_INDEX)
            insert_symbol((yyvsp[(2) - (3)].s), VAR, (yyvsp[(1) - (3)].i), ++var_num, NO_ATR,NO_ATR);
          else{
            if(get_atr3(var_indx) == NO_ATR){
              err("redefinition of '%s'", (yyvsp[(2) - (3)].s));
            }else{
              insert_symbol((yyvsp[(2) - (3)].s), VAR, (yyvsp[(1) - (3)].i), ++var_num, NO_ATR,NO_ATR);
            }
          }
        }else{
          if(lookup_symbol((yyvsp[(2) - (3)].s), VAR|PAR|ATR) == NO_INDEX)
            insert_symbol((yyvsp[(2) - (3)].s), VAR, (yyvsp[(1) - (3)].i), ++var_num, NO_ATR,current_class_idx);
          else {
            int var_indx =lookup_symbol((yyvsp[(2) - (3)].s),ATR);
            if(var_indx == NO_INDEX){
              err("redefinition of '%s'", (yyvsp[(2) - (3)].s));
            }else{
              if(get_atr3(var_indx) == current_class_idx){
                err("redefinition of '%s' attribute", (yyvsp[(2) - (3)].s));
              }else{
                insert_symbol((yyvsp[(2) - (3)].s), VAR, (yyvsp[(1) - (3)].i), ++var_num, NO_ATR,current_class_idx);
              }
            }
          }
        }
      ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 432 "micko.y"
    {
    int indx = lookup_symbol((yyvsp[(1) - (1)].s),INST);
    if(indx==NO_INDEX)
      err("unknown instance '%s'",(yyvsp[(1) - (1)].s));
    current_instance_idx=indx;
  ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 440 "micko.y"
    {
      isClass=1;
      if(lookup_symbol((yyvsp[(2) - (2)].s), CLAS) == NO_INDEX)
        err("'%s' is not a class", (yyvsp[(2) - (2)].s));
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 445 "micko.y"
    {
    int idx=lookup_symbol((yyvsp[(4) - (4)].s),VAR|PAR|INST);
    if(idx == NO_INDEX){
      instance_index = lookup_symbol((yyvsp[(2) - (4)].s),CLAS);
      current_instance_idx = insert_symbol((yyvsp[(4) - (4)].s), INST, NO_TYPE, NO_ATR, NO_ATR,instance_index);
    }else{
      err("redefinition of '%s' ",(yyvsp[(4) - (4)].s));
    }
  ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 454 "micko.y"
    {
      if(lookup_symbol((yyvsp[(8) - (8)].s), CLAS) == NO_INDEX)
        err("'%s' is not a class", (yyvsp[(8) - (8)].s));
      if(lookup_symbol((yyvsp[(2) - (8)].s),CLAS) != lookup_symbol((yyvsp[(8) - (8)].s),CLAS)){
        err("invalid instance of class creation");
      }
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 461 "micko.y"
    {instance_declaration_arg_counter = 0;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 462 "micko.y"
    {
      int class_idx = lookup_symbol((yyvsp[(2) - (12)].s), CLAS);
      if(get_atr1(class_idx) != instance_declaration_arg_counter)
        err("wrong number of args to class '%s'", get_name(class_idx));
      for(int i=instance_declaration_arg_counter-1; i >= 0 ; i--){
            int indx = arguments_array[i];
            free_if_reg(indx);
            code("\n\t\tPUSH\t");
            gen_sym_name(indx);
      }
      instance_declaration_arg_counter = 0;
      isClass=0;
      code("\n\t\tCALL\t%s", get_name(class_idx));
      code("\n\t\tADDS\t%%15,$%d,%%15",get_atr1(class_idx) * 4);

  ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 495 "micko.y"
    {
    if(parameter_map[get_atr3(current_instance_idx)][instance_declaration_arg_counter] != get_type((yyvsp[(1) - (1)].i)))
      err("incompatible type for argument in '%s'",get_name(get_atr3(current_instance_idx)));

    arguments_array[instance_declaration_arg_counter]=(yyvsp[(1) - (1)].i);
    instance_declaration_arg_counter += 1;
  ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 510 "micko.y"
    {
        if(isClass==0){
          int idx = lookup_symbol((yyvsp[(1) - (4)].s), VAR|PAR);
          if(idx == NO_INDEX)
            err("invalid lvalue '%s' in assignment", (yyvsp[(1) - (4)].s));
          else
            if(get_type(idx) != get_type((yyvsp[(3) - (4)].i)))
              err("incompatible types in assignment");
          gen_mov((yyvsp[(3) - (4)].i), idx);
        }else{
          int id_indx = lookup_symbol((yyvsp[(1) - (4)].s),VAR|PAR|ATR);
          if(id_indx == NO_INDEX){
            err("invalid lvalue '%s' in assignment", (yyvsp[(1) - (4)].s));
          }else{
            int is_atr = lookup_symbol((yyvsp[(1) - (4)].s),ATR);
            if(is_atr != NO_INDEX){
              if(get_atr3(is_atr) != current_class_idx)
                err("attribute not part of this class '%s' class '%s' ",(yyvsp[(1) - (4)].s),get_name(current_class_idx));
              else{
                  if(get_type(id_indx) != get_type((yyvsp[(3) - (4)].i)))
                    err("incompatible types in assignment");
                  gen_mov((yyvsp[(3) - (4)].i), id_indx);
              }
            }else{
                if(get_type(id_indx) != get_type((yyvsp[(3) - (4)].i)))
                  err("incompatible types in assignment");
                gen_mov((yyvsp[(3) - (4)].i), id_indx);
            }
          }
        }
      ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 547 "micko.y"
    {
        if(get_type((yyvsp[(1) - (3)].i)) != get_type((yyvsp[(3) - (3)].i)))
          err("invalid operands: arithmetic operation");
        int t1 = get_type((yyvsp[(1) - (3)].i));    
        code("\n\t\t%s\t", ar_instructions[(yyvsp[(2) - (3)].i) + (t1 - 1) * AROP_NUMBER]);
        gen_sym_name((yyvsp[(1) - (3)].i));
        code(",");
        gen_sym_name((yyvsp[(3) - (3)].i));
        code(",");
        free_if_reg((yyvsp[(3) - (3)].i));
        free_if_reg((yyvsp[(1) - (3)].i));
        (yyval.i) = take_reg();
        gen_sym_name((yyval.i));
        set_type((yyval.i), t1);
      ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 567 "micko.y"
    {
      isClass=1;
      int instance_indx = lookup_symbol((yyvsp[(1) - (3)].s),INST);
      current_class_idx= get_atr3(instance_indx);
      if(instance_indx==NO_INDEX){
        err("'%s' is not declared as class",(yyvsp[(1) - (3)].s));
      };      
      (yyval.i) = (yyvsp[(3) - (3)].i);
      isClass=0;
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 578 "micko.y"
    {
        if( isClass==0){
          (yyval.i) = lookup_symbol((yyvsp[(1) - (1)].s), VAR|PAR);
          if((yyval.i) == NO_INDEX)
            err("'%s' undeclared", (yyvsp[(1) - (1)].s));
        }else{
          int indx = lookup_symbol((yyvsp[(1) - (1)].s),VAR|PAR|ATR);
          (yyval.i) = indx;
          if((yyval.i) == NO_INDEX)
            err("'%s' undeclared", (yyvsp[(1) - (1)].s));
          if(lookup_symbol((yyvsp[(1) - (1)].s),VAR|PAR)==NO_INDEX){
            if(get_atr3(indx) != current_class_idx){
              err("'%s' undeclared, atr3 '%d' class idx '%d'", (yyvsp[(1) - (1)].s), get_atr3(indx),current_class_idx);
            }
          }
        }
      ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 596 "micko.y"
    {
        (yyval.i) = take_reg();
        gen_mov(FUN_REG, (yyval.i));
      ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 602 "micko.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 607 "micko.y"
    { (yyval.i) = insert_literal((yyvsp[(1) - (1)].s), INT); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 610 "micko.y"
    { (yyval.i) = insert_literal((yyvsp[(1) - (1)].s), UINT); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 615 "micko.y"
    {
        arg_counter=0;
        if(isClass==0){
        fcall_idx = lookup_symbol((yyvsp[(1) - (1)].s), FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", (yyvsp[(1) - (1)].s));
        }
        else
        {
          fcall_idx = lookup_symbol((yyvsp[(1) - (1)].s), FUN);
          if(fcall_idx == NO_INDEX)
            err("'%s' is not a function", (yyvsp[(1) - (1)].s));
          if(get_atr3(fcall_idx) != current_class_idx){
            err("'%s' is not a function of class", (yyvsp[(1) - (1)].s));
          }
        }
      ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 633 "micko.y"
    {

          if(get_atr1(fcall_idx) != arg_counter)
            err("wrong number of arguments for function '%s' number of arguments '%d' ",get_name(fcall_idx), arg_counter);
          
          for(int i=arg_counter-1; i >= 0 ; i--){
            int indx = arguments_array[i];
            free_if_reg(indx);
            code("\n\t\tPUSH\t");
            gen_sym_name(indx);
           }

          code("\n\t\tCALL\t%s", get_name(fcall_idx));
          if(arg_counter > 0)
            code("\n\t\tADDS\t%%15,$%d,%%15", arg_counter * 4);
          set_type(FUN_REG, get_type(fcall_idx));
          (yyval.i) = FUN_REG;
          arg_counter=0;
          
      ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 669 "micko.y"
    { 
      if(isClass==0){
        if(parameter_map_function[fcall_idx][arg_counter] != get_type((yyvsp[(1) - (1)].i))){
          err("incompatible arguments");
        }
        arguments_array[arg_counter]=(yyvsp[(1) - (1)].i);
        arg_counter += 1;

    
      }else{
        if(parameter_map_function[fcall_idx][arg_counter]  != get_type((yyvsp[(1) - (1)].i))){
          err("incompatible arguments");
        }
        arguments_array[arg_counter]=(yyvsp[(1) - (1)].i);
        arg_counter += 1;

    
      }
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 692 "micko.y"
    { code("\n@exit%d:", (yyvsp[(1) - (1)].i)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 695 "micko.y"
    { code("\n@exit%d:", (yyvsp[(1) - (3)].i)); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 700 "micko.y"
    {
        (yyval.i) = ++lab_num;
        code("\n@if%d:", lab_num);
      ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 705 "micko.y"
    {
        code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[(4) - (4)].i)], (yyvsp[(3) - (4)].i));
        code("\n@true%d:", (yyvsp[(3) - (4)].i));
      ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 710 "micko.y"
    {
        code("\n\t\tJMP \t@exit%d", (yyvsp[(3) - (7)].i));
        code("\n@false%d:", (yyvsp[(3) - (7)].i));
        (yyval.i) = (yyvsp[(3) - (7)].i);
      ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 719 "micko.y"
    {
        if(get_type((yyvsp[(1) - (3)].i)) != get_type((yyvsp[(3) - (3)].i)))
          err("invalid operands: relational operator");
        (yyval.i) = (yyvsp[(2) - (3)].i) + ((get_type((yyvsp[(1) - (3)].i)) - 1) * RELOP_NUMBER);
        gen_cmp((yyvsp[(1) - (3)].i), (yyvsp[(3) - (3)].i));
      ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 729 "micko.y"
    {
      if(get_type(fun_idx) == VOID)
        err("Function cannot return value");
      else if(get_type(fun_idx) != get_type((yyvsp[(2) - (3)].i)))
        err("incompatible types in return");
      return_count++;
        gen_mov((yyvsp[(2) - (3)].i), FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));        
      ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 739 "micko.y"
    {
      if(get_type(fun_idx) != VOID)
        warn("Function should return a value");
      return_count++; 
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2250 "micko.tab.c"
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
#line 746 "micko.y"


int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}


