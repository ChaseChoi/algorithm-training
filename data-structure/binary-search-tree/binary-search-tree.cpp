#include <iostream>
#include "binary-search-tree.h"
using namespace std;

void BinarySearchTree::build() {
    freopen("data.in", "r", stdin);
    int value;
    while (cin >> value) {
        root = insert(value, root);
    }
}

Node* BinarySearchTree::insert(int value, Node* current) {
    
    if (current == nullptr) {
        Node* current = new Node(value);
        return current;
    }

    if (current->value < value) {
        current->right = insert(value, current->right);
    } else {
        current->left = insert(value, current->left);
    }

    return current;
}

void BinarySearchTree::show() {
    showInOrder(root);
}

void BinarySearchTree::showInOrder(Node* current) {
    if (current == nullptr) {
        return;
    }

    showInOrder(current->left);
    cout << current->value << " ";
    showInOrder(current->right);
}