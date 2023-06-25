#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Iterator.hpp"
#include "Node.hpp"
#include <iostream>

template<typename T>
class Queue
{
private:
    Node<T> *head;
    size_t size;

public:
    Queue() : head(nullptr),  size(0) {}
    ~Queue();

    void push(const T &value);
    void pop();

    T &getFront() const;
    bool empty() const;
    size_t getSize() const;

    Iterator<T> begin();
    Iterator<T> end();

    void Sort();
    template<typename F>
    friend std::ostream &operator<<(std::ostream &out, Queue<T> &q);
};

#include "../src/Queue.cpp"

#endif//QUEUE_HPP