#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtEnd(Node** head, int data);
void printList(Node* head);
Node* operationA(Node* head);

#endif
