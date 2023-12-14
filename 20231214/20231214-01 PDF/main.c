#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
} List;

void initList(List* list) {
    list->head = NULL;
    list->tail = NULL;
}

void insertAtEnd(List* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o nó.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void displayList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void createOrderedList(List* L, List* K) {
    while (L->head != NULL) {
        Node* maxNode = L->head;
        Node* current = L->head->next;

        while (current != NULL) {
            if (current->data > maxNode->data) {
                maxNode = current;
            }
            current = current->next;
        }

        if (maxNode->prev != NULL) {
            maxNode->prev->next = maxNode->next;
        } else {
            L->head = maxNode->next;
        }

        if (maxNode->next != NULL) {
            maxNode->next->prev = maxNode->prev;
        }

        if (K->head == NULL) {
            K->head = maxNode;
            K->tail = maxNode;
            maxNode->next = NULL;
            maxNode->prev = NULL;
        } else {
            maxNode->next = K->head;
            K->head->prev = maxNode;
            K->head = maxNode;
            maxNode->prev = NULL;
        }
    }
}

int main() {
    List L, K;
    initList(&L);
    initList(&K);

    int numElements;
    printf("Quantos elementos deseja inserir na lista L? ");
    scanf("%d", &numElements);

    for (int i = 0; i < numElements; ++i) {
        int element;
        printf("Insira o elemento %d para a lista L: ", i + 1);
        scanf("%d", &element);
        insertAtEnd(&L, element);
    }

    printf("\nLista L antes da ordenação:\n");
    displayList(&L);

    createOrderedList(&L, &K);

    printf("\nLista K após a ordenação:\n");
    displayList(&K);

    return 0;
}
