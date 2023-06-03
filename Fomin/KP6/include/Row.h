#ifndef KP_6_INCLUDE_ROW_HPP_
#define KP_6_INCLUDE_ROW_HPP_

#include <iostream>
#include <string>

class Row {
    friend class DataBase;

private:
    std::string surname;
    std::string sex;
    size_t grade_number;
    std::string grade_letter;
    std::string university;
    std::string workplace;

public:
    Row() = default;
    Row(const std::string &surname,
        const std::string &sex,
        const size_t &grade_number,
        const std::string &grade_letter,
        const std::string &university,
        const std::string &workplace)
            : surname(surname), sex(sex), grade_number(grade_number), grade_letter(grade_letter), university(university), workplace(workplace) {
    }

    ~Row() = default;
};

#endif //KP_6_INCLUDE_ROW_HPP_