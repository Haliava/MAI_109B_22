#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "vector.hpp"

class Martix {
private:
    Vector<int64_t> M;
    Vector<int64_t> A;
    size_t m = 0;
    size_t n = 0;

public:
    Martix();
    Martix(const std::string& file_name);

    friend std::ostream& operator<<(std::ostream& out, Martix& mat);
    void print_as_vectors();

    Vector<int64_t> multuply_by_vector(Vector<int64_t> vec);
};

#include "../src/matrix.cpp"

#endif
