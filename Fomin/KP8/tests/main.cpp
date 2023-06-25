#include <iostream>
#include "../src/List.cpp"
#include <forward_list>
#include <chrono>

using namespace std;

void benchmark() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    List<int> listHALIAVEN;
    std::forward_list<int> listSTD;

    std::cout << "\nPush" << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        listSTD.push_front(i);
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        listHALIAVEN.addNode(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << std::endl;

    std::cout << "Pop" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        listSTD.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        listHALIAVEN.popNode();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
}

int main() {
    auto testList = new List<int>();

    testList->addNode(1);
    testList->addNode(2);
    testList->addNode(3);
    testList->addNode(4);

    cout << "Initial List: ";
    testList->print();

    testList->deleteNode(1);

    cout << "\nDeleted 1: ";
    testList->print();

    testList->deleteAllPrevAndNextToValue(3);

    cout << "\nDeleted all values around value 3: ";
    testList->print();

    benchmark();
    return 0;
}