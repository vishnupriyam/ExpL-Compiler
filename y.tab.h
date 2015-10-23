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
#line 15 "yacc_expl.y" /* yacc.c:1909  */

    AST * nptr;
    ArgStruct * arg;
    GSymbol * gvar;
    LSymbol * lvar;
    fieldList * field;
    TypeTable * ty;
    char c;

#line 140 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
