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
#line 1 "y.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define_lib.c"

extern FILE *yyin;
extern FILE *yyout;
extern int linenum;
int tabs = 0;
char object_class[NAME_LENGTH];
int self = 0;
int case_type = 0;
char last_type[NAME_LENGTH];
char object_call[NAME_LENGTH];
int actualpars_counter = 0;
char actualpars_arr[PAR_LIMIT][NAME_LENGTH];
int method_to_call;
int class_to_call;
char id_return_type_arr[NAME_LENGTH];
int placeholder_counter = 0;
char _printf_[PAR_LIMIT][TYPE_LENGTH];
char _scanf_[TYPE_LENGTH];
char d_placeholder[] = "%d";
char c_placeholder[] = "%c";
char f_placeholder[] = "%f";
char constructor_pars[NAME_LENGTH * PAR_LIMIT];
int index_array = 0;
int custom_object_counter = 0;
int digit_counter = 0;
int return_bool = 0;

typedef struct {
  char name_of_method[NAME_LENGTH];
  int number_of_pars;
  char type_of_each_par[PAR_LIMIT][TYPE_LENGTH];
  char name_of_each_par[PAR_LIMIT][NAME_LENGTH];
  char return_type[NAME_LENGTH];
  int number_of_vars;
  char type_of_each_var[LOCALS_GLOBALS_LIMIT][TYPE_LENGTH];
  char name_of_each_var[LOCALS_GLOBALS_LIMIT][NAME_LENGTH];
} method_s;

typedef struct {
  int interface;
  char name_of_class[NAME_LENGTH];
  int number_of_globals;
  char type_of_each_global[LOCALS_GLOBALS_LIMIT][TYPE_LENGTH];
  char name_of_each_global[LOCALS_GLOBALS_LIMIT][NAME_LENGTH];
  int number_of_abstract;
  char abstract_methods[METHOD_LIMIT][NAME_LENGTH];
  char name_of_inherited_class[NAME_LENGTH];
  int number_of_inherited_vars;
  char type_of_inherited_vars[INHERITED_LIMIT][TYPE_LENGTH];
  char name_of_inherited_vars[INHERITED_LIMIT][NAME_LENGTH];
  int methods_counter;
  method_s method[METHOD_LIMIT];
} class_s;

class_s classes[CLASS_LIMIT];
int class_counter = 0;
void init_values(int var_type);
void write_par_values(int var_type);
void how_many_tabs();
void write_semicolon();
void write_for_semicolon();
void write_keywords(int keyword);
void write_braces(int brace);
void write_parenthesis(int par);
void write_brackets(int bracket);
void write_symbols(int symbol);
void write_id();
void write_object_on_pars();
void write_main();
void write_call_return();
void write_return_0();
void init_for_values(int var_type);
void insert_class_names();
void insert_method_names_and_type(char type[NAME_LENGTH]);
void write_methods(int type);
void init_methods_counter();
void save_global_var(int type);
void init_globals_counter();
void init_locals_counter();
void init_pars_counter();
void init_last_type();
void init_object_call();
void init_inherited_vars_counter();
void init_type_of_class(int type);
void insert_inherited_vars();
void insert_inherited_class();
void save_local_vars(int type);
void save_pars(int type);
void init_abstract_counter();
void save_abstract();
void save_actualpars(int type);
void print_structs();
void check_on_inherited_vars(int check_dec_or_undec);
void check_on_globals(int check_dec_or_undec);
void check_on_pars(int check_dec_or_undec);
void check_on_locals(int check_dec_or_undec);
void check_interface_methods();
void check_same_class_name();
void check_same_method_name();
void check_pars();
void check_types_actualpars();
void clear_actualpars_arr();
int search_var(char names[][NAME_LENGTH], char value[], int limit);
void check_same_type(char names[][NAME_LENGTH], char types[][TYPE_LENGTH],
  int limit);
void find_type();
int search_type(char names[][NAME_LENGTH], char types[][TYPE_LENGTH],
  int limit);
void call_search();
void check_class_name();
void check_method_name();
void check_abstract_existence();
void check_type(char names[][NAME_LENGTH], char types[][TYPE_LENGTH]
  ,int limit);
int return_methods_counter();
int return_number_of_globals();
int return_number_of_vars();
int return_number_of_pars();
int search_local_vars();
int search_par_vars();
int search_global_vars();
int search_where_var_is();
char * return_type_of_object(char names[][NAME_LENGTH]
  , char types[][NAME_LENGTH],
  int limit);
int return_index_of_class(char name[NAME_LENGTH]);
void id_return_type();
void clear_id_return_type_arr();
void check_same_return_type();
void count_printf_vars(int type);
void check_placeholder();
void init_placeholder_counter();
void scanf_placeholder();
void choose_constructor(int type);
void combine_constructor_pars(int type);
void write_constructor_call(int which);
int check_types_actualpars_constructor();
void clear_constructor_pars();
void write_index_array();
void write_super(int class, int method);
void make_custom_ob();
void init_object_class();
void check_array_length();
void check_return_bool();

#line 217 "y.tab.c" /* yacc.c:339  */

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
    CLASSTK = 258,
    EXTENDSTK = 259,
    IFTK = 260,
    WHILETK = 261,
    FORTK = 262,
    RETURNTK = 263,
    SWITCHTK = 264,
    CASETK = 265,
    ELSETK = 266,
    ELIFTK = 267,
    INTTK = 268,
    DOUBLETK = 269,
    CHARTK = 270,
    PRINTTK = 271,
    INPUTTK = 272,
    VOIDTK = 273,
    BREAKTK = 274,
    ANDTK = 275,
    ORTK = 276,
    APOSTROPHETK = 277,
    IDTK = 278,
    DIGITTK = 279,
    EOFTK = 280,
    SEMICOLONTK = 281,
    COLONTK = 282,
    COMMATK = 283,
    QUESTIONMARKTK = 284,
    LEFTPARTK = 285,
    RIGHTPARTK = 286,
    LEFTBRACETK = 287,
    RIGHTBRACETK = 288,
    LESSTK = 289,
    GREATERTK = 290,
    LESSEQUALTK = 291,
    GREATEREQUALTK = 292,
    EQUALTK = 293,
    DOUBLEEQUALTK = 294,
    NOTEQUALTK = 295,
    PLUSTK = 296,
    MINUSTK = 297,
    MULTK = 298,
    DIVIDETK = 299,
    DOUBLEPLUSTK = 300,
    DOUBLEMINUSTK = 301,
    SINGLECOMMENTTK = 302,
    OPENBLOCKCOMTK = 303,
    CLOSEBLOCKCOMTK = 304,
    LEFTBRACKETTK = 305,
    RIGHTBRACKETTK = 306,
    CARETTK = 307,
    PERCENTTK = 308,
    PUBLICTK = 309,
    ENDPUBLICTK = 310,
    TRUETK = 311,
    PERCENTFTK = 312,
    OBJECTTK = 313,
    DOTTK = 314,
    CHARACTERTK = 315,
    NOTTK = 316,
    FALSETK = 317,
    DEFAULTTK = 318,
    PERCENTDTK = 319,
    PERCENTCTK = 320,
    NOTEQUALCONTK = 321,
    DOUBLEVALUETK = 322,
    ABSTRACTTK = 323,
    INTERFACETK = 324,
    CALLTK = 325,
    MAINTK = 326,
    CUSTOMOBJECTTK = 327,
    SUPERTK = 328
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 152 "y.y" /* yacc.c:355  */

    int intval;
    char string[100];
    double doubleval;

#line 337 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 352 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   906

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  163
/* YYNRULES -- Number of rules.  */
#define YYNRULES  295
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  510

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   328

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   175,   175,   177,   178,   177,   181,   182,   183,   185,
     187,   185,   189,   191,   194,   189,   197,   197,   201,   201,
     205,   206,   206,   209,   210,   212,   213,   214,   215,   216,
     218,   220,   221,   222,   221,   226,   227,   228,   227,   231,
     232,   235,   236,   238,   238,   241,   245,   244,   249,   252,
     252,   256,   256,   260,   261,   262,   263,   261,   267,   268,
     270,   271,   272,   268,   274,   275,   276,   277,   274,   279,
     281,   282,   283,   279,   285,   287,   288,   289,   285,   291,
     291,   294,   295,   296,   298,   299,   300,   301,   303,   304,
     305,   305,   310,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   324,   325,   325,   329,   328,   332,
     336,   335,   339,   342,   342,   342,   345,   346,   347,   346,
     352,   352,   355,   359,   360,   358,   363,   366,   367,   368,
     369,   370,   372,   374,   376,   378,   381,   382,   383,   381,
     385,   386,   387,   385,   389,   389,   392,   393,   394,   392,
     397,   398,   399,   400,   397,   403,   403,   407,   407,   410,
     411,   413,   414,   415,   417,   417,   420,   421,   422,   420,
     425,   426,   426,   428,   428,   430,   430,   433,   434,   435,
     437,   437,   441,   442,   442,   445,   445,   447,   447,   450,
     452,   453,   454,   455,   456,   458,   460,   463,   464,   465,
     467,   470,   471,   472,   473,   475,   475,   479,   481,   482,
     483,   485,   481,   487,   488,   489,   490,   492,   487,   496,
     497,   498,   499,   500,   501,   501,   502,   502,   503,   504,
     504,   507,   509,   507,   512,   513,   513,   515,   516,   516,
     518,   519,   519,   520,   520,   522,   523,   524,   525,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   539,   541,   542,   543,   544,   545,   546,   547,
     548,   550,   550,   553,   554,   555,   556,   557,   558,   559,
     560,   562,   563,   564,   565,   566,   567,   568,   570,   572,
     574,   576,   578,   580,   582,   584
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASSTK", "EXTENDSTK", "IFTK",
  "WHILETK", "FORTK", "RETURNTK", "SWITCHTK", "CASETK", "ELSETK", "ELIFTK",
  "INTTK", "DOUBLETK", "CHARTK", "PRINTTK", "INPUTTK", "VOIDTK", "BREAKTK",
  "ANDTK", "ORTK", "APOSTROPHETK", "IDTK", "DIGITTK", "EOFTK",
  "SEMICOLONTK", "COLONTK", "COMMATK", "QUESTIONMARKTK", "LEFTPARTK",
  "RIGHTPARTK", "LEFTBRACETK", "RIGHTBRACETK", "LESSTK", "GREATERTK",
  "LESSEQUALTK", "GREATEREQUALTK", "EQUALTK", "DOUBLEEQUALTK",
  "NOTEQUALTK", "PLUSTK", "MINUSTK", "MULTK", "DIVIDETK", "DOUBLEPLUSTK",
  "DOUBLEMINUSTK", "SINGLECOMMENTTK", "OPENBLOCKCOMTK", "CLOSEBLOCKCOMTK",
  "LEFTBRACKETTK", "RIGHTBRACKETTK", "CARETTK", "PERCENTTK", "PUBLICTK",
  "ENDPUBLICTK", "TRUETK", "PERCENTFTK", "OBJECTTK", "DOTTK",
  "CHARACTERTK", "NOTTK", "FALSETK", "DEFAULTTK", "PERCENTDTK",
  "PERCENTCTK", "NOTEQUALCONTK", "DOUBLEVALUETK", "ABSTRACTTK",
  "INTERFACETK", "CALLTK", "MAINTK", "CUSTOMOBJECTTK", "SUPERTK",
  "$accept", "program", "main", "$@1", "$@2", "class_type", "class", "$@3",
  "$@4", "$@5", "$@6", "$@7", "interface", "$@8", "block", "$@9",
  "interface_block", "$@10", "declarations", "values_list", "int_values",
  "array_or_not", "$@11", "$@12", "init_array_rule", "$@13", "$@14",
  "many_digits", "init_int_rule", "$@15", "double_values", "$@16",
  "char_values", "$@17", "object_values", "$@18", "constructors", "$@19",
  "$@20", "$@21", "methods", "$@22", "$@23", "$@24", "$@25", "$@26",
  "$@27", "$@28", "$@29", "$@30", "$@31", "$@32", "$@33", "$@34", "$@35",
  "$@36", "$@37", "$@38", "parlist", "parlist_types", "par_int", "$@39",
  "constructor_block", "method_block", "assignment", "$@40", "$@41",
  "$@42", "$@43", "$@44", "local_array_or_not", "$@45", "$@46",
  "local_int", "$@47", "init_object", "$@48", "$@49",
  "actualpars_constructor", "ifstat", "$@50", "$@51", "$@52", "$@53",
  "$@54", "$@55", "$@56", "whilestat", "$@57", "$@58", "$@59", "forstat",
  "$@60", "$@61", "$@62", "$@63", "int_values_for", "$@64", "$@65",
  "number_or_id", "forstep", "returnstat", "$@66", "switchstat", "$@67",
  "$@68", "$@69", "caserule", "$@70", "$@71", "$@72", "id_char_digit",
  "printstat", "$@73", "inside_print", "$@74", "$@75", "after_comma",
  "$@76", "inside_apostrophe", "outside_apostrophe", "id_print",
  "inputstat", "$@77", "callstat", "callcase", "$@78", "$@79", "$@80",
  "$@81", "$@82", "$@83", "$@84", "$@85", "$@86", "actualpars", "$@87",
  "$@88", "$@89", "super", "$@90", "$@91", "condition", "$@92", "boolterm",
  "$@93", "boolfactor", "$@94", "$@95", "expression", "$@96", "array_expr",
  "$@97", "operations", "relationaloper", "id", "id_init", "digit_init",
  "double_rule_init", "character_rule_init", "digit", "double_rule",
  "character_rule", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328
};
# endif

