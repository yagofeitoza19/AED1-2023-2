#include <stdio.h>
#include "data.h"

void preencherData(Data *data) {
    printf("Digite o dia: ");
    scanf("%d", &data->dia);

    printf("Digite o mês: ");
    scanf("%d", &data->mes);

    printf("Digite o ano: ");
    scanf("%d", &data->ano);
}

void imprimirData(const Data *data) {
    printf("Data de Nascimento: %02d/%02d/%04d\n", data->dia, data->mes, data->ano);
}
