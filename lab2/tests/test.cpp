#include "gtest/gtest.h"
#include "main.h"

TEST(test, t1) {
    struct node *root = newNode(69);
    root->left = newNode(20);
    root->right = newNode(99);
    root = add(root, root, 40);
    int answer = 40;
    ASSERT_EQ(answer, root->key);
}

TEST(test, t2) {
    struct node *root = newNode(69);
    root->left = newNode(20);
    root->right = newNode(99);
    root = add(root, root, 40);
    int answer = 20;
    ASSERT_EQ(answer, root->left->key);
}

TEST(test, t3) {
    struct node *root = newNode(69);
    root->left = newNode(20);
    root->right = newNode(99);
    root = search(root, 99);
    int answer = 99;
    ASSERT_EQ(answer, root->key);
}

TEST(test, t4) {
    struct node *root = newNode(69);
    root->left = newNode(20);
    root->right = newNode(99);
    root = search(root, 99);
    int answer = 69;
    ASSERT_EQ(answer, root->left->key);
}

TEST(test, t5) {
    struct node *root = newNode(69);
    root->left = newNode(20);
    root->right = newNode(99);
    root->left->left = newNode(7);
    Delete (root, 20);
    int answer = 7;
    ASSERT_EQ(answer, root->left->key);
}