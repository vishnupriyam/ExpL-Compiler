AST* TreeCreate(TypeTable *type, int nodetype, char *name, Constant value, AST *arglist, AST *t1, AST *t2, AST *t3) {
	AST *temp = (AST *)malloc(sizeof(AST));
	temp->Gentry = NULL;
    temp->Lentry = NULL;
	switch(nodetype){
		case NODETYPE_PLUS	:
		case NODETYPE_MINUS :
		case NODETYPE_MUL	:
		case NODETYPE_DIV	:
		case NODETYPE_MOD	: if(strcmp(t1->type->name,t2->type->name) != 0 || strcmp(t1->type->name,"int") != 0){
								 yyerror( "TreeCreate : unexpected operand types for nodetype plus/minus/div/mod/mul");exit(0);
							  }
							  break;
		case NODETYPE_GT	:
		case NODETYPE_LT	:
		case NODETYPE_GE	:
		case NODETYPE_LE	: if(strcmp(t1->type->name,t2->type->name) != 0 || strcmp(t1->type->name,"int") != 0){
								yyerror("TreeCreate : unexpected operand types for nodetype gt/lt/ge/le");exit(0);
							  }
							  break;
		case NODETYPE_EQ	:
		case NODETYPE_NE	: if(!(strcmp(t1->type->name,t2->type->name) == 0 && (strcmp(t1->type->name,"int") == 0 || strcmp(t1->type->name,"boolean") == 0) || strcmp(t1->type->name,"str") != 0)){
								yyerror("TreeCreate : unexpected operand types for nodetype eq/le");exit(0);
							  }
							  break;
		case NODETYPE_ASGN	: if(strcmp(t1->type->name,t2->type->name) != 0){
								yyerror("TreeCreate : unexpected operand types for nodetype assignment");exit(0);
							  }
							  break;
		case NODETYPE_ARR_ASGN : if(strcmp(t2->type->name,"int") != 0 || strcmp(t1->type->name,t3->type,name) != 0){
									yyerror("TreeCreate : unexpected types for node type array assignment");exit(0);
							     }
								 break;
		case NODETYPE_ARR_READ : if(strcmp(t2->type->name,"int") != 0 ){
									yyerror("TreeCreate : unexpected types for node type array read");exit(0);
							     }
								 break;
		case NODETYPE_ARR_ID 	: if(strcmp(t2->type->name,"int") != 0){
									yyerror("TreeCreate : unexpected operand type for node type arr_id");exit(0);
								  }
								  Gtemp = Glookup(t1->name);
								  if( Gtemp == NULL){
									yyerror("TreeCreate : undefined array variable");exit(0);
								  }
								  temp->Gentry = Gtemp;
								  type = Gtemp->type;
								  break;
		case NODETYPE_ID 	   : Ltemp = Glookup(name);
								 if(Ltemp == NULL){
									 Gtemp = Llookup(name);
									 if(Gtemp == NULL){
										 yyerror("TreeCreate : variable undefined !");exit(1);
									 }
									 else{
										 temp->Gentry = Gtemp;
										 type = Gtemp->type;
									 }
								 }
								 else{
									 temp->Lentry = Ltemp;
									 type = Ltemp->type;
								 }
								 break;
		case NODETYPE_FIELD	:	if(t1->Nodetype == NODETYPE_ID){
									Ltemp = Llookup(t1->Name);
									if(Ltemp == NULL){
										Gtemp = Glookup(t1->Name);
										if(Gtemp == NULL){
											 yyerror("TreeCreate : variable undefined !");exit(1);
										}
										else{
											t1->Gentry = Gtemp;
											t1->Type = Gtemp->type;
											ftemp = FLookUp(Gtemp->type->name, t2->Name);
										}
									}
									else{
										t1->Lentry = Ltemp;
										t1->Type = Ltemp->type;
										ftemp = FLookUp(Ltemp->type->Name, t2->Name);
									}
								}
								else if(t1->Nodetype == NODETYPE_FIELD)
									ftemp = FLookUp(t1->Type->name, t2->Name);
	                            if(ftemp == NULL){
	                                yyerror("Undefined user defined variable");exit(1);
	                            }
	                            type = ftemp->type;
								break;
		case NODETYPE_IF 	: if(t1->type != TLookUp("boolean")){
								yyerror(" TreeCreate : unexpected type of expression in if");exit(0);
							  }
							  break;
		case NODETYPE_WHILE : if(t1->type != TLookUp("boolean")){
								yyerror(" TreeCreate : unexpected type of expression in while");exit(0);
							  }
							  break;
		case NODETYPE_FUNCTION :
							  Gtemp = Glookup(name);
							  ArgStruct *temp1,*temp2;
							  temp1 = Gtemp->arglist;
							  temp2 = arglist;
							  while(temp1 != NULL && temp2 != NULL){
								  if(strcmp(temp1->type->name,temp2->type->name) != 0){
									  yyerror("TreeCreate : types of arguments passed to function donot match ");exit(0);
								  }
								  //TODO check for passType

								  temp1 = temp1->next;
								  temp2 = temp2->t1;
							  }
							  if(temp1 != NULL || temp2 != NULL){
								  yyerror("TreeCreate : mismatch in the number of arguments given");exit(0);
							  }
							  break;

		case NODETYPE_MAIN :  if(strcmp(t1->t2->type->name,"int") != 0){
								yyerror("TreeCreate : the return type of main is not int type !");exit(0);
							  }
							  break;


	}

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
