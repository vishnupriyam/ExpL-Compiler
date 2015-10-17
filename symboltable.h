#include <string.h>

typedef struct fieldList
{
	char *name;				//name of the field
	TypeTable *type;	//pointer to type table entry
	struct fieldList *next;
}fieldList;

fieldList *fieldListHead;

typedef struct TypeTable
{
	char *name;			 // type name
	fieldList *fields;	 	 // pointer to the head of the fieldlist
	struct TypeTable *next;
}TypeTable;

TypeTable *TypeTableHead;

void TTableCreate();
TypeTable* TLookUp(char *name);
TypeTable* TInstall(char *name, fieldList *fields);
TypeTable* TAppend(TypeTable *t1);
fieldList* FLookUp(char* name, char* fieldname)

typedef struct ArgStruct {
	TypeTable *type;
	char *name;
	int passType;
	struct ArgStruct *next;
}ArgStruct;

ArgStruct *ArgStructHead,*Argtemp;

ArgStruct* ArgInstall(char* name, TypeTable *type, int passType);

typedef struct GSymbol{
    char *name;
	TypeTable *type;
	int size;
	int BINDING;
	ArgStruct *arglist;
    AST *fbinding;
	struct GSymbol *next;
}GSymbol;

GSymbol *GSymbolHead,*Gtemp;

GSymbol* GInstall(char*name, TypeTable *type, int size, Argstuct *arglist);
GSymbol* Glookup(char *name);
GSymbol* GAppend(GSymbol *g1);
void AddGType(TypeTable *gtype, GSymbol *g);

typedef struct LSymbol{
	char *NAME;
	TypeTable *Type;
	int BINDING;
	struct LSymbol *NEXT;
}LSymbol;

LSymbol *LSymbolHead,*Ltemp;

LSymbol* LInstall(char*name, TypeTable *type);
LSymbol* Llookup(char *name);
void LAppend(LSymbol *l1);
LSymbol* AddLType(TypeTable *ltype, LSymbol *l);

void validate_funtion(char *fname,Typetable *rtype, ArgStruct *arglist, ASTNode *body);
