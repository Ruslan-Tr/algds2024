#include "stdlib.h"
#include <stdio.h>
#include "main.h"

int main(void) {

    struct node *root = newNode(100);
    root->left = newNode(50);
    root->right = newNode(200);
    root->left->left = newNode(40);
    root->left->left->left = newNode(30);
    root->left->left->left->left = newNode(20);


    printf("Дерево:\n");
    preOrder(root);

    printf("\nПроверка поиска элемента и изменения дерева функцией splay:\n");
    root = search(root, 20);
    preOrder(root);

    printf("\nПроверка добавления элемента и изменений, которые произошли вследствие этого:\n");
    root = add(root, root, 35);
    preOrder(root);

    printf("\nПроверка удаления элемента:\n");
    Delete(root, 200);
    preOrder(root);
    printf("\n");

    return 0;
}
