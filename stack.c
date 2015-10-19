void initialise_stack(){
	stack_pointer = -1;
	int i = 0;
	for (i = 0; i < STACK_SIZE; ++i)
	{
		stack[i] = (memstruct){MEMSTRUCT_EMPTY};
	}
}

void push(memstruct value){
	if(stack_pointer + 1 < STACK_SIZE){
		stack_pointer++;
		stack[stack_pointer] = value;
		return 1;
	}
	return 0;	//stack overflow
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
