#include <iostream>
#include "../include/BinTree.hpp"

int main() {
    BinTree<int> tree(40);
    bool result;

    tree.insert(15, tree.get_root());
    tree.insert(6, tree.get_root());
    tree.insert(20, tree.get_root());
    tree.insert(50, tree.get_root());
    tree.insert(45, tree.get_root());
    tree.insert(55, tree.get_root());

    result = tree.task(5, 60);
    std::cout << result << '\n';
}