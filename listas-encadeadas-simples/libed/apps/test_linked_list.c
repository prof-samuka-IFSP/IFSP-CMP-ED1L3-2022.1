#include <stdio.h>
#include "linked_list.h"

int main() {
    LinkedList *L = LinkedList_create();

    // lista vazia
    printf("size_slow = %ld\n", LinkedList_size_slow(L));
    printf("size = %ld\n", LinkedList_size(L));
    LinkedList_print(L);

    LinkedList_add_first(L, 5);
    LinkedList_add_first(L, 4);
    LinkedList_add_first(L, 2);
    LinkedList_add_first(L, 10);

    printf("size_slow = %ld\n", LinkedList_size_slow(L));
    printf("size = %ld\n", LinkedList_size(L));
    LinkedList_print(L);

    return 0;
}


