#ifndef STACK_HPP
#define STACK_HPP

#include "../../KP7/include/vector.hpp"

template<typename T>
class Stack {
private:
    Vector<T> vec;

public:
    Stack() = default;
    Stack(const Stack& other);

    void push(const T& value);
    T& pop();
    T& back();
    size_t size() const;
    bool empty();

    void delete_max();

    void clear();
    ~Stack() = default;
};

#include "../src/stack.cpp"

#endif
