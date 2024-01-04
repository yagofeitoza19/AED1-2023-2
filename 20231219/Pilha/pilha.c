#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

Pilha* criar_pilha(int capacidade) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->elementos = (Aviao*)malloc(capacidade * sizeof(Aviao));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    return pilha;
}

void destruir_pilha(Pilha* pilha) {
    free(pilha->elementos);
    free(pilha);
}

int pilha_vazia(Pilha* pilha) {
    return (pilha->topo == -1);
}

int pilha_cheia(Pilha* pilha) {
    return (pilha->topo == pilha->capacidade - 1);
}

void empilhar(Pilha* pilha, Aviao aviao) {
    if (pilha_cheia(pilha)) {
        printf("O hangar está cheio. Não é possível adicionar mais aviões.\n");
    } else {
        pilha->topo++;
        pilha->elementos[pilha->topo] = aviao;
    }
}

Aviao desempilhar(Pilha* pilha) {
    Aviao aviao;

    if (pilha_vazia(pilha)) {
        printf("O hangar está vazio. Não é possível remover aviões.\n");
    } else {
        aviao = pilha->elementos[pilha->topo];
        pilha->topo--;
    }

    return aviao;
}

Aviao topo_pilha(Pilha* pilha) {
    Aviao aviao;

    if (pilha_vazia(pilha)) {
        printf("O hangar está vazio. Não há avião no topo.\n");
    } else {
        aviao = pilha->elementos[pilha->topo];
    }

    return aviao;
}
