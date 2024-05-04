#pragma once

struct node {
    int key;
    struct node *left, *right;
};

struct node *newNode(int key) {
    struct node *node1 = (struct node *) malloc(sizeof(struct node));
    node1->key = key;
    node1->left = node1->right = NULL;
    return (node1);
}

struct node *rightRotate(struct node *x) {
    struct node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

struct node *leftRotate(struct node *x) {
    struct node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

struct node *splay(struct node *root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (root->key > key) {
        if (root->left == NULL) return root;

        if (root->left->key > key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        } else if (root->left->key < key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        return (root->left == NULL) ? root : rightRotate(root);
    } else {
        if (root->right == NULL) return root;

        if (root->right->key > key) {
            root->right->left = splay(root->right->left, key);

            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        } else if (root->right->key < key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        return (root->right == NULL) ? root : leftRotate(root);
    }
}

struct node *search(struct node *root, int key) {
    return splay(root, key);
}

void preOrder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}


struct node *add(struct node *tree, struct node *root, int data) {
    if (root == NULL) {
        return (newNode(data));
    } else if (data < root->key) {
        root->left = add(tree, root->left, data);
    } else if (data > root->key) {
        root->right = add(tree, root->right, data);
    }
    if (tree == root) {
        return (splay(tree, data));
    }
    return (root);
}

struct node *minValueNode(struct node *node) {
    struct node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct node *Delete(struct node *root, int data) {
    if (root == NULL) {
        return (root);
    }
    if (data > root->key) {
        root->right = Delete(root->right, data);
    } else if (data < root->key) {
        root->left = Delete(root->left, data);
    } else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = Delete(root->right, temp->key);
    }
    return (root);
}