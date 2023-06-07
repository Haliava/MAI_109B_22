#ifndef LAB26_STACK_H
#define LAB26_STACK_H

#include "../../../Huan/kp7/Vector.hpp"

template<typename T>
class Stack {
private:
    Vector<T> stack;

public:
    Stack();

    void push(const T& value);
    T& pop();
    const T& top();
    bool empty();
    void clear();
    std::size_t size();

    /// find first element that's smaller than previous one and move it to the left until
    /// it becomes bigger (or until it becomes the first in the stack)
    void rearrangeStack();
};


#endif //LAB26_STACK_H
