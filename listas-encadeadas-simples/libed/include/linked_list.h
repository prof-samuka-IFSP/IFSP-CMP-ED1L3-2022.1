#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct _node Node;
typedef struct _linked_list LinkedList;

LinkedList *LinkedList_create();
bool LinkedList_is_empty(const LinkedList *L);
void LinkedList_add_first(LinkedList *L, int val);

long LinkedList_size_slow(const LinkedList *L);
long LinkedList_size(const LinkedList *L);

void LinkedList_print(const LinkedList *L);

Node *Node_create(int val);


#endif
