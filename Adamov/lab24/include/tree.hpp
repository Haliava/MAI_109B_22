#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include "../../lab26/include/stack.hpp"
#include <string>

class Tree {
private:
    Node* root;

public:
    Tree();
    Tree(const std::string& expression);

    Node* get_root() const;
    std::string to_postfix(const std::string& expression);
    void print_bypass(Node* root, const size_t height = 0) const;
    void print() const;

    size_t get_levels_number();
    std::string make_new_polynomial(const Tree& g, int (*func)(int, int));
    
    void delete_tree(Node* node);
    ~Tree();
};

#include "../src/tree.cpp"
#endif // TREE_HPP
