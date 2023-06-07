#include "../include/Database.h"
#include <iostream>
#include <string>
#include "../../../Huan/kp7/Vector.hpp"

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
    Vector<std::string> grades;
    for (int i = 0; i < table.size(); i++) {
        grades.push_back(std::to_string(table[i].grade_number) + table[i].grade_letter);
    }

    for (int i = 0; i < grades.size(); i++) {
        int M = 0;
        int F = 0;
        for (int j = 0; j < table.size(); j++) {
            std::string sex = table[i].sex;

            if (sex == "F") F++;
            else if (sex == "M") M++;
        }

        if (F > M) output << grades[i] << " \n";
    }

    output.close();
    return "../tests/" + output_file + ".txt";
}
