#include <stdio.h>
#include "pessoa.h"

void preencherPessoa(Pessoa *pessoa) {
    printf("Digite o nome: ");
    scanf("%49s", pessoa->nome);

    preencherData(&pessoa->dataNascimento);

    printf("Digite o CPF (apenas números): ");
    scanf("%11s", pessoa->cpf);
}

void imprimirPessoa(const Pessoa *pessoa) {
    printf("Nome: %s\n", pessoa->nome);
    imprimirData(&pessoa->dataNascimento);
    printf("CPF: %s\n", pessoa->cpf);
}
