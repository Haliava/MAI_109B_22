#include "../include/DB.hpp"
#include <cstdint>
#include <iostream>


int main()
{
    DB test("aaaaa");
    Passenger test1("Alex1", "Stepanov", 11, 10003, "MAI", "10:23 AM", true, 0);
    Passenger testw("Alex", "Stepanov", 12, 12, "MAI", "10:53 AM", true, 0);
    Passenger test2("Alexaa", "Stepanovfvdv_a", 10, 100203, "MAI23", "11:23 PM", false, 0);

    test.addData(test1);
    test.addData(testw);
    test.addData(test2);
    test.print();
    test.find_passengers(1);
    test.find_passengers(12);
    std::cout << std::endl;
    test.find_passengers(0);
    test.print();
    return 0;
}
