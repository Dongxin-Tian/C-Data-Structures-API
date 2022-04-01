#include <stdlib.h>
#include "arraylist.h"

ArrayList* create_arraylist(void) {
    ArrayList* alist = malloc(sizeof(alist));
    alist->capacity = ARRAYLIST_INITIAL_CAPACITY;
    alist->length = 0;
    alist->data = malloc(sizeof(void*) * (ARRAYLIST_INITIAL_CAPACITY + 1));
    return alist;
}

void arraylist_add(ArrayList* alist, void* data) {
    alist->length++;

    // If the capacity is not enough, double the capacity by reallocating
    if (alist->length >= alist->capacity) {
        alist->capacity *= 2;
        realloc(alist->data, sizeof(void*) * (alist->capacity + 1));
    }

    alist->data[alist->length - 1] = data;
}

void arraylist_remove(ArrayList* alist, void* data_ptr) {
    
}

void arraylist_remove_at(ArrayList* alist, int index) {
    if (index < 0 && index >= alist->length) {
        
    }
}

void free_arraylist(ArrayList* list) {
    for (register int i = 0; i < list->capacity; i++) {
        free(list->data[i]);
    }
    free(list);
}