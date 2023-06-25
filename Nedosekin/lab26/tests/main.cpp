#include "../include/Queue.hpp"
#include "../src/Benchmark.cpp"

int main()
{
    Queue<int> queue;
    queue.push(1);
    queue.push(3);
    queue.push(5);
    queue.push(2);
    queue.push(4);
    queue.push(20);
    queue.push(-20);

    std::cout << "Original Queue: ";
    std::cout << queue << std::endl;

    queue.Sort();

    std::cout << "\nSorted Queue: ";
    std::cout << queue << std::endl;

    queue.pop();

    std::cout << "After pop: ";
    std::cout << queue << std::endl;

    std::cout << "If you want to start benchmark work enter 1, else enter 0" << std::endl;
    int bench = 0;
    std::cin >> bench;
    if(bench == 1) {
        benchmark();
    }
}
