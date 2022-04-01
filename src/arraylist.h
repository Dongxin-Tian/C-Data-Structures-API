#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdlib.h>

#define ARRAYLIST_INITIAL_CAPACITY 10

typedef struct {
    void** data;
    size_t length;
    size_t capacity;
} ArrayList;

ArrayList* create_arraylist(void);
void arraylist_add(ArrayList* alist, void* data);
void arraylist_remove(ArrayList* alist, void* data_ptr);
void arraylist_remove_at(ArrayList* alist, int index);
void free_arraylist(ArrayList* list);

#endif // ARRAY_LIST_H