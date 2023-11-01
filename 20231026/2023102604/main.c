#include <stdio.h>
#include "complexo.h"

int main() {
    double real1, imaginario1, real2, imaginario2;

    printf("Digite a parte real do primeiro número complexo: ");
    scanf("%lf", &real1);
    printf("Digite a parte imaginária do primeiro número complexo: ");
    scanf("%lf", &imaginario1);

    printf("Digite a parte real do segundo número complexo: ");
    scanf("%lf", &real2);
    printf("Digite a parte imaginária do segundo número complexo: ");
    scanf("%lf", &imaginario2);

    Complexo* num1 = criar_complexo(real1, imaginario1);
    Complexo* num2 = criar_complexo(real2, imaginario2);

    Complexo* soma = somar_complexos(num1, num2);
    Complexo* subtracao = subtrair_complexos(num1, num2);
    Complexo* multiplicacao = multiplicar_complexos(num1, num2);
    Complexo* divisao = dividir_complexos(num1, num2);

    printf("Num1 = %.1f + %.1fi\n", num1->real, num1->imaginario);
    printf("Num2 = %.1f + %.1fi\n", num2->real, num2->imaginario);
    printf("Soma = %.1f + %.1fi\n", soma->real, soma->imaginario);
    printf("Subtração = %.1f + %.1fi\n", subtracao->real, subtracao->imaginario);
    printf("Multiplicação = %.1f + %.1fi\n", multiplicacao->real, multiplicacao->imaginario);
    printf("Divisão = %.1f + %.1fi\n", divisao->real, divisao->imaginario);

    destruir_complexo(num1);
    destruir_complexo(num2);
    destruir_complexo(soma);
    destruir_complexo(subtracao);
    destruir_complexo(multiplicacao);
    destruir_complexo(divisao);

    return 0;
}
