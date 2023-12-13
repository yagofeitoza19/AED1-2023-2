#include <stdio.h>
#include "lista_alunos.h"

int main() {
    ListaAlunos lista;
    inicializarLista(&lista);

    printf("Lista inicializada.\n");

    Aluno aluno;
    int opcao, matricula;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir aluno\n");
        printf("2. Exibir alunos\n");
        printf("3. Verificar se a lista está vazia\n");
        printf("4. Verificar se a lista está cheia\n");
        printf("5. Excluir elemento por matrícula\n");
        printf("6. Reiniciar lista\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Inserir dados do aluno:\n");
                printf("Nome: ");
                scanf("%s", aluno.nome);
                printf("Idade: ");
                scanf("%d", &aluno.idade);
                printf("Matrícula: ");
                scanf("%d", &aluno.matricula);
                inserirElemento(&lista, aluno);
                break;

            case 2:
                printf("Elementos da lista:\n");
                exibirElementos(&lista);
                break;

            case 3:
                if (listaVazia(&lista)) {
                    printf("A lista está vazia.\n");
                } else {
                    printf("A lista não está vazia.\n");
                }
                break;

            case 4:
                printf("A lista não pode estar cheia.\n");
                break;

            case 5:
                printf("Digite a matrícula a ser excluída: ");
                scanf("%d", &matricula);
                excluirElemento(&lista, matricula);
                break;

            case 6:
                reiniciarLista(&lista);
                printf("Lista reiniciada.\n");
                break;

            case 7:
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }

    } while (opcao != 7);

    return 0;
}
