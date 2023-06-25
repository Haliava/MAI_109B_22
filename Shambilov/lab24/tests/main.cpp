#include "../include/Stack.hpp"
#include "../include/Stack.hpp"
#include "../include/Node.hpp"
#include "../src/ExpressionTree.cpp"
#include "../src/Stack.cpp"
#include "../src/Node.cpp"
#include <iostream>
#include <string>

int main() {
    std::string expression =  "a*(b-c)";
    ExpressionTree tree(expression);
    tree.printInfix(tree.getRoot());
    std::cout << "\n";
    tree.printPostfix(tree.getRoot());
    std::cout << "\n";
    tree.print(tree.getRoot());
    std::cout << "\n\n\n";
    tree.replace(tree);
    tree.print(tree.getRoot());
    return 0;
}