#include "../include/Queue.hpp"

template<typename T>
Queue<T>::~Queue()
{
    while (!empty()) {
        pop();
    }
}

template<typename T>
void Queue<T>::push(const T &value)
{
    Node<T> *newNode = new Node(value);
    if (empty()) {
        head = newNode;
        ++size;
    }
    else {
        Node<T> *temp = head;
        head = newNode;
        head->next = temp;
    }
    ++size;
}

template<typename T>
void Queue<T>::pop()
{
    if (size == 1) {
        head = nullptr;
        return;
    }
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    --size;
}

template<typename T>
T &Queue<T>::getFront() const
{
    return head->data;
}

template<typename T>
bool Queue<T>::empty() const
{
    return size == 0;
}

template<typename T>
size_t Queue<T>::getSize() const
{
    return size;
}

template<typename T>
Iterator<T> Queue<T>::begin()
{
    return Iterator<T>(head);
}

template<typename T>
Iterator<T> Queue<T>::end()
{
    Iterator<T> endIt = begin() + (size - 1);
    return endIt;
}

template<typename T>
void Queue<T>::Sort()
{
    for (Iterator<T> minTempIt = begin(); minTempIt.getCurr() != nullptr; ++minTempIt) {
        for (Iterator<T> findIt = minTempIt + 1; findIt.getCurr() != nullptr; ++findIt) {
            if (findIt.getCurr()->data < minTempIt.getCurr()->data) {
                T min_value = findIt.getCurr()->data;
                findIt.getCurr()->data = minTempIt.getCurr()->data;
                minTempIt.getCurr()->data = min_value;
            }
        }
    }
}

template<typename T>
std::ostream &operator<<(std::ostream &out, Queue<T> &q)
{
    if (!q.empty()) {
        Iterator<T> itEnd = q.end();
        for (Iterator<T> i = q.begin(); i != itEnd; ++i) {
            out << *i << ' ';
        }
        out << *itEnd << std::endl;
    }
    return out;
}
