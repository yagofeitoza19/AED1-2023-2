#include <stdio.h>

int calcular_soma(int vetor[], int tamanho) {
    if (tamanho == 0) {
        return 0;
    } else {
        return vetor[tamanho - 1] + calcular_soma(vetor, tamanho - 1);
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

    int soma = calcular_soma(vetor, tamanho);
    printf("Soma dos elementos: %d\n", soma);

    return 0;
}
