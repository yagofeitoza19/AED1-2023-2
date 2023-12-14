#include "linkedlist.h"
#include <stdio.h>

int main() {
    Node* l1 = NULL;
    Node* l2 = NULL;

    int numElementsL1, numElementsL2;

    printf("Quantos elementos deseja inserir na lista l1? ");
    scanf("%d", &numElementsL1);

    for (int i = 0; i < numElementsL1; ++i) {
        int element;
        printf("Insira o elemento %d para l1: ", i + 1);
        scanf("%d", &element);
        insertAtEnd(&l1, element);
    }

    printf("Quantos elementos deseja inserir na lista l2? ");
    scanf("%d", &numElementsL2);

    for (int i = 0; i < numElementsL2; ++i) {
        int element;
        printf("Insira o elemento %d para l2: ", i + 1);
        scanf("%d", &element);
        insertAtEnd(&l2, element);
    }

    Node* l2Copy = copyList(l1);
    Node* concatenatedList = concatenateLists(l1, l2);
    Node* interleavedList = interleaveLists(l1, l2);

    printf("Cópia de l1 para l2: ");
    printList(l2Copy);

    printf("Concatenação de l1 e l2: ");
    printList(concatenatedList);

    printf("Intercalação de l1 e l2: ");
    printList(interleavedList);

    return 0;
}
