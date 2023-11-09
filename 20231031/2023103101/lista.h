#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int *elementos;
    int quantidade;
} LISTA;

LISTA criar_lista(int tamanho);
void liberar_lista(LISTA *lista);
void inserir_elemento(LISTA *lista, int elemento);
void imprimir_lista(LISTA lista);
int buscar_sequencial(LISTA lista, int elemento);
int buscar_sequencial_ordenada(LISTA lista, int elemento);
int buscar_binaria(LISTA lista, int elemento);
int buscar_binaria_recursiva(LISTA lista, int elemento);
int buscar_maior(LISTA lista);
int buscar_menor(LISTA lista);
int calcular_soma(LISTA lista);
int calcular_produto(LISTA lista);

#endif
