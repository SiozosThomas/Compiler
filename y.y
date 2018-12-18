%{
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
%}

%union {
    int intval;
    char string[100];
    double doubleval;
};

%token CLASSTK EXTENDSTK IFTK WHILETK FORTK RETURNTK SWITCHTK CASETK ELSETK
%token ELIFTK INTTK DOUBLETK CHARTK PRINTTK INPUTTK VOIDTK BREAKTK ANDTK ORTK
%token APOSTROPHETK IDTK DIGITTK EOFTK SEMICOLONTK COLONTK COMMATK
%token QUESTIONMARKTK LEFTPARTK RIGHTPARTK LEFTBRACETK RIGHTBRACETK
%token LESSTK GREATERTK LESSEQUALTK GREATEREQUALTK EQUALTK DOUBLEEQUALTK
%token NOTEQUALTK PLUSTK MINUSTK MULTK DIVIDETK DOUBLEPLUSTK DOUBLEMINUSTK
%token SINGLECOMMENTTK OPENBLOCKCOMTK CLOSEBLOCKCOMTK LEFTBRACKETTK
%token RIGHTBRACKETTK CARETTK PERCENTTK PUBLICTK ENDPUBLICTK TRUETK PERCENTFTK
%token OBJECTTK DOTTK CHARACTERTK NOTTK FALSETK DEFAULTTK PERCENTDTK PERCENTCTK
%token NOTEQUALCONTK DOUBLEVALUETK ABSTRACTTK INTERFACETK CALLTK MAINTK
%token CUSTOMOBJECTTK SUPERTK

%type<string> IDTK
%type<intval> DIGITTK
%type<doubleval> DOUBLEVALUETK

%%
program: class_type main

main: MAINTK LEFTPARTK RIGHTPARTK { write_main(); }
      LEFTBRACETK { write_braces(OPEN_BRACE); } method_block RIGHTBRACETK
      { write_return_0(); write_braces(CLOSE_BRACE); }

class_type:    %empty
 | class_type class { check_abstract_existence(); check_interface_methods(); }
 | class_type interface

class: CLASSTK id_init { check_same_class_name();
            write_keywords(STRUCT_WORD); init_type_of_class(CLASS); }
            LEFTBRACETK { write_braces(OPEN_BRACE); init_globals_counter(); }
            block RIGHTBRACETK
 | CLASSTK id_init { check_same_class_name();
            write_keywords(STRUCT_WORD); init_type_of_class(CLASS); }
            EXTENDSTK id_init { check_class_name();
            insert_inherited_class(); init_inherited_vars_counter();
            insert_inherited_vars(); } LEFTBRACETK
            { write_braces(OPEN_BRACE); init_globals_counter(); }
            block RIGHTBRACETK

interface: INTERFACETK id_init { check_same_class_name(); insert_class_names();
            init_type_of_class(INTERFACE); } LEFTBRACETK interface_block
            RIGHTBRACETK

block: declarations { fprintf(yyout, "};\n"); tabs--;
              init_methods_counter(); init_locals_counter(); }
              constructors methods

interface_block:     %empty
 | interface_block id_init { write_methods(INTERFACE); }
    LEFTPARTK RIGHTPARTK SEMICOLONTK

declarations:   %empty
 | PUBLICTK values_list ENDPUBLICTK

values_list:    %empty
 | values_list int_values
 | values_list double_values
 | values_list char_values
 | values_list object_values

int_values: INTTK array_or_not

array_or_not: id_init init_int_rule
 | LEFTBRACKETTK digit_init { index_array = yylval.intval; } RIGHTBRACKETTK
      id_init { init_values(INIT_ARRAY); check_on_globals(DECLARED);
      save_global_var(INIT_ARRAY); write_brackets(OPEN_BRACKET);
      write_index_array(); write_brackets(CLOSE_BRACKET); } init_array_rule

