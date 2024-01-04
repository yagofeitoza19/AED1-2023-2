#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Fila* criar_fila(int capacidade) {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->elementos = (Aviao*)malloc(capacidade * sizeof(Aviao));
    fila->capacidade = capacidade;
    fila->tamanho = 0;
    fila->inicio = 0;
    fila->fim = -1;
    return fila;
}

void destruir_fila(Fila* fila) {
    free(fila->elementos);
    free(fila);
}

int fila_vazia(Fila* fila) {
    return (fila->tamanho == 0);
}

int fila_cheia(Fila* fila) {
    return (fila->tamanho == fila->capacidade);
}

void enfileirar(Fila* fila, Aviao aviao) {
    if (fila_cheia(fila)) {
        printf("A fila está cheia. Não é possível adicionar mais aviões.\n");
    } else {
        fila->fim = (fila->fim + 1) % fila->capacidade;
        fila->elementos[fila->fim] = aviao;
        fila->tamanho++;
    }
}

Aviao desenfileirar(Fila* fila) {
    Aviao aviao;

    if (fila_vazia(fila)) {
        printf("A fila está vazia. Não é possível remover aviões.\n");
    } else {
        aviao = fila->elementos[fila->inicio];
        fila->inicio = (fila->inicio + 1) % fila->capacidade;
        fila->tamanho--;
    }

    return aviao;
}

Aviao frente_fila(Fila* fila) {
    Aviao aviao;

    if (fila_vazia(fila)) {
        printf("A fila está vazia. Não há avião na frente.\n");
    } else {
        aviao = fila->elementos[fila->inicio];
    }

    return aviao;
}
