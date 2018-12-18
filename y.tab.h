/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 152 "y.y" /* yacc.c:1909  */

    int intval;
    char string[100];
    double doubleval;

#line 134 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
