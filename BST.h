#ifndef BST_H
#define BST_H

#include "Node.h"

class BST {
public:
    int getHeight(Node* N);
    int max(int a, int b);
    Node* newNode(std::string key);
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    int getBalance(Node* N);
    Node* insert(Node* node, std::string key);
    void inorder(Node* root);
    bool searchAvltree(Node* root, std::string word);
};

#endif
