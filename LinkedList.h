#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LLNode.h"

template<class T>
class LinkedList {
public:
    LLNode<T>* head;

    LinkedList();
    void insert(T data);
    int getLength();
    T searchWord(int num);
    std::string searchMistake(std::string word);
    void print();
};

#endif
