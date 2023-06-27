#include "../include/iterator.hpp"

template<typename T>
Iterator<T>::Iterator(Node<T>* _node) {
    node = _node;
}

template<typename T>
Node<T>* Iterator<T>::get_node() const {
    return node;
}

template<typename T>
T& Iterator<T>::operator*() {
    return node->data;
}

template<typename T>
const T& Iterator<T>::operator*() const {
    return node->data;
}

template<typename T>
Iterator<T> Iterator<T>::operator++() {
    if (node != nullptr) {
        node = node->next;
    }
    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator+(size_t sz) {
    while (sz > 0) {
        node = node->next;
        --sz;
    }
    return *this;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator<T>& other) const {
    return node == other.node;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& other) const {
    return !(node == other.node);
}
