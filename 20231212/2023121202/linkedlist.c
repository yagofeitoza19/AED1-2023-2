#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

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

Node* operationA(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* newHead = head->next;
    Node* current = newHead;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = head;
    head->next = NULL;

    return newHead;
}
