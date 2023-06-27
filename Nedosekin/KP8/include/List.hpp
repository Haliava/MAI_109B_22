 #ifndef LIST_HPP
#define LIST_HPP
#include "../include/Iterator.hpp"
template<typename T>
class List
{
public:
    List();
    ~List();
    Iterator<T> begin() const;
    Iterator<T> end();
    bool empty() const;
    size_t size() const;

    Iterator<T> insert(const Iterator<T>& pos, const T &value);
    Iterator<T> erase(const Iterator<T>& where) noexcept;
    Iterator<T> erase(const Iterator<T>& first, const Iterator<T>& last) noexcept;

    void push_back(const T &value);
    void push_front(const T &value);
    void pop_back();
    void pop_front();
    template<typename ...Args>
    void emplace_front(const T& first, const Args &...args);
    template<typename... Args>
    void emplace_back(const T &first, const Args &...args);
    T& front();
    T& back();
    void swap(size_t k);

    template<typename F>
    friend std::ostream &operator<<(std::ostream &out, List<T> &l);
private:
    size_t size_;
    Node<T>* head_;
};
#include "../src/List.cpp"
#endif//LIST_HPP