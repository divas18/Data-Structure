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
*                              WIDTH OF TREE                                 *
******************************************************************************/
int BinarySearchTree :: width()
{
    return width(root_);
}
int BinarySearchTree :: width(Node *ptr)
{
    if(!ptr)
        return 0;

    int wid = 0;
    queue<Node *> qu1, qu2;
    qu1.push(ptr);
    while(!qu1.empty() || !qu2.empty())
    {
        if(!qu1.empty())
        {
            while(!qu1.empty())
            {
                ptr = qu1.front();
                qu1.pop();
                if(ptr->left)
                    qu2.push(ptr->left);
                if(ptr->right)
                    qu2.push(ptr->right);
            }
            if(qu2.size() > wid)
                wid = qu2.size();
        }
        else
        {
            while(!qu2.empty())
            {
                ptr = qu2.front();
                qu2.pop();
                if(ptr->left)
                    qu1.push(ptr->left);
                if(ptr->right)
                    qu1.push(ptr->right);
            }
            if(qu1.size() > wid)
                wid = qu1.size();
        }
    }
    return wid;
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

/******************************************************************************
*                              INORDER SUCCESSOR                              *
******************************************************************************/

int BinarySearchTree :: successor(int key)
{
    Node * successor_ptr = NULL;
    successor(root_, successor_ptr, key);
    return successor_ptr ? successor_ptr->data : -1;
}

void BinarySearchTree :: successor(Node *ptr, Node *&succ, int key)
{
    if(!ptr)
        return;

    if(ptr->data == key)
    {
        if(ptr->right)
            succ = minNode(ptr->right);
    }

    if(ptr->data > key)
    {
        succ = ptr;
        successor(ptr->left, succ, key);
    }
    else
        successor(ptr->right, succ, key);
}

/******************************************************************************
*                              INORDER PREDECESSOR                            *
******************************************************************************/

int BinarySearchTree :: predecessor(int key)
{
    Node * predecessor_ptr = NULL;
    predecessor(root_, predecessor_ptr, key);
    return predecessor_ptr ? predecessor_ptr->data : -1;
}

void BinarySearchTree :: predecessor(Node *ptr, Node *&pre, int key)
{
    if(!ptr)
        return;

    if(ptr->data  == key)
    {
        if(ptr->left)
            pre = maxNode(ptr->left);
    }

    if(ptr->data < key)
    {
        pre = ptr;
        predecessor(ptr->right, pre, key);
    }
    else
        predecessor(ptr->left, pre, key);
}
