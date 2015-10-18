%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int yylex(void);
    extern FILE *yyin;
    #include "abstracttree.h"
    #include "symboltable.h"
    #include "symboltable.c"
    #include "abstracttree.c"
    AST *root;
    TypeTable decl_type,arg_type,local_type;
%}

%union{
    AST * nptr;
    ArgStruct * arg;
    char c;
};

%token ENDOFFILE READ WRITE IF THEN ELSE ENDIF DO ENDWHILE BREAK WHILE INT STR RETURN DECL ENDDECL MAIN TYPE ENDTYPE NULLC CONTINUE BEG END RELOP DELIM ASGN AROP2 AROP1 NOT LOGOP DOT NUM ID STRCONST ALLOC DEALLOC

%type <nptr> ENDOFFILE READ WRITE IF THEN ELSE ENDIF DO ENDWHILE BREAK WHILE INT STR RETURN DECL ENDDECL MAIN TYPE ENDTYPE NULLC CONTINUE BEG END RELOP DELIM AROP2 ASGN AROP1 NOT LOGOP DOT NUM ID STRCONST FIELD ALLOC DEALLOC Prog TypeDeclBlock GDecblock Fdefblock Mainblock TypeDefList TypeDef TypeDeclList TypeDecl IDList GDecblock GDecList GDecl GIdList GId  ArgList FArgList ArgType Args Arg Fdef Ldecblock Body LdecList Ldecl LIdList LId slist retstmt stmt E param

%nonassoc RELOP
%left AROP1
%left AROP2
%right LOGOP

%%

Prog: TypeDeclBlock GDecblock Fdefblock Mainblock   {
                                                        interpret($4);
                                                    }
    ;

TypeDeclBlock: TYPE TypeDefList ENDTYPE             {}
    |                                               {}
    ;

TypeDefList: TypeDefList TypeDef                    {}                                                    }
    |TypeDef                                        {}
    ;

TypeDef: NewType '{' TypeDeclList '}'               {
                                                        //Creates a 'fieldlist' out of the intermediate list.
                                                        //Verifies for multiple declaration of variables.
                                                        //Verfifies if the type assigned to the used defined variables are declared before or is the current one under definition
                                                        Type_field_list_validate();
                                                        $1->fields = fieldListHead;
                                                        fieldListHead = NULL;
                                                    }
    ;

NewType : ID    { $$ = TInstall($1->Name,NULL);}

TypeDeclList: TypeDeclList TypeDecl                 {}
    |TypeDecl                                       {}
    ;

TypeDecl: INT IDList DELIM                          {
                                                        //Fills the Type pointer in the intermediate list with integer
                                                        AddFType(TLookUp("int"),$2);
                                                    }
    |STR IDList DELIM                               {
                                                        //Fills the Type pointer in the intermediate list with string
                                                        AddFType(TLookUp("str"),$2);
                                                    }
    |ID IDList DELIM                                {
                                                        //Fills the Type pointer in the intermediate list(IntermList) with the name of the given identifier($1)
                                                        Ttemp = TLookUp($1->Name);
                                                        if(Ttemp == NULL){
                                                            yyerror("yacc (TypeDecl) : the type has not been defined");
                                                            printf(" %s",$1->Name);
                                                            exit(1);
                                                        }
                                                        AddFType(Ttemp,$2);
                                                    }
    ;

IDList : IDList ',' TId                            {
                                                        //Creates an intermediate list(IntermList) containing the name of the given identifier
                                                        $$ = FAppend($3);
                                                    }
    |TId                                            {
                                                        //Creates an intermediate list(IntermList) containing the name of the given identifier
                                                        $$ = FAppend($1);
                                                    }
    ;

TId : ID                                            {   $$ = FInstall($1->Name); }

GDecblock : DECL GDecList ENDDECL                   {}
    ;

GDecList : GDecList GDecl                           {}
    |GDecl                                          {}
    ;

