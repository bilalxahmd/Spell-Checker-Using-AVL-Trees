#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    Node* right;
    Node* left;
    std::string data;
    int height;

    Node(std::string str);
};

#endif
