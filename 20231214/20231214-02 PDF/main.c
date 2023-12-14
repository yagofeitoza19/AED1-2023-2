#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeficiente;
    int expoente;
    struct Node* next;
} Node;

typedef struct Lista {
    Node* head;
} Lista;

void inicializarLista(Lista* lista) {
    lista->head = NULL;
}

void inserirOrdenado(Lista* lista, int coeficiente, int expoente) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o nó.\n");
        exit(EXIT_FAILURE);
    }
    newNode->coeficiente = coeficiente;
    newNode->expoente = expoente;
    newNode->next = NULL;

    if (lista->head == NULL || expoente > lista->head->expoente) {
        newNode->next = lista->head;
        lista->head = newNode;
    } else {
        Node* current = lista->head;
        while (current->next != NULL && expoente < current->next->expoente) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

Lista* somaPolinomios(Lista* P1, Lista* P2) {
    Lista* resultado = (Lista*)malloc(sizeof(Lista));
    if (resultado == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a lista de resultado.\n");
        exit(EXIT_FAILURE);
    }
    inicializarLista(resultado);

    Node* nodeP1 = P1->head;
    Node* nodeP2 = P2->head;

    while (nodeP1 != NULL || nodeP2 != NULL) {
        int coefP1 = (nodeP1 != NULL) ? nodeP1->coeficiente : 0;
        int expoP1 = (nodeP1 != NULL) ? nodeP1->expoente : -1;

        int coefP2 = (nodeP2 != NULL) ? nodeP2->coeficiente : 0;
        int expoP2 = (nodeP2 != NULL) ? nodeP2->expoente : -1;

        int somaCoef = coefP1 + coefP2;

        inserirOrdenado(resultado, somaCoef, expoP1 > expoP2 ? expoP1 : expoP2);

        if (expoP1 == expoP2) {
            nodeP1 = nodeP1->next;
            nodeP2 = nodeP2->next;
        } else if (expoP1 > expoP2) {
            nodeP1 = nodeP1->next;
        } else {
            nodeP2 = nodeP2->next;
        }
    }

    return resultado;
}

void exibirPolinomio(Lista* lista) {
    Node* current = lista->head;
    while (current != NULL) {
        printf("%dx^%d ", current->coeficiente, current->expoente);
        if (current->next != NULL) {
            printf("+ ");
        }
        current = current->next;
    }
    printf("\n");
}

void liberarLista(Lista* lista) {
    Node* current = lista->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    lista->head = NULL;
    free(lista);
}

int main() {
    Lista* polinomio1 = (Lista*)malloc(sizeof(Lista));
    Lista* polinomio2 = (Lista*)malloc(sizeof(Lista));

    if (polinomio1 == NULL || polinomio2 == NULL) {
        fprintf(stderr, "Erro ao alocar memória para polinômios.\n");
        exit(EXIT_FAILURE);
    }

    inicializarLista(polinomio1);
    inicializarLista(polinomio2);

    int grau1, grau2;
    printf("Informe o grau do primeiro polinômio: ");
    scanf("%d", &grau1);

    printf("Informe os coeficientes do primeiro polinômio em ordem decrescente:\n");
    for (int i = grau1; i >= 0; i--) {
        int coeficiente;
        printf("Coeficiente para x^%d: ", i);
        scanf("%d", &coeficiente);
        if (coeficiente != 0) {
            inserirOrdenado(polinomio1, coeficiente, i);
        }
    }

    printf("\nInforme o grau do segundo polinômio: ");
    scanf("%d", &grau2);

    printf("Informe os coeficientes do segundo polinômio em ordem decrescente:\n");
    for (int i = grau2; i >= 0; i--) {
        int coeficiente;
        printf("Coeficiente para x^%d: ", i);
        scanf("%d", &coeficiente);
        if (coeficiente != 0) {
            inserirOrdenado(polinomio2, coeficiente, i);
        }
    }

    printf("\nPolinômio 1: ");
    exibirPolinomio(polinomio1);

    printf("\nPolinômio 2: ");
    exibirPolinomio(polinomio2);

    Lista* resultado = somaPolinomios(polinomio1, polinomio2);

    printf("\nResultado da soma dos polinômios: ");
    exibirPolinomio(resultado);

    liberarLista(polinomio1);
    liberarLista(polinomio2);
    liberarLista(resultado);

    return 0;
}
