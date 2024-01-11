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
    NodoPaciente *novoPaciente = (NodoPaciente *)malloc(sizeof(NodoPaciente));
    novoPaciente->prox = NULL;
    novoPaciente->codigo = codigo;
    strcpy(novoPaciente->nome, nome);
    strcpy(novoPaciente->cpf, cpf);
    novoPaciente->idade = idade;

    int indice = codigo % 100;

    if (tabela->pacientes[indice] == NULL) {
        tabela->pacientes[indice] = novoPaciente;
    } else {
        novoPaciente->prox = tabela->pacientes[indice];
        tabela->pacientes[indice] = novoPaciente;
    }
}

NodoPaciente *buscarPaciente(TabelaHash *tabela, int codigo) {
    int indice = codigo % 100;
    NodoPaciente *atual = tabela->pacientes[indice];

    while (atual != NULL) {
        if (atual->codigo == codigo) {
            return atual;
        }
        atual = atual->prox;
    }

    return NULL;
}

void imprimirTabela(TabelaHash *tabela) {
    for (int i = 0; i < 100; i++) {
        NodoPaciente *atual = tabela->pacientes[i];
        while (atual != NULL) {
            printf("Código: %d, Nome: %s, CPF: %s, Idade: %d\n", atual->codigo, atual->nome, atual->cpf, atual->idade);
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