init_array_rule: SEMICOLONTK { write_semicolon(); }
 | EQUALTK LEFTBRACETK { fprintf(yyout, " = {"); } many_digits
    RIGHTBRACETK { fprintf(yyout, "}"); } SEMICOLONTK
    { write_semicolon(); check_array_length(); digit_counter = 0;}

many_digits: DIGITTK { fprintf(yyout, "%d", yylval.intval); digit_counter++; }
 | many_digits COMMATK DIGITTK { write_symbols(COMMA);
      fprintf(yyout, "%d", yylval.intval); digit_counter++; }

init_int_rule:  %empty
 | SEMICOLONTK { init_values(INIT_INT);
       check_on_globals(DECLARED); save_global_var(INIT_INT); }
 | EQUALTK { init_values(INIT_INT_EXPR); check_on_globals(DECLARED);
   save_global_var(INIT_INT); } expression SEMICOLONTK { write_semicolon(); }

double_values: DOUBLETK id_init
        SEMICOLONTK { init_values(INIT_DOUBLE); check_on_globals(DECLARED);
          save_global_var(INIT_DOUBLE);}
 | DOUBLETK id_init
        EQUALTK { init_values(INIT_DOUBLE_EXPR); check_on_globals(DECLARED);
          save_global_var(INIT_DOUBLE); }
        expression SEMICOLONTK { write_semicolon(); }

char_values: CHARTK id_init
            SEMICOLONTK { init_values(INIT_CHAR); check_on_globals(DECLARED);
            save_global_var(INIT_CHAR); }
 | CHARTK id_init EQUALTK { init_values(INIT_CHAR_EXPR);
            check_on_globals(DECLARED); save_global_var(INIT_CHAR); }
            character_rule SEMICOLONTK { write_semicolon(); }

object_values: OBJECTTK id_init { check_class_name(); } id_init SEMICOLONTK
            { init_values(INIT_OBJECT); check_on_globals(DECLARED);
            save_global_var(INIT_OBJECT); }

constructors:   %empty
 |  constructors id_init { write_methods(CONSTRUCTOR); }
        LEFTPARTK { write_parenthesis(OPEN_PAR); write_par_values(INIT_OBJECT); }
        parlist RIGHTPARTK { write_parenthesis(CLOSE_PAR);
        write_braces(OPEN_BRACE); } LEFTBRACETK constructor_block RIGHTBRACETK
        { write_braces(CLOSE_BRACE); }

methods:    %empty
 | methods VOIDTK id_init { check_same_method_name();
    write_methods(VOID_METHOD); }
    LEFTPARTK { write_parenthesis(OPEN_PAR); write_par_values(INIT_OBJECT); }
    parlist RIGHTPARTK { write_parenthesis(CLOSE_PAR); }
    LEFTBRACETK { write_braces(OPEN_BRACE); }  method_block
    RIGHTBRACETK { write_braces(CLOSE_BRACE); }
 | methods INTTK id_init { check_same_method_name(); write_methods(INT_METHOD); }
    LEFTPARTK { write_parenthesis(OPEN_PAR); write_par_values(INIT_OBJECT); }
    parlist RIGHTPARTK { write_parenthesis(CLOSE_PAR); }
    LEFTBRACETK { write_braces(OPEN_BRACE); } method_block
    RIGHTBRACETK { write_braces(CLOSE_BRACE); check_return_bool(); }
 | methods DOUBLETK id_init { check_same_method_name();
    write_methods(DOUBLE_METHOD); }
    LEFTPARTK { write_parenthesis(OPEN_PAR); write_par_values(INIT_OBJECT); }
    parlist RIGHTPARTK { write_parenthesis(CLOSE_PAR); }
    LEFTBRACETK { write_braces(OPEN_BRACE); } method_block
    RIGHTBRACETK { write_braces(CLOSE_BRACE); check_return_bool(); }
 | methods CHARTK id_init { check_same_method_name();
    write_methods(CHAR_METHOD); }
    LEFTPARTK { write_parenthesis(OPEN_PAR); write_par_values(INIT_OBJECT); }
    parlist RIGHTPARTK { write_parenthesis(CLOSE_PAR); }
    LEFTBRACETK { write_braces(OPEN_BRACE); } method_block
    RIGHTBRACETK { write_braces(CLOSE_BRACE); check_return_bool(); }
 | methods ABSTRACTTK id_init { check_same_method_name(); save_abstract(); }
        LEFTPARTK RIGHTPARTK SEMICOLONTK

