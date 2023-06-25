#include "../include/ExpressionTree.h"
#include <stack>
#include <vector>
#include "../include/Node.h"

std::vector<std::string> split(std::string expression, char delimiter) {
    int pos;
    std::vector<std::string> exprParts;
    std::string token;
    std::string expressionCopy = expression;
    while ((pos = expressionCopy.find(delimiter)) != std::string::npos) {
        token = expressionCopy.substr(0, pos);
        exprParts.push_back(token);
        expressionCopy.erase(0, pos + 1);
    }
    exprParts.push_back(expressionCopy);

    return exprParts;
}

ExpressionTree::ExpressionTree() : root(nullptr) {}

ExpressionTree::ExpressionTree(const std::string &expression) {
    std::string postfix = doPostfix(expression);
    root = createTree(postfix);
    this->expression = expression;
}

ExpressionTree::~ExpressionTree() {
    deleteTree(root);
}

Node *ExpressionTree::getRoot() const {
    return this->root;
}

size_t getPriority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    } else if (c == '~') {
        return 4;
    }

    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

std::string ExpressionTree::doPostfix(const std::string &expression) {
    std::string postfix = "";
    std::stack<char> stack;

    for (size_t i = 0; i != expression.size(); ++i) {
        char c = expression[i];

        if (!isOperator(c) && c != '(' && c != ')') {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        } else {
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

void ExpressionTree::deleteTree(Node *node) {
    if (node == nullptr) return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

Node *ExpressionTree::createTree(const std::string &postfix) {
    if (postfix.length() == 0) return nullptr;
    std::stack<Node *> stack;

    for (char c: postfix) {
        if (c == '~') {
            Node *node_x = stack.top();
            stack.pop();

            Node *node = new Node('-', nullptr, node_x);
            stack.push(node);
        } else if (isOperator(c)) {
            Node *node_x = stack.top();
            stack.pop();

            Node *node_y = stack.top();
            stack.pop();

            Node *node = new Node(c, node_y, node_x);
            stack.push(node);
        } else {
            stack.push(new Node(c));
        }
    }

    return stack.top();
}

void ExpressionTree::printPostfix(Node *root) {
    if (root == nullptr) return;

    printPostfix(root->left);
    printPostfix(root->right);
    std::cout << root->data;
}

void ExpressionTree::printInfix(Node *root) const {
    if (root == nullptr) return;

    if (isOperator(root->data)) {
        std::cout << '(';
    }

    printInfix(root->left);
    std::cout << root->data;
    printInfix(root->right);

    if (isOperator(root->data)) {
        std::cout << ')';
    }
}

void ExpressionTree::printTree(Node *root, const size_t height) const {
    if (root != nullptr) {
        printTree(root->right, height + 1);
        for (size_t i = 0; i < height; ++i) {
            std::cout << "\t";
        }
        std::cout << root->data << "\n";
        printTree(root->left, height + 1);
    }
}

void ExpressionTree::composeToSquaredExpression() {
    if (root == nullptr) return;

    std::vector<std::string> parts = split(getExpression(), '+');
    std::vector<std::string> firstPart = split(parts[0], '^');
    std::vector<std::string> secondPart = split(parts[1], '*');
    std::vector<std::string> thirdPart = split(parts[2], '^');

    if (
        std::stoi(firstPart[1]) % 2 != 0 ||
        std::stoi(secondPart[0]) % 2 != 0 ||
        std::stoi(thirdPart[1]) % 2 != 0
    ) return;

    firstPart[1] = std::to_string(std::stoi(firstPart[1]) / 2);
    secondPart[0] = std::to_string(std::stoi(secondPart[0]) / 2);
    thirdPart[1] = std::to_string(std::stoi(thirdPart[1]) / 2);

    std::string newExpression =
            "(" +
                firstPart[0] + "^" + firstPart[1] + "+" + thirdPart[0] + "^" + thirdPart[1] +
            ")^2";
    //std::cout << newExpression << std::endl;

    deleteTree(getRoot());
    expression = newExpression;
    root = createTree(doPostfix(newExpression));
}

std::string ExpressionTree::getExpression() {
    return expression;
}
