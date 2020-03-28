#include "bst.h"

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
