#include <stdio.h>
#include "paciente.h"

int main() {
    TabelaHash *tabela = criarTabelaHash();

    int codigo;
    char nome[50];
    char cpf[15];
    int idade;

    for (int i = 0; i < 3; i++) {
        printf("Insira os dados do paciente %d:\n", i + 1);

        printf("Código: ");
        scanf("%d", &codigo);

        printf("Nome: ");
        scanf("%s", nome);

        printf("CPF: ");
        scanf("%s", cpf);

        printf("Idade: ");
        scanf("%d", &idade);

        inserirPaciente(tabela, codigo, nome, cpf, idade);
    }

    int codigoBusca;
    printf("Digite o código do paciente para busca: ");
    scanf("%d", &codigoBusca);

    Paciente *p = buscarPaciente(tabela, codigoBusca);
    if (p != NULL) {
        printf("Paciente encontrado: Código %d, Nome: %s, CPF: %s, Idade: %d\n", p->codigo, p->nome, p->cpf, p->idade);
    } else {
        printf("Paciente não encontrado.\n");
    }

    printf("Digite o código do paciente para exclusão: ");
    scanf("%d", &codigoBusca);
    excluirPaciente(tabela, codigoBusca);
    printf("Paciente excluído.\n");

    imprimirTabela(tabela);

    liberarTabelaHash(tabela);

    return 0;
}
