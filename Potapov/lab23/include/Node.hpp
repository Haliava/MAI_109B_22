#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data);
};

#include "../src/Node.cpp"

#endif// NODE_HPP_INCLUDED
