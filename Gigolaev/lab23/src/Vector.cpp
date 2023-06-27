#include "../include/Vector.hpp"


template <typename T>
Vector<T>::Vector() : dataSize(0), dataSizeMax(0), data(nullptr) {}

template <typename T>
Vector<T>::~Vector() {
    delete[] reinterpret_cast<unsigned char*>(data);
    //delete[] data;
}

template <typename T>
Vector<T>::Vector(const Vector& v) : dataSize(v.dataSize), dataSizeMax(v.dataSizeMax) {
    data = new unsigned char[dataSizeMax * sizeof(T)];
    for (size_t i = 0; i < dataSize; ++i)
        new(data + i * sizeof(T)) T((reinterpret_cast<T*>(v.data))[i]);
}

template <typename T>
Vector<T>::Vector(Vector&& v) {
    dataSize = v.dataSize;
    dataSizeMax = v.dataSizeMax;
    data = v.data;
    v.data = nullptr;
    v.dataSize = 0;
    v.dataSizeMax = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& v) {
    if (this == &v)
        return *this;
    if (data)
        delete[] reinterpret_cast<unsigned char*>(data);
    dataSize = v.dataSize;
    dataSizeMax = v.dataSizeMax;
    data = new unsigned char[dataSizeMax * sizeof(T)];
    for (size_t i = 0; i < dataSize; ++i)
        new(data + i * sizeof(T)) T((reinterpret_cast<T*>(v.data))[i]);
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& v) {
    if (this == &v)
        return *this;
    if (data)
        delete[] reinterpret_cast<unsigned char*>(data);
    dataSize = v.dataSize;
    dataSizeMax = v.dataSizeMax;
    data = v.data;
    v.data = nullptr;
    v.dataSize = 0;
    v.dataSizeMax = 0;
    return *this;
}

template <typename T>
void Vector<T>::reserve(size_t n) {
    if (n > dataSizeMax) {
        unsigned char* temp = new unsigned char[n * sizeof(T)];
        for (size_t i = 0; i < dataSize; ++i)
            new(temp + i * sizeof(T)) T((reinterpret_cast<T*>(data))[i]);
        if(data)
            delete[] reinterpret_cast<unsigned char*>(data);
        data = temp;
        dataSizeMax = n;
    }
}

template <typename T>
void Vector<T>::resize(size_t n) {
    if (n > dataSizeMax)
        reserve(n);
    for (size_t i = dataSize; i < n; ++i)
        new(data + i * sizeof(T)) T();
    for (size_t i = n; i < dataSize; ++i)
        (reinterpret_cast<T*>(data))[i].~T();
    dataSize = n;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (dataSize == dataSizeMax)
        reserve(dataSizeMax ? dataSizeMax * 2 : 1);
    new(data + dataSize * sizeof(T)) T(value);
    ++dataSize;
}

template <typename T>
void Vector<T>::push_back(T&& value) {
    if (dataSize == dataSizeMax)
        reserve(dataSizeMax ? dataSizeMax * 2 : 1);
    new(data + dataSize * sizeof(T)) T(std::move(value));
    ++dataSize;
}

template <typename T>
void Vector<T>::pop_back() {
    if (dataSize) {
        (reinterpret_cast<T*>(data))[dataSize - 1].~T();
        --dataSize;
    }
}

template <typename T>
T& Vector<T>::operator[](size_t i) {
    return (reinterpret_cast<T*>(data))[i];
}

template <typename T>
const T& Vector<T>::operator[](size_t i) const {
    return (reinterpret_cast<const T*>(data))[i];
}

template <typename T>
size_t Vector<T>::size() const {
    return dataSize;
}

template <typename T>
bool Vector<T>::empty() const {
    return dataSize == 0;
}

template <typename T>
void Vector<T>::clear() {
    for (size_t i = 0; i < dataSize; ++i)
        (reinterpret_cast<T*>(data))[i].~T();
    dataSize = 0;
}

