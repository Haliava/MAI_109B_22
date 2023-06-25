#ifndef KP6_DATABASE_HPP
#define KP6_DATABASE_HPP
#include "../include/RowTable.hpp"
#include "../src/RowTable.cpp"
#include <iostream>
#include <string>

class DataBase{
private:
    FILE* file = nullptr;
    std::string_view file_path;

public:
    DataBase() = default;
    DataBase(const std::string& file_name);
    ~DataBase();

    std::string createFile(const std::string& file_name = "DBFile");
    void deleteFile();
    void addData(const RowTable& computer);
    void print() const;
    void allStudentPc() const;
};

#endif //KP6_DATABASE_HPP
