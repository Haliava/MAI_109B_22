#include "../include/TreeNode.hpp"

TreeNode::TreeNode(const char &_data): data(_data) {}

TreeNode::TreeNode(const char &_data, TreeNode *_prev, TreeNode *_next): data(_data), prev(_prev), next(_next) {}

TreeNode *TreeNode::get_next() const {
    return next;
}

TreeNode *TreeNode::get_prev() const {
    return prev;
}

char TreeNode::get_data() const {
    return data;
}

void TreeNode::set_data(const char &_data) {
    data = _data;
}

void TreeNode::set_prev(TreeNode *_prev) {
    prev = _prev;
}

void TreeNode::set_next(TreeNode *_next) {
    next = _next;
}

TreeNode *TreeNode::get_copy(TreeNode *x) {
    if (x == nullptr)
        return nullptr;

    TreeNode *copy = new TreeNode();

    copy->data = x->data;
    copy->prev = get_copy(x->prev);
    copy->next = get_copy(x->next);

    return copy;
}

TreeNode *TreeNode::get_copy() {
    return get_copy(this);
}

