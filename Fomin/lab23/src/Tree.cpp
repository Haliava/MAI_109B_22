#include <iostream>

using namespace std;


class Tree {
private:
	vector<Node<T>> nodeList;
	Node<T>* root = nullptr;
	int nodeCount = 0;

public:
	Tree(int rootVal) {
		this->root = new Node<T>(rootVal);
		this->nodeCount++;
	}

	Tree(Node<T>* root) {
		this->root = root;
		this->nodeCount++;
	}

	Node* getRoot() {
		return root;
	}

	void addNode(int val) {
		Node<T>* current = this->root;
		nodeCount++;

		while (current) {
			if (val < current->val) {
				if (!current->left) {
					current->left = new Node<T>(val);
					break;
				}
				current = current->left;
			}
			else if (val > current->val) {
				// val > current->val
				if (!current->right) {
					current->right = new Node<T>(val);
					break;
				}
				current = current->right;
			}
			else {
				return;
			}
		}
	}

	/*
	* Algorithm goes as:
	* 1. Node has no children. Then we just delete Node parent's link to that node.
	* 2. Node has one child. Then we replace Node with its child.
	* 3. Node has both children. Then we go once to the right and then max to the left.
		 Then we replace Node's value with our max left child's value.
	*/
	void deleteNode(int val) {
		Node<T>* parent = nullptr;
		Node<T>* current = this->root;
		nodeCount--;

		while (current) {
			parent = current;

			if (val == current->val) {
				// returns to avoid excess nesting
				if (!current->left && !current->right) {
					if (val > parent->val) parent->right = nullptr;
					else parent->left = nullptr;
					return;
				}

				if (current->left && !current->right) {
					if (val > parent->val) parent->right = current->left;
					else parent->left = current->left;
					return;
				}

				if (!current->left && current->right) {
					if (val > parent->val) parent->right = current->right;
					else parent->left = current->right;
					return;
				}

				Node* smallestOfBiggerNodes = current->right;
				parent = current;
				while (smallestOfBiggerNodes->left) {
					parent = smallestOfBiggerNodes;
					smallestOfBiggerNodes = smallestOfBiggerNodes->left;
				}

				parent->left = smallestOfBiggerNodes->left ? smallestOfBiggerNodes->left : smallestOfBiggerNodes->right;
				current->val = smallestOfBiggerNodes->val;
				return;
			}

			if (val > current->val) {
				current = current->right;
			}
			else {
				current = current->left;
			}
		}
	}

	// we go as far left as we can, then, if there is no left child, we go once to the right and then as far as we can to the left
	int getDepthOfSmallestNode() {
		int max = 0;
		int depth = 0;

		Node<T>* current = root;
		while (current->left) {
			current = current->left;
			depth++;
		}

		if (depth <= 0 && current->right) {
			current = current->right;
			depth++;

			while (current->left) {
				current = current->left;
				depth++;
			}
		}

		return depth;
	}

	void print(const string& prefix, Node<T>* parent, bool isLeft, bool isRoot) {
		if (parent == nullptr)
			return;

		if (isRoot) {
			cout << "-----";
		}
		else {
			cout << prefix << (isLeft ? "L|----" : "R\\___");
		}
		cout << parent->val << endl;

		print(prefix + (isLeft ? " |   " : "    "),
			parent->left, true, false);
		print(prefix + (isLeft ? " |   " : "    "),
			parent->right, false, false);
	}

	void draw(Node<T>* root, int depth, int max_depth) {
		if (root == nullptr || depth > max_depth) return;

		draw(root->right, depth + 1, max_depth);
		cout << string(depth * 4, ' ') << root->val << endl;
		draw(root->left, depth + 1, max_depth);
	}

};