#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct Complexo {
    double real;
    double imaginario;
} Complexo;

Complexo* criar_complexo(double real, double imaginario);
void destruir_complexo(Complexo* numero);
Complexo* somar_complexos(Complexo* num1, Complexo* num2);
Complexo* subtrair_complexos(Complexo* num1, Complexo* num2);
Complexo* multiplicar_complexos(Complexo* num1, Complexo* num2);
Complexo* dividir_complexos(Complexo* num1, Complexo* num2);

#endif
