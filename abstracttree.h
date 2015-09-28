#include <string.h>
#define NODETYPE_LEAF 0
#define NODETYPE_ID 1
#define NODETYPE_PLUS 2
#define NODETYPE_MUL 3
#define NODETYPE_GT 4
#define NODETYPE_LT 5
#define NODETYPE_EQ 6
#define NODETYPE_ASGN 7
#define NODETYPE_READ 8
#define NODETYPE_WRITE 9
#define NODETYPE_IF 10
#define NODETYPE_THEN 11
#define NODETYPE_ELSE 12
#define NODETYPE_ENDIF 13
#define NODETYPE_WHILE 14
#define NODETYPE_DO 15
#define NODETYPE_ENDWHILE 16
#define NODETYPE_NONE 17
#define NODETYPE_ARR_ASGN 18
#define NODETYPE_ARR_READ 19
#define NODETYPE_ARR_ID 20
#define NODETYPE_GE 21
#define NODETYPE_LE 22
#define NODETYPE_NE 23
#define NODETYPE_FUNCTION 24
#define NODETYPE_BODY 25
#define NODETYPE_RET 26
#define NODETYPE_MAIN 27
#define NODETYPE_EXPRLIST 28
#define NODETYPE_MINUS 29
#define NODETYPE_MOD 30
#define NODETYPE_DIV 31
#define NODETYPE_AND 32
#define NODETYPE_OR 33
#define NODETYPE_TYPE 34

typedef union Constant {
       int intval;
       char* strval;
};

typedef struct ASTNode{
       TypeTable *Type;
       int Nodetype;
       char *Name;
       Constant Value;
       struct ASTNode *Arglist;
       struct ASTNode *Ptr1,*Ptr2,*Ptr3;
       GSymbol *Gentry;
       LSymbol *Lentry;
}AST;

typedef union memstruct{
	int value;
	char *str;
	int Bind;
}memstruct;

ASTNode* Treecreate(TypeTable *type, int nodetype, char *name, Constant value, ASTNode *arglist, ASTNode *t1, ASTNode *t2, ASTNode *t3);
ASTNode* TreeAppend(ASTNode *t, ASTNode *t1, ASTNode *t2, ASTNode *t3);
memstruct interpret(ASTNode *t);