parlist:    %empty
 | parlist_types
 | parlist COMMATK parlist_types

parlist_types: %empty
 | INTTK par_int
 | DOUBLETK id_init { write_par_values(INIT_DOUBLE); save_pars(INIT_DOUBLE); }
 | CHARTK id_init { write_par_values(INIT_CHAR); save_pars(INIT_CHAR); }

par_int: %empty
 | id_init { write_par_values(INIT_INT); save_pars(INIT_INT); }
 | LEFTBRACKETTK digit_init { index_array = yylval.intval; } RIGHTBRACKETTK
    id_init { write_par_values(INIT_ARRAY); save_pars(INIT_ARRAY);
      write_brackets(OPEN_BRACKET); write_index_array();
      write_brackets(CLOSE_BRACKET); }

constructor_block: method_block

method_block:    %empty
 | method_block assignment
 | method_block ifstat
 | method_block whilestat
 | method_block forstat
 | method_block returnstat
 | method_block switchstat
 | method_block printstat
 | method_block inputstat
 | method_block callstat
 | method_block super

assignment: INTTK local_array_or_not
 | id_init EQUALTK { init_values(EXPRESSION); find_type();
        check_on_locals(UNDECLARED); }
        expression SEMICOLONTK { write_semicolon(); }
 | DOUBLETK id_init
  EQUALTK { init_values(INIT_DOUBLE_EXPR); check_on_locals(DECLARED);
      save_local_vars(INIT_DOUBLE_EXPR); }
      expression SEMICOLONTK { write_semicolon(); }
 | DOUBLETK id_init
    SEMICOLONTK { init_values(INIT_DOUBLE); check_on_locals(DECLARED);
    save_local_vars(INIT_DOUBLE_EXPR); }
 | CHARTK id_init
        EQUALTK { init_values(INIT_CHAR_EXPR); check_on_locals(DECLARED);
        save_local_vars(INIT_CHAR_EXPR); }
        expression SEMICOLONTK { write_semicolon(); }
 | CHARTK id_init
        SEMICOLONTK { init_values(INIT_CHAR); check_on_locals(DECLARED);
        save_local_vars(INIT_CHAR_EXPR); }
 | OBJECTTK id_init { check_class_name(); } id_init { init_object_call(); }
        init_object { clear_constructor_pars(); }

local_array_or_not: id_init local_int
 | LEFTBRACKETTK digit_init { index_array = yylval.intval; } RIGHTBRACKETTK
      id_init { init_values(INIT_ARRAY); check_on_locals(DECLARED);
      save_local_vars(INIT_ARRAY); write_brackets(OPEN_BRACKET);
      write_index_array(); write_brackets(CLOSE_BRACKET); }
      init_array_rule

local_int: EQUALTK { init_values(INIT_INT_EXPR); check_on_locals(DECLARED);
            save_local_vars(INIT_INT_EXPR); }
            expression SEMICOLONTK { write_semicolon(); }
 | SEMICOLONTK { init_values(INIT_INT); check_on_locals(DECLARED);
   save_local_vars(INIT_INT_EXPR); }

init_object: EQUALTK
        { init_values(INIT_OBJECT); check_on_locals(DECLARED);
        save_local_vars(INIT_OBJECT_EXPR); } id_init { check_method_name(); }
        LEFTPARTK actualpars_constructor RIGHTPARTK SEMICOLONTK
        { choose_constructor(NEW); clear_actualpars_arr(); init_last_type(); }
 | SEMICOLONTK { init_values(INIT_OBJECT); check_on_locals(DECLARED);
        save_local_vars(INIT_OBJECT_EXPR); init_last_type(); }

