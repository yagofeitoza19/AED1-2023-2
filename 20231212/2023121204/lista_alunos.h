#ifndef LISTA_ALUNOS_H
#define LISTA_ALUNOS_H

#include "aluno.h"

typedef struct Node {
    Aluno aluno;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct ListaAlunos {
    Node* head;
} ListaAlunos;

void inicializarLista(ListaAlunos* lista);
void reiniciarLista(ListaAlunos* lista);
int quantidadeElementos(ListaAlunos* lista);
int listaCheia(ListaAlunos* lista);
int listaVazia(ListaAlunos* lista);
void exibirElementos(ListaAlunos* lista);
void inserirOrdenado(ListaAlunos* lista, Aluno aluno);
void excluirElemento(ListaAlunos* lista, int matricula);

#endif
