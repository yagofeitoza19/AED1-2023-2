#include "lista_alunos.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    ListaAlunos lista;
    inicializarLista(&lista);

    int opcao, matricula, idade;
    char nome[MAX_TAMANHO_NOME];

    do {
        printf("\n1. Inserir aluno\n");
        printf("2. Excluir aluno\n");
        printf("3. Alterar matrícula\n");
        printf("4. Exibir lista\n");
        printf("0. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a matrícula do aluno: ");
                scanf("%d", &matricula);

                // Limpar o buffer de entrada antes de ler a string do nome
                while (getchar() != '\n');

                printf("Digite o nome do aluno: ");
                fgets(nome, MAX_TAMANHO_NOME, stdin);
                nome[strcspn(nome, "\n")] = 0;  // Remover o caractere de nova linha

                printf("Digite a idade do aluno: ");
                scanf("%d", &idade);

                Aluno novoAluno = {matricula, "", idade};  // Inicializar nome vazio
                strncpy(novoAluno.nome, nome, MAX_TAMANHO_NOME - 1);  // Copiar o nome

                inserirElemento(&lista, novoAluno);
                break;
            case 2:
                printf("Digite a matrícula do aluno a ser excluído: ");
                scanf("%d", &matricula);
                excluirElemento(&lista, matricula);
                break;
            case 3:
                printf("Digite a matrícula do aluno a ser alterado: ");
                scanf("%d", &matricula);
                printf("Digite a nova matrícula: ");
                scanf("%d", &idade);
                alterarMatricula(&lista, matricula, idade);
                break;
            case 4:
                exibirLista(&lista);
                break;
            case 0:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    liberarLista(&lista);

    return 0;
}
