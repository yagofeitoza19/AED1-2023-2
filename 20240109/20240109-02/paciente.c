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
    Paciente novoPaciente;
    novoPaciente.codigo = codigo;
    strcpy(novoPaciente.nome, nome);
    strcpy(novoPaciente.cpf, cpf);
    novoPaciente.idade = idade;

    int indice = codigo % 100;

    NodoPaciente *novoNodo = (NodoPaciente *)malloc(sizeof(NodoPaciente));
    novoNodo->paciente = novoPaciente;
    novoNodo->prox = tabela->pacientes[indice];
    tabela->pacientes[indice] = novoNodo;
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
