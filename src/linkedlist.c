#include <stdlib.h>
#include "linkedlist.h"

/* Create an empty linked list and return the allocated memory pointer
 */
LinkedList* create_linkedlist() {
    LinkedList* llist = malloc(sizeof(LinkedList));
    llist->first = NULL;
    llist->last = NULL;
    llist->length = 0;
    return llist;
}

void linkedlist_addlast(LinkedList* llist, void* data) {
    // If linked list is empty
    if (llist->first == NULL) {
        LinkedNode* first = malloc(sizeof(LinkedNode));
        first->data = data;
        first->next = NULL;
        first->prev = NULL;

        llist->length = 1;
        llist->first = first;
        llist->last = first;
        return;
    }

    LinkedNode* next = malloc(sizeof(LinkedNode));
    next->data = data;
    next->next = NULL;
    next->prev = llist->last;

    llist->length++;
    llist->last->next = next;
    llist->last = next;
}

void linkedlist_addfirst(LinkedList* llist, void* data) {
    // If linked list is empty
    if (llist->first == NULL) {
        LinkedNode* first = malloc(sizeof(LinkedNode));
        first->data = data;
        first->next = NULL;
        first->prev = NULL;

        llist->length = 1;
        llist->first = first;
        llist->last = first;
        return;
    }

    LinkedNode* first = malloc(sizeof(LinkedNode));
    first->data = data;
    first->prev = NULL;
    first->next = llist->first;

    llist->length++;
    llist->first->prev = first;
    llist->first = first;
}

void linkedlist_removelast(LinkedList* llist) {
    LinkedNode* last_to_remove = llist->last;
    llist->last = last_to_remove->prev;
    llist->last->next = NULL;
    free(last_to_remove);

    llist->length--;
    if (llist->length == 1) {
        llist->first = llist->last;
    }
}

void linkedlist_removefirst(LinkedList* llist) {
    LinkedNode* first_to_remove = llist->first;
    llist->first = first_to_remove->next;
    llist->first->prev = NULL;
    free(first_to_remove);

    llist->length--;
    if (llist->length == 1) {
        llist->last = llist->first;
    }
}

void linkedlist_remove_at(LinkedList* llist, int index) {
    if (index == 0) {
        linkedlist_removefirst(llist);
        return;
    } else if (index == llist->length - 1) {
        linkedlist_removelast(llist);
        return;
    }

    LinkedNode* node = llist->first;
    int i = 0;
    while (i < index) {
        node = node->next;
        i++;
    }
    
    node->prev->next = node->next;
        
    llist->length--;
    
    free(node);
}

void linkedlist_free(LinkedList* llist) {
    LinkedNode* node = llist->first;
    while (node != NULL) {
        node = node->next;
        free(node->prev);
    }
    
    free(llist);
    // Didn't free data because they might not be allocated memory
}