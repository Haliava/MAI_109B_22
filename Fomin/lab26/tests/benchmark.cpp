#include "../src/stack.cpp"
#include <chrono>
#include <iostream>
#include <stack>

void benchmark() {
    std::cout << "Comparing my \"stack\" and \"stack\" from STL\n\n";

    Stack<int> stack;
    std::stack<int> std_stack;

    // PUSH
    std::cout << "push\n";
    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
    for (int i = 0; i != 1000000; ++i)
        stack.push(i);

    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
    std::cout << "mine: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()
              << " ms\n";

    start_time = std::chrono::steady_clock::now();
    for (int i = 0; i != 1000000; ++i)
        std_stack.push(i);

    end_time = std::chrono::steady_clock::now();
    std::cout << "stl: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()
              << " ms\n";




    // POP
    std::cout << "\npop\n";
    start_time = std::chrono::steady_clock::now();
    for (int i = 0; i != 1000000; ++i)
        stack.pop();

    end_time = std::chrono::steady_clock::now();
    std::cout << "mine: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()
              << " ms\n";

    start_time = std::chrono::steady_clock::now();
    for (int i = 0; i != 1000000; ++i)
        std_stack.pop();

    end_time = std::chrono::steady_clock::now();
    std::cout << "stl: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()
              << " ms\n";




    // CLEAR
    std::cout << "\nclear\n";
    start_time = std::chrono::steady_clock::now();
    stack.clear();
    end_time = std::chrono::steady_clock::now();
    std::cout << "mine: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()
              << " ms\n";



    // TOP
    stack.push(1);
    std_stack.push(1);

    std::cout << "\ntop\n";
    start_time = std::chrono::steady_clock::now();
    stack.top();
    end_time = std::chrono::steady_clock::now();
    std::cout << "mine: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()
              << " ms\n";

    start_time = std::chrono::steady_clock::now();
    std_stack.top();
    end_time = std::chrono::steady_clock::now();
    std::cout << "stl: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()
              << " ms\n";
}