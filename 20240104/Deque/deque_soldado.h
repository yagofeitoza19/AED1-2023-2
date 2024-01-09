#ifndef DEQUE_SOLDADOS_H
#define DEQUE_SOLDADOS_H

typedef struct Soldado {
    int codigo;
    char nome[50];
    char grau[10];
    struct Soldado* proximo;
    struct Soldado* anterior;
} Soldado;

typedef struct DequeSoldados {
    Soldado* inicio;
    Soldado* fim;
    int tamanho;
} DequeSoldados;

DequeSoldados* criar_deque();
int inserir_inicio(DequeSoldados* deque, int codigo, const char* nome, const char* grau);
int inserir_fim(DequeSoldados* deque, int codigo, const char* nome, const char* grau);
Soldado* remover_inicio(DequeSoldados* deque);
Soldado* remover_fim(DequeSoldados* deque);
Soldado* primeiro(DequeSoldados* deque);
Soldado* ultimo(DequeSoldados* deque);
int contar(DequeSoldados* deque);
int vazia(DequeSoldados* deque);
void imprimir_soldados(DequeSoldados* deque);
void liberar_deque(DequeSoldados* deque);

#endif
