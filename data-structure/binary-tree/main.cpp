#include <iostream>
#include "binary-tree.h"
using namespace std;

int main() {
    BinaryTree* tree = new BinaryTree();
    tree->build();
    tree->show();
}