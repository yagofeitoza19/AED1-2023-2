#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque_soldados.h"

DequeSoldados* criar_deque() {
    DequeSoldados* deque = (DequeSoldados*)malloc(sizeof(DequeSoldados));
    if (deque == NULL) {
        perror("Erro ao alocar memória para o deque");
        exit(EXIT_FAILURE);
    }

    deque->inicio = NULL;
    deque->fim = NULL;
    deque->tamanho = 0;
    return deque;
}

Soldado* criar_soldado(int codigo, const char* nome, const char* grau) {
    Soldado* novo_soldado = (Soldado*)malloc(sizeof(Soldado));
    if (novo_soldado == NULL) {
        perror("Erro ao alocar memória para o soldado");
        exit(EXIT_FAILURE);
    }

    novo_soldado->codigo = codigo;
    strncpy(novo_soldado->nome, nome, sizeof(novo_soldado->nome) - 1);
    strncpy(novo_soldado->grau, grau, sizeof(novo_soldado->grau) - 1);
    novo_soldado->proximo = NULL;
    novo_soldado->anterior = NULL;
    return novo_soldado;
}

int inserir_inicio(DequeSoldados* deque, int codigo, const char* nome, const char* grau) {
    Soldado* novo_soldado = criar_soldado(codigo, nome, grau);

    if (vazia(deque)) {
        deque->inicio = novo_soldado;
        deque->fim = novo_soldado;
    } else {
        novo_soldado->proximo = deque->inicio;
        deque->inicio->anterior = novo_soldado;
        deque->inicio = novo_soldado;
    }

    deque->tamanho++;
    return 1;
}

int inserir_fim(DequeSoldados* deque, int codigo, const char* nome, const char* grau) {
    Soldado* novo_soldado = criar_soldado(codigo, nome, grau);

    if (vazia(deque)) {
        deque->inicio = novo_soldado;
        deque->fim = novo_soldado;
    } else {
        novo_soldado->anterior = deque->fim;
        deque->fim->proximo = novo_soldado;
        deque->fim = novo_soldado;
    }

    deque->tamanho++;
    return 1;
}

Soldado* remover_inicio(DequeSoldados* deque) {
    if (vazia(deque)) {
        return NULL;
    }

    Soldado* soldado_removido = deque->inicio;

    if (deque->tamanho == 1) {
        deque->inicio = NULL;
        deque->fim = NULL;
    } else {
        deque->inicio = deque->inicio->proximo;
        deque->inicio->anterior = NULL;
    }

    deque->tamanho--;
    return soldado_removido;
}

Soldado* remover_fim(DequeSoldados* deque) {
    if (vazia(deque)) {
        return NULL;
    }

    Soldado* soldado_removido = deque->fim;

    if (deque->tamanho == 1) {
        deque->inicio = NULL;
        deque->fim = NULL;
    } else {
        deque->fim = deque->fim->anterior;
        deque->fim->proximo = NULL;
    }

    deque->tamanho--;
    return soldado_removido;
}

Soldado* primeiro(DequeSoldados* deque) {
    return deque->inicio;
}

Soldado* ultimo(DequeSoldados* deque) {
    return deque->fim;
}

int contar(DequeSoldados* deque) {
    return deque->tamanho;
}

int vazia(DequeSoldados* deque) {
    return deque->tamanho == 0;
}

void imprimir_soldados(DequeSoldados* deque) {
    Soldado* atual = deque->inicio;
    while (atual != NULL) {
        printf("Código: %d, Nome: %s, Grau: %s\n", atual->codigo, atual->nome, atual->grau);
        atual = atual->proximo;
    }
}

void liberar_deque(DequeSoldados* deque) {
    Soldado* atual = deque->inicio;
    Soldado* proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(deque);
}
