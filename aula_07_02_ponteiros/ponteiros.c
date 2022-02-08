#include <stdio.h>

int main() {
    int a = 10;
    int *p1 = &a;
    // int *p1 = 4;
    // int *p1 = 0x7ffdf5c8ea20;

    printf("&a = %p, a = %d\n", &a, a);
    printf("&p1 = %p, p1 = %p, *p1 = %d\n", &p1, p1, *p1);
    // printf("&p1 = %p\n", &p1);
    // printf("p1 = %p\n", p1);
    // printf("*p1 = %d\n", *p1);

    return 0;
}

