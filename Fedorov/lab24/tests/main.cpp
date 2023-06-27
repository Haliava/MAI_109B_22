#include <iostream>
#include "../include/ExpressionTree.hpp"


int main() {
    std::string e1 = "((x+8)^4+8)+8";
    ExpressionTree tree(e1);

    std::cout << "Infix notation: ";
    tree.print_infix_expr(tree.get_root());
    std::cout << std::endl;

    std::cout << "Postfix notation: ";
    tree.print_postfix_expr(tree.get_root());
    std::cout << std::endl;

    std::cout << "Expression tree: " << std::endl;
    tree.print_tree(tree.get_root());
    std::cout << std::endl;

    std::cout << "Lab task (reducing expression with the help of"
              << " replacement power operation to multiplication operation): " << std::endl;
    tree.lab_task();

    std::cout << "Infix notation: ";
    tree.print_infix_expr(tree.get_root());
    std::cout << std::endl;

    std::cout << "Expression tree: " << std::endl;
    tree.print_tree(tree.get_root());
}