actualpars_constructor:    %empty
 | id_init { save_actualpars(ID); combine_constructor_pars(ID); }
 | character_rule_init { save_actualpars(CHAR); combine_constructor_pars(ID); }
 | digit_init { save_actualpars(DIGIT); combine_constructor_pars(DIGIT); }
 | double_rule_init { save_actualpars(DOUBLE);
      combine_constructor_pars(DOUBLE); }
 | actualpars_constructor COMMATK id_init { save_actualpars(ID);
      combine_constructor_pars(COMMA_ID); }
 | actualpars_constructor COMMATK digit_init { save_actualpars(DIGIT);
      combine_constructor_pars(COMMA_DIGIT); }
 | actualpars_constructor COMMATK character_rule_init { save_actualpars(CHAR);
      combine_constructor_pars(COMMA_ID); }
 | actualpars_constructor COMMATK double_rule_init { save_actualpars(DOUBLE);
      combine_constructor_pars(COMMA_DOUBLE); }

ifstat: IFTK LEFTPARTK { write_keywords(IF_WORD); } condition
    RIGHTPARTK { write_parenthesis(CLOSE_PAR); }
    LEFTBRACETK { write_braces(OPEN_BRACE); } method_block RIGHTBRACETK
                        { write_braces(CLOSE_BRACE); }
 | ifstat ELIFTK LEFTPARTK { write_keywords(ELIF_WORD); } condition
    RIGHTPARTK { write_parenthesis(CLOSE_PAR); }
    LEFTBRACETK { write_braces(OPEN_BRACE); } method_block RIGHTBRACETK
                        { write_braces(CLOSE_BRACE); }
 | ifstat ELSETK LEFTBRACETK { write_keywords(ELSE_WORD); }
    method_block RIGHTBRACETK { write_braces(CLOSE_BRACE); }

whilestat: WHILETK LEFTPARTK { write_keywords(WHILE_WORD); }
    condition RIGHTPARTK { write_parenthesis(CLOSE_PAR); }
    LEFTBRACETK { write_braces(OPEN_BRACE); } method_block
    RIGHTBRACETK { write_braces(CLOSE_BRACE); }

forstat: FORTK LEFTPARTK { write_keywords(FOR_WORD); } int_values_for
    id relationaloper number_or_id SEMICOLONTK { write_for_semicolon(); }
    forstep RIGHTPARTK { write_parenthesis(CLOSE_PAR); }
    LEFTBRACETK { write_braces(OPEN_BRACE); } method_block
    RIGHTBRACETK { write_braces(CLOSE_BRACE); }

int_values_for: INTTK id_init EQUALTK { check_on_locals(DECLARED);
        init_for_values(INIT_INT_EXPR);
        save_local_vars(INIT_INT_EXPR); }
        expression SEMICOLONTK { write_for_semicolon(); }
 | id_init EQUALTK { init_for_values(EXPRESSION); check_on_locals(UNDECLARED); }
        expression SEMICOLONTK { write_for_semicolon(); }

number_or_id: id
 | digit

forstep: id EQUALTK expression
 | id DOUBLEPLUSTK { fprintf(yyout, "++"); }
 | id DOUBLEMINUSTK { fprintf(yyout, "--"); }

returnstat: RETURNTK { write_keywords(RETURN_WORD); } expression SEMICOLONTK
            { write_semicolon(); return_bool = 1; }

switchstat: SWITCHTK LEFTPARTK { write_keywords(SWITCH_WORD); } id
        RIGHTPARTK { write_parenthesis(CLOSE_PAR); }
        LEFTBRACETK { write_braces(OPEN_BRACE); } caserule
        RIGHTBRACETK { write_braces(CLOSE_BRACE); }

