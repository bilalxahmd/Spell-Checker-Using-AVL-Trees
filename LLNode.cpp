#include "LLNode.h"

template<class T>
LLNode<T>::LLNode() : data(""), next(NULL) {}

template<class T>
LLNode<T>::LLNode(T data) : data(data), next(NULL) {}

// Necessary to avoid linking errors.
template class LLNode<std::string>;
template class LLNode<CorrectedWords>;
