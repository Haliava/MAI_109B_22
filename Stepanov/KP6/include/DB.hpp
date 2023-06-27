#ifndef DB_HPP_INCLUDED
#define DB_HPP_INCLUDED
#include "friend_list_declaration.hpp"
#include "passenger.hpp"
#include <direct.h>
#include <io.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>

class DB
{
    FILE *file;
    std::string_view path_to_file;

public:
    DB() = default;
    DB(const std::string &db_name);
    ~DB();
    std::string createDB(const std::string &db_name = "DBFile");
    void deleteDB();
    void addData(const Passenger &new_pas);
    void print() const;
    void find_passengers(const uint64_t &num_of_addition_items) const;
};
#include "../src/DB.cpp"

#endif// DB_HPP_INCLUDED
