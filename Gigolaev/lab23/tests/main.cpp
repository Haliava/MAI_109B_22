#include <iostream>
#include "../include/Vector.hpp"
#include "../include/TreeNode.hpp"
///Example

int main() {
    TreeNode<int>* root = new TreeNode<int>(1);
    root->children.push_back(new TreeNode<int>(2));
    std::cout << find_node(root, 2) << std::endl;
    TreeNode<int>* node = new TreeNode<int>(3);
    add_child(root->children[0], node);
    add_child(node, new TreeNode<int>(8));
    add_child(root->children[0], new TreeNode<int>(4));
    root->children.push_back(new TreeNode<int>(5));
    root->children[1]->children.push_back(new TreeNode<int>(6));
    delete_node(root->children[1]);
    printTree(root);
    std::cout << countNonTerminals(root);
    delete root;
    return 0;    
}
