#include "lista_ligada_estatica.h"
#include <stdio.h>

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

ListaLigadaEstatica construirListaA(ListaLigadaEstatica *lista) {
    ListaLigadaEstatica listaA;
    inicializarLista(&listaA);

    for (int i = 1; i < lista->tamanho; i++) {
        adicionarElemento(&listaA, lista->elementos[i]);
    }

    adicionarElemento(&listaA, lista->elementos[0]);

    return listaA;
}

ListaLigadaEstatica construirListaB(ListaLigadaEstatica *lista) {
    ListaLigadaEstatica listaB;
    inicializarLista(&listaB);

    for (int i = lista->tamanho - 1; i >= 0; i--) {
        adicionarElemento(&listaB, lista->elementos[i]);
    }

    return listaB;
}
