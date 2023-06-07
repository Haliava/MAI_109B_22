#include "../src/Tree.cpp"

int main() {
    std::cout << "START" << std::endl;
    auto* tree = new Tree<int>(20);

    tree->addNode(10);
    tree->addNode(30);
    tree->addNode(5);
    tree->addNode(15);
    tree->addNode(15);
    tree->addNode(25);
    tree->addNode(17);
    tree->print();
    //tree->print("", tree->getRoot(), false, true);
    std::cout << "\n\n\n\n" << std::endl;

    /*
    деревья у меня в программе выводятся иначе, но тут удобнее рисовать его так
                  20
               /      \
              10      30
             /  \     /
            5   15   25
                  \
                  17
    */

    tree->deleteNode(17);
    tree->print();
    //tree->print("", tree->getRoot(), false, true);
    std::cout << "^ deleted 17\n\n\n\n" << std::endl;
    /*
                 20
              /      \
             10      30
            /  \    /
           5   15  25

    */

    tree->addNode(17);
    tree->deleteNode(15);
    tree->print();
    //tree->print("", tree->getRoot(), false, true);
    std::cout << "^ returned 17 and deleted 15\n\n\n\n" << std::endl;
    /*
                 20
              /      \
             10      30
            /  \    /
           5   17  25
    */

    tree->deleteNode(17);
    tree->deleteNode(15);
    tree->deleteNode(17);
    tree->deleteNode(10);
    tree->print();
    //tree->print("", tree->getRoot(), false, true);
    std::cout << "deleted 17 15 17 (to check deletion of not existing element) 10\n\n\n\n" << std::endl;
    /*
                 20
              /      \
             15      30
            /  \    /
           5   17  25
    */

    tree->deleteNode(20);
    tree->print();
    //tree->print("", tree->getRoot(), false, true);
    std::cout << "deleted root (20)\n\n\n\n" << std::endl;
    /*
                 25
              /      \
             15      30
            /  \
           5   17
    */

    // 2
    std::cout << tree->getMinNodeDepth() << std::endl;

    tree->addNode(100);
    tree->addNode(1);
    tree->print();
    //tree->print("", tree->getRoot(), false, true);
    std::cout << "added 100 and 1\n\n\n\n" << std::endl;
    /*
                  25
               /      \
              15      30
             /  \       \
            5   17      100
           /
          1
    */

    // 3
    std::cout << tree->getMinNodeDepth() << std::endl;

    return 0;
}