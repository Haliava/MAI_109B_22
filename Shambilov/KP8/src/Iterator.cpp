#include "../include/List.hpp"

template<typename T>
Iterator<T>::Iterator() {
    this->currentNode = nullptr;
}

template<typename T>
Iterator<T>::Iterator(const List<T>& list) {
    this->currentNode = list.start;
}

template<typename T>
Iterator<T>::Iterator(Node<T>* node) {
    this->currentNode = node;
}

template<typename T>
Iterator<T>& Iterator<T>::operator++() {
    this->currentNode = this->currentNode->nextNode;
    return *this;
}

template<typename T>
T& Iterator<T>::operator*() const {
    return this->currentNode->data;
}

template<typename T>
Iterator<T> Iterator<T>::operator+(size_t size) {
    Iterator<T> returnIterator(*this);
    while (size != 0) {
        if (returnIterator == nullptr and size != 0) {
            throw std::range_error("Segfault");
        }
        ++returnIterator;
        --size;
    }
    return returnIterator;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& other) const {
    return (other.currentNode == this->currentNode);
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& other) const {
    return !(*this == other);
}
