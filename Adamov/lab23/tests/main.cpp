#include "../include/Tree.hpp"
#include <iostream>

// 4. Определить значение листа дваичного дерева, имеющего минимальную глубину

int main() {
    {
        Tree<int> tree(5);
        tree.insert(11);
        tree.insert(2);
        tree.insert(1);
        tree.insert(9);
        tree.insert(8);
        tree.insert(12);
        tree.print_tree();
        Node<int>* minimal = tree.get_min_depth_node();
        std::cout << "Answer: " << minimal->get_data() << "\n\n";
    }
    {
        Tree<int> tree(15);
        tree.insert(10);
        tree.insert(12);
        tree.insert(14);
        tree.insert(8);
        tree.insert(4);
        tree.insert(9);
        tree.insert(18);
        tree.print_tree();
        Node<int>* minimal = tree.get_min_depth_node();
        std::cout << "Answer: " << minimal->get_data() << "\n\n";
    }
    {
        Tree<int> tree(4);
        tree.insert(3);
        tree.insert(2);
        tree.insert(1);
        tree.insert(8);
        tree.insert(7);
        tree.insert(9);
        tree.insert(6);
        tree.print_tree();
        Node<int>* minimal = tree.get_min_depth_node();
        std::cout << "Answer: " << minimal->get_data() << '\n';
    }
}
