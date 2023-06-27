#pragma once

#include <cstddef>
#include <iostream>
#include <exception>

template <typename T>
class Vector {
public:
    Vector();
    ~Vector();
    Vector(const Vector& v);
    Vector(Vector&& v);
    Vector& operator=(const Vector& v);
    Vector& operator=(Vector&& v);
    void reserve(size_t n);
    void resize(size_t n);
    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();
    T& operator[](size_t i);
    const T& operator[](size_t i) const;
    size_t size() const;
    bool empty() const;
    void clear();

private:
    size_t dataSize;
    size_t dataSizeMax;
    unsigned char* data;
};
#include "../src/Vector.cpp"
