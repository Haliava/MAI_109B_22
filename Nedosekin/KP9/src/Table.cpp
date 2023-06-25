#include "../include/Table.hpp"

template<typename T>
void Table<T>::push_back(const T &key, const std::string &data)
{
    lines.push_back(Line<T>(key, data));
}

template<typename T>
std::ostream &operator<<(std::ostream &out, Table<T> &table)
{
    for (size_t i = 0; i < table.lines.size(); ++i) {
        out << table.lines[i].get_key() << '\t' << table.lines[i].get_value() << std::endl;
    }

    return out;
}

template <typename T>
void Table<T>::swap(size_t index1, size_t index2) {
    Line<T> temp;
    temp = lines[index2];
    lines[index2] = lines[index1];
    lines[index1] = temp;
}

template<typename T>
void Table<T>::sort()
{
    Vector<size_t> count(lines.size());
    Table<long double> result;
    for (size_t i = 0 ; i < lines.size() ; ++i) {
        for (size_t j = i + 1; j < lines.size() ; ++j) {
            if (lines[i].get_key() >= lines[j].get_key()) {
                ++count[i];
            }
            else {
                ++count[j];
            }
            result.push_back(0.0, " ");
        }
        result.lines[i] = lines[i];
    }
    
    for(size_t i = 0 ; i < lines.size() ; ++i) {
        lines[count[i]] = result.lines[i];
    }
}

template<typename T>
Line<T> Table<T>::search(const T &key)
{
    size_t left = 0;
    size_t right = 0;
    right = lines.size();

    while (left <= right) {
        size_t m = left + (right - left) / 2;

        if (lines[m].get_key() == key) {
            return lines[m];
        }

        if (lines[m].get_key() < key) {
            left = m + 1;
        }
        else {
            right = m - 1;
        }
    }

    return Line<T>(key, "\0");
}