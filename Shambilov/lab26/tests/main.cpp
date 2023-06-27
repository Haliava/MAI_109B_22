#include "../include/stack.hpp"
#include "../src/stack.cpp"
#include <iostream>

int main() {
    Stack<int> s;
    s.push(5);
    s.push(3);
    s.push(7);
    s.push(1);
    s.push(9);
    std::cout << "Before sorting: ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
    s.push(5);
    s.push(3);
    s.push(7);
    s.push(1);
    s.push(9);
    s.bubbleSort(s);
    std::cout << "After sorting: ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
    return 0;
}
