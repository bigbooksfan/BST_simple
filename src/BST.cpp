#include "BST.h"

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