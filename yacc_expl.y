%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int yylex(void);
    extern FILE *yyin;

    #include "symboltable.h"
    #include "abstracttree.h"
    #include "stack.h"
    #include "heap.h"

    #include "symboltable.c"
    #include "abstracttree.c"
    #include "stack.c"
    #include "heap.c"

    AST *root;
    TypeTable decl_type,arg_type,local_type;
%}

%union{
    struct ASTNode * nptr;
    struct ArgStruct * arg;
    struct GSymbol * gvar;
    struct LSymbol * lvar;
    struct fieldList * field;
    struct TypeTable * ty;
    char c;
};

%token ENDOFFILE READ WRITE IF THEN ELSE ENDIF DO ENDWHILE BREAK WHILE INT STR RETURN DECL ENDDECL MAIN TYPE ENDTYPE NULLC CONTINUE BEG END RELOP DELIM ASGN AROP2 AROP1 NOT LOGOP DOT NUM ID STRCONST ALLOC DEALLOC

%type <nptr> ENDOFFILE READ WRITE IF THEN ELSE ENDIF DO ENDWHILE BREAK WHILE INT STR RETURN DECL ENDDECL MAIN TYPE ENDTYPE NULLC CONTINUE BEG END RELOP DELIM AROP2 ASGN AROP1 NOT LOGOP DOT NUM ID STRCONST FIELD ALLOC DEALLOC Prog TypeDeclBlock Fdefblock Mainblock TypeDefList TypeDef GDecblock GDecList GDecl Fdef Body slist retstmt stmt E param
%type <arg> ArgList FArgList ArgType Args Arg ArgList1
%type <gvar> GIdList GId
%type <lvar> Ldecblock LdecList Ldecl LIdList LId
%type <field> TypeDeclList TypeDecl IDList TId
%type <ty> NewType

%nonassoc RELOP
%left AROP1
%left AROP2
%right LOGOP
%nonassoc NOT

%%

Prog: TypeDeclBlock GDecblock Fdefblock Mainblock ENDOFFILE {
                                                        interpret($4);
                                                    }
    ;

TypeDeclBlock: TYPE TypeDefList ENDTYPE             {}
    |                                               {}
    ;

TypeDefList: TypeDefList TypeDef                    {}
    |TypeDef                                        {}
    ;

TypeDef: NewType '{' TypeDeclList '}'               {
                                                        //Creates a 'fieldlist' out of the intermediate list.
                                                        //Verifies for multiple declaration of variables.
                                                        //Verfifies if the type assigned to the used defined variables are declared before or is the current one under definition
                                                        Type_field_list_validate($3);
                                                        $1->fields = $3;
                                                    }
    ;

NewType : ID    { $$ = TInstall($1->name,NULL);}

TypeDeclList: TypeDeclList TypeDecl                 { $$ = FAppend($1, $2);}
    |TypeDecl                                       { $$ = $1; }
    ;

TypeDecl: INT IDList DELIM                          {
                                                        //Fills the Type pointer in the intermediate list with integer
                                                        AddFType(TLookUp("int"),$2);
                                                        $$ = $2;
                                                    }
    |STR IDList DELIM                               {
                                                        //Fills the Type pointer in the intermediate list with string
                                                        AddFType(TLookUp("str"),$2);
                                                        $$ = $2;
                                                    }
    |ID IDList DELIM                                {
                                                        //Fills the Type pointer in the intermediate list(IntermList) with the name of the given identifier($1)
                                                        Ttemp = TLookUp($1->name);
                                                        if(Ttemp == NULL){
                                                            yyerror("yacc (TypeDecl) : the type has not been defined");
                                                            printf(" %s",$1->name);
                                                            exit(1);
                                                        }
                                                        AddFType(Ttemp,$2);
                                                        $$ = $2;
                                                    }
    ;

IDList : IDList ',' TId                            {
                                                        //Creates an intermediate list(IntermList) containing the name of the given identifier
                                                        $3->next = $1;
                                                        $$ = $3;
                                                    }
    |TId                                            {
                                                        //Creates an intermediate list(IntermList) containing the name of the given identifier
                                                        $$ = $1;
                                                    }
    ;

TId : ID                                            {   $$ = FInstall($1->name); }

GDecblock : DECL GDecList ENDDECL                   {}
      |                                             {}
    ;

GDecList : GDecList GDecl                           {}
    |GDecl                                          {}
    ;

