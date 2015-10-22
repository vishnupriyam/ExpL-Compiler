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
        yyerror("Tlookup : Cannot look up for an identifier with type NULL in type table ");
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
        yyerror("Tinstall : type redefined ");
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
    //TODO negative bind for each argument
    //TODO install the argument in local symbol table also
    return temp;
}

ArgStruct* ArgAppend(ArgStruct *arg1, Argstruct *arg2){
    Argtemp = arg2;
    while (Argtemp->next != NULL) {
      Argtemp = Argtemp->next;
    }
    Argtemp->next = arg1;
    return arg2;
}

void AddArgType(TypeTable *type, Argstruct *arg){
    ArgStruct *temp = arg;
    while(temp != NULL){
        temp->type = type;
        temp = temp->next;
    }
    Argtemp->next = ArgStructHead;
    ArgStructHead = arg;
}

GSymbol* GInstall(char*name, TypeTable *type, int size, Argstuct *arglist){
    if(Glookup(name) != NULL)	//error on redefining the variable
	  {
        yyerror("GInstall : Global variable redefined ");
        printf(" %s",name);
        exit(1);
    }
    GSymbol *temp = (GSymbol *)malloc(sizeof(GSymbol));
    temp->name =  (char *)malloc(sizeof(name));
    strcpy(temp->name,name);
    temp->type = type;
    temp->size = size;
    if(arglist != NULL){
        size = 0;
        Argtemp = arglist;
        while(Argtemp != NULL){
            size = size + 1;
            Argtemp = Argtemp->next;
        }
        temp->size = size;
    }
    temp->arglist = arglist;
    temp->next = NULL;
    return temp;
}

void GAppend(GSymbol *g1){
    Gtemp = g1;
    while (Gtemp->next != NULL) {
      if(Gtemp->arglist == NULL && Gtemp->size != 0){
          Gtemp->binding = gbinding;
          gbinding = gbinding + Gtemp->size;
      }
      else{
          Gtemp->binding = -1;
      }
      Gtemp = Gtemp->next;
    }
    Gtemp->next = GSymbolHead;
    GSymbolHead = g1;
}

