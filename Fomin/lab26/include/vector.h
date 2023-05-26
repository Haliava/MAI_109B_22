#ifndef LAB26_VECTOR_H
#define LAB26_VECTOR_H

#include <cstddef>
#include <initializer_list>

template<typename T>
class Vector {
private:
    T* data;
    std::size_t size;
    std::size_t capacity;

public:
    Vector();
    Vector(const Vector& other);
    //Vector(std::initializer_list<T> initList);
    ~Vector();

    Vector& operator=(const Vector& other);
    void push_back(const T& value);
    T& pop_back();

/*    template<typename... Args>
    void emplace_back(Args... args);*/
    template<typename... Args>
    void emplace_back(const T &First, const Args &...args);
    void emplace_back();

    void reserve(std::size_t newCapacity);
    void resize(std::size_t newSize);

    T& at(std::size_t index);
    T& front();
    T& back();
    T& operator[](std::size_t index);

    bool empty();
    std::size_t getSize();
    std::size_t getCapacity();

    void shrink_to_fit();
    void clear();

    bool operator==(const Vector& other);
    bool operator!=(const Vector& other);
};

#endif //LAB26_VECTOR_H
