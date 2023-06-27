#include <iostream>
#include "../include/List.hpp"

int main() {
    List<int> l = {3,6,-5,222,495,-129,0};
    l.print();
    l.merge_sort();
    l.print();
    return 0;
}