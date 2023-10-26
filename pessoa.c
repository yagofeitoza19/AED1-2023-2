#include <stdio.h>
#include "pessoa.h"

void preencherPessoa(Pessoa *pessoa) {
    printf("Digite o nome: ");
    scanf("%49s", pessoa->nome);

    printf("Digite a data de nascimento (DD/MM/AAAA): ");
    scanf("%10s", pessoa->dataNascimento);

    printf("Digite o CPF (apenas números): ");
    scanf("%11s", pessoa->cpf);
}

void imprimirPessoa(const Pessoa *pessoa) {
    printf("Nome: %s\n", pessoa->nome);
    printf("Data de Nascimento: %s\n", pessoa->dataNascimento);
    printf("CPF: %s\n", pessoa->cpf);
}
