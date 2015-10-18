#define STACK_SIZE 1024
memstruct stack[STACK_SIZE];

int stack_top = -1;

void initialise_stack();
int push(memstruct value);	//0 for failure, 1 for success
memstruct pop();