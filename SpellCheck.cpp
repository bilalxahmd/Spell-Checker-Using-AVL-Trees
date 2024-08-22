#include "SpellCheck.h"
#include <algorithm>
#include <iostream>

//lower case alphabets.
char lower_alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

// QuickSort algorithm to sort the characters in a string
void quickSort(std::string& str, int low, int high) {
    if (low < high) {
        int pi = partition(str, low, high);
        quickSort(str, low, pi - 1);
        quickSort(str, pi + 1, high);
    }
}

int partition(std::string& str, int low, int high) {
    char pivot = str[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (str[j] <= pivot) {
            i++;
            std::swap(str[i], str[j]);
        }
    }
    std::swap(str[i + 1], str[high]);
    return (i + 1);
}

// Check if the input has characters in incorrect arrangement
int incorrectArrangement(std::string input, Node* root) {
    LinkedList<std::string> ob;
    incorrectArrangement(input, root, ob);
    return ob.getLength();
}

void incorrectArrangement(std::string input, Node* root, LinkedList<std::string>& ob) {
    if (root == NULL) return;

    std::string sortedInput = input;
    quickSort(sortedInput, 0, sortedInput.length() - 1);

    std::string sortedData = root->data;
    quickSort(sortedData, 0, sortedData.length() - 1);

    if (sortedData == sortedInput) {
        ob.insert(root->data);
    }

    incorrectArrangement(input, root->left, ob);
    incorrectArrangement(input, root->right, ob);
}

// Check if the input has exchanged adjacent characters
int exchangedCharacters(std::string input, Node* root) {
    LinkedList<std::string> ob;
    exchangedCharacters(input, root, ob);
    return ob.getLength();
}

void exchangedCharacters(std::string input, Node* root, LinkedList<std::string>& ob) {
    if (root == NULL) return;

    std::string data = root->data;
    if (data.length() == input.length()) {
        for (size_t i = 0; i < input.length() - 1; ++i) {
            std::swap(input[i], input[i + 1]);
            if (input == data) {
                ob.insert(data);
                break;
            }
            std::swap(input[i], input[i + 1]); // Swap back
        }
    }

    exchangedCharacters(input, root->left, ob);
    exchangedCharacters(input, root->right, ob);
}

// Check if the input is missing one character
int missingCharacter(std::string input, Node* root) {
    LinkedList<std::string> ob;
    missingCharacter(input, root, ob);
    return ob.getLength();
}

void missingCharacter(std::string input, Node* root, LinkedList<std::string>& ob) {
    if (root == NULL) return;

    std::string data = root->data;
    if (data.length() == input.length() + 1) {
        for (size_t i = 0; i < data.length(); ++i) {
            std::string temp = data;
            temp.erase(i, 1);
            if (temp == input) {
                ob.insert(data);
                break;
            }
        }
    }

    missingCharacter(input, root->left, ob);
    missingCharacter(input, root->right, ob);
}

// Check if the input has one extra character
int extraCharacter(std::string input, Node* root) {
    LinkedList<std::string> ob;
    extraCharacter(input, root, ob);
    return ob.getLength();
}

void extraCharacter(std::string input, Node* root, LinkedList<std::string>& ob) {
    if (root == NULL) return;

    std::string data = root->data;
    if (data.length() == input.length() - 1) {
        for (size_t i = 0; i < input.length(); ++i) {
            std::string temp = input;
            temp.erase(i, 1);
            if (temp == data) {
                ob.insert(data);
                break;
            }
        }
    }

    extraCharacter(input, root->left, ob);
    extraCharacter(input, root->right, ob);
}

// Check if the input has a combination of missing and extra characters
int mixedExtraMissing(std::string input, Node* root) {
    LinkedList<std::string> ob;
    mixedExtraMissing(input, root, ob);
    return ob.getLength();
}

void mixedExtraMissing(std::string input, Node* root, LinkedList<std::string>& ob) {
    if (root == NULL) return;

    std::string data = root->data;
    if (abs(static_cast<int>(data.length()) - static_cast<int>(input.length())) == 1) {
        for (size_t i = 0; i < std::min(input.length(), data.length()); ++i) {
            std::string tempInput = input;
            std::string tempData = data;
            tempInput.erase(i, 1);
            tempData.erase(i, 1);
            if (tempInput == tempData) {
                ob.insert(data);
                break;
            }
        }
    }

    mixedExtraMissing(input, root->left, ob);
    mixedExtraMissing(input, root->right, ob);
}
