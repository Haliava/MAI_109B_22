#include "../include/List.hpp"
#include <iostream>

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head.swap_nodes(2);

    Node* curr = head;
    while (curr) {
        std::cout << curr->data << ' ';
        curr = curr->next;
    }
}