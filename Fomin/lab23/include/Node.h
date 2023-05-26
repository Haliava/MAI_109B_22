#ifndef LAB23_NODE_H
#define LAB23_NODE_H

template<typename T>
struct Node {
    T val;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;

    Node();
    explicit Node(const T& x);
    Node(const T& x, Node<T>* left, Node<T>* right);
};


#endif //LAB23_NODE_H
