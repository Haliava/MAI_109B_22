#include <iostream>
#include "../include/Deque.hpp"
#include "../src/benchmark.cpp"


int main() {
    std::cout << std::endl << "-----------------------------------------" << std::endl;
    benchmark();

    std::cout << std::endl << "-----------------------------------------" << std::endl;
    std::cout << "List interface test." << std::endl;

    srand(time(NULL));
    Deque<int64_t> a;
    for (int64_t i = 100; i >= 0; --i) {
        a.push_back(random() % (200 - (-200) + 1) + (-200));
    }

    std::cout << "a: " << a << std::endl;

    a.pop_back();
    a.pop_front();
    std::cout << "a: " << a << std::endl;
    a.push_front(146);
    a.push_front(-1);

    std::cout << "a: " << a << std::endl;

    std::cout << "a: ";
    int64_t i = 0;
    for (auto it = a.begin(); it != a.end(); --it) {
        it.get_node()->set_data(it.get_node()->get_data() + (++i) * 3);
        std::cout << *it << "\t";
    }
    std::cout << std::endl;

    Deque<int64_t> b(a);
    a.clear();
    a.push_back(133);
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    a.concatenate(b);
    std::cout << "a: " << a << std::endl;

    a.sort();
    std::cout << "a: " << a << std::endl;

    return 0;
}
