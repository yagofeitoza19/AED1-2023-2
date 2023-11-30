#include "lista_ligada_estatica.h"
#include <stdio.h>

void imprimirElemento(int elemento) {
    printf("%d ", elemento);
}

int main() {
    ListaLigadaEstatica lista;
    inicializarLista(&lista);

    int opcao, elemento;

    do {
        printf("\n1. Inserir elemento na lista\n");
        printf("2. Construir e exibir Lista A\n");
        printf("3. Construir e exibir Lista B\n");
        printf("0. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido na lista: ");
                scanf("%d", &elemento);
                adicionarElemento(&lista, elemento);
                break;
            case 2:
                printf("Lista Original: ");
                percorrerLista(&lista, imprimirElemento);
                printf("\n");

                ListaLigadaEstatica listaA = construirListaA(&lista);
                printf("Lista A: ");
                percorrerLista(&listaA, imprimirElemento);
                printf("\n");
                break;
            case 3:
                printf("Lista Original: ");
                percorrerLista(&lista, imprimirElemento);
                printf("\n");

                ListaLigadaEstatica listaB = construirListaB(&lista);
                printf("Lista B: ");
                percorrerLista(&listaB, imprimirElemento);
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
