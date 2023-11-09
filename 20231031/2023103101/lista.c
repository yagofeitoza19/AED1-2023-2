#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

LISTA criar_lista(int tamanho) {
    LISTA lista;
    lista.elementos = (int *)malloc(tamanho * sizeof(int));
    lista.quantidade = 0;
    return lista;
}

void liberar_lista(LISTA *lista) {
    free(lista->elementos);
    lista->quantidade = 0;
}

void inserir_elemento(LISTA *lista, int elemento) {
    lista->elementos[lista->quantidade] = elemento;
    lista->quantidade++;
}

void imprimir_lista(LISTA lista) {
    for (int i = 0; i < lista.quantidade; i++) {
        printf("%d ", lista.elementos[i]);
    }
    printf("\n");
}

int buscar_sequencial(LISTA lista, int elemento) {
    for (int i = 0; i < lista.quantidade; i++) {
        if (lista.elementos[i] == elemento) {
            return i;
        }
    }
    return -1;
}

int buscar_sequencial_ordenada(LISTA lista, int elemento) {
    for (int i = 0; i < lista.quantidade; i++) {
        if (lista.elementos[i] == elemento) {
            return i;
        }
        if (lista.elementos[i] > elemento) {
            return -1;
        }
    }
    return -1;
}

int buscar_binaria(LISTA lista, int elemento) {
    int inicio = 0;
    int fim = lista.quantidade - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (lista.elementos[meio] == elemento) {
            return meio;
        }
        if (lista.elementos[meio] < elemento) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int buscar_maior(LISTA lista) {
    int maior = lista.elementos[0];
    for (int i = 1; i < lista.quantidade; i++) {
        if (lista.elementos[i] > maior) {
            maior = lista.elementos[i];
        }
    }
    return maior;
}

int buscar_menor(LISTA lista) {
    int menor = lista.elementos[0];
    for (int i = 1; i < lista.quantidade; i++) {
        if (lista.elementos[i] < menor) {
            menor = lista.elementos[i];
        }
    }
    return menor;
}

int calcular_soma(LISTA lista) {
    int soma = 0;
    for (int i = 0; i < lista.quantidade; i++) {
        soma += lista.elementos[i];
    }
    return soma;
}

int calcular_produto(LISTA lista) {
    int produto = 1;
    for (int i = 0; i < lista.quantidade; i++) {
        produto *= lista.elementos[i];
    }
    return produto;
}
