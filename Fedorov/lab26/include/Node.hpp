#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
#include <iostream>

template <typename T>
class Node {
private:
    T data;
    Node* prev = nullptr;
    Node* next = nullptr;

public:
    Node() = default;
    explicit Node(const T& _data);
    Node(const T& _data, Node* _prev, Node* _next);
    ~Node() = default;

    T get_data();
    Node* get_prev();
    Node* get_next();

    void set_data(const T& _data);
    void set_prev(Node<T> *_prev);
    void set_next(Node<T> *_next);

};

#include "../src/Node.cpp"
#endif
