AST* TreeCreate(TypeTable *type, int nodetype, char *name, Constant value, AST *arglist, AST *t1, AST *t2, AST *t3) {
	AST *temp = (AST *)malloc(sizeof(AST));
	//TODO All type checking conditions goes here
	temp->Type = type;
	temp->Nodetype = nodetype;
	temp->Value = value;
	if(name != NULL){
   		temp->Name = (char *)malloc(sizeof(name));
   		strcpy(temp->Name,name);
    }else
    {
   		temp->Name = NULL;     
    }
    temp->ArgList = arglist;
    temp->Ptr1 = t1;
    temp->Ptr2 = t2;
    temp->Ptr3 = t3;
    
    temp->Gentry = NULL;
    temp->Lentry = NULL;
    return temp;
}

AST* TreeAppend(AST *t, AST *t1, AST *t2, AST *t3) {
	if(t == NULL){
		return NULL;
	}
	t->Ptr1 = t1;
	t->Ptr2 = t2;
	t->Ptr3 = t3;
	return t;
}

memstruct interpret(AST *t) {

}