
void TTableCreate(){
    struct TypeTable *temp = new TypeTable();
    temp = TInstall("int",NULL);
    TAppend(temp);
    temp = TInstall("str",NULL);
    TAppend(temp);
    temp = TInstall("null",NULL);
    TAppend(temp);
    temp = TInstall("void",NULL);
    TAppend(temp);
    temp = TInstall("boolean",NULL);
    TAppend(temp);
}

struct TypeTable* TLookUp(char *name){
    if(name == NULL){
        printf("Error : Cannot look up for an identifier with type NULL in type table\n");
        exit(1);
    }
    struct TypeTable *temp;
    temp = TypeTableHead;
    while(temp != NULL && strcmp(temp->name,name) != 0){
   	 temp = temp->next;
    }
    return temp;
}

struct TypeTable* TInstall(char *name,struct fieldList *fields){
    struct TypeTable *temp = new TypeTable();
    temp->name =  (char *)malloc(sizeof(name));
    strcpy(temp->name,name);
    temp->fieldList = fields;
    temp->next = NULL;
    return temp;
}

struct TypeTable* TAppend(TypeTable *t1){
    t1->next = TypeTableHead;
    TypeTableHead = t1;
}

struct ArgStruct* Arginstall(char* name, struct TypeTable *type,int passType){
    struct ArgStruct *temp = new ArgStruct();
    temp->type = type;
    temp->name =  (char *)malloc(sizeof(name));
    strcpy(temp->name,name);
    temp->passType = passType;
    temp->next = NULL;
    //install the argument in local symbol table also
    return temp;
}
struct GSymbol* GInstall(char*name, struct TypeTable *type, int size, Argstuct *arglist){
    struct GSymbol *check;
    check = Glookup(name);
    if(check != NULL)	//error on redefining the variable
	  {
        yyerror("variable redefined ");
        printf(" %s",name);
        exit(0);
    }
    struct GSymbol *temp = new GSymbol();
    temp->name =  (char *)malloc(sizeof(name));
    strcpy(temp->name,name);
    temp->type = type;
    temp->size = size;
    temp->arglist = arglist;
    temp->next = NULL;
    return temp;
}

void GAppend(GSymbol *g1){
    g1->next = GSymbolHead;
    GSymbolHead = g1;
}

struct GSymbol* Glookup(char *name){
    if(name == NULL){
        printf("Error : Cannot look up for an identifier with name NULL in global symbol table\n");
        exit(1);
    }
    struct GSymbol *temp;
    temp = GSymbolHead;
    while(temp != NULL && strcmp(temp->name,name) != 0){
   	 temp = temp->next;
    }
    return temp;
}

void AddGType(struct TypeTable *gtype, struct GSymbol *g){
    g->type = gtype;
}

struct LSymbol* LInstall(char*name, struct TypeTable *type){
    struct LSymbol *check;
    check = Llookup(name);
    if(check != NULL)	//error on redefining the variable
	  {
        yyerror("variable redefined ");
        printf(" %s",name);
        exit(0);
    }
    struct LSymbol *temp = new LSymbol();
    temp->name =  (char *)malloc(sizeof(name));
    strcpy(temp->name,name);
    temp->type = type;
    temp->next = NULL;
    return temp;
}

struct LSymbol* Llookup(char *name){
    if(name == NULL){
        printf("Error : Cannot look up for an identifier with name NULL in global symbol table\n");
        exit(1);
    }
    struct LSymbol *temp;
    temp = LSymbolHead;
    while(temp != NULL && strcmp(temp->name,name) != 0){
   	 temp = temp->next;
    }
    return temp;
}

void LAppend(struct LSymbol *l1){
    l1->next = LSymbolHead;
    LSymbolHead = l1;
}

void AddLType(struct TypeTable *ltype,struct LSymbol *l){
    l->type = ltype;
}
