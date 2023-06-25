#include "../include/Table.hpp"

template<typename T>
void Table<T>::insertInfo(const T &key, const std::string &input_data) {
    keys.push_back(key);
    lines.push_back(input_data);
}

template<typename T>
void Table<T>::sort() {
    if (lines.empty()) {
        return;
    }
    if (lines.get_size() != keys.size()) {
        throw std::range_error("No one key founded");
    }

    myVector<size_t> indexes;
    indexes.push_back(0);
    indexes.push_back(lines.get_size() - 1);

    while (!indexes.empty()) {
        size_t end = indexes.back();
        indexes.pop_back();
        size_t start = indexes.back();
        indexes.pop_back();

        size_t pinIndex = partition(start, end);

        if (pinIndex - 1 > start) {
            indexes.push_back(start);
            indexes.push_back(pinIndex - 1);
        }

        if (pinIndex + 1 < end) {
            indexes.push_back(pinIndex + 1);
            indexes.push_back(end);
        }
    }
}

template<typename T>
size_t Table<T>::partition(size_t start, size_t end) {
    T pin = keys[end];

    if (start == 0) {
        throw std::range_error("Size_t cant be -");
    }

    size_t i = start - 1;

    for (size_t j = start; j <= end - 1; ++j) {
        if (keys[j] <= pin) {
            ++i;
            std::swap(keys[i], keys[j]);
            std::swap(lines[i], lines[j]);
        }
    }

    std::swap(keys[i + 1], keys[end]);
    std::swap(lines[i + 1], lines[end]);

    return i + 1;
}

template<typename T>
std::string Table<T>::binarySearch(const T &key) {
    sort();
    size_t left = 0, right = keys.size();
    while (left < right) {
        size_t mid = (left + right) / 2;
        if (keys[mid] < key) {
            left = mid + 1;
        }
        else if (keys[mid] > key) {
            right = mid;
        }
        else {
            return lines[mid];
        }
    }
    if (keys[left] == key) {
        return lines[left];
    }
    return "";
}

template<typename T>
std::ostream &operator<<(std::ostream &out, Table<T> &x) {
    for (size_t y = 0; y < x.keys.size(); ++y) {
        out << x.keys[y] << " " << x.lines[y] << '\n';
    }
    out << '\n';
    return out;
}

template<typename T>
std::istream &operator>>(std::istream &in, Table<T> &x) {
    int64_t number_for_range = 0;
    in >> number_for_range;

    for (int64_t y = 0; y < number_for_range; ++y) {
        T in_key;
        std::string in_data;
        in >> in_key >> in_data;
        x.insert(in_key, in_data);
    }
    return in;
}
