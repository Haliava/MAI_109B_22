#ifndef EXPRESSIONTREE_HPP
#define EXPRESSIONTREE_HPP

#include "TreeNode.hpp"
#include <iostream>
#include <string>

#include "../../lab26/include/Deque.hpp"

class ExpressionTree {
private:
    TreeNode *root;

    size_t find_priority(char c) const;
    bool is_operator(char o) const;
    TreeNode* lab_task(TreeNode *curr_node);
public:

    ExpressionTree();
    explicit ExpressionTree(const std::string &expression);
    ~ExpressionTree();
    TreeNode *get_root() const;

    TreeNode *build_tree(const std::string &postfix_notation);
    void delete_branch(const TreeNode *curr_node);
    std::string get_postfix_expr(const std::string &expr);
    void print_postfix_expr(const TreeNode *curr_node) const;
    void print_infix_expr(const TreeNode *curr_node) const;
    void print_tree(const TreeNode *curr_node, const size_t &height = 0) const;
    void lab_task();
};

#include "../src/ExpressionTree.cpp"

#endif