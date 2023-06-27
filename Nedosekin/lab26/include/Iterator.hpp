#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "../include/FriendClass.hpp"
#include "../include/Node.hpp"

template<typename T>
class Iterator
{
private:
    Node<T> *current;

public:
    explicit Iterator(Node<T> *node) : current(node) {}

    T &operator*() const;
    Iterator<T> &operator+(size_t num);

    Iterator<T> &operator++();

    Node<T>* getCurr() const;

    bool operator!=(const Iterator<T> &other) const;

};

#include "../src/Iterator.cpp"

#endif//ITERATOR_HPP