#include "../include/Node.hpp"
#include "../include/Tree.hpp"
#include <cstdint>
#include <iostream>


int main()
{ std::string expr = "2*0+4/1+2";
    ExpressionTree tree(expr);

    tree.print_infix_form(tree.get_root());
    std::cout << "\n";
    tree.print_postfix_form(tree.get_root());
    std::cout << "\n";
    tree.print_tree(tree.get_root());
    std::cout << "\n\n\n";
    tree.lab_task(tree.get_root());
    tree.print_infix_form(tree.get_root());
    std::cout << "\n";
    tree.print_postfix_form(tree.get_root());
    std::cout << "\n";
    tree.print_tree(tree.get_root());
    std::cout << "\n\n\n";
    expr = "0*(a*2)+(1^t)*0^9*(1*1*1)*o/1+1";
    std::cout<<expr<<std::endl;
    ExpressionTree tree2(expr);
    tree2.print_infix_form(tree2.get_root());
    std::cout << "\n";
    tree2.print_postfix_form(tree2.get_root());
    std::cout << "\n";
    tree2.print_tree(tree2.get_root());
    std::cout << "\n\n\n";
    tree2.lab_task(tree2.get_root());
    tree2.print_infix_form(tree2.get_root());
    std::cout << "\n";
    tree2.print_postfix_form(tree2.get_root());
    std::cout << "\n";
    tree2.print_tree(tree2.get_root());
    std::cout << "\n\n\n";
    return 0;
}