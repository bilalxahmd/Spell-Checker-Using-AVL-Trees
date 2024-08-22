#include "LinkedList.h"
#include <iostream>

template<class T>
LinkedList<T>::LinkedList() : head(NULL) {}

template<class T>
void LinkedList<T>::insert(T data) {
    LLNode<T>* newLLNode = new LLNode<T>(data);
    if (head == NULL) {
        head = newLLNode;
        return;
    }
    else {
        LLNode<T>* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newLLNode;
    }
}

template<class T>
int LinkedList<T>::getLength() {
    int counter = 0;
    LLNode<T>* temp = head;
    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

template<class T>
T LinkedList<T>::searchWord(int num) {
    LLNode<T>* temp = head;
    for (int i = 0; i < num - 1; i++) {
        temp = temp->next;
    }
    return temp->data;
}

template<class T>
std::string LinkedList<T>::searchMistake(std::string word) {
    LLNode<CorrectedWords>* temp = head;
    while (temp != NULL) {
        if (temp->data.mistake == word) {
            return temp->data.correction;
        }
        temp = temp->next;
    }
    return "N/A";
}

template<class T>
void LinkedList<T>::print() {
    LLNode<T>* temp = head;
    int i = 1;
    while (temp != NULL) {
        std::cout << "\n\t\t";
        std::cout << i << "." << temp->data;
        temp = temp->next;
        i++;
    }
}

// Necessary to avoid linking errors.
template class LinkedList<std::string>;
template class LinkedList<CorrectedWords>;