GDecl : INT GIdList DELIM                           {
                                                        //The Type field of the global symbol table entry is set to integer
                                                        AddGType(TLookUp("int"),$2);
                                                    }
    |STR GIdList DELIM                              {
                                                        //The type field of the global symbol table entry is set to string
                                                        AddGType(TLookUp("str"),$2);
                                                    }
    |ID GIdList DELIM                                 {
                                                        //Type field of the global symbol table entry is set to the specified type.
                                                        //The specified type for used defined type is obtained from a call to
                                                        //TypeTableLookUp function.
                                                        Ttemp = TLookUp($1->Name);
                                                        if(Ttemp == NULL){
                                                            yyerror("yacc : the type has not been defined");
                                                            printf(" %s",$1->Name);
                                                            exit(1);
                                                        }
                                                        AddGType(Ttemp,$2);
                                                    }
    ;

GIdList : GIdList ',' GId                           {
                                                        //Binds together the global symbol tabe entries.
                                                        $$ = GAppend($3);
                                                    }
    |GId                                            {
                                                        $$ = GAppend($1);
                                                    }
    ;

GId : ID '[' NUM ']'                                {
                                                        //Creats a global symbol table entry
                                                        $$ = GInstall($1->Name,NULL,$3->value,$3);
                                                    }
    |ID                                             {
                                                        //Creates a global symbol table entry
                                                        $$ = GInstall($1->Name,NULL,1,$3);
                                                    }
    |ID '(' ArgList ')'                             {
                                                        //Creates a global symbol table entry
                                                        $$ = GInstall($1->Name,NULL,1,$3);
                                                    }
    ;

FArgList : ArgList                                  {
                                                        //A Local Symbol Table is created out the entries made.
                                                         AddArgsToLTable(ArgStructHead);
                                                         $$ = ArgStructHead;

                                                    }
    ;

ArgList : ArgList ArgType                           {}
    |ArgType                                        {}
    ;

ArgType : INT Args DELIM                            {
                                                        //The Type field in the ArgStruct entry is set to the specified type.
                                                        AddArgType(TLookup("int"),$2);
                                                    }
    |STR Args DELIM                                 {
                                                        //The Type field in the ArgStruct entry is set to the specified type.
                                                        AddArgType(TLookup("str"),$2);
                                                    }
    |ID Args DELIM                                   {
                                                        //The Type field in the ArgStruct entry is set to the specified type.
                                                        Ttemp = TLookUp($1->Name);
                                                        if(Ttemp == NULL){
                                                            yyerror("yacc (argType) : the type has not been defined");
                                                            printf(" %s",$1->Name);
                                                            exit(1);
                                                        }
                                                        AddArgType(Ttemp,$2);
                                                    }
    |INT Args                                       {
                                                        //The Type field in the ArgStruct entry is set to the specified type.
                                                        AddArgType(TLookup("int"),$2);
                                                    }
    |STR Args                                       {
                                                        //The Type field in the ArgStruct entry is set to the specified type.
                                                        AddArgType(TLookup("str"),$2);
                                                    }
    |ID Args                                        {
                                                        //The Type field in the ArgStruct entry is set to the specified type.
                                                        Ttemp = TLookUp($1->Name);
                                                        if(Ttemp == NULL){
                                                            yyerror("yacc (argType 2): the type has not been defined");
                                                            printf(" %s",$1->Name);
                                                            exit(1);
                                                        }
                                                        AddArgType(Ttemp,$2);
                                                    }
    ;

Args : Args ',' Arg                                 {
                                                        //Appends newly created entries to the existing.
                                                        $$ = ArgAppend($3);
                                                    }
    |Arg                                            {
                                                        $$ = ArgAppend($1);
                                                    }
    ;

Arg : ID                                            {
                                                        //Creates an ArgStruct entry containing name of the identifier.
                                                        $$ = ArgInstall($1->Name,NULL,0);
                                                    }
    ;

Fdefblock : Fdefblock Fdef                          {}
    |                                               {}
    ;

