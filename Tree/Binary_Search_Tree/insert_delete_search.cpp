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

/******************************************************************************
*                              DELETION                                       *
******************************************************************************/
