#ifndef DATABASE_HPP_INCLUDED
#define DATABASE_HPP_INCLUDED

#include "Row.hpp"
#include <string>
#include <iostream>
#include <string>
#include <fstream>

class Database {
private:
    std::string path;
public:

    Database() = default;
    explicit Database(const std::string &filename);
    ~Database() = default;

    std::string create_db(const std::string &filename = "db1");
    void delete_db();

    void add_row(const Row &passenger);
    void print() const;
    void lab_task(const size_t& p1, const size_t& p2) const;

};


#include "../src/Database.cpp"

#endif
