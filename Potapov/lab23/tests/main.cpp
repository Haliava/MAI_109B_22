#include <iostream>
#include "../include/BinaryTree.hpp"

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    int cnt = 0;
    tree.print();
    tree.get_leaf_count(cnt, tree.root);
    std::cout << "Leaf count: " << cnt << std::endl;
    tree.remove(5);

    cnt = 0;
    std::cout << 123 << std::endl;
    tree.get_leaf_count(cnt, tree.root);
    std::cout << "Leaf count: " << cnt << std::endl;
    tree.print();
    tree.remove(8);
    tree.print();

    cnt = 0;
    tree.get_leaf_count(cnt, tree.root);
    std::cout << "Leaf count: " << cnt << std::endl;

    return 0;
}
