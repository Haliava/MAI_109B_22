#ifndef KP7_MATRIX_HPP
#define KP7_MATRIX_HPP
#include "../include/myVector.hpp"

class Matrix {
private:
    myVector<int> line_matrix;
    size_t matrix_lines;
    size_t matrix_columns;

public:
    Matrix();
    Matrix(size_t lines, size_t columns);

    friend std::istream& operator>>(std::istream& is, Matrix& matrix);

    void multiplication(const myVector<int>& cin_vector_string);
};

#include "../src/Matrix.cpp"

#endif //KP7_MATRIX_HPP
