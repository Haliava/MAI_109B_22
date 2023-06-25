#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include "../include/FriendClass.hpp"

template<typename T>
class Node
{
private:
    T data;
    Node *next;

public:
    friend class Queue<T>;
    friend class Iterator<T>;

    explicit Node(const T &value) : data(value), next(nullptr){};

    ~Node() = default;
};

#endif//NODE_HPP