#ifndef KP9_TABLE_HPP
#define KP9_TABLE_HPP
#include "../../KP7/include/MyVector.hpp"

template<typename T>
class Table {
private:
    myVector<T> keys;
    myVector<std::string> lines;

public:

    Table() = default;
    ~Table() = default;

    size_t partition(size_t start, size_t end);
    void insertInfo(const T &key, const std::string &input_data);
    std::string binarySearch(const T &key);
    void sort();

    template<typename U>
    friend std::ostream &operator<<(std::ostream &out, Table<U> &line);
    template<typename U>
    friend std::istream &operator>>(std::istream &in, Table<U> &line);
};

#include "../src/Table.cpp"

#endif //KP9_TABLE_HPP
