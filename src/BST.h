#pragma once

class BST {     // Binary search tree
private:
    struct Node {
        Node* left = nullptr;
        Node* right = nullptr;
        int val = 0;
    };

    Node* root = nullptr;
public:

    void Add(int val);
    bool Find(int val);
    void Print();
};