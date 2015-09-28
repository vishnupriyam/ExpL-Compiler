ASTNode* Treecreate(TypeTable *type, int nodetype, char *name, Constant value, ASTNode *arglist, ASTNode *t1, ASTNode *t2, ASTNode *t3) {
	ASTNode *temp = (ASTNode *)malloc(sizeof(ASTNode));
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

ASTNode* TreeAppend(ASTNode *t, ASTNode *t1, ASTNode *t2, ASTNode *t3) {
	if(t == NULL){
		return NULL;
	}
	t->Ptr1 = t1;
	t->Ptr2 = t2;
	t->Ptr3 = t3;
	return t;
}

memstruct interpret(ASTNode *t) {

}