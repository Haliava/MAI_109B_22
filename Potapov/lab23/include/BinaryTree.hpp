#ifndef TREE_HPP_INCLUDED
#define TREE_HPP_INCLUDED
#include "Node.hpp"

class BinaryTree {
public:
    Node* root = NULL;
    BinaryTree() = default;

    void insert(int data);
    Node* insertHelper(Node* node, int data);

    void print();
    void printHelper(Node* node, std::string indent);

    void remove(int data);
    Node* removeHelper(Node* node, int data);
    Node* findMin(Node* node);

    void get_leaf_count(int& count, Node* node);
};

#include "../src/BinaryTree.cpp"

#endif// TREE_HPP_INCLUDED
