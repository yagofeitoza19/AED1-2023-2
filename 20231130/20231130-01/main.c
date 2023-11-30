#include "lista_alunos.h"
#include <stdio.h>

int main() {
    ListaAlunos lista;
    inicializarLista(&lista);

    int opcao, matricula, novaMatricula;

    do {
        printf("\n1. Inserir elemento\n");
        printf("2. Excluir elemento\n");
        printf("3. Alterar matrícula\n");
        printf("4. Exibir lista\n");
        printf("0. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a matrícula do aluno a ser inserido: ");
                scanf("%d", &matricula);
                inserirElemento(&lista, matricula);
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
                scanf("%d", &novaMatricula);
                alterarMatricula(&lista, matricula, novaMatricula);
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
