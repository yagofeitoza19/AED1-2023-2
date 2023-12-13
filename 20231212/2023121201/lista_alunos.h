#ifndef LISTA_ALUNOS_H
#define LISTA_ALUNOS_H

#include "aluno.h"

typedef struct No {
    Aluno aluno;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    int tamanho;
} ListaAlunos;

void inicializarLista(ListaAlunos* lista);
void reiniciarLista(ListaAlunos* lista);
int quantidadeElementos(ListaAlunos* lista);
int listaCheia(ListaAlunos* lista);
int listaVazia(ListaAlunos* lista);
void exibirElementos(ListaAlunos* lista);
void inserirElemento(ListaAlunos* lista, Aluno aluno);
void excluirElemento(ListaAlunos* lista, int matricula);

#endif
