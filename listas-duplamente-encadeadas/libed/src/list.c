#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


typedef struct _doubly_node {
    int val;
    struct _doubly_node *prev;
    struct _doubly_node *next;
} DoublyNode, Node;

typedef struct _doubly_linked_list {
    Node *begin;
    Node *end;
    size_t size;
} DoublyLinkedList, List;


Node *Node_create(int val) {
    Node *node = (Node*) calloc(1, sizeof(Node));
    node->prev = NULL;
    node->next = NULL;
    node->val = val;

    return node;
}

List *List_create() {
    List *L = (List*) calloc(1, sizeof(List));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}


void List_destroy(List **L_ref) {
    List *L = *L_ref;

    Node *p = L->begin;
    Node *aux = NULL;

    while (p != NULL) {
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);

    *L_ref = NULL;
}

bool List_is_empty(const List *L) {
    return L->size == 0;
}

void List_add_first(List *L, int val) {
    Node *p = Node_create(val);
    
    if (List_is_empty(L)) {
        L->end = p;
    }
    else {
        p->next = L->begin;
        L->begin->prev = p;
    }

    L->begin = p;
    L->size++;
}




void List_add_last(List *L, int val) {
    Node *p = Node_create(val);

    if (List_is_empty(L)) {
        L->begin = p;
    }
    else {
        p->prev = L->end;
        L->end->next = p;
    }
    
    L->end = p;
    L->size++;
}



void List_print(const List *L) {
    Node *p = L->begin;

    printf("L -> ");

    // enquanto p não chegou ao fim da lista, isto é,
    // enquanto p estiver apontando para um nó da lista
    while (p != NULL) {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");

    if (L->end == NULL) {
        printf("L->end = NULL\n");
    }
    else {
        printf("L->end = %d\n", L->end->val);
    }
    
    printf("Size: %lu\n", L->size);
    puts("");
}

void List_inverted_print(const List *L) {
    Node *p = L->end;

    printf("L->end -> ");

    // enquanto p não chegou ao início da lista, isto é,
    // enquanto p estiver apontando para um nó da lista
    while (p != NULL) {
        printf("%d -> ", p->val);
        p = p->prev;
    }
    printf("NULL\n");

    if (L->end == NULL) {
        printf("L->begin = NULL\n");
    }
    else {
        printf("L->begin = %d\n", L->begin->val);
    }
    
    printf("Size: %lu\n", L->size);
    puts("");
}


void List_remove(List *L, int val) {
    if (!List_is_empty(L)) {
        Node *p = NULL;

        // caso 1: o elemento está na cabeça da lista
        if (L->begin->val == val) {
            printf("**** CASO 1: CABEÇA DA LISTA\n\n");

            p = L->begin;

            if (L->size == 1) {
                L->begin = NULL;
                L->end = NULL;
            }
            else {
                L->begin = L->begin->next;
                L->begin->prev = NULL;
            }

            free(p);
            L->size--;
        }
        // caso 2: o elemento está no meio da lista
        // caso 3: o elemento está no final da lista
        else {
            // aponte para o segundo nó da lista
            p = L->begin->next;

            // enquanto p está apontando para algum nó e
            // o nó não possui o valor desejado, vá para o próximo nó.
            // Ao final desse loop, o ponteiro p estará ou apontando para
            // o nó desejado, ou seja, o nó de valor val, ou ele chegou
            // no final da lista (p == NULL), o que significa que
            // não há nenhum nó na lista com valor val
            while (p != NULL && p->val != val) {
                p = p->next;
            }

            // achou um nó com valor val
            if (p != NULL) {
                p->prev->next = p->next;

                // caso 3: se p aponta para o último
                if (L->end == p) {
                    L->end = p->prev;
                    printf("**** CASO 3: CAUDA DA LISTA\n\n");
                }
                // caso 2: p está apontando para um nó do meio da lista
                else {
                    p->next->prev = p->prev;
                    printf("**** CASO 2: MEIO DA LISTA\n\n");
                }
                
                free(p);
                L->size--;
            }
            else {
                printf("**** NÃO ACHOU!\n\n");
            }
        }
    }
    else {
        printf("**** LISTA VAZIA\n\n");
    }
}


