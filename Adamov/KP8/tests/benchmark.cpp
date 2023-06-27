#include "../include/list.hpp"
#include "../../KP7/include/vector.hpp"
#include <bits/chrono.h>
#include <iostream>
#include <forward_list>
#include <chrono>

void benchmark() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Vector<int64_t> comparsions = {1000, 10000, 100000};
    for (size_t k = 0; k < comparsions.size(); ++k) {
        std::cout << "Comparsion size: " << comparsions[k] << '\n';
        List<int64_t> my_list;
        std::forward_list<int64_t> f_list;

        std::cout << "Push_front:" << std::endl;
        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now(); 
        for (int64_t i = 0; i < comparsions[k]; ++i) {
            f_list.push_front(i);
        }
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); 
        std::cout << "STL: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

        start = std::chrono::steady_clock::now(); 
        for (int64_t i = 0; i < comparsions[k]; ++i) {
            my_list.push_front(i);
        }
        end = std::chrono::steady_clock::now(); 
        std::cout << "Ours: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

        std::cout << "Pop_front:" << std::endl;
        start = std::chrono::steady_clock::now(); 
        for (int64_t i = 0; i < comparsions[k]; ++i) {
            f_list.pop_front();
        }
        end = std::chrono::steady_clock::now(); 
        std::cout << "STL: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

        start = std::chrono::steady_clock::now(); 
        for (int64_t i = 0; i < comparsions[k]; ++i) {
            my_list.pop_front();
        }
        end = std::chrono::steady_clock::now(); 
        std::cout << "Ours: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

        f_list.clear();
        f_list.push_front(-1);
        my_list.clear();
        my_list.push_front(-1);

        std::cout << "Insert:" << std::endl;
        start = std::chrono::steady_clock::now();
        for (int64_t i = 0; i < comparsions[k]; ++i) {
            f_list.insert_after(f_list.begin(), i);
        }
        end = std::chrono::steady_clock::now(); 
        std::cout << "STL: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

        start = std::chrono::steady_clock::now(); 
        for (int64_t i = 0; i < comparsions[k]; ++i) {
            my_list.insert(my_list.begin(), i);
        }
        end = std::chrono::steady_clock::now(); 
        std::cout << "Ours: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

        std::cout << "Erase:" << std::endl;
        start = std::chrono::steady_clock::now(); 
        f_list.erase_after(f_list.begin(), f_list.end());
        end = std::chrono::steady_clock::now(); 
        std::cout << "STL: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

        start = std::chrono::steady_clock::now(); 
        my_list.erase(my_list.begin(), my_list.end());
        end = std::chrono::steady_clock::now(); 
        std::cout << "Ours: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

        std::cout << std::endl;
    }
}
