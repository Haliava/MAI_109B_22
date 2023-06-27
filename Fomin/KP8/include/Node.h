#ifndef KP8_NODE_H
#define KP8_NODE_H

template<typename T>
class Node {
public:
    T data;
    Node *next;

    Node();
    Node(const T &data);
};

#endif //KP8_NODE_H
