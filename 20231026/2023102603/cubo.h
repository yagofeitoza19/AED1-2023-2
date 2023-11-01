#ifndef CUBO_H
#define CUBO_H

typedef struct Cubo {
    double lado;
} Cubo;

Cubo* criar_cubo(double lado);
void destruir_cubo(Cubo* cubo);
double obter_lado(Cubo* cubo);
void definir_lado(Cubo* cubo, double novo_lado);
double calcular_area(Cubo* cubo);
double calcular_volume(Cubo* cubo);

#endif
