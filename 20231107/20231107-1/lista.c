#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Lista criarLista(int tamanho) {
    Lista novaLista;
    novaLista.vetor = (int *)malloc(tamanho * sizeof(int));
    novaLista.quantidade = 0;
    return novaLista;
}

void liberarLista(Lista *lista) {
    free(lista->vetor);
    lista->quantidade = 0;
}

void inserirElemento(Lista *lista, int elemento) {
    lista->vetor[lista->quantidade++] = elemento;
}

void inserirElementoOrdenado(Lista *lista, int elemento) {
    int i = lista->quantidade - 1;
    while (i >= 0 && lista->vetor[i] > elemento) {
        lista->vetor[i + 1] = lista->vetor[i];
        i--;
    }
    lista->vetor[i + 1] = elemento;
    lista->quantidade++;
}

void imprimirListaIterativo(Lista lista) {
    for (int i = 0; i < lista.quantidade; i++) {
        printf("%d ", lista.vetor[i]);
    }
    printf("\n");
}

int buscaBinariaRecursiva(Lista lista, int elemento, int inicio, int fim) {
    if (inicio > fim) {
        return -1; // Elemento não encontrado
    }

    int meio = (inicio + fim) / 2;

    if (lista.vetor[meio] == elemento) {
        return meio; // Elemento encontrado
    } else if (lista.vetor[meio] < elemento) {
        return buscaBinariaRecursiva(lista, elemento, meio + 1, fim);
    } else {
        return buscaBinariaRecursiva(lista, elemento, inicio, meio - 1);
    }
}

void imprimirListaRecursivo(Lista lista, int indice) {
    if (indice == lista.quantidade) {
        printf("\n");
        return;
    }

    printf("%d ", lista.vetor[indice]);
    imprimirListaRecursivo(lista, indice + 1);
}

int buscarMaiorRecursivo(Lista lista, int indice) {
    if (indice == lista.quantidade - 1) {
        return lista.vetor[indice];
    }

    int maiorRestante = buscarMaiorRecursivo(lista, indice + 1);
    return (lista.vetor[indice] > maiorRestante) ? lista.vetor[indice] : maiorRestante;
}

int buscarMenorRecursivo(Lista lista, int indice) {
    if (indice == lista.quantidade - 1) {
        return lista.vetor[indice];
    }

    int menorRestante = buscarMenorRecursivo(lista, indice + 1);
    return (lista.vetor[indice] < menorRestante) ? lista.vetor[indice] : menorRestante;
}

int somarElementosRecursivo(Lista lista, int indice) {
    if (indice == lista.quantidade) {
        return 0;
    }

    return lista.vetor[indice] + somarElementosRecursivo(lista, indice + 1);
}

int multiplicarElementosRecursivo(Lista lista, int indice) {
    if (indice == lista.quantidade) {
        return 1;
    }

    return lista.vetor[indice] * multiplicarElementosRecursivo(lista, indice + 1);
}
