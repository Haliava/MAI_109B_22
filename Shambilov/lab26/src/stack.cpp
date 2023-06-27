#include "../include/stack.hpp" 
 
template <typename T> 
Stack<T>::Stack() { 
    capacity = 8; 
    data = new T[capacity]; 
    size = 0; 
} 
 
template <typename T> 
int Stack<T>::get_size() const { 
    return size; 
} 
 
template <typename T> 
void Stack<T>::push(T value) { 
    if (size == capacity) { 
        capacity *= 2; 
        T* newdata = new T[capacity]; 
        for (int i = 0; i < size; ++i) { 
            newdata[i] = data[i]; 
        } 
        delete[] data; 
        data = newdata; 
    } 
    data[size] = value; 
    ++size; 
} 
 
template <typename T> 
T Stack<T>::pop() { 
    if (size == 0) { 
        return 0; 
    } 
    char top = data[size-1]; 
    --size; 
    return top; 
} 
 
template <typename T> 
T Stack<T>::top() const { 
    if (size == 0) { 
        return 0; 
    } 
    return data[size-1]; 
} 
 
template <typename T> 
bool Stack<T>::empty() const { 
    return size == 0; 
} 
 
template <typename T> 
void Stack<T>::bubbleSort(Stack<T> &s) { 
    if (s.empty() or s.size() == 1) { 
        return; 
    } 
    bool swapped; 
    T temp; 
    for (T i = 0; i < s.size(); ++i) { 
        swapped = false; 
        for (T j = 0; j < s.size() - i - 1; ++j) { 
            int top = s.top(); 
            s.pop(); 
            if (top > s.top()) { 
                temp = top; 
                top = s.top(); 
                s.pop(); 
                s.push(temp); 
                s.push(top); 
                swapped = true; 
            } 
            else { 
                s.push(top); 
            } 
        } 
        if (!swapped) { 
            break; 
        } 
    } 
}
