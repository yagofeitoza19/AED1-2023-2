#include "lista_alunos.h"
#include <stdio.h>

int main() {
    ListaAlunos listaA, listaB, listaC;
    inicializarLista(&listaA);
    inicializarLista(&listaB);
    inicializarLista(&listaC);

    char opcao;
    do {
        printf("\nEscolha a lista (A, B ou C) ou digite Q para sair: ");
        scanf(" %c", &opcao);

        if (opcao == 'A' || opcao == 'B' || opcao == 'C') {
            printf("\nInserindo alunos na lista %c.\n", opcao);

            int numAlunos;
            printf("Quantos alunos deseja inserir na lista %c? ", opcao);
            scanf("%d", &numAlunos);

            for (int i = 0; i < numAlunos; ++i) {
                Aluno aluno;

                printf("\nInsira os dados do aluno %d para a lista %c:\n", i + 1, opcao);
                printf("Matrícula: ");
                scanf("%d", &aluno.matricula);
                printf("Nome: ");
                scanf("%s", aluno.nome);
                printf("Idade: ");
                scanf("%d", &aluno.idade);

                switch (opcao) {
                    case 'A':
                        inserirOrdenado(&listaA, aluno);
                        break;
                    case 'B':
                        inserirOrdenado(&listaB, aluno);
                        break;
                    case 'C':
                        inserirOrdenado(&listaC, aluno);
                        break;
                }
            }

            printf("\nLista A:\n");
            exibirElementos(&listaA);

            printf("\nLista B:\n");
            exibirElementos(&listaB);

            printf("\nLista C:\n");
            exibirElementos(&listaC);
        } else if (opcao != 'Q') {
            printf("\nOpção inválida. Tente novamente.\n");
        }

    } while (opcao != 'Q');

    reiniciarLista(&listaA);
    reiniciarLista(&listaB);
    reiniciarLista(&listaC);

    return 0;
}
