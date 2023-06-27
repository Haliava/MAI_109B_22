#ifndef NODE_HPP
#define NODE_HPP

class Node {
private:
    char data;
    Node* left = nullptr;
    Node* right = nullptr;

public:
    Node() = default;
    Node(const char& _data);
    Node(const char& _data, Node* _left, Node* _right);

    char get_data() const;
    Node* get_left() const;
    Node* get_right() const;

    ~Node() = default;
};

#include "../src/node.cpp"
#endif // NODE_HPP
