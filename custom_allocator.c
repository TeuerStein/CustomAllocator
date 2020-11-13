#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

#define u8 uint8_t
#define u16 uint16_t
#define STACK_SIZE 32
#define HEAP_SIZE STACK_SIZE * 4
#define HEADER 4

typedef struct virtual_memory {
    u8 stack[STACK_SIZE];
    char** unmapped;
    u8 heap[HEAP_SIZE];
    
    struct {
        char** data;
        char** bss;
        char* text;
    }data_t;
}virtual_memory_t;

typredef struct entity {
    /* interface for using our heap */
    
    u8* ptr;
    u16 size;
}entity_t;

entity_t LIST[40]; // with all of entities in the LIST
                    // we will be take access to the heap

void* my_own_malloc(size_t size) {
    assert(size <= HEAP_SIZE); // max memory for object
                                // what can give custom allocator
    size += HEADER;
}

void my_own_free(void* ptr) {
    
}

void test() {
    int* test_variable = my_own_malloc(sizeof(int)); // test variable
}

int main(int argc, char** argv) {
    return 0;
}
