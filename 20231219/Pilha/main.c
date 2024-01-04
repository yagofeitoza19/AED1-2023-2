#include "pilha.h"
#include <stdio.h>

int main() {
    Pilha* hangar = criar_pilha(10);

    while (1) {
        printf("\n1. Listar número de aviões no hangar\n");
        printf("2. Tirar um avião do hangar\n");
        printf("3. Adicionar avião no hangar\n");
        printf("4. Listar aviões no hangar\n");
        printf("5. Listar características do primeiro avião no hangar\n");
        printf("6. Tirar um avião do hangar pela posição\n");
        printf("0. Sair\n");

        int escolha;
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Número de aviões no hangar: %d\n", hangar->topo + 1);
                break;

            case 2:
                if (!pilha_vazia(hangar)) {
                    Aviao aviao = desempilhar(hangar);
                    printf("Avião %s (ID: %d) removido do hangar.\n", aviao.nome, aviao.identificador);
                } else {
                    printf("O hangar está vazio. Não há aviões para remover.\n");
                }
                break;

            case 3:
                if (!pilha_cheia(hangar)) {
                    Aviao aviao;
                    printf("Digite o nome do avião: ");
                    scanf("%s", aviao.nome);
                    printf("Digite o identificador do avião: ");
                    scanf("%d", &aviao.identificador);
                    printf("Digite outras características do avião: ");
                    scanf("%s", aviao.outras_caracteristicas);

                    empilhar(hangar, aviao);
                    printf("Avião %s adicionado ao hangar com sucesso.\n", aviao.nome);
                } else {
                    printf("O hangar está cheio. Não é possível adicionar mais aviões.\n");
                }
                break;

            case 4:
                printf("Aviões no hangar:\n");
                for (int i = 0; i <= hangar->topo; i++) {
                    printf("- %s (ID: %d)\n", hangar->elementos[i].nome, hangar->elementos[i].identificador);
                }
                break;

            case 5:
                if (!pilha_vazia(hangar)) {
                    Aviao aviao = topo_pilha(hangar);
                    printf("Características do primeiro avião no hangar: %s (ID: %d)\n", aviao.nome, aviao.identificador);
                } else {
                    printf("O hangar está vazio. Não há aviões no topo.\n");
                }
                break;

            case 6:
                if (!pilha_vazia(hangar)) {
                    int posicao;
                    printf("Digite a posição do avião a ser removido: ");
                    scanf("%d", &posicao);

                    if (posicao >= 1 && posicao <= hangar->topo + 1) {
                        Pilha* auxiliar = criar_pilha(hangar->capacidade);

                        for (int i = 0; i < posicao - 1; i++) {
                            Aviao aviao = desempilhar(hangar);
                            empilhar(auxiliar, aviao);
                        }

                        Aviao aviao_removido = desempilhar(hangar);
                        printf("Avião %s (ID: %d) removido do hangar pela posição %d.\n", aviao_removido.nome, aviao_removido.identificador, posicao);

                        while (!pilha_vazia(auxiliar)) {
                            Aviao aviao = desempilhar(auxiliar);
                            empilhar(hangar, aviao);
                        }

                        destruir_pilha(auxiliar);
                    } else {
                        printf("Posição inválida. Tente novamente.\n");
                    }
                } else {
                    printf("O hangar está vazio. Não há aviões para remover.\n");
                }
                break;

            case 0:
                destruir_pilha(hangar);
                printf("Programa encerrado.\n");
                return 0;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
