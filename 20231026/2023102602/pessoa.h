#ifndef PESSOA_H
#define PESSOA_H
#include "data.h"

typedef struct {
    char nome[50];
    Data dataNascimento;
    char cpf[12];
} Pessoa;

void preencherPessoa(Pessoa *pessoa);
void imprimirPessoa(const Pessoa *pessoa);

#endif
