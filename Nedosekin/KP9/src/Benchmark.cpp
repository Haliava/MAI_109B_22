#include "../include/Table.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

void benchmark() {
    std::cout << "Comparing my \"Sort\" and \"sort\" from STL\n\n";

    Table<long double> myTest1;
    std::vector<long double> stdTest1;

    for (size_t i = 0; i != 100; ++i){
        myTest1.push_back(i + 0.26, "sad");
        stdTest1.push_back(i + 0.27);
    }

    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
    myTest1.sort();
    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
    std::cout << "Time of work my Sort(100): " <<
    std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " milliseconds\n";

    start_time = std::chrono::steady_clock::now();
    std::sort(stdTest1.begin(), stdTest1.end());
    end_time = std::chrono::steady_clock::now();
    std::cout << "Time of work original sort(100): " <<
    std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " milliseconds\n\n";




    Table<long double> myTest2;
    std::vector<long double> stdTest2;

    for (size_t i = 0; i != 1000; ++i){
        myTest2.push_back(i + 0.26, "sad");
        stdTest2.push_back(i + 0.27);
    }

    start_time = std::chrono::steady_clock::now();
    myTest2.sort();
    end_time = std::chrono::steady_clock::now();
    std::cout << "Time of work my Sort(1000): " <<
    std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " milliseconds\n";

    start_time = std::chrono::steady_clock::now();
    std::sort(stdTest2.begin(), stdTest2.end());
    end_time = std::chrono::steady_clock::now();
    std::cout << "Time of work original sort(1000): " <<
    std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " milliseconds\n\n";




    Table<long double> myTest3;
    std::vector<long double> stdTest3;

    for (size_t i = 0; i != 10000; ++i){
        myTest3.push_back(i + 0.26, "sad;fnsadf.");
        stdTest3.push_back(i + 0.27);
    }

    start_time = std::chrono::steady_clock::now();
    myTest3.sort();
    end_time = std::chrono::steady_clock::now();
    std::cout << "Time of work my Sort(10000): " <<
    std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " milliseconds\n";

    start_time = std::chrono::steady_clock::now();
    std::sort(stdTest3.begin(), stdTest3.end());
    end_time = std::chrono::steady_clock::now();
    std::cout << "Time of work original sort(10000): " <<
    std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " milliseconds\n\n";
    
}