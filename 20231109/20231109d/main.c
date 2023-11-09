#include <stdio.h>

int calcular_produto(int vetor[], int tamanho) {
    if (tamanho == 0) {
        return 1;
    } else {
        return vetor[tamanho - 1] * calcular_produto(vetor, tamanho - 1);
    }
}

int main() {
    int tamanho;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];
    printf("Informe os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    int produto = calcular_produto(vetor, tamanho);
    printf("Produto dos elementos: %d\n", produto);

    return 0;
}
