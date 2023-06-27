#ifndef DEQUE_HPP_INCLUDED
#define DEQUE_HPP_INCLUDED
#include "Iterator.hpp"

template <typename T>
class Deque {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    size_t sz = 0;

    Deque<T> sort(Deque<T> x);
public:
    Deque() = default;

    Iterator<T> begin();
    Iterator<T> end();

    void push_back(const T& value);
    void push_front(const T& value);
    T pop_back();
    T pop_front();
    void clear();
    void concatenate(Deque<T> &x);
    void sort();

    template<typename U>
    friend std::ostream &operator<<(std::ostream &out, Deque<U> &x);

    size_t size() const;
    bool empty() const;

    ~Deque();
    Deque(const Deque<T> &x);
    Deque<T>& operator=(const Deque<T> &x);
};


#include "../src/Deque.cpp"
#endif