#define YYPACT_NINF -261

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-261)))

#define YYTABLE_NINF -274

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -261,     8,    13,  -261,    11,    11,    -5,  -261,  -261,  -261,
    -261,    39,  -261,    16,    31,    84,   101,  -261,  -261,    11,
    -261,   125,   129,  -261,     9,  -261,  -261,   184,  -261,   172,
    -261,  -261,  -261,    87,  -261,  -261,  -261,   196,    64,    -2,
      11,    11,  -261,    11,  -261,  -261,  -261,  -261,    11,   129,
     200,   197,   208,   221,  -261,   237,    82,    11,    11,   241,
     242,  -261,    11,    11,  -261,  -261,   114,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,   250,   265,  -261,     0,     2,
      92,  -261,    76,  -261,   261,   264,  -261,  -261,  -261,   748,
    -261,   265,  -261,    93,   109,   115,  -261,    11,  -261,   -26,
     266,   263,   275,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,    11,    11,    11,    11,    11,    11,   278,
    -261,  -261,   157,   157,   145,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,   198,   449,   280,
     854,   449,   449,  -261,   294,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,   303,  -261,    11,  -261,  -261,  -261,    32,
    -261,  -261,   748,   276,   748,   748,   273,   300,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,   141,   316,   721,   142,
      11,   294,   297,   748,  -261,   167,   167,   748,  -261,   -10,
     167,     1,   306,   288,   748,   748,   748,  -261,   194,   309,
    -261,    11,    11,  -261,  -261,   201,  -261,  -261,  -261,  -261,
    -261,   157,   257,    11,   334,   369,   320,  -261,   317,   324,
     325,   326,   328,   232,  -261,  -261,  -261,  -261,   331,   341,
     782,  -261,   329,   171,  -261,   810,  -261,   313,  -261,  -261,
     313,  -261,   826,   342,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,    11,   519,   554,   588,  -261,  -261,   345,   346,
     123,  -261,  -261,    32,  -261,   179,   144,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,   337,    98,    11,    11,
     205,  -261,   157,   349,   157,   157,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,   748,   350,  -261,   167,   748,  -261,  -261,
     323,   351,  -261,  -261,  -261,  -261,   644,     7,  -261,  -261,
    -261,  -261,  -261,   343,   354,  -261,  -261,  -261,  -261,   361,
    -261,  -261,   126,   232,   232,   232,   232,   377,   265,  -261,
    -261,  -261,  -261,   232,  -261,   316,  -261,   721,   341,   157,
     449,  -261,   748,   378,  -261,  -261,   676,  -261,  -261,   126,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,    11,    11,
    -261,  -261,   373,  -261,   376,  -261,   225,   229,   230,   234,
    -261,  -261,  -261,   386,  -261,   149,  -261,   794,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,    83,  -261,  -261,  -261,  -261,
    -261,  -261,   365,  -261,   315,  -261,   336,  -261,   294,    65,
     690,   389,   392,   238,  -261,  -261,  -261,  -261,  -261,   399,
     393,   394,   396,   397,    11,   391,   637,  -261,  -261,   401,
     136,   100,  -261,   403,  -261,    32,  -261,    36,  -261,   384,
    -261,   188,  -261,  -261,  -261,  -261,  -261,  -261,  -261,   748,
    -261,  -261,  -261,  -261,  -261,  -261,   414,   249,    83,   294,
     342,   367,  -261,   415,  -261,   416,  -261,  -261,  -261,  -261,
    -261,   417,   842,   421,   431,  -261,   425,   251,  -261,  -261,
    -261,  -261,  -261,   426,   430,   453,   466,   499,  -261,  -261,
     429,   535,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
     568,  -261,   438,   439,   604,   451,  -261,  -261,  -261,  -261
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       6,     0,     0,     1,     0,     0,     0,     2,     7,     8,
     289,     9,    16,     0,     0,     0,     0,     3,    10,     0,
      20,     0,    23,    13,     0,     4,    25,     0,    18,     0,
      17,    21,    93,     0,    11,    53,    14,     0,     0,     0,
       0,     0,    24,     0,    26,    27,    28,    29,    58,    23,
       0,     0,     0,     0,   164,     0,     0,     0,     0,     0,
       0,     5,     0,     0,   231,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,     0,    30,    41,     0,
       0,    51,    19,    54,     0,     0,   136,   146,   150,   249,
     166,     0,   104,     0,     0,     0,   180,     0,   113,     0,
       0,     0,     0,   105,   290,    32,    42,    43,    31,    45,
      46,    48,    49,     0,     0,     0,     0,     0,     0,     0,
      15,    22,   240,   240,     0,   288,   293,   261,   274,   275,
     276,   277,   279,   280,   278,   295,   294,   273,   273,   270,
     273,   273,   269,   252,     0,   117,   122,   120,   116,   109,
     107,   112,   110,   182,   205,     0,   213,   208,   207,   127,
     144,   140,   249,     0,   249,   249,     0,     0,    64,    69,
      74,    59,    79,    55,   247,   248,     0,   234,   237,     0,
       0,     0,     0,   249,   165,     0,   255,   249,   271,   265,
     264,     0,     0,     0,   249,   249,   249,   183,     0,     0,
     114,     0,     0,   292,   291,     0,   128,   130,   131,   129,
      93,   240,   273,     0,   273,   273,     0,    52,     0,     0,
       0,     0,     0,    81,   235,   137,   238,   241,     0,   246,
     281,   147,     0,   281,   157,   273,   267,   268,   266,   253,
       0,   254,   273,     0,   256,   257,   258,   260,   250,   259,
     251,   167,     0,   273,   273,   273,   190,   185,     0,     0,
       0,   214,   209,     0,   232,     0,     0,   106,    33,    44,
      47,    50,    65,    70,    75,    60,     0,    88,     0,     0,
       0,    82,   240,     0,   240,   240,   243,   283,   284,   285,
     286,   282,   287,   249,     0,   155,     0,   249,   262,   263,
       0,     0,   118,   121,   108,   111,     0,     0,   181,   206,
     126,   123,   115,     0,     0,   132,   133,   135,   134,     0,
     145,   141,     0,    81,    81,    81,    81,     0,     0,    85,
      89,    86,    87,    84,    56,   236,   138,   239,   242,   240,
     245,   148,   249,     0,   159,   160,   273,   272,   168,     0,
     184,   201,   202,   196,   204,   194,   195,   203,   193,   191,
     192,   187,   186,   189,   197,   198,   199,   200,     0,     0,
     210,   233,     0,    35,     0,    34,     0,     0,     0,     0,
      80,    90,    83,     0,    93,     0,    93,   273,   151,   158,
     170,   119,   190,   124,   215,   219,   142,    36,    66,    71,
      76,    61,     0,    93,     0,   244,     0,   156,     0,     0,
       0,     0,     0,     0,   220,   222,   223,   221,    93,     0,
       0,     0,     0,     0,     0,     0,    92,   139,   149,     0,
       0,     0,   169,     0,   188,   127,   216,   224,   211,     0,
      39,     0,    67,    72,    77,    62,    91,    57,   152,   249,
     162,   163,   171,   177,   178,   179,   175,     0,   219,     0,
       0,     0,   228,     0,   143,     0,    37,    93,    93,    93,
      93,     0,   273,     0,     0,    93,     0,     0,   225,   227,
     230,   212,    40,     0,     0,     0,     0,     0,   153,    93,
       0,     0,   125,   217,    38,    68,    73,    78,    63,    93,
       0,   174,     0,     0,     0,     0,   176,   218,   154,   172
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,   407,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,   135,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,   -11,   152,
    -261,  -261,  -261,  -183,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,    43,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,    95,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,    38,  -261,  -261,  -261,  -261,
    -261,  -261,  -116,  -261,   215,  -261,   214,  -261,  -261,   -79,
    -261,    14,  -261,   -76,    74,  -140,    -4,   -74,   239,  -260,
    -167,  -180,  -161
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     7,    21,    32,     2,     8,    14,    22,    15,
      29,    49,     9,    16,    27,    35,    24,    37,    28,    33,
      44,    77,   163,   322,   375,   419,   483,   441,   108,   164,
      45,   165,    46,   166,    47,   113,    48,   119,   223,   383,
      82,   221,   326,   423,   470,   218,   323,   420,   467,   219,
     324,   421,   468,   220,   325,   422,   469,   222,   280,   281,
     329,   402,   425,    38,    65,   162,   195,   196,   155,   260,
      92,   193,   349,   148,   194,   312,   368,   411,   205,    66,
     122,   283,   384,   211,   372,   418,   210,    67,   123,   294,
     386,    68,   124,   408,   471,   499,   181,   342,   297,   343,
     429,    69,    89,    70,   144,   301,   390,   409,   473,   474,
     475,   452,    71,   153,   198,   256,   307,   362,   392,   306,
     363,   358,    72,   199,    73,   158,   202,   314,   395,   463,
     201,   313,   412,   458,   503,   413,   459,   460,   461,    74,
     100,   319,   229,   282,   177,   284,   178,   285,   339,   230,
     183,   138,   243,   139,   360,   140,    75,   207,   208,   209,
     141,   142,   143
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,    12,   105,   318,   192,   216,   176,   179,     3,   246,
     137,   250,   156,   125,   126,    23,     4,   145,   238,   241,
      31,    10,   245,   248,   125,    13,   106,   265,   109,   361,
     125,   126,    10,   157,    10,    78,    79,    80,   107,    81,
     110,   233,    30,   -12,    83,   237,   240,    17,    76,   244,
     247,   249,    93,    94,    95,    10,   104,   136,    98,    99,
    -226,   185,   186,    18,   189,   190,   191,   135,   136,    51,
      52,    53,    54,    55,   136,   431,   300,    56,    57,    58,
      59,    60,     5,   212,     6,   214,   215,    10,    19,   114,
     115,   116,   203,   154,   117,   266,   135,    61,   432,   204,
      39,    40,    41,  -229,   235,    10,   125,   126,   242,   167,
     168,   169,   170,   171,   172,   253,   254,   255,   111,   146,
     182,    10,    62,    10,   104,   101,   102,   366,   433,   345,
     112,   147,    91,    20,    63,   149,   185,    64,   185,   185,
     365,   151,    42,   135,   118,    43,   367,   150,   328,   310,
     136,   200,   373,   152,   185,   206,   344,    25,   180,   185,
     203,   311,   224,   224,   374,   224,   185,   364,    10,   338,
     224,   455,   225,   231,   449,   321,   232,   185,   185,   185,
     405,   450,   451,    26,    51,    52,    53,    54,    55,   316,
     125,   126,    56,    57,    58,    59,    60,   261,   262,   236,
     239,   404,    10,   406,    36,   287,   288,   289,   290,   268,
     291,   292,   320,   174,   340,   416,   465,    34,   346,   175,
     426,   466,   257,   385,   184,   258,    50,    86,   415,   263,
     359,    85,   264,   333,   417,   439,   334,    62,    87,   128,
     129,   130,   131,   132,   133,   277,   278,   279,   302,    63,
     134,    88,    64,   333,   381,   414,   398,   333,   333,   315,
     399,   400,   333,   387,   185,   401,   437,    90,   430,   438,
     185,    96,    97,   330,   331,   332,   462,   263,   416,   437,
     476,   480,   493,   267,   484,   485,   486,   487,   103,   104,
     121,   415,   491,   479,   120,   160,   159,   417,   128,   129,
     130,   131,   132,   133,   293,   161,   500,   296,   173,   134,
     187,   185,   376,   377,   378,   379,   504,   125,   414,   478,
      51,    52,    53,    54,    55,   197,   217,   213,    56,    57,
      58,    59,    60,   135,   359,   234,   226,   251,    10,   252,
     259,    51,    52,    53,    54,    55,   271,   272,   427,    56,
      57,    58,    59,    60,   273,   274,   275,   454,   276,    10,
     269,   286,   224,   188,   393,   394,   126,   295,   327,   428,
     472,   308,   309,    62,   347,   128,   129,   130,   131,   132,
     133,   336,   341,   348,   370,    63,   134,   371,    64,    51,
      52,    53,    54,    55,    62,   270,   185,    56,    57,    58,
      59,    60,   369,   380,   388,   396,    63,    10,   397,    64,
     128,   129,   130,   131,   132,   133,   424,   464,   403,   435,
     446,   134,   436,   440,   447,   442,   443,   453,   444,   445,
     456,   206,   448,  -173,   136,    51,    52,    53,    54,    55,
     482,   481,    62,    56,    57,    58,    59,    60,   489,   488,
     490,   492,   494,    10,    63,   501,    84,    64,    51,    52,
      53,    54,    55,   495,   506,   507,    56,    57,    58,    59,
      60,    51,    52,    53,    54,    55,    10,   509,   457,    56,
      57,    58,    59,    60,   391,   382,   496,   410,    62,    10,
     128,   129,   130,   131,   132,   133,   477,   335,   337,   497,
      63,   134,   317,    64,    51,    52,    53,    54,    55,     0,
       0,    62,    56,    57,    58,    59,    60,     0,     0,     0,
       0,     0,    10,    63,    62,     0,    64,     0,     0,     0,
       0,     0,   498,     0,     0,     0,    63,     0,     0,    64,
      51,    52,    53,    54,    55,   303,     0,     0,    56,    57,
      58,    59,    60,     0,   502,     0,     0,    62,    10,     0,
     128,   129,   130,   131,   132,   133,     0,     0,     0,    63,
       0,   134,    64,    51,    52,    53,    54,    55,     0,     0,
     304,    56,    57,    58,    59,    60,     0,   505,     0,     0,
       0,    10,     0,    62,     0,   128,   129,   130,   131,   132,
     133,     0,     0,     0,     0,    63,   134,     0,    64,    51,
      52,    53,    54,    55,   305,     0,     0,    56,    57,    58,
      59,    60,     0,     0,     0,     0,    62,    10,     0,   128,
     129,   130,   131,   132,   133,     0,     0,   508,    63,     0,
     134,    64,    51,    52,    53,    54,    55,     0,     0,     0,
      56,    57,    58,    59,    60,     0,     0,     0,     0,     0,
      10,     0,    62,     0,     0,     0,   350,   351,   352,     0,
       0,     0,     0,     0,    63,     0,     0,    64,   287,   288,
     289,   290,     0,   291,   292,   128,   129,   130,   131,   132,
     133,     0,     0,     0,     0,    62,   134,     0,     0,     0,
       0,   353,   389,     0,   354,     0,     0,    63,   355,   356,
      64,   357,   434,   351,   352,     0,     0,   128,   129,   130,
     131,   132,   133,     0,   287,   288,   289,   290,   134,   291,
     292,   128,   129,   130,   131,   132,   133,     0,     0,     0,
       0,     0,   134,     0,   125,   126,     0,   353,     0,     0,
     354,   127,     0,     0,   355,   356,     0,   357,     0,     0,
       0,     0,   128,   129,   130,   131,   132,   133,     0,     0,
       0,   125,   126,   134,     0,     0,     0,   174,   127,     0,
       0,   135,   227,   175,     0,     0,     0,   228,   136,   128,
     129,   130,   131,   132,   133,     0,     0,     0,     0,     0,
     134,     0,     0,     0,     0,  -273,  -273,     0,   135,     0,
       0,     0,     0,     0,     0,   136,   287,   288,   289,   290,
     407,   291,   292,   128,   129,   130,   131,   132,   133,     0,
       0,     0,     0,     0,   134,   128,   129,   130,   131,   132,
     133,   298,     0,     0,     0,     0,   134,     0,     0,     0,
       0,   128,   129,   130,   131,   132,   133,   299,     0,     0,
       0,     0,   134,     0,     0,     0,     0,   128,   129,   130,
     131,   132,   133,  -161,     0,     0,     0,     0,   134,     0,
       0,     0,     0,   128,   129,   130,   131,   132,   133,     0,
       0,     0,     0,     0,   134,   128,   129,   130,   131,   132,
     133,     0,     0,     0,   188,     0,   134
};

