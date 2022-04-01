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
        alist->data = realloc(alist->data, sizeof(void*) * (alist->capacity + 1));
    }

    alist->data[alist->length - 1] = data;
}

void arraylist_remove(ArrayList* alist, void* data_ptr) {
    int index = -1;
    for (register int i = 0; i < alist->length; i++) {
        // The element to remove
        if (alist->data[i] == data_ptr) {
            index = i;
            break;
        }
    }

    // Didn't find the element in the list
    if (index == -1)
        return;
    
    alist->length--;

    // Rearrange the list
    for (register int i = index; i < alist->length; i++) {
        alist->data[i] = alist->data[i + 1];
    }
    alist->data[alist->length] = NULL;
}

void arraylist_remove_at(ArrayList* alist, int index) {
    // If the index is out of range
    if (index < 0 && index >= alist->length)
        return;
    
    alist->length--;
    for (register int i = index; i < alist->length; i++) {
        alist->data[i] = alist->data[i + 1];
    }
    alist->data[alist->length] = NULL;
}

void** arraylist_to_array(ArrayList* alist) {
    void** array = malloc(sizeof(void*) * (alist->length + 1));
    for (register int i = 0; i < alist->length; i++) {
        array[i] = alist->data[i];
    }
    return array;
}

void free_arraylist(ArrayList* list) {
    for (register int i = 0; i < list->capacity; i++) {
        free(list->data[i]);
    }
    free(list);
}