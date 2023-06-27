#ifndef LIST_HPP
#define LIST_HPP

#include <stdexcept>
#include <iostream>
#include <initializer_list>

template <typename T>
class List {
private:
    class Node {
    public:
        Node* next;
        T value;
    };

    Node head;
    size_t size;

public:
    List();
    List(const std::initializer_list<T>& init_list);

    size_t get_size();
    bool empty();
    bool is_sorted();
    void push_left(const T& value);
    void print();
    void merge_sort();
    Node* merge_sort(Node* n);
    Node* get_middle(Node* n);
    Node* merge(Node* a, Node* b);

    List(const List&) = delete;
    List& operator=(const List&) const = delete;
    ~List();

};


#include "../src/List.cpp"

#endif