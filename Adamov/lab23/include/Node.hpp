#ifndef NODE_HPP
#define NODE_HPP
#include <cstddef>
#include <iostream>

template<typename T>
class Tree;

template<typename T>
class Node {
    friend class Tree<T>;
private:
    T data;
    Node* left = nullptr;
    Node* right = nullptr;
public:
    Node() = default;
    Node(const T& data);
    Node(const T& data, Node* left, Node* right);

    T get_data() const;
    void insert(Node<T>* pred, const T& new_data);
    void print_tree(Node<T>* node, size_t depth) const;
    Node<T>* get_min_node(Node<T>* node) const;
    Node<T>* delete_node(Node<T>* node, const T& data);
    
    Node<T>* get_min_depth_node(Node<T>* root);
    Node<T>* bypass_min_depth_node(Node<T>* node, size_t depth, Node<T>* min_depth_node, size_t min_depth);

    ~Node() = default;
};

#include "../src/Node.cpp"

#endif
