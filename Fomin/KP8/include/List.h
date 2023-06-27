//
// Created by La Cretura on 24.06.2023.
//

#ifndef KP8_LIST_H
#define KP8_LIST_H

#include "Node.h"

template<typename T>
class List {
    Node<T>* head;
    T size;

public:
    List();
    void print();

    void addNode(const T& value);
    void deleteNode(const T& value);
    void popNode();
    T getSize();
    void deleteAllPrevAndNextToValue(const T& value);
};

#endif //KP8_LIST_H
