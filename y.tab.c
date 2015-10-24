/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc_expl.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int yylex(void);
    extern FILE *yyin;

    #include "symboltable.h"
    #include "abstracttree.h"
    #include "stack.h"
    #include "heap.h"

    #include "symboltable.c"
    #include "abstracttree.c"
    #include "stack.c"
    #include "heap.c"

    AST *root;
    TypeTable decl_type,arg_type,local_type;

#line 87 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ENDOFFILE = 258,
    READ = 259,
    WRITE = 260,
    IF = 261,
    THEN = 262,
    ELSE = 263,
    ENDIF = 264,
    DO = 265,
    ENDWHILE = 266,
    BREAK = 267,
    WHILE = 268,
    INT = 269,
    STR = 270,
    RETURN = 271,
    DECL = 272,
    ENDDECL = 273,
    MAIN = 274,
    TYPE = 275,
    ENDTYPE = 276,
    NULLC = 277,
    CONTINUE = 278,
    BEG = 279,
    END = 280,
    RELOP = 281,
    DELIM = 282,
    ASGN = 283,
    AROP2 = 284,
    AROP1 = 285,
    NOT = 286,
    LOGOP = 287,
    DOT = 288,
    NUM = 289,
    ID = 290,
    STRCONST = 291,
    ALLOC = 292,
    DEALLOC = 293
  };
#endif
/* Tokens.  */
#define ENDOFFILE 258
#define READ 259
#define WRITE 260
#define IF 261
#define THEN 262
#define ELSE 263
#define ENDIF 264
#define DO 265
#define ENDWHILE 266
#define BREAK 267
#define WHILE 268
#define INT 269
#define STR 270
#define RETURN 271
#define DECL 272
#define ENDDECL 273
#define MAIN 274
#define TYPE 275
#define ENDTYPE 276
#define NULLC 277
#define CONTINUE 278
#define BEG 279
#define END 280
#define RELOP 281
#define DELIM 282
#define ASGN 283
#define AROP2 284
#define AROP1 285
#define NOT 286
#define LOGOP 287
#define DOT 288
#define NUM 289
#define ID 290
#define STRCONST 291
#define ALLOC 292
#define DEALLOC 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 22 "yacc_expl.y" /* yacc.c:355  */

    struct ASTNode * nptr;
    struct ArgStruct * arg;
    struct GSymbol * gvar;
    struct LSymbol * lvar;
    struct fieldList * field;
    struct TypeTable * ty;
    char c;

#line 213 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 228 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   321

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,     2,
      44,    45,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    53,    54,    57,    58,    61,    70,    72,
      73,    76,    81,    86,    99,   104,   110,   112,   115,   116,
     119,   124,   129,   144,   149,   154,   158,   162,   168,   174,
     177,   178,   179,   182,   187,   192,   205,   210,   215,   219,
     224,   225,   228,   243,   258,   281,   286,   289,   290,   293,
     298,   303,   310,   320,   325,   331,   344,   350,   354,   357,
     362,   368,   373,   377,   381,   385,   388,   393,   397,   402,
     406,   410,   415,   421,   427,   432,   436,   440,   441,   444,
     448,   452,   453,   454,   459,   464,   469,   470,   485,   491,
     497
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENDOFFILE", "READ", "WRITE", "IF",
  "THEN", "ELSE", "ENDIF", "DO", "ENDWHILE", "BREAK", "WHILE", "INT",
  "STR", "RETURN", "DECL", "ENDDECL", "MAIN", "TYPE", "ENDTYPE", "NULLC",
  "CONTINUE", "BEG", "END", "RELOP", "DELIM", "ASGN", "AROP2", "AROP1",
  "NOT", "LOGOP", "DOT", "NUM", "ID", "STRCONST", "ALLOC", "DEALLOC",
  "'{'", "'}'", "','", "'['", "']'", "'('", "')'", "'&'", "$accept",
  "Prog", "TypeDeclBlock", "TypeDefList", "TypeDef", "NewType",
  "TypeDeclList", "TypeDecl", "IDList", "TId", "GDecblock", "GDecList",
  "GDecl", "GIdList", "GId", "FArgList", "ArgList", "ArgList1", "ArgType",
  "Args", "Arg", "Fdefblock", "Fdef", "Ldecblock", "LdecList", "Ldecl",
  "LIdList", "LId", "Mainblock", "Body", "slist", "stmt", "FIELD", "E",
  "param", "retstmt", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   123,
     125,    44,    91,    93,    40,    41,    38
};
# endif

