digit               [0-9]
letter              [a-zA-Z]

%{
#include "y.tab.h"
int linenum = 1;
%}

%%

"class"             { return CLASSTK; }
"extends"           { return EXTENDSTK; }
"if"                { return IFTK; }
"while"             { return WHILETK; }
"for"               { return FORTK; }
"return"            { return RETURNTK; }
"switch"            { return SWITCHTK; }
"case"              { return CASETK; }
"else"              { return ELSETK; }
"elif"              { return ELIFTK; }
"int"               { return INTTK; }
"double"            { return DOUBLETK; }
"char"              { return CHARTK; }
"print"             { return PRINTTK; }
"input"             { return INPUTTK; }
"void"              { return VOIDTK; }
"public"            { return PUBLICTK; }
"endpublic"         { return ENDPUBLICTK; }
"object"            { return OBJECTTK; }
"not"               { return NOTTK; }
"true"              { return TRUETK; }
"false"             { return FALSETK; }
"abstract"          { return ABSTRACTTK; }
"interface"         { return INTERFACETK; }
"default"           { return DEFAULTTK; }
"call"              { return CALLTK; }
"main"              { return MAINTK; }
"super"             { return SUPERTK; }
"custom_object"+{digit}*     { return CUSTOMOBJECTTK; }
";"                 { return SEMICOLONTK; }
":"                 { strcpy(yylval.string, yytext); return COLONTK; }
","                 { strcpy(yylval.string, yytext); return COMMATK; }
"?"                 { strcpy(yylval.string, yytext); return QUESTIONMARKTK; }
"("                 { strcpy(yylval.string, yytext); return LEFTPARTK; }
")"                 { strcpy(yylval.string, yytext); return RIGHTPARTK; }
"{"                 { return LEFTBRACETK; }
"}"                 { return RIGHTBRACETK; }
"<"                 { strcpy(yylval.string, yytext); return LESSTK; }
">"                 { strcpy(yylval.string, yytext); return GREATERTK; }
"<="                { strcpy(yylval.string, yytext); return LESSEQUALTK; }
">="                { strcpy(yylval.string, yytext); return GREATEREQUALTK; }
"="                 { return EQUALTK; }
"=="                { strcpy(yylval.string, yytext); return DOUBLEEQUALTK; }
"!="                { strcpy(yylval.string, yytext); return NOTEQUALTK; }
"!"                 { strcpy(yylval.string, yytext); return NOTEQUALCONTK; }
"+"                 { strcpy(yylval.string, yytext); return PLUSTK; }
"-"                 { strcpy(yylval.string, yytext); return MINUSTK; }
"*"                 { strcpy(yylval.string, yytext); return MULTK; }
"/"                 { strcpy(yylval.string, yytext); return DIVIDETK; }
"++"                { strcpy(yylval.string, yytext); return DOUBLEPLUSTK; }
"--"                { strcpy(yylval.string, yytext); return DOUBLEMINUSTK; }
"//"                { return SINGLECOMMENTTK; }
"/*"                { return OPENBLOCKCOMTK; }
"*/"                { return CLOSEBLOCKCOMTK; }
"break"             { return BREAKTK ; }
"&&"                { return ANDTK ; }
"||"                { return ORTK ; }
"["                 { return LEFTBRACKETTK; }
"]"                 { return RIGHTBRACKETTK; }
"^"                 { strcpy(yylval.string, yytext); return CARETTK; }
"%"                 { strcpy(yylval.string, yytext); return PERCENTTK; }
"'"                 { return APOSTROPHETK ; }
"."                 { return DOTTK; }
"%d"                { return PERCENTDTK; }
"%c"                { return PERCENTCTK; }
"%f"                { return PERCENTFTK; }
\n                  { ++linenum; }
\t                  { /* ignore whitespase */ }
{letter}({letter}|{digit})*   { strcpy(yylval.string, yytext); return IDTK; }
"'"+{letter}+"'"              { strcpy(yylval.string, yytext); return CHARACTERTK; }
{digit}{digit}*               { yylval.intval = atoi(yytext); return DIGITTK; }
{digit}+"."{digit}*           { yylval.doubleval = atof(yytext); return DOUBLEVALUETK; }
<<EOF>>             { yyterminate(); }
.                   { /* ignore */ }
%%
