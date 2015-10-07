void TTableCreate(){
    TypeTable *temp;
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

TypeTable* TLookUp(char *name){
    if(name == NULL){
        yyerror("Cannot look up for an identifier with type NULL in type table ");
        printf(" %s",name);
        exit(1);
    }
    TypeTable *temp;
    temp = TypeTableHead;
    while(temp != NULL && strcmp(temp->name,name) != 0){
   	 temp = temp->next;
    }
    return temp;
}

fieldList* FLookUp(char *name, char* fieldname){
    TypeTable *temp = TLookUp(name);
    if(temp == NULL){
        return NULL;
    }
    fieldList *list = temp->fields;
    while(list != NULL && strcmp(list->name,name) != 0){
        list = list->next;
    }
    return list;
}

TypeTable* TInstall(char *name, fieldList *fields){
    TypeTable *temp = (TypeTable *)malloc(sizeof(TypeTable));
    if(TLookUp(name) != NULL){
        yyerror("type redefined ");
        printf(" %s",name);
        exit(1);
    }
    temp->name =  (char *)malloc(sizeof(name));
    strcpy(temp->name,name);
    temp->fieldList = fields;
    temp->next = NULL;
    return temp;
}

TypeTable* TAppend(TypeTable *t1){
    t1->next = TypeTableHead;
    TypeTableHead = t1;
}

ArgStruct* ArgInstall(char* name, TypeTable *type,int passType){
    ArgStruct *temp = (ArgStruct *)malloc(sizeof(ArgStruct));
    //TODO check multiple arg with same name
    temp->type = type;
    temp->name =  (char *)malloc(sizeof(name));
    strcpy(temp->name,name);
    temp->passType = passType;
    temp->next = NULL;
    //TODO install the argument in local symbol table also
    return temp;
}
GSymbol* GInstall(char*name, TypeTable *type, int size, Argstuct *arglist){
    if(Glookup(name) != NULL)	//error on redefining the variable
	  {
        yyerror("Global variable redefined ");
        printf(" %s",name);
        exit(1);
    }
    GSymbol *temp = (GSymbol *)malloc(sizeof(GSymbol));
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

GSymbol* Glookup(char *name){
    if(name == NULL){
        yyerror("Cannot look up for an identifier with name NULL in global symbol table ");
        printf(" %s",name);
        exit(1);
    }
    GSymbol *temp;
    temp = GSymbolHead;
    while(temp != NULL && strcmp(temp->name,name) != 0){
   	 temp = temp->next;
    }
    return temp;
}

void AddGType(TypeTable *gtype, GSymbol *g){
    g->type = gtype;
}

LSymbol* LInstall(char *name, TypeTable *type){
    if(Llookup(name) != NULL)	//error on redefining the variable
	  {
        yyerror("Local variable redefined ");
        printf(" %s",name);
        exit(1);
    }
    LSymbol *temp = (LSymbol *)malloc(sizeof(LSymbol));
    temp->name =  (char *)malloc(sizeof(name));
    strcpy(temp->name,name);
    temp->type = type;
    temp->next = NULL;
    return temp;
}

LSymbol* Llookup(char *name){
    if(name == NULL){
        yyerror("Cannot look up for an identifier with name NULL in global symbol table ");
        printf(" %s",name);
        exit(1);
    }
    LSymbol *temp;
    temp = LSymbolHead;
    while(temp != NULL && strcmp(temp->name,name) != 0){
   	 temp = temp->next;
    }
    return temp;
}

void LAppend(LSymbol *l1){
    l1->next = LSymbolHead;
    LSymbolHead = l1;
}

void AddLType(TypeTable *ltype, LSymbol *l){
    l->type = ltype;
}
