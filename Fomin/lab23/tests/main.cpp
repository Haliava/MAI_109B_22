#include "../include/Tree.hpp"

int main() {
	Tree<int> tree = new Tree<int>(20);

	tree->addNode(10);
	tree->addNode(30);
	tree->addNode(5);
	tree->addNode(15);
	tree->addNode(15);
	tree->addNode(25);
	tree->addNode(17);

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
	/*
				 20
			  /      \
			 10      30
			/  \    /
		   5   15  25
				 
    */

	tree->addNode(17);
	tree->deleteNode(15);
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
	/*
				 20
			  /      \
			 15      30
			/  \    /
		   5   17  25
	*/

	tree->deleteNode(20);
	/*
				 25
			  /      \
			 15      30
			/  \  
		   5   17
	*/

	// 2
	cout << tree->getDepthOfSmallestNode() << endl;

	tree->addNode(100);
	tree->addNode(1);
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
	cout << tree->getDepthOfSmallestNode() << endl;

	return 0;
}