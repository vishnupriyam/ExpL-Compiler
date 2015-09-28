typedef struct fieldList
{
	char *name;				//name of the field
	struct TypeTable *type;	//pointer to type table entry
	struct fieldList *next;
}fieldList;

typedef struct TypeTable
{
	char *name;			 // type name
	fieldList *fields;	 	 // pointer to the head of the fieldlist
	struct TypeTable *next;
}TypeTable;

void TTableCreate();
struct TypeTable* TLookUp(char *name);
struct TypeTable* TInstall(char *name,struct fieldList *fields);
struct TypeTable* TAppend(struct TypeTable *t1);

struct ArgStruct {
	struct TypeTable *type;
	char *name;
	int passType;
	struct ArgStruct *next;
};

struct ArgStruct *Arginstall(char* name,struct TypeTable *type,int passType);

typedef struct GSymbol{
    char *name;
	TypeTable *type;
	int size;
	int BINDING;
	struct ArgStruct *ARGLIST;
    struct AST *FBINDING;
struct GSymbol *next;
}gsymbol;

struct GSymbol* GInstall(char*name,struct TypeTable *type, int size,struct Argstuct *arglist);
struct GSymbol* Glookup(char *name);
void GAppend(struct GSymbol *g1);
void AddGType(struct TypeTable *gtype,struct GSymbol *g);

typedef struct LSymbol{
	char *NAME;
	struct TypeTable *Type;
	int BINDING;
	struct LSymbol *NEXT;
}lsymbol;

struct LSymbol* LInstall(char*name,struct TypeTable *type, int size);
struct LSymbol* Llookup(char *name);
void LAppend(struct LSymbol *l1);
void AddLType(struct TypeTable *ltype,struct LSymbol *l);
