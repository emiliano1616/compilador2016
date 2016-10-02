
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
#line 1 "syntax.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "structs.h"
#include "defines.h"
#include "arbol.h"
#include "pila.h"
#include "cola.h"
#include "ts.h"
#include "funciones.h"

#define DEBUG 1
extern YYSTYPE yylval;
char temp_variables[MAX_VARIABLES][30];
// char temp_tipo_dato[MAX_VARIABLES][10];
char temp_tipo_dato[10];
int variables_a_agregar= 0;


extern int linecount;

t_pila_de_colas * pila_de_colas;
t_pila * pila_bloques;
t_cola * cola_sentencias;
t_pila * pila_comparaciones;
t_pila * pila_condiciones;
t_pila * pila_expresiones;
t_pila * pila_factores;
t_pila * pila_terminos;
t_pila_asm * pila_whiles;

t_arbol * arbol_ejecucion;
t_nodo_arbol * nodo_between;
t_nodo_arbol * nodo_average;
t_nodo_arbol * nodo_factor;
t_nodo_arbol * nodo_termino;
t_nodo_arbol * nodo_expresion;
t_nodo_arbol * nodo_asignacion;
t_nodo_arbol * nodo_condicion;
t_nodo_arbol * nodo_comparacion;
t_nodo_arbol * nodo_pgm;
t_nodo_arbol * nodo_programa;
t_nodo_arbol * nodo_sentencia;
t_nodo_arbol * nodo_sentencias;
t_nodo_arbol * nodo_comparador;
t_nodo_arbol * nodo_condicional;
t_nodo_arbol * nodo_iteracion;
t_nodo_arbol * nodo_io;
t_nodo_arbol * nodo_entrada;
t_nodo_arbol * nodo_salida;
t_nodo_arbol * nodo_declaracion_variable;
t_nodo_arbol * nodo_sentencias_then;
t_nodo_arbol * nodo_sentencias_else;
t_nodo_arbol * nodo_then;
t_nodo_arbol * nodo_asm_while;


int yylex();

FILE  *yyin; //Archivo de Entrada


/* Line 189 of yacc.c  */
#line 138 "y.tab.c"

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
     TOKEN_ID = 258,
     CONST_INT = 259,
     CONST_STR = 260,
     CONST_FLOAT = 261,
     PR_MAIN = 262,
     PR_WRITE = 263,
     PR_READ = 264,
     PR_IF = 265,
     PR_THEN = 266,
     PR_ENDIF = 267,
     PR_ELSE = 268,
     PR_NOT = 269,
     PR_WHILE = 270,
     PR_DO = 271,
     PR_ENDWHILE = 272,
     PR_AVERAGE = 273,
     PR_DECVAR = 274,
     PR_ENDDEC = 275,
     PR_BETWEEN = 276,
     PAR_ABRE = 277,
     PAR_CIERRA = 278,
     COR_ABRE = 279,
     COR_CIERRA = 280,
     COMA = 281,
     OP_LOG_AND = 282,
     OP_LOG_OR = 283,
     OP_SUMA = 284,
     OP_RESTA = 285,
     OP_MUL = 286,
     OP_DIV = 287,
     OP_MAYOR = 288,
     OP_MAYOR_IGUAL = 289,
     OP_MENOR = 290,
     OP_MENOR_IGUAL = 291,
     OP_DISTINTO = 292,
     OP_IGUAL_IGUAL = 293,
     OP_IGUAL = 294,
     PR_AS = 295,
     PR_DIM = 296,
     PR_FLOAT = 297,
     PR_INT = 298,
     PR_STRING = 299,
     OP_CONCAT = 300,
     PUNTO_Y_COMA = 301,
     DOS_PUNTOS = 302
   };
#endif
/* Tokens.  */
#define TOKEN_ID 258
#define CONST_INT 259
#define CONST_STR 260
#define CONST_FLOAT 261
#define PR_MAIN 262
#define PR_WRITE 263
#define PR_READ 264
#define PR_IF 265
#define PR_THEN 266
#define PR_ENDIF 267
#define PR_ELSE 268
#define PR_NOT 269
#define PR_WHILE 270
#define PR_DO 271
#define PR_ENDWHILE 272
#define PR_AVERAGE 273
#define PR_DECVAR 274
#define PR_ENDDEC 275
#define PR_BETWEEN 276
#define PAR_ABRE 277
#define PAR_CIERRA 278
#define COR_ABRE 279
#define COR_CIERRA 280
#define COMA 281
#define OP_LOG_AND 282
#define OP_LOG_OR 283
#define OP_SUMA 284
#define OP_RESTA 285
#define OP_MUL 286
#define OP_DIV 287
#define OP_MAYOR 288
#define OP_MAYOR_IGUAL 289
#define OP_MENOR 290
#define OP_MENOR_IGUAL 291
#define OP_DISTINTO 292
#define OP_IGUAL_IGUAL 293
#define OP_IGUAL 294
#define PR_AS 295
#define PR_DIM 296
#define PR_FLOAT 297
#define PR_INT 298
#define PR_STRING 299
#define OP_CONCAT 300
#define PUNTO_Y_COMA 301
#define DOS_PUNTOS 302




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 66 "syntax.y"

int intval;
float val;
char *str_val;