Fdef : INT ID '(' FArgList ')' '{' Ldecblock Body '}'   {
                                                          //Function definition is compared with their declarartion earlier for compatibility
                                                          //Lentry is set to the LST of the function
                                                          //LST is set to NULL
                                                          validate_function($2->Name,TLookUp("int"),$4,$8);
                                                          $2->Lentry = LSymbolHead;
                                                          interpret($7);
                                                          LSymbolHead = NULL;
                                                          ArgStructHead = NULL;
                                                        }
    |STR ID '(' FArgList ')' '{' Ldecblock Body '}'     {
                                                          //Function definition is compared with their declarartion earlier for compatibility
                                                          //Lentry is set to the LST of the function
                                                          //LST is set to NULL
                                                          validate_function($2->Name,TLookUp("str"),$4,$8);
                                                          $2->Lentry = LSymbolHead;
                                                          interpret($7);
                                                          LSymbolHead = NULL;
                                                          ArgStructHead = NULL;
                                                        }
    |ID ID '(' FArgList ')' '{' Ldecblock Body '}'      {
                                                          //Function definition is compared with their declarartion earlier for compatibility
                                                          //Lentry is set to the LST of the function
                                                          //LST is set to NULL
                                                          Ttemp = TLookUp($1->Name);
                                                          if(Ttemp == NULL){
                                                              yyerror("yacc(Fdef) : the return type has not been defined");
                                                              printf(" %s",$1->Name);
                                                              exit(1);
                                                          }
                                                          validate_function($2->Name,Ttemp,$4,$8);
                                                          $2->Lentry = LSymbolHead;
                                                          interpret($7);
                                                          LSymbolHead = NULL;
                                                          ArgStructHead = NULL;
                                                        }
    ;

Ldecblock : DECL LdecList ENDDECL {}
    ;

LdecList : LdecList Ldecl {}
    |Ldecl {}
    ;

Ldecl : INT LIdList DELIM {
                            //Fills the Type field of the local symbol table entry with integer.
                            AddLType($2,TLookUp("int"));
                          }
    |STR LIdList DELIM    {
                            //Fills the Type field of the local symbol table entry with string.
                            AddLType($2,TLookUp("str"));
                          }
    |ID LIdList DELIM     {
                            //Fills the Type field of the Local symbol table with the specified user defined type.
                            AddLType($2,TLookUp($1->Name));
                          }
    ;

LIdList : LIdList ',' LId {
                            //Appends newly created local symbol table entries to the existing.
                            $$ = LAppend($3);
                          }
    |LId                  {
                            $$ = LAppend($1);
                          }
    ;

LId : ID    {
                //Creates a Local Symbol Table entry containing the name of the identifier
                $$ = LInstall($1->Name,decl_type);
            }
    ;

Mainblock : INT MAIN '(' ')' '{' Ldecblock Body '}' {
                                                        //Verifies if the type of the return statemnt is of type integer
                                                        //calls interpreter
                                                        $$ = TreeCreate(TLookUp("void"), NODETYPE_MAIN, NULL, (Constant){}, NULL, $7, NULL, NULL);
                                                    }
    ;

Body : BEG slist retstmt END{
                                //Return statement is set as Ptr2 of slist
                                $$ = TreeCreate(TLookUp("void"), NODETYPE_BODY, NULL, (Constant){}, NULL, $2, $3, NULL);
                            }
    ;

slist: slist stmt           {
                                //Appends newly created statement node to the existing.
                                $$ = TreeCreate(TLookUp("void"), NODETYPE_NONE, NULL, (Constant){}, NULL, $1, $2, NULL);
                            }
    |stmt                   { $$ = $1; }
    ;

