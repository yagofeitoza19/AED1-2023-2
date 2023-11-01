#include "complexo.h"
#include <stdio.h>
#include <stdlib.h>

Complexo* criar_complexo(double real, double imaginario) {
    Complexo* numero = (Complexo*)malloc(sizeof(Complexo));
    numero->real = real;
    numero->imaginario = imaginario;
    return numero;
}

void destruir_complexo(Complexo* numero) {
    free(numero);
}

Complexo* somar_complexos(Complexo* num1, Complexo* num2) {
    Complexo* resultado = criar_complexo(0, 0);
    resultado->real = num1->real + num2->real;
    resultado->imaginario = num1->imaginario + num2->imaginario;
    return resultado;
}

Complexo* subtrair_complexos(Complexo* num1, Complexo* num2) {
    Complexo* resultado = criar_complexo(0, 0);
    resultado->real = num1->real - num2->real;
    resultado->imaginario = num1->imaginario - num2->imaginario;
    return resultado;
}

Complexo* multiplicar_complexos(Complexo* num1, Complexo* num2) {
    Complexo* resultado = criar_complexo(0, 0);
    resultado->real = num1->real * num2->real - num1->imaginario * num2->imaginario;
    resultado->imaginario = num1->real * num2->imaginario + num1->imaginario * num2->real;
    return resultado;
}

Complexo* dividir_complexos(Complexo* num1, Complexo* num2) {
    Complexo* resultado = criar_complexo(0, 0);
    double divisor = num2->real * num2->real + num2->imaginario * num2->imaginario;
    resultado->real = (num1->real * num2->real + num1->imaginario * num2->imaginario) / divisor;
    resultado->imaginario = (num1->imaginario * num2->real - num1->real * num2->imaginario) / divisor;
    return resultado;
}
