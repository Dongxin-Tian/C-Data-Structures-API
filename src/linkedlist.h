#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>

typedef struct LinkedNode
{
    void* data;
    struct LinkedNode* next;
    struct LinkedNode* prev;
} LinkedNode;

typedef struct
{
    LinkedNode* first;
    LinkedNode* last;
    int length;
} LinkedList;

LinkedList* create_linkedlist();
void linkedlist_addlast(LinkedList* llist, void* data);
void linkedlist_addfirst(LinkedList* llist, void* data);
void linkedlist_removelast(LinkedList* llist);
void linkedlist_removefirst(LinkedList* llist);
void linkedlist_remove_at(LinkedList* llist, int index);
void linkedlist_free(LinkedList* llist);

#endif // LINKED_LIST_H