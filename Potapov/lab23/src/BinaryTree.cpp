#include "../include/BinaryTree.hpp"

void BinaryTree::insert(int data) {
    this->root = insertHelper(root, data);
}

Node* BinaryTree::insertHelper(Node* node, int data) {
    if (node == NULL) {
        node = new Node(data);
    } else if (data <= node -> data) {
        node -> left = insertHelper(node -> left, data);
    } else {
        node -> right = insertHelper(node -> right, data);
    }
    return node;
}

void BinaryTree::print() {
    std::cout << "Binary Tree: " << std::endl;
    printHelper(root, "");
    std::cout << std::endl;
}

void BinaryTree::printHelper(Node* node, std::string indent) {
    if (node == NULL) {
        return;
    }
    printHelper(node -> right, indent + "\t");
    std::cout << indent << node -> data << std::endl;
    printHelper(node -> left, indent + "\t");
}

void BinaryTree::remove(int data) {
    root = removeHelper(root, data);
}

Node* BinaryTree::removeHelper(Node* node, int data) {
    if (node == NULL) {
        return NULL;
    } else if (data < node -> data) {
        node -> left = removeHelper(node -> left, data);
    } else if (data > node -> data) {
        node -> right = removeHelper(node -> right, data);
    } else {
        if (node -> left == NULL && node -> right == NULL) {
            delete node;
            node = NULL;
        } else if (node -> left == NULL) {
            Node* temp = node;
            node = node -> right;
            delete temp;
        } else if (node -> right == NULL) {
            Node* temp = node;
            node = node -> left;
            delete temp;
        } else {
            Node* temp = findMin(node -> right);
            node -> data = temp -> data;
            node -> right = removeHelper(node -> right, temp -> data);
        }
    }
    return node;
}

Node* BinaryTree::findMin(Node* node) {
    while (node -> left != NULL) {
        node = node -> left;
    }
    return node;
}

void BinaryTree::get_leaf_count(int & count, Node* node) {
    if (node == nullptr) {
        return;
    }
    if (node -> left == nullptr && node -> right == nullptr) {
        count++;
        return;
    }
    if (node -> left != nullptr) {
        get_leaf_count(count, node -> left);
    }
    if (node -> right != nullptr) {
        get_leaf_count(count, node -> right);
    }
}
