#include "../include/node.hpp"

Node::Node(const char& _data) {
    data = _data;
}

Node::Node(const char& _data, Node* _left, Node* _right) {
    data = _data;
    left = _left;
    right = _right;
}

char Node::get_data() const { 
    return data;
}

Node* Node::get_left() const {
    return left;
}

Node* Node::get_right() const {
    return right;
}