caserule:   %empty
 | caserule CASETK id_char_digit { write_keywords(CASE_WORD); } COLONTK
        method_block BREAKTK SEMICOLONTK { write_keywords(BREAK_WORD); }
 | caserule DEFAULTTK COLONTK { write_keywords(DEFAULT_WORD); }
        BREAKTK SEMICOLONTK { write_keywords(BREAK_WORD); }
 | caserule DEFAULTTK COLONTK { write_keywords(DEFAULT_WORD); } method_block
        BREAKTK SEMICOLONTK { write_keywords(BREAK_WORD); }

id_char_digit: id_init { case_type = CASE_ID; }
 | digit_init { case_type = CASE_DIGIT; }
 | character_rule_init { case_type = CASE_CHAR; }

printstat: PRINTTK LEFTPARTK { write_keywords(PRINT_WORD);
        init_placeholder_counter(); } inside_print
        RIGHTPARTK SEMICOLONTK { write_parenthesis(CLOSE_PAR_AND_SEMICOLON); }

inside_print: %empty
 | APOSTROPHETK { write_symbols(APOSTROPHE);
    init_placeholder_counter(); } inside_apostrophe
    APOSTROPHETK { write_symbols(APOSTROPHE); init_placeholder_counter(); }
 | inside_print COMMATK { write_symbols(COMMA); } after_comma

after_comma: APOSTROPHETK { write_symbols(APOSTROPHE);
   init_placeholder_counter(); } inside_apostrophe
   APOSTROPHETK { write_symbols(APOSTROPHE); init_placeholder_counter(); }
 | outside_apostrophe

inside_apostrophe: %empty
 | inside_apostrophe operations
 | inside_apostrophe relationaloper
 | inside_apostrophe id_print
 | inside_apostrophe PERCENTDTK { fprintf(yyout, " %s", d_placeholder);
        count_printf_vars(INIT_INT); }
 | inside_apostrophe PERCENTCTK { fprintf(yyout, " %s", c_placeholder);
        count_printf_vars(INIT_CHAR); }
 | inside_apostrophe PERCENTFTK { fprintf(yyout, " %s", f_placeholder);
        count_printf_vars(INIT_DOUBLE); }

outside_apostrophe: id { find_type(); check_placeholder(); init_last_type(); }
 | digit { strcpy(last_type, "int"); check_placeholder(); init_last_type(); }
 | double_rule { strcpy(last_type, "double"); check_placeholder();
                  init_last_type(); }
 | character_rule { strcpy(last_type, "char"); check_placeholder();
                  init_last_type(); }

id_print: IDTK { fprintf(yyout, " %s", yylval.string); }
 | DIGITTK { fprintf(yyout, "%d", yylval.intval); }
 | DOUBLEVALUETK { fprintf(yyout, " %f", yylval.doubleval); }
 | CHARACTERTK { fprintf(yyout, " %s", yylval.string); }

inputstat: INPUTTK LEFTPARTK id_init { init_placeholder_counter();
  write_keywords(INPUT_WORD); }
  RIGHTPARTK SEMICOLONTK { write_parenthesis(CLOSE_PAR_AND_SEMICOLON); }

callstat: CALLTK id_init callcase

callcase: DOTTK { init_object_call(); call_search(); find_type();
        init_last_type(); } id_init { write_keywords(CALL_WORD);
        check_method_name(); } LEFTPARTK { write_parenthesis(OPEN_PAR);
        write_object_on_pars(); } actualpars RIGHTPARTK
        { check_types_actualpars(); } SEMICOLONTK
        { write_parenthesis(CLOSE_PAR_AND_SEMICOLON); clear_actualpars_arr(); }
 | EQUALTK { id_return_type(); write_call_return(); } id_init
        { init_object_call(); call_search(); find_type(); init_last_type(); }
        DOTTK id_init { write_keywords(CALL_WORD); check_method_name();
        check_same_return_type(); } LEFTPARTK { write_parenthesis(OPEN_PAR);
        write_object_on_pars(); } actualpars RIGHTPARTK
        { check_types_actualpars(); } SEMICOLONTK
        { write_parenthesis(CLOSE_PAR_AND_SEMICOLON); clear_actualpars_arr();
        clear_id_return_type_arr(); }

