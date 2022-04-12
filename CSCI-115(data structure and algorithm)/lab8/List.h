#include <iostream>
using namespace std;

class Node
{
public:
	Node(int data)
	{
		this->data = data;
		this->LeftChild = NULL;
		this->RightChild = NULL;
	};
	int data;
	Node* LeftChild;
	Node* RightChild;
};

class BST
{
private:
	Node* root;

public:
	BST();
	Node* getRoot() { return this->root; };
	void printTree(Node* root);
	Node* InsertNode(Node* node, int data);
	bool FindNode(Node* root, int data);
	int Largest(Node* root);
};
BST::BST()
{
	root = NULL;
}
void BST::printTree(Node* root)
{
	if (root->LeftChild)
		printTree(root->LeftChild);
	if (root->RightChild)
		printTree(root->RightChild);
	cout << root->data << " ";
}
Node* BST::InsertNode(Node* node, int data)
{

	if (!node)
	{
		node = new Node(data);
	}
	else if (node->data > data)
		node->LeftChild = InsertNode(node->LeftChild, data);
	else
		node->RightChild = InsertNode(node->RightChild, data);
	root = node;
	return node;
}
bool BST::FindNode(Node* root, int data)
{
	if (!root)
		return false;
	else if (root->data == data)
	{
		cout << data<<endl;
	}
	else
	{
		if (root->data < data)
			return FindNode(root->RightChild, data);
		else
			return FindNode(root->LeftChild, data);
	}
	return true;
}
int BST::Largest(Node* root)
{
	int num;
	if (root->RightChild)
		num = Largest(root->RightChild);
	else
		num = root->data;
	return num;
}