#include "bst.h"


/******************************************************************************
*                              INORDER TRAVERSAL                              *
******************************************************************************/

void BinarySearchTree :: inorder()
{
	if(!root_)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << "\n ---Inorder---\n :";
    inorder(root_);
    cout << "\n";
}

void BinarySearchTree :: inorder(Node *ptr)
{
	if(ptr)
    {
        inorder(ptr->left);
        cout << " " << ptr->data;
        inorder(ptr->right);
    }
}

/******************************************************************************
*                            PREORDER TRAVERSAL                               *
******************************************************************************/

void BinarySearchTree :: preorder()
{
	if(!root_)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << "\n ---Preorder---\n :";
    preorder(root_);
    cout << "\n";
}

void BinarySearchTree ::preorder(Node *ptr)
{
	if(ptr)
    {
        cout << " " << ptr->data;
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

/******************************************************************************
*                              POSTORDER TRAVERSAL                            *
******************************************************************************/

void BinarySearchTree :: postorder()
{
	if(!root_)
	{
		cout << " Tree is empty\n";
		return;
	}
	cout << "\n ---Postorder---\n :";
	postorder(root_);
	cout << "\n";
}

void BinarySearchTree :: postorder(Node *ptr)
{
	if(ptr)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout << " " << ptr->data;
	}
}

/******************************************************************************
*                              LEVELORDER TRAVERSAL                           *
******************************************************************************/

void BinarySearchTree :: levelorder()
{
	if(!root_)
	{
		cout << " Tree is empty\n";
		return;
	}

	cout << "\n ---Levelorder---\n :";
	queue<Node *> qu;
	qu.push(root_);
	Node * ptr;
	while(!qu.empty())
	{
		ptr = qu.front();
		qu.pop();
		cout << " " << ptr->data;
		if(ptr->left)
			qu.push(ptr->left);
		if(ptr->right)
			qu.push(ptr->right);
	}
	cout  << "\n";
}
