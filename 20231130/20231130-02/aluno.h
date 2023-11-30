#ifndef ALUNO_H
#define ALUNO_H

#define MAX_TAMANHO_NOME 50

typedef struct {
    int matricula;
    char nome[MAX_TAMANHO_NOME];
    int idade;
} Aluno;

#endif
