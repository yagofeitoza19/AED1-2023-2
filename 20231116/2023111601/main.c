#include <stdio.h>

int K_esimoDigito(int n, int k) {
    if (k == 1) {
        return n % 10;
    } else {
        return K_esimoDigito(n / 10, k - 1);
    }
}

int main() {
    int numero, k;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    printf("Digite a posição do dígito desejado: ");
    scanf("%d", &k);

    int resultado = K_esimoDigito(numero, k);
    printf("O %d-ésimo dígito de %d é %d\n", k, numero, resultado);

    return 0;
}
