#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

BinarySearchTree* createTree() {
    BinarySearchTree* tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    if (tree == NULL) {
        printf("Erro ao alocar memória para a árvore.\n");
        exit(EXIT_FAILURE);
    }
    tree->root = NULL;
    return tree;
}

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(BinarySearchTree* tree, int key) {
    Node* newNode = createNode(key);
    if (tree->root == NULL) {
        tree->root = newNode;
        return;
    }

    Node* current = tree->root;
    Node* parent = NULL;
    while (current != NULL) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;
}

void printInOrder(Node* node) {
    if (node != NULL) {
        printInOrder(node->left);
        printf("%d ", node->key);
        printInOrder(node->right);
    }
}

int countNodes(Node* node) {
    if (node == NULL)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

Node* search(Node* node, int key) {
    if (node == NULL || node->key == key)
        return node;

    if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

void printPreOrder(Node* node) {
    if (node != NULL) {
        printf("%d ", node->key);
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

void printPostOrder(Node* node) {
    if (node != NULL) {
        printPostOrder(node->left);
        printPostOrder(node->right);
        printf("%d ", node->key);
    }
}
