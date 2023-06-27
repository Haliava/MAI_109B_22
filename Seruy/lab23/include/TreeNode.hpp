#ifndef TREENODE_HPP_INCLUDED
#define TREENODE_HPP_INCLUDED
 
#include "../include/MyVector.hpp"
#include "../include/Tree.hpp"
#include <iostream>

template<typename T>
class Tree;

template<typename T>
class TreeNode {
private:
    friend class Tree<T>;
    T data;
    myVector<TreeNode<T>*> children;
public:
    TreeNode();
    explicit TreeNode(const T&);
    explicit TreeNode(const T&, const myVector<TreeNode*>&); 
    ~TreeNode() = default;
};

#include "../src/TreeNode.cpp"

#endif