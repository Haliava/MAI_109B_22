#include "../include/tree.hpp"
#include <iostream>

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int multiply(int a, int b) {
    return (a*b)%10;
}

int main() {
    std::string pol_1 = "1*x^0+2*x^1+4*x^2+6*x^3";
    std::string pol_2 = "8*x^0+6*x^1+5*x^2+3*x^3";
    Tree f(pol_1);
    Tree g(pol_2);
    std::cout << f.make_new_polynomial(g, &max) << '\n';
    std::cout << f.make_new_polynomial(g, &min) << '\n';
    std::cout << f.make_new_polynomial(g, &multiply) << '\n';

    return 0;
}
