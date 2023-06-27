#include "../include/MyVector.hpp"
#include <climits>
#include <memory>

template <typename T>
myVector<T>::myVector() {
    data = new T[1];
    size = 0;
    capacity = 1;
}

template <typename T>
myVector<T>::myVector(const myVector<T>& vector) {
    size = vector.size;
    capacity = vector.capacity;

    T* new_data = reinterpret_cast<T*>(new int8_t[capacity * sizeof(T)]);
    try {
        std::uninitialized_copy(vector.data, vector.data + vector.size, new_data);
    } catch (...) {
        delete[] reinterpret_cast<int8_t*>(new_data);
        throw;
    }

    data = new_data;
}

template <typename T>
myVector<T>::myVector(const std::initializer_list<T>& list) {
    size = list.size();
    capacity = size;
    data = new T[size];
    std::copy(list.begin(), list.end(), data);
}

template <typename T>
myVector<T>::~myVector() {
    for (size_t i = 0; i != size; ++i) {
        data[i].~T();
    }

    delete[] reinterpret_cast<int8_t*>(data);
    size = 0;
    capacity = 0;
}

template <typename T>
size_t myVector<T>::get_size() const {
    return size;
}

template <typename T>
size_t myVector<T>::get_capacity() const {
    return capacity;
}

template <typename T>
bool myVector<T>::operator==(const myVector<T>& another_vector) {
    if (size != another_vector.size) return false;

    for (size_t i = 0; i != size; ++i) {
        if (this->data[i] != another_vector.data[i]) return false;
    }

    return true;
}

template <typename T>
bool myVector<T>::operator!=(const myVector<T>& another_vector) {
    if (size != another_vector.size) return true;

    for (size_t i = 0; i != size; ++i) {
        if (this->data[i] != another_vector.data[i]) return true;
    }

    return false;
}

template <typename T>
bool myVector<T>::empty() const {
    return size == 0;
}

template <typename T>
void myVector<T>::reserve(size_t reserved_size) {
    if (reserved_size <= size) {
        return;
    }

    T* newArr = reinterpret_cast<T*>(new int8_t[reserved_size * sizeof(T)]);

    try {
        std::uninitialized_copy(data, data + size, newArr);
    } catch (...) {
        delete[] reinterpret_cast<int8_t*>(newArr);
        throw;
    }

    for (size_t i = 0; i < size; ++i) {
        data[i].~T();
    }

    delete[] reinterpret_cast<int8_t*>(data);
    data = newArr;
    capacity = reserved_size;
}

template <typename T>
void myVector<T>::resize(size_t new_size, const T& value) {
    if (new_size > capacity) {
        throw std::range_error("Capacity overflow");
    }

    if (new_size > capacity) reserve(new_size);

    if (new_size > size) {
        for (size_t i = size; i != new_size; ++i){
            data[i] = T(value);
        }
    }

    if (new_size < size) {
        for (size_t i = new_size; i != size; ++i) {
            data[i].~T();
        }
    }

    size = new_size;
}

template <typename T>
void myVector<T>::shrink_to_fit() {
    if (size == 0) {
        reserve(1);
        return;
    }

    reserve(size);
}

template <typename T>
void myVector<T>::push_back(const T& value) {
    if (capacity == size){
        if (capacity * 2 < capacity){
            throw std::range_error("Capacity overflow");
        }

        reserve(2 * capacity);
    }

    data[size] = value;
    ++size;
}

template <typename T>
void myVector<T>::pop_back() {
    if (size == 0) return;

    --size;
    data[size].~T();
}

template <typename T>
void myVector<T>::clear() {
    for (size_t i = 0; i != size; ++i) {
        data[i].~T();
    }
    size = 0;
    shrink_to_fit();
}

template <typename T>
T& myVector<T>::at(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    return data[index];
}

template <typename T>
T& myVector<T>::front() {
    if (size == 0) {
        throw std::range_error("Vector is empty");
    }

    return data[0];
}

template <typename T>
T& myVector<T>::back() {
    if (size == 0) {
        throw std::range_error("Vector is empty");
    }

    return data[size - 1];
}

template <typename T>
template <typename... Args>
void myVector<T>::emplace_back(const Args& ...args) {
    if (capacity == size) reserve(2 * capacity);

    new (data + size) T(args...);
    ++size;
}

template <typename T>
T& myVector<T>::operator[](size_t i) const {
    return data[i];
}
