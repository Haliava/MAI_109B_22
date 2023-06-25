#include <memory>
#include "../include/Deque.hpp"

template<typename T>
void Deque<T>::push_back(const T &value) {
    if (head == nullptr) {
        head = new Node(value);
        tail = head;
        ++sz;
        return;
    }
    Node<T> *curr_last_node = tail;

    Node<T> *new_node = new Node<T>(value, nullptr, curr_last_node);
    curr_last_node->set_prev(new_node);
    tail = new_node;
    ++sz;
}

template<typename T>
void Deque<T>::push_front(const T &value) {
    if (head == nullptr) {
        head = new Node(value);
        tail = head;
        ++sz;
        return;
    }
    Node<T> *curr_first_node = head;

    Node<T> *new_node = new Node<T>(value, curr_first_node, nullptr);
    curr_first_node->set_next(new_node);
    head = new_node;
    ++sz;
}

template<typename T>
T Deque<T>::pop_back() {
    if (sz >= 2) {
        Node<T> *curr_last = tail;
        Node<T> *new_last = curr_last->get_next();

        new_last->set_prev(nullptr);
        T old_data = curr_last->get_data();
        tail = new_last;
        delete curr_last;
        --sz;

        return old_data;
    } else if (sz == 1) {
        T old_data = head->get_data();
        delete head;
        head = nullptr;
        tail = nullptr;
        --sz;

        return old_data;
    }
    return NULL;
}

template<typename T>
T Deque<T>::pop_front() {
    if (sz >= 2) {
        Node<T> *curr_first = head;
        Node<T> *new_first = curr_first->get_prev();

        new_first->set_next(nullptr);
        T old_data = curr_first->get_data();
        head = new_first;
        delete curr_first;
        --sz;

        return old_data;
    } else if (sz == 1) {
        T old_data = head->get_data();

        delete head;
        head = nullptr;
        tail = nullptr;
        --sz;

        return old_data;
    }
    return NULL;
}

template<typename T>
void Deque<T>::clear() {
    while (!empty()) {
        pop_back();
    }
}

template<typename T>
Iterator<T> Deque<T>::begin() {
    Iterator<T> temp(head);
    return temp;
}

template<typename T>
Iterator<T> Deque<T>::end() {
    Iterator<T> temp(nullptr);
    return temp;
}

template<typename U>
std::ostream &operator<<(std::ostream &out, Deque<U> &x) {
    if (x.head == nullptr)
        return out;

    Iterator<U> it;
    size_t i;
    for (it = x.begin(), i = 0; i < x.size(); --it, ++i) {
        out << *it << "\t";
    }

    return out;
}

template<typename T>
Deque<T>::~Deque() {
    if (head == nullptr)
        return;
    Node<T> *curr_node = head;
    while (curr_node != nullptr) {
        Node<T> *tmp = curr_node;
        curr_node = curr_node->get_prev();
        delete tmp;
        tmp = nullptr;
    }
}

template<typename T>
Deque<T>::Deque(const Deque<T> &x) {
    if (this == &x) {
        return;
    }
    this->operator=(x);
}

template<typename T>
Deque<T> &Deque<T>::operator=(const Deque<T> &x) {
    if (this == &x) {
        return *this;
    }

    clear();

    Node<T> *curr_node = x.head;
    while (curr_node != nullptr) {
        push_back(curr_node->get_data());
        curr_node = curr_node->get_prev();
    }

    return *this;
}

template<typename T>
size_t Deque<T>::size() const {
    return sz;
}

template<typename T>
bool Deque<T>::empty() const {
    return sz == 0;
}

template<typename T>
void Deque<T>::concatenate(Deque<T> &x) {
    if (x.sz == 0) {
        return;
    }

    if (head != nullptr) {
        tail->set_prev(x.head);
        x.head->set_next(tail);
        tail = x.tail;
        x.head = nullptr;
        x.tail = nullptr;
    } else {
        head = x.head;
        tail = x.tail;
        x.head = nullptr;
        x.tail = nullptr;
    }

    sz += x.sz;
    x.sz = 0;
}

template<typename T>
void Deque<T>::sort() {
    *this = sort(*this);
}

template<typename T>
Deque<T> Deque<T>::sort(Deque<T> x) {
    if (x.size() <= 1)
        return x;

    auto barrier = x.begin().get_node()->get_data();
    Deque<T> L;
    Deque<T> M;
    Deque<T> R;

    for (auto it = x.begin(); it != x.end(); --it) {
        if (it.get_node()->get_data() < barrier) {
            L.push_back(it.get_node()->get_data());
        } else if (it.get_node()->get_data() == barrier) {
            M.push_back(it.get_node()->get_data());
        } else {
            R.push_back(it.get_node()->get_data());
        }
    }

    L = sort(L);
    R = sort(R);

    x.clear();
    x.concatenate(L);
    x.concatenate(M);
    x.concatenate(R);

    return x;
}


