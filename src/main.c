#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(void) {

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

    return 0;
}