#include <stdio.h>
#include "binary_search_tree.h"

int main() {
    BinarySearchTree* tree = createTree();

    insert(tree, 24);
    insert(tree, 10);
    insert(tree, 32);
    insert(tree, 5);
    insert(tree, 12);
    insert(tree, 29);
    insert(tree, 35);

    printf("Árvore em ordem: ");
    printInOrder(tree->root);
    printf("\n");

    printf("Número de elementos na árvore: %d\n", countNodes(tree->root));

    int searchKey = 10;
    Node* foundNode = search(tree->root, searchKey);
    if (foundNode != NULL)
        printf("Elemento %d encontrado na árvore.\n", searchKey);
    else
        printf("Elemento %d não encontrado na árvore.\n", searchKey);

    printf("Árvore em pré-ordem: ");
    printPreOrder(tree->root);
    printf("\n");
  
    printf("Árvore em pós-ordem: ");
    printPostOrder(tree->root);
    printf("\n");

    return 0;
}
