#ifndef SPELLCHECK_H
#define SPELLCHECK_H

#include "BST.h"
#include "LinkedList.h"

void quickSort(std::string& str, int low, int high);
int partition(std::string& str, int low, int high);

int incorrectArrangement(std::string input, Node* root);
void incorrectArrangement(std::string input, Node* root, LinkedList<std::string>& ob);

int exchangedCharacters(std::string input, Node* root);
void exchangedCharacters(std::string input, Node* root, LinkedList<std::string>& ob);

int missingCharacter(std::string input, Node* root);
void missingCharacter(std::string input, Node* root, LinkedList<std::string>& ob);

int extraCharacter(std::string input, Node* root);
void extraCharacter(std::string input, Node* root, LinkedList<std::string>& ob);

int mixedExtraMissing(std::string input, Node* root);
void mixedExtraMissing(std::string input, Node* root, LinkedList<std::string>& ob);

#endif
