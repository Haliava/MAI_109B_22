#include "../include/List.hpp"

template <typename T>
List<T>::List() {
    head->next = nullptr;            
    size = 0;
}

template <typename T>
List<T>::List(const std::initializer_list<T>& init_list) {
    head.next = nullptr;            
    size = 0;
    for (auto it = init_list.begin(); it != init_list.end(); ++it) {
        push_left(*it);
    }
}

template <typename T>
size_t List<T>::get_size() {
    return size;
}

template <typename T>
bool List<T>::empty() {
    return size == 0;
}

template <typename T>
bool List<T>::is_sorted() {
    Node* n_ptr = head->next;
    while (n_ptr->next != nullptr) {
        if (n_ptr->value > n_ptr->next->value)
            return false;
        n_ptr = n_ptr->next;
    }
    return true;
}

template <typename T>
void List<T>::push_left(const T& value) {
    Node* n = new Node;
    n->value = value;
    n->next = head.next;
    head.next = n;
    ++size;
}

template <typename T>
void List<T>::print() {
    Node* loop_ptr = head.next;
    while (loop_ptr != nullptr) {
        std::cout << loop_ptr->value << " ";
        loop_ptr = loop_ptr->next;
    }
    std::cout << std::endl;
}

template <typename T>
void List<T>::merge_sort() {
    head.next = merge_sort(head.next);
}

template <typename T>
typename List<T>::Node* List<T>::merge_sort(Node* n) {
    if (n == nullptr || n->next == nullptr)
        return n;

    Node* middle = get_middle(n);
    Node* left_head = n;
    Node* right_head = middle->next;
    middle->next = nullptr;
    return merge(merge_sort(left_head), merge_sort(right_head));
}

template <typename T>
typename List<T>::Node* List<T>::get_middle(Node* n) {
    if(n == nullptr)
        return n;

    Node* slow = n;
    Node* fast = n;

    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

template <typename T>
typename List<T>::Node* List<T>::merge(Node* a, Node* b) {
    Node dummy_head;
    Node* current = &dummy_head;

    while (a != nullptr && b != nullptr) {
        if (a->value < b->value) {
            current->next = a;
            a = a->next;
        } else {
            current->next = b;
            b = b->next;
        }
        current = current->next;
    }

    current->next = (a == nullptr) ? b : a;
    return dummy_head.next; 
}

template <typename T>
List<T>::~List() {
    Node* node_to_delete;
    Node* ptr = head.next;

    while(ptr != nullptr) {
        node_to_delete = ptr;
        ptr = ptr->next;
        delete node_to_delete;
    }
}    
