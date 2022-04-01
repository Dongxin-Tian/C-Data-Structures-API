#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_STACK_CAPACITY 10

typedef struct {
    void** data;
    size_t length;
    size_t capacity;
} Stack;

Stack* create_stack(void);
bool stack_is_empty(Stack* stack);
void stack_push(Stack* stack, void* data);
void* stack_pop(Stack* stack);
void* stack_peek(Stack* stack);
void free_stack(Stack* stack);

#endif // STACK_H