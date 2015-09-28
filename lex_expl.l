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
"begin"					{return BEGINC;}
"end"					{return END;}
{gt}    				{return GT;}
{lt}    				{return LT;}
">="					{return GE;}
"<="					{return LE;}
"!="					{return NE;}
"=="   					{return EQ;}
[()]    				{return *yytext;}
"{"						{return *yytext;}
"}"						{return *yytext;}
"["    					{return *yytext;}
"]"    					{return *yytext;}
{div}					{return DIV;}
[;]   					{return DELIM;}
{mul}   				{return MUL;}
"="    	 				{return ASGN;}
{plus}  				{return PLUS;}
{minus}					{return MINUS;}
{mod}					{return MOD;}
"AND"					{return AND;}
"NOT"					{return NOT;}
"OR"					{return OR;}
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
							return STRING;
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
