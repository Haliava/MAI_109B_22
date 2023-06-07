#include <iostream>
#include "../include/Tree.h"

template<typename T>
Tree<T>::Tree(const T& rootVal) {
    this->root = new Node<T>(rootVal);
}

template<typename T>
Tree<T>::Tree(Node<T>* root) {
    this->root = root;
}

template<typename T>
Node<T> *Tree<T>::getRoot() {
    return root;
}

template<typename T>
void Tree<T>::addNode(const T &val) {
    Node<T>* current = this->root;

    while (current) {
        if (val < current->val) {
            if (!current->left) {
                current->left = new Node<T>(val);
                break;
            }
            current = current->left;
        }
        else if (val > current->val) {
            // val > current->val
            if (!current->right) {
                current->right = new Node<T>(val);
                break;
            }
            current = current->right;
        }
        else {
            return;
        }
    }
}

/*
* Algorithm goes as:
* 1. Node has no children. Then we just delete Node parent's link to that node.
* 2. Node has one child. Then we replace Node with its child.
* 3. Node has both children. Then we go once to the right and then max to the left.
	 Then we replace Node's value with our max left child's value.
*/
template<typename T>
void Tree<T>::deleteNode(const T& val) {
    Node<T>* parent;
    Node<T>* current = this->root;

    while (current) {

        if (val == current->val) {
            // returns to avoid excess nesting
            if (!current->left && !current->right) {
                if (val >= parent->val) parent->right = nullptr;
                else parent->left = nullptr;
                return;
            }

            if (current->left && !current->right) {
                if (val > parent->val) parent->right = current->left;
                else parent->left = current->left;
                return;
            }

            if (!current->left && current->right) {
                if (val > parent->val) parent->right = current->right;
                else parent->left = current->right;
                return;
            }

            Node<int>* smallestOfBiggerNodes = current->right;
            parent = current;
            while (smallestOfBiggerNodes->left) {
                parent = smallestOfBiggerNodes;
                smallestOfBiggerNodes = smallestOfBiggerNodes->left;
            }

            parent->left = smallestOfBiggerNodes->left ? smallestOfBiggerNodes->left : smallestOfBiggerNodes->right;
            current->val = smallestOfBiggerNodes->val;
            return;
        } else {
            parent = current;
        }

        if (val > current->val) {
            current = current->right;
        }
        else {
            current = current->left;
        }

    }
}

// we go as far left as we can, then, if there is no left child, we go once to the right and then as far as we can to the left
template<typename T>
int Tree<T>::getMinNodeDepth() {
    int depth = 0;

    Node<T>* current = root;
    while (current->left) {
        current = current->left;
        depth++;
    }

    if (depth <= 0 && current->right) {
        current = current->right;
        depth++;

        while (current->left) {
            current = current->left;
            depth++;
        }
    }

    return depth;
}

template<typename T>
void Tree<T>::print(const std::string& prefix, Node<T>* parent, bool isLeft, bool isRoot) {
    if (parent == nullptr)
        return;

    if (isRoot) {
        std::cout << "-----";
    }
    else {
        std::cout << prefix << (isLeft ? "L|----" : "R\\___");
    }
    std::cout << parent->val << std::endl;

    print(prefix + (isLeft ? " |   " : "    "),
          parent->left, true, false);
    print(prefix + (isLeft ? " |   " : "    "),
          parent->right, false, false);
}

template<typename T>
void Tree<T>::print() {
    print("", root, false, true);
}

template<typename T>
bool Tree<T>::findNode(const T &val) {
    Node<T>* current = this->root;

    while (current) {
        if (val < current->val) {
            if (!current->left)
                return false;

            current = current->left;
        }
        else if (val > current->val) {
            if (!current->right)
                return false;

            current = current->right;
        }
        else {
            return true;
        }
    }

    return false;
}
