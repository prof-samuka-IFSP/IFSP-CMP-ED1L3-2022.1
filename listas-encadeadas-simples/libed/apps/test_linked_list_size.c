#include <stdio.h>
#include "linked_list.h"

int main() {
    LinkedList *L = LinkedList_create();

    puts("inserindo na lista");
    for (long i = 0; i < 200000000; i++) {
        LinkedList_add_first(L, i);
    }

    puts("computando o size");
    // printf("size_slow = %ld\n", LinkedList_size_slow(L));
    printf("size = %ld\n", LinkedList_size(L));

    return 0;
}


