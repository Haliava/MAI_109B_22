#ifndef LAB23_TREE_H
#define LAB23_TREE_H

#include "../src/Node.cpp"

template<typename T>
class Tree {
private:
    Node<T>* root = nullptr;

public:
    explicit Tree(const T& rootVal);
    explicit Tree(Node<T>* root);

    Node<T>* getRoot();

    void addNode(const T& val);
    void deleteNode(const T& val);
    bool findNode(const T& val);

    int getMinNodeDepth();

    void print(const std::string& prefix, Node<T>* parent, bool isLeft, bool isRoot);
    void print();
};

#endif //LAB23_TREE_H