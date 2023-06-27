#ifndef LAB26_STACK_HPP 
#define LAB26_STACK_HPP 
#include <iostream> 
 
template <typename T> 
class Stack { 
private: 
    T* data; 
    int capacity; 
    int size; 
 
public: 
    Stack(); 
 
    void push(T value); 
    T pop(); 
    T top() const; 
    bool empty() const; 
    int get_size() const; 
    void bubbleSort(Stack<T>& s); 
}; 
 
#include "../src/stack.cpp" 
#endif //LAB26_STACK_HPP
