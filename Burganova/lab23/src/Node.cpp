#include "../include/Node.hpp"

template <typename T>
Node<T>::Node(const T& data): data(data) {}

template <typename T>
T& Node<T>::get_data() {
    return data;
}

template <typename T>
Node<T>* Node<T>::get_left_node() {
    return left_node;
}

template <typename T>
Node<T>* Node<T>::get_right_node() {
    return right_node;
}

template <typename T>
void Node<T>::set_left_node(Node<T>* left) {
    this->left_node = left;
}

template <typename T>
void Node<T>::set_right_node(Node<T>* right) {
    this->right_node = right;
}