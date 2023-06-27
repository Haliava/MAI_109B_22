#include "../include/List.hpp"
#include <forward_list>
#include <chrono>
void benchmark(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    List<size_t> myLs;
    std::forward_list<size_t> stdLs;



    std::cout << "Push_front(100):" << std::endl;

    std::cout << "Library list" << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();;
    for(size_t i = 0; i < 100; ++i){
        stdLs.push_front(i);
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100; ++i){
        myLs.push_front(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;



    std::cout << "Push_front(1000):" << std::endl;

    std::cout << "Library list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000; ++i){
        stdLs.push_front(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000; ++i){
        myLs.push_front(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;




    std::cout << "Push_front(10000):" << std::endl;

    std::cout << "Library list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        stdLs.push_front(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        myLs.push_front(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;



    std::cout << "Push_front(100000):" << std::endl;

    std::cout << "Library list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100000; ++i){
        stdLs.push_front(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100000; ++i){
        myLs.push_front(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;



    std::cout << "Push_front(1000000):" << std::endl;

    std::cout << "Library list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        stdLs.push_front(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        myLs.push_front(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;



    std::cout << "Pop_front(10000):" << std::endl;

    std::cout << "Library list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        stdLs.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        myLs.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;



    std::cout << "Pop_front(100000):" << std::endl;

    std::cout << "Library list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100000; ++i){
        stdLs.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100000; ++i){
        myLs.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;




    std::cout << "Pop_front(1000000):" << std::endl;

    std::cout << "Library list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        stdLs.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        myLs.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;





    std::cout << "Pop_back(100):" << std::endl;

    std::cout << "My list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100; ++i){
        myLs.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;



    std::cout << "Push_back(1000):" << std::endl;

    std::cout << "My list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000; ++i){
        myLs.push_back(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;



    std::cout << "Push_back(10000):" << std::endl;

    std::cout << "My list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        myLs.push_back(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;



    std::cout << "insert(1000):" << std::endl;

    std::cout << "Library list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000; ++i){
        stdLs.insert_after(stdLs.begin(), 5);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000; ++i){
        myLs.insert(myLs.begin(), 5);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;



    std::cout << "insert(10000):" << std::endl;

    std::cout << "Library list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        stdLs.insert_after(stdLs.begin(), 5);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        myLs.insert(myLs.begin(), 5);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;




    std::cout << "insert(100000):" << std::endl;

    std::cout << "Library list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100000; ++i){
        stdLs.insert_after(stdLs.begin(), 5);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100000; ++i){
        myLs.insert(myLs.begin(), 5);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;



    std::cout << "insert(1000000):" << std::endl;

    std::cout << "Library list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        stdLs.insert_after(stdLs.begin(), 5);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My list" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        myLs.insert(myLs.begin(), 5);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;



    std::cout << "erase(~1000000):" << std::endl;

    std::cout << "Library list" << std::endl;
    begin = std::chrono::steady_clock::now();
    stdLs.erase_after(stdLs.begin(), stdLs.end());
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My list" << std::endl;
    begin = std::chrono::steady_clock::now();
    myLs.erase(myLs.begin(), myLs.end());
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;
}