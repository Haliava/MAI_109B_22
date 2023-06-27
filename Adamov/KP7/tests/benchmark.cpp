#include "../include/vector.hpp"
#include <bits/chrono.h>
#include <cstdint>
#include <iostream>
#include <vector>
#include <chrono>

void benchmark() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int64_t comparsion_num = 100000000;
    Vector<int64_t> my_vec;
    std::vector<int64_t> vec;

    std::cout << "Push_back:" << std::endl;
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now(); 
    for (int64_t i = 0; i < comparsion_num; ++i) {
        vec.push_back(i);
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); 
    std::cout << "STL: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now(); 
    for (int64_t i = 0; i < comparsion_num; ++i) {
        my_vec.push_back(i);
    }
    end = std::chrono::steady_clock::now(); 
    std::cout << "Ours: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    std::cout << "Pop_back:" << std::endl;
    start = std::chrono::steady_clock::now(); 
    for (int64_t i = 0; i < comparsion_num; ++i) {
        vec.pop_back();
    }
    end = std::chrono::steady_clock::now(); 
    std::cout << "STL: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now(); 
    for (int64_t i = 0; i < comparsion_num; ++i) {
        my_vec.pop_back();
    }
    end = std::chrono::steady_clock::now(); 
    std::cout << "Ours: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    std::cout << "Shrink_to_fit:" << std::endl;
    start = std::chrono::steady_clock::now(); 
    vec.shrink_to_fit();
    end = std::chrono::steady_clock::now(); 
    std::cout << "STL: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now(); 
    my_vec.shrink_to_fit();
    end = std::chrono::steady_clock::now(); 
    std::cout << "Ours: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    std::cout << "Reserve:" << std::endl;
    start = std::chrono::steady_clock::now(); 
    vec.reserve(comparsion_num);
    end = std::chrono::steady_clock::now(); 
    std::cout << "STL: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now(); 
    my_vec.reserve(comparsion_num);
    end = std::chrono::steady_clock::now(); 
    std::cout << "Ours: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    std::cout << "Resize:" << std::endl;
    start = std::chrono::steady_clock::now(); 
    vec.resize(comparsion_num, 404);
    end = std::chrono::steady_clock::now(); 
    std::cout << "STL: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now(); 
    my_vec.resize(comparsion_num, 404);
    end = std::chrono::steady_clock::now(); 
    std::cout << "Ours: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    std::cout << "Clear:" << std::endl;
    start = std::chrono::steady_clock::now(); 
    vec.clear();
    end = std::chrono::steady_clock::now(); 
    std::cout << "STL: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now(); 
    my_vec.clear();
    end = std::chrono::steady_clock::now(); 
    std::cout << "Ours: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n" << std::endl;
}
