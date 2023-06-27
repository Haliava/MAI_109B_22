#include "../include/Tree.hpp"
#include "../include/TreeNode.hpp"


int main(){

    Tree<size_t> tree(3);

    for(size_t nodeData = 1; nodeData < 3; ++nodeData){
        tree.addNode((nodeData*3)/2+5, tree.getRoot());
        tree.addNode((nodeData*2)/3+2, tree.getRoot());
    }
    tree.visualize(tree.getRoot());
    tree.linearize(tree.getRoot());
    std::cout << "\n\n\n";
    
    Tree<size_t> secondTree;
    for(size_t nodeData = 1; nodeData < 3; ++nodeData){
        secondTree.addNode(nodeData, secondTree.getRoot());
        secondTree.addNode((nodeData+5)*34, secondTree.getRoot());
    }
    secondTree.visualize(secondTree.getRoot());
    secondTree.linearize(secondTree.getRoot());
    std::cout << "\n\n\n";
    
    return 0;

}