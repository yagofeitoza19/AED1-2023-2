#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    int tamanho1;
    printf("Informe o tamanho da primeira LISTA: ");
    scanf("%d", &tamanho1);

    LISTA lista1 = criar_lista(tamanho1);

    printf("Insira os elementos da primeira LISTA:\n");
    for (int i = 0; i < tamanho1; i++) {
        int elemento;
        scanf("%d", &elemento);
        inserir_elemento(&lista1, elemento);
    }

    printf("Elementos da primeira LISTA: ");
    imprimir_lista(lista1);

    int elemento_busca;
    printf("Informe um número a ser buscado na primeira LISTA: ");
    scanf("%d", &elemento_busca);
    int resultado = buscar_sequencial(lista1, elemento_busca);
    if (resultado != -1) {
        printf("Elemento encontrado na posição %d (Busca Sequencial).\n", resultado);
    } else {
        printf("Elemento não encontrado (Busca Sequencial).\n");
    }

    liberar_lista(&lista1);

    return 0;
}
