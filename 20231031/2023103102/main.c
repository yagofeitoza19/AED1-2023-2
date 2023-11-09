#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "turma.h"

int main() {
    int quantidade_alunos;
    printf("Informe a quantidade de alunos na turma: ");
    scanf("%d", &quantidade_alunos);

    TURMA turma = criar_turma(quantidade_alunos);

    for (int i = 0; i < quantidade_alunos; i++) {
        int codigo;
        char nome[50];
        int idade;
        float coeficiente;

        printf("Informe os dados do aluno %d:\n", i + 1);
        printf("Código: ");
        scanf("%d", &codigo);
        printf("Nome: ");
        scanf("%s", nome);
        printf("Idade: ");
        scanf("%d", &idade);
        printf("Coeficiente: ");
        scanf("%f", &coeficiente);

        ALUNO aluno = criar_aluno(codigo, nome, idade, coeficiente);
        inserir_aluno(&turma, aluno);
    }

    printf("Alunos na turma:\n");
    imprimir_turma(turma);

    int codigo_busca;
    printf("Informe o código do aluno a ser buscado: ");
    scanf("%d", &codigo_busca);
    buscar_aluno(turma, codigo_busca);

    liberar_turma(&turma);

    return 0;
}
