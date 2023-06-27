#include "../include/vector.hpp"
#include "../include/matrix.hpp"
#include "benchmark.cpp"
#include <iostream>

int main() {
    benchmark();

    Martix mt("matrix.txt");

    std::cout << "Внутреннее представлние:\n";
    mt.print_as_vectors();
    std::cout << "Внешнее представлние:\n";
    std::cout << mt << '\n';

    Vector<int64_t> mul = {2, 3, 4, 5};
    Vector<int64_t> res = mt.multuply_by_vector(mul);
    
    int not_zero = 0;
    std::cout << "Результат умножения:\n";
    for (size_t i = 0; i < res.size(); ++i) {
        if (res[i] == 0) {
            ++not_zero;
        }
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';
    std::cout << "Количество ненулевых элементов результата: "<< not_zero << '\n';

    return 0;
}
