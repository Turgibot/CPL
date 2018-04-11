/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_CPM_TAB_H_INCLUDED
# define YY_YY_CPM_TAB_H_INCLUDED
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
    num = 258,
    addop = 259,
    mulop = 260,
    orop = 261,
    andop = 262,
    assignop = 263,
    relop = 264,
    toop = 265,
    sentence = 266,
    id = 267,
    CASE = 268,
    CONST = 269,
    DEFAULT = 270,
    READ = 271,
    ELSE = 272,
    FOR = 273,
    IF = 274,
    STEPOP = 275,
    INT = 276,
    PROGRAM = 277,
    LOOP = 278,
    PRINT = 279,
    _BEGIN = 280,
    STRING = 281,
    FLOAT = 282,
    SWITCH = 283,
    END = 284,
    VAR = 285,
    WHILE = 286,
    WHEN = 287,
    BREAK = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "cpm.y" /* yacc.c:1909  */


	struct parserTree{
		char *code;
		int type;
		char *head;
		char* label;
	}Ptree;

	struct declTree{
		char *code;
		int type;
		int count;
		char *label;
	}Dtree;

	struct number{
		int type;
		union {
			int ival;
			float fval;
		}val;
	}num;

	char sign1;
	char sign2 [3];
	char sign3 [4];
	char *strVal;

#line 118 "cpm.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CPM_TAB_H_INCLUDED  */
