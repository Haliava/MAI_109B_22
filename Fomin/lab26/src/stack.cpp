#include "../include/stack.h"

template<typename T>
Stack<T>::Stack() {
}

template<typename T>
void Stack<T>::push(const T &value) {
    stack.push_back(value);
}

template<typename T>
T &Stack<T>::pop() {
    return stack.pop_back();
}

template<typename T>
const T &Stack<T>::top() {
    if (!stack.empty()) {
        return stack.back();
    }
}

template<typename T>
bool Stack<T>::empty() {
    return stack.empty();
}

template<typename T>
std::size_t Stack<T>::size() {
    return stack.size();
}

template<typename T>
void Stack<T>::rearrangeStack() {
    if (this->empty()) {
        return;
    }

    // for 1 2 4 3 5 6
    Stack<T> tempStack;
    tempStack.push(this->top()); // 6, stack: 1 2 4 3 5, tstack: 6
    this->pop();

    while (!this->empty()) {
        T currentElement = this->top(); // 5, stack: 1 2 4 3, tstack: 6 --- iteration 1
                                        // 6, stack: 1 2 4 3, tstack: 5 --- iteration 2
                                        // 3, stack: 1 2 4, tstack: 5 6 --- iteration 3
                                        // 5, stack: 1 2 4 6, tstack: 3 --- iteration 4
                                        // 6, stack: 1 2 4, tstack: 3 5 --- iteration 5
                                        // 4, stack: 1 2, tstack: 3 5 6 --- iteration 6
        this->pop();

        if (currentElement >= tempStack.top()) { // 5 >= 6?, stack: 1 2 4 3, tstack: 6 --- iteration 1
                                                 // 6 >= 5?, stack: 1 2 4 3, tstack: 5 6 --- iteration 2
                                                 // 3 >= 6?, stack: 1 2 4 3, tstack: 5 6 --- iteration 3
                                                 // 5 >= 3?, stack: 1 2 4 6, tstack: 3 5 --- iteration 4
                                                 // 6 >= 3?, stack: 1 2 4, tstack: 3 5 6 --- iteration 5
                                                 // 4 >= 6?, stack: 1 2, tstack: 3 5 6 --- iteration 6
            tempStack.push(currentElement);
            continue;
        }

        while (!tempStack.empty()) { // stack: 1 2 4 3, tstack: 6 --- iteration 1
                                     // stack: 1 2 4, tstack: 5 6 --- iteration 3
                                     // stack: 1 2, tstack: 3 5 6 --- iteration 6

            this->push(tempStack.top()); // stack: 1 2 4 3 6, tstack: - --- iteration 1
                                              // stack: 1 2 4 6 5, tstack: - --- iteration 3
                                              // stack: 1 2 6 5 3, tstack: - --- iteration 6
            tempStack.pop();
        }

        tempStack.push(currentElement); // 5, stack: 1 2 4 3 6, tstack: 5 --- iteration 1
                                             // 3, stack: 1 2 4 6 5, tstack: 3 --- iteration 3
                                             // 4, stack: 1 2 6 5 3, tstack: 4 --- iteration 6
    }

    // stack: -, tstack: 6 5 4 3 2 1
    while (!tempStack.empty()) {
        this->push(tempStack.top());
        tempStack.pop();
    }
    // stack 1 2 3 4 5 6, tstack: -
}

template<typename T>
void Stack<T>::clear() {
    this->stack.clear();
}


