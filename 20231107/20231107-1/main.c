#include "lista.h"
#include <stdio.h>

int main() {
    int tamanhoLista;
    printf("Digite o tamanho da lista: ");
    scanf("%d", &tamanhoLista);

    Lista minhaLista = criarLista(tamanhoLista);

    int opcao;
    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Inserir elemento\n");
        printf("2. Inserir elemento ordenado\n");
        printf("3. Imprimir lista\n");
        printf("4. Busca binaria\n");
        printf("5. Imprimir lista recursivamente\n");
        printf("6. Buscar maior elemento\n");
        printf("7. Buscar menor elemento\n");
        printf("8. Somar todos os elementos\n");
        printf("9. Multiplicar todos os elementos\n");
        printf("0. Sair\n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int elemento;
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elemento);
                inserirElemento(&minhaLista, elemento);
                break;
            }
            case 2: {
                int elemento;
                printf("Digite o elemento a ser inserido ordenadamente: ");
                scanf("%d", &elemento);
                inserirElementoOrdenado(&minhaLista, elemento);
                break;
            }
            case 3:
                printf("Lista: ");
                imprimirListaIterativo(minhaLista);
                break;
            case 4: {
                int elementoBusca;
                printf("Digite o elemento a ser buscado: ");
                scanf("%d", &elementoBusca);
                int indiceBusca = buscaBinariaRecursiva(minhaLista, elementoBusca, 0, minhaLista.quantidade - 1);
                if (indiceBusca != -1) {
                    printf("Elemento %d encontrado na posicao %d.\n", elementoBusca, indiceBusca);
                } else {
                    printf("Elemento %d nao encontrado na lista.\n", elementoBusca);
                }
                break;
            }
            case 5:
                printf("Lista recursiva: ");
                imprimirListaRecursivo(minhaLista, 0);
                break;
            case 6:
                printf("Maior elemento: %d\n", buscarMaiorRecursivo(minhaLista, 0));
                break;
            case 7:
                printf("Menor elemento: %d\n", buscarMenorRecursivo(minhaLista, 0));
                break;
            case 8:
                printf("Soma de todos os elementos: %d\n", somarElementosRecursivo(minhaLista, 0));
                break;
            case 9:
                printf("Produto de todos os elementos: %d\n", multiplicarElementosRecursivo(minhaLista, 0));
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    liberarLista(&minhaLista);

    return 0;
}
