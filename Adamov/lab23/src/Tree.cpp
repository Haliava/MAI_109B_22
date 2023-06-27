#include "../include/Tree.hpp"
#include <iostream>
#include <cstddef>

template<typename T>
Tree<T>::Tree(const T& data) {
    this->root = new Node<T>(data);
}

template<typename T>
Node<T>* Tree<T>::get_root() {
    return this->root;
}

template<typename T>
void Tree<T>::insert(const T& new_data) {
    root->insert(root, new_data);
}

template<typename T>
void Tree<T>::delete_node(const T& data) {
    root->delete_node(root, data);
}

template<typename T>
void Tree<T>::print_tree() const {
    root->print_tree(root, 0);
}

template<typename T>
Node<T>* Tree<T>::get_min_depth_node() const {
    return root->get_min_depth_node(root);
}

template<typename T>
void Tree<T>::delete_tree(Node<T>* node) {
    if (node == nullptr) {
        return;
    }
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

template<typename T>
Tree<T>::~Tree() {
    delete_tree(this->root);
}
