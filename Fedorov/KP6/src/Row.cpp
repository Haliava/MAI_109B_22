#include "../include/Row.hpp"
#include <iomanip>
#include <iostream>

void Row::print() {
    std::cout
            << std::setw(20) << std::left << surname << "\t|\t"
            << std::setw(10) << std::left << initials << "\t|\t"
            << std::setw(15) << std::left << items_quantity << "\t|\t"
            << std::setw(15) << std::left << items_weight << "\t|\t"
            << std::setw(40) << std::left << destination << "\t|\t"
            << std::setw(15) << std::left << departure_time << "\t|\t"
            << std::setw(15) << std::left << has_transfer << "\t|\t"
            << std::setw(50) << std::left << children_info << std::endl;
}

Row::Row(const std::string &surname, const std::string &initials, const size_t &items_quantity,
         const size_t &items_weight,
         const std::string &destination, const std::string &departure_time, const bool &has_transfer,
         const std::string &children_info) : surname(surname), initials(initials), items_quantity(items_quantity),
                                             items_weight(items_weight), destination(destination),
                                             departure_time(departure_time), has_transfer(has_transfer),
                                             children_info(children_info) {}

std::ostream &operator<<(std::ostream &out, const Row &passenger) {
    out.write(passenger.surname.c_str(), passenger.surname.length() + 1);
    out.write(passenger.initials.c_str(), passenger.initials.length() + 1);
    out.write((char *) &passenger.items_quantity, sizeof(passenger.items_quantity));
    out.write((char *) &passenger.items_weight, sizeof(passenger.items_weight));
    out.write(passenger.destination.c_str(), passenger.destination.length() + 1);
    out.write(passenger.departure_time.c_str(), passenger.departure_time.length() + 1);
    out.write((char *) &passenger.has_transfer, sizeof(passenger.has_transfer));
    out.write(passenger.children_info.c_str(), passenger.children_info.length() + 1);

    return out;
}

std::istream &operator>>(std::istream &in, Row &passenger) {
    getline(in, passenger.surname, '\0');
    getline(in, passenger.initials, '\0');
    in.read((char *) &passenger.items_quantity, sizeof(passenger.items_quantity));
    in.read((char *) &passenger.items_weight, sizeof(passenger.items_weight));
    getline(in, passenger.destination, '\0');
    getline(in, passenger.departure_time, '\0');
    in.read((char *) &passenger.has_transfer, sizeof(passenger.has_transfer));
    getline(in, passenger.children_info, '\0');
    return in;
}

