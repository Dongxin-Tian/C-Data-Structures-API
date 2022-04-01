#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "arraylist.h"

int main(void) {

    printf("Linked list test: \n");
    // Create an integer linked list
    LinkedList* llist = create_linkedlist();

    // Add 1, 2, and 3 respectively
    int* a = malloc(sizeof(int));
    *a = 1;
    linkedlist_addlast(llist, a);
    int* b = malloc(sizeof(int));
    *b = 2;
    linkedlist_addlast(llist, b);
    int* c = malloc(sizeof(int));
    *c = 3;
    linkedlist_addlast(llist, c);

    // Remove
    linkedlist_remove_at(llist, 1);
    linkedlist_remove_at(llist, 0);

    // Print the linked list
    LinkedNode* node = llist->first;
    while (node != NULL) {
        printf("%d\n", *(int*)node->data);
        node = node->next;
    }
    
    free_linkedlist(llist);
    free(a);
    free(b);
    free(c);

    printf("Array list test: \n");
    ArrayList* alist = create_arraylist();
    a = malloc(sizeof(int));
    *a = 1;
    b = malloc(sizeof(int));
    *b = 2;
    c = malloc(sizeof(int));
    *c = 3;
    arraylist_add(alist, a);
    arraylist_add(alist, b);
    arraylist_add(alist, c);

    arraylist_remove(alist, a);
    arraylist_remove_at(alist, 0);

    // Print the array list
    for (register int i = 0; i < alist->length; i++) {
        printf("%d", *(int*)alist->data[i]);
        if (i != alist->length - 1)
            printf(", ");
    }

    free_arraylist(alist);
    free(a);
    free(b);
    free(c);

    return 0;
}