#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int *vetor;
    int quantidade;
} Lista;

Lista criarLista(int tamanho);
void liberarLista(Lista *lista);
void inserirElemento(Lista *lista, int elemento);
void inserirElementoOrdenado(Lista *lista, int elemento);
void imprimirListaIterativo(Lista lista);
int buscaBinariaRecursiva(Lista lista, int elemento, int inicio, int fim);
void imprimirListaRecursivo(Lista lista, int indice);
int buscarMaiorRecursivo(Lista lista, int indice);
int buscarMenorRecursivo(Lista lista, int indice);
int somarElementosRecursivo(Lista lista, int indice);
int multiplicarElementosRecursivo(Lista lista, int indice);

#endif
