#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 1024
#define MIN_BLOCK_SIZE 8
#define MAX_BLOCK_SIZE HEAP_SIZE/2

memstruct heap[HEAP_SIZE];

void initialise_memory();
void print_memory_freelist();
int ceil2(int size);
int get_free_list(int size);
int find_free_list_size(int size);
void add_to_list(int free_list, int addr);
void remove_from_list(int free_list, int free_list_size, int addr);
int get_free_block(int free_list,int list_size);
int split_rec(int current_list, int list_size, int current_size, int required_size);
int allocate(int size);
void free_block(int start_addr,int size);
int find_free_buddy(int start_addr, int ceil_size);
int minimum(int x, int y);
void merge_buddies(int start_addr, int ceil_size);
int deallocate(int start_addr);
struct memstruct getValueFromBind(memstruct bind);
struct memstruct getValueAtDynamicLocation(int location);
void setValueAtDynamicLocation(int location, memstruct value);
