// Copyright 2021 NNTU-CS
#include "../include/bst.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream file(filename);

    std::string current_word = "";
    char ch;

    while (file.get(ch)) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            current_word += std::tolower(static_cast<unsigned char>(ch));
        }
        else {
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
    std::vector<std::pair<std::string, int>> words;
    tree.getAllElements(words);

    std::sort(words.begin(), words.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first;
        });

    std::ofstream outFile("../result/freq.txt");

    for (const auto& pair : words) {
        std::cout << pair.first << ": " << pair.second << std::endl;
        outFile << pair.first << " " << pair.second << "\n";
    }

    outFile.close();
}
