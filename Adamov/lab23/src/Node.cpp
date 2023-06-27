#include "../include/Node.hpp"
#include <cstddef>
#include <cstdint>

template<typename T>
Node<T>::Node(const T &data) {
    this->data = data;
}

template<typename T>
Node<T>::Node(const T &data, Node<T>* left, Node<T>* right) {
    this->data = data;
    this->left = left;
    this->right = right;
}

template<typename T>
T Node<T>::get_data() const {
    return this->data;
}

template<typename T>
void Node<T>::print_tree(Node<T>* node, size_t depth) const {
    if (node == nullptr) {
        return;
    }
    print_tree(node->left, depth + 1);
    for (size_t cur_depth = 0; cur_depth < depth; ++cur_depth) {
        std::cout << '\t';
    }
    std::cout << node->get_data() << '\n';
    print_tree(node->right, depth + 1);
}

template<typename T>
void Node<T>::insert(Node<T>* pred, const T& new_data) {
    if (pred == nullptr) {
        return;
    }
    if (pred->data > new_data) {
        if (pred->left == nullptr) {
            pred->left = new Node<T>(new_data);
        } else {
            insert(pred->left, new_data);
        }
    }
    else if (pred->data <= new_data) {
        if (pred->right == nullptr) {
            pred->right = new Node<T>(new_data);
        } else {
            insert(pred->right, new_data);
        }
    }
}

template<typename T>
Node<T>* Node<T>::get_min_node(Node<T>* node) const {
    Node<T>* min_node = node;
    while (min_node->left != nullptr) {
        min_node = min_node->left;
    }
    return min_node;
}

template<typename T>
Node<T>* Node<T>::delete_node(Node<T>* node, const T& data) {
    if (node == nullptr) {
        return node;
    }
    else if (data < node->data) {
        node->left = delete_node(node->left, data);
    }
    else if (data > node->data) {
        node->right = delete_node(node->right, data);
    }
    else {
        if (node->left == nullptr and node->right == nullptr) {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr) {
            Node<T>* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node<T>* temp = node->left;
            delete node;
            return temp;
        }
        Node<T>* temp = get_min_node(node->right);
        node->data = temp->data;
        node->right = delete_node(node->right, temp->data);
    }
    return node;
}

template<typename T>
Node<T>* Node<T>::get_min_depth_node(Node<T>* root) {
    if (root == nullptr) {
        return root;
    }
    else if (root->left == nullptr and root->right == nullptr) {
        return root;
    }
    else { 
        return this->bypass_min_depth_node(root, 0, nullptr, SIZE_MAX);
    }
}

template<typename T>
Node<T>* Node<T>::bypass_min_depth_node(Node<T>* node, size_t depth, Node<T>* min_depth_node, size_t min_depth) {
    if (node == nullptr) {
        return min_depth_node;
    }
    min_depth_node = bypass_min_depth_node(node->left, depth + 1, min_depth_node, min_depth);
    if (node->left == nullptr and node->right == nullptr) {
        if (min_depth_node == nullptr) {
            min_depth_node = node;
        }
        else if (depth < min_depth and depth != 0) {
            min_depth_node = node;
            min_depth = depth;
        }
    }
    min_depth_node = bypass_min_depth_node(node->right, depth + 1, min_depth_node, min_depth);
    return min_depth_node;
}
