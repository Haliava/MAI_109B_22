#ifndef LISTNODEHPP
#define LISTNODEHPP

template <typename T>
class Node{
public:
    T data;
    Node<T>* next;
    Node<T>* previous;

public:
    Node();
    Node(const T& value);
    Node(const T& value, Node<T>* previous_node, Node<T>* current_node);
};

#endif