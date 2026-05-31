// Copyright 2021 NNTU-CS
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "../include/bst.h"

void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream file(filename);

    std::string current_word = "";
    char ch;

    while (file.get(ch)) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            current_word += std::tolower(static_cast<unsigned char>(ch));
        } else {
            if (!current_word.empty()) {
                tree.add(current_word);
                current_word = "";
            }
        }
    }
    if (!current_word.empty()) {
        tree.add(current_word);
    }

    file.close();
}

void printFreq(BST<std::string>& tree) {
    std::vector<BST<std::string>::Item> words;
    tree.getAllElements(words);

    std::sort(words.begin(), words.end(), [](const BST<std::string>::Item& a, const BST<std::string>::Item& b) {
        if (a.count != b.count) {
            return a.count > b.count;
        }
        return a.value < b.value;
    });

    std::ofstream outFile("../result/freq.txt");

    for (const auto& item : words) {
        std::cout << item.value << ": " << item.count << std::endl;
        outFile << item.value << " " << item.count << "\n";
    }

    outFile.close();
}
