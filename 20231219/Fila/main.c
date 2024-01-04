#include "fila.h"
#include <stdio.h>

int main() {
    Fila* fila = criar_fila(10);

    while (1) {
        printf("\n1. Listar número de aviões na fila\n");
        printf("2. Autorizar decolagem do primeiro avião\n");
        printf("3. Adicionar avião à fila de espera\n");
        printf("4. Listar aviões na fila de espera\n");
        printf("5. Listar características do primeiro avião\n");
        printf("0. Sair\n");

        int escolha;
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Número de aviões na fila: %d\n", fila->tamanho);
                break;

            case 2:
                if (!fila_vazia(fila)) {
                    Aviao aviao = desenfileirar(fila);
                    printf("Autorizando decolagem do avião %s (ID: %d)\n", aviao.nome, aviao.identificador);
                } else {
                    printf("Não há aviões na fila para decolagem.\n");
                }
                break;

            case 3:
                if (!fila_cheia(fila)) {
                    Aviao aviao;
                    printf("Digite o nome do avião: ");
                    scanf("%s", aviao.nome);
                    printf("Digite o identificador do avião: ");
                    scanf("%d", &aviao.identificador);
                    printf("Digite outras características do avião: ");
                    scanf("%s", aviao.outras_caracteristicas);

                    enfileirar(fila, aviao);
                    printf("Avião %s adicionado à fila com sucesso.\n", aviao.nome);
              } else {
              printf("A fila está cheia. Não é possível adicionar mais aviões.\n");
          }
          break;
          
            case 4:
                printf("Aviões na fila de espera:\n");
                for (int i = fila->inicio, count = 0; count < fila->tamanho; i = (i + 1) % fila->capacidade, count++) {
                    printf("- %s (ID: %d)\n", fila->elementos[i].nome, fila->elementos[i].identificador);
                }
                break;

            case 5:
                if (!fila_vazia(fila)) {
                    Aviao aviao = frente_fila(fila);
                    printf("Características do primeiro avião na fila: %s (ID: %d)\n", aviao.nome, aviao.identificador);
                } else {
                    printf("Não há aviões na fila.\n");
                }
                break;

            case 0:
                destruir_fila(fila);
                printf("Programa encerrado.\n");
                return 0;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
