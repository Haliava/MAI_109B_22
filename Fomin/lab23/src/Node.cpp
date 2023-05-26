#include "../include/Node.h"

template<typename T>
Node<T>::Node(): val(0), left(nullptr), right(nullptr) {
}

template<typename T>
Node<T>::Node(const T& val): val(val), left(nullptr), right(nullptr) {
}

template<typename T>
Node<T>::Node(const T& x, Node<T>* left, Node<T>* right): val(x), left(left), right(right) {
}

