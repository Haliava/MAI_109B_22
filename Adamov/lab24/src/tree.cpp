#include "../include/tree.hpp"
#include <cstddef>
#include <string>

bool is_operator(char c) {
    return (c == '*' or c == '+' or c == '^');
}

size_t get_priority(char c) {
    if (c == '^') {
        return 2;
    }
    else if (c == '*' or c == '+') {
        return 1;
    }
    return 0;
}

Tree::Tree() {
    root = nullptr;
}

Tree::Tree(const std::string& expression) {
    if (expression.length() == 0)
        root = nullptr;

    std::string postfix = to_postfix(expression);

    Stack<Node*> stack;
    for (char c : postfix) {
        if (is_operator(c)) {
            Node* left_node = stack.pop();
            Node* right_node = stack.pop();
            Node* new_node = new Node(c, left_node, right_node);
            stack.push(new_node);
        }
        else {
            stack.push(new Node(c));
        }
    }

    root = stack.back();
}

Node* Tree::get_root() const {
    return root;
}

std::string Tree::to_postfix(const std::string &expression) {
    std::string postfix = "";
    Stack<char> stack;

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];

        if (!is_operator(c) and c != '(' and c != ')') {
            postfix += c;
        }
        else if (c == '(') {
            stack.push(c);
        }
        else if (c == ')') {
            while (stack.back() != '(') {
                postfix += stack.pop();
            }
            stack.pop();
        }
        else {
            while (!stack.empty() and get_priority(stack.back()) >= get_priority(c)) {
                postfix += stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.empty()) {
        postfix += stack.pop();
    }

    return postfix;
}

void Tree::print_bypass(Node* root, const size_t height) const {
    if (root != nullptr) {
        print_bypass(root->get_right(), height + 1);
        for (size_t i = 0; i < height; ++i) {
            std::cout << '\t';
        }
        std::cout << root->get_data() << '\n';
        print_bypass(root->get_left(), height + 1);
    }
}

void Tree::print() const {
    print_bypass(root, 0);
}

size_t Tree::get_levels_number() {
    size_t height = 1;
    Node* cur_node = root;
    while (cur_node->get_right() != nullptr) {
        ++height;
        cur_node = cur_node->get_right();
    }
    return height/2;
}

std::string Tree::make_new_polynomial(const Tree& g, int (*func)(int, int)) {
    std::string h = "";
    Vector<int> coefficents;
    size_t levels = get_levels_number();
    Node* f_summand = this->root;
    Node* g_summand = g.get_root();
    
    while (levels > 1) {
        int f_coef = f_summand->get_right()->get_left()->get_data() - '0';
        int g_coef = g_summand->get_right()->get_left()->get_data() - '0';
        coefficents.push_back(func(f_coef, g_coef));
        
        f_summand = f_summand->get_right()->get_right();
        g_summand = g_summand->get_right()->get_right();
        --levels;
    }
    int f_coef = f_summand->get_right()->get_data() - '0';
    int g_coef = g_summand->get_right()->get_data() - '0';
    coefficents.push_back(func(f_coef, g_coef));

    for (size_t i = 0; i < coefficents.size(); ++i) {
        char coef = coefficents[coefficents.size() - 1 - i] + '0';
        char deg = i + '0';
        h += std::string() + coef + "*x^" + deg;
        if (i != coefficents.size() - 1) {
            h += '+';
        }
    }

    return h;
}

void Tree::delete_tree(Node* node) {
    if (node == nullptr)
        return;
    delete_tree(node->get_left());
    delete_tree(node->get_right());
    delete node;
    node = nullptr;
}

Tree::~Tree() {
    delete_tree(root);
}
