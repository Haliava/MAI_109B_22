#include "../include/stack.hpp" 
#include <chrono> 
#include <stack> 
#include <iostream> 
 
void bencmark() { 
    std::cout << "Comparing my \"Stack\" and \"stack\" from STL\n\n"; 
 
    Stack<int> my_stack; 
    std::stack<int> original_stack; 
 
    std::cout << "push\n"; 
    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now(); 
    for (int i = 0; i != 1000000; ++i){ 
        my_stack.push(i); 
    } 
    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now(); 
    std::cout << "Time of work my Stack: " << 
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " milliseconds\n"; 
     
    start_time = std::chrono::steady_clock::now(); 
    for (int i = 0; i != 1000000; ++i){ 
        original_stack.push(i); 
    } 
    end_time = std::chrono::steady_clock::now(); 
    std::cout << "Time of work original stack: " << 
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " milliseconds\n"; 
 
    std::cout << "\ntop\n"; 
    start_time = std::chrono::steady_clock::now(); 
    for (int i = 0; i != 1000000; ++i){ 
        my_stack.top(); 
    } 
    end_time = std::chrono::steady_clock::now(); 
    std::cout << "Time of work my Stack: " << 
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " milliseconds\n"; 
 
    start_time = std::chrono::steady_clock::now(); 
    for (int i = 0; i != 1000000; ++i){ 
        original_stack.top(); 
    } 
    end_time = std::chrono::steady_clock::now(); 
    std::cout << "Time of work original stack: " << 
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " milliseconds\n"; 
 
   std::cout << "\npop\n"; 
    start_time = std::chrono::steady_clock::now(); 
    for (int i = 0; i != 1000000; ++i){ 
        my_stack.pop(); 
    } 
    end_time = std::chrono::steady_clock::now(); 
    std::cout << "Time of work my Stack: " << 
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " milliseconds\n"; 
 
    start_time = std::chrono::steady_clock::now(); 
    for (int i = 0; i != 1000000; ++i){ 
        original_stack.pop(); 
    } 
    end_time = std::chrono::steady_clock::now(); 
    std::cout << "Time of work original stack: " << 
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " milliseconds\n"; 
   
    return; 
}
