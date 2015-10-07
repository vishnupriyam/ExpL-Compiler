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
							
							yylval.nptr = TreeCreate(TLookUp("boolean"),NODETYPE_GT,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return RELOP;
						}
{lt}    				{
							
							yylval.nptr = TreeCreate(TLookUp("boolean"),NODETYPE_LT,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return RELOP;
						}
">="					{
							
							yylval.nptr = TreeCreate(TLookUp("boolean"),NODETYPE_GE,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return RELOP;
						}
"<="					{
							
							yylval.nptr = TreeCreate(TLookUp("boolean"),NODETYPE_LE,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return RELOP;
						}
"!="					{
							
							yylval.nptr = TreeCreate(TLookUp("boolean"),NODETYPE_NE,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return RELOP;
						}
"=="   					{
							
							yylval.nptr = TreeCreate(TLookUp("boolean"),NODETYPE_EQ,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return RELOP;
						}
[()]    				{return *yytext;}
"{"						{return *yytext;}
"}"						{return *yytext;}
"["    					{return *yytext;}
"]"    					{return *yytext;}
{div}					{
							
							yylval.nptr = TreeCreate(TLookUp("int"),NODETYPE_DIV,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return AROP2;
						}
[;]   					{return DELIM;}
{mul}   				{
							
							yylval.nptr = TreeCreate(TLookUp("int"),NODETYPE_MUL,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return AROP2;
						}
"="    	 				{return ASGN;}
{plus}  				{
							
							yylval.nptr = TreeCreate(TLookUp("int"),NODETYPE_PLUS,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return AROP1;
						}
{minus}					{
							
							yylval.nptr = TreeCreate(TLookUp("int"),NODETYPE_MINUS,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return AROP1;
						}
{mod}					{
							
							yylval.nptr = TreeCreate(TLookUp("int"),NODETYPE_MOD,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return AROP2;
						}
"AND"					{
							
							yylval.nptr = TreeCreate(TLookUp("boolean"),NODETYPE_AND,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return LOGOP;
						}
"NOT"					{return NOT;}
"OR"					{
							
							yylval.nptr = TreeCreate(TLookUp("boolean"),NODETYPE_OR,NULL,NULL,NULL,NULL,NULL,NULL);
						 	return LOGOP;
						}
"."						{return DOT;}
{digit}+				{
							number=atoi(yytext);
							yylval.nptr = TreeCreate(TLookUp("int"),NODETYPE_LEAF,number,NULL,NULL,NULL,NULL,NULL);
							return NUM;
						}
[a-zA-Z][a-zA-Z0-9]* 	{
							yylval.nptr = TreeCreate(TLookUp("void"),NODETYPE_ID,0,yytext,NULL,NULL,NULL,NULL);
							return ID;
						}
\"(\\.|[^\\"])*\"		{
							
							yylval.nptr = TreeCreate(TLookUp("str"),NODETYPE_LEAF,yytext,NULL,NULL,NULL,NULL,NULL);
							return STRCONST;
						}
{NL}    				;
{whitespaces} 			;
.   		 			{printf("INVALID CHARACTER");exit(1);}
%%

int yywrap(){
	return 1;
}
yyerror(char const *s)
{
	printf("yyerror - line %d : character %s",yylineno,s);
}
