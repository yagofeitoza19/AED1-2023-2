#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"

TabelaHash *criarTabelaHash() {
    TabelaHash *tabela = (TabelaHash *)malloc(sizeof(TabelaHash));
    for (int i = 0; i < 100; i++) {
        tabela->pacientes[i] = NULL;
    }
    return tabela;
}

void inserirPaciente(TabelaHash *tabela, int codigo, const char *nome, const char *cpf, int idade) {
    int indice = codigo % 100;

    NodoPaciente *novoNodo = (NodoPaciente *)malloc(sizeof(NodoPaciente));
    novoNodo->prox = NULL;

    if (tabela->pacientes[indice] == NULL || tabela->pacientes[indice]->paciente.disponivel == 1) {
        if (tabela->pacientes[indice] != NULL) {
            free(tabela->pacientes[indice]);
        }

        tabela->pacientes[indice] = novoNodo;
        tabela->pacientes[indice]->paciente.codigo = codigo;
        strcpy(tabela->pacientes[indice]->paciente.nome, nome);
        strcpy(tabela->pacientes[indice]->paciente.cpf, cpf);
        tabela->pacientes[indice]->paciente.idade = idade;
        tabela->pacientes[indice]->paciente.disponivel = 0;
    } else {
        free(novoNodo);
    }
}

Paciente *buscarPaciente(TabelaHash *tabela, int codigo) {
    int indice = codigo % 100;
    NodoPaciente *atual = tabela->pacientes[indice];

    while (atual != NULL) {
        if (atual->paciente.codigo == codigo) {
            return &(atual->paciente);
        }
        atual = atual->prox;
    }

    return NULL;
}

void excluirPaciente(TabelaHash *tabela, int codigo) {
    int indice = codigo % 100;
    NodoPaciente *atual = tabela->pacientes[indice];
    NodoPaciente *anterior = NULL;

    while (atual != NULL && atual->paciente.codigo != codigo) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        atual->paciente.disponivel = 1;
        if (anterior != NULL) {
            anterior->prox = atual->prox;
        } else {
            tabela->pacientes[indice] = atual->prox;
        }
        free(atual);
    }
}

void imprimirTabela(TabelaHash *tabela) {
    for (int i = 0; i < 100; i++) {
        NodoPaciente *atual = tabela->pacientes[i];
        while (atual != NULL) {
            printf("Código: %d, Nome: %s, CPF: %s, Idade: %d\n", atual->paciente.codigo, atual->paciente.nome, atual->paciente.cpf, atual->paciente.idade);
            atual = atual->prox;
        }
    }
}

void liberarTabelaHash(TabelaHash *tabela) {
    for (int i = 0; i < 100; i++) {
        NodoPaciente *atual = tabela->pacientes[i];
        while (atual != NULL) {
            NodoPaciente *proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
    }
    free(tabela);
}
