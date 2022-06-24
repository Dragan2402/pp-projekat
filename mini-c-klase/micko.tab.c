
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
  int class_idx = -1;
  int current_class_idx = -1;
  int current_instance_idx= -1;
  int instance_declaration_arg_counter = 0;

  int fcall_idx = -1;
  int instance_index=-1;
  int lab_num = -1;

  int* parameter_map[128];
  int arg_counter = 0;
  int isClass = 0;
  int attributes_counter=0;
  FILE *output;


/* Line 189 of yacc.c  */
#line 111 "micko.tab.c"

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
#line 38 "micko.y"

  int i;
  char *s;



/* Line 214 of yacc.c  */
#line 176 "micko.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 188 "micko.tab.c"

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
#define YYLAST   95

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  23
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  133

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
      76,    81,    82,    90,    91,    94,    95,   101,   102,   105,
     109,   110,   113,   115,   117,   119,   121,   123,   124,   125,
     126,   127,   128,   144,   145,   147,   149,   153,   155,   159,
     164,   166,   170,   172,   176,   178,   180,   184,   186,   188,
     189,   195,   196,   198,   200,   204,   205,   206,   214,   218
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
      -1,    -1,     3,     9,    46,    12,    47,    13,    48,    -1,
      -1,     3,     9,    -1,    -1,    14,    50,    49,    52,    15,
      -1,    -1,    50,    51,    -1,     3,     9,    17,    -1,    -1,
      52,    53,    -1,    63,    -1,    64,    -1,    71,    -1,    54,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,     7,     9,
      55,     9,    56,    16,     8,     9,    57,    12,    58,    60,
      59,    13,    17,    -1,    -1,    61,    -1,    62,    -1,    61,
      19,    62,    -1,    65,    -1,    14,    52,    15,    -1,     9,
      16,    65,    17,    -1,    66,    -1,    65,    20,    66,    -1,
      67,    -1,     9,    18,    68,    -1,     9,    -1,    68,    -1,
      12,    65,    13,    -1,    10,    -1,    11,    -1,    -1,     9,
      69,    12,    70,    13,    -1,    -1,    65,    -1,    72,    -1,
      72,     5,    53,    -1,    -1,    -1,     4,    12,    73,    75,
      74,    13,    53,    -1,    65,    21,    65,    -1,     6,    65,
      17,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    74,    74,    81,    83,    87,    88,    92,
     103,    92,   113,   115,   119,   119,   145,   147,   150,   151,
     155,   163,   155,   168,   170,   174,   175,   179,   209,   211,
     214,   236,   235,   280,   282,   299,   298,   309,   311,   315,
     347,   349,   353,   354,   355,   356,   357,   361,   366,   375,
     382,   383,   361,   395,   397,   401,   402,   406,   415,   419,
     454,   456,   475,   476,   488,   506,   512,   517,   520,   526,
     525,   558,   560,   581,   584,   590,   595,   589,   608,   618
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
  "parameter", "body", "$@9", "variable_list", "variable",
  "statement_list", "statement", "class_declaration", "$@10", "$@11",
  "$@12", "$@13", "$@14", "class_argument_list", "class_arguments",
  "class_argument", "compound_statement", "assignment_statement",
  "num_exp", "exp", "literal", "function_call", "$@15", "argument",
  "if_statement", "if_part", "@16", "$@17", "rel_exp", "return_statement", 0
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
      44,    46,    45,    47,    47,    49,    48,    50,    50,    51,
      52,    52,    53,    53,    53,    53,    53,    55,    56,    57,
      58,    59,    54,    60,    60,    61,    61,    62,    63,    64,
      65,    65,    66,    66,    66,    66,    66,    67,    67,    69,
      68,    70,    70,    71,    71,    73,    74,    72,    75,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     4,     0,     1,     1,     2,     0,
       0,     9,     0,     2,     0,     4,     0,     1,     1,     2,
       0,     0,     9,     0,     1,     1,     3,     2,     0,     2,
       4,     0,     7,     0,     2,     0,     5,     0,     2,     3,
       0,     2,     1,     1,     1,     1,     1,     0,     0,     0,
       0,     0,    15,     0,     1,     1,     3,     1,     3,     4,
       1,     3,     1,     3,     1,     1,     3,     1,     1,     0,
       5,     0,     1,     1,     3,     0,     0,     7,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,     0,     3,     6,     7,     9,     0,
       8,     0,     0,     4,    18,    12,    31,    19,     0,     0,
       0,    20,    13,    10,    33,    14,     0,    16,     0,     0,
       0,    23,     0,    17,    34,     0,    15,     0,     0,    24,
      25,    11,    37,    32,    27,     0,     0,    35,    28,    26,
       0,    40,    38,    21,     0,     0,     0,     0,    29,    39,
       0,     0,     0,     0,    40,    36,    41,    45,    42,    43,
      44,    73,    46,     0,    22,    75,    64,    67,    68,     0,
       0,    60,    62,    65,    47,     0,     0,     0,     0,     0,
       0,     0,     0,    79,     0,     0,     0,    58,    74,    30,
       0,    76,    69,    63,    71,    66,    61,    48,    59,     0,
       0,    72,     0,     0,    78,     0,    70,     0,    77,     0,
      49,     0,    50,    53,    51,    54,    55,    57,     0,     0,
       0,    56,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     9,     5,     6,     7,    11,    27,    18,
      22,    30,    32,    13,    23,    26,    57,    38,    39,    40,
      53,    58,    14,    19,    29,    43,    51,    47,    52,    55,
      66,    67,    95,   113,   121,   123,   128,   124,   125,   126,
      68,    69,   127,    81,    82,    83,    91,   112,    70,    71,
      89,   110,   101,    72
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -87
static const yytype_int8 yypact[] =
{
     -87,    16,    13,   -87,    18,   -87,    13,   -87,   -87,    39,
     -87,    32,    38,    39,   -87,   -87,   -87,   -87,    12,    37,
      41,   -87,   -87,   -87,    48,   -87,    40,    39,    44,    42,
      43,    51,    46,    39,   -87,    45,   -87,    47,    49,    50,
     -87,   -87,   -87,   -87,   -87,    52,    51,    54,   -87,   -87,
      55,   -87,   -87,    56,    53,    -1,    57,    59,   -87,   -87,
      60,    27,    58,    61,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,    63,   -87,    62,   -87,   -87,     7,   -87,   -87,    27,
       6,   -87,   -87,   -87,   -87,    27,    26,     3,    64,    27,
      66,    67,    -9,   -87,    27,    69,    14,   -87,   -87,   -87,
      24,   -87,   -87,   -87,    27,   -87,   -87,   -87,   -87,    27,
      70,    65,    71,    72,    65,     3,   -87,    68,   -87,    73,
     -87,    74,   -87,    27,   -87,    75,   -87,    65,    76,    27,
      78,   -87,   -87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -87,   -87,   -87,   -87,   -87,   -87,    81,   -87,   -87,   -87,
     -87,   -87,   -87,    31,   -87,   -87,   -87,   -87,   -87,    17,
     -87,   -87,   -11,   -87,   -87,   -87,   -87,   -87,   -87,    28,
     -86,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -49,
     -87,   -87,   -61,    -4,   -87,     1,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -70
static const yytype_int16 yytable[] =
{
      80,    98,    17,    60,   105,    61,    62,    60,    63,    61,
      62,    94,    63,    64,    65,    20,     3,    64,    92,   -69,
       4,    21,    17,    93,    96,    90,    94,     8,   100,   118,
      60,   108,    61,    62,    94,    63,    76,    77,    78,    79,
      64,    97,    12,   111,    94,   109,    15,    16,   114,    24,
      25,    28,    31,    34,    37,    35,    44,    50,    33,    42,
      36,    41,    45,    49,    54,    56,    48,    84,    87,    46,
      59,    88,    75,    73,    74,   102,   119,    85,   107,   104,
     131,    99,   120,   115,   116,    94,   122,    10,   117,   130,
     106,   103,    86,     0,   129,   132
};

static const yytype_int16 yycheck[] =
{
      61,    87,    13,     4,    13,     6,     7,     4,     9,     6,
       7,    20,     9,    14,    15,     3,     0,    14,    79,    12,
       7,     9,    33,    17,    85,    18,    20,     9,    89,   115,
       4,    17,     6,     7,    20,     9,     9,    10,    11,    12,
      14,    15,     3,   104,    20,    21,    14,     9,   109,    12,
       9,     3,    12,     9,     3,    13,     9,     3,    27,    14,
      17,    15,    13,    46,     9,     9,    14,     9,     5,    19,
      17,     9,    12,    16,    15,     9,     8,    16,     9,    12,
     129,    17,     9,    13,    13,    20,    12,     6,    16,    13,
      94,    90,    64,    -1,    19,    17
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    25,     0,     7,    27,    28,    29,     9,    26,
      29,    30,     3,    36,    45,    14,     9,    45,    32,    46,
       3,     9,    33,    37,    12,     9,    38,    31,     3,    47,
      34,    12,    35,    36,     9,    13,    17,     3,    40,    41,
      42,    15,    14,    48,     9,    13,    19,    50,    14,    42,
       3,    49,    51,    43,     9,    52,     9,    39,    44,    17,
       4,     6,     7,     9,    14,    15,    53,    54,    63,    64,
      71,    72,    76,    16,    15,    12,     9,    10,    11,    12,
      65,    66,    67,    68,     9,    16,    52,     5,     9,    73,
      18,    69,    65,    17,    20,    55,    65,    15,    53,    17,
      65,    75,     9,    68,    12,    13,    66,     9,    17,    21,
      74,    65,    70,    56,    65,    13,    13,    16,    53,     8,
       9,    57,    12,    58,    60,    61,    62,    65,    59,    19,
      13,    62,    17
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
#line 74 "micko.y"
    { isClass=1; ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 74 "micko.y"
    { isClass=0; ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 75 "micko.y"
    {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 92 "micko.y"
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
#line 103 "micko.y"
    { 
       if( arg_counter != get_atr1(class_idx)){
        err("Invalid number of arguments in constructor, arguments '%d', attributes '%d'",arg_counter,attributes_counter);
       }
       
     ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 108 "micko.y"
    {
      arg_counter=0;
      attributes_counter=0;
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 119 "micko.y"
    {
      {
        int atr_idx = lookup_symbol((yyvsp[(2) - (2)].s), ATR);
        if(atr_idx == NO_INDEX){
          int idx=insert_symbol((yyvsp[(2) - (2)].s), ATR, (yyvsp[(1) - (2)].i), attributes_counter, NO_ATR,current_class_idx);
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
#line 155 "micko.y"
    {
    char* class_name = get_name(current_class_idx);
    char* id = (yyvsp[(1) - (1)].s);
    int ret = strcmp(class_name,id);
    if (ret < 0 ){
      err("Inavlid constructor name '%s', class name '%s'",(yyvsp[(1) - (1)].s),get_name(current_class_idx));
    }
    arg_counter = 0 ;
  ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 163 "micko.y"
    {  
    clear_symbols(get_last_element() - arg_counter +1);
    arg_counter = 0 ;
  ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 180 "micko.y"
    {
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
            insert_symbol((yyvsp[(2) - (2)].s), PAR, (yyvsp[(1) - (2)].i), arg_counter , NO_ATR,current_class_idx);
            ++arg_counter;
          }
        }else{
          int* param_types = parameter_map[current_class_idx];
          if(param_types[arg_counter] != (yyvsp[(1) - (2)].i)){
            err("inavlid constructor parameter, paramtere type '%d', attribute type '%d'",(yyvsp[(1) - (2)].i),param_types[arg_counter]);
          }
          insert_symbol((yyvsp[(2) - (2)].s), PAR, (yyvsp[(1) - (2)].i), arg_counter, NO_ATR,current_class_idx);
          ++arg_counter;
        }
      }
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 215 "micko.y"
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
        }else{
          err("unknown attribute '%s' in class", (yyvsp[(1) - (4)].s));
        }
      }
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 236 "micko.y"
    {
        if (isClass==0){
            fun_idx = lookup_symbol((yyvsp[(2) - (2)].s), FUN);
            if(fun_idx == NO_INDEX)
              fun_idx = insert_symbol((yyvsp[(2) - (2)].s), FUN, (yyvsp[(1) - (2)].i), NO_ATR, NO_ATR,NO_ATR);
            else
              if(get_atr3(fun_idx) == NO_ATR){
                fun_idx = insert_symbol((yyvsp[(2) - (2)].s), FUN, (yyvsp[(1) - (2)].i), NO_ATR, NO_ATR,NO_ATR);
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
              fun_idx = insert_symbol((yyvsp[(2) - (2)].s), FUN, (yyvsp[(1) - (2)].i), NO_ATR, NO_ATR,current_class_idx);   
            }
            else {
              if(get_atr3(fun_idx) == current_class_idx){
                err("redefinition of function '%s' in class '%s", (yyvsp[(2) - (2)].s), get_name(current_class_idx));
              }else{
                  fun_idx = insert_symbol((yyvsp[(2) - (2)].s), FUN, (yyvsp[(1) - (2)].i), NO_ATR, NO_ATR,current_class_idx);
              }
            }
        }
      ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 267 "micko.y"
    {
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
#line 280 "micko.y"
    { set_atr1(fun_idx, 0); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 283 "micko.y"
    {
        if(isClass==0){
        insert_symbol((yyvsp[(2) - (2)].s), PAR, (yyvsp[(1) - (2)].i), 1, NO_ATR,NO_ATR);
        set_atr1(fun_idx, 1);
        set_atr2(fun_idx, (yyvsp[(1) - (2)].i));
        }else{
        insert_symbol((yyvsp[(2) - (2)].s), PAR, (yyvsp[(1) - (2)].i), 1, NO_ATR,current_class_idx);
        set_atr1(fun_idx, 1);
        set_atr2(fun_idx, (yyvsp[(1) - (2)].i));
        }
        
      ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 299 "micko.y"
    {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
      ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 316 "micko.y"
    {
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

  case 47:

/* Line 1455 of yacc.c  */
#line 361 "micko.y"
    {
      isClass=1;
      if(lookup_symbol((yyvsp[(2) - (2)].s), CLAS) == NO_INDEX)
        err("'%s' is not a class", (yyvsp[(2) - (2)].s));
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 366 "micko.y"
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

  case 49:

/* Line 1455 of yacc.c  */
#line 375 "micko.y"
    {
      if(lookup_symbol((yyvsp[(8) - (8)].s), CLAS) == NO_INDEX)
        err("'%s' is not a class", (yyvsp[(8) - (8)].s));
      if(lookup_symbol((yyvsp[(2) - (8)].s),CLAS) != lookup_symbol((yyvsp[(8) - (8)].s),CLAS)){
        err("invalid instance of class creation");
      }
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 382 "micko.y"
    {instance_declaration_arg_counter = 0;;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 383 "micko.y"
    {
      int class_idx = lookup_symbol((yyvsp[(2) - (12)].s), CLAS);
      if(get_atr1(class_idx) != instance_declaration_arg_counter)
        err("wrong number of args to class '%s'", get_name(class_idx));
      instance_declaration_arg_counter = 0;
      isClass=0;
  ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 407 "micko.y"
    {
    if(parameter_map[get_atr3(current_instance_idx)][instance_declaration_arg_counter] != get_type((yyvsp[(1) - (1)].i)))
      err("incompatible type for argument in '%s'",get_name(get_atr3(current_instance_idx)));
    instance_declaration_arg_counter += 1;
  ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 420 "micko.y"
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

  case 61:

/* Line 1455 of yacc.c  */
#line 457 "micko.y"
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

  case 63:

/* Line 1455 of yacc.c  */
#line 477 "micko.y"
    {
      isClass=1;
      int instance_indx = lookup_symbol((yyvsp[(1) - (3)].s),INST);
      current_class_idx= get_atr3(instance_indx);
      if(instance_indx==NO_INDEX){
        err("'%s' is not declared as class",(yyvsp[(1) - (3)].s));
      };      
      (yyval.i) = (yyvsp[(3) - (3)].i);
      isClass=0;
      print_symtab();
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 489 "micko.y"
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

  case 65:

/* Line 1455 of yacc.c  */
#line 507 "micko.y"
    {
        (yyval.i) = take_reg();
        gen_mov(FUN_REG, (yyval.i));
      ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 513 "micko.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 518 "micko.y"
    { (yyval.i) = insert_literal((yyvsp[(1) - (1)].s), INT); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 521 "micko.y"
    { (yyval.i) = insert_literal((yyvsp[(1) - (1)].s), UINT); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 526 "micko.y"
    {
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

  case 70:

/* Line 1455 of yacc.c  */
#line 543 "micko.y"
    {

          if(get_atr1(fcall_idx) != (yyvsp[(4) - (5)].i))
            err("wrong number of arguments");
          code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
          if((yyvsp[(4) - (5)].i) > 0)
            code("\n\t\t\tADDS\t%%15,$%d,%%15", (yyvsp[(4) - (5)].i) * 4);
          set_type(FUN_REG, get_type(fcall_idx));
          (yyval.i) = FUN_REG;
          
      ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 558 "micko.y"
    { (yyval.i) = 0; ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 561 "micko.y"
    { 
      if(isClass==0){
        if(get_type(fcall_idx) != get_type((yyvsp[(1) - (1)].i)))
          err("incompatible type for argument");
        free_if_reg((yyvsp[(1) - (1)].i));
        code("\n\t\t\tPUSH\t");
        gen_sym_name((yyvsp[(1) - (1)].i));
        (yyval.i) = 1;
      }else{
        if(get_type(fcall_idx) != get_type((yyvsp[(1) - (1)].i)))
          err("incompatible type for argument");
        free_if_reg((yyvsp[(1) - (1)].i));
        code("\n\t\t\tPUSH\t");
        gen_sym_name((yyvsp[(1) - (1)].i));
        (yyval.i) = 1;
      }
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 582 "micko.y"
    { code("\n@exit%d:", (yyvsp[(1) - (1)].i)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 585 "micko.y"
    { code("\n@exit%d:", (yyvsp[(1) - (3)].i)); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 590 "micko.y"
    {
        (yyval.i) = ++lab_num;
        code("\n@if%d:", lab_num);
      ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 595 "micko.y"
    {
        code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[(4) - (4)].i)], (yyvsp[(3) - (4)].i));
        code("\n@true%d:", (yyvsp[(3) - (4)].i));
      ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 600 "micko.y"
    {
        code("\n\t\tJMP \t@exit%d", (yyvsp[(3) - (7)].i));
        code("\n@false%d:", (yyvsp[(3) - (7)].i));
        (yyval.i) = (yyvsp[(3) - (7)].i);
      ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 609 "micko.y"
    {
        if(get_type((yyvsp[(1) - (3)].i)) != get_type((yyvsp[(3) - (3)].i)))
          err("invalid operands: relational operator");
        (yyval.i) = (yyvsp[(2) - (3)].i) + ((get_type((yyvsp[(1) - (3)].i)) - 1) * RELOP_NUMBER);
        gen_cmp((yyvsp[(1) - (3)].i), (yyvsp[(3) - (3)].i));
      ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 619 "micko.y"
    {
        if(get_type(fun_idx) != get_type((yyvsp[(2) - (3)].i))){
          err("incompatible types in return");
          }
        gen_mov((yyvsp[(2) - (3)].i), FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));        
      ;}
    break;



/* Line 1455 of yacc.c  */
#line 2132 "micko.tab.c"
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
#line 628 "micko.y"


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