#define YYPACT_NINF -138

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-138)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -11,   -20,    28,    46,  -138,    60,  -138,    -1,  -138,    27,
    -138,  -138,  -138,    98,    22,    22,    22,    54,  -138,   102,
      59,    59,    59,    40,  -138,   216,    79,  -138,   111,   117,
    -138,  -138,   -12,    70,    83,  -138,   128,  -138,   148,  -138,
     163,   164,  -138,  -138,    52,   115,  -138,    22,  -138,  -138,
      99,   118,   123,   157,  -138,  -138,    59,  -138,  -138,   135,
     -13,   -13,   -13,   109,  -138,   186,  -138,   179,   115,   115,
     115,  -138,  -138,  -138,   192,   190,  -138,   190,   190,  -138,
     115,   195,   193,  -138,   200,   205,  -138,   -13,  -138,   224,
     228,   229,   230,  -138,   120,   231,   224,   224,   224,   235,
     235,   235,    93,  -138,    61,   233,   231,   231,   231,  -138,
     165,  -138,   166,   168,  -138,  -138,   232,   234,   236,   237,
     -23,   238,    21,  -138,    51,  -138,   239,   243,   244,  -138,
     235,  -138,  -138,   240,   105,   105,   105,    56,   242,   105,
     250,   105,  -138,   249,    88,   251,  -138,  -138,  -138,  -138,
     169,   167,  -138,   105,  -138,   177,  -138,   105,   254,   116,
     127,   134,   245,   196,  -138,   144,   170,   175,   203,  -138,
     247,   210,  -138,   105,   261,   263,   222,   105,   105,   139,
     105,   105,   105,   105,   265,   286,   284,   252,  -138,   267,
     269,   271,  -138,   255,  -138,   151,  -138,  -138,   156,   222,
     106,  -138,   227,   270,    44,   270,  -138,    61,    61,   272,
     105,  -138,  -138,   274,   258,  -138,   105,  -138,     8,    47,
    -138,   217,  -138,   277,   222,    61,   278,   279,  -138,  -138,
      26,  -138,  -138,   280,  -138
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     8,     0,     6,     0,     1,     0,
      41,     3,     5,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,    10,    26,     0,    24,     0,     0,
      17,    18,     0,     0,     0,    40,     0,    16,     0,    15,
       0,     0,     7,     9,     0,    30,    20,     0,    21,    22,
       0,     0,     0,     0,     2,    11,     0,    12,    13,     0,
       0,     0,     0,     0,    29,    32,    23,     0,    30,    30,
      30,    14,    25,    38,     0,    33,    37,    34,    35,    27,
       0,     0,     0,    28,     0,     0,    39,     0,    31,    46,
       0,     0,     0,    36,     0,     0,    46,    46,    46,     0,
       0,     0,     0,    48,     0,     0,     0,     0,     0,    54,
       0,    53,     0,     0,    45,    47,     0,     0,     0,     0,
       0,     0,     0,    58,     0,    55,     0,     0,     0,    49,
       0,    50,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,     0,     0,    42,    43,    44,    52,
       0,     0,    86,     0,    81,    83,    82,     0,    85,     0,
       0,     0,     0,     0,    73,     0,     0,     0,     0,    56,
       0,     0,    74,     0,     0,     0,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,     0,
       0,     0,    90,     0,    70,     0,    61,    62,     0,    89,
       0,    77,    78,    76,    75,    79,    64,     0,     0,     0,
       0,    71,    72,     0,     0,    84,     0,    87,     0,     0,
      68,     0,    69,     0,    88,     0,     0,     0,    60,    63,
       0,    65,    67,     0,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,  -138,  -138,   303,  -138,  -138,   287,    80,   253,
    -138,  -138,   294,   246,   266,   194,   273,   241,  -138,   204,
     225,  -138,  -138,   100,  -138,   212,   171,   185,  -138,   110,
    -137,  -121,  -104,  -133,  -138,  -138
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,     7,    23,    24,    38,    39,
      10,    17,    18,    26,    27,    82,    83,    64,    65,    75,
      76,    19,    35,    95,   102,   103,   110,   111,    36,   105,
     122,   123,   158,   159,   200,   143
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     124,   142,   160,   161,   163,   137,   165,    50,   168,     1,
     138,   171,   116,   117,   118,     4,   225,   226,   124,   139,
     176,   119,    73,    51,   179,   116,   117,   118,     8,   151,
     116,   117,   118,    74,   119,   233,   167,   141,    13,   119,
     195,    14,    15,   120,   198,   199,   121,   202,   203,   204,
     205,   116,   117,   118,    20,    21,   120,    25,   227,   121,
     119,   120,    16,     9,   121,   116,   117,   118,    14,    15,
     218,   219,    30,   181,   119,    22,   183,   221,   152,   144,
      42,    11,   120,   224,   145,   121,    59,   153,   230,    16,
     154,   155,   156,   162,    37,     4,   120,   142,   142,   121,
     157,    40,    41,   124,   124,    52,    46,    99,   100,   142,
     152,   114,    20,    21,   124,   124,    32,    33,    53,   153,
      47,   124,   154,   155,   156,   170,   124,   152,   101,    60,
      61,    54,   157,    22,    99,   100,   153,    34,    48,   154,
     155,   156,   180,    67,    49,   181,   182,   216,   183,   157,
      62,   217,    47,   180,    79,   101,   181,   182,    47,   183,
     180,   184,    68,   181,   182,   180,   183,    69,   181,   182,
     180,   183,   185,   181,   182,    55,   183,   180,    72,   186,
     181,   182,   180,   183,   201,   181,   182,   189,   183,    56,
      57,    58,   129,   131,   214,   132,   106,   107,   108,   215,
     145,    70,   138,   138,    56,    56,   130,   130,   145,   130,
     138,   173,   175,    80,   174,   190,   126,   127,   128,   177,
     191,   178,   180,   188,    81,   181,   182,    86,   183,   180,
     192,    87,   181,   182,    89,   183,   180,   194,    90,   181,
     182,    94,   183,   180,   228,    91,   181,   182,   180,   183,
      92,   181,   182,    -1,   183,   104,   181,   182,    44,   183,
      45,    28,    29,    84,    85,    77,    78,    96,    97,    98,
     109,   112,   113,   125,   169,   150,   133,   164,   134,   146,
     135,   136,   140,   147,   148,   166,   172,   145,   196,   187,
     197,   193,   206,   207,   208,   210,   211,   209,   212,   220,
     213,   222,   183,   223,   229,   231,   232,   234,    12,    71,
      43,    31,    93,    66,   115,   149,     0,     0,    63,     0,
       0,    88
};