stmt: ID ASGN E DELIM       {
                                //Verifies if the LHS and RHS of the assignment node is of the same type.
                                $$ = TreeCreate(TLookUp("void"), NODETYPE_ASGN, NULL, (Constant){}, NULL, $1, $3, NULL);
                            }
    |ID '[' E ']' ASGN E DELIM      {
                                        //Verifies if the LHS and RHS of the Assignment node is of the same type.
                                        //Also type checks for array
                                        $$ = TreeCreate(TLookup("void"), NODETYPE_ARR_ASGN, NULL, (Constant){}, NULL, $1, $3, $6);
                                    }

    |READ '(' ID ')' DELIM      {
                                    //Verifies if the identifier is of type integer or string
                                    $$ = TreeCreate(TLookUp("void"), NODETYPE_READ, NULL, (Constant){}, NULL, $3, NULL, NULL);
                                }
    |READ '(' FIELD ')' DELIM   {
                                    //Verifies if the FIELD is of type integer or string
                                    $$ = TreeCreate(TLookup("void"), NODETYPE_FIELD_READ, NULL, (Constant){}, NULL, $3, NULL, NULL);
                                }
    |READ '(' ID '[' E ']' ')' DELIM    {
                                            //Verifies if the identifier is of type integer or string. //Being an array, Expression node has to be of type integer.
                                            $$ = TreeCreate(TLookUp("void"), NODETYPE_ARR_READ, NULL, (Constant){}, NULL, $3, $5, NULL);
                                        }
    |WRITE '(' E ')' DELIM         {
                                        //Verifies if the Expression node is of type integer or string
                                        $$ = TreeCreate(TLookUp("void"), NODETYPE_WRITE, NULL, (Constant){}, NULL, $3, NULL, NULL);
                                    }
    |IF '(' E ')' THEN slist ENDIF DELIM    {
                                                $$ = TreeCreate(TLookUp("void"), NODETYPE_IF, NULL, (Constant){},NULL, $3, $6, NULL);
                                            }
    |IF '(' E ')' THEN slist ELSE slist ENDIF DELIM     {
                                                            //Verifies if the Conditional Expression node is of boolean type.
                                                            //Verifies if the Conditional Expression node is of boolean type
                                                            $$ = TreeCreate(TLookUp("void"), NODETYPE_IF, NULL, (Constant){},NULL, $3, $6, $8);
                                                        }
    |WHILE '(' E ')' DO slist ENDWHILE DELIM    {
                                                    //Verifies if the Conditional Expression node is of boolean type.
                                                    $$ = TreeCreate(TLookUp("void"), NODETYPE_WHILE, NULL, (Constant){}, NULL, $3, $6, NULL);
                                                }
    |ID ASGN ALLOC '(' ')' DELIM                {
                                                    //Verifies if the identifier is of user defined type
                                                    $$ = TreeCreate(TLookup("void"),NODETYPE_ALLOC,NULL,(Constant){},NULL,$1,NULL,NULL);
                                                }
    |FIELD ASGN ALLOC '(' ')' DELIM             {
                                                    //Verifies if the FIELD is of user defined type.
                                                    $$ = TreeCreate(TLookup("void"),NODETYPE_ALLOC,NULL,(Constant){},NULL,$1,NULL,NULL);
                                                }
    |FIELD ASGN E DELIM                 {
                                            //Verifies if the left hand side and right hand side of the Assignment statement is of same type.
                                            $$ = TreeCreate(TLookup("void"), NODETYPE_FIELD_ASGN, NULL, (Constant){}, NULL, $1, $3, NULL);
                                        }
    |DEALLOC '(' ID ')' DELIM           {
                                            //Verifies if the field is of user defined type.
                                            $$ = TreeCreate(TLookUp("void"),NODETYPE_DEALLOC,NULL,(Constant){},NULL,$3,NULL,NULL);
                                        }
    |DEALLOC '(' FIELD ')' DELIM        {
                                            //Verifies if the FIELD is of user defined type.
                                            $$ = TreeCreate(TLookUp("void"),NODETYPE_DEALLOC,NULL,(Constant){},NULL,$3,NULL,NULL);
                                        }
    ;

