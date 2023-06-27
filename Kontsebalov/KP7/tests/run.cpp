#include "MyVector.hpp"
#include "MyVector.cpp"
#include "benchmark.cpp"
#include "Matrix.hpp"
#include "Matrix.cpp"
#include <iostream>

int main(){

    myVector<int> vector_string = {4, 10, 52, 0, 34, 47, -4, 9};
    Matrix sparse_matrix;

    std::cin >> sparse_matrix;
    myVector<int> res = sparse_matrix.multiply(vector_string);

    benchmark();
    return 0;
}