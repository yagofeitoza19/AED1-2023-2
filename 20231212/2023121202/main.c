#include "linkedlist.h"
#include <stddef.h>

int main() {
    Node* myList = NULL;

    int numElements;
    printf("Quantos elementos deseja inserir na lista? ");
    scanf("%d", &numElements);

    for (int i = 0; i < numElements; ++i) {
        int element;
        printf("Insira o elemento %d: ", i + 1);
        scanf("%d", &element);
        insertAtEnd(&myList, element);
    }

    printf("Lista original: ");
    printList(myList);

    Node* newListA = operationA(myList);

    printf("Operação a): ");
    printList(newListA);

    return 0;
}
