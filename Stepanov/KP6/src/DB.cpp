#include "../include/DB.hpp"
DB::DB(const std::string &db_name)
{
    path_to_file = createDB(db_name);
    file = fopen(path_to_file.data(), "wb+");
}
std::string make_dir(const std::string &dir_name)
{
    std::string dir_path = std::string(getenv("USERPROFILE")) + "\\Desktop\\" + dir_name;

    if (access(dir_path.c_str(), 0) != 0) {
        mkdir(dir_path.c_str());
    }

    return dir_path;
}
std::string DB::createDB(const std::string &db_name)
{
    std::string path = make_dir("DB") + "\\" + db_name + ".bin";
    file = fopen(path.c_str(), "ab+");
    if (!file) {
        throw std::runtime_error("Failed to create the file");
    }
    fclose(file);

    return path;
}
DB::~DB()
{
    if (file != nullptr) fclose(file);
}
void DB::deleteDB()
{
    if (file != nullptr) fclose(file);
    remove(path_to_file.data());
}
void DB::addData(const Passenger &new_pas)
{
    if (file == nullptr) {
        throw std::runtime_error("Table doesn't exist");
    }

    fseek(file, 0, SEEK_END);
    fwrite(&new_pas, sizeof(new_pas), 1, file);
}
void DB::print() const
{
    std::cout << std::endl;
    fseek(file, 0, SEEK_END);
    std::cout << "| Passenger Name"
              << " | "
              << "Passenger Surname"
              << " | "
              << "Number of items"
              << " | "
              << "Total weith"
              << " | "
              << "Destination"
              << " | "
              << "Time of flight"
              << " | "
              << "Transfers"
              << " | "
              << "number of children"
              << " |" << std::endl;
    std::cout << "|________________|___________________|_________________|_____________|_____________|________________|___________|____________________|" << std::endl;
    fseek(file, 0, SEEK_SET);
    Passenger pas;

    while (fread(&pas, sizeof(Passenger), 1, file) == 1) {
        pas.print();
        std::cout << "|________________|___________________|_________________|_____________|_____________|________________|___________|____________________|" << std::endl;
    }
}
void DB::find_passengers(const uint64_t &num_of_addition_items) const
{
    fseek(file, 0, SEEK_SET);
    Passenger pas;
    uint64_t counter = 0, items_averenge = 0;
    while (fread(&pas, sizeof(Passenger), 1, file) == 1) {
        ++counter;
        items_averenge += pas.num_of_items;
    }
    items_averenge /= counter;
    fseek(file, 0, SEEK_SET);
    counter = 0;
    std::cout << "All passengers whose number of items exceeds the average by " << num_of_addition_items << std::endl;
    while (fread(&pas, sizeof(Passenger), 1, file) == 1) {
        ++counter;
        if (pas.num_of_items >= items_averenge && pas.num_of_items - items_averenge >= num_of_addition_items) {
            std::cout << counter << " " << pas.name << " " << pas.surname << std::endl;
        }
    }
}
