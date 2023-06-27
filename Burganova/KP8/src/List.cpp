
#include <iostream>

#include "../include/List.hpp"

template <typename T, typename Allocator>
List<T, Allocator>::Node::Node(const T& value): value(value) {}

template <typename T, typename Allocator>
List<T, Allocator>::Node::Node(const T& value, Node* ptr): value(value), next(ptr) {}

template <typename T, typename Allocator>
List<T, Allocator>::List(const T& value) {
    Node* new_ptr = AllocTraits::allocate(alloc, 1);
    AllocTraits::construct(alloc, new_ptr, value);
    head = new_ptr;
    head->next = block_el;
}

template <typename T, typename Allocator>
List<T, Allocator>::~List() {
    while (head) {
        if (head == block_el) {
            AllocTraits::deallocate(alloc, head, 1);
            return;
        }

        pop_front();
    }
}

template <typename T, typename Allocator>
void List<T, Allocator>::pop_front() { 
    Node* prev_head = head;
    head = head->next;
    AllocTraits::destroy(alloc, prev_head);
    AllocTraits::deallocate(alloc, prev_head, 1);
    --size;
}

template <typename T, typename Allocator>
void List<T, Allocator>::push_front(const T& value) {
    Node* ptr = AllocTraits::allocate(alloc, 1);
    AllocTraits::construct(alloc, ptr, value);

    if (head == nullptr) {
        head = ptr;
        head->next = block_el;
    } else {
        Node* prev_head = head;
        head = ptr;
        head->next = prev_head;
    }

    ++size;  
}

template <typename T, typename Allocator>
void List<T, Allocator>::push_back(const T& value) {
    Node* ptr = AllocTraits::allocate(alloc, 1);
    AllocTraits::construct(alloc, ptr, value);

    if (head == nullptr) {
        head = ptr;
        head->next = block_el;
    } else {
        Node* last_el = head;
        while(last_el->next != block_el) {
            last_el = last_el->next;
        }
        last_el->next = ptr;
        ptr->next = block_el;
    }

    ++size;
}

template <typename T, typename Allocator>
void List<T, Allocator>::pop_back() {

    if (head == nullptr) {
        return;
    } else {
        Node* last_el = head;
        while(last_el->next->next != block_el) {
            last_el = last_el->next;
        }
        AllocTraits::destroy(alloc, last_el->next);
        AllocTraits::deallocate(alloc, last_el->next, 1);
        last_el->next = block_el;
    }

    --size;
}

template <typename T, typename Allocator>
void List<T, Allocator>::insert(Iterator& it, const T& value) {
    if (it.current_node == block_el) {
        return;
    }

    Node* new_node = AllocTraits::allocate(alloc, 1);
    AllocTraits::construct(alloc, new_node, value);

    if (head == nullptr) {
        head = new_node;
        head->next = block_el;
    } else {
        Node* temp = it.current_node->next;
        it.current_node->next = new_node;
        new_node->next = temp;

    }
        
    ++size;
}

template <typename T, typename Allocator>
void List<T, Allocator>::erase(Iterator& it) {
    if (size == 0) {
        return;
    }

    Iterator prev = this->begin();
    while (prev.current_node->next != it.current_node) {
        ++prev;
    }

    Node* temp = it.current_node->next;
    AllocTraits::destroy(alloc, it.current_node);
    AllocTraits::deallocate(alloc, it.current_node, 1);
    prev.current_node->next = temp;

    --size;
}

template <typename T, typename Allocator>
void List<T, Allocator>::erase(Iterator& start, Iterator& end) {
    Iterator it = this->begin();

    if (it != start) {
        while (it.current_node->next != start.current_node) {
            ++it;
        }
        it.current_node->next = end.current_node;

    } else {
        head = end.current_node;
    }

    while (start != end) {
        ++it;
        AllocTraits::destroy(alloc, start.current_node);
        AllocTraits::deallocate(alloc, start.current_node, 1);
        --size;
        start = it;
    }
}

template <typename T, typename Allocator>
void List<T, Allocator>::task(size_t k) {
    if (size == 0 || size < k) {
        return;
    }
    
    Iterator it = this->begin();
    int count = 1;
    while (it != this->end()) {
        Iterator temp = it;
        ++it;
        if (count % k == 0) {
            erase(temp);
        }
        ++count;
    }
}

template <typename T, typename Allocator>
template <typename... Args>
void List<T, Allocator>::emplace_back(const Args&... args) {
    push_back(T(args...));
}

template <typename T, typename Allocator>
size_t List<T, Allocator>::get_size() {
    return size;
}

template <typename T, typename Allocator>
List<T, Allocator>::Iterator::Iterator(Node* ptr): current_node(ptr) {}

template <typename T, typename Allocator>
typename List<T, Allocator>::Iterator& List<T, Allocator>::Iterator::operator=(Node* node_ptr) {
        this->current_node = node_ptr;
        return *this;
} 

template <typename T, typename Allocator>
T& List<T, Allocator>::Iterator::operator*() {
    return current_node->value;
}

template <typename T, typename Allocator>
const T& List<T, Allocator>::Iterator::operator*() const {
    return current_node->value;
}

template <typename T, typename Allocator>
typename List<T, Allocator>::Iterator& List<T, Allocator>::Iterator::operator++() {
    if (current_node) {
        current_node = current_node->next;
    }
    return *this;
}

template <typename T, typename Allocator>
typename List<T, Allocator>::Iterator& List<T, Allocator>::Iterator::operator++(int) {
    Iterator copy = *this;
    ++*this;
    return copy;
}

template <typename T, typename Allocator>
bool List<T, Allocator>::Iterator::operator==(const Iterator& it) const {
    return current_node == it.current_node;
}

template <typename T, typename Allocator>
bool List<T, Allocator>::Iterator::operator!=(const Iterator& it) const {
    return current_node != it.current_node;
}

template <typename T, typename Allocator>
void List<T, Allocator>::Iterator::advance(size_t n) {
    for (size_t i = 0; i < n; ++i) {
        ++*this;
    }
}

template <typename T, typename Allocator>
typename List<T, Allocator>::Iterator List<T, Allocator>::begin() const {
    Iterator iter(head);
    return iter;
}

template <typename T, typename Allocator>
typename List<T, Allocator>::Iterator List<T, Allocator>::end() const {
    Iterator iter(block_el);
    return iter;
}

template <typename T, typename Allocator>
std::ostream& operator<<(std::ostream& stream, List<T, Allocator>& lst) {
    for (typename List<T, Allocator>::Iterator it = lst.begin(); it != lst.end(); ++it) {
        stream << *it << ' ';
    }

    return stream;
}
