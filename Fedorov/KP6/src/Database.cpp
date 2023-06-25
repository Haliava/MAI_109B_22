#include "../include/Database.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <filesystem>

Database::Database(const std::string &filename) {
    path = create_db(filename);
}

std::string make_dir(const std::string &dir_name) {
    std::string dir_path = std::string(getenv("HOME")) + "/Documents/" + dir_name;

    if (!std::filesystem::is_directory(dir_path.c_str())) {
        std::filesystem::create_directories(dir_path.c_str());
    }

    return dir_path;
}

std::string Database::create_db(const std::string &filename) {
    std::fstream file;
    std::string curr_path = make_dir("Databases") + "/" + filename + ".dat";
    file.open(curr_path, std::ios::app);
    if (!file) {
        throw std::runtime_error("Problems with file creation");
    }
    file.close();
    return curr_path;
}

void Database::delete_db() {
    std::fstream file;
    if (file) file.close();
    remove(path.data());
}

void Database::add_row(const Row &passenger) {
    std::fstream file;
    if (!file) {
        throw std::runtime_error("File doesn't exist");
    }
    file.open(path.data(), std::ios::out | std::ios::app);
    file << passenger;
    file.close();
}


void Database::print() const {

    std::fstream file;
    std::cout
            << std::setw(20) << std::left << "Surname" << "\t|\t"
            << std::setw(8) << std::left << "Initials" << "\t|\t"
            << std::setw(15) << std::left << "Items quantity" << "\t|\t"
            << std::setw(15) << std::left << "Items weight" << "\t|\t"
            << std::setw(40) << std::left << "Destination" << "\t|\t"
            << std::setw(15) << std::left << "Departure time" << "\t|\t"
            << std::setw(15) << std::left << "Has transfer" << "\t|\t"
            << std::setw(50) << std::left << "Info about children" << std::endl;
    std::cout << "___________________________________________________________________________________________\n";

    file.open(path.data(), std::ios::in);
    Row passenger;
    while (file.peek() != EOF) {
        file >> passenger;
        passenger.print();
        std::cout << "___________________________________________________________________________________________\n";
    }
    file.close();
}


void Database::lab_task(const size_t &p1, const size_t &p2) const {
    std::cout << "Find out if there are passengers with luggage,  which consists of items with quantity {p1} = " <<
              p1 << " items with weight greater or equal to {p2} = " << p2 << " [kg]" << std::endl;

    std::cout << "___________________________________________________________________________________________\n";

    std::fstream file;
    file.open(path.data(), std::ios::in);
    Row passenger;
    while (file.peek() != EOF) {
        file >> passenger;
        if (passenger.items_quantity == p1 and passenger.items_weight >= p2) {
            std::cout << passenger.surname << "\t"
            << passenger.initials << "\t has "
            << passenger.items_quantity << " items \t with weight "
            << passenger.items_weight << " [kg]" << std::endl;
            std::cout << "___________________________________________________\n";
        }
    }
    file.close();
}