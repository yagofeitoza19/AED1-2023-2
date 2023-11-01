#include <stdio.h>
#include "cubo.h"

int main() {
    Cubo* cubo1 = criar_cubo(5.0);

    printf("Lado do cubo: %.2f\n", obter_lado(cubo1));
    printf("Área do cubo: %.2f\n", calcular_area(cubo1));
    printf("Volume do cubo: %.2f\n", calcular_volume(cubo1));

    definir_lado(cubo1, 7.0);
    printf("Novo lado do cubo: %.2f\n", obter_lado(cubo1));
    printf("Nova área do cubo: %.2f\n", calcular_area(cubo1));
    printf("Novo volume do cubo: %.2f\n", calcular_volume(cubo1));

    destruir_cubo(cubo1);

    return 0;
}