GSymbol* Glookup(char *name){
    if(name == NULL){
        yyerror("Glookup : Cannot look up for an identifier with name NULL in global symbol table ");
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
    GSymbol *temp = g;
    while(temp != NULL){
        temp->type = gtype;
        temp = temp->next;
    }
}

LSymbol* LInstall(char *name, TypeTable *type){
    /*if(Llookup(name) != NULL)	//error on redefining the variable
	  {
        yyerror("LInstall : Local variable redefined ");
        printf(" %s",name);
        exit(1);
    }*/
    LSymbol *temp = (LSymbol *)malloc(sizeof(LSymbol));
    temp->name =  (char *)malloc(sizeof(name));
    strcpy(temp->name,name);
    temp->type = type;
    temp->next = NULL;
    return temp;
}

LSymbol* Llookup(char *name){
    if(name == NULL){
        yyerror("Llookup : Cannot look up for an identifier with name NULL in local symbol table ");
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

LSymbol *LlookupInTable(LSymbol *LSymbolHead, char *name) {
    if(name == NULL){
        yyerror("Llookup : Cannot look up for an identifier with name NULL in local symbol table ");
        printf(" %s",name);
        exit(1);
    }
    Ltemp = LSymbolHead;
    while(Ltemp != NULL && strcmp(Ltemp->name,name) != 0){
     temp = temp->next;
    }
    return temp;
}

LSymbol* LAppend(LSymbol *l1, LSymbol *l2){
    Ltemp = l2;
    while (Ltemp->next != NULL) {
      if(LlookupInTable(l1, Ltemp->name) != NULL){
        yyerror("LInstall : Local variable redefined ");
        printf(" %s",Ltemp->name);
        exit(1);
      }
      Ltemp = Ltemp->next;
    }
    Ltemp->next = l1;
    return l2;
    /*l1->next = LSymbolHead;
    if(LSymbolHead == NULL){
        l1->binding = 1;
    }
    else{
        l1->binding = LSymbolHead->binding + 1;
    }
    LSymbolHead = l1;
    return LSymbolHead;*/
}

void setLocalBindings(LSymbol *LSymbolHead) {
    Ltemp = LSymbolHead;
    int Lbinding = LOCAL_START_BIND;
    while(Ltemp != NULL){
      Ltemp->binding = binding;
      Lbinding++;
      Ltemp = Ltemp->next;
    }
}

void AddLType(TypeTable *ltype, LSymbol *l){
    LSymbol *temp = l;
    while( temp != NULL){
        temp->type = ltype;
        temp = temp->next;
    }
}

void validate_funtion(char *fname,Typetable *rtype, ArgStruct *arglist, ASTNode *body){
    //check function is declared
    Gtemp = Glookup(fname);
    if(Gtemp == NULL){
        yyerror("validate_function : function has not been declared");
        printf(" %s",fname);
        exit(1);
    }

    //compare the return type as declared and as from the body of the function
    if(!(Gtemp->type == rtype && body->type == rtype)){
        yyerror("validate_function : return type doesnot match with definition or with return type of body");
        printf("%s\n",fname);
        exit(1);
    }

    //compare the type and names of the arguments as in the sequence of declaration
    ArgStruct *temp1,*temp2;
    temp1 = Gtemp->arglist;
    temp2 = arglist;
    while(temp1 != NULL && temp2 != NULL){
        if(strcmp(temp1->name,temp2->name) != 0){
            yyerror("validate_function : argument names donot match");
            printf("%s\n",fname);
            exit(1);
        }

        if(strcmp(temp1->type->name,temp2->type->name) != 0){
            yyerror("validate_function : type of arguments donot match");
            printf("%s\n",fname);
            exit(1);
        }

        if(temp1->passType != temp2->passType){
            yyerror("validate_function : passType of arguments donot match");
            printf("%s\n",fname);
            exit(1);
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if(temp1 != NULL || temp2 != NULL ){
        yyerror("validate_function: no of arguments donot match");
        printf("%s\n",fname);
        exit(1);
    }
}

void AddArgsToLTable(LSymbol **LSymbolHead, ArgStruct *a){
    int argLength = ArgLength(a);
    int ArgBind = ARG_START_BIND + argLength;
    while(a != NULL){
        if(LlookupInTable(*LSymbolHead, a->name) != NULL){
          yyerror("LInstall : Local variable redefined ");
          printf(" %s",a->name);
          exit(1);
        }
        Ltemp = LInstall(a->name,a->type);
        Ltemp->next = *LSymbolHead;
        Ltemp->binding = ArgBind;
        ArgBind++;
        *LSymbolHead = Ltemp;
        a = a->next;
    }
}

int ArgLength(ArgStruct *a){
    int len = 0;
    while(a != NULL){
        len++;
        a = a->next;
    }
    return len;
}

fieldList* FInstall(char *name){
    if(FieldLookup(name) != NULL){
        yyerror("FInstall : multiple declarations of same field");
        printf(" %s",name);
        exit(1);
    }
    fieldList *temp = (fieldList *)malloc(sizeof(fieldList));
    temp->name =  (char *)malloc(sizeof(name));
    strcpy(temp->name,name);
    return temp;
}

void AddFType(TypeTable *type, fieldList *f){
    fieldList temp = f;
    while(temp != NULL){
        temp->type = type;
        f = f->next;
    }
}

fieldList* FAppend(fieldList *f1, fieldList *f2){
    ftemp = f2;
    while (ftemp->next != NULL) {
       ftemp = ftemp->next;
    }
    ftemp->next = f1;
    return f2;
}

fieldList* FieldLookup(char *name){
    if(name == NULL){
        yyerror("Flookup : Cannot look up for an identifier with name NULL in local symbol table ");
        printf(" %s",name);
        exit(1);
    }
    fieldList *temp;
    temp = fieldListHead;
    while(temp != NULL && strcmp(temp->name,name) != 0){
   	    temp = temp->next;
    }
    return temp;
}

void Type_field_list_validate(fieldList *f){
    fieldList *temp = f;
    while(temp != NULL){
        if(TLookUp(temp->type) == NULL){
            yyerror("Type_field_list_validate : the field type has not been declared previously");
            printf(" %s",temp->type->name);
            exit(1);
        }
    }
}

int fieldRelativeAddress(TypeTable *t, char *name) {
    ftemp = t->fields;
    int relBind = 0;
    while(strcmp(ftemp->name,name) != 0){
      relBind++;
      ftemp = ftemp->next;
    }
    return relBind;
}

int isUserDefinedtype(TypeTable *t){
    if(strcmp(t->name,"int") == 0 || strcmp(t->name,"str")==0 || strcmp(t->name,"void")== 0 || strcmp(t->name,"boolean")==0 ){
        return 0;
    }
    else
        return 1;
}

int sizeoftype(TypeTable *t){
    if(strcmp(t->name,"int") == 0 || strcmp(type->name,"str") == 0){
        return 1;
    }
    else{
        int size = 0;
        fieldList *temp;
        temp = type->fields;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }
        return size;
    }
}
