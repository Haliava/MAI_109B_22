#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "../../KP7/include/vector.hpp"
#include "row.hpp"
#include <fstream>
#include <string>

class Database {
private:
    std::string path;
    std::ofstream database;
    Vector<Row> table;

    void create_db();

public:
    Database();
    explicit Database(const std::string& file_name);

    void add_row(const Row& row);
    void print();
    void print_best_students(const size_t& p);

    ~Database();
};

#include "../src/database.cpp"

#endif // DATABASE_HPP
