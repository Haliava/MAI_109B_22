#include "../include/TreeNode.hpp"


template<typename T>
TreeNode<T>::TreeNode() : data(T()), children() {}

template<typename T>
TreeNode<T>::TreeNode(const T& data) : data(data), children() {}

template<typename T>
TreeNode<T>::TreeNode(const T& data, const myVector<TreeNode*>& children) : data(data), children(children) {}
