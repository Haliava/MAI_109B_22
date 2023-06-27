#pragma once
#include "Vector.hpp"
template <typename T>
struct TreeNode {
  T val;
  Vector<TreeNode*> children;
  TreeNode(T value) : val(value) {};
  ~TreeNode();
};
#include "../src/TreeNode.cpp"
