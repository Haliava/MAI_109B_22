#include "../include/Vector.hpp"
#include <chrono>
#include <vector>

void benchmark()
{
    

    std::cout << "Push_back(50)" << std::endl;
    std::cout << "Library vector:" << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Vector<int> Vec2;
    for (int64_t pushValue = 0; pushValue < 50; ++pushValue) {
        Vec2.push_back(pushValue);
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    std::vector<int> vec2;
    for (int64_t pushValue = 0; pushValue < 50; ++pushValue) {
        vec2.push_back(pushValue);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;




    std::cout << "push_back(1000):" << std::endl;

    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 1000; ++popCount) {
        Vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 1000; ++popCount) {
        vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;




    std::cout << "push_back(10000):" << std::endl;

    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 10000; ++popCount) {
        Vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 10000; ++popCount) {
        vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;




    std::cout << "push_back(10^6):" << std::endl;

    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 1000000; ++popCount) {
        Vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 1000000; ++popCount) {
        vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;




    std::cout << "push_back(10^7):" << std::endl;

    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 10000000; ++popCount) {
        Vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 10000000; ++popCount) {
        vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;

 
    std::cout << "Pop_back(50):" << std::endl;

    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 50; ++popCount) {
        Vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 50; ++popCount) {
        vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;




    std::cout << "Pop_back(1000):" << std::endl;

    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 1000; ++popCount) {
        Vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 1000; ++popCount) {
        vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;





    std::cout << "Pop_back(10000):" << std::endl;

    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 10000; ++popCount) {
        Vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 10000; ++popCount) {
        vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;





    std::cout << "Pop_back(10^6):" << std::endl;

    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 1000000; ++popCount) {
        Vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 1000000; ++popCount) {
        vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;






    std::cout << "Pop_back(10^7):" << std::endl;

    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 10000000; ++popCount) {
        Vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 10000000; ++popCount) {
        vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;
 

}
