#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct Node {
    int value;
    Node *left, *right;
    Node(int val): left(nullptr), right(nullptr), value(val) {}
};

class BinarySearchTree {
    public:
        BinarySearchTree(): root(nullptr) {}
        void build();
        void show();
    private:
        Node* root;
        Node* insert(int, Node*);
        void showInOrder(Node*);
};
#endif