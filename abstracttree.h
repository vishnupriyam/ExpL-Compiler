#include <string.h>

struct ASTNode{
       struct TypeTable *Type;
       int Nodetype;
       char *Name;
       union Constant Value;
       struct Tnode *Arglist;
       struct Tnode *Ptr1,*Ptr2,*Ptr3;
       struct GSymbol *Gentry;
       struct LSymbol *Lentry;
}AST;

union Constant {
	int intval;
	char* strval;
};

typedef union memstruct{
	int value;
	char *str;
	int Bind;
}memstruct;


AST* Treecreate(TypeTable *type,int nodetype,char *name,union Constant value,AST *arglist,AST *t1,AST *t2,AST *t3);
AST* TreeAppend(AST *t,AST *t1, AST *t2, AST *t3);
memstruct interpret(AST *t);