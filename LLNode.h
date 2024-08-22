#ifndef LLNODE_H
#define LLNODE_H

template<class T>
class LLNode {
public:
    T data;
    LLNode* next;

    LLNode();
    LLNode(T data);
};

#endif
