#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    int codigo;
    char nome[50];
    char cpf[15];
    int idade;
} Paciente;

typedef struct NodoPaciente {
    Paciente paciente;
    struct NodoPaciente *prox;
} NodoPaciente;

typedef struct {
    NodoPaciente *pacientes[100];
} TabelaHash;

TabelaHash *criarTabelaHash();
void inserirPaciente(TabelaHash *tabela, int codigo, const char *nome, const char *cpf, int idade);
Paciente *buscarPaciente(TabelaHash *tabela, int codigo);
void imprimirTabela(TabelaHash *tabela);
void liberarTabelaHash(TabelaHash *tabela);

#endif
