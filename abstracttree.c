AST* TreeCreate(TypeTable *type, int nodetype, char *name, Constant value, AST *arglist, AST *t1, AST *t2, AST *t3) {
	AST *temp = (AST *)malloc(sizeof(AST));

	if(name != NULL){
   		temp->name = (char *)malloc(sizeof(name));
   		strcpy(temp->name,name);
    }else
    {
   		temp->name = NULL;
    }

  temp->type = type;
	temp->nodetype = nodetype;
	temp->value = value;
	temp->arglist = arglist;
  temp->ptr1 = t1;
  temp->ptr2 = t2;
  temp->ptr3 = t3;
	temp->Gentry = NULL;
  temp->Lentry = NULL;

	switch(nodetype){
		case NODETYPE_PLUS	:
		case NODETYPE_MINUS :
		case NODETYPE_MUL	:
		case NODETYPE_DIV	:
		case NODETYPE_MOD	: if(strcmp(t1->type->name,t2->type->name) != 0 || strcmp(t1->type->name,"int") != 0){
								 yyerror( "TreeCreate : unexpected operand types for nodetype plus/minus/div/mod/mul");exit(1);
							  }
							  break;
		case NODETYPE_GT	:
		case NODETYPE_LT	:
		case NODETYPE_GE	:
		case NODETYPE_LE	: if(strcmp(t1->type->name,t2->type->name) != 0 || strcmp(t1->type->name,"int") != 0){
								yyerror("TreeCreate : unexpected operand types for nodetype gt/lt/ge/le");exit(1);
							  }
							  break;
		case NODETYPE_EQ	:
		case NODETYPE_NE	: if(!(strcmp(t1->type->name,t2->type->name) == 0 && (strcmp(t1->type->name,"int") == 0 || strcmp(t1->type->name,"boolean") == 0) || strcmp(t1->type->name,"str") == 0)){
									yyerror("TreeCreate : unexpected operand types for nodetype eq/ne");exit(1);
							  }
							  break;
		case NODETYPE_ASGN	: setVariableType(t1, IS_ARRAY_FALSE);
							  if(strcmp(t1->type->name,t2->type->name) != 0){
									yyerror("TreeCreate : unexpected operand types for nodetype assignment");exit(1);
							  }
							  break;
		case NODETYPE_ARR_ASGN :
								setVariableType(t1, IS_ARRAY_TRUE);
								if(strcmp(t2->type->name,"int") != 0 || strcmp(t1->type->name,t3->type->name) != 0){
									yyerror("TreeCreate : unexpected types for node type array assignment");exit(1);
								}
								break;
		case NODETYPE_FIELD_ASGN:
								if(strcmp(t1->type->name, t2->type->name) != 0){
									yyerror("TreeCreate : unexpected operand types for nodetype field asgn");exit(1);
								}
								break;
		case NODETYPE_ARR_READ :
								setVariableType(t1, IS_ARRAY_TRUE);
								if(strcmp(t1->type->name,"str") != 0 && strcmp(t1->type->name,"int") != 0){
									yyerror("TreeCreate : invalid operation on a non primitive type array member");exit(1);
								}
								if(strcmp(t2->type->name,"int") != 0 ){
									yyerror("TreeCreate : unexpected types for node type array read");exit(1);
							     }
								 break;
		case NODETYPE_WRITE		:
								if(strcmp(t1->type->name,"str") != 0 && strcmp(t1->type->name,"int") != 0){
									yyerror("TreeCreate : write operation on a non primitive type variable");exit(1);
								}
								break;
		case NODETYPE_ARR_ID 	:
								if(strcmp(t2->type->name,"int") != 0){
									yyerror("TreeCreate : unexpected operand type for node type arr_id");exit(1);
								}
								setVariableType(t1, IS_ARRAY_TRUE);
								temp->type = t1->type;
								break;
		case NODETYPE_ID 	   : setVariableType(temp, IS_ARRAY_FALSE);
								 break;
		case NODETYPE_FIELD	:	if(t1->nodetype == NODETYPE_ID){
									setVariableType(t1, IS_ARRAY_FALSE);
									if(t1->Gentry != NULL){
										ftemp = FLookUp(t1->Gentry->type->name, t2->name);
									}
									else {
										ftemp = FLookUp(t1->Lentry->type->name, t2->name);
									}
								}
								else if(t1->nodetype == NODETYPE_FIELD)
									ftemp = FLookUp(t1->type->name, t2->name);
	                            if(ftemp == NULL){
	                                yyerror("Undefined user defined variable");exit(1);
	                            }
	                            temp->type = ftemp->type;
								break;
		case NODETYPE_IF 	: if(t1->type != TLookUp("boolean")){
								yyerror(" TreeCreate : unexpected type of expression in if");exit(1);
							  }
							  break;
		case NODETYPE_WHILE : if(t1->type != TLookUp("boolean")){
								yyerror(" TreeCreate : unexpected type of expression in while");exit(1);
							  }
							  break;
		case NODETYPE_ALLOC :
							setVariableType(t1, IS_ARRAY_FALSE);
							if(!isUserDefinedtype(t1->type)){
							  	yyerror("TreeCreate : variable is not user defined type");exit(1);
							}
							break;
		case NODETYPE_DEALLOC :
							setVariableType(t1, IS_ARRAY_FALSE);
							if(!isUserDefinedtype(t1->type)){
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

		case NODETYPE_MAIN :  if(strcmp(t1->t2->type->name,"int") != 0){
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
	t->ptr1 = t1;
	t->ptr2 = t2;
	t->ptr3 = t3;
	return t;
}

memstruct getValueFromBind(memstruct bind){
	while(bind.type == MEMSTRUCT_BIND){
		bind = heap[bind.value.intval];
	}
	return bind;
}

void setVariableType(AST *t, int isArray){
	Ltemp = Llookup(t->name);
	if(Ltemp == NULL || isArray){
		Gtemp = Glookup(t->name);
		if(Gtemp == NULL){
			 yyerror("TreeCreate : variable undefined !");exit(1);
		}
		else{
			t->Gentry = Gtemp;
			t->type = Gtemp->type;
		}
	}
	else if(!isArray){
		t->Lentry = Ltemp;
		t->type = Ltemp->type;
	}
}

memstruct interpret(AST *t) {
	memstruct result1, result2;
	switch(t->nodetype){
		case NODETYPE_PLUS :
							result1 = getValueFromBind(interpret(t->ptr1));
							result2	= getValueFromBind(interpret(t->ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval + result2.value.intval};
							break;
		case NODETYPE_MINUS :
							result1 = getValueFromBind(interpret(t->ptr1));
							result2	= getValueFromBind(interpret(t->ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval - result2.value.intval};
							break;
		case NODETYPE_MUL	:
							result1 = getValueFromBind(interpret(t->ptr1));
							result2	= getValueFromBind(interpret(t->ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval * result2.value.intval};
							break;
		case NODETYPE_DIV	:
							result1 = getValueFromBind(interpret(t->ptr1));
							result2	= getValueFromBind(interpret(t->ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval / result2.value.intval};
							break;
		case NODETYPE_MOD	:
							result1 = getValueFromBind(interpret(t->ptr1));
							result2	= getValueFromBind(interpret(t->ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval % result2.value.intval};
							break;
		case NODETYPE_GT	:
							result1 = getValueFromBind(interpret(t->ptr1));
							result2	= getValueFromBind(interpret(t->ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval > result2.value.intval};
							break;
		case NODETYPE_LT	:
							result1 = getValueFromBind(interpret(t->ptr1));
							result2	= getValueFromBind(interpret(t->ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval < result2.value.intval};
							break;
		case NODETYPE_GE	:
							result1 = getValueFromBind(interpret(t->ptr1));
							result2	= getValueFromBind(interpret(t->ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval >= result2.value.intval};
							break;
		case NODETYPE_LE	:
							result1 = getValueFromBind(interpret(t->ptr1));
							result2	= getValueFromBind(interpret(t->ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval <= result2.value.intval};
							break;
		case NODETYPE_EQ	:
							result1 = getValueFromBind(interpret(t->ptr1));
							result2	= getValueFromBind(interpret(t->ptr2));
							if(strcmp(t->ptr1->type, "str") == 0)
								return (memstruct){MEMSTRUCT_INT, strcmp(result1.value.strval, result2.value.strval) == 0};
							else
								return (memstruct){MEMSTRUCT_INT, result1.value.intval == result2.value.intval};
							break;
		case NODETYPE_NE	:
							result1 = getValueFromBind(interpret(t->ptr1));
							result2	= getValueFromBind(interpret(t->ptr2));
							if(strcmp(t->ptr1->type, "str") == 0)
								return (memstruct){MEMSTRUCT_INT, strcmp(result1.value.strval, result2.value.strval) != 0};
							else
								return (memstruct){MEMSTRUCT_INT, result1.value.intval != result2.value.intval};
							break;
		case NODETYPE_ID	:
							if(t->Lentry != NULL){
								return getLocalValue(t->Lentry->binding);
							}
							else {
								return getGlobalValue(t->Gentry->binding);
							}
		 					break;
		case NODETYPE_LEAF	:
							if(strcmp(t->type->name,"str") == 0){
								return (memstruct){MEMSTRUCT_STR, t->value};
							}
							else {
								return (memstruct){MEMSTRUCT_INT, t->value};
							}
							break;
		case NODETYPE_ASGN	:
							result1 = interpret(t->ptr2);
							if(t->ptr1->Lentry != NULL){
								assignLocalValue(t->ptr1->Lentry->binding, result1);
							}
							else {
								assignGlobalValue(t->ptr1->Gentry->binding, result1);
							}
							break;
		case NODETYPE_ARR_ASGN	:
							result1 = interpret(t->ptr3);
							result2 = getValueFromBind(interpret(t->ptr2));
							if(result2.value.intval < t->ptr1->Gentry->size){
								yyerror("interpret: index out of bounds");exit(1);
							}
							assignGlobalValue(t->ptr1->Gentry->binding + result2.value.intval, result1);
							break;
		case NODETYPE_FIELD_ASGN	:
							result1 = interpret(t->ptr2);
							
							break;
	}


}