static const yytype_int16 yycheck[] =
{
       4,     5,    76,   263,   144,   166,   122,   123,     0,   189,
      89,   191,    38,    23,    24,    19,     3,    91,   185,   186,
      24,    23,   189,   190,    23,    30,    26,   210,    26,    22,
      23,    24,    23,    59,    23,    39,    40,    41,    38,    43,
      38,   181,    33,     4,    48,   185,   186,    31,    50,   189,
     190,   191,    56,    57,    58,    23,    24,    67,    62,    63,
      24,   137,   138,    32,   140,   141,   142,    60,    67,     5,
       6,     7,     8,     9,    67,    10,   243,    13,    14,    15,
      16,    17,    69,   162,    71,   164,   165,    23,     4,    13,
      14,    15,    60,    97,    18,   211,    60,    33,    33,    67,
      13,    14,    15,    67,   183,    23,    23,    24,   187,   113,
     114,   115,   116,   117,   118,   194,   195,   196,    26,    26,
     124,    23,    58,    23,    24,    11,    12,   307,    63,   296,
      38,    38,    50,    32,    70,    26,   212,    73,   214,   215,
     307,    26,    55,    60,    68,    58,   307,    38,    50,    26,
      67,   155,    26,    38,   230,   159,   296,    32,    13,   235,
      60,    38,    21,    21,    38,    21,   242,   307,    23,   285,
      21,   431,    31,    31,    38,    31,   180,   253,   254,   255,
      31,    45,    46,    54,     5,     6,     7,     8,     9,   263,
      23,    24,    13,    14,    15,    16,    17,   201,   202,   185,
     186,   384,    23,   386,    32,    34,    35,    36,    37,   213,
      39,    40,    33,    56,   293,   395,    28,    33,   297,    62,
     403,    33,    28,   339,    26,    31,    30,    30,   395,    28,
     306,    31,    31,    28,   395,   418,    31,    58,    30,    41,
      42,    43,    44,    45,    46,    13,    14,    15,   252,    70,
      52,    30,    73,    28,   328,   395,    31,    28,    28,   263,
      31,    31,    28,   342,   340,    31,    28,    30,   408,    31,
     346,    30,    30,   277,   278,   279,   437,    28,   458,    28,
      31,   461,    31,    26,   467,   468,   469,   470,    38,    24,
      26,   458,   475,   460,    33,    32,    30,   458,    41,    42,
      43,    44,    45,    46,   230,    30,   489,   233,    30,    52,
      30,   387,   323,   324,   325,   326,   499,    23,   458,   459,
       5,     6,     7,     8,     9,    22,    26,    51,    13,    14,
      15,    16,    17,    60,   410,    38,    20,    31,    23,    51,
      31,     5,     6,     7,     8,     9,    26,    30,    33,    13,
      14,    15,    16,    17,    30,    30,    30,   431,    30,    23,
      26,    30,    21,    50,   368,   369,    24,    38,    31,    33,
     449,    26,    26,    58,    51,    41,    42,    43,    44,    45,
      46,    32,    32,    32,    30,    70,    52,    26,    73,     5,
       6,     7,     8,     9,    58,    26,   472,    13,    14,    15,
      16,    17,    59,    26,    26,    32,    70,    23,    32,    73,
      41,    42,    43,    44,    45,    46,    51,    33,    32,    30,
     424,    52,    30,    24,    33,    32,    32,   431,    32,    32,
      27,   435,    31,    19,    67,     5,     6,     7,     8,     9,
      24,    26,    58,    13,    14,    15,    16,    17,    27,    32,
      19,    26,    26,    23,    70,    26,    49,    73,     5,     6,
       7,     8,     9,    33,    26,    26,    13,    14,    15,    16,
      17,     5,     6,     7,     8,     9,    23,    26,   435,    13,
      14,    15,    16,    17,   349,   333,    33,   392,    58,    23,
      41,    42,    43,    44,    45,    46,   458,   282,   284,    33,
      70,    52,   263,    73,     5,     6,     7,     8,     9,    -1,
      -1,    58,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    23,    70,    58,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    70,    -1,    -1,    73,
       5,     6,     7,     8,     9,    26,    -1,    -1,    13,    14,
      15,    16,    17,    -1,    19,    -1,    -1,    58,    23,    -1,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    70,
      -1,    52,    73,     5,     6,     7,     8,     9,    -1,    -1,
      26,    13,    14,    15,    16,    17,    -1,    19,    -1,    -1,
      -1,    23,    -1,    58,    -1,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    70,    52,    -1,    73,     5,
       6,     7,     8,     9,    26,    -1,    -1,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    58,    23,    -1,    41,
      42,    43,    44,    45,    46,    -1,    -1,    33,    70,    -1,
      52,    73,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    58,    -1,    -1,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    34,    35,
      36,    37,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    58,    52,    -1,    -1,    -1,
      -1,    57,    26,    -1,    60,    -1,    -1,    70,    64,    65,
      73,    67,    22,    23,    24,    -1,    -1,    41,    42,    43,
      44,    45,    46,    -1,    34,    35,    36,    37,    52,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    23,    24,    -1,    57,    -1,    -1,
      60,    30,    -1,    -1,    64,    65,    -1,    67,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    23,    24,    52,    -1,    -1,    -1,    56,    30,    -1,
      -1,    60,    61,    62,    -1,    -1,    -1,    66,    67,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    23,    24,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    34,    35,    36,    37,
      26,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    41,    42,    43,    44,    45,
      46,    31,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    31,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    31,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    50,    -1,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,    79,     0,     3,    69,    71,    76,    80,    86,
      23,   230,   230,    30,    81,    83,    87,    31,    32,     4,
      32,    77,    82,   230,    90,    32,    54,    88,    92,    84,
      33,   230,    78,    93,    33,    89,    32,    91,   137,    13,
      14,    15,    55,    58,    94,   104,   106,   108,   110,    85,
      30,     5,     6,     7,     8,     9,    13,    14,    15,    16,
      17,    33,    58,    70,    73,   138,   153,   161,   165,   175,
     177,   186,   196,   198,   213,   230,    50,    95,   230,   230,
     230,   230,   114,   230,    88,    31,    30,    30,    30,   176,
      30,    50,   144,   230,   230,   230,    30,    30,   230,   230,
     214,    11,    12,    38,    24,   231,    26,    38,   102,    26,
      38,    26,    38,   109,    13,    14,    15,    18,    68,   111,
      33,    26,   154,   162,   166,    23,    24,    30,    41,    42,
      43,    44,    45,    46,    52,    60,    67,   223,   225,   227,
     229,   234,   235,   236,   178,   231,    26,    38,   147,    26,
      38,    26,    38,   187,   230,   142,    38,    59,   199,    30,
      32,    30,   139,    96,   103,   105,   107,   230,   230,   230,
     230,   230,   230,    30,    56,    62,   216,   218,   220,   216,
      13,   170,   230,   224,    26,   227,   227,    30,    50,   227,
     227,   227,   229,   145,   148,   140,   141,    22,   188,   197,
     230,   204,   200,    60,    67,   152,   230,   231,   232,   233,
     160,   157,   223,    51,   223,   223,   236,    26,   119,   123,
     127,   115,   131,   112,    21,    31,    20,    61,    66,   216,
     223,    31,   230,   229,    38,   223,   225,   229,   234,   225,
     229,   234,   223,   226,   229,   234,   235,   229,   234,   229,
     235,    31,    51,   223,   223,   223,   189,    28,    31,    31,
     143,   230,   230,    28,    31,   137,   216,    26,   230,    26,
      26,    26,    30,    30,    30,    30,    30,    13,    14,    15,
     132,   133,   217,   155,   219,   221,    30,    34,    35,    36,
      37,    39,    40,   228,   163,    38,   228,   172,    31,    31,
     234,   179,   230,    26,    26,    26,   193,   190,    26,    26,
      26,    38,   149,   205,   201,   230,   231,   232,   233,   215,
      33,    31,    97,   120,   124,   128,   116,    31,    50,   134,
     230,   230,   230,    28,    31,   218,    32,   220,   216,   222,
     223,    32,   171,   173,   229,   234,   223,    51,    32,   146,
      22,    23,    24,    57,    60,    64,    65,    67,   195,   227,
     228,    22,   191,   194,   229,   234,   235,   236,   150,    59,
      30,    26,   158,    26,    38,    98,   132,   132,   132,   132,
      26,   231,   133,   113,   156,   216,   164,   223,    26,    26,
     180,    98,   192,   230,   230,   202,    32,    32,    31,    31,
      31,    31,   135,    32,   137,    31,   137,    26,   167,   181,
     193,   151,   206,   209,   229,   234,   235,   236,   159,    99,
     121,   125,   129,   117,    51,   136,   137,    33,    33,   174,
     229,    10,    33,    63,    22,    30,    30,    28,    31,   137,
      24,   101,    32,    32,    32,    32,   230,    33,    31,    38,
      45,    46,   185,   230,   231,   233,    27,   152,   207,   210,
     211,   212,   236,   203,    33,    28,    33,   122,   126,   130,
     118,   168,   223,   182,   183,   184,    31,   209,   229,   234,
     235,    26,    24,   100,   137,   137,   137,   137,    32,    27,
      19,   137,    26,    31,    26,    33,    33,    33,    33,   169,
     137,    26,    19,   208,   137,    19,    26,    26,    33,    26
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    77,    78,    76,    79,    79,    79,    81,
      82,    80,    83,    84,    85,    80,    87,    86,    89,    88,
      90,    91,    90,    92,    92,    93,    93,    93,    93,    93,
      94,    95,    96,    97,    95,    98,    99,   100,    98,   101,
     101,   102,   102,   103,   102,   104,   105,   104,   106,   107,
     106,   109,   108,   110,   111,   112,   113,   110,   114,   115,
     116,   117,   118,   114,   119,   120,   121,   122,   114,   123,
     124,   125,   126,   114,   127,   128,   129,   130,   114,   131,
     114,   132,   132,   132,   133,   133,   133,   133,   134,   134,
     135,   134,   136,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   138,   139,   138,   140,   138,   138,
     141,   138,   138,   142,   143,   138,   144,   145,   146,   144,
     148,   147,   147,   150,   151,   149,   149,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   154,   155,   156,   153,
     157,   158,   159,   153,   160,   153,   162,   163,   164,   161,
     166,   167,   168,   169,   165,   171,   170,   172,   170,   173,
     173,   174,   174,   174,   176,   175,   178,   179,   180,   177,
     181,   182,   181,   183,   181,   184,   181,   185,   185,   185,
     187,   186,   188,   189,   188,   190,   188,   192,   191,   191,
     193,   193,   193,   193,   193,   193,   193,   194,   194,   194,
     194,   195,   195,   195,   195,   197,   196,   198,   200,   201,
     202,   203,   199,   204,   205,   206,   207,   208,   199,   209,
     209,   209,   209,   209,   210,   209,   211,   209,   209,   212,
     209,   214,   215,   213,   216,   217,   216,   218,   219,   218,
     220,   221,   220,   222,   220,   220,   220,   220,   220,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   224,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   226,   225,   227,   227,   227,   227,   227,   227,   227,
     227,   228,   228,   228,   228,   228,   228,   228,   229,   230,
     231,   232,   233,   234,   235,   236
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     0,     8,     0,     2,     2,     0,
       0,     7,     0,     0,     0,    10,     0,     6,     0,     4,
       0,     0,     6,     0,     3,     0,     2,     2,     2,     2,
       2,     2,     0,     0,     7,     1,     0,     0,     7,     1,
       3,     0,     1,     0,     4,     3,     0,     6,     3,     0,
       6,     0,     5,     0,     0,     0,     0,    11,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,    13,     0,
       0,     0,     0,    13,     0,     0,     0,     0,    13,     0,
       7,     0,     1,     3,     0,     2,     2,     2,     0,     1,
       0,     5,     1,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     0,     5,     0,     6,     3,
       0,     6,     3,     0,     0,     6,     2,     0,     0,     7,
       0,     4,     1,     0,     0,     8,     1,     0,     1,     1,
       1,     1,     3,     3,     3,     3,     0,     0,     0,    10,
       0,     0,     0,    11,     0,     6,     0,     0,     0,    10,
       0,     0,     0,     0,    16,     0,     6,     0,     5,     1,
       1,     3,     2,     2,     0,     4,     0,     0,     0,    10,
       0,     0,     8,     0,     6,     0,     7,     1,     1,     1,
       0,     6,     0,     0,     4,     0,     4,     0,     4,     1,
       0,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     3,     0,     0,
       0,     0,    10,     0,     0,     0,     0,     0,    13,     0,
       1,     1,     1,     1,     0,     4,     0,     4,     3,     0,
       4,     0,     0,     7,     1,     0,     4,     1,     0,     4,
       0,     0,     4,     0,     6,     4,     2,     1,     1,     0,
       3,     3,     1,     3,     3,     2,     3,     3,     3,     3,
       3,     0,     4,     4,     2,     2,     3,     3,     3,     1,
       1,     0,     5,     0,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
        case 3:
#line 177 "y.y" /* yacc.c:1646  */
    { write_main(); }
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 178 "y.y" /* yacc.c:1646  */
    { write_braces(OPEN_BRACE); }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 179 "y.y" /* yacc.c:1646  */
    { write_return_0(); write_braces(CLOSE_BRACE); }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 182 "y.y" /* yacc.c:1646  */
    { check_abstract_existence(); check_interface_methods(); }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 185 "y.y" /* yacc.c:1646  */
    { check_same_class_name();
            write_keywords(STRUCT_WORD); init_type_of_class(CLASS); }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 187 "y.y" /* yacc.c:1646  */
    { write_braces(OPEN_BRACE); init_globals_counter(); }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 189 "y.y" /* yacc.c:1646  */
    { check_same_class_name();
            write_keywords(STRUCT_WORD); init_type_of_class(CLASS); }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 191 "y.y" /* yacc.c:1646  */
    { check_class_name();
            insert_inherited_class(); init_inherited_vars_counter();
            insert_inherited_vars(); }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 194 "y.y" /* yacc.c:1646  */
    { write_braces(OPEN_BRACE); init_globals_counter(); }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 197 "y.y" /* yacc.c:1646  */
    { check_same_class_name(); insert_class_names();
            init_type_of_class(INTERFACE); }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 201 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, "};\n"); tabs--;
              init_methods_counter(); init_locals_counter(); }
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 206 "y.y" /* yacc.c:1646  */
    { write_methods(INTERFACE); }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 221 "y.y" /* yacc.c:1646  */
    { index_array = yylval.intval; }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 222 "y.y" /* yacc.c:1646  */
    { init_values(INIT_ARRAY); check_on_globals(DECLARED);
      save_global_var(INIT_ARRAY); write_brackets(OPEN_BRACKET);
      write_index_array(); write_brackets(CLOSE_BRACKET); }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 226 "y.y" /* yacc.c:1646  */
    { write_semicolon(); }
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 227 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " = {"); }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 228 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, "}"); }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 229 "y.y" /* yacc.c:1646  */
    { write_semicolon(); check_array_length(); digit_counter = 0;}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 231 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, "%d", yylval.intval); digit_counter++; }
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 232 "y.y" /* yacc.c:1646  */
    { write_symbols(COMMA);
      fprintf(yyout, "%d", yylval.intval); digit_counter++; }
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 236 "y.y" /* yacc.c:1646  */
    { init_values(INIT_INT);
       check_on_globals(DECLARED); save_global_var(INIT_INT); }
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 238 "y.y" /* yacc.c:1646  */
    { init_values(INIT_INT_EXPR); check_on_globals(DECLARED);
   save_global_var(INIT_INT); }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 239 "y.y" /* yacc.c:1646  */
    { write_semicolon(); }
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 242 "y.y" /* yacc.c:1646  */
    { init_values(INIT_DOUBLE); check_on_globals(DECLARED);
          save_global_var(INIT_DOUBLE);}
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 245 "y.y" /* yacc.c:1646  */
    { init_values(INIT_DOUBLE_EXPR); check_on_globals(DECLARED);
          save_global_var(INIT_DOUBLE); }
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 247 "y.y" /* yacc.c:1646  */
    { write_semicolon(); }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 250 "y.y" /* yacc.c:1646  */
    { init_values(INIT_CHAR); check_on_globals(DECLARED);
            save_global_var(INIT_CHAR); }
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 252 "y.y" /* yacc.c:1646  */
    { init_values(INIT_CHAR_EXPR);
            check_on_globals(DECLARED); save_global_var(INIT_CHAR); }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 254 "y.y" /* yacc.c:1646  */
    { write_semicolon(); }
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 256 "y.y" /* yacc.c:1646  */
    { check_class_name(); }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 257 "y.y" /* yacc.c:1646  */
    { init_values(INIT_OBJECT); check_on_globals(DECLARED);
            save_global_var(INIT_OBJECT); }
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 261 "y.y" /* yacc.c:1646  */
    { write_methods(CONSTRUCTOR); }
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 262 "y.y" /* yacc.c:1646  */
    { write_parenthesis(OPEN_PAR); write_par_values(INIT_OBJECT); }
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 263 "y.y" /* yacc.c:1646  */
    { write_parenthesis(CLOSE_PAR);
        write_braces(OPEN_BRACE); }
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 265 "y.y" /* yacc.c:1646  */
    { write_braces(CLOSE_BRACE); }
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 268 "y.y" /* yacc.c:1646  */
    { check_same_method_name();
    write_methods(VOID_METHOD); }
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 270 "y.y" /* yacc.c:1646  */
    { write_parenthesis(OPEN_PAR); write_par_values(INIT_OBJECT); }
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 271 "y.y" /* yacc.c:1646  */
    { write_parenthesis(CLOSE_PAR); }
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 272 "y.y" /* yacc.c:1646  */
    { write_braces(OPEN_BRACE); }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 273 "y.y" /* yacc.c:1646  */
    { write_braces(CLOSE_BRACE); }
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 274 "y.y" /* yacc.c:1646  */
    { check_same_method_name(); write_methods(INT_METHOD); }
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 275 "y.y" /* yacc.c:1646  */
    { write_parenthesis(OPEN_PAR); write_par_values(INIT_OBJECT); }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 276 "y.y" /* yacc.c:1646  */
    { write_parenthesis(CLOSE_PAR); }
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 277 "y.y" /* yacc.c:1646  */
    { write_braces(OPEN_BRACE); }
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 278 "y.y" /* yacc.c:1646  */
    { write_braces(CLOSE_BRACE); check_return_bool(); }
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 279 "y.y" /* yacc.c:1646  */
    { check_same_method_name();
    write_methods(DOUBLE_METHOD); }
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 281 "y.y" /* yacc.c:1646  */
    { write_parenthesis(OPEN_PAR); write_par_values(INIT_OBJECT); }
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 282 "y.y" /* yacc.c:1646  */
    { write_parenthesis(CLOSE_PAR); }
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 283 "y.y" /* yacc.c:1646  */
    { write_braces(OPEN_BRACE); }
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 284 "y.y" /* yacc.c:1646  */
    { write_braces(CLOSE_BRACE); check_return_bool(); }
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 285 "y.y" /* yacc.c:1646  */
    { check_same_method_name();
    write_methods(CHAR_METHOD); }
