#ifndef TREE_HPP_INCLUDED
#define TREE_HPP_INCLUDED

#include "TreeNode.hpp"

template<typename T>
class Tree {
public:
    Tree();
    Tree(const T&);
    ~Tree();

    TreeNode<T>* getRoot() const;
    TreeNode<T>* deleteNode(const T&, TreeNode<T>*);
    
    void addNode(const T& newData, TreeNode<T>* node);
    bool linearize(TreeNode<T>* node); 
    void visualize(TreeNode<T>*) const;
    void deleteTree(TreeNode<T>*);
    
private:    
    TreeNode<T>* root = nullptr;
    bool linear;
};

#include "../src/Tree.cpp"

#endif