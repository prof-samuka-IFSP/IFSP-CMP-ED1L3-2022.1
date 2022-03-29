#include <stdio.h>

#include "float_vector.h"

int main() {
    FloatVector *vet = create(100);
    int vet_capacity = capacity(vet);
    int vet_size = size(vet);
    printf("vet_capacity = %d\n", vet_capacity);
    printf("vet_size = %d\n", vet_size);

    append(vet, 0.5);
    append(vet, 1.5);
    append(vet, 2.5);
    append(vet, 3.5);
    append(vet, 4.5);
    append(vet, 5.5);
    append(vet, 6.5);
    append(vet, 7.5);
    append(vet, 8.5);
    append(vet, 9.5);

    print(vet);

    destroy(&vet);
    printf("\nvet == NULL: %d\n", vet == NULL);

    return 0;
}
