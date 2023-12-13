#include <stdio.h>
#include <stdlib.h>
#include "lista_alunos.h"

void inicializarLista(ListaAlunos* lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void reiniciarLista(ListaAlunos* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
    lista->tamanho = 0;
}

int quantidadeElementos(ListaAlunos* lista) {
    return lista->tamanho;
}

int listaCheia(ListaAlunos* lista) {
    return 0;
}

int listaVazia(ListaAlunos* lista) {
    return lista->inicio == NULL;
}

void exibirElementos(ListaAlunos* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        printf("Matricula: %d, Nome: %s, Idade: %d\n", atual->aluno.matricula, atual->aluno.nome, atual->aluno.idade);
        atual = atual->proximo;
    }
}

void inserirElemento(ListaAlunos* lista, Aluno aluno) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }

    novo->aluno = aluno;
    novo->proximo = NULL;

    if (lista->inicio == NULL || aluno.matricula < lista->inicio->aluno.matricula) {
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    } else {
        No* atual = lista->inicio;
        while (atual->proximo != NULL && aluno.matricula > atual->proximo->aluno.matricula) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }

    lista->tamanho++;
}

void excluirElemento(ListaAlunos* lista, int matricula) {
    No* atual = lista->inicio;
    No* anterior = NULL;

    while (atual != NULL && atual->aluno.matricula != matricula) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            lista->inicio = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }
        free(atual);
        lista->tamanho--;
    }
}
