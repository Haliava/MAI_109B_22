#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <initializer_list>
#include <iostream>

template<typename T>
class Vector {
private:
    T* arr;
    size_t sz;
    size_t cap;

public:
    Vector();
    Vector(const Vector& other);
    Vector(const std::initializer_list<T>& init);

    void reserve(size_t new_cap);
    void resize(size_t new_sz, const T& value = T());

    void push_back(const T& value);
    template<typename... Args>
    void emplace_back(const Args& ...args); 
    void pop_back();
    
    T& at(size_t idx);
    T& front();
    T& back();
    bool empty();
    size_t size() const;
    size_t capacity() const;

    T& operator[](size_t idx);
    bool operator==(const Vector<T>& other_vector);
    bool operator!=(const Vector<T>& other_vector);

    void shrink_to_fit();
    void clear();
    ~Vector();
};

#include "../src/vector.cpp"

#endif // VECTOR_HPP
