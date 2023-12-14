#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o nó.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Node* copyList(Node* original) {
    Node* newHead = NULL;
    Node* current = original;

    while (current != NULL) {
        insertAtEnd(&newHead, current->data);
        current = current->next;
    }

    return newHead;
}

Node* concatenateLists(Node* l1, Node* l2) {
    if (l1 == NULL) {
        return copyList(l2);
    }

    Node* concatenatedList = copyList(l1);
    Node* current = concatenatedList;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = copyList(l2);

    return concatenatedList;
}

Node* interleaveLists(Node* l1, Node* l2) {
    Node* interleavedList = NULL;

    while (l1 != NULL && l2 != NULL) {
        insertAtEnd(&interleavedList, l1->data);
        insertAtEnd(&interleavedList, l2->data);
        l1 = l1->next;
        l2 = l2->next;
    }

    if (l1 != NULL) {
        Node* remaining = copyList(l1);
        while (remaining != NULL) {
            insertAtEnd(&interleavedList, remaining->data);
            remaining = remaining->next;
        }
    } else if (l2 != NULL) {
        Node* remaining = copyList(l2);
        while (remaining != NULL) {
            insertAtEnd(&interleavedList, remaining->data);
            remaining = remaining->next;
        }
    }

    return interleavedList;
}
