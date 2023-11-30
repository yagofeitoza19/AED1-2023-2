#include "lista_ligada_estatica.h"

void inicializarLista(ListaLigadaEstatica *lista) {
    lista->tamanho = 0;
}

void adicionarElemento(ListaLigadaEstatica *lista, int elemento) {
    if (lista->tamanho < MAX_TAMANHO_LISTA) {
        lista->elementos[lista->tamanho++] = elemento;
    }
}

void percorrerLista(ListaLigadaEstatica *lista, void (*funcao)(int)) {
    for (int i = 0; i < lista->tamanho; i++) {
        funcao(lista->elementos[i]);
    }
}

ListaLigadaEstatica copiarLista(ListaLigadaEstatica *lista) {
    ListaLigadaEstatica copia;
    inicializarLista(&copia);

    for (int i = 0; i < lista->tamanho; i++) {
        adicionarElemento(&copia, lista->elementos[i]);
    }

    return copia;
}

ListaLigadaEstatica concatenarListas(ListaLigadaEstatica *lista1, ListaLigadaEstatica *lista2) {
    ListaLigadaEstatica concatenacao;
    inicializarLista(&concatenacao);

    for (int i = 0; i < lista1->tamanho; i++) {
        adicionarElemento(&concatenacao, lista1->elementos[i]);
    }

    for (int i = 0; i < lista2->tamanho; i++) {
        adicionarElemento(&concatenacao, lista2->elementos[i]);
    }

    return concatenacao;
}

ListaLigadaEstatica intercalarListas(ListaLigadaEstatica *lista1, ListaLigadaEstatica *lista2) {
    ListaLigadaEstatica intercalacao;
    inicializarLista(&intercalacao);

    int tamanhoMaximo = lista1->tamanho > lista2->tamanho ? lista1->tamanho : lista2->tamanho;

    for (int i = 0; i < tamanhoMaximo; i++) {
        if (i < lista1->tamanho) {
            adicionarElemento(&intercalacao, lista1->elementos[i]);
        }
        if (i < lista2->tamanho) {
            adicionarElemento(&intercalacao, lista2->elementos[i]);
        }
    }

    return intercalacao;
}

