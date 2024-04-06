#pragma once

#include <vector>

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
    int GetSubtreeDepth(Node* node);
    int GetDepth();
    void GetSubtreeElements(std::vector<int>& v, Node* node);
    std::vector<int> GetAllElements();
};