GDecl : INT GIdList DELIM                           {
                                                        //The Type field of the global symbol table entry is set to integer
                                                        AddGType(TLookUp("int"),$2);
                                                        GAppend($2);
                                                    }
    |STR GIdList DELIM                              {
                                                        //The type field of the global symbol table entry is set to string
                                                        AddGType(TLookUp("str"),$2);
                                                        GAppend($2);
                                                    }
    |ID GIdList DELIM                                 {
                                                        //Type field of the global symbol table entry is set to the specified type.
                                                        //The specified type for used defined type is obtained from a call to
                                                        //TypeTableLookUp function.
                                                        Ttemp = TLookUp($1->name);
                                                        if(Ttemp == NULL){
                                                            yyerror("yacc : the type has not been defined");
                                                            printf(" %s",$1->name);
                                                            exit(1);
                                                        }
                                                        AddGType(Ttemp,$2);
                                                        GAppend($2);
                                                    }
    ;

GIdList : GIdList ',' GId                           {
                                                        //Binds together the global symbol tabe entries.
                                                        $3->next = $1;
                                                        $$ = $3;
                                                    }
    |GId                                            {
                                                        $$ = $1;
                                                    }
    ;

GId : ID '[' NUM ']'                                {
                                                        //Creats a global symbol table entry
                                                        $$ = GInstall($1->name,NULL,$3->value.intval,NULL);
                                                    }
    |ID                                             {
                                                        //Creates a global symbol table entry
                                                        $$ = GInstall($1->name,NULL,1,NULL);
                                                    }
    |ID '(' ArgList ')'                             {
                                                        //Creates a global symbol table entry
                                                        $$ = GInstall($1->name,NULL,0,$3);
                                                    }
    ;

FArgList : ArgList                                  {
                                                        //A Local Symbol Table is created out the entries made.
                                                         $$ = $1;
                                                    }
    ;

ArgList : ArgList1                                  {
                                                        $$ = $1;
                                                    }
    |                                               { $$ = NULL;}
ArgList1 : ArgType DELIM ArgList1                   { $$ = ArgAppend($3, $1);}
    | ArgType                                       { $$ = $1;}
    ;

ArgType : INT Args                                  {
                                                        //The Type field in the ArgStruct entry is set to the specified type.
                                                        AddArgType(TLookUp("int"),$2);
                                                        $$ = $2;
                                                    }
    |STR Args                                       {
                                                        //The Type field in the ArgStruct entry is set to the specified type.
                                                        AddArgType(TLookUp("str"),$2);
                                                        $$ = $2;
                                                    }
    |ID Args                                        {
                                                        //The Type field in the ArgStruct entry is set to the specified type.
                                                        Ttemp = TLookUp($1->name);
                                                        if(Ttemp == NULL){
                                                            yyerror("yacc (argType 2): the type has not been defined");
                                                            printf(" %s",$1->name);
                                                            exit(1);
                                                        }
                                                        AddArgType(Ttemp,$2);
                                                        $$ = $2;
                                                    }
    ;

Args : Args ',' Arg                                 {
                                                        //Appends newly created entries to the existing.
                                                        $3->next = $1;
                                                        $$ = $3;
                                                    }
    |Arg                                            {
                                                        $$ = $1;
                                                    }
    ;

Arg : ID                                            {
                                                        //Creates an ArgStruct entry containing name of the identifier.
                                                        $$ = ArgInstall($1->name,NULL,PASS_BY_VAL);
                                                    }
    | '&' ID                                        {
                                                        $$ = ArgInstall($2->name,NULL,PASS_BY_REF);
                                                    }
    ;

Fdefblock : Fdefblock Fdef                          {}
    |                                               {}
    ;

