#ifndef INCLUDE_NODE_HPP_
#define INCLUDE_NODE_HPP_
#include <iostream>
#include <algorithm>

template<typename T>
struct Node {
	T val;
	Node<T>* left;
	Node<T>* right;

	Node() : val(0), left(nullptr), right(nullptr) {}
	Node(T x) : val(x), left(nullptr), right(nullptr) {}
	Node(T x, Node<T>* left, Node<T>* right) : val(x), left(left), right(right) {}
};

#include "../src/Node.cpp"

#endif