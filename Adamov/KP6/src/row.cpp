#include "../include/row.hpp"
#include <iostream>
#include <iomanip>

void Row::print() const {
    std::cout << std::setw(4) << std::left << ID << '\t'
        << std::setw(4) << std::left << group_number << '\t'
        << std::setw(10) << std::left << surname << '\t'
        << std::setw(8) << std::left << inits << '\t'
        << std::setw(8) << std::left << sex << '\t'
        << std::setw(8) << std::left << calculus << '\t'
        << std::setw(8) << std::left << algebra << '\t'
        << std::setw(8) << std::left << geometry << '\t';
}
