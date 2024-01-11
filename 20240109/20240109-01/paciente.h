#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct NodoPaciente {
    struct NodoPaciente *prox;
    int codigo;
    char nome[50];
    char cpf[15];
    int idade;
} NodoPaciente;

typedef struct {
    NodoPaciente *pacientes[100];
} TabelaHash;

TabelaHash *criarTabelaHash();
void inserirPaciente(TabelaHash *tabela, int codigo, const char *nome, const char *cpf, int idade);
NodoPaciente *buscarPaciente(TabelaHash *tabela, int codigo);
void imprimirTabela(TabelaHash *tabela);
void liberarTabelaHash(TabelaHash *tabela);

#endif
