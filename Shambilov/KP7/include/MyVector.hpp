#ifndef KP7_MYVECTOR_HPP
#define KP7_MYVECTOR_HPP
#include <iostream>
#pragma once

template <typename T>
class myVector{
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    myVector();
    myVector(const myVector<T>&);
    myVector(const std::initializer_list<T>& list);
    ~myVector();

    size_t get_size() const;
    size_t get_capacity() const;

    bool operator==(const myVector<T>& another_vector);
    bool operator!=(const myVector<T>& another_vector);
    bool empty() const;

    void reserve(size_t n);
    void resize(size_t new_size, const T& value = T());
    void shrink_to_fit();
    void push_back(const T& value);
    void pop_back();
    void clear();

    template <typename... Args>
    void emplace_back(const Args& ...args);

    T& at(size_t index);
    T& front();
    T& back();
    T& operator[](size_t i) const;
};

#endif //KP7_MYVECTOR_HPP
