#ifndef ROW_HPP_INCLUDED
#define ROW_HPP_INCLUDED

#include <string>

class Row {
private:
    std::string surname;
    std::string initials;
    size_t items_quantity = 0;
    size_t items_weight = 0;
    std::string destination;
    std::string departure_time;
    bool has_transfer = false;
    std::string children_info;


public:

    Row() = default;

    Row(
            const std::string &surname,
            const std::string &initials,
            const size_t &items_quantity,
            const size_t &items_weight,
            const std::string &destination,
            const std::string &departure_time,
            const bool &has_transfer,
            const std::string &children_info
    );

    void print();

    friend std::ostream& operator<<(std::ostream& out, const Row& passenger);
    friend std::istream& operator>>(std::istream& in, Row& passenger);

    friend class Database;
};


#include "../src/Row.cpp"

#endif
