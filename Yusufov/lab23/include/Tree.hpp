#ifndef TREE_HPP_INCLUDED
#define TREE_HPP_INCLUDED

#include "Node.hpp"

template<typename T>
class Tree {
private:
    Node<T>* root;
    Node<T>* createNode(T data);
    Node<T>* insertNode(Node<T>* root, T data);
    void traversal(Node<T>* root);
    Node<T>* deleteNode(Node<T>* root, T data);
    Node<T>* findMin(Node<T>* root);
    int findMaxDepth(Node<T>* root);
    T findMaxDepthLeaf(Node<T>* root, int depth, int& maxDepth, T& maxDepthLeaf);
public:
    Tree();
    void insert(T data);
    void remove(T data);
    void display();
    int getMaxDepth();
    T getMaxDepthLeaf();
};

#include "../src/Tree.cpp"

#endif