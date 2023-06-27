#ifndef BINTREE_HPP
#define BINTREE_HPP

#include "Node.hpp"

template <typename T>
class BinTree {
private:
    Node<T>* root = nullptr; 

    void clear(Node<T>*);

public:
    BinTree() = default;
    BinTree(const T&);
    ~BinTree();
    Node<T>* get_root() const; 
    void insert(const T&, Node<T>* node); 
    void bypass(Node<T>*, int, int, bool&) const;
    bool task(int, int) const;
};

#include "../src/BinTree.cpp"

#endif