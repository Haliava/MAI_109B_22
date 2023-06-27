#ifndef PASSENGER_HPP_INCLUDED
#define PASSENGER_HPP_INCLUDED
#include "friend_list_declaration.hpp"
#include <iomanip>
#include <iostream>
#include <string>
class Passenger
{
    std::string name = "";
    std::string surname = "";
    uint64_t num_of_items = 0;
    uint64_t total_weith = 0;
    std::string final_destination = "";
    std::string time_of_flight = "";
    bool availability_of_transfers = false;
    uint64_t num_of_children = 0;

public:
    friend class DB;
    Passenger() = default;
    ~Passenger() = default;
    Passenger(const std::string &_name, const std::string &_surname, const uint64_t _num_of_items, const uint64_t _total_weith,
              const std::string &_final_destination, const std::string &_time_of_flight, const bool _availability_of_transfers,
              const uint64_t _num_of_children);
    void print() const;
};

#include "../src/passenger.cpp"
#endif// PASSENGER_HPP_INCLUDED
