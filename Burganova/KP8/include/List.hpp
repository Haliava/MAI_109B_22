#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

template <typename T, typename Allocator = std::allocator<T>>
class List {
private:
    class Node { 
    public:
        T value;
        Node* next = nullptr;

        Node(const T&); 
        Node(const T&, Node*);
    };

    using Alloc = typename std::allocator_traits<Allocator>::template rebind_alloc<Node>;
    Alloc alloc;
    using AllocTraits = std::allocator_traits<Alloc>;

    size_t size = 0;
    Node* head = nullptr;
    Node* const block_el = AllocTraits::allocate(alloc, 1); 

public:
    class Iterator; 

    List() = default;
    List(const T&);
    ~List(); 

    void pop_front(); 
    void push_front(const T&); 
    void pop_back(); 
    void push_back(const T&); 
    void insert(Iterator&, const T&); 
    void erase(Iterator&); 
    void erase(Iterator&, Iterator&); 
    void task(size_t);

    template <typename... Args>
    void emplace_back(const Args&... args); 
    
    size_t get_size(); 
    
    class Iterator { 
    public:
        Node* current_node; 

        Iterator(Node*);
        ~Iterator() = default;
        Iterator& operator=(Node*);
        T& operator*();
        const T& operator*() const;
        Iterator& operator++();
        Iterator& operator++(int);
        void advance(size_t n);

        bool operator==(const Iterator&) const;
        bool operator!=(const Iterator&) const;
    }; 

    Iterator begin() const; 
    Iterator end() const;
};

#include "../src/List.cpp"

#endif