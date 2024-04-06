#include "BST.h"

#include <queue>
#include <iostream>
#include <string>
#include <cmath>

void BST::Add(int val) {
    if (root == nullptr) {
        // add root node
        root = new Node;
        root->val = val;
        return;
    }

    Node *runner = root;
    while (true) {
        if (runner->val > val) {
            // go left
            if (runner->left == nullptr) {
                // add left branch
                Node *tmp = new Node;
                tmp->val = val;
                runner->left = tmp;
                return;
            }
            else {
                runner = runner->left;
                continue;
            }
        }
        else if (runner->val < val) {
            // go right
            if (runner->right == nullptr) {
                // right branch
                Node *tmp = new Node;
                tmp->val = val;
                runner->right = tmp;
                return;
            }
            else {
                runner = runner->right;
                continue;
            }
        }
        else if (runner->val == val) {
            // element already exists
            return;
        }
    }
}

bool BST::Find(int val) {
    Node *runner = root;

    while (true) {
        // base case
        if (runner->val == val) {
            return true;
        }
        if (runner->val > val) {
            // go left
            if (runner->left == nullptr) {
                return false;
            }
            runner = runner->left;
        }
        else {
            // go right
            if (runner->right == nullptr) {
                return false;
            }
            runner = runner->right;
        }
    }
}

void BST::Print() {
    std::queue<Node*> q;
    int counter = 0;
    int depth = GetDepth();
    int curr_row = 0;
    std::string filler;
    // BFS
    q.push(root);
    ++counter;
    while(counter > 0) {
        int diff = depth - curr_row;
        for (int i = 0, j = q.size(); i < j; ++i) {
            filler.clear();
            for (int n = 0; n < std::pow(2, diff - 1); ++n) {
                filler += "\t";
            }
            Node* node = q.front();
            q.pop();
            if (node != nullptr) --counter;

            if (node == nullptr) {
                std::cout << "." << filler;
                q.push(nullptr);
                q.push(nullptr);
            }
            else {
                std::cout << node->val << filler;
                q.push(node->left);
                if (node->left != nullptr) ++counter;
                q.push(node->right);
                if (node->right != nullptr) ++counter;
            }
        }
        std::cout << std::endl;
        ++curr_row;
    }
}

int BST::GetSubtreeDepth(Node* node) {
    // base case
    if (node == nullptr) return 0;

    int a = GetSubtreeDepth(node->left);
    int b = GetSubtreeDepth(node->right);
    return std::max(a, b) + 1;
}

int BST::GetDepth() {
    return GetSubtreeDepth(root);
}

void BST::GetSubtreeElements(std::vector<int>& v, Node* node) {
    // base case
    if (node == nullptr) return;

    GetSubtreeElements(v, node->left);
    v.push_back(node->val);
    GetSubtreeElements(v, node->right);
}

std::vector<int> BST::GetAllElements() {
    std::vector<int> ret;

    GetSubtreeElements(ret, root);
    return ret;
}