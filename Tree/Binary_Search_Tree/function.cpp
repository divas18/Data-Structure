#include "bst.h"


/******************************************************************************
*                              INSERTION                                      *
******************************************************************************/

void BinarySearchTree :: insert(int key)
{
    if(!root_)
    {
        root_ = new Node(key);
        return;
    }
    insert(root_, key);
}

void BinarySearchTree :: insert(Node *ptr, int key)
{
    if(key < ptr->data)
    {
        if(ptr->left)
            insert(ptr->left, key);
        else
            ptr->left = new Node(key);
    }
    else if(key > ptr->data)
    {
        if(ptr->right)
            insert(ptr->right, key);
        else
            ptr->right = new Node(key);
    }
}
/******************************************************************************
*                              SEARCHING                                      *
******************************************************************************/

Node * BinarySearchTree :: search(int key)
{
    return search(root_, key);
}

Node * BinarySearchTree :: search(Node *ptr, int key)
{
    if(!ptr)
        return ptr;

    if(ptr->data == key)
        return ptr;

    if(ptr->data < key)
        return search(ptr->right, key);

    return search(ptr->left, key);
}
                        /*************************
                        *        ITERATIVE       *
                        *************************/
/*
Node * BinarySearchTree :: search(Node *ptr, int key)
{
    while(ptr)
    {
        if(ptr->data == key)
            break;

        else if(ptr->data < key)
            ptr = ptr->right;

        else
            ptr = ptr->left;
    }
    return ptr;
}
*/

/******************************************************************************
*                              DELETION                                       *
******************************************************************************/


/******************************************************************************
*                              HEIGHT OF TREE                                 *
******************************************************************************/
int BinarySearchTree :: height()
{
    return height(root_);
}

int BinarySearchTree :: height(Node *ptr)
{
    if(ptr)
    {
        int height_left  = height(ptr->left);
        int height_right = height(ptr->right);
        return 1 + max(height_left, height_right);
    }
    return 0;
}

/******************************************************************************
*                              NODE WITH MINIMUM VALUE                        *
******************************************************************************/

                        /*************************
                        *        RECURSIVE       *
                        *************************/

Node * BinarySearchTree :: minNode()
{
    if(!root_)
        return root_;
    return  minNode(root_);
}

Node * BinarySearchTree :: minNode(Node *ptr)
{
    if(ptr->left)
        return minNode(ptr->left);
    return ptr;
}
                        /*************************
                        *        ITERATIVE       *
                        *************************/
/*
Node * BinarySearchTree :: minNode(Node *ptr)
{
    while(ptr->left)
        ptr = ptr->left;
    return ptr;
}
*/

/******************************************************************************
*                              NODE WITH MAXIMUM VALUE                        *
******************************************************************************/
Node * BinarySearchTree :: maxNode()
{
    if(!root_)
        return root_;
    return maxNode(root_);
}

Node * BinarySearchTree :: maxNode(Node *ptr)
{
    if(ptr->right)
        return maxNode(ptr->right);
    return ptr;
}
                        /*************************
                        *        ITERATIVE       *
                        *************************/
/*
Node * BinarySearchTree :: maxNode(Node *ptr)
{
    while(ptr->right)
        ptr = ptr->right;
    return ptr;
}
*/


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
