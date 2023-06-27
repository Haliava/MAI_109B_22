#include "../include/database.hpp"
#include <iostream>

int main() {
    Database base;

    Row row1(1, 12, "Adamov", "AAA", "male", 5, 5, 5);
    Row row2(2, 12, "Yusufov", "YRT", "male", 4, 3, 4);
    Row row3(3, 12, "Kontsebalov", "KOM", "male", 4, 5, 4);
    Row row4(4, 12, "Lyubovarsky", "LIA", "male", 4, 5, 5);
    Row row5(5, 12, "Stepanov", "SAA", "male", 5, 5, 5);
    Row row6(6, 12, "Povarova", "PAK", "female", 3, 3, 3);
    Row row7(7, 12, "Hatsunova", "HMM", "female", 2, 3, 3);
    Row row8(8, 12, "Lenin", "LVV", "male", 3, 2, 2);
    base.add_row(row1);
    base.add_row(row2);
    base.add_row(row3);
    base.add_row(row4);
    base.add_row(row5);
    base.add_row(row6);
    base.add_row(row6);
    base.add_row(row6);

    base.print();

    base.print_best_students(4);

    return 0;
}
