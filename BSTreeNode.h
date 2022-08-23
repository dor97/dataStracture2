#pragma once

#include"Person.h"

class BSTreeNode{

	Person& value;
	BSTreeNode* left, * right, *parent;

public:

	BSTreeNode(Person& p, BSTreeNode *left, BSTreeNode* right, BSTreeNode* parent):value(p),left(left),right(right),parent(parent){}
	~BSTreeNode(){}
	const Person* getValue() { return &value; }
	const long& getPersonId() { return value.get_id(); }
	const string& getPersonName() { return value.get_name(); }
	BSTreeNode* getLeft() {return left; }
	BSTreeNode* getRight() { return right; }
	BSTreeNode* getparent() { return parent; }
	void setLeft(BSTreeNode* node) { left = node; }
	void setRight(BSTreeNode* node){ right = node; }
	void setPerson(const Person& p) const { value = p; }

};
