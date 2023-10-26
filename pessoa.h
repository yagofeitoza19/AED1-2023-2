#ifndef PESSOA_H
#define PESSOA_H

typedef struct {
    char nome[50];
    char dataNascimento[11];
    char cpf[12];
} Pessoa;

void preencherPessoa(Pessoa *pessoa);
void imprimirPessoa(const Pessoa *pessoa);

#endif
