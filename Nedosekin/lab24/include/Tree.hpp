#ifndef TREE_HPP
#define TREE_HPP
#include "../../KP7/include/Vector.hpp"
#include "Node.hpp"
class ExpressionTree
{
    Node *root = nullptr;

public:
    ExpressionTree() = default;
    ~ExpressionTree();
    ExpressionTree(const std::string &expression);
    Node *get_root() const;
    void delete_branch(Node *node);
    Node *create_branch(const std::string &postfix);
    std::string to_postfix_form(const std::string &expression);
    void lab_task(Node *node);
    void print_postfix_form(Node *root) const;
    void print_infix_form(Node *root) const;
    void print_tree(Node *node, const size_t height = 0) const;
};

#include "../src/Tree.cpp"
#endif//TREE_HPP