/* Line 214 of yacc.c  */
#line 276 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 288 "y.tab.c"

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
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   119

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNRULES -- Number of states.  */
#define YYNSTATES  117

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     9,    12,    15,    18,    21,    23,
      26,    28,    30,    33,    44,    51,    53,    57,    59,    61,
      64,    67,    70,    77,    85,    88,    91,    93,    97,   101,
     105,   108,   116,   120,   124,   126,   130,   134,   136,   140,
     144,   146,   148,   150,   152,   154,   159,   164,   170,   172,
     176,   178,   180,   182,   184,   186,   188,   190,   192
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    50,    -1,     7,    69,    52,    -1,     7,
      52,    -1,    65,    46,    -1,    53,    46,    -1,    54,    46,
      -1,    51,    -1,    51,    52,    -1,    59,    -1,    64,    -1,
      56,    46,    -1,    21,    22,     3,    26,    24,    66,    46,
      66,    25,    23,    -1,    18,    22,    24,    55,    25,    23,
      -1,    66,    -1,    66,    26,    55,    -1,    57,    -1,    58,
      -1,     9,     3,    -1,     8,     3,    -1,     8,     5,    -1,
      10,    22,    62,    23,    60,    12,    -1,    10,    22,    62,
      23,    60,    61,    12,    -1,    11,    52,    -1,    13,    52,
      -1,    63,    -1,    63,    27,    63,    -1,    63,    28,    63,
      -1,    66,    73,    66,    -1,    14,    66,    -1,    15,    22,
      62,    23,    16,    52,    17,    -1,     3,    39,    66,    -1,
      68,    45,    68,    -1,    67,    -1,    66,    29,    67,    -1,
      66,    30,    67,    -1,    68,    -1,    67,    32,    68,    -1,
      67,    31,    68,    -1,    53,    -1,     5,    -1,     4,    -1,
       6,    -1,     3,    -1,    19,    70,    20,    46,    -1,    71,
      47,    72,    46,    -1,    71,    47,    72,    46,    70,    -1,
       3,    -1,     3,    26,    71,    -1,    43,    -1,    42,    -1,
      44,    -1,    33,    -1,    35,    -1,    36,    -1,    34,    -1,
      38,    -1,    37,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   131,   131,   138,   150,   158,   174,   190,   207,   220,
     240,   261,   280,   293,   321,   336,   344,   353,   364,   373,
     388,   405,   415,   428,   443,   453,   462,   478,   497,   515,
     539,   553,   568,   590,   641,   658,   690,   723,   737,   771,
     806,   819,   840,   862,   882,   901,   910,   919,   935,   948,
    1021,  1037,  1052,  1067,  1076,  1085,  1096,  1105,  1114
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_ID", "CONST_INT", "CONST_STR",
  "CONST_FLOAT", "PR_MAIN", "PR_WRITE", "PR_READ", "PR_IF", "PR_THEN",
  "PR_ENDIF", "PR_ELSE", "PR_NOT", "PR_WHILE", "PR_DO", "PR_ENDWHILE",
  "PR_AVERAGE", "PR_DECVAR", "PR_ENDDEC", "PR_BETWEEN", "PAR_ABRE",
  "PAR_CIERRA", "COR_ABRE", "COR_CIERRA", "COMA", "OP_LOG_AND",
  "OP_LOG_OR", "OP_SUMA", "OP_RESTA", "OP_MUL", "OP_DIV", "OP_MAYOR",
  "OP_MAYOR_IGUAL", "OP_MENOR", "OP_MENOR_IGUAL", "OP_DISTINTO",
  "OP_IGUAL_IGUAL", "OP_IGUAL", "PR_AS", "PR_DIM", "PR_FLOAT", "PR_INT",
  "PR_STRING", "OP_CONCAT", "PUNTO_Y_COMA", "DOS_PUNTOS", "$accept", "pgm",
  "programa", "sentencia", "lista_sentencias", "between", "average",
  "lista_expresiones", "io", "entrada", "salida", "condicional", "then",
  "else", "condicion", "comparacion", "iteracion", "asignacion",
  "expresion", "termino", "factor", "declaracion_variables",
  "linea_de_declaracion_de_tipos", "lista_variables", "tipo_dato",
  "comparador", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    52,    52,
      51,    51,    51,    53,    54,    55,    55,    56,    56,    57,
      58,    58,    59,    59,    60,    61,    62,    62,    62,    63,
      63,    64,    65,    66,    66,    66,    66,    67,    67,    67,
      68,    68,    68,    68,    68,    69,    70,    70,    71,    71,
      72,    72,    72,    73,    73,    73,    73,    73,    73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     2,     2,     2,     2,     1,     2,
       1,     1,     2,    10,     6,     1,     3,     1,     1,     2,
       2,     2,     6,     7,     2,     2,     1,     3,     3,     3,
       2,     7,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     1,     1,     1,     1,     4,     4,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     4,     0,     0,     0,    17,    18,    10,
      11,     0,     0,     1,     0,    20,    21,    19,     0,     0,
       0,    48,     0,     0,     0,     9,     6,     7,    12,     5,
       3,    44,    42,    41,    43,    40,    32,    34,    37,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,     0,     0,    53,    56,
      54,    55,    58,    57,     0,     0,     0,    15,    49,    45,
      51,    50,    52,     0,     0,    35,    37,    36,    39,    38,
      33,     0,     0,    27,    28,    29,     0,     0,     0,    46,
       0,    24,    22,     0,     0,     0,    14,    16,    47,     0,
      25,    23,    31,     0,     0,     0,    13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    12,    13,    45,    15,    76,    16,    17,
      18,    19,    92,   104,    50,    51,    20,    21,    52,    47,
      48,    22,    32,    33,    83,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -22
