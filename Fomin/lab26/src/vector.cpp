#include <stdexcept>
#include "../include/vector.h"

template<typename T>
Vector<T>::Vector() : data(nullptr), size(0), capacity(0) {}
// the same as data = nullptr; size = 0; capacity = 0;

// copy constructor
template<typename T>
Vector<T>::Vector(const Vector<T> &other) : size(other.size), capacity(other.capacity) {
    data = new T[capacity];
    for (std::size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// delete
template<typename T>
Vector<T>::~Vector() {
    delete[] data;
}

// operator prisvaivaniya copy
template<typename T>
Vector<T> &Vector<T>::operator=(const Vector &other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (std::size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this; // returns the thing that pointer "this" is pointing to (to bish sam vector)
}

template<typename T>
void Vector<T>::push_back(const T &value) {
    if (size == capacity) reserve(capacity == 0 ? 1 : capacity * 2);

    data[size++] = value;
}

template<typename T>
T &Vector<T>::pop_back() {
    if (size > 0) size--;

    return this->back();
}

template<typename T>
template<typename... Args>
void Vector<T>::emplace_back(const T& first, const Args& ...args)
{
    push_back(first);
    emplace_back(args...);
}

template<typename T>
void Vector<T>::emplace_back(){}

template<typename T>
void Vector<T>::reserve(std::size_t newCapacity) {
    if (newCapacity > capacity) {
        T* newData = new T[newCapacity];
        for (std::size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
}

template<typename T>
void Vector<T>::resize(std::size_t newSize) {
    if (newSize < size) size = newSize; // maybe memory leak?
    if (newSize > size) {
        reserve(newSize);
        for (std::size_t i = size; i < newSize; ++i) {
            data[i] = T();
        }
        size = newSize;
    }
}

template<typename T>
T &Vector<T>::at(std::size_t index) {
    if (index >= size) throw std::out_of_range("Index out of range");

    return data[index];
}

template<typename T>
T &Vector<T>::front() {
    return data[0];
}

template<typename T>
T &Vector<T>::operator[](std::size_t index) {
    return data[index];
}

template<typename T>
T &Vector<T>::back() {
    return data[size - 1];
}

template<typename T>
bool Vector<T>::empty() {
    return size == 0;
}

template<typename T>
std::size_t Vector<T>::getSize() {
    return size;
}

template<typename T>
std::size_t Vector<T>::getCapacity() {
    return capacity;
}

template<typename T>
void Vector<T>::shrink_to_fit() {
    if (size < capacity) {
        T* newData = new T[size];
        for (std::size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = size;
    }
}

template<typename T>
void Vector<T>::clear() {
    size = 0;
}

template<typename T>
bool Vector<T>::operator==(const Vector &other) {
    if (size != other.size) return false;

    for (std::size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) return false;
    }

    return true;
}

template<typename T>
bool Vector<T>::operator!=(const Vector &other) {
    if (size != other.size) return true;

    for (std::size_t i = 0; i < other.size; i++) {
        if (other[i] != this[i]) return true;
    }

    return false;

    //return *this != other;
}

/*template<typename T>
Vector<T>::Vector(std::initializer_list<T> initList) : size(initList.size()), capacity(initList.size()) {
    data = new T[capacity];
    std::size_t i = 0;
    for (const auto& element : initList) {
        data[i++] = element;
    }
}*/

/*template<typename T>
template<typename... Args>
void Vector<T>::emplace_back(Args... args) {
    if (size == capacity) {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }

    data[size++] = T(std::forward<Args>(args)...);
    // applies std::forward for each arg in args
    // std::forward makes it so args save their link nature
}*/

