#include "../include/Node.hpp"

template<typename T>
Node<T>::Node(const T &val, Node<T>* next)
{
    this->next_ = next;
    this->value_ = val;
}