#include <string.h>

typedef struct fieldList
{
	char *name;				//name of the field
	TypeTable *type;	//pointer to type table entry
	struct fieldList *next;
}*fieldListHead;

typedef struct TypeTable
{
	char *name;			 // type name
	fieldList *fields;	 	 // pointer to the head of the fieldlist
	struct TypeTable *next;
}*TypeTableHead;

void TTableCreate();
struct TypeTable* TLookUp(char *name);
struct TypeTable* TInstall(char *name, fieldList *fields);
struct TypeTable* TAppend(struct TypeTable *t1);

typedef struct ArgStruct {
	TypeTable *type;
	char *name;
	int passType;
	struct ArgStruct *next;
}*ArgStructHead;

struct ArgStruct* Arginstall(char* name, struct TypeTable *type,int passType);

typedef struct GSymbol{
    char *name;
	struct TypeTable *type;
	int size;
	int BINDING;
	ArgStruct *arglist;
    ASTNode *fbinding;
	struct GSymbol *next;
}*GSymbolHead;

struct GSymbol* GInstall(char*name, struct TypeTable *type, int size, Argstuct *arglist);
struct GSymbol* Glookup(char *name);
void GAppend(GSymbol *g1);
void AddGType(struct TypeTable *gtype, struct GSymbol *g);

typedef struct LSymbol{
	char *NAME;
	TypeTable *Type;
	int BINDING;
	struct LSymbol *NEXT;
}*LSymbolHead;

struct LSymbol* LInstall(char*name, struct TypeTable *type);
struct LSymbol* Llookup(char *name);
void LAppend(struct LSymbol *l1);
void AddLType(struct TypeTable *ltype,struct LSymbol *l);
