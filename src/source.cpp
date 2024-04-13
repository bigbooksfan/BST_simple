#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>

#include "BST.h"
#include "AVL.h"
#include "log_duration.h"

static std::random_device rd; // random device engine, usually based on /dev/random on UNIX-like systems
// initialize Mersennes' twister using rd to generate the seed
static std::mt19937 rng{rd()}; 

int dice(int n)
{
    static std::uniform_int_distribution<int> uid(1,n); // random dice
    return uid(rng); // use rng as a generator
}

int main() {
    LOG_DURATION("main");

    int n = 1e5;

    BST t;
    {
        LOG_DURATION("BST creation");
        std::cout << "Common binary tree\n";
        for (int i = 1; i <= n; ++i) {
            t.Add(i);
        }
    }

    // AVL
    AVL<int> avl;
    std::cout << "AVL tree:\n";
    {
        LOG_DURATION("AVL creation");
        for (int i = 1; i <= n; ++i) {
            avl.insert(i);
        }
    }

    std::vector<int> v;
    std::cout << "vector:\n";
    {
        LOG_DURATION("Vector creation");
        v.reserve(n);
        for (int i = 1; i <= n; ++i) {
            v.push_back(i);
        }
    }

    int m = 1e5;

    {
        LOG_DURATION("BST search");
        for (int i = 0; i < m; ++i){
            t.Find(dice(n));
        }
    }

    {
        LOG_DURATION("AVL search");
        for (int i = 0; i < m; ++i){
            avl.Find(dice(n));
        }
    }

    {
        LOG_DURATION("Vector search");
        for (int i = 0; i < m; ++i){
            std::vector<int>::iterator It = std::find(v.begin(), v.end(), dice(n));
        }
    }


    return 0;
}