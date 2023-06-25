#include "../include/Iterator.hpp"

template<typename T>
T &Iterator<T>::operator*() const
{
    return current->data;
}

template<typename T>
Iterator<T> &Iterator<T>::operator++()
{
    current = current->next;
    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator+(size_t num)
{
    while(--num && current) {
      current = current->next;
    }
    return *this;
}

template<typename T>
Node<T>* Iterator<T>::getCurr() const {
  return this->current;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T> &other) const
{
    return current != other.current;
}