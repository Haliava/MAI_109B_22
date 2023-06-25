#include "../include/List.hpp"

template<typename T>
List<T>::List() : size_(0)
{
    head_ = new Node<T>();
}
template<typename T>
List<T>::~List()
{
    if (size_ != 0) {
        Iterator<T> currentNode = begin();
        while (size_) {
            Node<T> *tempNode = currentNode.getNode();
            ++currentNode;
            delete tempNode;
            --size_;
        }
    }
}

template<typename T>
Iterator<T> List<T>::begin() const
{
    Iterator<T> begin(head_);
    return begin;
}

template<typename T>
Iterator<T> List<T>::end()
{
    return (begin() + (size() - 1));
}
template<typename T>
bool List<T>::empty() const
{
    return (size_ == 0);
}
template<typename T>
size_t List<T>::size() const
{
    return size_;
}
template<typename T>
void List<T>::push_back(const T &value)
{
    emplace_back(value);
}
template<typename T>
template<typename... Args>
void List<T>::emplace_back(const T &first, const Args &...args)
{
    Iterator<T> itEnd = end();
    if (size() == 0) {
        head_ = new Node<T>(first, head_);
        ++size_;
        if constexpr (sizeof...(args) > 0) {
            emplace_back(args...);
        }
    }
    else {
        itEnd.getNode()->next_ = new Node<T>(first, itEnd.getNode()->next_);
        ++size_;
        if constexpr (sizeof...(args) > 0) {
            emplace_back(args...);
        }
    }
}
template<typename T>
void List<T>::push_front(const T &value)
{
    emplace_front(value);
}
template<typename T>
template<typename... Args>
void List<T>::emplace_front(const T &first, const Args &...args)
{
    if (size_ == 0) {
        head_->value_ = first;
        ++size_;
        if constexpr (sizeof...(args) > 0) {
            emplace_front(args...);
        }
    }
    else {
        Node<T> *new_node = new Node<T>(first, new_node);
        new_node->next_ = head_;
        head_ = new_node;
        ++size_;
        if constexpr (sizeof...(args) > 0) {
            emplace_front(args...);
        }
    }
}
template<typename T>
void List<T>::pop_back()
{
    Iterator<T> endIt = end();
    delete endIt.getNode();
    --size_;
}

template<typename T>
void List<T>::pop_front()
{
    Iterator<T> beginIt = begin();
    if (size_ > 1) {
        head_ = beginIt.getNode()->next_;
    }
    else {
        head_ = nullptr;
    }
    delete beginIt.getNode();
    --size_;
}

template<typename T>
Iterator<T> List<T>::erase(const Iterator<T> &where) noexcept
{
    Iterator<T> tempIt = begin();
    if (where == begin()) {
        head_ = tempIt.getNode()->next_;
        delete tempIt.getNode();
        --size_;
    }
    else if (where == end()) {
        delete end().getNode();
        --size_;
    }
    else {
        while (tempIt.getNode()->next_ != where.getNode()) {
            ++tempIt;
        }
        tempIt.getNode()->next_ = where.getNode()->next_;
        delete where.getNode();
        --size_;
    }
    return tempIt;
}

template<typename T>
Iterator<T> List<T>::erase(const Iterator<T> &first, const Iterator<T> &last) noexcept
{
    Iterator<T> tempIt = begin();
    Iterator<T> currIt = first;
    Iterator<T> currItPrev = begin();
    while (currIt != last) {
        if (currIt == begin()) {
            head_ = tempIt.getNode()->next_;
            tempIt = currIt;
            ++currIt;
            delete tempIt.getNode();
            --size_;
        }
        else {
            while (currItPrev.getNode()->next_ != currIt.getNode()) {
                ++currItPrev;
            }
            tempIt = currIt;
            currItPrev.getNode()->next_ = currIt.getNode()->next_;
            ++currIt;
            delete tempIt.getNode();
            --size_;
        }
    }
    if (currIt == end()) {
        delete end().getNode();
        --size_;
    }
    else {
        tempIt = currIt;
        currItPrev.getNode()->next_ = currIt.getNode()->next_;
        ++currIt;
        delete tempIt.getNode();
        --size_;
    }
    return currIt;
}

template<typename T>
T &List<T>::front()
{
    return head_->value_;
}
template<typename T>
T &List<T>::back()
{
    return end().getNode()->value_;
}

template<typename T>
Iterator<T> List<T>::insert(const Iterator<T> &pos, const T &value)
{
    Node<T>* temp = pos.getNode()->next_;
    pos.getNode()->next_ = new Node<T>(value, pos.getNode()->next_);
    ++size_;
    pos.getNode()->next_->next_ = temp;
    return pos;
}

template<typename T>
void List<T>::swap(size_t k)
{
    if (size() != 0 && k > 1 && k < size()) {
        Iterator<T> kPrev = begin() + (k - 2);
        Iterator<T> kNext = kPrev;
        kNext = kNext + 2;
        T tempValue = kPrev.getNode()->value_;
        kPrev.getNode()->value_ = kNext.getNode()->value_;
        kNext.getNode()->value_ = tempValue;
    }
}

int64_t charToSet(char c)
{
    tolower(c);
    if (c < 'a' || c > 'z') {
        return 0;
    }
    else {
        return 1u << (c - 'a');
    }
}
template<typename T>
std::ostream &operator<<(std::ostream &out, List<T> &l)
{
    if (l.size() != 0) {
        char alpha;
        for (Iterator<T> it = l.begin(); it != l.end(); ++it) {
            for (alpha = 'a'; alpha <= 'z'; ++alpha) {
                if ((*it & charToSet(alpha)) != 0) {
                    out << alpha;
                }
            }
            out << ' ';
        }
        for (alpha = 'a'; alpha <= 'z'; ++alpha) {
            if ((*l.end() & charToSet(alpha)) != 0) {
                out << alpha;
            }
        }
        out << '\n';
    }
    return out;
}