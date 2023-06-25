#include "../include/passenger.hpp"

Passenger::Passenger(const std::string &_name, const std::string &_surname, const uint64_t _num_of_items, const uint64_t _total_weith,
                     const std::string &_final_destination, const std::string &_time_of_flight, const bool _availability_of_transfers,
                     const uint64_t _num_of_children) : name(_name), surname(_surname), num_of_items(_num_of_items), total_weith(_total_weith), final_destination(_final_destination), time_of_flight(_time_of_flight),
                                                        availability_of_transfers(_availability_of_transfers), num_of_children(_num_of_children) {}

void Passenger::print() const
{
    std::cout << "| " << std::setw(15) << std::left << name << "| " << std::setw(18) << std::left << surname << "| " << std::setw(16) << std::left << num_of_items << "| " << std::setw(12) << std::left << total_weith
              << "| " << std::setw(12) << std::left << final_destination << "| " << std::setw(15) << std::left << time_of_flight << "| " << std::setw(10) << std::left << availability_of_transfers << "| "
              << std::setw(19) << std::left << num_of_children << "|" << std::endl;
}
