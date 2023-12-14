#include "lista_alunos.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarLista(ListaAlunos* lista) {
    lista->head = NULL;
}

void reiniciarLista(ListaAlunos* lista) {
    while (lista->head != NULL) {
        Node* temp = lista->head;
        lista->head = lista->head->next;
        free(temp);
    }
}

int quantidadeElementos(ListaAlunos* lista) {
    int count = 0;
    Node* current = lista->head;

    while (current != NULL) {
        count++;
        current = current->next;
        if (current == lista->head) {
            break;
        }
    }

    return count;
}

int listaCheia(ListaAlunos* lista) {
    return 0;
}

int listaVazia(ListaAlunos* lista) {
    return lista->head == NULL;
}

void exibirElementos(ListaAlunos* lista) {
    if (listaVazia(lista)) {
        printf("A lista está vazia.\n");
        return;
    }

    Node* current = lista->head;

    do {
        printf("Matrícula: %d, Nome: %s, Idade: %d\n", current->aluno.matricula, current->aluno.nome, current->aluno.idade);
        current = current->next;
    } while (current != lista->head);
}

void inserirOrdenado(ListaAlunos* lista, Aluno aluno) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o nó.\n");
        exit(EXIT_FAILURE);
    }

    newNode->aluno = aluno;

    if (listaVazia(lista) || aluno.matricula < lista->head->aluno.matricula) {
        newNode->next = lista->head;
        newNode->prev = (lista->head != NULL) ? lista->head->prev : NULL;

        if (lista->head != NULL) {
            lista->head->prev = newNode;
        }

        lista->head = newNode;
    } else {
        Node* current = lista->head;

        while (current->next != NULL && aluno.matricula > current->next->aluno.matricula) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }

        current->next = newNode;
    }
}

void excluirElemento(ListaAlunos* lista, int matricula) {
    if (listaVazia(lista)) {
        printf("A lista está vazia.\n");
        return;
    }

    Node* current = lista->head;
    Node* toDelete = NULL;

    do {
        if (current->aluno.matricula == matricula) {
            toDelete = current;
            break;
        }

        current = current->next;
    } while (current != lista->head);

    if (toDelete != NULL) {
        if (toDelete == lista->head) {
            lista->head = toDelete->next;
        }

        if (toDelete->prev != NULL) {
            toDelete->prev->next = toDelete->next;
        }

        if (toDelete->next != NULL) {
            toDelete->next->prev = toDelete->prev;
        }

        free(toDelete);
    } else {
        printf("Matrícula %d não encontrada na lista.\n", matricula);
    }
}
