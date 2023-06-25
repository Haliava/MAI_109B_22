#include <iostream>
#include "../src/stack.cpp"

void rearrangeAndPrint(Stack<int> stack) {
    stack.rearrangeStack();

    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
}

int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(4);
    stack.push(3);
    stack.push(5);
    stack.push(6);

    std::cout << "1: ";
    rearrangeAndPrint(stack);
    stack.clear();

    // 4 56 66 74 55
    stack.push(4);
    stack.push(56);
    stack.push(66);
    stack.push(74);
    stack.push(55);

    std::cout << "\n2: ";
    rearrangeAndPrint(stack);
    stack.clear();

    std::cout << "\n3: ";
    rearrangeAndPrint(stack);

    std::cout << "\n3.1: ";
    stack.push(1);
    rearrangeAndPrint(stack);
    stack.clear();

    stack.push(2);
    stack.push(1);
    std::cout << "\n4: ";
    rearrangeAndPrint(stack);
    stack.clear();

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    std::cout << "\n5: ";
    rearrangeAndPrint(stack);
    stack.clear();

    stack.push(1);
    stack.push(1);
    stack.push(1);
    stack.push(1);
    stack.push(1);
    std::cout << "\n6: ";
    rearrangeAndPrint(stack);
    stack.clear();

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(5);
    stack.push(0);
    std::cout << "\n7: ";
    rearrangeAndPrint(stack);

    return 0;
}