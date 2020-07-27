#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>

struct Node {
    char value;
    Node *left, *right;

    Node(): left(nullptr), right(nullptr), value('0') {}
};

class BinaryTree {
    public:
        BinaryTree(): root(nullptr), stopFlag('.') {}
        void build();
        void show();
    private:
        Node* root;
        char stopFlag;

        Node* buildPreOrder();
        void showPreOrder(Node*);
        void showLevelOrder();
};

#endif