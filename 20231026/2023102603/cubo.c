#include "cubo.h"
#include <stdio.h>

Cubo* criar_cubo(double lado) {
    Cubo* cubo = (Cubo*)malloc(sizeof(Cubo));
    cubo->lado = lado;
    return cubo;
}

void destruir_cubo(Cubo* cubo) {
    free(cubo);
}

double obter_lado(Cubo* cubo) {
    return cubo->lado;
}

void definir_lado(Cubo* cubo, double novo_lado) {
    cubo->lado = novo_lado;
}

double calcular_area(Cubo* cubo) {
    return 6 * cubo->lado * cubo->lado;
}

double calcular_volume(Cubo* cubo) {
    return cubo->lado * cubo->lado * cubo->lado;
}
