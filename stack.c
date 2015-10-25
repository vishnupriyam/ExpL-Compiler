void initialise_stack(){
	stack_pointer = -1;
	int i = 0;
	for (i = 0; i < STACK_SIZE; ++i)
	{
		stack[i] = (memstruct){MEMSTRUCT_EMPTY};
	}
}

int push(memstruct value){
	if(stack_pointer + 1 < STACK_SIZE){
		stack_pointer++;
		stack[stack_pointer] = value;
		return 1;
	}
	return 0;	//stack overflow
}

void push_BP(){
	push((memstruct){MEMSTRUCT_BIND, base_pointer});
	base_pointer = stack_pointer;
}

void pop_BP() {
	base_pointer = pop().value.intval;
}

void set_BP_to_SP(){
	base_pointer = stack_pointer;
}

memstruct pop(){
	if(stack_pointer >= 0){
		memstruct temp = stack[stack_pointer];
		stack_pointer--;
		return temp;
	}
	return (memstruct){MEMSTRUCT_EMPTY};	//stack underflow
}

memstruct getLocalValue(int location){
	return stack[base_pointer + location];
}

memstruct getGlobalValue(int location) {
	return stack[GLOBAL_INDEX + location];
}

void assignLocalValue(int location, memstruct value){
	stack[base_pointer + location] = value;
}

void assignGlobalValue(int location, memstruct value) {
	stack[GLOBAL_INDEX + location] = value;
}

void setFunctionReturnValue(memstruct value) {
	stack[base_pointer + RELATIVE_RETURN_ADDRESS] = value;
}
