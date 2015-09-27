

Prog: TypeDeclBlock GDecblock Fdefblock Mainblock
 	;

TypeDeclBlock: TYPE TypeDefList ENDTYPE
    |
    ;

TypeDefList: TypeDefList TypeDef //Appends the newly created TypeTable to the existing.
    |TypeDef                     //The globally maintained TypeTable TTable is set to $1.
    ;

TypeDef: ID '{' TypeDeclList '}' //Creates a 'TypeTable' out of the intermediate list.
                                 //Verifies for multiple declaration of variables.
                                 //Verfifies if the type assigned to the used defined variables are declared before or is the current one under definition
    ;

TypeDeclList: TypeDeclList TypeDecl
    |TypeDecl
    ;

TypeDecl: INT IDList ';' //Fills the Type pointer in the intermediate list with integer
    |STR IDList ';' //Fills the Type pointer in the intermediate list with string
    |ID IDList ';' //Fills the Type pointer in the intermediate list(IntermList) with the name of the given identifier($1)
    ;

IDList : IDList ',' ID //Creates an intermediate list(IntermList) containing the name of the given identifier.
    |ID //Creates an intermediate list(IntermList) containing the name of the given identifier.
    ;

GDecblock : DECL GDecList ENDDECL
    ;

GDecList : GDecList GDecl //Appends the newly created entries to the GST.
    |GDecl
    ;

GDecl : INT GIdList ';'   //The Type field of the global symbol table entry is set to integer.
    |STR GIdList ';'      //The type field of the global symbol table entry is set to string
    |ID GIdList ';'       //Type field of the global symbol table entry is set to the specified type.
                          //The specified type for used defined type is obtained from a call to
                          //TypeTableLookUp function.
    ;

GIdList : GIdList ',' GId    //Binds together the global symbol tabe entries.
    |GId
    ;

GId : ID '[' NUM ']'         //Creats a global symbol table entry
    |ID //Creates a global symbol table entry
    |ID '(' ArgList ')' //Creates a global symbol table entry
    ;

FArgList : ArgList //A Local Symbol Table is created out the entries made.
    ;

ArgList : ArgList ArgType //Appends newly created entries to the existing
    |ArgType
    ;

ArgType : INT Args ';'     //The Type field in the ArgStruct entry is set to the specified type.
    |STR Args ';'          //The Type field in the ArgStruct entry is set to the specified type.
    |ID Args ';'           //The Type field in the ArgStruct entry is set to the specified type.
    |INT Args          //The Type field in the ArgStruct entry is set to the specified type.
    |STR Args           //The Type field in the ArgStruct entry is set to the specified type.
    |ID Args               //The Type field in the ArgStruct entry is set to the specified type.
    ;

Args : Args ',' Arg        //Appends newly created entries to the existing.
    |Arg
    ;

Arg : ID //Creates an ArgStruct entry containing name of the identifier.
    ;

Fdefblock : Fdefblock Fdef
    |
    ;

Fdef : INT ID '(' FArgList ')' '{' Ldecblock Body '}' //Function definition is compared with their declarartion earlier for compatibility
                                                          //Lentry is set to the LST of the function
                                                          //LST is set to NULL
    |STR ID '(' FArgList ')' '{' Ldecblock Body '}'    //Function definition is compared with their declarartion earlier for compatibility
                                                          //Lentry is set to the LST of the function
                                                          //LST is set to NULL
    |ID ID '(' FArgList ')' '{' Ldecblock Body '}'        //Function definition is compared with their declarartion earlier for compatibility
                                                          //Lentry is set to the LST of the function
                                                          //LST is set to NULL
    ;

Ldecblock : DECL LdecList ENDDECL //Appends the local symbol table to the LST(with parameters)
    ;

LdecList : LdecList Ldecl //Appends newly created local symbol table entries to the existing.
    |Ldecl //$$=$1;
    ;

