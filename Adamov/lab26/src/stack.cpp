#include "../include/stack.hpp"
#include <climits>
#include <stdexcept>

template<typename T>
Stack<T>::Stack(const Stack<T>& other) {
    vec = other.vec;
}

template<typename T>
void Stack<T>::push(const T& value) {
    vec.push_back(value);
}

template<typename T>
T& Stack<T>::pop() {
    if (!empty()) {
        T& res = vec.back();
        vec.pop_back();
        return res;
    }
    throw std::range_error("Stack is empty!");
}

template<typename T>
T& Stack<T>::back() {
    if (!empty()) {
        return vec.back();
    }
}

template<typename T>
size_t Stack<T>::size() const {
    return vec.size();
}

template<typename T>
bool Stack<T>::empty() {
    return vec.empty();
}

template<>
void Stack<int>::delete_max() {
    Stack<int> dop;
    int max_val = INT_MIN;
    while (!this->empty()) {
        int tmp = this->pop();
        if (tmp > max_val) {
            max_val = tmp;
        } 
        dop.push(tmp);
    }
    bool max_val_found = false;
    while (!dop.empty()) {
        int tmp = dop.pop();
        if (tmp != max_val or max_val_found != false) {
            this->push(tmp);
        }
        else if (tmp == max_val) {
            max_val_found = true;
        }
    }
    this->push(max_val); // add max element to the beginning
    this->pop(); // delete this element
}

template<typename T>
void Stack<T>::clear() {
    vec.clear();
}
