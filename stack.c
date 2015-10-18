void initialise_stack(){
	stack_top = -1;
	int i = 0;
	for (i = 0; i < STACK_SIZE; ++i)
	{
		stack[i] = (memstruct){MEMSTRUCT_EMPTY};
	}
}

void push(memstruct value){
	if(stack_top + 1 < STACK_SIZE){
		stack_top++;
		stack[stack_top] = value;
		return 1;
	}
	return 0;	//stack overflow
}

memstruct pop(){
	if(stack_top >= 0){
		memstruct temp = stack[stack_top];
		stack_top--;
		return temp;
	}
	return (memstruct){MEMSTRUCT_EMPTY};
}