#include <iostream>
#include "binary-search-tree.h"
using namespace std;

int main() {
    BinarySearchTree* bst = new BinarySearchTree();
    bst->build();
    bst->show();

    bst->remove(9);
    bst->show();
}