#line 2238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 287 "y.y" /* yacc.c:1646  */
    { write_parenthesis(OPEN_PAR); write_par_values(INIT_OBJECT); }
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 288 "y.y" /* yacc.c:1646  */
    { write_parenthesis(CLOSE_PAR); }
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 289 "y.y" /* yacc.c:1646  */
    { write_braces(OPEN_BRACE); }
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 290 "y.y" /* yacc.c:1646  */
    { write_braces(CLOSE_BRACE); check_return_bool(); }
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 291 "y.y" /* yacc.c:1646  */
    { check_same_method_name(); save_abstract(); }
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 300 "y.y" /* yacc.c:1646  */
    { write_par_values(INIT_DOUBLE); save_pars(INIT_DOUBLE); }
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 301 "y.y" /* yacc.c:1646  */
    { write_par_values(INIT_CHAR); save_pars(INIT_CHAR); }
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 304 "y.y" /* yacc.c:1646  */
    { write_par_values(INIT_INT); save_pars(INIT_INT); }
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 305 "y.y" /* yacc.c:1646  */
    { index_array = yylval.intval; }
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 306 "y.y" /* yacc.c:1646  */
    { write_par_values(INIT_ARRAY); save_pars(INIT_ARRAY);
      write_brackets(OPEN_BRACKET); write_index_array();
      write_brackets(CLOSE_BRACKET); }
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 325 "y.y" /* yacc.c:1646  */
    { init_values(EXPRESSION); find_type();
        check_on_locals(UNDECLARED); }
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 327 "y.y" /* yacc.c:1646  */
    { write_semicolon(); }
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 329 "y.y" /* yacc.c:1646  */
    { init_values(INIT_DOUBLE_EXPR); check_on_locals(DECLARED);
      save_local_vars(INIT_DOUBLE_EXPR); }
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 331 "y.y" /* yacc.c:1646  */
    { write_semicolon(); }
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 333 "y.y" /* yacc.c:1646  */
    { init_values(INIT_DOUBLE); check_on_locals(DECLARED);
    save_local_vars(INIT_DOUBLE_EXPR); }
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 336 "y.y" /* yacc.c:1646  */
    { init_values(INIT_CHAR_EXPR); check_on_locals(DECLARED);
        save_local_vars(INIT_CHAR_EXPR); }
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 338 "y.y" /* yacc.c:1646  */
    { write_semicolon(); }
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 340 "y.y" /* yacc.c:1646  */
    { init_values(INIT_CHAR); check_on_locals(DECLARED);
        save_local_vars(INIT_CHAR_EXPR); }
#line 2353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 342 "y.y" /* yacc.c:1646  */
    { check_class_name(); }
#line 2359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 342 "y.y" /* yacc.c:1646  */
    { init_object_call(); }
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 343 "y.y" /* yacc.c:1646  */
    { clear_constructor_pars(); }
#line 2371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 346 "y.y" /* yacc.c:1646  */
    { index_array = yylval.intval; }
#line 2377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 347 "y.y" /* yacc.c:1646  */
    { init_values(INIT_ARRAY); check_on_locals(DECLARED);
      save_local_vars(INIT_ARRAY); write_brackets(OPEN_BRACKET);
      write_index_array(); write_brackets(CLOSE_BRACKET); }
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 352 "y.y" /* yacc.c:1646  */
    { init_values(INIT_INT_EXPR); check_on_locals(DECLARED);
            save_local_vars(INIT_INT_EXPR); }
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 354 "y.y" /* yacc.c:1646  */
    { write_semicolon(); }
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 355 "y.y" /* yacc.c:1646  */
    { init_values(INIT_INT); check_on_locals(DECLARED);
   save_local_vars(INIT_INT_EXPR); }
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 359 "y.y" /* yacc.c:1646  */
    { init_values(INIT_OBJECT); check_on_locals(DECLARED);
        save_local_vars(INIT_OBJECT_EXPR); }
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 360 "y.y" /* yacc.c:1646  */
    { check_method_name(); }
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 362 "y.y" /* yacc.c:1646  */
    { choose_constructor(NEW); clear_actualpars_arr(); init_last_type(); }
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 363 "y.y" /* yacc.c:1646  */
    { init_values(INIT_OBJECT); check_on_locals(DECLARED);
        save_local_vars(INIT_OBJECT_EXPR); init_last_type(); }
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 367 "y.y" /* yacc.c:1646  */
    { save_actualpars(ID); combine_constructor_pars(ID); }
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 368 "y.y" /* yacc.c:1646  */
    { save_actualpars(CHAR); combine_constructor_pars(ID); }
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 369 "y.y" /* yacc.c:1646  */
    { save_actualpars(DIGIT); combine_constructor_pars(DIGIT); }
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 370 "y.y" /* yacc.c:1646  */
    { save_actualpars(DOUBLE);
      combine_constructor_pars(DOUBLE); }
#line 2456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 372 "y.y" /* yacc.c:1646  */
    { save_actualpars(ID);
      combine_constructor_pars(COMMA_ID); }
#line 2463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 374 "y.y" /* yacc.c:1646  */
    { save_actualpars(DIGIT);
      combine_constructor_pars(COMMA_DIGIT); }
#line 2470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 376 "y.y" /* yacc.c:1646  */
    { save_actualpars(CHAR);
      combine_constructor_pars(COMMA_ID); }
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 378 "y.y" /* yacc.c:1646  */
    { save_actualpars(DOUBLE);
      combine_constructor_pars(COMMA_DOUBLE); }
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 381 "y.y" /* yacc.c:1646  */
    { write_keywords(IF_WORD); }
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 382 "y.y" /* yacc.c:1646  */
    { write_parenthesis(CLOSE_PAR); }
