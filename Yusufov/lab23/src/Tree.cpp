#include "../include/Tree.hpp"

template <typename T>
Node<T>* Tree<T>::createNode(T data) {
    return new Node<T>(data);
}

template <typename T>
Node<T>* Tree<T>::insertNode(Node<T>* root, T data) {
    if (root == nullptr) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

template <typename T>
void Tree<T>::traversal(Node<T>* root) {
    if (root == nullptr) {
        return;
    }
    traversal(root->left);
    std::cout << root->data << " ";
    traversal(root->right);
}

template <typename T>
Node<T>* Tree<T>::deleteNode(Node<T>* root, T data) {
    if (root == nullptr) {
        return root;
    } else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
            Node<T>* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            Node<T>* temp = root;
            root = root->left;
            delete temp;
        } else {
            Node<T>* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

template <typename T>
Node<T>* Tree<T>::findMin(Node<T>* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

template <typename T>
int Tree<T>::findMaxDepth(Node<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftDepth = findMaxDepth(root->left);
    int rightDepth = findMaxDepth(root->right);
    return std::max(leftDepth, rightDepth) + 1;
}

template <typename T>
T Tree<T>::findMaxDepthLeaf(Node<T>* root, int depth, int& maxDepth, T& maxDepthLeaf) {
    if (root == nullptr) {
        return maxDepthLeaf;
    }
    if (root->left == nullptr && root->right == nullptr) {
        if (depth > maxDepth) {
            maxDepth = depth;
            maxDepthLeaf = root->data;
        }
    }
    T leftLeaf = findMaxDepthLeaf(root->left, depth + 1, maxDepth, maxDepthLeaf);
    T rightLeaf = findMaxDepthLeaf(root->right, depth + 1, maxDepth, maxDepthLeaf);
    return std::max(leftLeaf, rightLeaf);
}

template <typename T>
Tree<T>::Tree() {
    root = nullptr;
}

template <typename T>
void Tree<T>::insert(T data) {
    root = insertNode(root, data);
}

template <typename T>
void Tree<T>::remove(T data) {
    root = deleteNode(root, data);
}

template <typename T>
void Tree<T>::display() {
    traversal(root);
    std::cout << std::endl;
}

template <typename T>
int Tree<T>::getMaxDepth() {
    return findMaxDepth(root);
}

template <typename T>
T Tree<T>::getMaxDepthLeaf() {
    int maxDepth = 0;
    T maxDepthLeaf = 0;
    return findMaxDepthLeaf(root, 0, maxDepth, maxDepthLeaf);
}