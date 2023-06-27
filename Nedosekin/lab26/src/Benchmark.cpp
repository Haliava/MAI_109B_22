#include "../include/Queue.hpp"

#include <queue>
#include <chrono>

void benchmark(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    Queue<size_t> myQ;
    std::queue<size_t> stdQ;



    std::cout << "Push(100):" << std::endl;

    std::cout << "Library queue" << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();;
    for(size_t i = 0; i < 100; ++i){
        stdQ.push(i);
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100; ++i){
        myQ.push(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;



    std::cout << "Push_front(1000):" << std::endl;

    std::cout << "Library queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000; ++i){
        stdQ.push(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000; ++i){
        myQ.push(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;




    std::cout << "Push_front(10000):" << std::endl;

    std::cout << "Library queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        stdQ.push(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        myQ.push(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;





    std::cout << "Push_front(100000):" << std::endl;

    std::cout << "Library queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100000; ++i){
        stdQ.push(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100000; ++i){
        myQ.push(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;





    std::cout << "Push_front(1000000):" << std::endl;

    std::cout << "Library queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        stdQ.push(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        myQ.push(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;





    std::cout << "Push_front(10000000):" << std::endl;

    std::cout << "Library queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000000; ++i){
        stdQ.push(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000000; ++i){
        myQ.push(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;





    std::cout << "Pop(100):" << std::endl;

    std::cout << "Library queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100; ++i){
        stdQ.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100; ++i){
        myQ.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;




    std::cout << "Pop(1000):" << std::endl;

    std::cout << "Library queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000; ++i){
        stdQ.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000; ++i){
        myQ.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;




    std::cout << "Pop(10000):" << std::endl;

    std::cout << "Library queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        stdQ.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        myQ.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;





    std::cout << "Pop(100000):" << std::endl;

    std::cout << "Library queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100000; ++i){
        stdQ.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100000; ++i){
        myQ.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;




    std::cout << "Pop(1000000):" << std::endl;

    std::cout << "Library queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        stdQ.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        myQ.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;





    std::cout << "Pop(10000000):" << std::endl;

    std::cout << "Library queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000000; ++i){
        stdQ.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My queue" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000000; ++i){
        myQ.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;
}