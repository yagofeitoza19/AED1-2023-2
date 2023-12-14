#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data);
void insertAtEnd(Node** head, int data);
void printList(Node* head);
Node* copyList(Node* original);
Node* concatenateLists(Node* l1, Node* l2);
Node* interleaveLists(Node* l1, Node* l2);

#endif
