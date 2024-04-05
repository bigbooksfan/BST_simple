#include <iostream>
#include <iomanip>

#include "BST.h"

int main() {
    BST t;
    t.Add(8);
    t.Add(3);
    t.Add(10);
    t.Add(1);
    t.Add(6);
    t.Add(4);
    t.Add(7);
    t.Add(14);
    t.Add(13);

    bool b;
    b = t.Find(6);
    b = t.Find(26);

    return 0;
}