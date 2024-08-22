# Spell Checker - Data Structures Project

## Project Description

This project is a spell checker application developed using C++. It utilizes data structures like Binary Search Trees (BST) and Linked Lists to manage a dictionary and provide spell-checking capabilities. The application can check individual words or entire paragraphs for spelling mistakes and suggests possible corrections.

### Features
- **Word Correction:** Users can input a single word, and the application will verify if the spelling is correct. If the word is misspelled, possible corrections are suggested based on common spelling mistakes.
- **Paragraph Correction:** Users can input an entire paragraph. The application will check each word in the paragraph and provide suggestions for corrections where needed. It also keeps a history of corrections made during the session.
- **Spell Check Techniques:**
  - Incorrect arrangement of characters.
  - Exchanged adjacent characters.
  - Missing characters.
  - Extra characters.
  - Mixed missing and extra characters.

### Data Structures Used
- **Binary Search Tree (BST):** Used to store the dictionary words and efficiently search for words.
- **Linked List:** Used to store and display the list of suggestions for misspelled words, and to maintain a history of corrections made during the session.

### Files in the Project
- **`main.cpp`:** The main driver file containing the user interface and main logic of the spell checker.
- **`BST.h` and `BST.cpp`:** Contains the implementation of the Binary Search Tree (BST) used for storing dictionary words.
- **`LinkedList.h` and `LinkedList.cpp`:** Contains the implementation of a linked list used for managing suggestions and correction history.
- **`CorrectedWords.h` and `CorrectedWords.cpp`:** Stores and manages a history of corrections made during a session.
- **`SpellCheck.h` and `SpellCheck.cpp`:** Contains various algorithms for detecting and suggesting corrections for spelling mistakes.
- **`loadingfunction.h` and `loadingfunction.cpp`:** Displays a loading screen animation when the application starts.
- **`words.txt`:** The dictionary file containing a list of correctly spelled words.

### How to Run the Project
1. **Compile the Project:** Ensure all `.cpp` and `.h` files are in the same directory. Compile the project using a C++ compiler. For example:
   ```bash
   g++ -o SpellChecker main.cpp BST.cpp LinkedList.cpp CorrectedWords.cpp SpellCheck.cpp loadingfunction.cpp
   ```
2. **Run the Executable:**   
   ```bash
   ./SpellChecker
   ```
### Example Usage
- **Word Correction:** Type in a word, and the application will check its spelling. If incorrect, it will suggest possible correct words.
- **Paragraph Correction:** Type in a paragraph, and the application will check each word. It will suggest corrections and allow you to choose whether to apply them.
### Future Enhancements
- **Dynamic Dictionary Update:** Add functionality to dynamically update the dictionary by adding new words.
- **Advanced Correction Suggestions:** Implement more sophisticated algorithms for suggesting corrections.
### Authors
- Bilal Ahmed (21K-4864)
- Atif Ali (21K-3340)
- Muhammad (21K-3192)
### License
This project is for educational purposes and may be used as a reference for understanding the implementation of data structures in C++. Please give credit if using any part of this code in your own projects.
  
