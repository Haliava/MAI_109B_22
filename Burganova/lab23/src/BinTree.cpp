#include "../include/BinTree.hpp"
#include "../include/Node.hpp"

template <typename T>
BinTree<T>::BinTree(const T& data) {
    root = new Node<T>(data);
}

template <typename T>
void BinTree<T>::insert(const T& data, Node<T>* node) {
    if (data < node->get_data()) {
        if (node->get_left_node() == nullptr) {
            node->set_left_node(new Node<T>(data));
        } else {
            insert(data, node->get_left_node());
        }
    }
    if (data > node->get_data()) {
        if (node->get_right_node() == nullptr) {
            node->set_right_node(new Node<T>(data));
        } else {
            insert(data, node->get_right_node());
        }
    }
    return;
}

template <typename T>
void BinTree<T>::clear(Node<T>* node) {
    if (node == nullptr) {
        return;
    }

    clear(node->get_left_node()); 
    clear(node->get_right_node());
    delete node;
    node = nullptr;
}

template <typename T>
BinTree<T>::~BinTree() {
    clear(root);
}

template <typename T>
Node<T>* BinTree<T>::get_root() const {
    return root;
}

template <typename T>
void BinTree<T>::bypass(Node<T>* node, int begin, int end, bool& flag) const {
    if (node == nullptr) {
        return;
    }

    bypass(node->get_left_node(), begin, end, flag);
    if ((node->get_left_node() == nullptr)&& (node->get_right_node() == nullptr) && !((begin <= node->get_data()) && (node->get_data() <= end))) {
        flag = false;
    }
    bypass(node->get_right_node(), begin, end, flag);
}

template <typename T>
bool BinTree<T>::task(int begin, int end) const {
    bool flag = true;
    bypass(root, begin, end, flag);
    if (flag) {
        return true;
    } else {
        return false;
    }
}