#line 2496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 383 "y.y" /* yacc.c:1646  */
    { write_braces(OPEN_BRACE); }
#line 2502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 384 "y.y" /* yacc.c:1646  */
    { write_braces(CLOSE_BRACE); }
#line 2508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 385 "y.y" /* yacc.c:1646  */
    { write_keywords(ELIF_WORD); }
#line 2514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 386 "y.y" /* yacc.c:1646  */
    { write_parenthesis(CLOSE_PAR); }
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 387 "y.y" /* yacc.c:1646  */
    { write_braces(OPEN_BRACE); }
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 388 "y.y" /* yacc.c:1646  */
    { write_braces(CLOSE_BRACE); }
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 389 "y.y" /* yacc.c:1646  */
    { write_keywords(ELSE_WORD); }
#line 2538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 390 "y.y" /* yacc.c:1646  */
    { write_braces(CLOSE_BRACE); }
#line 2544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 392 "y.y" /* yacc.c:1646  */
    { write_keywords(WHILE_WORD); }
#line 2550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 393 "y.y" /* yacc.c:1646  */
    { write_parenthesis(CLOSE_PAR); }
#line 2556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 394 "y.y" /* yacc.c:1646  */
    { write_braces(OPEN_BRACE); }
#line 2562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 395 "y.y" /* yacc.c:1646  */
    { write_braces(CLOSE_BRACE); }
#line 2568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 397 "y.y" /* yacc.c:1646  */
    { write_keywords(FOR_WORD); }
#line 2574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 398 "y.y" /* yacc.c:1646  */
    { write_for_semicolon(); }
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 399 "y.y" /* yacc.c:1646  */
    { write_parenthesis(CLOSE_PAR); }
#line 2586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 400 "y.y" /* yacc.c:1646  */
    { write_braces(OPEN_BRACE); }
#line 2592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 401 "y.y" /* yacc.c:1646  */
    { write_braces(CLOSE_BRACE); }
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 403 "y.y" /* yacc.c:1646  */
    { check_on_locals(DECLARED);
        init_for_values(INIT_INT_EXPR);
        save_local_vars(INIT_INT_EXPR); }
#line 2606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 406 "y.y" /* yacc.c:1646  */
    { write_for_semicolon(); }
#line 2612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 407 "y.y" /* yacc.c:1646  */
    { init_for_values(EXPRESSION); check_on_locals(UNDECLARED); }
#line 2618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 408 "y.y" /* yacc.c:1646  */
    { write_for_semicolon(); }
#line 2624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 414 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, "++"); }
#line 2630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 415 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, "--"); }
#line 2636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 417 "y.y" /* yacc.c:1646  */
    { write_keywords(RETURN_WORD); }
#line 2642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 418 "y.y" /* yacc.c:1646  */
    { write_semicolon(); return_bool = 1; }
#line 2648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 420 "y.y" /* yacc.c:1646  */
    { write_keywords(SWITCH_WORD); }
#line 2654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 421 "y.y" /* yacc.c:1646  */
    { write_parenthesis(CLOSE_PAR); }
#line 2660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 422 "y.y" /* yacc.c:1646  */
    { write_braces(OPEN_BRACE); }
#line 2666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 423 "y.y" /* yacc.c:1646  */
    { write_braces(CLOSE_BRACE); }
#line 2672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 426 "y.y" /* yacc.c:1646  */
    { write_keywords(CASE_WORD); }
#line 2678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 427 "y.y" /* yacc.c:1646  */
    { write_keywords(BREAK_WORD); }
#line 2684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 428 "y.y" /* yacc.c:1646  */
    { write_keywords(DEFAULT_WORD); }
#line 2690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 429 "y.y" /* yacc.c:1646  */
    { write_keywords(BREAK_WORD); }
#line 2696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 430 "y.y" /* yacc.c:1646  */
    { write_keywords(DEFAULT_WORD); }
#line 2702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 431 "y.y" /* yacc.c:1646  */
    { write_keywords(BREAK_WORD); }
#line 2708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 433 "y.y" /* yacc.c:1646  */
    { case_type = CASE_ID; }
#line 2714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 434 "y.y" /* yacc.c:1646  */
    { case_type = CASE_DIGIT; }
#line 2720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 435 "y.y" /* yacc.c:1646  */
    { case_type = CASE_CHAR; }
#line 2726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 437 "y.y" /* yacc.c:1646  */
    { write_keywords(PRINT_WORD);
        init_placeholder_counter(); }
#line 2733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 439 "y.y" /* yacc.c:1646  */
    { write_parenthesis(CLOSE_PAR_AND_SEMICOLON); }
#line 2739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 442 "y.y" /* yacc.c:1646  */
    { write_symbols(APOSTROPHE);
    init_placeholder_counter(); }
#line 2746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 444 "y.y" /* yacc.c:1646  */
    { write_symbols(APOSTROPHE); init_placeholder_counter(); }
#line 2752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 445 "y.y" /* yacc.c:1646  */
    { write_symbols(COMMA); }
#line 2758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 447 "y.y" /* yacc.c:1646  */
    { write_symbols(APOSTROPHE);
   init_placeholder_counter(); }
#line 2765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 449 "y.y" /* yacc.c:1646  */
    { write_symbols(APOSTROPHE); init_placeholder_counter(); }
#line 2771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 456 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s", d_placeholder);
        count_printf_vars(INIT_INT); }
#line 2778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 458 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s", c_placeholder);
        count_printf_vars(INIT_CHAR); }
#line 2785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 460 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s", f_placeholder);
        count_printf_vars(INIT_DOUBLE); }
#line 2792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 463 "y.y" /* yacc.c:1646  */
    { find_type(); check_placeholder(); init_last_type(); }
#line 2798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 464 "y.y" /* yacc.c:1646  */
    { strcpy(last_type, "int"); check_placeholder(); init_last_type(); }
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 465 "y.y" /* yacc.c:1646  */
    { strcpy(last_type, "double"); check_placeholder();
                  init_last_type(); }
#line 2811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 467 "y.y" /* yacc.c:1646  */
    { strcpy(last_type, "char"); check_placeholder();
                  init_last_type(); }
#line 2818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 470 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s", yylval.string); }
#line 2824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 471 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, "%d", yylval.intval); }
#line 2830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 472 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %f", yylval.doubleval); }
#line 2836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 473 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s", yylval.string); }
#line 2842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 475 "y.y" /* yacc.c:1646  */
    { init_placeholder_counter();
  write_keywords(INPUT_WORD); }
#line 2849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 477 "y.y" /* yacc.c:1646  */
    { write_parenthesis(CLOSE_PAR_AND_SEMICOLON); }
#line 2855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 481 "y.y" /* yacc.c:1646  */
    { init_object_call(); call_search(); find_type();
        init_last_type(); }
#line 2862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 482 "y.y" /* yacc.c:1646  */
    { write_keywords(CALL_WORD);
        check_method_name(); }
#line 2869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 483 "y.y" /* yacc.c:1646  */
    { write_parenthesis(OPEN_PAR);
        write_object_on_pars(); }
#line 2876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 485 "y.y" /* yacc.c:1646  */
    { check_types_actualpars(); }
#line 2882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 486 "y.y" /* yacc.c:1646  */
    { write_parenthesis(CLOSE_PAR_AND_SEMICOLON); clear_actualpars_arr(); }
#line 2888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 487 "y.y" /* yacc.c:1646  */
    { id_return_type(); write_call_return(); }
#line 2894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 488 "y.y" /* yacc.c:1646  */
    { init_object_call(); call_search(); find_type(); init_last_type(); }
#line 2900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 489 "y.y" /* yacc.c:1646  */
    { write_keywords(CALL_WORD); check_method_name();
        check_same_return_type(); }
#line 2907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 490 "y.y" /* yacc.c:1646  */
    { write_parenthesis(OPEN_PAR);
        write_object_on_pars(); }
#line 2914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 492 "y.y" /* yacc.c:1646  */
    { check_types_actualpars(); }
#line 2920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 493 "y.y" /* yacc.c:1646  */
    { write_parenthesis(CLOSE_PAR_AND_SEMICOLON); clear_actualpars_arr();
        clear_id_return_type_arr(); }
#line 2927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 497 "y.y" /* yacc.c:1646  */
    { save_actualpars(ID); }
#line 2933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 498 "y.y" /* yacc.c:1646  */
    { save_actualpars(CHAR); }
#line 2939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 499 "y.y" /* yacc.c:1646  */
    { save_actualpars(DIGIT); }
#line 2945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 500 "y.y" /* yacc.c:1646  */
    { save_actualpars(DOUBLE); }
#line 2951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 501 "y.y" /* yacc.c:1646  */
    { write_symbols(COMMA); }
#line 2957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 501 "y.y" /* yacc.c:1646  */
    { save_actualpars(ID); }
#line 2963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 502 "y.y" /* yacc.c:1646  */
    { write_symbols(COMMA); }
#line 2969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 502 "y.y" /* yacc.c:1646  */
    { save_actualpars(DIGIT);}
#line 2975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 503 "y.y" /* yacc.c:1646  */
    { save_actualpars(CHAR); }
#line 2981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 504 "y.y" /* yacc.c:1646  */
    { write_symbols(COMMA); }
#line 2987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 505 "y.y" /* yacc.c:1646  */
    { save_actualpars(DOUBLE); }
#line 2993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 507 "y.y" /* yacc.c:1646  */
    { make_custom_ob(); init_object_class(); }
#line 2999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 509 "y.y" /* yacc.c:1646  */
    { choose_constructor(SUPER); clear_actualpars_arr();
          init_last_type();}
#line 3006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 513 "y.y" /* yacc.c:1646  */
    { write_symbols(OR); }
#line 3012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 516 "y.y" /* yacc.c:1646  */
    { write_symbols(AND); }
#line 3018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 519 "y.y" /* yacc.c:1646  */
    { write_symbols(NOT); }
#line 3024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 520 "y.y" /* yacc.c:1646  */
    { write_symbols(NOTEQUAL); }
#line 3030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 521 "y.y" /* yacc.c:1646  */
    { write_parenthesis(CLOSE_PAR); }
#line 3036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 539 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, "%s", yylval.string); }
#line 3042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 540 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, "%s", yylval.string); }
#line 3048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 550 "y.y" /* yacc.c:1646  */
    { write_brackets(OPEN_BRACKET); }
#line 3054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 551 "y.y" /* yacc.c:1646  */
    { write_brackets(CLOSE_BRACKET); }
#line 3060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 554 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s ", yylval.string); }
#line 3066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 555 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s ", yylval.string); }
#line 3072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 556 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s ", yylval.string); }
#line 3078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 557 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s ", yylval.string); }
#line 3084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 558 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s ", yylval.string); }
#line 3090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 559 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, "%s", yylval.string); }
#line 3096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 560 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, "%s", yylval.string); }
#line 3102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 563 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s ", yylval.string); }
#line 3108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 564 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s ", yylval.string); }
#line 3114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 565 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s ", yylval.string); }
#line 3120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 566 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s ", yylval.string); }
#line 3126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 567 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s ", yylval.string); }
#line 3132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 568 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s ", yylval.string); }
#line 3138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 570 "y.y" /* yacc.c:1646  */
    { check_on_locals(UNDECLARED); write_id(); }
#line 3144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 580 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %d", yylval.intval); }
#line 3150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 582 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %f", yylval.doubleval); }
#line 3156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 584 "y.y" /* yacc.c:1646  */
    { fprintf(yyout, " %s", yylval.string); }
#line 3162 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3166 "y.tab.c" /* yacc.c:1646  */
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
#line 586 "y.y" /* yacc.c:1906  */


int main(int argc, char **argv) {
    if(argc > 1) {
        if(!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return 1;
        }
    }
    yyout = fopen(argv[2], "w+");
    yyparse();
    return 0;
}

yyerror(char *s) {
    fprintf(stderr, "error: line %d: %s\n", linenum, s);
}

void how_many_tabs() {
    int i = 0;
    while(i < tabs) {
        fprintf(yyout, "\t");
        i++;
    }
}

int return_methods_counter() {
  return classes[class_counter-1].methods_counter;
}

int return_number_of_globals() {
  return classes[class_counter-1].number_of_globals;
}

int return_number_of_vars() {
  return classes[class_counter-1].method[return_methods_counter()-1]
  .number_of_vars;
}

int return_number_of_pars() {
  return classes[class_counter-1].method[return_methods_counter()-1]
  .number_of_pars;
}

void write_semicolon() {
    fprintf(yyout, ";\n");
    init_last_type();
    self = 0;
}

void write_for_semicolon() {
    fprintf(yyout, "; ");
}

