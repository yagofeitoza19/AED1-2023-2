#include "turma.h"
#include <stdio.h>
#include <stdlib.h>

TURMA criar_turma(int quantidade) {
    TURMA turma;
    turma.alunos = (ALUNO *)malloc(quantidade * sizeof(ALUNO));
    turma.quantidade = 0;
    return turma;
}

void liberar_turma(TURMA *turma) {
    free(turma->alunos);
    turma->quantidade = 0;
}

void inserir_aluno(TURMA *turma, ALUNO aluno) {
    turma->alunos[turma->quantidade] = aluno;
    turma->quantidade++;
}

void buscar_aluno(TURMA turma, int codigo) {
    for (int i = 0; i < turma.quantidade; i++) {
        if (turma.alunos[i].codigo == codigo) {
            imprimir_aluno(turma.alunos[i]);
            return;
        }
    }
    printf("Aluno com código %d não encontrado na turma.\n", codigo);
}

void imprimir_turma(TURMA turma) {
    for (int i = 0; i < turma.quantidade; i++) {
        printf("Código: %d, Nome: %s\n", turma.alunos[i].codigo, turma.alunos[i].nome);
    }
}
