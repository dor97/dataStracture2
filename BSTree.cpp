#include"BSTree.h"
//-----------------------------------------------------------------------------------------------------------
BSTree::~BSTree()
{
	if (root != nullptr)
		MakeEmpty(root);
}
//-----------------------------------------------------------------------------------------------------------
//The function return True if the tree is empty, else return False
bool BSTree::IsEmpty()
{
	return root == nullptr;
}
//-----------------------------------------------------------------------------------------------------------
//The function make a tree empty
void BSTree::MakeEmpty(BSTreeNode* node)
{
	if (node == nullptr)
		return;
	MakeEmpty(node->getLeft());
	MakeEmpty(node->getRight());
	delete node;
}
//-----------------------------------------------------------------------------------------------------------
//The function find a node by a given key
BSTreeNode* BSTree::Find(long k)
{
	BSTreeNode* temp = root;
	while (temp != nullptr)
	{
		if (k == temp->getPersonId())
			return temp;
		else if (k < temp->getPersonId())
			temp = temp->getLeft();
		else
			temp = temp->getRight();
	}
	return nullptr;
}
//-----------------------------------------------------------------------------------------------------------
//The function insert a new node into the tree
void BSTree::Insert(Person& p)
{
	BSTreeNode* temp = root;
	BSTreeNode* parent = nullptr;
	BSTreeNode* newnode;

	while (temp != nullptr)
	{
		parent = temp;
		++numComp;
		if (*temp->getValue() == p)
			throw("Invalid input");
		++numComp;
		if (p.get_id() < temp->getPersonId())
			temp = temp->getLeft();
		else
			temp = temp->getRight();
	}
	newnode = new BSTreeNode(p, nullptr, nullptr, parent);
	if (parent == nullptr)
		root = newnode;
	else
	{
		++numComp;
		if (p.get_id() < parent->getPersonId())
			parent->setLeft(newnode);
		else
			parent->setRight(newnode);
	}
}
//-----------------------------------------------------------------------------------------------------------
//The function return the node with the biggest key
BSTreeNode* BSTree::getMaxKey(BSTreeNode* node)
{
	while (node->getRight() != nullptr)
		node = node->getRight();
	return node;
}
//-----------------------------------------------------------------------------------------------------------
//The function delete a node using a given key
void BSTree::Delete(long k)
{
	BSTreeNode* curr = Find(k);

	if (curr == nullptr)
		return;

	// Case 1: node to be deleted has no children, i.e., it is a leaf node
	if (curr->getLeft() == nullptr && curr->getRight() == nullptr)
	{
		if (curr != root)
		{
			if (curr->getparent()->getLeft() == curr)
				curr->getparent()->setLeft(nullptr);
			else
				curr->getparent()->setRight(nullptr);
		}
		// if the tree has only a root node, set it to null
		else
			this->setRoot(nullptr);		//in case it is a new tree created in case 2		
		delete(curr);
	}

	// Case 2: node to be deleted has two children
	else if (curr->getLeft() != nullptr && curr->getRight() != nullptr)
	{
		BSTree successor((getMaxKey(curr->getLeft())));	//creat a new tree with the max node as it's root

		curr->setPerson(*successor.root->getValue());

		successor.Delete(successor.root->getValue()->get_id());
		successor.root = nullptr;
	}
	// Case 3: node to be deleted has only one child
	else {

		BSTreeNode* child = (curr->getLeft()) ? curr->getLeft() : curr->getRight();
		if (curr != root)
		{
			if (curr == curr->getparent()->getLeft())
				curr->getparent()->setLeft(child);
			else
				curr->getparent()->setRight(child);
		}

		// if the node to be deleted is a root node, then set the root to the child
		else
			this->setRoot(child);	//in case it is a new tree created in case 2

		delete(curr);
	}
}
//-----------------------------------------------------------------------------------------------------------
//The function set the root to a given node (or null)
void BSTree::setRoot(BSTreeNode* node)
{
	if (root->getparent() == nullptr)
		root = node;
	else
	{
		if (root->getparent()->getLeft() == root)
			root->getparent()->setLeft(node);
		else
			root->getparent()->setRight(node);
	}
}
//-----------------------------------------------------------------------------------------------------------
//The function is a shell function for searching  the k in size person
const Person& BSTree::search(int k)
{
	int comp = 0;
	return *searchKInSize(root, k, comp);
}
//-----------------------------------------------------------------------------------------------------------
//The function search the k in size person
const Person* BSTree::searchKInSize(BSTreeNode* node, int k, int& comp)
{
	const Person* res = nullptr;
	if (node == nullptr)
		return res;
	res = searchKInSize(node->getLeft(), k, comp);
	if (res != nullptr)
		return res;
	if (k == comp++)
	{
		++numComp;
		return node->getValue();
	}
	return searchKInSize(node->getRight(), k, comp);
}
//-----------------------------------------------------------------------------------------------------------
