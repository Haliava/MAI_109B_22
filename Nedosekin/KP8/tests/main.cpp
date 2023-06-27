#include "../include/List.hpp"
#include "../src/Benchmark.cpp"
int64_t transform(std::string& set)
{
    int64_t elem = 0;
    for(int64_t i = 0 ; i < set.size() ; ++i) {
        char c = set[i];
        elem = elem | charToSet(c);
    }
    return elem;
}
int main()
{
    List<int64_t> sets;
    std::string s1 = "asdw";
    std::string s2 = "qwerty";
    std::string s3 = "zxcvbn";
    std::string s4 = "gloty";
    int64_t elem1 = transform(s1);
    int64_t elem2 = transform(s2);
    int64_t elem3 = transform(s3);
    int64_t elem4 = transform(s4);
    sets.emplace_back(elem1, elem2);
    sets.emplace_front(elem3, elem4);
    std::cout << "After emplace_back and emplace_front" << std::endl;
    std::cout << sets << std::endl;
    std::cout << "Size of list : " << sets.size() << std::endl; 
    std::cout << "Look, we can not swap begin - 1 and begin + 1" << std::endl;
    sets.swap(1);
    std::cout << sets << std::endl;
    std::cout << "Swap 1 and 3 sets" << std::endl;
    sets.swap(2);
    std::cout << sets << std::endl;
    sets.pop_back();
    sets.pop_front();
    std::cout << "After pop_back and pop_front" << std::endl;
    std::cout << sets << std::endl;
    std::cout << "Size of list : " << sets.size() << std::endl; 
    Iterator<int64_t> eraser = sets.begin();
    sets.erase(eraser);
    std::cout << "After erase: " << std::endl;
    std::cout << sets << std::endl;

    std::string s5 = "asdfghjkl";
    int64_t elem5 = transform(s5);
    Iterator<int64_t> beg = sets.begin();
    sets.insert(beg, elem5);
    std::cout << "After insert: " << std::endl;
    std::cout << sets << std::endl;


    std::cout << "If you want to start benchmark work enter 1, else enter 0" << std::endl;
    int bench = 0;
    std::cin >> bench;
    if(bench == 1) {
        benchmark();
    }
}