#include <iostream>
#include <queue>
#include "binary-tree.h"
using namespace std;

// Build tree
void BinaryTree::build() {
    freopen("data.in", "r", stdin);
    root = buildPreOrder();
}

Node* BinaryTree::buildPreOrder() {
    char inputValue;
    Node* current = nullptr;
    cin >> inputValue;

    if (inputValue != '.') {
        current = new Node();
        current->value = inputValue;
        current->left = buildPreOrder();
        current->right = buildPreOrder();
    }

    return current;
}

// Show tree
void BinaryTree::show() {
    cout << "Pre:" << endl;
    showPreOrder(root);
    cout << endl;

    cout << "Level" << endl;
    showLevelOrder();
    cout << endl;
}

void BinaryTree::showPreOrder(Node* current) {
    if (current == nullptr) {
        cout << stopFlag;
    } else {
        cout << current->value;
        showPreOrder(current->left);
        showPreOrder(current->right);
    }
}

void BinaryTree::showLevelOrder() {
    queue<Node*> nodesQueue;
    if (root != nullptr) {
        nodesQueue.push(root);
    }
    while (!nodesQueue.empty()) {
        Node* front = nodesQueue.front();
        nodesQueue.pop();
        cout << front->value;
        if (front->left != nullptr) {
            nodesQueue.push(front->left);
        }
        if (front->right != nullptr) {
            nodesQueue.push(front->right);
        }
    }
}