actualpars:    %empty
 | id { save_actualpars(ID); }
 | character_rule { save_actualpars(CHAR); }
 | digit { save_actualpars(DIGIT); }
 | double_rule { save_actualpars(DOUBLE); }
 | actualpars COMMATK { write_symbols(COMMA); } id { save_actualpars(ID); }
 | actualpars COMMATK { write_symbols(COMMA); } digit { save_actualpars(DIGIT);}
 | actualpars COMMATK character_rule { save_actualpars(CHAR); }
 | actualpars COMMATK { write_symbols(COMMA); } double_rule
                          { save_actualpars(DOUBLE); }

super: SUPERTK { make_custom_ob(); init_object_class(); } LEFTPARTK
          actualpars_constructor
          RIGHTPARTK { choose_constructor(SUPER); clear_actualpars_arr();
          init_last_type();} SEMICOLONTK

condition: boolterm
 | condition ORTK { write_symbols(OR); } boolterm

boolterm: boolfactor
 | boolterm ANDTK { write_symbols(AND); } boolfactor

boolfactor:    %empty
 | boolfactor NOTTK { write_symbols(NOT); } condition
 | boolfactor NOTEQUALCONTK LEFTPARTK { write_symbols(NOTEQUAL); }
        condition RIGHTPARTK { write_parenthesis(CLOSE_PAR); }
 | boolfactor expression relationaloper expression
 | boolfactor condition
 | TRUETK
 | FALSETK

expression:    %empty
 | digit operations digit
 | double_rule operations double_rule
 | character_rule
 | array_expr operations array_expr
 | array_expr operations digit
 | array_expr operations
 | id operations id
 | id operations digit
 | id operations double_rule
 | double_rule operations id
 | digit operations id
 | LEFTPARTK { fprintf(yyout, "%s", yylval.string); }
        expression RIGHTPARTK { fprintf(yyout, "%s", yylval.string); }
 | operations LEFTPARTK expression RIGHTPARTK
 | digit operations
 | id operations    /* error int a ++ ; */
 | expression operations digit
 | expression operations array_expr
 | expression operations id
 | double_rule
 | operations

array_expr: id LEFTBRACKETTK { write_brackets(OPEN_BRACKET); } digit
              RIGHTBRACKETTK { write_brackets(CLOSE_BRACKET); }

operations:    %empty
 | PLUSTK   { fprintf(yyout, " %s ", yylval.string); }
 | MINUSTK  { fprintf(yyout, " %s ", yylval.string); }
 | MULTK    { fprintf(yyout, " %s ", yylval.string); }
 | DIVIDETK { fprintf(yyout, " %s ", yylval.string); }
 | CARETTK  { fprintf(yyout, " %s ", yylval.string); }
 | DOUBLEPLUSTK { fprintf(yyout, "%s", yylval.string); }
 | DOUBLEMINUSTK    { fprintf(yyout, "%s", yylval.string); }

relationaloper:    %empty
 | DOUBLEEQUALTK    { fprintf(yyout, " %s ", yylval.string); }
 | LESSTK   { fprintf(yyout, " %s ", yylval.string); }
 | GREATERTK    { fprintf(yyout, " %s ", yylval.string); }
 | LESSEQUALTK  { fprintf(yyout, " %s ", yylval.string); }
 | GREATEREQUALTK   { fprintf(yyout, " %s ", yylval.string); }
 | NOTEQUALTK   { fprintf(yyout, " %s ", yylval.string); }

id: IDTK { check_on_locals(UNDECLARED); write_id(); }

id_init: IDTK

digit_init: DIGITTK

double_rule_init: DOUBLEVALUETK

character_rule_init: CHARACTERTK

digit: DIGITTK { fprintf(yyout, " %d", yylval.intval); }

double_rule: DOUBLEVALUETK { fprintf(yyout, " %f", yylval.doubleval); }

character_rule: CHARACTERTK { fprintf(yyout, " %s", yylval.string); }

%%

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
