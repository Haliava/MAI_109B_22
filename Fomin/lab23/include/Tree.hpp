#ifndef INCLUDE_TREE_HPP_
#define INCLUDE_TREE_HPP_
#include "Node.hpp"

class Tree {
private:
	vector<Node<T>> nodeList;
	Node<T>* root = nullptr;
	int nodeCount;

public:
	Tree(int rootVal) {}
	Tree(Node* root) {}

	Node<T>* getRoot() {}

	void addNode(int val) {}
	void deleteNode(int val) {}

	int getDepthOfBiggestNode() {}

	void print(const string& prefix, Node<T>* parent, bool isLeft, bool isRoot) {}
	void draw(Node<T>* root, int depth, int max_depth) {}

};

#include "../src/Tree.cpp"

#endif