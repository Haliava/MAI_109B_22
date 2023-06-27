#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"

template<typename T>
class Tree {
private:
    Node<T>* root = nullptr;
public:
    Tree() = default;
    Tree(const T& data);

    Node<T>* get_root();

    void insert(const T& new_data);
    void delete_node(const T& data);
    void print_tree() const;
    void bypass() const;

    Node<T>* get_min_depth_node() const;

    void delete_tree(Node<T>* node);
    ~Tree();
};

#include "../src/Tree.cpp"

#endif
