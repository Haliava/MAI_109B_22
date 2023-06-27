#include "../include/database.hpp"
#include <iostream>
#include <iomanip>

Database::Database() {
    path = std::string(getenv("HOME")) + "/Documents/database.csv";
    database.open(path, std::ios::trunc);
    if (database.is_open()) {
        create_db();
    }
    else {
        std::cerr << "Unable to open/create database file.\n";
    }
    database.close();
}

Database::Database(const std::string& file_name) {
    path = std::string(getenv("HOME")) + "/Documents/" + file_name + ".csv";
    database.open(path, std::ios::trunc);
    if (database.is_open()) {
        create_db();
    }
    else {
        std::cerr << "Unable to open database file.\n";
    }
    database.close();
}

void Database::create_db() {
    if (database.is_open()) {
        database << "ID, group_number, surname, inits, sex, calculus, algebra, geometry" << '\n'; 
    }
    else {
        std::cerr << "Unable to open/create database file.\n";
    }
}

void Database::print() {
    std::cout << "---------------------------------------------------------------------------------------------------------\n";
    std::cout << std::setw(4) << std::left << "ID" << "\t"
        << std::setw(4) << std::left << "Group" << "\t"
        << std::setw(10) << std::left << "Surname" << "\t"
        << std::setw(8) << std::left << "Initials" << "\t"
        << std::setw(8) << std::left << "Sex" << "\t"
        << std::setw(8) << std::left << "Calculus" << "\t"
        << std::setw(8) << std::left << "Algebra" << "\t"
        << std::setw(8) << std::left << "Geometry" << "\t\n";
    std::cout << "---------------------------------------------------------------------------------------------------------\n";
    for (size_t i = 0; i < table.size(); ++i) {
        table[i].print();
        std::cout << "\n---------------------------------------------------------------------------------------------------------\n";
    }
}

void Database::add_row(const Row &row) {
    database.open(path, std::ios::out | std::ios::app);
    table.push_back(row);
    if (database.is_open()) {
        database << row.ID << ", " 
            << row.group_number << ", "
            << row.surname << ", "
            << row.inits << ", "
            << row.sex << ", "
            << row.calculus << ", "
            << row.algebra << ", "
            << row.geometry << '\n';
        database.close();
    }
    else {
        std::cerr << "Unable to open/create database file.\n";
    }
    database.close();
}

void Database::print_best_students(const size_t& p) {
    Vector<double> avg_marks;
    for (size_t i = 0; i < table.size(); ++i) {
        double avg = (table[i].calculus + table[i].algebra + table[i].geometry) / 3.0;
        avg_marks.push_back(avg);
    }
    
    std::cout << "Best " << p << " students:\n";
    std::cout << "-------------------------------------------------------------------------------------------------------------------------\n";
    std::cout << std::setw(4) << std::left << "ID" << '\t'
        << std::setw(4) << std::left << "Group" << '\t'
        << std::setw(10) << std::left << "Surname" << '\t'
        << std::setw(8) << std::left << "Initials" << '\t'
        << std::setw(8) << std::left << "Sex" << '\t'
        << std::setw(8) << std::left << "Calculus" << '\t'
        << std::setw(8) << std::left << "Algebra" << '\t'
        << std::setw(8) << std::left << "Geometry" << '\t'
        << std::setw(8) << std::left << "Average" << "\t\n";
    std::cout << "-------------------------------------------------------------------------------------------------------------------------\n";

    for (size_t i = 0; i < p; ++i) {
        double max_val = -1;
        double max_val_idx = 0;
        for (size_t j = 0; j < avg_marks.size(); ++j) {
            if (avg_marks[j] > max_val) {
                max_val = avg_marks[j];
                max_val_idx = j;
            }
        }
        // change printed rows avg_mark to -1 
        avg_marks[max_val_idx] = -1;
        table[max_val_idx].print();
        std::cout << std::setw(8) << std::left << max_val << '\n';
        std::cout << "-------------------------------------------------------------------------------------------------------------------------\n";
    }
}

Database::~Database() {
    if (database.is_open()) {
        database.close();
    }
}
