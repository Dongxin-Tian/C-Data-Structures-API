#include <stdlib.h>
#include "stack.h"

Stack* create_stack(void) {
    Stack* stack = malloc(sizeof(Stack));
    stack->capacity = INITIAL_STACK_CAPACITY;
    stack->length = 0;
    stack->data = malloc(sizeof(void*) * (INITIAL_STACK_CAPACITY + 1));
    return stack;
}

bool stack_is_empty(Stack* stack) {
    if (stack->length > 0)
        return false;
    return true;
}

void* stack_pop(Stack* stack) {
    if (stack->length == 0)
        return NULL;
    
    void* result = stack->data[stack->length - 1];
    stack->data[stack->length - 1] = NULL;
    stack->length--;
    return result;
}

void stack_push(Stack* stack, void* data) {
    stack->length++;

    // If the stack is full
    if (stack->length >= stack->capacity) {
        stack->capacity *= 2;
        stack->data = realloc(stack->data, sizeof(void*) * (stack->capacity + 1));
    }

    stack->data[stack->length - 1] = data;
}

void* stack_peek(Stack* stack) {
    if (stack->length == 0)
        return NULL;
    
    return stack->data[stack->length - 1];
}

void free_stack(Stack* stack) {
    free(stack->data);
    free(stack);
}