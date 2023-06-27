#include "../include/Node.hpp"

template<typename T>
Node<T>::Node(const T &_data): data(_data) {}

template<typename T>
Node<T>::Node(const T &_data, Node *_prev, Node *_next): data(_data), prev(_prev), next(_next) {}

template<typename T>
Node<T> *Node<T>::get_next() {
    return next;
}

template<typename T>
Node<T> *Node<T>::get_prev() {
    return prev;
}

template<typename T>
T Node<T>::get_data() {
    return data;
}

template<typename T>
void Node<T>::set_data(const T &_data) {
    data = _data;
}

template<typename T>
void Node<T>::set_prev(Node<T> *_prev) {
    prev = _prev;
}

template<typename T>
void Node<T>::set_next(Node<T> *_next) {
    next = _next;
}
