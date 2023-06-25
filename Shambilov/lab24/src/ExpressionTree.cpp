#include "../include/ExpressionTree.hpp"
#include "../include/Stack.hpp"
#include "../include/Node.hpp"

ExpressionTree::ExpressionTree(): root(nullptr){}

ExpressionTree::ExpressionTree(const std::string& expression){
    std::string postfix = doPostfix(expression);
    create(postfix);
}

ExpressionTree::~ExpressionTree() {
    clear(root);
}

Node* ExpressionTree::getRoot() const {
    return this->root;
}

size_t getPriority(char c){
    if (c == '+' || c == '-'){
        return 1;
    } else if (c == '*' || c == '/'){
        return 2;
    } else if (c == '^'){
        return 3;
    } else if (c == '~'){
        return 4;
    }

    return 0;
}

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

std::string ExpressionTree::doPostfix(const std::string& expression) {
    std::string postfix = "";
    Stack<char> stack;

    for (size_t i = 0; i != expression.size(); ++i) {
        char c = expression[i];

        if (!isOperator(c) && c != '(' && c != ')') {
            postfix += c;
        }
        else if (c == '(') {
            stack.push(c);
        }
        else if (c == ')') {
            while (stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else {
            if (c == '-' && expression[i - 1] == '(') c = '~';

            while (!stack.empty() && (getPriority(stack.top()) >= getPriority(c))) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}

void ExpressionTree::clear(Node* node) {
    if (node == nullptr) return;

    clear(node->left);
    clear(node->right);
    delete node;
    node = nullptr;
}

void ExpressionTree::create(const std::string& postfix) {
    if (postfix.length() == 0) return;

    Stack<Node*> stack;

    for (char c: postfix) {
        if (c == '~'){
            Node* node_x = stack.top();
            stack.pop();

            Node* node = new Node('-', nullptr, node_x);
            stack.push(node);
        }
        else if (isOperator(c)) {
            Node* node_x = stack.top();
            stack.pop();

            Node* node_y = stack.top();
            stack.pop();

            Node* node = new Node(c, node_y, node_x);
            stack.push(node);
        }
        else {
            stack.push(new Node(c));
        }
    }
}

void ExpressionTree::printPostfix(Node* root) const {
    if (root == nullptr) return;

    printPostfix(root->left);
    printPostfix(root->right);
    std::cout << root->data;
}

void ExpressionTree::printInfix(Node* root) const {
    if (root == nullptr) return;

    if (isOperator(root->data)){
        std::cout << '(';
    }

    printInfix(root->left);
    std::cout << root->data;
    printInfix(root->right);

    if (isOperator(root->data)){
        std::cout << ')';
    }
}

void ExpressionTree::print(Node* root, const size_t height) const {
    if (root != nullptr){
        print(root->right, height + 1);
        for (size_t i = 0; i < height; ++i){
            std::cout << "\t";
        }
        std::cout << root->data << "\n";
        print(root->left, height + 1);
    }
}

void ExpressionTree::replace(Node* root) {
    if (root == nullptr) return;

    if (root->data == '*' && root -> left->data == 'a' && root->right->data == '-') {
        Node* node1 = new Node('*');
        node1->left = new Node('a');
        node1->right = new Node(root->right->left->data);

        Node* node2 = new Node('*');
        node2->left = new Node('a');
        node2->right = new Node(root->right->right->data);

        Node* node3 = new Node('-');
        node3->left = node1;
        node3->right = node2;

        root = node3;
    }

    replace(root->left);
    replace(root->right);
}
