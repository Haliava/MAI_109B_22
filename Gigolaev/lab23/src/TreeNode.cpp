#include "../include/TreeNode.hpp"
template <typename T>
TreeNode<T>::~TreeNode()
{
    for (size_t i = 0; i < children.size(); ++i)
        delete children[i];
}
template <typename T>
void printTree(TreeNode<T>* root, int indent = 0) {
    if (!root) {
        return;
    }
    for (int i = 0; i < indent; i++) {
        std::cout << "  ";
    }
    std::cout << root->val << std::endl;
    for (size_t i = 0; i < root->children.size(); ++i) {
        if (root->children[i] == nullptr)
        {
            continue;
        }
        printTree(root->children[i], indent + 1);
    }

}

template<typename T>
bool find_node(TreeNode<T>* currentRoot, T _val)
{
    static bool isFound = false;
    if (isFound)
        return true;
    if (currentRoot == nullptr) {
        return 0;
    }
    
    if(currentRoot->val == _val)
    {
	isFound = true;
	return true;
    }
    for (size_t i = 0; i < currentRoot->children.size(); ++i) {
        if (currentRoot->children[i]->val == _val)
        {
            isFound = true;
	    return true;
        }
        isFound = find_node(currentRoot->children[i], _val);
    }
    return isFound;
}

template<typename T>
void add_child(TreeNode<T>* parent, TreeNode<T>* child) {
    parent->children.push_back(child);
}

template<typename T>
void delete_node(TreeNode<T>*& node) {
    while (!node->children.empty()) {
        delete_node(node->children[node->children.size() - 1]);
        node->children.pop_back();
    }
    delete node;
    node = nullptr;
    //node->val = -1;
}
template<typename T>
int countNonTerminals(TreeNode<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->children.empty()) {
        return 0;
    }
    int count = 1;
    for (size_t i = 0; i < root->children.size(); ++i) {
        count += countNonTerminals(root->children[i]);
    }
    return count;
}