static const yytype_int8 yypact[] =
{
      -3,    -2,    18,   -22,   -16,    19,    31,    27,    38,    56,
      44,    58,    17,   -22,    41,    42,    43,   -22,   -22,   -22,
     -22,    45,    17,   -22,    40,   -22,   -22,   -22,    36,    36,
      70,    71,    76,    51,    96,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,     0,     5,    55,    40,
      78,    46,    29,    80,    40,    44,    59,    12,    81,    40,
      40,    40,    40,    40,     0,    93,    36,    36,   -22,   -22,
     -22,   -22,   -22,   -22,    40,    90,    83,    22,   -22,   -22,
     -22,   -22,   -22,    64,    85,     5,   -22,     5,   -22,   -22,
     -22,    17,    63,   -22,   -22,     0,    17,    88,    40,    44,
      40,   -22,   -22,    17,   100,    97,   -22,   -22,   -22,   -15,
     -22,   -22,   -22,    40,   -20,    92,   -22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -22,   -22,   -22,   -22,   -10,    -1,   -22,    15,   -22,   -22,
     -22,   -22,   -22,   -22,    87,    16,   -22,   -22,   -21,    25,
       9,   -22,    20,    62,   -22,   -22
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      14,     4,    35,    46,     1,   115,     5,     6,     7,    59,
      60,    14,    40,     8,    59,    60,     9,    10,    23,    11,
       4,    14,    25,    24,    26,     5,     6,     7,    64,    59,
      60,   113,     8,    77,    27,     9,    61,    62,    11,    41,
      42,    43,    44,    41,    42,    43,    44,    31,    98,    28,
      49,    59,    60,    95,    80,    81,    82,    11,    59,    60,
      29,    11,    68,    69,    70,    71,    72,    73,    86,    86,
      88,    89,    90,    66,    67,   102,   103,    77,    30,   109,
      34,   101,    93,    94,    85,    87,   105,    36,    37,    38,
      14,    39,   114,   110,    54,    14,    56,    55,    57,    58,
      63,    65,    14,    75,    91,    79,    96,    84,    97,   100,
      99,   106,   111,   107,   112,   116,    53,    78,     0,   108
};

