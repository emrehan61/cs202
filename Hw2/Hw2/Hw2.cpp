
#include "BinarySearchTree.h"
#include <iostream>
#define BST BinarySearchTree
int main()
{
    BST* temp = new BST();
    temp->add(3);
    temp->add(1);
    temp->add(2);
    temp->add(4);
    temp->add(5);
    temp->add(6);
    temp->add(7);
    std::cout <<" " << temp->getHeight()<<" ";
    temp->inorderTraverse();
    std::cout << " node " << temp->getNumberOfNodes() << " ";
    std::cout << temp->remove(8);
    std::cout << temp->remove(2)<<" ";
    temp->inorderTraverse();
    std::cout << temp->count(1,7);
    std::cout << " " << temp->successor(9);
    std::cout << " Select Index Check: " << temp->select(9);
    std::cout << "\n END \n";
}

