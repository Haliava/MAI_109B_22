#include "../include/Tree.hpp"

int main() {
    Tree<int> bintr;
    int choice, value;
    bool exitProgram = false;

    while (!exitProgram) {
        std::cout << "1. Insert Node" << std::endl;
        std::cout << "2. Delete Node" << std::endl;
        std::cout << "3. Display Tree" << std::endl;
        std::cout << "4. Get Max Depth" << std::endl;
        std::cout << "5. Get Max Depth Leaf" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to be inserted: ";
                std::cin >> value;
                bintr.insert(value);
                break;
            case 2:
                std::cout << "Enter value to be deleted: ";
                std::cin >> value;
                bintr.remove(value);
                break;
            case 3:
                std::cout << "Tree: ";
                bintr.display();
                break;
            case 4:
                std::cout << "Max Depth: " << bintr.getMaxDepth() << std::endl;
                break;
            case 5:
                std::cout << "Max Depth Leaf: " << bintr.getMaxDepthLeaf() << std::endl;
                break;
            case 6:
                std::cout << "Exiting program..." << std::endl;
                exitProgram = true;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
