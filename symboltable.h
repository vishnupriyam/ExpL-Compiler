#include <string.h>

#define ARG_START_BIND -2
#define LOCAL_START_BIND 1
#define GLOBAL_START_BIND 0

typedef struct TypeTable
{
	char *name;			 // type name
	struct fieldList *fields;	 	 // pointer to the head of the fieldlist
	struct TypeTable *next;
}TypeTable;

TypeTable *TypeTableHead,*Ttemp;

void TTableCreate();
struct TypeTable* TLookUp(char *name);
struct TypeTable* TInstall(char *name,struct fieldList *fields);
struct TypeTable* TAppend(TypeTable *t1);
struct fieldList* FLookUp(char* name, char* fieldname);

typedef struct fieldList
{
	char *name;				//name of the field
	struct TypeTable *type;	//pointer to type table entry
	struct fieldList *next;
}fieldList;

fieldList *fieldListHead,*ftemp;

struct fieldList* FInstall(char *name);
void AddFType(TypeTable *type, fieldList *f);
struct fieldList* FAppend(fieldList *f1, fieldList *f2);
struct fieldList* FieldLookup(char *name);
void Type_field_list_validate();
int isUserDefinedtype(TypeTable *t);
int fieldRelativeAddress(TypeTable *t, char *name);

typedef struct ArgStruct {
	TypeTable *type;
	char *name;
	int passType;
	struct ArgStruct *next;
}ArgStruct;

ArgStruct *ArgStructHead,*Argtemp;

struct ArgStruct* ArgInstall(char* name, TypeTable *type, int passType);
struct ArgStruct* ArgAppend(ArgStruct *arg1, ArgStruct *arg2);
void AddArgType(TypeTable *type, ArgStruct *arg);

typedef struct GSymbol{
  char *name;
	TypeTable *type;
	int size;
	int binding;
	ArgStruct *arglist;
	struct ASTNode *fbinding;
	struct GSymbol *next;
}GSymbol;

GSymbol *GSymbolHead,*Gtemp;
int gbinding = GLOBAL_START_BIND;

struct GSymbol* GInstall(char *name, TypeTable *type, int size, ArgStruct *arglist);
struct GSymbol* Glookup(char *name);
void GAppend(GSymbol *g1);
void AddGType(TypeTable *gtype, GSymbol *g);

typedef struct LSymbol{
	char *name;
	TypeTable *type;
	int binding;
	struct LSymbol *next;
}LSymbol;

LSymbol *LSymbolHead,*Ltemp;

struct LSymbol* LInstall(char *name, TypeTable *type);
struct LSymbol* Llookup(char *name);
struct LSymbol *LlookupInTable(LSymbol *LSymbolHead, char *name);
struct LSymbol* LAppend(LSymbol *l1, LSymbol *l2);
void setLocalBindings(LSymbol *LSymbolHead);
void AddLType(TypeTable *ltype, LSymbol *l);

void validate_function(char *fname,TypeTable *rtype, ArgStruct *arglist,struct ASTNode *body);
void AddArgsToLTable(LSymbol **LSymbolHead, ArgStruct *a);