void write_keywords(int keyword) {
    switch(keyword) {
        case STRUCT_WORD:
            how_many_tabs();
            fprintf(yyout, "struct %s\n", yylval.string);
            insert_class_names();
            break;
        case IF_WORD:
            how_many_tabs();
            fprintf(yyout, "if %s", yylval.string);
            break;
        case ELIF_WORD:
            how_many_tabs();
            fprintf(yyout, "elif %s", yylval.string);
            break;
        case ELSE_WORD:
            how_many_tabs();
            fprintf(yyout, "else {\n");
            tabs++;
            break;
        case WHILE_WORD:
            how_many_tabs();
            fprintf(yyout, "while %s", yylval.string);
            break;
        case FOR_WORD:
            how_many_tabs();
            fprintf(yyout, "for %s", yylval.string);
            break;
        case SWITCH_WORD:
            how_many_tabs();
            fprintf(yyout, "switch%s", yylval.string);
            break;
        case CASE_WORD:
            how_many_tabs();
            switch(case_type) {
              case CASE_ID:
                check_on_locals(UNDECLARED);
                fprintf(yyout, "case ");
                write_id();
                fprintf(yyout, ":\n\t");
                break;
              case CASE_DIGIT:
                fprintf(yyout, "case %d: \n\t", yylval.intval);
                break;
              case CASE_CHAR:
                fprintf(yyout, "case %s: \n\t", yylval.string);
                break;
              default:
                printf("Something goes wrong in cases!\n");
                break;
            }
            break;
        case DEFAULT_WORD:
            how_many_tabs();
            fprintf(yyout, "default:\n");
            break;
        case BREAK_WORD:
            how_many_tabs();
            fprintf(yyout, "\tbreak;\n");
            break;
        case PRINT_WORD:
            how_many_tabs();
            fprintf(yyout, "printf %s", yylval.string);
            break;
        case INPUT_WORD:
            how_many_tabs();
            fprintf(yyout, "scanf('");
            scanf_placeholder();
            check_on_locals(UNDECLARED);
            fprintf(yyout, "', &");
            write_id();
            break;
        case CALL_WORD:
            if(id_return_type_arr[0] == '\0') {
              how_many_tabs();
            }
            fprintf(yyout, "%s.%s", object_call, yylval.string);
            break;
        case RETURN_WORD:
            how_many_tabs();
            fprintf(yyout, "return ");
            break;
        default:
            printf("Something goes wrong with statements!\n");
            break;
    }
}

void write_braces(int brace) {
    switch(brace) {
        case OPEN_BRACE:
            how_many_tabs();
            fprintf(yyout, "{\n");
            tabs++;
            break;
        case CLOSE_BRACE:
            tabs--;
            how_many_tabs();
            fprintf(yyout, "}\n");
            break;
        default:
            printf("Something goes wrong with braces!\n");
            break;
    }
}

void write_parenthesis(int par) {
    switch(par) {
        case OPEN_PAR:
            fprintf(yyout, "(");
            break;
        case CLOSE_PAR:
            fprintf(yyout, ")\n");
            break;
        case CLOSE_PAR_AND_SEMICOLON:
            fprintf(yyout, ");\n");
            break;
        default:
            printf("Something goes wrong with parenthesis!\n");
            break;
    }
}

void write_brackets(int bracket) {
  switch(bracket) {
      case OPEN_BRACKET:
          fprintf(yyout, "[");
          break;
      case CLOSE_BRACKET:
          fprintf(yyout, "]");
          break;
      default:
          printf("Something goes wrong with brackets!\n");
          break;
  }
}

void write_symbols(int symbol) {
    switch(symbol) {
        case COMMA:
            fprintf(yyout, ", ");
            break;
        case APOSTROPHE:
            fprintf(yyout, "'");
            break;
        case OR:
            fprintf(yyout, " || ");
            break;
        case AND:
            fprintf(yyout, " && ");
            break;
        case NOT:
            fprintf(yyout, "!");
            break;
        case NOTEQUAL:
            fprintf(yyout, " != (");
            break;
        default:
            printf("Something goes wrong with symbols!\n");
            break;
    }
}

void write_methods(int type) {
  char *class_name = classes[class_counter-1].name_of_class;
  int methods_counter = return_methods_counter();
  switch(type) {
    case CONSTRUCTOR:
      fprintf(yyout, "void %s@constructor%d", class_name, methods_counter);
      insert_method_names_and_type("void");
      break;
    case VOID_METHOD:
      fprintf(yyout, "void %s@%s", class_name, yylval.string);
      insert_method_names_and_type("void");
      break;
    case INT_METHOD:
      fprintf(yyout, "int %s@%s", class_name, yylval.string);
      insert_method_names_and_type("int");
      break;
    case DOUBLE_METHOD:
      fprintf(yyout, "double %s@%s", class_name, yylval.string);
      insert_method_names_and_type("double");
      break;
    case CHAR_METHOD:
      fprintf(yyout, "char %s@%s", class_name, yylval.string);
      insert_method_names_and_type("char");
      break;
    case INTERFACE:
      insert_method_names_and_type("void");
      break;
    default:
      printf("Something goes wrong with methods!");
      break;
  }
}

void write_object_on_pars() {
  switch(search_where_var_is()) {
    case LOCAL:
      if(classes[class_to_call].method[method_to_call].number_of_pars == 0) {
        fprintf(yyout, "%s", object_call);
      } else {
        fprintf(yyout, "%s, ", object_call);
      }
      break;
    case GLOBAL:
      if(classes[class_to_call].method[method_to_call].number_of_pars == 0) {
        fprintf(yyout, "self.%s", object_call);
      } else {
        fprintf(yyout, "self.%s, ", object_call);
      }
      break;
    default:
      printf("Something goes wron in write_object_on_pars!\n");
      break;
  }
}

void write_id() {
  if(self == GLOBAL) {
    fprintf(yyout, "self.%s", yylval.string);
    self = 0;
  } else if(self == INH) {
    fprintf(yyout, "%sself.%s", classes[class_counter-1]
    .name_of_inherited_class, yylval.string);
    self = 0;
  }else {
    fprintf(yyout, "%s", yylval.string);
    self = 0;
  }
}

void write_main() {
  fprintf(yyout, "int main() ");
}

void write_call_return() {
  how_many_tabs();
  fprintf(yyout, "%s = ", yylval.string);
}

void write_return_0() {
  fprintf(yyout, "\treturn 0;\n");
}

void write_index_array() {
  fprintf(yyout, "%d", index_array);
}

void init_values(int var_type) {
    switch(var_type) {
        case INIT_INT:
            how_many_tabs();
            fprintf(yyout, "int %s;\n", yylval.string);
            init_last_type();
            break;
        case INIT_DOUBLE:
            how_many_tabs();
            fprintf(yyout, "double %s;\n", yylval.string);
            init_last_type();
            break;
        case INIT_CHAR:
            how_many_tabs();
            fprintf(yyout, "char %s;\n", yylval.string);
            init_last_type();
            break;
        case INIT_INT_EXPR:
            how_many_tabs();
            fprintf(yyout, "int %s =", yylval.string);
            strcpy(last_type, "int");
            break;
        case INIT_DOUBLE_EXPR:
            how_many_tabs();
            fprintf(yyout, "double %s =", yylval.string);
            strcpy(last_type, "double");
            break;
        case INIT_CHAR_EXPR:
            how_many_tabs();
            fprintf(yyout, "char %s =", yylval.string);
            strcpy(last_type, "char");
            break;
        case INIT_ARRAY:
            how_many_tabs();
            fprintf(yyout, "int %s", yylval.string);
            strcpy(last_type, "arr");
            break;
        case EXPRESSION:
            how_many_tabs();
            check_on_locals(UNDECLARED);
            write_id();
            fprintf(yyout, " =");
            break;
        case INIT_OBJECT:
            how_many_tabs();
            fprintf(yyout, "struct %s %s;\n", object_class, yylval.string);
            //strcpy(last_type, object_class);
            break;
        default:
            printf("No declarations!\n");
            break;
    }
}

void init_for_values(int var_type) {
    switch(var_type) {
        case INIT_INT_EXPR:
            fprintf(yyout, "int %s =", yylval.string);
            break;
        case EXPRESSION:
            fprintf(yyout, "%s =", yylval.string);
            break;
        default:
            printf("Something goes with for!");
            break;
    }
}

void init_type_of_class(int type) {
  switch(type) {
    case CLASS:
      classes[class_counter-1].interface = CLASS;
      break;
    case INTERFACE:
      classes[class_counter-1].interface = INTERFACE;
      break;
    default:
      printf("Something goes wrong with initializing interface!");
      break;
  }
}

void write_par_values(int var_type) {
    switch(var_type) {
      case INIT_INT:
          fprintf(yyout, ", int %s", yylval.string);
          strcpy(last_type, "int");
          break;
      case INIT_DOUBLE:
          fprintf(yyout, ", double %s", yylval.string);
          strcpy(last_type, "double");
          break;
      case INIT_CHAR:
          fprintf(yyout, ", char %s", yylval.string);
          strcpy(last_type, "char");
          break;
      case INIT_ARRAY:
          fprintf(yyout, ", int %s", yylval.string);
          strcpy(last_type, "arr");
          break;
      case INIT_OBJECT:
          fprintf(yyout, "%s self", classes[class_counter-1].name_of_class);
          if(strcmp(classes[class_counter-1].name_of_inherited_class, "") != 0)
          {
            fprintf(yyout, ", %s %sself", classes[class_counter-1]
                              .name_of_inherited_class
                              , classes[class_counter-1]
                                          .name_of_inherited_class);
          }
          break;
      default:
          printf("No parameters!\n");
          break;
  }
}

void init_methods_counter() {
  classes[class_counter-1].methods_counter = 0;
}

void init_globals_counter() {
  classes[class_counter-1].number_of_globals = 0;
}

void init_locals_counter() {
  int methods_counter = return_methods_counter() - 1;
  classes[class_counter-1].method[methods_counter].number_of_vars = 0;
}

void init_pars_counter() {
  int methods_counter = return_methods_counter() - 1;
  classes[class_counter-1].method[methods_counter].number_of_pars = 0;
}

void init_last_type() {
  strcpy(last_type, "nothing");
}

void init_object_call() {
  strcpy(object_call, yylval.string);
}

void init_inherited_vars_counter() {
  classes[class_counter-1].number_of_inherited_vars = 0;
}

void init_abstract_counter() {
  classes[class_counter-1].number_of_abstract = 0;
}

void insert_inherited_vars() {
  int number_of_inherited_vars = classes[class_counter-1]
                  .number_of_inherited_vars;
  int i = 0, j = 0;
  for(i = 0; i < class_counter; i++) {
    if(strcmp(classes[i].name_of_class, yylval.string) == 0) {
      for(j = 0; j < classes[i].number_of_globals; j++) {
        number_of_inherited_vars = classes[class_counter-1]
                        .number_of_inherited_vars;
        strcpy(classes[class_counter-1].type_of_inherited_vars
          [number_of_inherited_vars], classes[i].type_of_each_global[j]);
        strcpy(classes[class_counter-1].name_of_inherited_vars
          [number_of_inherited_vars], classes[i].name_of_each_global[j]);
          classes[class_counter-1].number_of_inherited_vars++;
      }
      break;
    }
  }
}

void insert_class_names() {
  strcpy(classes[class_counter].name_of_class, yylval.string);
  class_counter++;
}

void insert_method_names_and_type(char type[NAME_LENGTH]) {
  int methods_counter = return_methods_counter();
  strcpy(classes[class_counter-1]
                      .method[methods_counter].name_of_method, yylval.string);
  strcpy(classes[class_counter-1].method[methods_counter].return_type, type);
  classes[class_counter-1].methods_counter++;
}

void insert_inherited_class() {
  strcpy(classes[class_counter-1]
      .name_of_inherited_class, yylval.string);
}

void save_global_var(int type) {
  int number_of_globals = return_number_of_globals();
  switch(type) {
    case INIT_INT:
      strcpy(classes[class_counter-1]
                  .type_of_each_global[number_of_globals], "int");
      strcpy(classes[class_counter-1]
                  .name_of_each_global[number_of_globals], yylval.string);
      break;
    case INIT_DOUBLE:
      strcpy(classes[class_counter-1]
                  .type_of_each_global[number_of_globals], "double");
      strcpy(classes[class_counter-1]
                  .name_of_each_global[number_of_globals], yylval.string);
      break;
    case INIT_CHAR:
      strcpy(classes[class_counter-1]
                  .type_of_each_global[number_of_globals], "char");
      strcpy(classes[class_counter-1]
                  .name_of_each_global[number_of_globals], yylval.string);
      break;
    case INIT_ARRAY:
      strcpy(classes[class_counter-1]
                  .type_of_each_global[number_of_globals], "arr");
      strcpy(classes[class_counter-1]
                  .name_of_each_global[number_of_globals], yylval.string);
      break;
    case INIT_OBJECT:
      strcpy(classes[class_counter-1]
                .type_of_each_global[number_of_globals], object_class);
      strcpy(classes[class_counter-1]
                .name_of_each_global[number_of_globals], yylval.string);
      break;
    default:
      printf("Somethig goes wrong on saving globals!\n");
      break;
  }
  classes[class_counter-1].number_of_globals++;
}

void save_local_vars(int type) {
  int methods_counter = return_methods_counter() - 1;
  int number_of_vars = return_number_of_vars();
  switch(type) {
    case INIT_INT_EXPR:
      strcpy(classes[class_counter-1].method[methods_counter]
                            .type_of_each_var[number_of_vars], "int");
      strcpy(classes[class_counter-1].method[methods_counter]
                            .name_of_each_var[number_of_vars], yylval.string);
      break;
    case INIT_DOUBLE_EXPR:
      strcpy(classes[class_counter-1].method[methods_counter]
                            .type_of_each_var[number_of_vars], "double");
      strcpy(classes[class_counter-1].method[methods_counter]
                            .name_of_each_var[number_of_vars], yylval.string);
      break;
    case INIT_CHAR_EXPR:
      strcpy(classes[class_counter-1].method[methods_counter]
                            .type_of_each_var[number_of_vars], "char");
      strcpy(classes[class_counter-1].method[methods_counter]
                            .name_of_each_var[number_of_vars], yylval.string);
      break;
    case INIT_ARRAY:
      strcpy(classes[class_counter-1].method[methods_counter]
                            .type_of_each_var[number_of_vars], "arr");
      strcpy(classes[class_counter-1].method[methods_counter]
                            .name_of_each_var[number_of_vars], yylval.string);
      break;
    case INIT_OBJECT_EXPR:
      strcpy(classes[class_counter-1].method[methods_counter]
                            .type_of_each_var[number_of_vars], object_class);
      strcpy(classes[class_counter-1].method[methods_counter]
                            .name_of_each_var[number_of_vars], yylval.string);
      break;
    default:
      printf("Somethig goes wrong on saving locals!\n");
      break;
  }
  classes[class_counter-1].method[methods_counter].number_of_vars++;
}

