#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* root;
} BinarySearchTree;

BinarySearchTree* createTree();
void insert(BinarySearchTree* tree, int key);
void printInOrder(Node* node);
int countNodes(Node* node);
Node* search(Node* node, int key);
void printPreOrder(Node* node);
void printPostOrder(Node* node);

#endif
