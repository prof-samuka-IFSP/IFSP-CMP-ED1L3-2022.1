#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _filme {
    long id;
    char nome[64];
    int ano;
} Filme;


Filme *Filme_create(long id, const char *nome, int ano) {
    Filme *filme = (Filme *) calloc(1, sizeof(Filme));

    filme->id = id;
    strcpy(filme->nome, nome);
    filme->ano = ano;

    return filme;
}

void Filme_destroy(Filme* *filme_ref) {
    Filme *filme = *filme_ref;
    free(filme);
    *filme_ref = NULL;
}


void Filme_print(const Filme *filme) {
    puts("-------");
    printf("ID: %ld\n", filme->id);
    printf("nome: %s\n", filme->nome);
    printf("ano: %d\n", filme->ano);
    puts("-------\n");
}


int main() {
    Filme *harry = Filme_create(1, "Harry Potter 1", 2001);
    Filme *batman = Filme_create(2, "The Batman", 2022);

    Filme_print(harry);    
    Filme_print(batman);

    printf("&harry = %p\n", &harry);
    printf("harry = %p\n", harry);
    printf("&harry->id = %p\n", &harry->id);
    printf("&harry->nome = %p\n", &harry->nome);
    printf("&harry->ano = %p\n", &harry->ano);

    // cleaning up
    Filme_destroy(&harry);
    Filme_destroy(&batman);

    printf("harry == NULL: %d\n", harry == NULL);
    printf("batman == NULL: %d\n", batman == NULL);

    return 0;
}

