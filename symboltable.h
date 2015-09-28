typedef struct fieldList
{
	char *name;				//name of the field
	TypeTable *type;	//pointer to type table entry
	struct fieldList *next;
}fieldList;

typedef struct TypeTable
{
	char *name;			 // type name
	fieldList *fields;	 	 // pointer to the head of the fieldlist
	struct TypeTable *next;
}TypeTable;

void TTableCreate();
TypeTable* TLookUp(char *name);
TypeTable* TInstall(char *name, fieldList *fields);
TypeTable* TAppend(TypeTable *t1);

typedef struct ArgStruct {
	TypeTable *type;
	char *name;
	int passType;
	struct ArgStruct *next;
}ArgStruct;

ArgStruct *Arginstall(char* name, TypeTable *type,int passType);

typedef struct GSymbol{
    char *name;
	TypeTable *type;
	int size;
	int BINDING;
	ArgStruct *ARGLIST;
    ASTNode *FBINDING;
	struct GSymbol *next;
}GSymbol;

GSymbol* GInstall(char*name, TypeTable *type, int size, Argstuct *arglist);
GSymbol* Glookup(char *name);
void GAppend(GSymbol *g1);
void AddGType(TypeTable *gtype, GSymbol *g);

typedef struct LSymbol{
	char *NAME;
	TypeTable *Type;
	int BINDING;
	struct LSymbol *NEXT;
}LSymbol;

LSymbol* LInstall(char*name, TypeTable *type, int size);
LSymbol* Llookup(char *name);
void LAppend(LSymbol *l1);
void AddLType(TypeTable *ltype, LSymbol *l);