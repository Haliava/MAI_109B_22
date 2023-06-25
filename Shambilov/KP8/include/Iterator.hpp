#ifndef KP8_ITERATOR_HPP
#define KP8_ITERATOR_HPP
#include "../include/Node.hpp"
template<typename T>
class List;

template<typename T>
class Iterator {
private:
    Node<T>* currentNode;
public:
    Iterator();
    Iterator(const List<T>& list);
    Iterator(Node<T>* node);

    Iterator<T>& operator++();
    T& operator*() const;
    Iterator<T> operator+(size_t);
    bool operator==(const Iterator<T>& other) const;
    bool operator!=(const Iterator<T>& other) const;
};

#include "../src/Iterator.cpp"


#endif //KP8_ITERATOR_HPP
