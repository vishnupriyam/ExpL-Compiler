AST* TreeCreate(struct TypeTable *type, int nodetype, char *name, Constant value, AST *arglist, AST *t1, AST *t2, AST *t3) {
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
	temp->Gentry = NULL;
	temp->Lentry = NULL;

	switch(nodetype){
		case NODETYPE_ASGN	: setVariableType(t1, IS_ARRAY_FALSE);
							  if(!(strcmp(t1->type->name,t2->type->name) == 0 || (!(isUserDefinedtype(t1->type) && strcmp(t2->type->name,"null"))))){
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
								if(!(strcmp(t1->type->name, t2->type->name) == 0 || (isUserDefinedtype(t1->type) && (strcmp(t2->type->name,"null") == 0)))){
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
		 case NODETYPE_READ :
 								setVariableType(t1, IS_ARRAY_FALSE);
 								if(strcmp(t1->type->name,"str") != 0 && strcmp(t1->type->name,"int") != 0){
 									yyerror("TreeCreate : invalid operation on a non primitive type");exit(1);
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
		case NODETYPE_ID 	   : //setVariableType(temp, IS_ARRAY_FALSE);
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
								if(Gtemp->arglist == NULL && Gtemp->size > 0){
									yyerror("TreeCreate : invalid usage of an identifier as a function ");exit(1);
								}
							  ArgStruct *temp1;
							  AST *temp2;
							  temp1 = Gtemp->arglist;
							  temp2 = arglist;
							  while(temp1 != NULL && temp2 != NULL){
									if(strcmp(temp1->type->name,temp2->ptr2->type->name) != 0){
										yyerror("TreeCreate : types of arguments passed to function donot match ");exit(1);
									}
								  //TODO check for passType

								  temp1 = temp1->next;
								  temp2 = temp2->ptr1;
							  }
							  if(temp1 != NULL || temp2 != NULL){
								  yyerror("TreeCreate : mismatch in the number of arguments given");exit(1);
							  }
							  temp->Gentry = Gtemp;
							  break;

		case NODETYPE_MAIN :  if(strcmp(t1->ptr2->type->name,"int") != 0){
								yyerror("TreeCreate : the return type of main is not int type !");exit(1);
							  }
							  break;
	}
		temp->ptr1 = t1;
		temp->ptr2 = t2;
		temp->ptr3 = t3;
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

void setVariableType(AST *t, int isArray){
	if(t->nodetype == NODETYPE_FIELD){
		while(t->ptr1 != NULL){
			t = t->ptr1;
		}
	}
	Ltemp = Llookup(t->name);
	if(Ltemp == NULL || isArray){
		Gtemp = Glookup(t->name);
		if(Gtemp == NULL){
			 yyerror("TreeCreate : variable undefined !");
			 printf("\n%s",t->name);
			 exit(1);
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

int getFieldBind(AST *t, int flag){
	if(t->nodetype == NODETYPE_FIELD){
		if(flag == FLAG_FBIND_VALUE){
			 	memstruct temp;
				temp = getValueAtDynamicLocation(getFieldBind(t->ptr1,FLAG_FBIND_VALUE) + fieldRelativeAddress(t->ptr1->type, t->ptr2->name));
				if(temp.type != MEMSTRUCT_BIND){
					yyerror("getFieldBind: Invalid access to the memory");exit(1);
				}
				return temp.value.intval;
		}
		else
			 	return getFieldBind(t->ptr1,FLAG_FBIND_VALUE) + fieldRelativeAddress(t->ptr1->type, t->ptr2->name);
	}
	if(t->nodetype == NODETYPE_ID){
			 if(t->Lentry != NULL){
				 	if(getLocalValue(t->Lentry->binding).type != MEMSTRUCT_BIND){
						yyerror("getFieldBind: Invalid access to the memory");exit(1);
					}
				 	return t->Lentry->binding;
			 }
			 else {
				 if(getGlobalValue(t->Gentry->binding).type != MEMSTRUCT_BIND){
					 yyerror("getFieldBind: Invalid access to the memory");exit(1);
				 }
				 return t->Gentry->binding;
			 }
	}
}

struct memstruct interpret(AST *t) {
	memstruct result1, result2;
	AST *values;
	ArgStruct *params;
	int address, iTemp,mem_location;
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
							if(strcmp(t->ptr1->type->name,"null") == 0)
								return (memstruct){MEMSTRUCT_INT, result2.type == MEMSTRUCT_EMPTY};
							else if(strcmp(t->ptr2->type->name,"null") == 0){
								return (memstruct){MEMSTRUCT_INT, result1.type == MEMSTRUCT_EMPTY};
							}
							else if(strcmp(t->ptr1->type->name, "str") == 0)
								return (memstruct){MEMSTRUCT_INT, strcmp(result1.value.strval, result2.value.strval) == 0};
							else if(strcmp(t->ptr1->type->name,"int") == 0)
								return (memstruct){MEMSTRUCT_INT, result1.value.intval == result2.value.intval};

							break;
		case NODETYPE_NE	:
							result1 = getValueFromBind(interpret(t->ptr1));
							result2	= getValueFromBind(interpret(t->ptr2));
							if(strcmp(t->ptr1->type->name,"null") == 0)
								return (memstruct){MEMSTRUCT_INT, result2.type != MEMSTRUCT_EMPTY};
							else if(strcmp(t->ptr2->type->name,"null") == 0)
								return (memstruct){MEMSTRUCT_INT, result1.type != MEMSTRUCT_EMPTY};
							else if(strcmp(t->ptr1->type->name, "str") == 0)
								return (memstruct){MEMSTRUCT_INT, strcmp(result1.value.strval, result2.value.strval) != 0};
							else if(strcmp(t->ptr1->type->name,"int") == 0)
								return (memstruct){MEMSTRUCT_INT, result1.value.intval != result2.value.intval};
							break;
		case NODETYPE_AND	:
							result1 = getValueFromBind(interpret(t->ptr1));
							result2 = getValueFromBind(interpret(t->ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval && result2.value.intval};
							break;
		case NODETYPE_OR	:
							result1 = getValueFromBind(interpret(t->ptr1));
							result2 = getValueFromBind(interpret(t->ptr2));
							return (memstruct){MEMSTRUCT_INT, result1.value.intval || result2.value.intval};
							break;
		case NODETYPE_NOT	:
							result1 = getValueFromBind(interpret(t->ptr1));
							result1.value.intval = !(result1.value.intval);
							return result1;
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
							if(result2.value.intval >= t->ptr1->Gentry->size){
								yyerror("interpret: index out of bounds");exit(1);
							}
							assignGlobalValue(t->ptr1->Gentry->binding + result2.value.intval, result1);
							break;
		case NODETYPE_FIELD_ASGN	:
							result1 = interpret(t->ptr2);
							int mem_location = getFieldBind(t->ptr1, FLAG_FBIND_ADDRESS);
							setValueAtDynamicLocation(mem_location,result1);
							break;
		case NODETYPE_READ	:
							if(strcmp(t->ptr1->type->name, "int")==0){
								result1.type = MEMSTRUCT_INT;
								scanf("%d", &result1.value.intval);
							} else {
								result1.type = MEMSTRUCT_STR;
								result1.value.strval = (char *)malloc(sizeof(char)*16);
								scanf("%s", result1.value.strval);
							}
							if(t->ptr1->Lentry != NULL){
								assignLocalValue(t->ptr1->Lentry->binding, result1);
							}
							else {
								assignGlobalValue(t->ptr1->Gentry->binding, result1);
							}
							break;
		case NODETYPE_ARR_READ	:
							if(strcmp(t->ptr1->type->name, "int")==0){
								result1.type = MEMSTRUCT_INT;
								scanf("%d", &result1.value.intval);
							} else {
								result1.type = MEMSTRUCT_STR;
								result1.value.strval = (char *)malloc(sizeof(char)*16);
								scanf("%s", result1.value.strval);
							}
							result2 = getValueFromBind(interpret(t->ptr2));
							if(result2.value.intval >= t->ptr1->Gentry->size){
								yyerror("interpret: index out of bounds");exit(1);
							}
							assignGlobalValue(t->ptr1->Gentry->binding + result2.value.intval, result1);
							break;
		case NODETYPE_WRITE	:
							result1 = getValueFromBind(interpret(t->ptr1));
							if(strcmp(t->ptr1->type->name, "int")==0){
								printf("%d\n", result1.value.intval);
							} else {
								printf("%s\n", result1.value.strval);
							}
							break;
		case NODETYPE_IF	:
							result1 = getValueFromBind(interpret(t->ptr1));
							if(result1.value.intval){
									interpret(t->ptr2);
							}
							else if(t->ptr3 != NULL){
									interpret(t->ptr3);
							}
							break;
		case NODETYPE_WHILE	:
							result1 = getValueFromBind(interpret(t->ptr1));
							while (result1.value.intval) {
									interpret(t->ptr2);
									result1 = getValueFromBind(interpret(t->ptr1));
							}
							break;
		case NODETYPE_NONE	:
							interpret(t->ptr1);
							interpret(t->ptr2);
							break;
		case NODETYPE_ARR_ID	:
							result1 = getValueFromBind(interpret(t->ptr2));
							return getGlobalValue(t->ptr1->Gentry->binding + result1.value.intval);
							break;
		case NODETYPE_ALLOC :
							address = allocate(sizeoftype(t->ptr1->type));
							if(address == -1){
								yyerror("Interpret: Unable to create memory for the variable");
								exit(1);
							}
							if(t->ptr1->nodetype == NODETYPE_FIELD){
								mem_location = getFieldBind(t->ptr1,FLAG_FBIND_ADDRESS);
								setValueAtDynamicLocation(mem_location,(memstruct){MEMSTRUCT_BIND,address});
							}
							else{
								if(t->ptr1->Lentry != NULL){
									assignLocalValue(t->ptr1->Lentry->binding, (memstruct){MEMSTRUCT_BIND, address});
								}
								else if(t->ptr1->Gentry != NULL){
									assignGlobalValue(t->ptr1->Gentry->binding, (memstruct){MEMSTRUCT_BIND, address});
								}
							}
							break;
		case NODETYPE_DEALLOC :
							if(t->ptr1->Lentry != NULL){
								address = getLocalValue(t->ptr1->Lentry->binding).value.intval;
							}
							else {
								address = getGlobalValue(t->ptr1->Gentry->binding).value.intval;
							}
							if(deallocate(address) == -1){
								yyerror("Interpret: Unable to free memory for the variable");
								exit(1);
							}
							break;
		case NODETYPE_BODY  :
							interpret(t->ptr1);
							interpret(t->ptr2);
							break;
		case NODETYPE_MAIN	:
							initialise_stack();
							initialise_memory();
							Gtemp = GSymbolHead;
							while(Gtemp != NULL){
								iTemp = Gtemp->size;
								while(iTemp--){
									push((memstruct){MEMSTRUCT_EMPTY});
								}
								Gtemp = Gtemp->next;
							}
							set_BP_to_SP();
		case NODETYPE_FUNCTION :
							values = t->arglist;
							params = t->Gentry->arglist;
							while(values != NULL){
								if(params->passType != PASS_BY_REF && !isUserDefinedtype(params->type)){
									push(interpret(values->ptr2));
								}
								else if(params->passType == PASS_BY_REF || isUserDefinedtype(params->type)){
									//TODO the argument is primitive type and is passed by reference
								}
								values = values->ptr1;
								params = params->next;
							}
							//push return value
							push((memstruct){MEMSTRUCT_EMPTY});

							//push current base_pointer and set it to stack_pointer
							push_BP();

							Ltemp = t->Gentry->fbinding->Lentry;
							while(Ltemp != NULL){
								push((memstruct){MEMSTRUCT_EMPTY});
								Ltemp = Ltemp->next;
							}

							interpret(t->Gentry->fbinding);

							Ltemp = t->Gentry->fbinding->Lentry;
							while(Ltemp != NULL){
								pop();
								Ltemp = Ltemp->next;
							}

							pop_BP();
							result1 = pop();
							//pop all the arguments
							params = t->Gentry->arglist;
							while(params != NULL){
								pop();
								params = params->next;
							}
							//return the stored result
							return result1;
							break;
		case NODETYPE_RET	:
							result1 = interpret(t->ptr1);
							if(isUserDefinedtype(t->type)){
								setFunctionReturnValue((memstruct){MEMSTRUCT_BIND, result1.value.intval});
							}
							else if(strcmp(t->type->name,"int") == 0){
								setFunctionReturnValue((memstruct){MEMSTRUCT_INT, result1.value.intval});
							}
							else if(strcmp(t->type->name,"str") == 0) {
								Constant val;
								val.strval = result1.value.strval;
								setFunctionReturnValue((memstruct){MEMSTRUCT_STR, val});
							}
							break;
		case NODETYPE_FIELD :
							mem_location = getFieldBind(t,FLAG_FBIND_ADDRESS);
							return (memstruct){MEMSTRUCT_BIND,mem_location};
							break;
		case NODETYPE_NULL :
							return (memstruct){MEMSTRUCT_EMPTY};
							break;
		default :
							yyerror("invalid node type : ");
							printf("nodetype %d\n",t->nodetype);
							exit(1);
							break;

	}


}
