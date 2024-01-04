#ifndef FILA_H
#define FILA_H

typedef struct {
    char nome[50];
    int identificador;
    char outras_caracteristicas[100];
} Aviao;

typedef struct {
    Aviao* elementos;
    int capacidade;
    int tamanho;
    int inicio;
    int fim;
} Fila;

Fila* criar_fila(int capacidade);
void destruir_fila(Fila* fila);
int fila_vazia(Fila* fila);
int fila_cheia(Fila* fila);
void enfileirar(Fila* fila, Aviao aviao);
Aviao desenfileirar(Fila* fila);
Aviao frente_fila(Fila* fila);

#endif
