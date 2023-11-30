#include "lista_ligada_estatica.h"
#include <stdio.h>

void imprimirElemento(int elemento) {
    printf("%d ", elemento);
}

int main() {
    ListaLigadaEstatica lista1, lista2;
    inicializarLista(&lista1);
    inicializarLista(&lista2);

    int opcao, elemento;

    do {
        printf("\n1. Inserir elemento na Lista 1\n");
        printf("2. Copiar Lista 1 para Lista 2\n");
        printf("3. Concatenar Listas 1 e 2\n");
        printf("4. Intercalar Listas 1 e 2\n");
        printf("5. Exibir Lista 1\n");
        printf("6. Exibir Lista 2\n");
        printf("0. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido na Lista 1: ");
                scanf("%d", &elemento);
                adicionarElemento(&lista1, elemento);
                break;
            case 2:
                lista2 = copiarLista(&lista1);
                printf("Lista 1 copiada para Lista 2.\n");
                break;
            case 3:
                {
                    ListaLigadaEstatica concatenacao = concatenarListas(&lista1, &lista2);
                    printf("Listas 1 e 2 concatenadas: ");
                    percorrerLista(&concatenacao, imprimirElemento);
                    printf("\n");
                }
                break;
            case 4:
                {
                    ListaLigadaEstatica intercalacao = intercalarListas(&lista1, &lista2);
                    printf("Listas 1 e 2 intercaladas: ");
                    percorrerLista(&intercalacao, imprimirElemento);
                    printf("\n");
                }
                break;
            case 5:
                printf("Lista 1: ");
                percorrerLista(&lista1, imprimirElemento);
                printf("\n");
                break;
            case 6:
                printf("Lista 2: ");
                percorrerLista(&lista2, imprimirElemento);
                printf("\n");
                break;
            case 0:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
