#ifndef NODE_H
#define NODE_H

class ExpressionTree;

class Node{
    friend class ExpressionTree;

private:
    char data;
    Node* left;
    Node* right;

public:
    Node();
    Node(const char data);
    Node(const char data, Node* left, Node* right);
};

#endif