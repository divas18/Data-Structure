#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>
#include <queue>
#include <deque>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

struct BinaryTree
{
private:
    Node *root_;
    void insert(Node *node, int key);
    void preOrder(Node *node);
    void postOrder(Node *node);
    void inOrder(Node *node);
    void levelOrder(Node *node);
    void destroy(Node *node);
public:
    BinaryTree();
    ~BinaryTree();
    void insert(int key);
    void preOrder();
    void postOrder();
    void inOrder();
    void levelOrder();
    void nonRecPreOrder();
    void nonRecPostOrder();
    void nonRecInOrder();
};

#endif
