#include "../include/Node.hpp"

template<typename T>
Node<T>::Node(const T& value, Node<T>* next) {
    this->nextNode = next;
    this->data = value;
}

template<typename T>
T& Node<T>::get_data() const {
    return data;
}

template<typename T>
Node<T>* Node<T>::get_nextNode() const {
    return nextNode;
}
