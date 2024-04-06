#include <iostream>
#include <iomanip>
#include <vector>

#include "BST.h"

int main() {
    BST t;
    for (int i = 1; i <= 4; ++i) {
        t.Add(i);
    }

    t.Print();

    bool b;
    b = t.Find(6);
    b = t.Find(26);

    std::vector<int> v = t.GetAllElements();
    for (int i : v) std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}