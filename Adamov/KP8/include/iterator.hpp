#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "node.hpp"
#include <cstddef>

template<typename T>
class Iterator {
private:
    Node<T>* node = nullptr;

public:
    Iterator() = default;
    explicit Iterator(Node<T>* _node);

    Node<T>* get_node() const;
    T& operator*();
    const T& operator*() const;

    Iterator<T> operator++();
    Iterator<T> operator+(size_t sz);

    bool operator==(const Iterator<T>& other) const;
    bool operator!=(const Iterator<T>& other) const;

    ~Iterator() = default;
};

#include "../src/iterator.cpp"
#endif // ITERATOR_HPP
