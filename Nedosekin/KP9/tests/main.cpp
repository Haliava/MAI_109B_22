#include <iostream>
#include "../include/Table.hpp"
#include <string>
#include "../src/Benchmark.cpp"

int main() {

    Table<long double> table;

    table.push_back(-4.1, "January");
    table.push_back(1.2, "February");
    table.push_back(3.5, "March");
    table.push_back(0.5, "April");
    table.push_back(6.78, "May");
    table.push_back(20.8, "June");
    table.push_back(20.8, "July");
    table.push_back(6.77, "August");
    table.push_back(1.25, "September");
    table.push_back(3.14, "October");
    table.push_back(14.1, "November");
    table.push_back(17.4, "December");
    table.push_back(-23.2, "END");
    table.push_back(2.5, "Monday");
    table.push_back(6.3, "Friday");
    table.push_back(1.2, "Saturday");
    table.push_back(1.7, "Sunday");
    table.push_back(20.8, "Thersday(i know that no tak writitsa)");

    table.sort();

    std::cout << table << std::endl;

    long double d = 3.14;
    Line<long double> search_res = table.search(d);

    if (search_res.get_value() != "\0") {
        std::cout << "Object with key '" << search_res.get_key()
                    << "' found! Data inside is '" << search_res.get_value()
                    << "'" << std::endl;

    } else {
        std::cout << "Object with key '" << search_res.get_key()
                    << "' not found!" << std::endl;
    }

    std::cout << "If you want to start benchmark work enter 1, else enter 0" << std::endl;
    int bench = 0;
    std::cin >> bench;
    if(bench == 1) {
        benchmark();
    }
}