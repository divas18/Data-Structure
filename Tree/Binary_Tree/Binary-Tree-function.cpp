#include "Binary-tree.hpp"

BinaryTree :: BinaryTree()
{
    root_ = NULL;
}

BinaryTree :: ~BinaryTree()
{
    destroy(root_);
}

void BinaryTree :: preOrder()
{
    preOrder(root_);
}
void BinaryTree :: preOrder(Node *node)
{
    if(node)
    {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void BinaryTree :: postOrder()
{
    postOrder(root_);
}
void BinaryTree :: postOrder(Node *node)
{
    if(node)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

void BinaryTree :: inOrder()
{
    inOrder(root_);
}
void BinaryTree :: inOrder(Node *node)
{
    if(node)
    {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void BinaryTree :: levelOrder()
{
    levelOrder(root_);
}
void BinaryTree :: levelOrder(Node *node)
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

void BinaryTree :: destroy(Node *node)
{
    if(node)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}


void BinaryTree :: insert(int key)
{
    if(!root_)
    {
        root_ = new Node(key);
        return;
    }
    insert(root_, key);
}

void BinaryTree :: insert(Node *node, int key)
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

void BinaryTree :: nonRecPreOrder()
{
    if(!root_)
    {
        cout << " Tree is empty\n";
        return;
    }
    deque<Node *> Q;
    Node *temp;
    Q.push_front(root_);
    while(!Q.empty())
    {
        temp = Q.front();
        Q.pop_front();
        cout << temp->data << " ";
        if(temp->right)
            Q.push_front(temp->right);
        if(temp->left)
            Q.push_front(temp->left);
    }
}

void BinaryTree :: nonRecInOrder()
{
    if(!root_)
    {
        cout << " Tree is empty\n";
        return;
    }
    deque<Node *> Q;
    Node *temp;
    Q.push_front(root_);
    while(!Q.empty())
    {
        temp = Q.front();
        Q.pop_front();

    }
}

void BinaryTree :: nonRecPostOrder()
{
    
}
