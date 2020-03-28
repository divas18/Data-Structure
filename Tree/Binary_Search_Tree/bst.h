#ifndef BST_H
#define BST_H

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
	Node(int key)
	{
		data = key;
		left = right =NULL;
	}
};

class BinarySearchTree
{

private:
	Node *	root_;
	void 	inorder(Node *ptr);
	void 	preorder(Node *ptr);
	void 	postorder(Node *ptr);
	void 	insert(Node *ptr, int key);
	int 	height(Node *ptr);
	Node *	minNode(Node *ptr);
	Node *	maxNode(Node *ptr);
	Node * search(Node *ptr, int key);

public:
	BinarySearchTree()
	{
		root_ = NULL;
	}
	void 	insert(int key);
	void 	inorder();
	void 	preorder();
	void 	postorder();
	int 	height();
	Node *	minNode();
	Node *	maxNode();
	Node * search(int key);
	int 	successor(int key);
	int 	predecessor(int key);
};

#endif