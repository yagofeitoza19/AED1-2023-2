#include <stdio.h>
#include <stdlib.h>
#include "deque_soldados.h"

void resolver_josephus(DequeSoldados* deque, int n) {
    while (contar(deque) > 1) {
        for (int i = 1; i < n; i++) {
            Soldado* removido = remover_inicio(deque);
            inserir_fim(deque, removido->codigo, removido->nome, removido->grau);
        }

        Soldado* eliminado = remover_inicio(deque);
        printf("Soldado eliminado: Código: %d, Nome: %s, Grau: %s\n", eliminado->codigo, eliminado->nome, eliminado->grau);
    }

    Soldado* sobrevivente = primeiro(deque);
    printf("Soldado que escapará: Código: %d, Nome: %s, Grau: %s\n", sobrevivente->codigo, sobrevivente->nome, sobrevivente->grau);
}

int main() {
    DequeSoldados* deque = criar_deque();

    inserir_fim(deque, 1, "Soldado A", "Grau 1");
    inserir_fim(deque, 2, "Soldado B", "Grau 2");
    inserir_fim(deque, 3, "Soldado C", "Grau 3");
    inserir_fim(deque, 4, "Soldado D", "Grau 4");
    inserir_fim(deque, 5, "Soldado E", "Grau 5");

    printf("Soldados no início:\n");
    imprimir_soldados(deque);

    int n = 3;
    printf("\nResolvendo Josephus com n = %d:\n", n);
    resolver_josephus(deque, n);

    liberar_deque(deque);

    return 0;
}
