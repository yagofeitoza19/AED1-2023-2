#include "lista_alunos.h"
#include <stdio.h>

void inicializarLista(ListaAlunos *lista) {
    lista->quantidade = 0;
}

void liberarLista(ListaAlunos *lista) {
    lista->quantidade = 0;
}

int tamanhoLista(ListaAlunos *lista) {
    return lista->quantidade;
}

int listaCheia(ListaAlunos *lista) {
    return lista->quantidade == MAX_ALUNOS;
}

int listaVazia(ListaAlunos *lista) {
    return lista->quantidade == 0;
}

void exibirLista(ListaAlunos *lista) {
    printf("Lista de Alunos: ");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

void inserirElemento(ListaAlunos *lista, int matricula) {
    if (listaCheia(lista)) {
        printf("Erro: Lista cheia, não é possível inserir mais elementos.\n");
        return;
    }

    int posicao = 0;
    while (posicao < lista->quantidade && lista->elementos[posicao] < matricula) {
        posicao++;
    }

    for (int i = lista->quantidade; i > posicao; i--) {
        lista->elementos[i] = lista->elementos[i - 1];
    }

    lista->elementos[posicao] = matricula;
    lista->quantidade++;
}

void excluirElemento(ListaAlunos *lista, int matricula) {
    int posicao = 0;

    while (posicao < lista->quantidade && lista->elementos[posicao] < matricula) {
        posicao++;
    }

    if (posicao < lista->quantidade && lista->elementos[posicao] == matricula) {
        for (int i = posicao; i < lista->quantidade - 1; i++) {
            lista->elementos[i] = lista->elementos[i + 1];
        }

        lista->quantidade--;
    } else {
        printf("Erro: Matrícula não encontrada na lista.\n");
    }
}

void alterarMatricula(ListaAlunos *lista, int matriculaAntiga, int novaMatricula) {
    excluirElemento(lista, matriculaAntiga);
    inserirElemento(lista, novaMatricula);
}
