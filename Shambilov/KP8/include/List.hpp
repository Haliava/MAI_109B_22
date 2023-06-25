#ifndef KP8_LIST_HPP
#define KP8_LIST_HPP
#include "../include/Iterator.hpp"
#include "../include/Node.hpp"
#include <iostream>

template<typename T>
class List {
private:
    Node<T>* start;
public:
    List();
    List(const size_t, const T& = T());
    List(const List<T>&);

    std::ostream& operator<<(std::ostream& stream);

    void push_back(const T&);
    void push_front(const T&);
    template<typename... Args>
    void emplace_back(const Args&...);
    template<typename... Args>
    void emplace_front(const Args&...);
    void pop_back();
    void pop_front();
    void insert(const Iterator<T>&, const T& data);
    void erase(const Iterator<T>&, const Iterator<T>&);
    void swapNodes(int k);

    Iterator<T> begin() const;
    Iterator<T> end() const;

    ~List();
};

#include "../src/List.cpp"

#endif //KP8_LIST_HPP