void save_pars(int type) {
  int methods_counter = return_methods_counter() - 1;
  int number_of_pars = return_number_of_pars();
  switch(type) {
    case INIT_INT:
      strcpy(classes[class_counter-1].method[methods_counter]
                            .type_of_each_par[number_of_pars], "int");
      strcpy(classes[class_counter-1].method[methods_counter]
                            .name_of_each_par[number_of_pars], yylval.string);
      break;
    case INIT_DOUBLE:
      strcpy(classes[class_counter-1].method[methods_counter]
                            .type_of_each_par[number_of_pars], "double");
      strcpy(classes[class_counter-1].method[methods_counter]
                            .name_of_each_par[number_of_pars], yylval.string);
      break;
    case INIT_CHAR:
      strcpy(classes[class_counter-1].method[methods_counter]
                            .type_of_each_par[number_of_pars], "char");
      strcpy(classes[class_counter-1].method[methods_counter]
                            .name_of_each_par[number_of_pars], yylval.string);
      break;
    case INIT_ARRAY:
      strcpy(classes[class_counter-1].method[methods_counter]
                            .type_of_each_par[number_of_pars], "arr");
      strcpy(classes[class_counter-1].method[methods_counter]
                            .name_of_each_par[number_of_pars], yylval.string);
      break;
    default:
      printf("Somethig goes wrong on saving parameters!\n");
      break;
  }
  classes[class_counter-1].method[methods_counter].number_of_pars++;
}

void save_abstract() {
  int number_of_abstract = classes[class_counter-1].number_of_abstract;
  strcpy(classes[class_counter-1].abstract_methods[number_of_abstract]
                        , yylval.string);
  classes[class_counter-1].number_of_abstract++;
}

void save_actualpars(int type) {
  switch(type) {
    case ID:
      find_type();
      strcpy(actualpars_arr[actualpars_counter], last_type);
      break;
    case DIGIT:
      strcpy(actualpars_arr[actualpars_counter], "int");
      break;
    case DOUBLE:
      strcpy(actualpars_arr[actualpars_counter], "double");
      break;
    case CHAR:
      strcpy(actualpars_arr[actualpars_counter], "char");
      break;
    default:
      printf("Something goes wrong on saving actualpars!\n");
      break;
  }
  actualpars_counter++;
}

void check_on_inherited_vars(int check_dec_or_undec) {
  int number_of_inherited_vars = classes[class_counter-1]
                      .number_of_inherited_vars;
  int result_of_search;
  result_of_search = search_var(classes[class_counter-1].name_of_inherited_vars,
                          yylval.string, number_of_inherited_vars);
  switch(check_dec_or_undec) {
    case DECLARED:
      if(result_of_search == FIND) {
        printf("Line: %d, you have an already declared variable: %s!\n"
                                      , linenum, yylval.string);
        exit(0);
      }
      break;
    case UNDECLARED:
      if(result_of_search == NOT_FIND) {
        printf("Line: %d, you have an undeclared variable: %s!\n"
                                      , linenum, yylval.string);
        exit(0);
      }else if(result_of_search == FIND) {
        check_same_type(classes[class_counter-1].name_of_inherited_vars,
                          classes[class_counter-1].type_of_inherited_vars,
                          number_of_inherited_vars);
        self = INH;
      }
      break;
    default:
      printf("Something goes wrong with"
                              "declared/undeclared inherited values!\n");
      break;
  }
}

void check_on_globals(int check_dec_or_undec) {
    int number_of_globals = return_number_of_globals();
    int result_of_search;
    result_of_search = search_var(classes[class_counter-1].name_of_each_global,
                            yylval.string, number_of_globals);
    switch(check_dec_or_undec) {
      case DECLARED:
        if(result_of_search == FIND) {
          printf("Line: %d, you have an already declared variable: %s!\n"
                                        , linenum, yylval.string);
          exit(0);
        }
        break;
      case UNDECLARED:
        if(result_of_search == NOT_FIND) {
          check_on_inherited_vars(check_dec_or_undec);
        }else if(result_of_search == FIND) {
          check_same_type(classes[class_counter-1].name_of_each_global,
                            classes[class_counter-1].type_of_each_global,
                            number_of_globals);
          self = GLOBAL;
        }
        break;
      default:
        printf("Something goes wrong with"
                                "declared/undeclared globals values!\n");
        break;
    }
}

void check_on_pars(int check_dec_or_undec) {
  int methods_counter = return_methods_counter() - 1;
  int number_of_pars = return_number_of_pars();
  int result_of_search;
  result_of_search = search_var(classes[class_counter-1]
                          .method[methods_counter].name_of_each_par,
                          yylval.string, number_of_pars);
  switch(check_dec_or_undec) {
    case DECLARED:
      if(result_of_search == FIND) {
        printf("Line: %d, you have an already declared variable: %s!\n"
                                      , linenum, yylval.string);
        exit(0);
      }
      break;
    case UNDECLARED:
      if(result_of_search == NOT_FIND) {
        check_on_globals(check_dec_or_undec);
      }else if(result_of_search == FIND) {
        check_same_type(classes[class_counter-1].method[methods_counter]
                            .name_of_each_par, classes[class_counter-1]
                            .method[methods_counter].type_of_each_par,
                            number_of_pars);
      }
      break;
    default:
      printf("Something goes wrong with"
                                "declared/undeclared parameters values!\n");
      break;
  }
}

void check_on_locals(int check_dec_or_undec) {
  if( self == 1 ) {
    self = 0;
  }
  int methods_counter = return_methods_counter() - 1;
  int number_of_vars = return_number_of_vars();
  int result_of_search;
  result_of_search = search_var(classes[class_counter-1]
                          .method[methods_counter].name_of_each_var,
                          yylval.string, number_of_vars);
  switch(check_dec_or_undec) {
    case DECLARED:
      if(result_of_search == FIND) {
        printf("Line: %d, you have an already declared variable: %s!\n"
                                      , linenum, yylval.string);
        exit(0);
      }
      break;
    case UNDECLARED:
      if(result_of_search == NOT_FIND) {
        check_on_pars(check_dec_or_undec);
      } else if(result_of_search == FIND) {
        check_same_type(classes[class_counter-1].method[methods_counter]
                            .name_of_each_var, classes[class_counter-1]
                            .method[methods_counter].type_of_each_var,
                            number_of_vars);
      }
      break;
    default:
      printf("Something goes wrong with"
                              "declared/undeclared locals values!\n");
      break;
  }
}

int search_var(char names[][NAME_LENGTH], char value[], int limit) {
  int i = 0;
  //printf("------------------------\n");
  for(i = 0; i < limit; i++) {
    if(strcmp(names[i], value) == 0) {
      return FIND;
    }
  }
  //printf("token = %s\t", value);
  //printf("Didn't find it!\n");
  return NOT_FIND;
}

void check_same_type(char names[][NAME_LENGTH], char types[][TYPE_LENGTH],
  int limit) {
  int i = 0;
  int access = 0;
  if(strcmp(last_type, "nothing") != 0) {
    for(i = 0; i < limit; i++) {
      if(strcmp(names[i], yylval.string) == 0) {
        if(strcmp(types[i], "arr") == 0 && strcmp(last_type, "int") == 0) {
          access = 1;
        }
        if(strcmp(types[i], last_type) != 0 && access == 0) {
          printf("Line: %d, different type of variable: %s", linenum,
          yylval.string);
          printf("\n");
          exit(0);
        }
      }
    }
  }
}

void check_same_class_name() {
  int i = 0;
  for(i = 0; i < class_counter; i++) {
    if(strcmp(yylval.string, classes[i].name_of_class) == 0) {
      printf("Line: %d, same class name: %s\n", linenum, yylval.string);
      exit(0);
    }
  }
}

void check_same_method_name() {
  int i = 0;
  int methods_counter = return_methods_counter();
  for(i = 0; i < methods_counter; i++) {
    if(strcmp(yylval.string, classes[class_counter-1]
              .method[i].name_of_method) == 0) {
      printf("Line: %d, same method name: %s\n", linenum, yylval.string);
      exit(0);
    }
  }
}

void find_type() {
  int methods_counter = return_methods_counter() - 1;
  int number_of_globals = return_number_of_globals();
  int number_of_pars = return_number_of_pars();
  int number_of_vars = return_number_of_vars();
  int i = 0;
  int result = search_type(classes[class_counter-1]
          .method[methods_counter].name_of_each_var, classes[class_counter-1]
          .method[methods_counter].type_of_each_var, number_of_vars);
  if(result == NOT_FIND) {
    result = search_type(classes[class_counter-1]
            .method[methods_counter].name_of_each_par, classes[class_counter-1]
            .method[methods_counter].type_of_each_par, number_of_pars);
    if(result == NOT_FIND) {
      result = search_type(classes[class_counter-1]
              .name_of_each_global, classes[class_counter-1]
              .type_of_each_global, number_of_globals);
      if(result == NOT_FIND) {
        result = search_type(classes[class_counter-1]
                .name_of_inherited_vars, classes[class_counter-1]
                .type_of_inherited_vars, classes[class_counter-1]
                .number_of_inherited_vars);
      }
    }
  }
}

int search_type(char names[][NAME_LENGTH], char types[][TYPE_LENGTH],
  int limit) {
  int methods_counter = return_methods_counter() - 1;
  int result_of_search = search_var(names, yylval.string, limit);
  int i = 0;
  if( result_of_search == FIND) {
    while(i < limit) {
    if(strcmp(names[i], yylval.string) == 0) {
          break;
        }
    i++;
    }
    strcpy(last_type, types[i]);
    return FIND;
  }
  return NOT_FIND;
}

void check_type(char names[][NAME_LENGTH], char types[][TYPE_LENGTH]
  ,int limit) {
  int methods_counter = return_methods_counter() - 1;
  int i = 0;
  while (i < limit) {
      if(strcmp(names[i], yylval.string) == 0) {
        if(strcmp(types[i], last_type) != 0) {
              printf("Line: %d, undeclared ", linenum);
              printf("object: %s\n", yylval.string);
              exit(0);
        }
      }
    i++;
  }
}

int search_local_vars() {
  int methods_counter = return_methods_counter() - 1;
  int number_of_vars = return_number_of_vars();
  return search_var(classes[class_counter-1]
          .method[methods_counter].name_of_each_var, object_call,
          number_of_vars);
}

int search_par_vars() {
  int methods_counter = return_methods_counter() - 1;
  int number_of_pars = return_number_of_pars();
  return search_var(classes[class_counter-1]
          .method[methods_counter].name_of_each_par, object_call,
          number_of_pars);
}

int search_global_vars() {
  int methods_counter = return_methods_counter() - 1;
  int number_of_globals = return_number_of_globals();
  return search_var(classes[class_counter-1]
          .name_of_each_global, object_call,
          number_of_globals);
}

int search_where_var_is() {
  int result_of_search = 0;
  result_of_search = search_local_vars();
  if(result_of_search == FIND) {
    return LOCAL;
  } else {
    result_of_search = search_par_vars();
    if(result_of_search == FIND) {
      return PAR;
    } else {
      result_of_search = search_global_vars();
      if(result_of_search == FIND) {
        return GLOBAL;
      }
    }
  }
  return 0;
}

void call_search() {
  int methods_counter = return_methods_counter() - 1;
  int number_of_globals = return_number_of_globals();
  int number_of_pars = return_number_of_pars();
  int number_of_vars = return_number_of_vars();
  int result_of_search;
  result_of_search = search_where_var_is();
  switch(result_of_search) {
    case LOCAL:
      search_type(classes[class_counter-1].method[methods_counter]
        .name_of_each_var, classes[class_counter-1].method[methods_counter]
        .type_of_each_var, number_of_vars);
      check_type(classes[class_counter-1].method[methods_counter]
        .name_of_each_var, classes[class_counter-1].method[methods_counter]
        .type_of_each_var, number_of_vars);
      break;
    case PAR:
      search_type(classes[class_counter-1].method[methods_counter]
      .name_of_each_par, classes[class_counter-1].method[methods_counter]
      .type_of_each_par, number_of_pars);
      check_type(classes[class_counter-1].method[methods_counter]
      .name_of_each_par, classes[class_counter-1].method[methods_counter]
      .type_of_each_par, number_of_pars);
      break;
    case GLOBAL:
      search_type(classes[class_counter-1].name_of_each_global
        , classes[class_counter-1].type_of_each_global, number_of_globals);
      check_type(classes[class_counter-1].name_of_each_global
        , classes[class_counter-1].type_of_each_global, number_of_globals);
      break;
    default:
      printf("Something goes wrong on call_search!\n");
      break;
  }
}

void check_class_name() {
  int i = 0;
  int result = NOT_FIND;
  for(i = 0; i < class_counter; i++) {
    if(strcmp(classes[i].name_of_class, yylval.string) == 0) {
      strcpy(object_class, classes[i].name_of_class);
      result = FIND;
      break;
    }
  }
  if(result == NOT_FIND) {
    printf("Line: %d, undeclared class: %s\n", linenum, yylval.string);
    exit(0);
  }
}

