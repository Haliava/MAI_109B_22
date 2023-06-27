#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"
#include "iterator.hpp"
#include <ostream>

template<typename T>
class List {
private:
    Node<T>* head = nullptr;
    size_t sz = 0;

public:
    List() = default;
    List(const List<T>& other);

    Iterator<T> begin();
    Iterator<T> end();

    void push_back(const T& data);
    void push_front(const T& data);
    template<typename ...Args>
    void emplace_back(const T& first, const Args&... args);
    template<typename ...Args>
    void emplace_front(const T& first, const Args&... args);
    void pop_back();
    void pop_front();
    void insert(const Iterator<T>& pos, const T& data);
    void erase(const Iterator<T>& begin_pos, const Iterator<T>& end_pos);
    bool empty();
    void clear();
    
    bool check_order();

    std::ostream& operator<<(std::ostream& out);

    ~List();
};

#include "../src/list.cpp"
#endif // LIST_HPP
