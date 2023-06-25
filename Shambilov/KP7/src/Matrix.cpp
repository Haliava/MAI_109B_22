#include <iostream>
#include "../include/Matrix.hpp"

Matrix::Matrix(): matrix_lines(0), matrix_columns(0) {
    line_matrix.push_back(0);
    line_matrix.push_back(0);
}

Matrix::Matrix(size_t lines, size_t columns): matrix_lines(lines), matrix_columns(columns) {
    line_matrix.push_back(0);
    line_matrix.push_back(0);
}

std::istream& operator>>(std::istream& is, Matrix& matrix) {
    matrix.line_matrix.pop_back();
    size_t line;
    size_t columns;
    int input_value;

    is >> line >> columns;

    matrix.matrix_lines = line;
    matrix.matrix_columns = columns;

    for (size_t i = 0; i < line; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            is >> input_value;
            if (input_value != 0) {
                if (matrix.line_matrix.back() == 0) {
                    matrix.line_matrix.push_back(i + 1);
                }
                matrix.line_matrix.push_back(j + 1);
                matrix.line_matrix.push_back(input_value);
            }
        }

        if (matrix.line_matrix.back() != 0) {
            matrix.line_matrix.push_back(0);
        }
    }

    matrix.line_matrix.push_back(0);

    return is;
}

void Matrix::multiplication(const myVector<int>& cin_vector_string) {

    if (cin_vector_string.get_size() != matrix_lines) {
        throw std::range_error("Vector columns not equal matrix lines");
    }

    myVector<int> result;

    for (size_t i = 0; i != matrix_columns; ++i) {
        result.push_back(0);
    }

    size_t cur_line = 0;

    while (cur_line < line_matrix.get_size()) {
        int j = line_matrix[cur_line];
        if (j == 0){
            ++cur_line;

            if (cur_line >= line_matrix.get_size() || line_matrix[cur_line] == 0) {
                break;
            }

            j = line_matrix[cur_line];
        }

        uint64_t cur_column = cur_line + 1;
        uint64_t column_of_result_vector = line_matrix[cur_line] - 1;

        for (size_t column = cur_column; line_matrix[column] != 0; column += 2) {
            int value = line_matrix[column + 1];
            result[line_matrix[column] - 1] += (cin_vector_string[column_of_result_vector] * value);
            cur_line = column;
        }

        ++cur_line;
    }

    uint64_t non_zero_elements = 0;
    std::cout << "Result: ";
    for (size_t i = 0; i != result.get_size(); ++i) {
        if (result[i] != 0) ++non_zero_elements;
        std::cout << result[i] << " ";
    }
    std::cout << "\nnon-zeros elements: " << non_zero_elements << "\n";
}