Ldecl : INT LIdList ';' //Fills the Type field of the local symbol table entry with integer.
    |STR LIdList ';' //Fills the Type field of the local symbol table entry with string.
    |ID LIdList ';' //Fills the Type field of the Local symbol table with the specified user defined type.
    ;

LIdList : LIdList ',' LId //Appends newly created local symbol table entries to the existing.
    |LId //$$=$1;
    ;

LId : ID //Creates a Local Symbol Table entry containing the name of the identifier
    ;

Mainblock : INT MAIN '(' ')' '{' Ldecblock Body '}' //Verifies if the type of the return statemnt is of type integer
                                                        //calls interpreter;
    ;

Body : BEG slist retstmt END //Return statement is set as Ptr2 of slist
    ;

slist: slist stmt //Appends newly created statement node to the existing.
    |stmt //$$=$1;
    ;

stmt: ID ASGN E ';' //Verifies if the LHS and RHS of the assignment node is of the same type.
    |ID '[' E ']' ASGN E ';' //Verifies if the LHS and RHS of the Assignment node is of the same type.
                           //Also type checks for array
    |READ '(' ID ')' ';' //Verifies if the identifier is of type integer or string
    |READ '(' FIELD ')' ';' //Verifies if the FIELD is of type integer or string
    |READ '(' ID '[' E ']' ')' ';' //Verifies if the identifier is of type integer or string. //Being an array, Expression node has to be of type integer.
    |WRITE '(' E ')' ';' //Verifies if the Expression node is of type integer or string
    |IF '(' E ')' THEN slist ENDIF ';'
    |IF '(' E ')' THEN slist ELSE slist ENDIF ';' //Verifies if the Conditional Expression node is of boolean type.
                                                  //Verifies if the Conditional Expression node is of boolean type
    |WHILE '(' E ')' DO slist ENDWHILE ';' //Verifies if the Conditional Expression node is of boolean type.
    |ID ASGN ALLOC '(' ')' ';' //Verifies if the identifier is of user defined type.
    |FIELD ASGN ALLOC '(' ')' ';' //Verifies if the FIELD is of user defined type.
    |FIELD ASGN E ';' //Verifies if the left hand side and right hand side of the Assignment statement is of same type.
    |DEALLOC '(' ID ')' ';' //Verifies if the field is of user defined type.
    |DEALLOC '(' FIELD ')' ';' //Verifies if the FIELD is of user defined type.
    ;

FIELD :ID DOT ID //The Type field for the identifiers are set.
                 //Example: In the reduction of a.b, the Type field of a is set based on the symbol table entry.
                 //The Type field of b is set to that specified in the fieldlist of the Typetable entry for a
    |FIELD DOT ID
    ;

E: E AROP1 E   //Verifies if both the expression is of type integer.
    |E AROP2 E //Verifies if both the expression is of type integer.
    |'(' E ')' //$$=$2;
    |E RELOP E //Both the expression has to be of either integer or string.
               //User defined variables are allowed only for the relational operators '==' and '!='
    |E LOGOP E //Verifies if both the expression is of type boolean
    |NOTOP E //Verifies if the expression is of type boolean or null
    |NUM //$$=$1;
    |STRCONST //$$=$1;
    |ID //type field of the identifier is set to that specified in the symbol table.
    |ID '[' E ']' //Type field in the Tnode is set to that specified in the symbol table.
                 //Verifies if the expression node is an integer
    |FIELD //$$=$1 //The Type field of the identifier is from the fieldlist entry of the TypeTable. //Verifies for the parameter compatibility in function declaration and calling.
    |null //$$=$1
    |ID '(' param ')'
 //Type of the identifier is set to that specified in the global symbol table during declaration.
 //The Argument list created before is set to the Arglist field.
 ;

param : param ',' E //Creates a statement node and its Ptr1 field is set to the expression node.
                    //Appends the newly created parameter list to the existing.
    |E //Creates a statement node and its Ptr1 field is set to the expression node.
    ;

retstmt : RETURN E ';' //Appends expression to the return statement.
    ;
