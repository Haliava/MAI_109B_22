#include "../include/Iterator.hpp"

template<typename T>
Iterator<T>::Iterator(Node<T> *_node): node(_node) {}

template<typename T>
Node<T> *Iterator<T>::get_node() {
    return node;
}

template<typename T>
T Iterator<T>::operator*() const {
    return node->get_data();
}

template<typename T>
Iterator<T> Iterator<T>::operator++() {
    if (node != nullptr) {
        node = node->get_next();
    }
    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator--() {
    if (node) {
        node = node->get_prev();
    }
    return *this;
}


template<typename T>
Iterator<T> Iterator<T>::operator+(int64_t val) {
    if (node == nullptr)
        return *this;
    if (val >= 0) {
        while (val && node) {
            --val;
            node = node->get_next();
        }
    } else {
        while (val && node) {
            ++val;
            node = node->get_prev();
        }
    }
    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator-(int64_t val) {
    return *this + (-val);
}

template<typename T>
bool Iterator<T>::operator==(Iterator const &x) const {
    return this->node == x.node;
}

template<typename T>
bool Iterator<T>::operator!=(Iterator const &x) const {
    return !(this->node == x.node);
}
