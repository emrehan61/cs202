#include "BinarySearchTree.h"
BinarySearchTree::BinarySearchTree(){
	root = NULL;
	height = 0;
	numNodes = 0;
}
int BinarySearchTree::getHeight2(BinaryNode* root) {


	if (root == NULL) return 0;

	else {
		int r1 = getHeight2(root->rightChild);
		int l1 = getHeight2(root->leftChild);

		return (r1 > l1) ? (r1+1) : (l1+1);
	}
	
}
int BinarySearchTree::getHeight() {
	return getHeight2(root);
}


int BinarySearchTree::getNumberOfNodes() {
	return numNodes;
}

bool BinarySearchTree::isEmpty() {
	if (root == NULL ) return true;

	else return false;
}

bool BinarySearchTree::add(int newEntry) {
	return add2(root, newEntry);
}
bool BinarySearchTree::add2(BinaryNode*& root, int newEntry){
	BinaryNode** temp = &root; 
	if (newEntry <= 0) return false;
	
	else {
	

		if (root == NULL) {
			root = new BinaryNode(newEntry);
			numNodes++;
			return true;
		}
		else {
			//std::cout << temp << " " << &root << " " << *temp << " " << root<<" "<<&((*temp)->rightChild)<<" "<<root->rightChild<<" ";
			if (newEntry > root->value) {
				return add2(root->rightChild, newEntry);
			}
			else {
				return add2(root->leftChild, newEntry);
			}
		}
	}
	
}
bool BinarySearchTree::contains(int anEntry) {
	BinaryNode* temp = root;
	while (temp != NULL){
		if (temp->value == anEntry) return true;
		else {
			if (anEntry > temp->value) {

				temp = temp->rightChild;
			}
			else {
				temp = temp->leftChild;
			}
		}
	}
	return false;
}
/*we need to find parent too, if we are deleting the leaf thats why there is a aprent parameter */
BinaryNode* BinarySearchTree::findElement(int anEntry,BinaryNode*& parent) {
	if (contains(anEntry)) { 
		BinaryNode* temp = root;
		while(temp != NULL) {
			if (temp->value == anEntry) return temp;
			else {
				if (anEntry > temp->value) {
					parent = temp;
					temp = temp->rightChild;
				}
				else {
					parent = temp; 
					temp = temp->leftChild;
				}
			}
		}
	}
	return NULL;
}

bool BinarySearchTree::remove(int anEntry) {
	BinaryNode* temp = root;
	return remove2(temp , anEntry); 
}

bool BinarySearchTree::remove2(BinaryNode* root, int anEntry) {
	if (anEntry <= 0 || !contains(anEntry)) return false; // check if bst has that value 
	else {
		BinaryNode* parent = NULL;
		root  = findElement(anEntry, parent);
		if (root->rightChild == NULL && root->leftChild == NULL) { // if node has no child 
			if (parent->leftChild == root) parent->leftChild = NULL;
			else parent->rightChild = NULL;
			delete root;
			root = NULL;
			numNodes--; 
			return true; 
		}
		else if (root->rightChild == NULL) {// if has only left child 
			root->value = root->leftChild->value;

			BinaryNode* temp = root->leftChild->leftChild;
			delete root->leftChild;
			root->leftChild = temp;
			numNodes--;
			return true; 

		}
		else if (root->leftChild == NULL) {// if has only right child
		
			root->value = root->rightChild->value;
		
			BinaryNode* temp = root->rightChild->rightChild;
			delete root->rightChild;
			root->rightChild = temp;
			numNodes--; 
			return true; 
		}
		else {
			BinaryNode* temp = root; 
			if(temp->rightChild != NULL)	temp = min(temp->rightChild);
	
			std::cout <<"  asd: "<< temp->value<<"end of temp value: "<< root->value;
			root->value = temp->value;
			if (temp->rightChild != NULL) {
				BinaryNode* temp2 = temp->rightChild;
				root->rightChild = temp2; 
			}
			delete temp;
			temp = NULL; 
			numNodes--; 
			return true; 
		}
	}
}

int BinarySearchTree::getWidth(){
	BinaryNode* temp = root;
	return getWidth1(temp);
}
int BinarySearchTree::getWidth1(BinaryNode* temp){
	int width1 = 0;
	int width;
	int h = getHeight();
	int i;

	for (i = 1; i <= h; i++) {
		width = getWidth2(temp, i);
		if (width > width1)
			width1 = width;
	}

	return width1;
}
int BinarySearchTree::getWidth2(BinaryNode* temp, int lastLevel){
	if (temp == NULL)
		return 0;

	if (lastLevel == 1)
		return 1;

	else if (lastLevel > 1)
		return getWidth2(temp->leftChild, lastLevel - 1) + getWidth2(temp->rightChild, lastLevel - 1);

	else return 0;
}

void BinarySearchTree::inorderTraverse2(BinaryNode* temp) {
	if (temp != NULL) {
		
		inorderTraverse2(temp->leftChild);


		std::cout << temp->value << " ";


		inorderTraverse2(temp->rightChild);
		
	}
		

	
	
}
void BinarySearchTree::inorderTraverse() {

	inorderTraverse2(root);
}

int BinarySearchTree::count(int a, int b){
	int count = 0; 
	count2(root, a, b, count);
	return count;

}

void BinarySearchTree::count2(BinaryNode* temp, int a, int b, int& count) {

	if (temp != NULL)
	{
		if (temp->value >= a)
		{
			count2(temp->leftChild, a, b, count);
		}
		if (temp->value >= a && temp->value <= b)
		{
			count++;
		}
		if (temp->value <= b)
		{
			count2(temp->rightChild, a, b, count);
		}
	
	}

}
BinaryNode* BinarySearchTree::min(BinaryNode* root) {
	while (root->leftChild != NULL) root = root->leftChild;
	return root;

}

int BinarySearchTree::successor(int anEntry) {
	if (!contains(anEntry)) return -1; // bst does not contain that key 
	else {
		BinaryNode* temp = NULL;
		temp = succ(root, temp, anEntry);
		if (temp == NULL) return -2;
		else return temp->value;
	}
}
BinaryNode* BinarySearchTree::succ(BinaryNode* root,BinaryNode* next, int anEntry) {
	if (root == nullptr) {
		return next;
	}
	if (root->value == anEntry)
	{
		if (root->rightChild != NULL) {
			return min(root->rightChild);
		}
	}
	else if (anEntry < root->value)
	{
		next = root;
		return succ(root->leftChild, next, anEntry);
	}
	else {
		return succ(root->rightChild, next,anEntry);
	}

	return next;
}

int BinarySearchTree::select(int anEntry) {
	int index = -1; 
	select2(anEntry, root, index);
	return index;
}

void BinarySearchTree::select2(int anEntry,BinaryNode* temp,int& count ) {
	
	if (!contains(anEntry)) return ;
	else {
		int tmp = min(root)->value;
		if (anEntry == tmp) {
				
			count = 0;
			return; 
		}
		else {
			count = 0;
			while (anEntry != tmp) {
				tmp = successor(tmp);
				count++;
			}
			
			
		}

	}
}
