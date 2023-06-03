#ifndef KP_6_INCLUDE_DATABASE_HPP_
#define KP_6_INCLUDE_DATABASE_HPP_

#include "Row.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "../include/Vector.h"

class DataBase {
public:
    DataBase();
    explicit DataBase(const std::string& file_name);
    ~DataBase();

    void print();
    void addRow(const Row &row);
    std::string findClassesWithMoreMthanF(const std::string &output_file);

private:
    std::ofstream database;
    std::string path;
    std::vector<Row> table;

    void createTable();
};

#endif //KP_6_INCLUDE_DATABASE_HPP_