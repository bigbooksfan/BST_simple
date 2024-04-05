#pragma once

class BST {     // Binary search tree
private:
    struct Node {
        Node* left = nullptr;
        Node* right = nullptr;
        int val = 0;
    };
public:
    Node* root = nullptr;

    void Add(int val);
    bool Find(int val);
};