FIELD :ID DOT ID         {
                            //The Type field for the identifiers are set.
                            //Example: In the reduction of a.b, the Type field of a is set based on the symbol table entry.
                            //The Type field of b is set to that specified in the fieldlist of the Typetable entry for a
                            $$ = TreeCreate(TLookUp("void"), NODETYPE_FIELD, NULL, (Constant){}, NULL, $1, $3, NULL);
                        }
    |FIELD DOT ID       {
                            $$ = TreeCreate(TLookUp("void"), NODETYPE_FIELD, NULL, (Constant){}, NULL, $1, $3, NULL);
                        }
    ;

E: E AROP1 E            {
                            //Verifies if both the expression is of type integer
                            $$ = TreeCreate(TLookUp("int"), $2->Nodetype, NULL, (Constant){}, NULL, $1, $3, NULL);
                        }
    |E AROP2 E          {
                            //Verifies if both the expression is of type integer
                            $$ = TreeCreate(TLookUp("int"), $2->Nodetype, NULL, (Constant){}, NULL, $1, $3, NULL);
                        }
    |'(' E ')'          {$$=$2;}
    |E RELOP E          {
                            $$ = TreeCreate(TLookUp("boolean"), $2->Nodetype, NULL, (Constant){}, NULL, $1, $3, NULL);
                        }
    |E LOGOP E          {
                            //Verifies if both the expression is of type boolean
                            $$ = TreeCreate(TLookUp("boolean"), $2->Nodetype, NULL, (Constant){}, NULL, $1, $3, NULL);
                        }
    |NOT E              {
                            //Verifies if the expression is of type boolean or null
                            $$ = TreeCreate(TLookUp("boolean"), NODETYPE_NOT, NULL, (Constant){}, NULL, $2, NULL, NULL);
                        }
    |NUM                {$$ = $1;}
    |STRCONST           {$$ = $1;}
    |ID                 {
                            //type field of the identifier is set to that specified in the symbol table.
                            $$ = $1;
                        }
    |ID '[' E ']'       {
                            //Type field in the ASTnode is set to that specified in the symbol table.
                            //Verifies if the expression node is an integer
                            $$ = TreeCreate(NULL, NODETYPE_ARR_ID, NULL, (Constant){}, NULL, $1, $3, NULL);
                        }
    |FIELD              {
                            //The Type field of the identifier is from the fieldlist entry of the TypeTable.
                            //Verifies for the parameter compatibility in function declaration and calling.
                            $$ = $1;
                        }
    |NULLC              {$$ = $1;}
    |ID '(' param ')'   {
                            //Type of the identifier is set to that specified in the global symbol table during declaration.
                            //The Argument list created before is set to the Arglist field.
                            Gtemp = Glookup($1->Name);
                            if(Gtemp == NULL){
                                yyerror("Yacc : Undefined function");
                                printf(" %s\n" $3->Name);
                                exit(1);
                            }
                            $$ = TreeCreate(Gtemp->type,NODETYPE_FUNCTION,$1->Name,(Constant){},$3,NULL,NULL,NULL)
                        }
 ;

param : param ',' E {
                        //Creates a statement node and its Ptr1 field is set to the expression node.
                        //Appends the newly created parameter list to the existing.
                        $$ = TreeCreate(TLookUp("void"),NODETYPE_PARAM,NULL,(Constant){},NULL,$1,$3,NULL);

                    }
    |E              {
                        //Creates a statement node and its Ptr1 field is set to the expression node.
                        $$ = TreeCreate(TLookUp("void"),NODETYPE_PARAM,NULL,(Constant){},NULL,$1,NULL,NULL);
                    }
    ;

retstmt : RETURN E DELIM {
                            //Appends expression to the return statement.
                            $$ = TreeCreate($2->type, NODETYPE_RET,NULL,(Constant){},NULL,$2,NULL,NULL);
                         }
    ;

%%

int main(int argc,char* argv[]) {
    if(argc>1)
    {
        FILE *file = fopen(argv[1],"r");
        if(file)
            yyin = file;
    }
    yyparse();
    return 0;
}
