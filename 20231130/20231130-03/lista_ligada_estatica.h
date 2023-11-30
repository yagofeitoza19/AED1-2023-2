#ifndef LISTA_LIGADA_ESTATICA_H
#define LISTA_LIGADA_ESTATICA_H

#define MAX_TAMANHO_LISTA 100

typedef struct {
    int elementos[MAX_TAMANHO_LISTA];
    int tamanho;
} ListaLigadaEstatica;

void inicializarLista(ListaLigadaEstatica *lista);
void adicionarElemento(ListaLigadaEstatica *lista, int elemento);
void percorrerLista(ListaLigadaEstatica *lista, void (*funcao)(int));
ListaLigadaEstatica construirListaA(ListaLigadaEstatica *lista);
ListaLigadaEstatica construirListaB(ListaLigadaEstatica *lista);

#endif
