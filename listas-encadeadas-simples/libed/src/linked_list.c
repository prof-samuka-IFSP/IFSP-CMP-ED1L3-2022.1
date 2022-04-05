#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>


struct _node {
    int val;
    struct _node *next;
};

struct _linked_list {
    Node *begin;
    long size;
};


LinkedList *LinkedList_create() {
    LinkedList *L = calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    L->size = 0;

    return L;
}

bool LinkedList_is_empty(const LinkedList *L) {
    // return (L->size == 0);
    return (L->begin == NULL);
}

void LinkedList_add_first_old(LinkedList *L, int val) {
    // se a lista está vazia
    if (LinkedList_is_empty(L)) {
        Node *p = Node_create(val);
        L->begin = p;
    }
    // a lista possui elementos
    else {
        Node *p = Node_create(val);
        p->next = L->begin;
        L->begin = p;
    }
}

void LinkedList_add_first(LinkedList *L, int val) {
    Node *p = Node_create(val);
    p->next = L->begin;
    L->begin = p;
    L->size++;
}


long LinkedList_size_slow(const LinkedList *L) {
    long size = 0;  // numero de nós da lista

    Node *p = L->begin;

    while (p != NULL) {
        size++;
        p = p->next;
    }

    return size;
}

long LinkedList_size(const LinkedList *L) {
    return L->size;
}


void LinkedList_print(const LinkedList *L) {
    printf("L -> ");
    
    Node *p = L->begin;

    while (p != NULL) {
        printf("%d -> ", p->val);
        p = p->next;
    }

    printf("NULL\n");
}


Node *Node_create(int val) {
    Node *node = (Node *) calloc(1, sizeof(Node));
    node->next = NULL;
    node->val = val;

    return node;
}
