AST* TreeCreate(TypeTable *type, int nodetype, char *name, Constant value, AST *arglist, AST *t1, AST *t2, AST *t3) {
	AST *temp = (AST *)malloc(sizeof(AST));
	
	if(name != NULL){
   		temp->Name = (char *)malloc(sizeof(name));
   		strcpy(temp->Name,name);
    }else
    {
   		temp->Name = NULL;
    }
    
    temp->Type = type;
	temp->Nodetype = nodetype;
	temp->Value = value;
	temp->ArgList = arglist;
    temp->Ptr1 = t1;
    temp->Ptr2 = t2;
    temp->Ptr3 = t3;
	temp->Gentry = NULL;
    temp->Lentry = NULL;

	switch(nodetype){
		case NODETYPE_PLUS	:
		case NODETYPE_MINUS :
		case NODETYPE_MUL	:
		case NODETYPE_DIV	:
		case NODETYPE_MOD	: if(strcmp(t1->Type->name,t2->Type->name) != 0 || strcmp(t1->Type->name,"int") != 0){
								 yyerror( "TreeCreate : unexpected operand types for nodetype plus/minus/div/mod/mul");exit(1);
							  }
							  break;
		case NODETYPE_GT	:
		case NODETYPE_LT	:
		case NODETYPE_GE	:
		case NODETYPE_LE	: if(strcmp(t1->Type->name,t2->Type->name) != 0 || strcmp(t1->Type->name,"int") != 0){
								yyerror("TreeCreate : unexpected operand types for nodetype gt/lt/ge/le");exit(1);
							  }
							  break;
		case NODETYPE_EQ	:
		case NODETYPE_NE	: if(!(strcmp(t1->Type->name,t2->Type->name) == 0 && (strcmp(t1->Type->name,"int") == 0 || strcmp(t1->Type->name,"boolean") == 0) || strcmp(t1->Type->name,"str") == 0)){
								yyerror("TreeCreate : unexpected operand types for nodetype eq/ne");exit(1);
							  }
							  break;
		case NODETYPE_ASGN	: setVariableType(t1, IS_ARRAY_FALSE);
							  if(strcmp(t1->Type->name,t2->Type->name) != 0){
								yyerror("TreeCreate : unexpected operand types for nodetype assignment");exit(1);
							  }
							  break;
		case NODETYPE_ARR_ASGN : 
								setVariableType(t1, IS_ARRAY_TRUE);
								if(strcmp(t2->Type->name,"int") != 0 || strcmp(t1->Type->name,t3->Type->name) != 0){
									yyerror("TreeCreate : unexpected types for node type array assignment");exit(1);
							     }
								 break;
		case NODETYPE_ARR_READ :
								setVariableType(t1, IS_ARRAY_TRUE);
								if(strcmp(t1->Type->name,"str") != 0 && strcmp(t1->Type->name,"int") != 0){
									yyerror("TreeCreate : invalid operation on a non primitive type array member");exit(1);
								}
								if(strcmp(t2->Type->name,"int") != 0 ){
									yyerror("TreeCreate : unexpected types for node type array read");exit(1);
							     }
								 break;
		case NODETYPE_WRITE		:
								if(strcmp(t1->Type->name,"str") != 0 && strcmp(t1->Type->name,"int") != 0){
									yyerror("TreeCreate : write operation on a non primitive type variable");exit(1);
								}
								break;
		case NODETYPE_ARR_ID 	: 
								if(strcmp(t2->Type->name,"int") != 0){
									yyerror("TreeCreate : unexpected operand type for node type arr_id");exit(1);
								}
								setVariableType(t1, IS_ARRAY_TRUE);
								temp->Type = t1->Type;
								break;
		case NODETYPE_ID 	   : setVariableType(temp, IS_ARRAY_FALSE);
								 break;
		case NODETYPE_FIELD	:	if(t1->Nodetype == NODETYPE_ID){
									setVariableType(t1, IS_ARRAY_FALSE);
									if(t1->Gentry != NULL){
										ftemp = FLookUp(t1->Gentry->type->name, t2->Name);
									}
									else {
										ftemp = FLookUp(t1->Lentry->type->Name, t2->Name);
									}
								}
								else if(t1->Nodetype == NODETYPE_FIELD)
									ftemp = FLookUp(t1->Type->name, t2->Name);
	                            if(ftemp == NULL){
	                                yyerror("Undefined user defined variable");exit(1);
	                            }
	                            temp->Type = ftemp->type;
								break;
		case NODETYPE_IF 	: if(t1->Type != TLookUp("boolean")){
								yyerror(" TreeCreate : unexpected type of expression in if");exit(1);
							  }
							  break;
		case NODETYPE_WHILE : if(t1->Type != TLookUp("boolean")){
								yyerror(" TreeCreate : unexpected type of expression in while");exit(1);
							  }
							  break;
		case NODETYPE_ALLOC : 
							setVariableType(t1, IS_ARRAY_FALSE);
							if(!isUserDefinedtype(t1->Type)){
							  	yyerror("TreeCreate : variable is not user defined type");exit(1);
							}
							break;
		case NODETYPE_DEALLOC : 
							setVariableType(t1, IS_ARRAY_FALSE);
							if(!isUserDefinedtype(t1->Type)){
							  	yyerror("TreeCreate : variable is not user defined type");exit(0);
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

		case NODETYPE_MAIN :  if(strcmp(t1->t2->Type->name,"int") != 0){
								yyerror("TreeCreate : the return type of main is not int type !");exit(0);
							  }
							  break;
	}

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

memstruct getValueFromBind(memstruct bind){
	if(bind.type == MEMSTRUCT_BIND){
		return heap[bind.value.intval];
	}
	return bind;
}

void setVariableType(AST *t, int isArray){
	Ltemp = Llookup(t->Name);
	if(Ltemp == NULL || isArray){
		Gtemp = Glookup(t->Name);
		if(Gtemp == NULL){
			 yyerror("TreeCreate : variable undefined !");exit(1);
		}
		else{
			t->Gentry = Gtemp;
			t->Type = Gtemp->type;
		}
	}
	else if(!isArray){
		t->Lentry = Ltemp;
		t->Type = Ltemp->type;
	}
}

memstruct interpret(AST *t) {
	memstruct result1, result2;
	switch(t->Nodetype){
		case NODETYPE_PLUS : 
							result1 = getValueFromBind(interpret(t->Ptr1));
							result2	= getValueFromBind(interpret(t->Ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval + result2.value.intval};						
							break;
		case NODETYPE_MINUS : 
							result1 = getValueFromBind(interpret(t->Ptr1));
							result2	= getValueFromBind(interpret(t->Ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval - result2.value.intval};
							break;
		case NODETYPE_MUL	: 
							result1 = getValueFromBind(interpret(t->Ptr1));
							result2	= getValueFromBind(interpret(t->Ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval * result2.value.intval};
							break;
		case NODETYPE_DIV	: 
							result1 = getValueFromBind(interpret(t->Ptr1));
							result2	= getValueFromBind(interpret(t->Ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval / result2.value.intval};
							break;
		case NODETYPE_MOD	:
							result1 = getValueFromBind(interpret(t->Ptr1));
							result2	= getValueFromBind(interpret(t->Ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval % result2.value.intval};
							break;
		case NODETYPE_GT	:
							result1 = getValueFromBind(interpret(t->Ptr1));
							result2	= getValueFromBind(interpret(t->Ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval > result2.value.intval};
							break;
		case NODETYPE_LT	:
							result1 = getValueFromBind(interpret(t->Ptr1));
							result2	= getValueFromBind(interpret(t->Ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval < result2.value.intval};
							break;
		case NODETYPE_GE	:
							result1 = getValueFromBind(interpret(t->Ptr1));
							result2	= getValueFromBind(interpret(t->Ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval >= result2.value.intval};
							break;
		case NODETYPE_LE	:
							result1 = getValueFromBind(interpret(t->Ptr1));
							result2	= getValueFromBind(interpret(t->Ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval <= result2.value.intval};
							break;
		case NODETYPE_EQ	:
							result1 = getValueFromBind(interpret(t->Ptr1));
							result2	= getValueFromBind(interpret(t->Ptr2));
							if(strcmp(t->Ptr1->Type, "str") == 0)
								return (memstruct){MEMSTRUCT_INT, strcmp(result1.value.strval, result2.value.strval) == 0};	
							else 
								return (memstruct){MEMSTRUCT_INT, result1.value.intval == result2.value.intval};
							break;
		case NODETYPE_NE	:
							result1 = getValueFromBind(interpret(t->Ptr1));
							result2	= getValueFromBind(interpret(t->Ptr2));
							if(strcmp(t->Ptr1->Type, "str") == 0)
								return (memstruct){MEMSTRUCT_INT, strcmp(result1.value.strval, result2.value.strval) != 0};	
							else 
								return (memstruct){MEMSTRUCT_INT, result1.value.intval != result2.value.intval};
							break;
	}

}
