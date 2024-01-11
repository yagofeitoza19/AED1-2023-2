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

    if (tabela->pacientes[indice] == NULL || tabela->pacientes[indice]->disponivel == 1) {
        if (tabela->pacientes[indice] == NULL) {
            tabela->pacientes[indice] = (Paciente *)malloc(sizeof(Paciente));
        }

        tabela->pacientes[indice]->codigo = codigo;
        strcpy(tabela->pacientes[indice]->nome, nome);
        strcpy(tabela->pacientes[indice]->cpf, cpf);
        tabela->pacientes[indice]->idade = idade;
        tabela->pacientes[indice]->disponivel = 0;
    }
}

Paciente *buscarPaciente(TabelaHash *tabela, int codigo) {
    int indice = codigo % 100;

    if (tabela->pacientes[indice] != NULL && tabela->pacientes[indice]->codigo == codigo && tabela->pacientes[indice]->disponivel == 0) {
        return tabela->pacientes[indice];
    }

    return NULL;
}

void excluirPaciente(TabelaHash *tabela, int codigo) {
    int indice = codigo % 100;

    if (tabela->pacientes[indice] != NULL && tabela->pacientes[indice]->codigo == codigo) {
        tabela->pacientes[indice]->disponivel = 1;
    }
}

void imprimirTabela(TabelaHash *tabela) {
    for (int i = 0; i < 100; i++) {
        if (tabela->pacientes[i] != NULL && tabela->pacientes[i]->disponivel == 0) {
            printf("Código: %d, Nome: %s, CPF: %s, Idade: %d\n", tabela->pacientes[i]->codigo, tabela->pacientes[i]->nome, tabela->pacientes[i]->cpf, tabela->pacientes[i]->idade);
        }
    }
}

void liberarTabelaHash(TabelaHash *tabela) {
    for (int i = 0; i < 100; i++) {
        if (tabela->pacientes[i] != NULL) {
            free(tabela->pacientes[i]);
        }
    }
    free(tabela);
}
