%option yylineno
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	#include "abstracttree.h"
	int number;
%}


digit					[0-9]
letter 					[a-zA-Z]
whitespaces 			[ \t]
NL 						[\n]
plus					[+]
mul						[*]
minus 					[-]
asgn 					[=]
mod 					[%]
div 					[/]
gt						[>]
lt 						[<]


%%
<<EOF>>  				{return ENDOFFILE;}
"read"  				{return READ;}
"write" 				{return WRITE;}
"if"    				{return IF;}
"then"  				{return THEN;}
"else"  				{return ELSE;}
"endif" 				{return ENDIF;}
"do"    				{return DO;}
"endwhile"  			{return ENDWHILE;}
"break"					{return BREAK;}
"while" 				{return WHILE;}
"int"   				{return INT;}
"str"   				{return STR;}
"return"				{return RETURN;}
"decl"    				{return DECL;}
"enddecl"				{return ENDDECL;}
"main"					{return MAIN;}
"type"					{return TYPE;}
"endtype"				{return ENDTYPE;}
"NULL"					{return NULLC;}
"continue"				{return CONTINUE;}
"begin"					{return BEG;}
"end"					{return END;}
{gt}    				{
							//change the type to boolean type - typetable pointer
							yylval.nptr = TreeCreate(TYPE_BOOLEAN,NODETYPE_GT,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return RELOP;
						}
{lt}    				{
							//change the type to boolean type - typetable pointer
							yylval.nptr = TreeCreate(TYPE_BOOLEAN,NODETYPE_LT,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return RELOP;
						}
">="					{
							//change the type to boolean type - typetable pointer
							yylval.nptr = TreeCreate(TYPE_BOOLEAN,NODETYPE_GE,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return RELOP;
						}
"<="					{
							//change the type to boolean type - typetable pointer
							yylval.nptr = TreeCreate(TYPE_BOOLEAN,NODETYPE_LE,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return RELOP;
						}
"!="					{
							//change the type to boolean type - typetable pointer
							yylval.nptr = TreeCreate(TYPE_BOOLEAN,NODETYPE_NE,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return RELOP;
						}
"=="   					{
							//change the type to boolean type - typetable pointer
							yylval.nptr = TreeCreate(TYPE_BOOLEAN,NODETYPE_EQ,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return RELOP;
						}
[()]    				{return *yytext;}
"{"						{return *yytext;}
"}"						{return *yytext;}
"["    					{return *yytext;}
"]"    					{return *yytext;}
{div}					{
							//change the type to boolean type - typetable pointer
							yylval.nptr = TreeCreate(TYPE_INT,NODETYPE_DIV,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return AROP2;
						}
[;]   					{return DELIM;}
{mul}   				{
							//change the type to boolean type - typetable pointer
							yylval.nptr = TreeCreate(TYPE_INT,NODETYPE_MUL,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return AROP2;
						}
"="    	 				{return ASGN;}
{plus}  				{
							//change the type to boolean type - typetable pointer
							yylval.nptr = TreeCreate(TYPE_INT,NODETYPE_PLUS,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return AROP1;
						}
{minus}					{
							//change the type to boolean type - typetable pointer
							yylval.nptr = TreeCreate(TYPE_INT,NODETYPE_MINUS,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return AROP1;
						}
{mod}					{
							//change the type to boolean type - typetable pointer
							yylval.nptr = TreeCreate(TYPE_INT,NODETYPE_MOD,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return AROP2;
						}
"AND"					{
							//change the type to boolean type - typetable pointer
							yylval.nptr = TreeCreate(TYPE_BOOLEAN,NODETYPE_AND,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return LOGOP;
						}
"NOT"					{return NOT;}
"OR"					{
							//change the type to boolean type - typetable pointer
							yylval.nptr = TreeCreate(TYPE_BOOLEAN,NODETYPE_OR,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return LOGOP;
						}
"."						{return DOT;}
{digit}+				{
							number=atoi(yytext);
							yylval.nptr = TreeCreate(TYPE_INT,NODETYPE_LEAF,number,NULL,NULL,NULL,NULL,NULL);
							return NUM;
						}
[a-zA-Z][a-zA-Z0-9]* 	{
							yylval.nptr = TreeCreate(TYPE_VOID,NODETYPE_ID,0,yytext,NULL,NULL,NULL,NULL);
							return ID;
						}
\"(\\.|[^\\"])*\"		{
							//handle string constant
							yylval.nptr = TreeCreate(TYPE_STR,NODETYPE_LEAF,yytext,NULL,NULL,NULL,NULL,NULL);
							return STRCONST;
						}
{NL}    				;
{whitespaces} 			;
.   		 			{printf("INVALID CHARACTER");exit(0);}
%%

int yywrap(){
	return 1;
}
yyerror(char const *s)
{
	printf("yyerror - line %d : character %s",yylineno,s);
}
