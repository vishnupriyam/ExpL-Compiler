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
#define NODETYPE_PARAM 28
#define NODETYPE_MINUS 29
#define NODETYPE_MOD 30
#define NODETYPE_DIV 31
#define NODETYPE_AND 32
#define NODETYPE_OR 33
#define NODETYPE_TYPE 34
#define NODETYPE_NULL 35
#define NODETYPE_NOT 36
#define NODETYPE_FIELD_READ 37
#define NODETYPE_FIELD_ASGN 38
#define NODETYPE_FIELD 39
#define NODETYPE_ALLOC 40
#define NODETYPE_DEALLOC 41

#define MEMSTRUCT_EMPTY -1
#define MEMSTRUCT_INT 1
#define MEMSTRUCT_STR 2
#define MEMSTRUCT_BIND 3

#define IS_ARRAY_FALSE 0
#define IS_ARRAY_TRUE 1

#define FLAG_FBIND_ADDRESS 0
#define FLAG_FBIND_VALUE 1

typedef union Constant {
       int intval;
       char* strval;
}Constant;

typedef struct ASTNode{
       TypeTable *type;
       int nodetype;
       char *name;
       Constant value;
       struct ASTNode *arglist;
       struct ASTNode *ptr1,*ptr2,*ptr3;
       GSymbol *Gentry;
       LSymbol *Lentry;
}AST;

typedef struct memstruct{
	int type;
	Constant value;
}memstruct;

AST* TreeCreate(TypeTable *type, int nodetype, char *name, Constant value, AST *arglist, AST *t1, AST *t2, AST *t3);
AST* TreeAppend(AST *t, AST *t1, AST *t2, AST *t3);
memstruct interpret(AST *t);
void setVariableType(AST *t, int isArray);