static const yytype_int16 yycheck[] =
{
     104,   122,   135,   136,   137,    28,   139,    19,   141,    20,
      33,   144,     4,     5,     6,    35,     8,     9,   122,    42,
     153,    13,    35,    35,   157,     4,     5,     6,     0,   133,
       4,     5,     6,    46,    13,     9,   140,    16,    39,    13,
     173,    14,    15,    35,   177,   178,    38,   180,   181,   182,
     183,     4,     5,     6,    14,    15,    35,    35,    11,    38,
      13,    35,    35,    17,    38,     4,     5,     6,    14,    15,
     207,   208,    18,    29,    13,    35,    32,   210,    22,    28,
      40,    21,    35,   216,    33,    38,    34,    31,   225,    35,
      34,    35,    36,    37,    35,    35,    35,   218,   219,    38,
      44,    21,    22,   207,   208,    35,    27,    14,    15,   230,
      22,    18,    14,    15,   218,   219,    14,    15,    35,    31,
      41,   225,    34,    35,    36,    37,   230,    22,    35,    14,
      15,     3,    44,    35,    14,    15,    31,    35,    27,    34,
      35,    36,    26,    44,    27,    29,    30,    41,    32,    44,
      35,    45,    41,    26,    45,    35,    29,    30,    41,    32,
      26,    45,    44,    29,    30,    26,    32,    44,    29,    30,
      26,    32,    45,    29,    30,    27,    32,    26,    43,    45,
      29,    30,    26,    32,    45,    29,    30,    43,    32,    41,
      27,    27,    27,    27,    43,    27,    96,    97,    98,    43,
      33,    44,    33,    33,    41,    41,    41,    41,    33,    41,
      33,    42,    45,    27,    45,    45,   106,   107,   108,    42,
      45,    44,    26,    27,    45,    29,    30,    35,    32,    26,
      27,    41,    29,    30,    39,    32,    26,    27,    45,    29,
      30,    17,    32,    26,    27,    45,    29,    30,    26,    32,
      45,    29,    30,    26,    32,    24,    29,    30,    42,    32,
      44,    15,    16,    69,    70,    61,    62,    39,    39,    39,
      35,   100,   101,    40,    25,    35,    44,    35,    44,    40,
      44,    44,    44,    40,    40,    35,    35,    33,    27,    44,
      27,    44,    27,     7,    10,    28,    27,    45,    27,    27,
      45,    27,    32,    45,    27,    27,    27,    27,     5,    56,
      23,    17,    87,    47,   102,   130,    -1,    -1,    45,    -1,
      -1,    80
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    48,    49,    35,    50,    51,    52,     0,    17,
      57,    21,    51,    39,    14,    15,    35,    58,    59,    68,
      14,    15,    35,    53,    54,    35,    60,    61,    60,    60,
      18,    59,    14,    15,    35,    69,    75,    35,    55,    56,
      55,    55,    40,    54,    42,    44,    27,    41,    27,    27,
      19,    35,    35,    35,     3,    27,    41,    27,    27,    34,
      14,    15,    35,    63,    64,    65,    61,    44,    44,    44,
      44,    56,    43,    35,    46,    66,    67,    66,    66,    45,
      27,    45,    62,    63,    62,    62,    35,    41,    64,    39,
      45,    45,    45,    67,    17,    70,    39,    39,    39,    14,
      15,    35,    71,    72,    24,    76,    70,    70,    70,    35,
      73,    74,    73,    73,    18,    72,     4,     5,     6,    13,
      35,    38,    77,    78,    79,    40,    76,    76,    76,    27,
      41,    27,    27,    44,    44,    44,    44,    28,    33,    42,
      44,    16,    78,    82,    28,    33,    40,    40,    40,    74,
      35,    79,    22,    31,    34,    35,    36,    44,    79,    80,
      80,    80,    37,    80,    35,    80,    35,    79,    80,    25,
      37,    80,    35,    42,    45,    45,    80,    42,    44,    80,
      26,    29,    30,    32,    45,    45,    45,    44,    27,    43,
      45,    45,    27,    44,    27,    80,    27,    27,    80,    80,
      81,    45,    80,    80,    80,    80,    27,     7,    10,    45,
      28,    27,    27,    45,    43,    43,    41,    45,    77,    77,
      27,    80,    27,    45,    80,     8,     9,    11,    27,    27,
      77,    27,    27,     9,    27
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    52,    53,
      53,    54,    54,    54,    55,    55,    56,    57,    58,    58,
      59,    59,    59,    60,    60,    61,    61,    61,    62,    63,
      63,    64,    64,    65,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    70,    70,    71,    71,    72,
      72,    72,    73,    73,    74,    75,    76,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    79,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    81,    81,
      82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     0,     2,     1,     4,     1,     2,
       1,     3,     3,     3,     3,     1,     1,     3,     2,     1,
       3,     3,     3,     3,     1,     4,     1,     4,     1,     1,
       0,     3,     1,     2,     2,     2,     3,     1,     1,     2,
       2,     0,     9,     9,     9,     3,     0,     2,     1,     3,
       3,     3,     3,     1,     1,     8,     4,     2,     1,     4,
       7,     5,     5,     8,     5,     8,    10,     8,     6,     6,
       4,     5,     5,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     1,     4,     1,     1,     4,     3,     1,
       3
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
#line 48 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        interpret((yyvsp[-1].nptr));
                                                    }
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 53 "yacc_expl.y" /* yacc.c:1646  */
    {}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 54 "yacc_expl.y" /* yacc.c:1646  */
    {}
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 57 "yacc_expl.y" /* yacc.c:1646  */
    {}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 58 "yacc_expl.y" /* yacc.c:1646  */
    {}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 61 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //Creates a 'fieldlist' out of the intermediate list.
                                                        //Verifies for multiple declaration of variables.
                                                        //Verfifies if the type assigned to the used defined variables are declared before or is the current one under definition
                                                        Type_field_list_validate((yyvsp[-1].field));
                                                        (yyvsp[-3].ty)->fields = (yyvsp[-1].field);
                                                    }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 70 "yacc_expl.y" /* yacc.c:1646  */
    { (yyval.ty) = TInstall((yyvsp[0].nptr)->name,NULL);}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 72 "yacc_expl.y" /* yacc.c:1646  */
    { (yyval.field) = FAppend((yyvsp[-1].field), (yyvsp[0].field));}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 73 "yacc_expl.y" /* yacc.c:1646  */
    { (yyval.field) = (yyvsp[0].field); }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 76 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //Fills the Type pointer in the intermediate list with integer
                                                        AddFType(TLookUp("int"),(yyvsp[-1].field));
                                                        (yyval.field) = (yyvsp[-1].field);
                                                    }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 81 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //Fills the Type pointer in the intermediate list with string
                                                        AddFType(TLookUp("str"),(yyvsp[-1].field));
                                                        (yyval.field) = (yyvsp[-1].field);
                                                    }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 86 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //Fills the Type pointer in the intermediate list(IntermList) with the name of the given identifier($1)
                                                        Ttemp = TLookUp((yyvsp[-2].nptr)->name);
                                                        if(Ttemp == NULL){
                                                            yyerror("yacc (TypeDecl) : the type has not been defined");
                                                            printf(" %s",(yyvsp[-2].nptr)->name);
                                                            exit(1);
                                                        }
                                                        AddFType(Ttemp,(yyvsp[-1].field));
                                                        (yyval.field) = (yyvsp[-1].field);
                                                    }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 99 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //Creates an intermediate list(IntermList) containing the name of the given identifier
                                                        (yyvsp[0].field)->next = (yyvsp[-2].field);
                                                        (yyval.field) = (yyvsp[0].field);
                                                    }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 104 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //Creates an intermediate list(IntermList) containing the name of the given identifier
                                                        (yyval.field) = (yyvsp[0].field);
                                                    }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 110 "yacc_expl.y" /* yacc.c:1646  */
    {   (yyval.field) = FInstall((yyvsp[0].nptr)->name); }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 112 "yacc_expl.y" /* yacc.c:1646  */
    {}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 115 "yacc_expl.y" /* yacc.c:1646  */
    {}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 116 "yacc_expl.y" /* yacc.c:1646  */
    {}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 119 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //The Type field of the global symbol table entry is set to integer
                                                        AddGType(TLookUp("int"),(yyvsp[-1].gvar));
                                                        GAppend((yyvsp[-1].gvar));
                                                    }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 124 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //The type field of the global symbol table entry is set to string
                                                        AddGType(TLookUp("str"),(yyvsp[-1].gvar));
                                                        GAppend((yyvsp[-1].gvar));
                                                    }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 129 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //Type field of the global symbol table entry is set to the specified type.
                                                        //The specified type for used defined type is obtained from a call to
                                                        //TypeTableLookUp function.
                                                        Ttemp = TLookUp((yyvsp[-2].nptr)->name);
                                                        if(Ttemp == NULL){
                                                            yyerror("yacc : the type has not been defined");
                                                            printf(" %s",(yyvsp[-2].nptr)->name);
                                                            exit(1);
                                                        }
                                                        AddGType(Ttemp,(yyvsp[-1].gvar));
                                                        GAppend((yyvsp[-1].gvar));
                                                    }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 144 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //Binds together the global symbol tabe entries.
                                                        (yyvsp[0].gvar)->next = (yyvsp[-2].gvar);
                                                        (yyval.gvar) = (yyvsp[0].gvar);
                                                    }
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 149 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        (yyval.gvar) = (yyvsp[0].gvar);
                                                    }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 154 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //Creats a global symbol table entry
                                                        (yyval.gvar) = GInstall((yyvsp[-3].nptr)->name,NULL,(yyvsp[-1].nptr)->value.intval,NULL);
                                                    }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 158 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //Creates a global symbol table entry
                                                        (yyval.gvar) = GInstall((yyvsp[0].nptr)->name,NULL,1,NULL);
                                                    }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 162 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //Creates a global symbol table entry
                                                        (yyval.gvar) = GInstall((yyvsp[-3].nptr)->name,NULL,0,(yyvsp[-1].arg));
                                                    }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 168 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //A Local Symbol Table is created out the entries made.
                                                         (yyval.arg) = (yyvsp[0].arg);
                                                    }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 174 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        (yyval.arg) = (yyvsp[0].arg);
                                                    }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 177 "yacc_expl.y" /* yacc.c:1646  */
    { (yyval.arg) = NULL;}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 178 "yacc_expl.y" /* yacc.c:1646  */
    { (yyval.arg) = ArgAppend((yyvsp[0].arg), (yyvsp[-2].arg));}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 179 "yacc_expl.y" /* yacc.c:1646  */
    { (yyval.arg) = (yyvsp[0].arg);}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 182 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //The Type field in the ArgStruct entry is set to the specified type.
                                                        AddArgType(TLookUp("int"),(yyvsp[0].arg));
                                                        (yyval.arg) = (yyvsp[0].arg);
                                                    }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 187 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //The Type field in the ArgStruct entry is set to the specified type.
                                                        AddArgType(TLookUp("str"),(yyvsp[0].arg));
                                                        (yyval.arg) = (yyvsp[0].arg);
                                                    }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 192 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //The Type field in the ArgStruct entry is set to the specified type.
                                                        Ttemp = TLookUp((yyvsp[-1].nptr)->name);
                                                        if(Ttemp == NULL){
                                                            yyerror("yacc (argType 2): the type has not been defined");
                                                            printf(" %s",(yyvsp[-1].nptr)->name);
                                                            exit(1);
                                                        }
                                                        AddArgType(Ttemp,(yyvsp[0].arg));
                                                        (yyval.arg) = (yyvsp[0].arg);
                                                    }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 205 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //Appends newly created entries to the existing.
                                                        (yyvsp[0].arg)->next = (yyvsp[-2].arg);
                                                        (yyval.arg) = (yyvsp[0].arg);
                                                    }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 210 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        (yyval.arg) = (yyvsp[0].arg);
                                                    }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 215 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //Creates an ArgStruct entry containing name of the identifier.
                                                        (yyval.arg) = ArgInstall((yyvsp[0].nptr)->name,NULL,PASS_BY_VAL);
                                                    }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 219 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        (yyval.arg) = ArgInstall((yyvsp[0].nptr)->name,NULL,PASS_BY_REF);
                                                    }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 224 "yacc_expl.y" /* yacc.c:1646  */
    {}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 225 "yacc_expl.y" /* yacc.c:1646  */
    {}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 228 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                          //Function definition is compared with their declarartion earlier for compatibility
                                                          //Lentry is set to the LST of the function
                                                          //LST is set to NULL
                                                          AddArgsToLTable(&((yyvsp[-2].lvar)), (yyvsp[-5].arg));
                                                          setVariableType((yyvsp[-7].nptr), IS_ARRAY_FALSE);
                                                          validate_function((yyvsp[-7].nptr)->name,TLookUp("int"),(yyvsp[-5].arg),(yyvsp[-1].nptr));
                                                          Gtemp = Glookup((yyvsp[-7].nptr)->name);
                                                          if(Gtemp == NULL){
                                                              yyerror("Yacc : undeclared function");exit(1);
                                                          }
                                                          (yyvsp[-1].nptr)->Lentry = (yyvsp[-2].lvar);  //Body's Lentry has the local symbol table
                                                          Gtemp->fbinding = (yyvsp[-1].nptr);
                                                          LSymbolHead = NULL;
                                                        }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 243 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                          //Function definition is compared with their declarartion earlier for compatibility
                                                          //Lentry is set to the LST of the function
                                                          //LST is set to NULL
                                                          AddArgsToLTable(&((yyvsp[-2].lvar)), (yyvsp[-5].arg));
                                                          setVariableType((yyvsp[-7].nptr), IS_ARRAY_FALSE);
                                                          validate_function((yyvsp[-7].nptr)->name,TLookUp("str"),(yyvsp[-5].arg),(yyvsp[-1].nptr));
                                                          Gtemp = Glookup((yyvsp[-7].nptr)->name);
                                                          if(Gtemp == NULL){
                                                              yyerror("Yacc : undeclared function");exit(1);
                                                          }
                                                          (yyvsp[-1].nptr)->Lentry = (yyvsp[-2].lvar);
                                                          Gtemp->fbinding = (yyvsp[-1].nptr);
                                                          LSymbolHead = NULL;
                                                        }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 258 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                          //Function definition is compared with their declarartion earlier for compatibility
                                                          //Lentry is set to the LST of the function
                                                          //LST is set to NULL
                                                          Ttemp = TLookUp((yyvsp[-8].nptr)->name);
                                                          setVariableType((yyvsp[-7].nptr), IS_ARRAY_FALSE);
                                                          if(Ttemp == NULL){
                                                              yyerror("yacc(Fdef) : the return type has not been defined");
                                                              printf(" %s",(yyvsp[-8].nptr)->name);
                                                              exit(1);
                                                          }
                                                          AddArgsToLTable(&((yyvsp[-2].lvar)), (yyvsp[-5].arg));
                                                          validate_function((yyvsp[-7].nptr)->name,Ttemp,(yyvsp[-5].arg),(yyvsp[-1].nptr));
                                                          Gtemp = Glookup((yyvsp[-7].nptr)->name);
                                                          if(Gtemp == NULL){
                                                              yyerror("Yacc : undeclared function");exit(1);
                                                          }
                                                          (yyvsp[-1].nptr)->Lentry = (yyvsp[-2].lvar);
                                                          Gtemp->fbinding = (yyvsp[-1].nptr);
                                                          LSymbolHead = NULL;
                                                        }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 281 "yacc_expl.y" /* yacc.c:1646  */
    {
                                      setLocalBindings((yyvsp[-1].lvar));
                                      (yyval.lvar) = (yyvsp[-1].lvar);
                                      LSymbolHead = (yyval.lvar);
                                  }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 286 "yacc_expl.y" /* yacc.c:1646  */
    {}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 289 "yacc_expl.y" /* yacc.c:1646  */
    { (yyval.lvar) = LAppend((yyvsp[-1].lvar), (yyvsp[0].lvar)); }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 290 "yacc_expl.y" /* yacc.c:1646  */
    {  (yyval.lvar) = (yyvsp[0].lvar);  }
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 293 "yacc_expl.y" /* yacc.c:1646  */
    {
                            //Fills the Type field of the local symbol table entry with integer.
                            AddLType(TLookUp("int"),(yyvsp[-1].lvar));
                            (yyval.lvar) = (yyvsp[-1].lvar);
                          }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 298 "yacc_expl.y" /* yacc.c:1646  */
    {
                            //Fills the Type field of the local symbol table entry with string.
                            AddLType(TLookUp("str"),(yyvsp[-1].lvar));
                            (yyval.lvar) = (yyvsp[-1].lvar);
                          }
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 303 "yacc_expl.y" /* yacc.c:1646  */
    {
                            //Fills the Type field of the Local symbol table with the specified user defined type.
                            AddLType(TLookUp((yyvsp[-2].nptr)->name),(yyvsp[-1].lvar));
                            (yyval.lvar) = (yyvsp[-1].lvar);
                          }
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 310 "yacc_expl.y" /* yacc.c:1646  */
    {
                            //Appends newly created local symbol table entries to the existing.
                            if(LlookupInTable((yyvsp[-2].lvar), (yyvsp[0].lvar)->name) != NULL){
                              yyerror("LInstall : Local variable redefined ");
                              printf(" %s",(yyvsp[0].lvar)->name);
                              exit(1);
                            }
                            (yyvsp[0].lvar)->next = (yyvsp[-2].lvar);
                            (yyval.lvar) = (yyvsp[0].lvar);
                          }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 320 "yacc_expl.y" /* yacc.c:1646  */
    {
                            (yyval.lvar) = (yyvsp[0].lvar);
                          }
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 325 "yacc_expl.y" /* yacc.c:1646  */
    {
                //Creates a Local Symbol Table entry containing the name of the identifier
                (yyval.lvar) = LInstall((yyvsp[0].nptr)->name,NULL);
            }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 331 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                        //Verifies if the type of the return statemnt is of type integer
                                                        //calls interpreter
                                                        (yyvsp[-1].nptr)->Lentry = (yyvsp[-2].lvar);
                                                        Gtemp = GInstall("MAIN",TLookUp("int"),0, NULL);
                                                        Gtemp->fbinding = (yyvsp[-1].nptr);
                                                        GAppend(Gtemp);
                                                        (yyval.nptr) = TreeCreate(TLookUp("int"), NODETYPE_MAIN, Gtemp->name, (Constant){}, NULL, (yyvsp[-1].nptr), NULL, NULL);
                                                        (yyval.nptr)->Gentry = Gtemp;
                                                        LSymbolHead = NULL;
                                                    }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 344 "yacc_expl.y" /* yacc.c:1646  */
    {
                                //Return statement is set as Ptr2 of slist
                                (yyval.nptr) = TreeCreate(TLookUp("void"), NODETYPE_BODY, NULL, (Constant){}, NULL, (yyvsp[-2].nptr), (yyvsp[-1].nptr), NULL);
                            }
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 350 "yacc_expl.y" /* yacc.c:1646  */
    {
                                //Appends newly created statement node to the existing.
                                (yyval.nptr) = TreeCreate(TLookUp("void"), NODETYPE_NONE, NULL, (Constant){}, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                            }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 354 "yacc_expl.y" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 357 "yacc_expl.y" /* yacc.c:1646  */
    {
                                setVariableType((yyvsp[-3].nptr), IS_ARRAY_FALSE);
                                //Verifies if the LHS and RHS of the assignment node is of the same type.
                                (yyval.nptr) = TreeCreate(TLookUp("void"), NODETYPE_ASGN, NULL, (Constant){}, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                            }
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 362 "yacc_expl.y" /* yacc.c:1646  */
    {
                                        //Verifies if the LHS and RHS of the Assignment node is of the same type.
                                        //Also type checks for array
                                        (yyval.nptr) = TreeCreate(TLookUp("void"), NODETYPE_ARR_ASGN, NULL, (Constant){}, NULL, (yyvsp[-6].nptr), (yyvsp[-4].nptr), (yyvsp[-1].nptr));
                                    }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 368 "yacc_expl.y" /* yacc.c:1646  */
    {
                                    //Verifies if the identifier is of type integer or string
                                    setVariableType((yyvsp[-2].nptr), IS_ARRAY_FALSE);
                                    (yyval.nptr) = TreeCreate(TLookUp("void"), NODETYPE_READ, NULL, (Constant){}, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 373 "yacc_expl.y" /* yacc.c:1646  */
    {
                                    //Verifies if the FIELD is of type integer or string
                                    (yyval.nptr) = TreeCreate(TLookUp("void"), NODETYPE_FIELD_READ, NULL, (Constant){}, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                }
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 377 "yacc_expl.y" /* yacc.c:1646  */
    {
                                            //Verifies if the identifier is of type integer or string. //Being an array, Expression node has to be of type integer.
                                            (yyval.nptr) = TreeCreate(TLookUp("void"), NODETYPE_ARR_READ, NULL, (Constant){}, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                                        }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 381 "yacc_expl.y" /* yacc.c:1646  */
    {
                                        //Verifies if the Expression node is of type integer or string
                                        (yyval.nptr) = TreeCreate(TLookUp("void"), NODETYPE_WRITE, NULL, (Constant){}, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                    }
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 385 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                (yyval.nptr) = TreeCreate(TLookUp("void"), NODETYPE_IF, NULL, (Constant){},NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                            }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 388 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                            //Verifies if the Conditional Expression node is of boolean type.
                                                            //Verifies if the Conditional Expression node is of boolean type
                                                            (yyval.nptr) = TreeCreate(TLookUp("void"), NODETYPE_IF, NULL, (Constant){},NULL, (yyvsp[-7].nptr), (yyvsp[-4].nptr), (yyvsp[-2].nptr));
                                                        }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 393 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                    //Verifies if the Conditional Expression node is of boolean type.
                                                    (yyval.nptr) = TreeCreate(TLookUp("void"), NODETYPE_WHILE, NULL, (Constant){}, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                }
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 397 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                    //Verifies if the identifier is of user defined type
                                                    setVariableType((yyvsp[-5].nptr), IS_ARRAY_FALSE);
                                                    (yyval.nptr) = TreeCreate(TLookUp("void"),NODETYPE_ALLOC,NULL,(Constant){},NULL,(yyvsp[-5].nptr),NULL,NULL);
                                                }
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 402 "yacc_expl.y" /* yacc.c:1646  */
    {
                                                    //Verifies if the FIELD is of user defined type.
                                                    (yyval.nptr) = TreeCreate(TLookUp("void"),NODETYPE_ALLOC,NULL,(Constant){},NULL,(yyvsp[-5].nptr),NULL,NULL);
                                                }
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 406 "yacc_expl.y" /* yacc.c:1646  */
    {
                                            //Verifies if the left hand side and right hand side of the Assignment statement is of same type.
                                            (yyval.nptr) = TreeCreate(TLookUp("void"), NODETYPE_FIELD_ASGN, NULL, (Constant){}, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                        }
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 410 "yacc_expl.y" /* yacc.c:1646  */
    {
                                            //Verifies if the field is of user defined type.
                                            setVariableType((yyvsp[-2].nptr), IS_ARRAY_FALSE);
                                            (yyval.nptr) = TreeCreate(TLookUp("void"),NODETYPE_DEALLOC,NULL,(Constant){},NULL,(yyvsp[-2].nptr),NULL,NULL);
                                        }
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 415 "yacc_expl.y" /* yacc.c:1646  */
    {
                                            //Verifies if the FIELD is of user defined type.
                                            (yyval.nptr) = TreeCreate(TLookUp("void"),NODETYPE_DEALLOC,NULL,(Constant){},NULL,(yyvsp[-2].nptr),NULL,NULL);
                                        }
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 421 "yacc_expl.y" /* yacc.c:1646  */
    {
                            //The Type field for the identifiers are set.
                            //Example: In the reduction of a.b, the Type field of a is set based on the symbol table entry.
                            //The Type field of b is set to that specified in the fieldlist of the Typetable entry for a
                            (yyval.nptr) = TreeCreate(TLookUp("void"), NODETYPE_FIELD, NULL, (Constant){}, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 427 "yacc_expl.y" /* yacc.c:1646  */
    {
                            (yyval.nptr) = TreeCreate(TLookUp("void"), NODETYPE_FIELD, NULL, (Constant){}, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 432 "yacc_expl.y" /* yacc.c:1646  */
    {
                            //Verifies if both the expression is of type integer
                            (yyval.nptr) = TreeCreate(TLookUp("int"), (yyvsp[-1].nptr)->nodetype, NULL, (Constant){}, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 436 "yacc_expl.y" /* yacc.c:1646  */
    {
                            //Verifies if both the expression is of type integer
                            (yyval.nptr) = TreeCreate(TLookUp("int"), (yyvsp[-1].nptr)->nodetype, NULL, (Constant){}, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 440 "yacc_expl.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[-1].nptr);}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 441 "yacc_expl.y" /* yacc.c:1646  */
    {
                            (yyval.nptr) = TreeCreate(TLookUp("boolean"), (yyvsp[-1].nptr)->nodetype, NULL, (Constant){}, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 444 "yacc_expl.y" /* yacc.c:1646  */
    {
                            //Verifies if both the expression is of type boolean
                            (yyval.nptr) = TreeCreate(TLookUp("boolean"), (yyvsp[-1].nptr)->nodetype, NULL, (Constant){}, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 448 "yacc_expl.y" /* yacc.c:1646  */
    {
                            //Verifies if the expression is of type boolean or null
                            (yyval.nptr) = TreeCreate(TLookUp("boolean"), NODETYPE_NOT, NULL, (Constant){}, NULL, (yyvsp[0].nptr), NULL, NULL);
                        }
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 452 "yacc_expl.y" /* yacc.c:1646  */
    {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 453 "yacc_expl.y" /* yacc.c:1646  */
    {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 454 "yacc_expl.y" /* yacc.c:1646  */
    {
                            //type field of the identifier is set to that specified in the symbol table.
                            setVariableType((yyvsp[0].nptr), IS_ARRAY_FALSE);
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 459 "yacc_expl.y" /* yacc.c:1646  */
    {
                            //Type field in the ASTnode is set to that specified in the symbol table.
                            //Verifies if the expression node is an integer
                            (yyval.nptr) = TreeCreate(NULL, NODETYPE_ARR_ID, NULL, (Constant){}, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                        }
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 464 "yacc_expl.y" /* yacc.c:1646  */
    {
                            //The Type field of the identifier is from the fieldlist entry of the TypeTable.
                            //Verifies for the parameter compatibility in function declaration and calling.
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 469 "yacc_expl.y" /* yacc.c:1646  */
    {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 470 "yacc_expl.y" /* yacc.c:1646  */
    {
                            //Type of the identifier is set to that specified in the global symbol table during declaration.
                            //The Argument list created before is set to the Arglist field.
                            setVariableType((yyvsp[-3].nptr), IS_ARRAY_FALSE);
                            Gtemp = Glookup((yyvsp[-3].nptr)->name);
                            if(Gtemp == NULL){
                                yyerror("Yacc : Undefined function");
                                printf(" %s",(yyvsp[-3].nptr)->name);
                                exit(1);
                            }
                            (yyval.nptr) = TreeCreate(Gtemp->type,NODETYPE_FUNCTION,(yyvsp[-3].nptr)->name,(Constant){},(yyvsp[-1].nptr),NULL,NULL,NULL);
                            (yyval.nptr)->Gentry = Gtemp;
                        }
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 485 "yacc_expl.y" /* yacc.c:1646  */
    {
                        //Creates a statement node and its Ptr1 field is set to the expression node.
                        //Appends the newly created parameter list to the existing.
                        (yyval.nptr) = TreeCreate(TLookUp("void"),NODETYPE_PARAM,NULL,(Constant){},NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);

                    }
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 491 "yacc_expl.y" /* yacc.c:1646  */
    {
                        //Creates a statement node and its Ptr1 field is set to the expression node.
                        (yyval.nptr) = TreeCreate(TLookUp("void"),NODETYPE_PARAM,NULL,(Constant){},NULL,(yyvsp[0].nptr),NULL,NULL);
                    }
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 497 "yacc_expl.y" /* yacc.c:1646  */
    {
                            //Appends expression to the return statement.
                            (yyval.nptr) = TreeCreate((yyvsp[-1].nptr)->type, NODETYPE_RET,NULL,(Constant){},NULL,(yyvsp[-1].nptr),NULL,NULL);
                         }
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2308 "y.tab.c" /* yacc.c:1646  */
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
#line 503 "yacc_expl.y" /* yacc.c:1906  */


int main(int argc,char* argv[]) {
    TTableCreate();
    if(argc>1)
    {
        FILE *file = fopen(argv[1],"r");
        if(file)
            yyin = file;
    }
    yyparse();
    return 0;
}
