#include <stdio.h>
#include "pessoa.h"

int main() {
    Pessoa pessoa;

    preencherPessoa(&pessoa);

    printf("\nDados da Pessoa:\n");
    imprimirPessoa(&pessoa);

    return 0;
}
