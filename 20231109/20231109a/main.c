#include <stdio.h>

int encontrar_maximo(int vetor[], int tamanho) {
    if (tamanho == 1) {
        return vetor[0];
    } else {
        int max_resto = encontrar_maximo(vetor, tamanho - 1);
        return (max_resto > vetor[tamanho - 1]) ? max_resto : vetor[tamanho - 1];
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

    int maximo = encontrar_maximo(vetor, tamanho);
    printf("Elemento máximo: %d\n", maximo);

    return 0;
}
