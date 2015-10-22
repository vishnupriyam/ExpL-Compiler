#define STACK_SIZE 1024
#define GLOBAL_INDEX 0

memstruct stack[STACK_SIZE];

int stack_pointer = -1;
int base_pointer = -1;

void initialise_stack();
int push(memstruct value);	//0 for failure, 1 for success
memstruct pop();
void push_BP();
void pop_BP();
void set_BP_to_SP();
memstruct getLocalValue(int location);
memstruct getGlobalValue(int location);
void assignLocalValue(int location, memstruct value);
void assignGlobalValue(int location, memstruct value);
