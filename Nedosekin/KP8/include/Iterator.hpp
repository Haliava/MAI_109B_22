#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "../include/FriendClass.hpp"
#include "../include/Node.hpp"
template<typename T>
class Iterator
{
public:
    Iterator() = default;
    explicit Iterator(Node<T> *node);
    ~Iterator() = default;

    Iterator<T> operator++();
    Iterator<T> operator+(int64_t num);
    Node<T>* getNode() const;

    T &operator*();
    const T &operator*() const;
    bool operator==(const Iterator<T>& compared) const;
    bool operator!=(const Iterator<T>& compared) const;
private:
    Node<T> *node_;
};
#include "../src/Iterator.cpp"
#endif//ITERATOR_HPP