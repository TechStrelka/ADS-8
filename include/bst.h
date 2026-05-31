// Copyright 2021 NNTU-CS
#ifndef BST_H
#define BST_H

#include <string>
#include <vector>
#include <algorithm>

template <typename T>
class BST {
private:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;

        Node(const T& val) : value(val), count(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void addNode(Node*& node, const T& value) {
        if (node == nullptr) {
            node = new Node(value);
        }
        else if (value < node->value) {
            addNode(node->left, value);
        }
        else if (value > node->value) {
            addNode(node->right, value);
        }
        else {
            node->count++;
        }
    }

    int getDepth(Node* node) const {
        if (node == nullptr) return 0;
        return 1 + std::max(getDepth(node->left), getDepth(node->right));
    }

    bool searchNode(Node* node, const T& value) const {
        if (node == nullptr) return false;
        if (value == node->value) return true;
        if (value < node->value) return searchNode(node->left, value);
        return searchNode(node->right, value);
    }

    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    void collect(Node* node, std::vector<std::pair<T, int>>& items) const {
        if (node == nullptr) return;
        collect(node->left, items);
        items.push_back({ node->value, node->count });
        collect(node->right, items);
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        clear(root);
    }

    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;

    void add(const T& value) {
        addNode(root, value);
    }

    int depth() const {
        return getDepth(root);
    }

    bool search(T value) const {
        return searchNode(root, value);
    }

    void getAllElements(std::vector<std::pair<T, int>>& items) const {
        collect(root, items);
    }
};
#endif  // INCLUDE_BST_H_
