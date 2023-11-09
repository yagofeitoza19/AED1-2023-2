#include <stdio.h>

int encontrar_minimo(int vetor[], int tamanho) {
    if (tamanho == 1) {
        return vetor[0];
    } else {
        int min_resto = encontrar_minimo(vetor, tamanho - 1);
        return (min_resto < vetor[tamanho - 1]) ? min_resto : vetor[tamanho - 1];
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

    int minimo = encontrar_minimo(vetor, tamanho);
    printf("Elemento mínimo: %d\n", minimo);

    return 0;
}
