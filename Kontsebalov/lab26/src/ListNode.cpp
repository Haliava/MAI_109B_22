#include "ListNode.hpp"

template <typename T>
Node<T>::Node(): data(0), next(nullptr), previous(nullptr){}

template <typename T>
Node<T>::Node(const T& value): data(value), next(nullptr), previous(nullptr){}

template <typename T>
Node<T>::Node(const T& value, Node<T>* previous_node, Node<T>* current_node): data(value), next(current_node), previous(previous_node){
    if (previous != nullptr){
        previous->next = this;
    }

    if (current_node != nullptr){
        current_node->previous = this;
    }
}