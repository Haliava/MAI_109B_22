#ifndef NODE_HPP
#define NODE_HPP
#include "../include/FriendClass.hpp"
#include <iostream>
template<typename T>
class Node
{
public:
    friend class Iterator<T>;
    friend class List<T>;
    Node() = default;
    explicit Node(const T &val, Node<T>* next);
    ~Node() = default;
private:
    T value_;
    Node *next_ = nullptr;
};
#include "../src/Node.cpp"
#endif//NODE_HPP