#include "binary_search_tree.hpp"

BinarySearchTree :: BinarySearchTree()
{
    root_ = NULL;
}

BinarySearchTree :: ~BinarySearchTree()
{
    destroy(root_);
}

void BinarySearchTree :: preOrder()
{
    preOrder(root_);
}
void BinarySearchTree :: preOrder(Node *node)
{
    if(node)
    {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void BinarySearchTree :: postOrder()
{
    postOrder(root_);
}
void BinarySearchTree :: postOrder(Node *node)
{
    if(node)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

void BinarySearchTree :: inOrder()
{
    inOrder(root_);
}
void BinarySearchTree :: inOrder(Node *node)
{
    if(node)
    {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void BinarySearchTree :: levelOrder()
{
    levelOrder(root_);
}
void BinarySearchTree :: levelOrder(Node *node)
{
    queue<Node*> Q;
    Q.push(node);
    while(!Q.empty())
    {
        node = Q.front();
        Q.pop();
        cout << node->data << " ";
        if(node->left)
            Q.push(node->left);
        if(node->right)
            Q.push(node->right);
    }
}

void BinarySearchTree :: destroy(Node *node)
{
    if(node)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

void BinarySearchTree :: insert(int key)
{
    if(!root_)
    {
        root_ = new Node(key);
        return;
    }
    insert(root_, key);
}
void BinarySearchTree :: insert(Node *node, int key)
{
    if(key < node->data)
    {
        if(node->left)
            insert(node->left, key);
        else
        {
            Node *temp = new Node(key);
            node->left = temp;
        }
    }
    else if(key > node->data)
    {
        if(node->right)
            insert(node->right, key);
        else
        {
            Node *temp = new Node(key);
            node->right = temp;
        }
    }
}

Node * BinarySearchTree :: search(int key)
{
    if(!root_)
    {
        cout << " Tree is empty\n";
        return NULL;
    }
    search(root_, key);
}
Node * BinarySearchTree :: search(Node *node, int key)
{
    if(!node)
        return node;
    if(node->data < key)
        return search(node->right, key);
    if(node->data > key)
        return search(node->left, key);
    return node;
}

Node * BinarySearchTree :: minValue()
{
    return minValueNode(root_);
}
Node * BinarySearchTree :: minValueNode(Node *node)
{
    if(node->left)
        return minValueNode(node->left);
    return node;
}

Node * BinarySearchTree :: maxValue()
{
    return maxValueNode(root_);
}
Node * BinarySearchTree :: maxValueNode(Node *node)
{
    if(node->right)
        return maxValueNode(node->right);
    return node;
}
