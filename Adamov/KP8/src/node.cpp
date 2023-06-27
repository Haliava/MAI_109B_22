#include "../include/node.hpp"

template<typename T>
Node<T>::Node(const T& _data) {
    data = _data;
}

template<typename T>
Node<T>::Node(const T& _data, Node* _next) {
    data = _data;
    next = _next;
}

template<typename T>
T Node<T>::get_data() {
    return data;
}

template<typename T>
Node<T>* Node<T>::get_next() {
    return next;
}

template<typename T>
void Node<T>::set_next(Node<T> *_next) {
    next = _next;
}
