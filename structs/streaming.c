#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _filme {
    long id;
    char nome[64];
    int ano;
} Filme;


typedef struct _streaming {
    long id;
    char nome[64];
    float mensalidade;
    Filme **filmes;
    int n_filmes;
    int capacity;
} Streaming;


Filme *Filme_create(long id, const char *nome, int ano) {
    Filme *filme = (Filme *) calloc(1, sizeof(Filme));

    filme->id = id;
    strcpy(filme->nome, nome);
    filme->ano = ano;

    return filme;
}


void Filme_destroy(Filme **filme_ref) {
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

Filme *Filme_copy(const Filme *filme) {
    return Filme_create(filme->id, filme->nome, filme->ano);
}


Streaming *Streaming_create(long id, const char *nome, float mensalidade,
                            int capacity) {
    Streaming *s = (Streaming*) calloc(1, sizeof(Streaming));

    s->id = id;
    strcpy(s->nome, nome);
    s->mensalidade = mensalidade;
    s->capacity = capacity;

    s->n_filmes = 0;
    s->filmes = calloc(s->capacity, sizeof(Filme *));

    return s;
}

void Streaming_destroy(Streaming **streaming_ref) {
    // atribua o conteúdo a um auxiliar para facilitar
    // o manuseio da função
    Streaming *aux = *streaming_ref;

    // desalocação
    for (int i = 0; i < aux->n_filmes; i++) {
        Filme_destroy(&aux->filmes[i]);
    }
    free(aux->filmes);
    aux->filmes = NULL;  // não precisa pq desalocaremos o aux

    free(aux);

    // setar o ponteiro externo como NULL
    *streaming_ref = NULL;
}


bool Streaming_filme_is_full(Streaming *streaming) {
    return (streaming->capacity == streaming->n_filmes);
}


void Streaming_add_filme(Streaming *streaming, Filme *filme) {
    if (!Streaming_filme_is_full(streaming)) {
        streaming->filmes[streaming->n_filmes] = Filme_copy(filme);
        streaming->n_filmes++;
    }
}

void Streaming_print(const Streaming *streaming) {
    printf("id: %ld\n", streaming->id);
    printf("nome: %s\n", streaming->nome);
    printf("mensalidade: %.2f\n", streaming->mensalidade);
    printf("num. de filmes: %d\n", streaming->n_filmes);
    printf("capacity: %d\n\n", streaming->capacity);

    // imprima os filmes
    for (int i = 0; i < streaming->n_filmes; i++) {
        Filme_print(streaming->filmes[i]);
    }
    puts("");
}

void Streaming_savetxt(const char *filename, const Streaming *streaming) {
    FILE *fp = fopen(filename, "w");
    
    fprintf(fp, "id: %ld\n", streaming->id);
    fprintf(fp, "nome: %s\n", streaming->nome);
    fprintf(fp, "mensalidade: %.2f\n", streaming->mensalidade);
    fprintf(fp, "num. de filmes: %d\n", streaming->n_filmes);
    fprintf(fp, "capacity: %d\n\n", streaming->capacity);

    // imprima os filmes
    for (int i = 0; i < streaming->n_filmes; i++) {
        fprintf(fp, "-------\n");
        fprintf(fp, "ID: %ld\n", streaming->filmes[i]->id);
        fprintf(fp, "nome: %s\n", streaming->filmes[i]->nome);
        fprintf(fp, "ano: %d\n", streaming->filmes[i]->ano);
        fprintf(fp, "-------\n");
    }
    fprintf(fp, "-------\n");
    fclose(fp);
}


int main() {
    Filme *harry = Filme_create(1, "Harry Potter 1", 2001);
    Filme *batman = Filme_create(2, "The Batman", 2022);
    Filme *avengers = Filme_create(3, "Avengers 2", 2019);

    Filme_print(harry);

    Streaming *streaming = Streaming_create(1, "Netflix", 39.90, 100);
    Streaming_add_filme(streaming, harry);
    Streaming_add_filme(streaming, batman);
    Streaming_add_filme(streaming, avengers);

    Streaming_print(streaming);

    harry->id = 99;
    harry->ano = 2099;
    strcpy(harry->nome, "Rick and Morty");

    puts("Filme alterado");
    Filme_print(harry);
    
    Streaming_print(streaming);
    Streaming_savetxt("streaming.txt", streaming);

    Filme_destroy(&harry);
    Filme_destroy(&batman);
    Filme_destroy(&batman);

    Streaming_destroy(&streaming);

    printf("streaming == NULL? %d\n", streaming == NULL);

    return 0;
}

