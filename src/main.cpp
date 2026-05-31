// Copyright 2021 NNTU-CS
#include <iostream>
#include <string>
#include "../include/bst.h"

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
    BST<std::string> tree;

    makeTree(tree, "../src/war_peace.txt");

    std::cout << "Глубина дерева: " << tree.depth() << std::endl;

    if (tree.search("war")) {
        std::cout << "Слово 'war' найдено" << std::endl;
    } else {
        std::cout << "Слово 'war' не найдено" << std::endl;
    }

    printFreq(tree);

    return 0;
}
