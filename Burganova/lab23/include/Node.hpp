#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template <typename T>
class Node {
private:
    T data;
    Node<T>* left_node = nullptr;
    Node<T>* right_node = nullptr;

public:
    Node(const T&);

    T& get_data();
    
    Node<T>* get_left_node();
    Node<T>* get_right_node();

    void set_left_node(Node<T>* left);
    void set_right_node(Node<T>* right);
};

#include "../src/Node.cpp"

#endif