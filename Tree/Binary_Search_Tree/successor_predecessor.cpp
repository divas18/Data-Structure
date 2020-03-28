#include "bst.h"

/******************************************************************************
*                              INORDER SUCCESSOR                              *
******************************************************************************/

int BinarySearchTree :: successor(int key)
{
    Node * successor_ptr;
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
    Node * predecessor_ptr;
    predecessor(root_, predecessor_ptr, key);
    return predecessor_ptr ? predecessor_ptr->data : -1;
}

void BinarySearchTree :: predecessor(Node *ptr, Node *&pre, int key)
{
    if(!root_)
        return;

    if(ptr->data  == key)
    {
        if(ptr->left)
            pre = maxNode(ptr->right);
    }

    if(ptr->data < key)
    {
        pre = ptr;
        predecessor(ptr->right, pre, key);
    }
    else
        predecessor(ptr->left, pre, key);
}