void check_abstract_existence() {
  int methods_counter = return_methods_counter();
  int number_of_abstract;
  char *abstract;
  int result = NOT_FIND;
  int i = 0, j = 0;
  for(j = 0; j < class_counter; j++) {
    if(strcmp(classes[class_counter-1].name_of_inherited_class
        , classes[j].name_of_class) == 0) {
          break;
    }
  }
  number_of_abstract = classes[j].number_of_abstract;
  for(j = 0; j < number_of_abstract; j++) {
    abstract = classes[j].abstract_methods[j];
    for(j = 0; j < methods_counter; j++) {
      if(strcmp(abstract, classes[class_counter-1]
              .method[j].name_of_method) == 0) {
                result = FIND;
                break;
    }
  }
  if(result == NOT_FIND) {
    printf("You have an abstract method: %s, that ", abstract);
    printf("doesn't explained in class: %s\n"
            , classes[class_counter-1].name_of_class);
    exit(0);
  }
  result = NOT_FIND;
  }
}

void check_interface_methods() {
  int methods_counter = return_methods_counter();
  int interface_methods_counter;
  int inherited_class;
  char *method;
  int result = 0;
  int j = 0, k = 0;
  for(j = 0; j < class_counter; j++) {
    if(strcmp(classes[class_counter-1].name_of_inherited_class
        , classes[j].name_of_class) == 0) {
          inherited_class = j;
          break;
    }
  }
  if(classes[j].interface == INTERFACE) {
    interface_methods_counter = classes[j].methods_counter;
    for(j = 0; j < interface_methods_counter; j++) {
      method = classes[inherited_class].method[j].name_of_method;
      for(k = 0; k < methods_counter; k++) {
        if(strcmp(method, classes[class_counter-1]
          .method[k].name_of_method) == 0) {
          result++;
          break;
        }
      }
    }
    if(result != interface_methods_counter) {
      printf("Interface that extended from class: %s "
            , classes[class_counter-1].name_of_class);
      printf("isn't fully explained!\n");
      exit(0);
    }
  }
  result = 0;
}

char * return_type_of_object(char names[][NAME_LENGTH]
  , char types[][NAME_LENGTH],
  int limit) {
  int i = 0;
  for(i = 0; i < limit; i++) {
    if(strcmp(names[i], object_call) == 0) {
      return types[i];
    }
  }
}

int return_index_of_class(char name[NAME_LENGTH]) {
  int i = 0;
  for(i = 0; i < class_counter; i++) {
    if(strcmp(name, classes[i].name_of_class) == 0) {
      return i;
    }
  }
}

void check_method_name() {
  int i = 0;
  int methods_counter = return_methods_counter() - 1;
  int number_of_vars = return_number_of_vars();
  int number_of_globals = return_number_of_globals();
  int result_of_search = 0;
  char *type;
  result_of_search = search_where_var_is();
  if(result_of_search == LOCAL) {
    type =  return_type_of_object(classes[class_counter-1]
      .method[methods_counter].name_of_each_var
      , classes[class_counter-1].method[methods_counter].type_of_each_var
      , number_of_vars);
  } else if(result_of_search == GLOBAL) {
      type = return_type_of_object(classes[class_counter-1]
        .name_of_each_global, classes[class_counter-1].type_of_each_global
        , number_of_globals);
  }
  if(result_of_search == LOCAL || result_of_search == GLOBAL) {
    class_to_call = return_index_of_class(type);
    methods_counter = classes[class_to_call].methods_counter;
    i = 0;
    while(i < methods_counter) {
      if(strcmp(classes[class_to_call]
        .method[i].name_of_method, yylval.string) != 0) {
        result_of_search = NOT_FIND;
      } else {
        method_to_call = i;
        result_of_search = FIND;
        break;
      }
      i++;
    }
    if(result_of_search == NOT_FIND) {
      printf("Line: %d, undeclared method: %s\n", linenum, yylval.string);
      exit(0);
    }
  } else if(result_of_search == NOT_FIND) {
    printf("Line: %d, undeclared object: %s\n", linenum, object_call);
    exit(0);
  }
}

void check_types_actualpars() {
  int i = 0;
  for(i = 0; i < actualpars_counter; i++) {
    if(actualpars_counter != classes[class_to_call]
      .method[method_to_call].number_of_pars) {
      printf("Line: %d, different number or arguments!\n", linenum);
      exit(0);
    }
    if(strcmp(actualpars_arr[i], classes[class_to_call]
          .method[method_to_call].type_of_each_par[i]) != 0) {
      printf("Line: %d, different argument type!\n", linenum);
      exit(0);
    }
  }
}

void check_same_return_type() {
  if(strcmp(classes[class_to_call]
    .method[method_to_call].return_type, "void") == 0) {
    printf("Line: %d, you can't return from void method!\n", linenum);
    exit(0);
  } else {
    if(strcmp(id_return_type_arr
      , classes[class_to_call].method[method_to_call].return_type) != 0) {
      printf("Line: %d, id and return type isn't same!\n", linenum);
      exit(0);
    }
  }
}

void clear_actualpars_arr() {
  int i = 0;
  for(i = 0; i < actualpars_counter; i++) {
    strcpy(actualpars_arr[i], "");
  }
  actualpars_counter = 0;
}

void clear_id_return_type_arr() {
  strcpy(id_return_type_arr, "");
}

void id_return_type() {
  check_on_locals(UNDECLARED);
  find_type();
  strcpy(id_return_type_arr, last_type);
  init_last_type();
}

void init_placeholder_counter() {
  placeholder_counter = 0;
}

void count_printf_vars(int type) {
  switch(type) {
    case INIT_INT:
      strcpy(_printf_[placeholder_counter], "int");
      break;
    case INIT_DOUBLE:
      strcpy(_printf_[placeholder_counter], "double");
      break;
    case INIT_CHAR:
      strcpy(_printf_[placeholder_counter], "char");
      break;
    default:
      printf("Something goes wrong in count_printf_vars!\n");
      break;
  }
  placeholder_counter++;
}

void check_placeholder() {
  if(strcmp(last_type, "arr") == 0) {
    strcpy(last_type, "int");
  }
  if(strcmp(_printf_[placeholder_counter], last_type) != 0) {
    printf("Line: %d, check your placeholders!\n", linenum);
    exit(0);
  }
  placeholder_counter++;
}

void scanf_placeholder() {
  find_type();
  if(strcmp(last_type, "int") == 0) {
    fprintf(yyout, "%s", d_placeholder);
  } else if(strcmp(last_type, "double") == 0) {
    fprintf(yyout, "%s", f_placeholder);
  } else if(strcmp(last_type, "char") == 0) {
    fprintf(yyout, "%s", c_placeholder);
  }
  init_last_type();
}

void combine_constructor_pars(int type) {
  char str[CONSTRUCTOR] =  { "" };
  char self_string[PAR_LIMIT] = { "" };
  char inh[NAME_LENGTH] = { "" };
  switch(type) {
    case ID:
      check_on_locals(UNDECLARED);
      strcpy(self_string, "self.");
      if(self == GLOBAL) {
        strcat(self_string, yylval.string);
        strcat(str, self_string);
        self = 0;
      } else if(self == INH) {
        strcpy(inh, classes[class_counter-1]
          .name_of_inherited_class);
        strcat(str, inh);
        strcat(str, self_string);
        strcat(str, yylval.string);
        self = 0;
      }else {
        strcat(str, yylval.string);
      }
      strcat(constructor_pars, str);
      break;
    case COMMA_ID:
      strcat(constructor_pars, ", ");
      strcat(constructor_pars, yylval.string);
      break;
    case DIGIT:
      sprintf(str, "%d", yylval.intval);
      strcat(constructor_pars, str);
      break;
    case COMMA_DIGIT:
      strcat(constructor_pars, ", ");
      sprintf(str, "%d", yylval.intval);
      strcat(constructor_pars, str);
      break;
    case DOUBLE:
      sprintf(str, "%f", yylval.doubleval);
      strcat(constructor_pars, str);
      break;
    case COMMA_DOUBLE:
      strcat(constructor_pars, ", ");
      sprintf(str, "%f", yylval.doubleval);
      strcat(constructor_pars, str);
      break;
    default:
      printf("Something goes wrong with combine_constructor_pars!\n");
      break;
  }
}

void choose_constructor(int type) {
  int class = 0;
  int which_constructor = 0;
  int i = 0;
  int result = NOT_FIND;
  while(i < class_counter) {
    if(strcmp(object_class, classes[i].name_of_class) == 0) {
      class = i;
      break;
    }
    i++;
  }

  i = 0;
  while(i < classes[class].methods_counter) {
    method_to_call = i;
    which_constructor = check_types_actualpars_constructor();
    if(which_constructor == 1) {
      if(type == NEW) {
        write_constructor_call(i);
      }else if(type == SUPER) {
        write_super(class, i);
      }
      result = FIND;
      break;
    }
    i++;
  }

  if(result == NOT_FIND) {
    printf("Line: %d, no constructor", linenum);
    printf(" with this number/type of arguments\n");
    exit(0);
  }
}

int check_types_actualpars_constructor() {
  int i = 0;
  int same_type_counter = 0;
  if(actualpars_counter == 0) {
    if(classes[class_to_call].method[method_to_call].number_of_pars == 0) {
      return 1;
    }
  }

  while(i < actualpars_counter) {
    if(strcmp(actualpars_arr[i], classes[class_to_call]
          .method[method_to_call].type_of_each_par[i]) == 0) {
      same_type_counter++;
    }
    if(same_type_counter == actualpars_counter) {
      return 1;
    }
    i++;
  }
  return 0;
}

void write_constructor_call(int which) {
  if(strcmp(object_class, classes[class_counter-1].name_of_class) != 0) {
    printf("Line: %d, no constructor", linenum);
    printf(" with this number/type of arguments\n");
    exit(0);
  }
  how_many_tabs();
  fprintf(yyout, "%s.%s@constructor%d", object_call, object_class, which);
  fprintf(yyout, "(");
  if(actualpars_counter != 0) {
    fprintf(yyout, "%s ,", object_call);
  } else {
    fprintf(yyout, "%s", object_call);
  }
  fprintf(yyout, "%s", constructor_pars);
  fprintf(yyout, ");\n");
}

void clear_constructor_pars() {
  strcpy(constructor_pars, "");
}

void make_custom_ob() {
  how_many_tabs();
  if(strcmp(classes[class_counter-1].name_of_inherited_class, "") != 0) {
    fprintf(yyout, "struct %s custom_object%d;\n", classes[class_counter-1]
          .name_of_inherited_class, custom_object_counter);
  } else {
    printf("Line: %d, you can't call super without extended class!\n", linenum);
    exit(0);
  }
  custom_object_counter++;
}

void write_super(int class, int method) {
  how_many_tabs();
  fprintf(yyout, "custom_object%d.%s(", custom_object_counter-1
      , classes[class].method[method].name_of_method);
  if(classes[class].method[method].number_of_pars == 0) {
    fprintf(yyout, "custom_object%d", custom_object_counter-1);
  } else {
    fprintf(yyout, "custom_object%d, ", custom_object_counter-1);
  }
  fprintf(yyout, "%s", constructor_pars);
  fprintf(yyout, ");\n");
}

void init_object_class() {
  strcpy(object_class, classes[class_counter-1].name_of_inherited_class);
}

void check_array_length() {
  if(index_array != digit_counter) {
    printf("Line: %d, different size on array!\n", linenum);
    exit(0);
  }
}

void check_return_bool() {
  int methods_counter = return_methods_counter() - 1;
  if(return_bool == 0) {
    printf("Method %s needs to return something!\n", classes[class_counter-1]
      .method[methods_counter].name_of_method);
    exit(0);
  }
}

void print_structs() {
  int i = 0, j = 0, k = 0;
  printf("-----------------------------------");
  for(i = 0; i < class_counter; i++) {
    printf("\nname of class: %s\n", classes[i].name_of_class);
    printf("\nglobals of class: \n");
    for(j = 0; j < classes[i].number_of_globals; j++) {
      printf("type = %s, name = %s\n",
        classes[i].type_of_each_global[j], classes[i].name_of_each_global[j]);
    }
    printf("\nInherited class: \n");
    printf("inherited class: %s\n", classes[i].name_of_inherited_class);
    printf("\nInherited variables: \n");
    for(j = 0; j < classes[i].number_of_inherited_vars; j++) {
      printf("type = %s, name = %s\n", classes[i].type_of_inherited_vars[j]
                                      ,classes[i].name_of_inherited_vars[j]);
    }
    printf("\nabstract methods: \n");
    for(j = 0; j < classes[i].number_of_abstract; j++) {
      printf("%s\n", classes[i].abstract_methods[j]);
    }
    printf("\nmethods of class: \n");
    for(j = 0; j < classes[i].methods_counter; j++) {
      printf("\nname of method: %s\n",
                                        classes[i].method[j].name_of_method);
      printf("\nreturn type: %s\n",
                                        classes[i].method[j].return_type);
      printf("\npars: \n");
      for(k = 0; k < classes[i].method[j].number_of_pars; k++) {
        printf("type = %s, name = %s\n",
                  classes[i].method[j].type_of_each_par[k],
                  classes[i].method[j].name_of_each_par[k]);
      }
      printf("\nlocals: \n");
      for(k = 0; k < classes[i].method[j].number_of_vars; k++) {
        printf("type = %s, name = %s\n",
                  classes[i].method[j].type_of_each_var[k],
                  classes[i].method[j].name_of_each_var[k]);
      }
    }
  }
}
