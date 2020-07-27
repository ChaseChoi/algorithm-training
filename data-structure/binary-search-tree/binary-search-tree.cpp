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
    cout << endl;
}

void BinarySearchTree::showInOrder(Node* current) {
    if (current == nullptr) {
        return;
    }

    showInOrder(current->left);
    cout << current->value << " ";
    showInOrder(current->right);
}

void BinarySearchTree::remove(int value) {
    root = remove(value, root);
}

Node* BinarySearchTree::remove(int value, Node* current) {
    
    if (current == nullptr) {
        return nullptr;
    }

    if (current->value < value) {
        current->right = remove(value, current->right);
    } else if (current->value > value) {
        current->left = remove(value, current->left);
    } else {
        if (current->left == nullptr || current->right == nullptr) {
            Node* temp = current->left == nullptr ? current->right : current->left;
            delete current;
            current = temp;
        } else {
            Node* minNode = findMin(current->right);
            int minValue = minNode->value;
            Node* newCenter = new Node(minValue);
            
            newCenter->left = current->left;
            newCenter->right = remove(minValue, current->right);
            
            delete current;
            current = newCenter;
        }
    }
    return current;
}

Node* BinarySearchTree::findMin(Node* current) {
    
    if (current == nullptr) {
        return current;
    }

    if (current->left == nullptr) {
        return current;
    }

    return findMin(current->left);
}