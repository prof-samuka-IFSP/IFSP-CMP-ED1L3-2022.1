#include <stdio.h>
#include <stdlib.h>



int main() {
    int i, n = 5;
    int* v = NULL;

    printf("&i = %p, i = %d\n", &i, i);
    printf("&n = %p, n = %d\n", &n, n);
    printf("&v = %p, v = %p\n\n", &v, v);

    v = (int*) malloc(n * sizeof(int));
    printf("&v = %p, v = %p\n\n", &v, v);

    for (i = 0; i < n; i++) {
        // puts("ANTES");
        // printf("&v[%d] = %p, v[%d] = %d\n",
        //         i, &v[i], i, v[i]);
        // printf("*(v + %d) = *(%p + %d) = *(%p) = %d\n",
        //         i, v, i, (v + i), *(v + i));

        v[i] = i;

        // puts("DEPOIS");
        printf("&v[%d] = %p, v[%d] = %d\n",
                i, &v[i], i, v[i]);
        printf("*(v + %d) = *(%p + %d) = *(%p) = %d\n",
                i, v, i, (v + i), *(v + i));
        puts("");
    }

    free(v);
    v = NULL;

    return 0;
}

