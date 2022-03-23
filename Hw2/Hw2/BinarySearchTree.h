#pragma once
#include <iostream>
#include "BinaryNode.h"
class BinarySearchTree
{
public:
	BinarySearchTree();
	int getHeight();
	int getHeight2(BinaryNode* root);
	bool isEmpty();
	bool add(int newEntry);
	bool add2(BinaryNode*& root, int newEntry);
	int getNumberOfNodes();
	bool remove(int anEntry);
	bool remove2(BinaryNode* root, int anEntry);
	bool contains(int anEntry);
	void inorderTraverse();
	void inorderTraverse2(BinaryNode* temp);
	int getWidth();
	int getWidth1(BinaryNode* temp);
	int getWidth2(BinaryNode* temp, int lastLevel);
	int count(int a, int b);
	void count2(BinaryNode* temp, int a, int b, int& count);
	int select(int anEntry);
	void select2(int anEntry,BinaryNode* temp,int& count); 
	int successor(int anEntry);
	BinaryNode*  succ(BinaryNode* root,BinaryNode* next, int anEntry);
	BinaryNode* min(BinaryNode* root);
	BinaryNode* findElement(int anEntry,BinaryNode*& parent);

//private:
	BinaryNode* root;
	int height;
	int numNodes;
};

