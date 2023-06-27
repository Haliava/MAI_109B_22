#include "../include/stack.hpp"
#include "benchmark.cpp"
#include <iostream>

int main() {
    benchmark();

    Stack<int> st;
    st.push(4);
    st.push(5);
    st.push(3);
    st.push(5);
    st.push(2);
    st.push(1);

    st.delete_max();

    while (!st.empty()) {
        std::cout << st.pop() << ' ';
    }
    std::cout << '\n';
}
