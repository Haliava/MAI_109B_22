#include "benchmark.cpp"
#include "../include/List.hpp"
#include <iostream>

int main() {
    benchmark();

    std::cout << "Benchmark finished its work" << '\n';

    List<int> lst(7);
    lst.push_front(5);
    lst.push_front(2);
    lst.push_front(0);
    lst.push_front(4);
    lst.push_front(8);
    lst.push_front(3);

    std::cout << lst << '\n';

    lst.task(3);
    std::cout << lst << '\n';

}