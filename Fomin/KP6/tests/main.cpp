#include <iostream>
#include <string>
#include "../include/Database.h"
#include "../include/Row.h"


int main() {
    DataBase database("MyDatabase");

    Row row1("beba", "F", 10, "B", "MAI", "Ya");
    Row row2("biby", "M", 10, "C", "HSE", "Tink");
    Row row3("ooba", "M", 10, "D", "MSU", "Sber");
    Row row4("indo", "M", 10, "D", "Poly", "None");
    Row row5("keke", "F", 11, "A", "MAI", "Tink");
    Row row6("kouka", "F", 11, "A", "AAA", "ss");
    Row row7("kiki", "F", 11, "A", "AAA", "ss");
    Row row8("oozy", "M", 11, "B", "AAA", "ss");
    Row row9("bibo", "M", 11, "B", "AAA", "ss");
    Row row10("koku", "F", 11, "B", "AAA", "ss");

    database.addRow(row1);
    database.addRow(row2);
    database.addRow(row3);
    database.addRow(row4);
    database.addRow(row5);
    database.addRow(row6);
    database.addRow(row7);
    database.addRow(row8);
    database.addRow(row9);
    database.addRow(row10);

    database.print();
    std::string resultFile = database.findClassesWithMoreMthanF("../tests/MtoF.txt");
}