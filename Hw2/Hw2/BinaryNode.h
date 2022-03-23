#pragma once
#include <iostream>
class BinaryNode
{

public:
	BinaryNode(int x);
	//BinaryNode* getLeftChild();
	//BinaryNode* getRightChild();
	//int getValue();
	//void setLeftChild(BinaryNode* x);
	//void setRightChild(BinaryNode* x);
	//void setValue(int x);

//private:
	BinaryNode* leftChild;
	BinaryNode* rightChild;
	int value;
};

