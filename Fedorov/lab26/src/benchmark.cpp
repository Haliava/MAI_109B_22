#include <chrono>
#include <fstream>
#include <iostream>
#include <deque>

void benchmark() {
    std::ifstream fin;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cout << "My 'Deque' vs 'std::deque' benchmark." << std::endl;
    fin.open("./tests/benchmark_test.txt",std::ios_base::in);
    Deque<int64_t> test1;
    std::deque<int64_t> test2;
    int64_t number, in_int;
    fin >> number;
    std::cout << "Numbers in a test file: " << number << std::endl << std::endl;

    std::cout << "push_back O(1)" << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int64_t y = 0; y < number; y++) {
        fin >> in_int;
        test1.push_back(in_int);
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    fin.clear();
    fin.seekg(0);
    fin >> in_int;
    begin = std::chrono::steady_clock::now();
    for (int64_t y = 0; y < number; y++) {
        fin >> in_int;
        test2.push_back(in_int);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    if (test1.size() != test2.size()) {
        throw std::exception();
    }


    std::cout << std::endl << "push_front O(1)" << std::endl;
    fin.clear();
    fin.seekg(0);
    begin = std::chrono::steady_clock::now();
    for (int64_t y = 0; y < number; y++) {
        fin >> in_int;
        test1.push_front(in_int);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    fin.clear();
    fin.seekg(0);
    fin >> in_int;
    begin = std::chrono::steady_clock::now();
    for (int64_t y = 0; y < number; y++) {
        fin >> in_int;
        test2.push_front(in_int);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    if (test1.size() != test2.size()) {
        throw std::exception();
    }


    std::cout << std::endl << "pop_front O(1)" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t y = 0; y < number; y++) {
        test1.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for (int64_t y = 0; y < number; y++) {
        test2.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    if (test1.size() != test2.size()) {
        throw std::exception();
    }


    std::cout << std::endl << ": test1.size =" << test1.size() << " test2.size =" << test1.size() << std::endl;
    std::cout << "clear" << std::endl;
    begin = std::chrono::steady_clock::now();
    test1.clear();
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    begin = std::chrono::steady_clock::now();
    test2.clear();
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

}
