#include <iostream>
#include "../include/List.h"
#include "../src/Node.cpp"

template<typename T>
void List<T>::addNode(const T& value) {
    auto newNode = new Node<T>(value);
    this->size++;

    if (this->head == nullptr) {
        this->head = newNode;
        this->head->data = newNode->data;
        this->head->next = newNode;
        return;
    }

    Node<T>* last = this->head;
    while (last->next != this->head)
        last = last->next;

    last->next = newNode;
    newNode->next = this->head;
}

/** deletes first encountered Node with given value */
template<typename T>
void List<T>::deleteNode(const T& value) {
    bool hasFoundVal = false;
    Node<T>* currentParent;
    Node<T>* current = this->head;

    if (current->data == value) {
        // if the deleted Node is the head of the List we need to change links in more places than usual
        this->head = current->next;

        current = current->next;
        while (current->next != this->head) {
            currentParent = current;
            current = current->next;
        }

        currentParent->next = this->head;
    } else {
        while (current->data != value) {
            currentParent = current;
            current = current->next;
            hasFoundVal = true;
        }

        if (!hasFoundVal) return;

        currentParent->next = current->next;
        current->next = nullptr;
    }

    delete current;
    this->size--;
}

template<typename T>
void List<T>::popNode() {
    if (this->size <= 1) {
        this->head = nullptr;
        this->size = 0;
    }

    Node<T>* current = this->head;
    while (current->next->next != this->head) {
        current = current->next;
    }

    Node<T>* deletedNode = current->next;
    current->next = current->next->next;
    deletedNode->next = nullptr;
    delete deletedNode;
}

template<typename T>
T List<T>::getSize() {
    return this->size;
}

template<typename T>
void List<T>::print() {
    if (this->head == nullptr)
        return;

    Node<T>* current = this->head;

    std::cout << current->data << " ";
    current = current->next;
    while (current != this->head) {
        std::cout << current->data << " ";
        current = current->next;
    }
}

/** Deletes all Nodes with values that differ by 1 from the given value */
template<typename T>
void List<T>::deleteAllPrevAndNextToValue(const T &value) {
    if (this->size <= 1) {
        this->head = nullptr;
        this->size = 0;
        return;
    }

    Node<T>* current = this->head;
    Node<T>* tail = this->head;
    while (tail->next != this->head)
        tail = tail->next;

    if (abs(this->head->data - value) == 1) {
        this->head = current->next;
        current = current->next;
    }
    tail->next = this->head;

    while (current->next != this->head) {
        if (abs(current->next->data - value) == 1) {
            deleteNode(current->next->data);
        }

        current = current->next;
    }
}

template<typename T>
List<T>::List(): size(0), head(nullptr) {
}
