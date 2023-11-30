#ifndef LISTA_ALUNOS_H
#define LISTA_ALUNOS_H

#define MAX_ALUNOS 100

typedef struct {
    int elementos[MAX_ALUNOS];
    int quantidade;
} ListaAlunos;

void inicializarLista(ListaAlunos *lista);
void liberarLista(ListaAlunos *lista);
int tamanhoLista(ListaAlunos *lista);
int listaCheia(ListaAlunos *lista);
int listaVazia(ListaAlunos *lista);
void exibirLista(ListaAlunos *lista);
void inserirElemento(ListaAlunos *lista, int matricula);
void excluirElemento(ListaAlunos *lista, int matricula);
void alterarMatricula(ListaAlunos *lista, int matriculaAntiga, int novaMatricula);

#endif
