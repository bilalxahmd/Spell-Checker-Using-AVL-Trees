#include "BST.h"
#include <algorithm>
#include <iostream>

int BST::getHeight(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int BST::max(int a, int b) {
    return (a > b) ? a : b;
}

Node* BST::newNode(std::string key) {
    Node* node = new Node(key);
    return node;
}

Node* BST::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left),
                    getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left),
                    getHeight(x->right)) + 1;

    return x;
}

Node* BST::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left),
                    getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left),
                    getHeight(y->right)) + 1;

    return y;
}

int BST::getBalance(Node* N) {
    if (N == NULL)
        return 0;
    return getHeight(N->left) - getHeight(N->right);
}

Node* BST::insert(Node* node, std::string key) {
    if (node == NULL)
        return (newNode(key));

    else if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    node->height = 1 + max(getHeight(node->left),
                           getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void BST::inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    else {
        inorder(root->left);
        std::cout << root->data << std::endl;
        inorder(root->right);
    }
}

bool BST::searchAvltree(Node* root, std::string word) {
    if (root == NULL)
        return false;

    else if (word == root->data)
        return true;

    else if (word < root->data)
        return searchAvltree(root->left, word);

    else if (word > root->data)
        return searchAvltree(root->right, word);

    return false;
}
