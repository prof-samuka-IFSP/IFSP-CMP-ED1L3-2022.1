#include "float_vector.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>






/**** PUBLIC STRUCTS ****/
// o que está disponível no float_vector.h

struct float_vector {
    int capacity;
    int size;
    float *data;
};
/*************************/



/**** PRIVATE FUNCTIONS ****/
bool is_full(const FloatVector *vet) {
    return (vet->size == vet->capacity);
}

/**************************/


/**** PUBLIC FUNCTIONS ****/
// o que está disponível no float_vector.h
FloatVector *create(int capacity) {
    FloatVector *vet = calloc(1, sizeof(FloatVector));

    vet->capacity = capacity;
    vet->size = 0;
    vet->data = calloc(vet->capacity, sizeof(float));

    return vet;
}

void destroy(FloatVector **vet_ref) {
    FloatVector *aux = *vet_ref;
    free(aux->data);
    free(aux);
    *vet_ref = NULL;
}


int capacity(const FloatVector *vet) {
    return vet->capacity;
}

int size(const FloatVector *vet) {
    return vet->size;
}


void append(FloatVector *vet, float val) {
    // se of vetor estiver cheio, mate a execução
    if (is_full(vet)) {
        printf("ERROR: vector is full!\n");
        exit(-1);
    }

    vet->data[vet->size] = val;
    vet->size++;
}

void print(const FloatVector *vet) {
    puts("-----------");
    printf("Capacity: %d\n", vet->capacity);
    printf("Size: %d\n\n", vet->size);

    for (int i = 0; i < vet->size; i++) {
        printf("[%d] = %f\n", i, vet->data[i]);
    }
    puts("-----------\n");
}