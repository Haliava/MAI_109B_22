#include "../include/RowTable.hpp"
#include "../include/DataBase.hpp"
#include <direct.h>
#include <io.h>
#include <iostream>
#include <iomanip>
#include <string>

DataBase::DataBase(const std::string& file_name){
    file_path = createFile(file_name);
    file = fopen(file_path.data(), "wb+");
}

DataBase::~DataBase(){
    if (file != nullptr) fclose(file);
}

std::string make_dir(const std::string& dir_name){
    std::string dir_path = std::string(getenv("USERPROFILE")) + "\\Desktop\\" + dir_name;

    if (access(dir_path.c_str(), 0) != 0){
        mkdir(dir_path.c_str());
    }

    return dir_path;
}

std::string DataBase::createFile(const std::string& file_name){
    std::string path = make_dir("DataBase") + "\\" + file_name + ".bin";
    file = fopen(path.c_str(), "ab+");
    if (!file){
        throw std::runtime_error("Failed to create the file");
    }

    std::string header = "My Data Base";
    fwrite(header.c_str(), header.size(), 1, file);
    fclose(file);

    return path;
}

void DataBase::deleteFile(){
    if (file != nullptr) fclose(file);
    remove(file_path.data());
}

void DataBase::addData(const RowTable& computer){
    if (file == nullptr){
        throw std::runtime_error("File doesn't exist");
    }

    fseek(file, 0, SEEK_END);
    fwrite(&computer, sizeof(computer), 1, file);
}

void DataBase::print() const{
    std::cout << "\n| " << "Owner Surname" << " | " << "Number Processors" << " | " << "Processors Type" << " | " <<
              "Memory Size" << " | " << "Video Controller Type" << " | " << "Video Memory" << " | " <<
              "Hard Driver Type" << " | " << "Number Hard Drivers" << " | " << "Hard Driver Memory" << " | " <<
              "Number Integrated Controllers" << " | " << "Number External Devices" << " | " << "Operating System" << " |\n";
    std::cout << "+---------------+-------------------+-----------------+-------------+-----------------------+" <<
              "--------------+------------------+---------------------+--------------------+-------------------------------+" <<
              "-------------------------+------------------+\n";

    fseek(file, 0, SEEK_SET);
    RowTable computer;

    while (fread(&computer, sizeof(RowTable), 1, file) == 1){
        computer.print();
        std::cout << "+---------------+-------------------+-----------------+-------------+-----------------------+" <<
                  "--------------+------------------+---------------------+--------------------+-------------------------------+" <<
                  "-------------------------+------------------+\n";
    }
}

void DataBase::allStudentPc() const {
    fseek(file, 0, SEEK_END);
    RowTable computer;
    while (fread(&computer, sizeof(RowTable), 1, file) == 1) {
        if (computer.operating_system != "WINTEL") {
            std::cout << "Surname of Student: " << computer.owner_surname << '\n' << "Operaring System of Student: "
            << computer.operating_system << '\n' << "Other" << computer.num_processors <<
            computer.processor_type << computer.memory_sz << computer.video_controller_type <<
            computer.video_memory_sz << computer.hard_driver_type << computer.num_hard_drivers <<
            computer.hard_driver_memory << computer.num_integrated_controllers << computer.num_external_devices;
        }
    }
}