Fdef : INT ID '(' FArgList ')' '{' Ldecblock Body '}'   {
                                                          //Function definition is compared with their declarartion earlier for compatibility
                                                          //Lentry is set to the LST of the function
                                                          //LST is set to NULL
                                                          AddArgsToLTable(&($7), $4);
                                                          setVariableType($2, IS_ARRAY_FALSE);
                                                          validate_function($2->name,TLookUp("int"),$4,$8);
                                                          Gtemp = Glookup($2->name);
                                                          if(Gtemp == NULL){
                                                              yyerror("Yacc : undeclared function");exit(1);
                                                          }
                                                          $8->Lentry = $7;  //Body's Lentry has the local symbol table
                                                          Gtemp->fbinding = $8;
                                                          LSymbolHead = NULL;
                                                        }
    |STR ID '(' FArgList ')' '{' Ldecblock Body '}'     {
                                                          //Function definition is compared with their declarartion earlier for compatibility
                                                          //Lentry is set to the LST of the function
                                                          //LST is set to NULL
                                                          AddArgsToLTable(&($7), $4);
                                                          setVariableType($2, IS_ARRAY_FALSE);
                                                          validate_function($2->name,TLookUp("str"),$4,$8);
                                                          Gtemp = Glookup($2->name);
                                                          if(Gtemp == NULL){
                                                              yyerror("Yacc : undeclared function");exit(1);
                                                          }
                                                          $8->Lentry = $7;
                                                          Gtemp->fbinding = $8;
                                                          LSymbolHead = NULL;
                                                        }
    |ID ID '(' FArgList ')' '{' Ldecblock Body '}'      {
                                                          //Function definition is compared with their declarartion earlier for compatibility
                                                          //Lentry is set to the LST of the function
                                                          //LST is set to NULL
                                                          Ttemp = TLookUp($1->name);
                                                          setVariableType($2, IS_ARRAY_FALSE);
                                                          if(Ttemp == NULL){
                                                              yyerror("yacc(Fdef) : the return type has not been defined");
                                                              printf(" %s",$1->name);
                                                              exit(1);
                                                          }
                                                          AddArgsToLTable(&($7), $4);
                                                          validate_function($2->name,Ttemp,$4,$8);
                                                          Gtemp = Glookup($2->name);
                                                          if(Gtemp == NULL){
                                                              yyerror("Yacc : undeclared function");exit(1);
                                                          }
                                                          $8->Lentry = $7;
                                                          Gtemp->fbinding = $8;
                                                          LSymbolHead = NULL;
                                                        }
    ;

Ldecblock : DECL LdecList ENDDECL {
                                      setLocalBindings($2);
                                      $$ = $2;
                                      LSymbolHead = $$;
                                  }
    |                             {}
    ;

LdecList : LdecList Ldecl { $$ = LAppend($1, $2); }
    |Ldecl {  $$ = $1;  }
    ;

Ldecl : INT LIdList DELIM {
                            //Fills the Type field of the local symbol table entry with integer.
                            AddLType(TLookUp("int"),$2);
                            $$ = $2;
                          }
    |STR LIdList DELIM    {
                            //Fills the Type field of the local symbol table entry with string.
                            AddLType(TLookUp("str"),$2);
                            $$ = $2;
                          }
    |ID LIdList DELIM     {
                            //Fills the Type field of the Local symbol table with the specified user defined type.
                            AddLType(TLookUp($1->name),$2);
                            $$ = $2;
                          }
    ;

LIdList : LIdList ',' LId {
                            //Appends newly created local symbol table entries to the existing.
                            if(LlookupInTable($1, $3->name) != NULL){
                              yyerror("LInstall : Local variable redefined ");
                              printf(" %s",$3->name);
                              exit(1);
                            }
                            $3->next = $1;
                            $$ = $3;
                          }
    |LId                  {
                            $$ = $1;
                          }
    ;

LId : ID    {
                //Creates a Local Symbol Table entry containing the name of the identifier
                $$ = LInstall($1->name,NULL);
            }
    ;

