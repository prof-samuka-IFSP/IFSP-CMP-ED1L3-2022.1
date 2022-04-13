#include <stdio.h>
#include <stdlib.h>

typedef struct _aluno {
    char nome[128];
    int idade;
    char RA[7];  // um char a mais para o '\0'
    char email[128];
    float notas[4];  // [0] nada
                     // [1] Prova 1
                     // [2] Prova 2
                     // [3] Prova 3
} Aluno;


void imprime_aluno(Aluno aluno) {
    printf("Nome: %s\n", aluno.nome);
    printf("Idade: %d\n", aluno.idade);
    printf("RA: %s\n", aluno.RA);
    printf("Email: %s\n", aluno.email);
    printf("P1: %.2f\n", aluno.notas[1]);
    printf("P2: %.2f\n", aluno.notas[2]);
    printf("P3: %.2f\n", aluno.notas[3]);
}


int main() {
    int n_alunos;
    scanf("%d", &n_alunos);

    // vetor com 'n_alunos' alunos
    Aluno *alunos = (Aluno*) calloc(n_alunos, sizeof(Aluno));

    // para cada aluno
    for (int i = 1; i <= n_alunos; i++) {
        scanf(" %[^\t\n]s", alunos[i].nome);
        printf("alunos[i].nome = %s\n", alunos[i].nome);
        scanf("%d", &alunos[i].idade);
        printf("IDADE alunos[i].nome = %s\n", alunos[i].nome);
        scanf("%s", alunos[i].RA);
        printf("RA alunos[i].nome = %s\n", alunos[i].nome);
        scanf("%s", alunos[i].email);
        printf("EMAIL alunos[i].nome = %s\n", alunos[i].nome);
        scanf("%f %f %f", &alunos[i].notas[1],
                          &alunos[i].notas[2],
                          &alunos[i].notas[3]);
        printf("NOTAS alunos[i].nome = %s\n", alunos[i].nome);

        // imprimindo
        printf("Aluno: [%d]\n", i);
        imprime_aluno(alunos[i]);
        printf("\n");
    }

    return 0;
}
