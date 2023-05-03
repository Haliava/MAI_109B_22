#include "../include/Node.hpp"

template<typename T>
Node<T>::Node() {
    this->val = 0;
    this->left = nullptr;
    this->right = nullptr;
}

template<typename T>
Node<T>::Node(T val) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
}

template<typename T>
Node<T>::Node(T x, Node<T>* left, Node<T>* right) {
    this->val = x;
    this->left = left;
    this->right = right;
}