Mainblock : INT MAIN '(' ')' '{' Ldecblock Body '}' {
                                                        //Verifies if the type of the return statemnt is of type integer
                                                        //calls interpreter
                                                        $7->Lentry = $6;
                                                        Gtemp = GInstall("MAIN",TLookUp("int"),0, NULL);
                                                        Gtemp->fbinding = $7;
                                                        GAppend(Gtemp);
                                                        $$ = TreeCreate(TLookUp("int"), NODETYPE_MAIN, Gtemp->name, (Constant){}, NULL, $7, NULL, NULL);
                                                        $$->Gentry = Gtemp;
                                                        LSymbolHead = NULL;
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
                                setVariableType($1, IS_ARRAY_FALSE);
                                //Verifies if the LHS and RHS of the assignment node is of the same type.
                                $$ = TreeCreate(TLookUp("void"), NODETYPE_ASGN, NULL, (Constant){}, NULL, $1, $3, NULL);
                            }
    |ID '[' E ']' ASGN E DELIM      {
                                        //Verifies if the LHS and RHS of the Assignment node is of the same type.
                                        //Also type checks for array
                                        $$ = TreeCreate(TLookUp("void"), NODETYPE_ARR_ASGN, NULL, (Constant){}, NULL, $1, $3, $6);
                                    }

    |READ '(' ID ')' DELIM      {
                                    //Verifies if the identifier is of type integer or string
                                    setVariableType($3, IS_ARRAY_FALSE);
                                    $$ = TreeCreate(TLookUp("void"), NODETYPE_READ, NULL, (Constant){}, NULL, $3, NULL, NULL);
                                }
    |READ '(' FIELD ')' DELIM   {
                                    //Verifies if the FIELD is of type integer or string
                                    $$ = TreeCreate(TLookUp("void"), NODETYPE_FIELD_READ, NULL, (Constant){}, NULL, $3, NULL, NULL);
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
                                                    setVariableType($1, IS_ARRAY_FALSE);
                                                    $$ = TreeCreate(TLookUp("void"),NODETYPE_ALLOC,NULL,(Constant){},NULL,$1,NULL,NULL);
                                                }
    |FIELD ASGN ALLOC '(' ')' DELIM             {
                                                    //Verifies if the FIELD is of user defined type.
                                                    $$ = TreeCreate(TLookUp("void"),NODETYPE_ALLOC,NULL,(Constant){},NULL,$1,NULL,NULL);
                                                }
    |FIELD ASGN E DELIM                 {
                                            //Verifies if the left hand side and right hand side of the Assignment statement is of same type.
                                            $$ = TreeCreate(TLookUp("void"), NODETYPE_FIELD_ASGN, NULL, (Constant){}, NULL, $1, $3, NULL);
                                        }
    |DEALLOC '(' ID ')' DELIM           {
                                            //Verifies if the field is of user defined type.
                                            setVariableType($3, IS_ARRAY_FALSE);
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
                            if(strcmp($1->type->name,$3->type->name) != 0 || strcmp($1->type->name,"int") != 0){
                        		  yyerror( "TreeCreate : unexpected operand types for nodetype plus/minus/div/mod/mul");exit(1);
                        		}
                            $$ = TreeCreate(TLookUp("int"), $2->nodetype, NULL, (Constant){}, NULL, $1, $3, NULL);
                        }
    |E AROP2 E          {
                            //Verifies if both the expression is of type integer
                            if(strcmp($1->type->name,$3->type->name) != 0 || strcmp($1->type->name,"int") != 0){
                        			yyerror( "TreeCreate : unexpected operand types for nodetype plus/minus/div/mod/mul");exit(1);
                        		}
                            $$ = TreeCreate(TLookUp("int"), $2->nodetype, NULL, (Constant){}, NULL, $1, $3, NULL);
                        }
    |'(' E ')'          {$$=$2;}
    |E RELOP E          {
                            if(strcmp($1->type->name,$3->type->name) != 0 || strcmp($1->type->name,"int") != 0){
                        			yyerror("TreeCreate : unexpected operand types for nodetype gt/lt/ge/le");exit(1);
                        		}
                            $$ = TreeCreate(TLookUp("boolean"), $2->nodetype, NULL, (Constant){}, NULL, $1, $3, NULL);
                        }
    |E LOGOP E          {
                            //Verifies if both the expression is of type boolean
                            if(!(strcmp($1->type->name,$3->type->name) == 0 && (strcmp($1->type->name,"int") == 0 || strcmp($1->type->name,"boolean") == 0) || strcmp($1->type->name,"str") == 0)){
            									yyerror("TreeCreate : unexpected operand types for nodetype eq/ne");exit(1);
            							  }
                            $$ = TreeCreate(TLookUp("boolean"), $2->nodetype, NULL, (Constant){}, NULL, $1, $3, NULL);
                        }
    |NOT E              {
                            //Verifies if the expression is of type boolean or null
                            $$ = TreeCreate(TLookUp("boolean"), NODETYPE_NOT, NULL, (Constant){}, NULL, $2, NULL, NULL);
                        }
    |NUM                {$$ = $1;}
    |STRCONST           {$$ = $1;}
    |ID                 {
                            //type field of the identifier is set to that specified in the symbol table.
                            setVariableType($1, IS_ARRAY_FALSE);
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
                            setVariableType($1, IS_ARRAY_FALSE);
                            Gtemp = Glookup($1->name);
                            if(Gtemp == NULL){
                                yyerror("Yacc : Undefined function");
                                printf(" %s",$1->name);
                                exit(1);
                            }
                            $$ = TreeCreate(Gtemp->type,NODETYPE_FUNCTION,$1->name,(Constant){},$3,NULL,NULL,NULL);
                            $$->Gentry = Gtemp;
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
    TTableCreate();
    if(argc>1)
    {
        FILE *file = fopen(argv[1],"r");
        if(file)
            yyin = file;
    }
    yyparse();
    return 0;
}
