#ifndef ROW_HPP
#define ROW_HPP

#include <string>

class Row {
    friend class Database;
private:
    size_t ID;
    size_t group_number;
    std::string surname;
    std::string inits;
    std::string sex;
    size_t calculus;
    size_t algebra;
    size_t geometry;

public:
    Row() = default;
    Row(const size_t& ID,
        const size_t& group_number,
        const std::string& surname,
        const std::string& inits,
        const std::string& sex,
        const size_t& calculus,
        const size_t& algebra,
        const size_t& geometry)
            : ID(ID), group_number(group_number), surname(surname), inits(inits), sex(sex), calculus(calculus), algebra(algebra), geometry(geometry) {}; 

    void print() const;

    ~Row() = default;
};

#include "../src/row.cpp"

#endif // ROW_HPP