static const yytype_int8 yycheck[] =
{
       1,     3,    12,    24,     7,    25,     8,     9,    10,    29,
      30,    12,    22,    15,    29,    30,    18,    19,     0,    21,
       3,    22,     3,    39,     5,     8,     9,    10,    49,    29,
      30,    46,    15,    54,     3,    18,    31,    32,    21,     3,
       4,     5,     6,     3,     4,     5,     6,     3,    26,    22,
      14,    29,    30,    74,    42,    43,    44,    21,    29,    30,
      22,    21,    33,    34,    35,    36,    37,    38,    59,    60,
      61,    62,    63,    27,    28,    12,    13,    98,    22,   100,
      22,    91,    66,    67,    59,    60,    96,    46,    46,    46,
      91,    46,   113,   103,    24,    96,    20,    26,    47,     3,
      45,    23,   103,    23,    11,    46,    16,    26,    25,    24,
      46,    23,    12,    98,    17,    23,    29,    55,    -1,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    49,    50,     3,     8,     9,    10,    15,    18,
      19,    21,    51,    52,    53,    54,    56,    57,    58,    59,
      64,    65,    69,     0,    39,     3,     5,     3,    22,    22,
      22,     3,    70,    71,    22,    52,    46,    46,    46,    46,
      52,     3,     4,     5,     6,    53,    66,    67,    68,    14,
      62,    63,    66,    62,    24,    26,    20,    47,     3,    29,
      30,    31,    32,    45,    66,    23,    27,    28,    33,    34,
      35,    36,    37,    38,    73,    23,    55,    66,    71,    46,
      42,    43,    44,    72,    26,    67,    68,    67,    68,    68,
      68,    11,    60,    63,    63,    66,    16,    25,    26,    46,
      24,    52,    12,    13,    61,    52,    23,    55,    70,    66,
      52,    12,    17,    46,    66,    25,    23
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
#line 132 "syntax.y"
    {
	nodo_pgm = nodo_programa;
	puts("COMPILACION EXITOSA\n");
	puts("-------------------\n");
}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 139 "syntax.y"
    {

	// nodo_declaracion_variable = nodo_sentencias;

	if(DEBUG){
		puts("Codigo con variables\n");
		puts("-------------------\n");
	}

}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 151 "syntax.y"
    {
	if(DEBUG){
		puts("Codigo sin variables\n");
		puts("-------------------\n");
	}
}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 159 "syntax.y"
    {
	if(DEBUG) {
		puts("sentencia : asignacion PUNTO_Y_COMA\n");
		puts("-------------------\n");		
	}


	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_asignacion,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
	// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);


}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 175 "syntax.y"
    {
	if(DEBUG) {
		puts("sentencia : between PUNTO_Y_COMA\n");
		puts("-------------------\n");		
	}


	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_between,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
	// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);


}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 191 "syntax.y"
    {
	if(DEBUG) {
		puts("sentencia : average PUNTO_Y_COMA\n");
		puts("-------------------\n");		
	}


	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_average,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
	// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);


}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 208 "syntax.y"
    {
	if(DEBUG){
		puts("Una sola sentencia\n");
		puts("-------------------\n");
		// printf("la pila esta vacia? %d\n",pila_vacia(&cola_sentencias) );
	}
		t_info_sentencias * sentencia_apilada = sacar_de_cola(&cola_sentencias);
		nodo_sentencias = sentencia_apilada->a;
		// puts("sacando de cola");
		// recorrer_en_orden(sentencia_apilada->a,&visitar);
}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 221 "syntax.y"
    {
	// if(DEBUG) {
		puts("Varias sentencias\n");
		puts("-------------------\n");
	// }
	// nodo_sentencias = nodo_sentencia;
	// nodo_sentencias->nodo_der = nodo_sentencia;
	t_info_sentencias * sentencia_apilada = sacar_de_cola(&cola_sentencias);
	nodo_sentencias->nodo_der = sentencia_apilada->a;
	nodo_sentencias->nodo_der->padre = nodo_sentencias;
	nodo_sentencias = sentencia_apilada->a;
		// puts("sacando de cola");
		// recorrer_en_orden(sentencia_apilada->a,&visitar);



	// nodo_sentencias = crear_nodo_arbol(crear_info("NUEVA"),nodo_sentencias,sentencia_apilada->a);
}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 241 "syntax.y"
    {

	// nodo_sentencia = nodo_condicional;
	if(DEBUG) {
		puts("sentencia : condicional \n");
		puts("-------------------\n");		
	}
	
	//para esta altura todas las sentencias del bloque deberian haber sido desencoladas
	printf("La cola de sentencias esta vacia? %d\n",cola_vacia(&cola_sentencias));
	cola_sentencias = sacar_de_pila_de_colas(&pila_de_colas);

	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_condicional,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
	// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);

}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 262 "syntax.y"
    {
	if(DEBUG) {
		puts("sentencia : iteracion\n");
		puts("-------------------\n");		
	}

	//para esta altura todas las sentencias del bloque deberian haber sido desencoladas
	printf("La cola de sentencias esta vacia? %d\n",cola_vacia(&cola_sentencias));
	cola_sentencias = sacar_de_pila_de_colas(&pila_de_colas);

	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_iteracion,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
		// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);
	// print_t(nodo_sentencia);
	// nodo_sentencia = nodo_iteracion;
}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 281 "syntax.y"
    {
	if(DEBUG) {
		puts("Operacion de entrada salidas\n");
		puts("-------------------\n");		
	}
	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_io,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
		// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);
}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 294 "syntax.y"
    {
	if(DEBUG) {
		puts("between : PR_BETWEEN  PAR_ABRE TOKEN_ID COMA COR_ABRE expresion PUNTO_Y_COMA expresion COR_CIERRA PAR_CIERRA\n");
		puts("-------------------\n");		
	}

	t_info_sentencias * p_info1 = sacar_de_pila(&pila_expresiones);
	t_info_sentencias * p_info2 = sacar_de_pila(&pila_expresiones);


	t_nodo_arbol * p_if_cond1 = crear_nodo_arbol(crear_info("<"),crear_hoja(crear_info((yyvsp[(3) - (10)].str_val))),p_info1->a);
	t_nodo_arbol * p_if_cond2 = crear_nodo_arbol(crear_info(">"),crear_hoja(crear_info((yyvsp[(3) - (10)].str_val))),p_info2->a);

	t_nodo_arbol * p_if = crear_nodo_arbol(crear_info("AND"),p_if_cond1,p_if_cond2);



	t_nodo_arbol * p_if_then = crear_nodo_arbol(crear_info("<V.F>"),crear_hoja(crear_info("1")),crear_hoja(crear_info("0")));



	nodo_between = crear_nodo_arbol(crear_info("BETWEEN"),p_if,p_if_then);



}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 322 "syntax.y"
    {
	if(DEBUG) {
		puts("average : PR_AVERAGE PAR_ABRE COR_ABRE lista_expresiones COR_CIERRA PAR_CIERRA \n");
		puts("-------------------\n");
	}

	while(!pila_vacia(&pila_expresiones) )
	{
		t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);
		// printf("asdasd\n");
	}

}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 337 "syntax.y"
    {
	if(DEBUG) {
		puts("lista_expresiones : expresion \n");
		puts("-------------------\n");
	}
}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 345 "syntax.y"
    {
	if(DEBUG) {
		puts("lista_expresiones : expresion COMA lista_expresiones \n");
		puts("-------------------\n");
	}
}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 354 "syntax.y"
    {
	if(DEBUG) {
		puts("io : entrada\n");
		puts("-------------------\n");
	}

	nodo_io = nodo_entrada;

}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 365 "syntax.y"
    {
	if(DEBUG) {
		puts("io : salida\n");
		puts("-------------------\n");		
	}
	nodo_io = nodo_salida;
}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 374 "syntax.y"
    {
	if(DEBUG) {
		puts("entrada : READ id\n");
		puts("-------------------\n");		
	}
	char mjs[50];
	if(buscar_en_TS_sin_prefijo((yyvsp[(2) - (2)].str_val),mjs,linecount) == -1)
	{
		puts(mjs);
		exit(1);
	}
	nodo_entrada = crear_nodo_arbol(crear_info("READ"),crear_hoja(crear_info((yyvsp[(2) - (2)].str_val))),crear_hoja(crear_info("READ")));
}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 389 "syntax.y"
    {
	if(DEBUG) {
		puts("salida : PR_WRITE id\n");
		puts("-------------------\n");
	}

	char mjs[50];
	if(buscar_en_TS_sin_prefijo((yyvsp[(2) - (2)].str_val),mjs,linecount) == -1)
	{
		puts(mjs);
		exit(1);
	}
	nodo_salida = crear_nodo_arbol(crear_info("WRITE"),crear_hoja(crear_info((yyvsp[(2) - (2)].str_val))),crear_hoja(crear_info("WRITE")));

}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 406 "syntax.y"
    {
	if(DEBUG) {
		puts("salida : PR_WRITE cte\n");
		puts("-------------------\n");	
	}
	nodo_salida = crear_nodo_arbol(crear_info("WRITE"),crear_hoja(crear_info((yyvsp[(2) - (2)].str_val))),crear_hoja(crear_info("WRITE")));

}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 416 "syntax.y"
    {
	if(DEBUG) {
		puts("Condicional sin ELSE\n");
		puts("-------------------\n");
	}

	t_info_sentencias * p_info = sacar_de_pila(&pila_condiciones);
	//le pongo null porque ahi iria el ELSE y no hay
	nodo_then = crear_nodo_arbol(crear_info("THEN"),nodo_sentencias_then,NULL);
	nodo_condicional = crear_nodo_arbol(crear_info("IF"),p_info->a,nodo_then);
}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 429 "syntax.y"
    {


	if(DEBUG) {
		puts("Condicional con ELSE\n");
		puts("-------------------\n");	
	}

	t_info_sentencias * p_info = sacar_de_pila(&pila_condiciones);
	nodo_then = crear_nodo_arbol(crear_info("<V.F>"),nodo_sentencias_then,nodo_sentencias_else);
	nodo_condicional = crear_nodo_arbol(crear_info("IF"),p_info->a,nodo_then);

}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 444 "syntax.y"
    {
	if(DEBUG) {
		puts("PR_THEN lista_sentencias\n");
		puts("-------------------\n");	
	}
	nodo_sentencias_then = obtener_raiz(nodo_sentencias);

}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 454 "syntax.y"
    {
	if(DEBUG) {
		puts("PR_ELSE lista_sentencias\n");
		puts("-------------------\n");	
	}
	nodo_sentencias_else = obtener_raiz(nodo_sentencias);
}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 463 "syntax.y"
    {
	// if(DEBUG) {
		puts("condicion : comparacion\n");
		puts("-------------------\n");
	// }

	insertar_en_pila_de_colas(&pila_de_colas,cola_sentencias);
	crear_cola(&cola_sentencias);

	t_info_sentencias * p_info = sacar_de_pila(&pila_comparaciones);
	nodo_condicion = p_info->a;
	insertar_en_pila(&pila_condiciones,crear_info_sentencias(nodo_condicion));

}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 479 "syntax.y"
    {
	// if(DEBUG) {
		puts("condicion : comparacion and comparacion\n");
		puts("-------------------\n");		
	// }

	insertar_en_pila_de_colas(&pila_de_colas,cola_sentencias);
	crear_cola(&cola_sentencias);

	t_info_sentencias * p_info1 = sacar_de_pila(&pila_comparaciones);
	t_info_sentencias * p_info2 = sacar_de_pila(&pila_comparaciones);

	nodo_condicion = crear_nodo_arbol(crear_info("AND"),p_info1->a,p_info2->a);
	insertar_en_pila(&pila_condiciones,crear_info_sentencias(nodo_condicion));


}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 498 "syntax.y"
    {
	// if(DEBUG) {
		puts("condicion : comparacion or comparacion\n");
		puts("-------------------\n");		
	// }

	insertar_en_pila_de_colas(&pila_de_colas,cola_sentencias);
	crear_cola(&cola_sentencias);

	t_info_sentencias * p_info1 = sacar_de_pila(&pila_comparaciones);
	t_info_sentencias * p_info2 = sacar_de_pila(&pila_comparaciones);

	nodo_condicion = crear_nodo_arbol(crear_info("OR"),p_info1->a,p_info2->a);
	insertar_en_pila(&pila_condiciones,crear_info_sentencias(nodo_condicion));

}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 516 "syntax.y"
    {
	// if(DEBUG) {
	// puts($2);
		puts("comparacion : expresion comparador expresion\n");
		puts("-------------------\n");
	// }
	char mjs_error[60];
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error,linecount)) 
	{
		puts(mjs_error);
		exit(1);
	}

	t_info_sentencias * p_info1 = sacar_de_pila(&pila_expresiones);
	t_info_sentencias * p_info2 = sacar_de_pila(&pila_expresiones);
	nodo_comparacion = crear_nodo_arbol(crear_info((yyvsp[(2) - (3)].str_val)),p_info1->a,p_info2->a);

	// puts("a ver esto ahora");
	// nodo_comparacion = crear_nodo_arbol(crear_info($2),nodo_expresion,nodo_termino);
	insertar_en_pila(&pila_comparaciones,crear_info_sentencias(nodo_comparacion));
}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 540 "syntax.y"
    {
	if(DEBUG) {
		puts("comparacion : PR_NOT expresion comparador expresion\n");
		puts("-------------------\n");
	}

	t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);

	nodo_comparacion = crear_nodo_arbol(crear_info("NOT"),p_info->a,NULL);
	insertar_en_pila(&pila_comparaciones,crear_info_sentencias(nodo_comparacion));

}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 554 "syntax.y"
    {
	if(DEBUG) {
		puts("iteracion : PR_WHILE PAR_ABRE condicion PAR_CIERRA PR_DO lista_sentencias PR_ENDWHILE\n");
		puts("-------------------\n");
	}

	t_info_sentencias * p_info = sacar_de_pila(&pila_condiciones);
	t_nodo_arbol * sentencias_del_do = obtener_raiz(nodo_sentencias);
	// nodo_do = crear_nodo_arbol(crear_info("DO"),sentencias_del_do,NULL);
	nodo_iteracion = crear_nodo_arbol(crear_info("WHILE"),p_info->a,sentencias_del_do);
	sentencias_del_do->padre = nodo_iteracion;

}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 569 "syntax.y"
    {
	if(DEBUG) {
		puts((yyvsp[(1) - (3)].str_val));
		puts("Asignacion -> Token_ID := expresion\n");
		puts("-------------------\n");
	}

	// printf("asignacion %s %s\n",$1,$3 );
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	puts("asignacion comprobacion tipos iguales");
	char mjs_error[60];
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);
	/* guardo la asignacion en el arbol de ejecucion */
	nodo_asignacion = crear_nodo_arbol(crear_info(":="),crear_hoja(crear_info((yyvsp[(1) - (3)].str_val))),p_info->a);

}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 591 "syntax.y"
    {
	if(DEBUG) {
		printf("expresion %s %s\n",(yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val) );
		puts("expresion : factor OP_CONCAT factor ");
		puts("-------------------\n");
	}

	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}

	/* Verifico que no este concatenando flotantes*/
	int tipo = traer_tipo((yyvsp[(3) - (3)].str_val));
	if(tipo == TIPO_FLOAT) {
		char aux_float[10];
		char aux_float2[10];
		sprintf(aux_float,"%s",(yyvsp[(1) - (3)].str_val));
		sprintf(aux_float2,"%s",(yyvsp[(3) - (3)].str_val));
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"CONCATENACION",aux_float,aux_float2,"FLOAT",linecount);
		puts(mjs_error);
		exit(1);
	}

	/* Verifico que no este concatenando enteros*/
	if(tipo == TIPO_INT) {
		char aux_int[10];
		char aux_int2[10];
		sprintf(aux_int,"%s",(yyvsp[(1) - (3)].str_val));
		sprintf(aux_int2,"%s",(yyvsp[(3) - (3)].str_val));
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"CONCATENACION",aux_int,aux_int2,"INT",linecount);
		puts(mjs_error);
		exit(1);
	}


	/* guardo la expresion en el arbol de ejecucion */

	t_info_sentencias * p_nodo_factor1 = sacar_de_pila(&pila_factores);

	t_info_sentencias * p_nodo_factor2 = sacar_de_pila(&pila_factores);

	nodo_expresion = crear_nodo_arbol(crear_info("++"),p_nodo_factor1->a,p_nodo_factor2->a);

	insertar_en_pila(&pila_expresiones,crear_info_sentencias(nodo_expresion));

}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 642 "syntax.y"
    {
	if(DEBUG) {
	printf("%s\n",(yyvsp[(1) - (1)].str_val) );
		puts("Expresion -> termino\n");
		puts("-------------------\n");
	}

	(yyval.str_val)=(yyvsp[(1) - (1)].str_val);
	
	/* guardo la expresion en el arbol de ejecucion */
	t_info_sentencias * p_nodo_termino = sacar_de_pila(&pila_terminos);
	nodo_expresion = p_nodo_termino->a;
	insertar_en_pila(&pila_expresiones,p_nodo_termino);

}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 659 "syntax.y"
    {
	if(DEBUG) {
		printf("%s %s\n", (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val));
		puts("expresion : expresion OP_SUMA termino\n");
		puts("-------------------\n");
	}
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	/* Verifico que no este sumando strings*/
	int tipo = traer_tipo((yyvsp[(3) - (3)].str_val));
	if(tipo == TIPO_STRING) {
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"SUMA",(yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),"STRING",linecount);
		puts(mjs_error);
		exit(1);
	}

	/* guardo la expresion en el arbol de ejecucion */
	t_info_sentencias * p_nodo_expresion = sacar_de_pila(&pila_expresiones);
	t_info_sentencias * p_nodo_termino =  sacar_de_pila(&pila_terminos);
	nodo_expresion = crear_nodo_arbol(crear_info("+"),p_nodo_expresion->a,p_nodo_termino->a);
	insertar_en_pila(&pila_expresiones,crear_info_sentencias(nodo_expresion));

	free(p_nodo_expresion);
	free(p_nodo_termino);

}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 691 "syntax.y"
    {
	if(DEBUG) {
		printf("%s %s\n", (yyvsp[(1) - (3)].str_val), (yyvsp[(3) - (3)].str_val));
		puts("Resta\n");
		puts("-------------------\n");
	}

	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	/* Verifico que no este restando strings*/
	int tipo = traer_tipo((yyvsp[(3) - (3)].str_val));
	if(tipo == TIPO_STRING) {
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"RESTA",(yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),"STRING",linecount);
		puts(mjs_error);
		exit(1);
	}

	/* guardo la expresion en el arbol de ejecucion */
	t_info_sentencias * p_nodo_expresion = sacar_de_pila(&pila_expresiones);
	t_info_sentencias * p_nodo_termino =  sacar_de_pila(&pila_terminos);
	nodo_expresion = crear_nodo_arbol(crear_info("-"),p_nodo_expresion->a,p_nodo_termino->a);
	insertar_en_pila(&pila_expresiones,crear_info_sentencias(nodo_expresion));

	free(p_nodo_expresion);
	free(p_nodo_termino);

}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 724 "syntax.y"
    {
	if(DEBUG) {
	printf("%s\n",(yyvsp[(1) - (1)].str_val) );
		puts("termino : factor\n");
		puts("-------------------\n");
	}
	/*guardo el termino en el arbol de ejecucion*/
	t_info_sentencias * p_nodo_factor = sacar_de_pila(&pila_factores);
	nodo_termino = p_nodo_factor->a;
	insertar_en_pila(&pila_terminos,p_nodo_factor);

}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 738 "syntax.y"
    {
	if(DEBUG) {
	printf("%s %s\n", (yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val));
		puts("termino : termino OP_DIV factor\n");
		puts("-------------------\n");
	}
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}

	/* Verifico que no este dividiendo strings*/
	int tipo = traer_tipo((yyvsp[(3) - (3)].str_val));
	if(tipo == TIPO_STRING) {
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"DIVISION",(yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),"STRING",linecount);
		puts(mjs_error);
		exit(1);
	}

	/*guardo el termino en el arbol de ejecucion*/
	t_info_sentencias * p_nodo_factor = sacar_de_pila(&pila_factores);
	t_info_sentencias * p_nodo_termino = sacar_de_pila(&pila_terminos);

	nodo_termino = crear_nodo_arbol(crear_info("/"),p_nodo_termino->a,p_nodo_factor->a);
	insertar_en_pila(&pila_terminos,crear_info_sentencias(nodo_termino));

	free(p_nodo_factor);
	free(p_nodo_termino);

}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 772 "syntax.y"
    {
	if(DEBUG) {
	printf("%s %s\n", (yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val));
		puts("termino : termino OP_MUL factor\n");
		puts("-------------------\n");
	}

	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}

	/* Verifico que no este multiplicando strings*/
	int tipo = traer_tipo((yyvsp[(3) - (3)].str_val));
	if(tipo == TIPO_STRING) {
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"MULTIPLICACION",(yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val),"STRING",linecount);
		puts(mjs_error);
		exit(1);
	}

	/*guardo el termino en el arbol de ejecucion*/
	t_info_sentencias * p_nodo_factor = sacar_de_pila(&pila_factores);
	t_info_sentencias * p_nodo_termino = sacar_de_pila(&pila_terminos);

	nodo_termino = crear_nodo_arbol(crear_info("*"),p_nodo_termino->a,p_nodo_factor->a);
	insertar_en_pila(&pila_terminos,crear_info_sentencias(nodo_termino));

	free(p_nodo_factor);
	free(p_nodo_termino);

}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 807 "syntax.y"
    {
	if(DEBUG) {
		// puts($1);
		puts("factor : between \n");
		puts("-------------------\n");	
	}
	insertar_en_pila(&pila_factores,crear_info_sentencias(crear_nodo_arbol(crear_info("BETWEEN"),nodo_between,NULL)));
	// nodo_factor = crear_nodo_arbol(crear_info("IGUALES"),nodo_iguales,NULL);
	//nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_iguales,NULL);
	//insertar_en_pila(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 820 "syntax.y"
    {
	if(DEBUG) {
		// printf("%s\n",$1);
		puts("factor : cte\n");
		puts("-------------------\n");		
	}

	/* agrego la constante a la tabla de simbolos */
	agregar_cte_a_TS(TIPO_STRING,(yyvsp[(1) - (1)].str_val), 0,0.0,linecount);
	(yyval.str_val)=(yyvsp[(1) - (1)].str_val);

	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor =  crear_hoja(crear_info((yyvsp[(1) - (1)].str_val)));
	insertar_en_pila(&pila_factores,crear_info_sentencias(nodo_factor));
	// nodo_factor = crear_hoja(crear_info($1));

	puts((yyvsp[(1) - (1)].str_val));

}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 841 "syntax.y"
    {
	if(DEBUG) {
		printf("%d\n",(yyvsp[(1) - (1)].intval));
		puts("factor : cte\n");
		puts("-------------------\n");		
	}
	/* agrego la constante a la tabla de simbolos, pero para hacerlo, primero
	tengo que castearla a string */
	char temp[10];
	sprintf(temp,"%d",(yyvsp[(1) - (1)].intval));
	(yyval.str_val) = temp;
	agregar_cte_a_TS(TIPO_INT,NULL, (yyvsp[(1) - (1)].intval),0.0,linecount);

	// puts("agregando a factooooor intttttttttttttttttttttttttttttt");
	// puts(temp);
	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor =  crear_hoja(crear_info(temp));
	insertar_en_pila(&pila_factores,crear_info_sentencias(nodo_factor));
	// nodo_factor = crear_hoja(crear_info(temp));
}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 863 "syntax.y"
    {
	if(DEBUG) {
		printf("%.4f\n",(yyvsp[(1) - (1)].val));
		puts("factor : cte\n");
		puts("-------------------\n");
	}
	/* agrego la constante a la tabla de simbolos, pero para hacerlo, primero
	tengo que castearla a string */
	char temp[10];
	sprintf(temp,"%.4f",(yyvsp[(1) - (1)].val));
	(yyval.str_val) = temp;
	agregar_cte_a_TS(TIPO_FLOAT,NULL, 0,(yyvsp[(1) - (1)].val),linecount);

	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor =  crear_hoja(crear_info(temp));
	insertar_en_pila(&pila_factores,crear_info_sentencias( nodo_factor));
	// nodo_factor = crear_hoja(crear_info(temp));
}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 883 "syntax.y"
    {
	if(DEBUG) {
		puts("factor : TOKEN_ID\n");
		puts("-------------------\n");
	}
	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor =  crear_hoja(crear_info((yyvsp[(1) - (1)].str_val)));
	insertar_en_pila(&pila_factores,crear_info_sentencias(nodo_factor ));
	// nodo_factor = crear_hoja(crear_info(temp));
}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 902 "syntax.y"
    {
	// if(DEBUG) {
		puts("declaracion_variables : PR_DECVAR linea_de_declaracion_de_tipos PR_ENDDEC PUNTO_Y_COMA\n");
		puts("-------------------\n");
	// }

}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 911 "syntax.y"
    {
	printf("El tipo de dato a agregar es %s \n", (yyvsp[(3) - (4)].str_val));
	puts("linea_de_declaracion_de_tipos : lista_variables DOS_PUNTOS tipo_dato\n");
	puts("-------------------\n");


}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 920 "syntax.y"
    {
	printf("El tipo de dato a agregar es %s \n", (yyvsp[(3) - (5)].str_val));
	puts("linea_de_declaracion_de_tipos : linea_de_declaracion_de_tipos linea_de_declaracion_de_tipos\n");
	puts("-------------------\n");

	int i;
	for (i = 0; i < variables_a_agregar; ++i)
	{
		agregar_variable_a_TS(temp_variables[i], (yyvsp[(3) - (5)].str_val),linecount);
	}
	variables_a_agregar = 0;
}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 936 "syntax.y"
    {
	printf("la variable es: %s \n",(yyvsp[(1) - (1)].str_val));
	if(DEBUG) {
		puts("lista_variables : TOKEN_ID \n");
		puts("-------------------\n");
	}

	strcpy(temp_variables[variables_a_agregar],(yyvsp[(1) - (1)].str_val));
	variables_a_agregar++;

}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 949 "syntax.y"
    {
	printf("la variable es: %s \n",(yyvsp[(1) - (3)].str_val));
	// if(DEBUG) {
		puts("lista_variables : TOKEN_ID COMA lista_variables \n");
		puts("-------------------\n");
	// }


	strcpy(temp_variables[variables_a_agregar],(yyvsp[(1) - (3)].str_val));
	variables_a_agregar++;

}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 1022 "syntax.y"
    {
	(yyval.str_val)=(yyvsp[(1) - (1)].str_val);
	if(DEBUG) {
		puts("PR_INT\n");
		puts("-------------------\n");	
	}

	int i;
	for (i = 0; i < variables_a_agregar; ++i)
	{
		agregar_variable_a_TS(temp_variables[i], (yyvsp[(1) - (1)].str_val),linecount);
	}
	variables_a_agregar = 0;
}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 1038 "syntax.y"
    {
	(yyval.str_val)=(yyvsp[(1) - (1)].str_val);
	if(DEBUG) { 
		puts("PR_FLOAT\n");
		puts("-------------------\n");
	}
	int i;
	for (i = 0; i < variables_a_agregar; ++i)
	{
		agregar_variable_a_TS(temp_variables[i], (yyvsp[(1) - (1)].str_val),linecount);
	}
	variables_a_agregar = 0;
}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 1053 "syntax.y"
    {
	(yyval.str_val)=(yyvsp[(1) - (1)].str_val);
	if(DEBUG) {
		puts("PR_STRING\n");
		puts("-------------------\n");
	}
	int i;
	for (i = 0; i < variables_a_agregar; ++i)
	{
		agregar_variable_a_TS(temp_variables[i], (yyvsp[(1) - (1)].str_val),linecount);
	}
	variables_a_agregar = 0;
}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 1068 "syntax.y"
    {
	// strcpy(nodo_comparador->info->a, ">");
	if(DEBUG) {
		puts("OP_MAYOR\n");
		puts("-------------------\n");
	}
}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1077 "syntax.y"
    {
	// strcpy(nodo_comparador->info->a, "<");
	if(DEBUG) {
		puts("OP_MENOR\n");
		puts("-------------------\n");
	}
}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 1086 "syntax.y"
    {
	// strcpy(nodo_comparador->info->a, "<=");

	(yyval.str_val)=(yyvsp[(1) - (1)].str_val);
	if(DEBUG) {
		puts("OP_MENOR_IGUAL\n");
		puts("-------------------\n");
	}
}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 1097 "syntax.y"
    {
	// strcpy(nodo_comparador->info->a, ">=");
	if(DEBUG) {
		puts("OP_MAYOR_IGUAL\n");
		puts("-------------------\n");
	}
}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 1106 "syntax.y"
    {
	// strcpy(nodo_comparador->info->a, "==");
	if(DEBUG) {
		puts("OP_IGUAL_IGUAL\n");
		puts("-------------------\n");
	}
}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 1115 "syntax.y"
    {
	// strcpy(nodo_comparador->info->a, "!=");
	if(DEBUG) {
		puts("OP_DISTINTO\n");
		puts("-------------------\n");
	}
}
    break;



/* Line 1455 of yacc.c  */
#line 2733 "y.tab.c"
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
#line 1123 "syntax.y"



extern t_simbolo tabla_simbolos[2000];

//funcion para realizar todo lo que haga falta previo a terminar
void finally(FILE *yyin){
	vaciar_tabla_simbolos();
	// vaciar_arbol(&arbol_ejecucion);
	fclose(yyin);
}



int main(int argc, char **argv ) {
	// puts("Corriendo el compilador...");
	// crear_inicio_assembler();

	++argv, --argc; 

	if ( argc > 0 ) {
	    yyin = fopen( argv[0], "r" );
    }	else {
	    yyin = stdin;

    }



    crear_pila_de_colas(&pila_de_colas);
    // crear_pila(&cola_sentencias);
    crear_cola(&cola_sentencias);
    crear_pila(&pila_bloques);
    crear_pila(&pila_comparaciones);
    crear_pila(&pila_condiciones);
    crear_pila(&pila_factores);
    crear_pila(&pila_terminos);
    crear_pila(&pila_expresiones);
    crear_arbol(&arbol_ejecucion);

	yyparse();
	imprimir_tabla_simbolos();
	arbol_ejecucion->p_nodo = obtener_raiz(nodo_sentencia);

	refactorizar_nodo(&arbol_ejecucion->p_nodo);
	// recorrer_en_orden(arbol_ejecucion->p_nodo,&reemplazar_etiqueta_por_valor_TS);

	// crear_codigo_assembler(arbol_ejecucion->p_nodo);
	// arbol_ejecucion->p_nodo = obtener_raiz(nodo_iguales);

	// recorrer_en_orden(arbol_ejecucion->p_nodo,&visitar);
	// puts("hola");
	print_t(arbol_ejecucion->p_nodo);
	
	// imprimir_arbol(arbol_ejecucion->p_nodo);

	// printf("la pila esta vacia? %d\n", pila_vacia(&cola_sentencias) );
	// if(!pila_vacia)
	// {
	// 	t_nodo_arbol
	// }
	
	finally(yyin); 
	puts("\nFinalizando compilacion...");
	return EXIT_SUCCESS;
}

int yyerror(void)
{
	printf("Syntax Error\n");
	system ("Pause");
	exit (1);
}

