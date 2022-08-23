#pragma once

//#include"Person.h"
#include"BSTreeNode.h"

class BSTree {

	BSTreeNode* root;
	int numComp = 0;


	BSTreeNode* getMaxKey(BSTreeNode* node);
public:
	BSTree():root(nullptr){}
	BSTree(BSTreeNode* root): root(root){}
	~BSTree();
	void Insert(Person& p);
	void MakeEmpty(BSTreeNode* node);
	const Person& search(int k);
	const Person* searchKInSize(BSTreeNode* node, int k, int& comp);
	BSTreeNode* Find(long k);
	void Delete(long k);
	void setRoot(BSTreeNode* node);
	bool IsEmpty();
	int getNumComp() { return this->numComp; }

};