#include "../include/Database.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

DataBase::DataBase() {
    path = "../tests/database.txt";
    database.open(path, std::ios::trunc);
    if (database.is_open()) {
        createTable();
    } else {
        std::cerr << "Unable to create/open the database file." << std::endl;
    }
    database.close();
}

DataBase::DataBase(const std::string &file_name) {
    path = "../tests/" + file_name + ".txt";
    database.open(path, std::ios::trunc);
    if (database.is_open()) {
        createTable();
    } else {
        std::cerr << "Unable to create/open the database file." << std::endl;
    }
    database.close();
}

DataBase::~DataBase() {
    if (database.is_open()) {
        database.close();
    }
}

void DataBase::createTable() {
    if (database.is_open()) {
        database
                << "+---------------------+----------------+---------------------+--------------+----------------+-------------+"
                << std::endl;
        database
                << "|       Surname       | Sex            | Grade Number        | Grade letter | University     | Workplace   |"
                << std::endl;
        database
                << "+---------------------+----------------+---------------------+--------------+----------------+-------------+"
                << std::endl;
    } else {
        std::cerr << "Unable to create/open the database file." << std::endl;
    }
}

void DataBase::print() {
    std::ifstream file(path);
    std::string line;

    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}

void DataBase::addRow(const Row &row) {
    database.open(path, std::ios::app);
    table.push_back(row);
    if (database.is_open()) {
        database << "| " << std::left << std::setw(20) << row.surname
                 << "| " << std::left << std::setw(15) << row.sex
                 << "| " << std::left << std::setw(20) << row.grade_number
                 << "| " << std::left << std::setw(13) << row.grade_letter
                 << "| " << std::left << std::setw(15) << row.university
                 << "| " << std::left << std::setw(11) << row.workplace
                 << " |" << std::endl;
        database
                << "+---------------------+----------------+---------------------+--------------+----------------+-------------+"
                << std::endl;
        database.close();
    } else {
        std::cerr << "The database file is not open." << std::endl;
    }
}

std::string DataBase::findClassesWithMoreMthanF(const std::string &output_file) {
    std::string line;
    std::ofstream output(output_file);

    std::map<std::string, std::vector<int>> grade_map;

    for (int i = 0; i < table.size(); i++) {
        std::string sex = table[i].sex;
        std::string grade = std::to_string(table[i].grade_number) + table[i].grade_letter;

        if (!grade_map.contains(grade)) {
            grade_map[grade].push_back(0);
            grade_map[grade].push_back(0);
        }

        if (sex == "F") grade_map[grade][0]++;
        else if (sex == "M") grade_map[grade][1]++;
    }

    for (auto & [key, value] : grade_map) {
        if (value[1] > value[0]) output << key << " \n";
    }

    output.close();
    return "../tests/" + output_file + ".txt";
}