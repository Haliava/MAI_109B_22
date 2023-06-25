#include "../include/matrix.hpp"
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>

Martix::Martix() {
    M.push_back(0);
    A.push_back(0);
}

Martix::Martix(const std::string& file_name) {
    std::fstream file;
    std::string str;
    
    M.push_back(1); // Для удобной индексации

    file.open(file_name);
    while (!file.eof()) {
        getline(file, str);
        std::istringstream line(str);
        ++m;
        size_t col = 0;
        for (int64_t a; line >> a; ) {
            ++col;
            if (a != 0) {
                if (M.size() != m) {
                    M.push_back(A.size());
                } else {
                    A.pop_back();
                    A.push_back(A.size() + 1); 
                }

                A.push_back(col);
                A.push_back(a);
                A.push_back(0);
            }
        } 
        if (M.size() != m) {
            M.push_back(0);
        }
        if (n == 0) {
            n = col;
        }
    }
    M.pop_back(); // EOF

    file.close();
}

std::ostream& operator<<(std::ostream& out, Martix& mat) {
    for (size_t i = 0; i < mat.M.size(); ++i) {
        if (mat.M[i] != 0) {
            size_t k = mat.M[i];
            size_t pos = mat.A[k];
            for (size_t j = 1; j < mat.n + 1; ++j) {
                if (pos != j) {
                    out << 0 << ' ';
                } else {
                    out << mat.A[k + 1] << ' ';
                    if (mat.A[k+2] != 0) {
                        k += 3;
                        pos = mat.A[k];
                    }
                }
            }
        }
        else {
            for (size_t j = 0; j < mat.n; ++j) {
                out << 0 << ' ';
            }
        }
        out << '\n';
    }

    return out;
}

void Martix::print_as_vectors() {
    for (size_t i = 0; i < M.size(); ++i) {
        std::cout << M[i] << ' ';
    }
    std::cout << '\n';
    for (size_t i = 0; i < A.size(); ++i) {
        std::cout << A[i] << ' ';
    }
    std::cout << '\n';
}

Vector<int64_t> Martix::multuply_by_vector(Vector<int64_t> vec) {
    Vector<int64_t> res;
    for (size_t i = 0; i < n; ++i) {
        res.push_back(0);
    }
    for (size_t i = 0; i < M.size(); ++i) {
        if (M[i] != 0) {
            size_t k = M[i];
            while (true) {
                res[A[k]-1] += vec[i] * A[k+1];
                if (A[k+2] != 0) {
                    k += 3;
                } else {
                    break;
                }
            }
        }
    }
    return res;
}
