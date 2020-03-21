#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

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

struct BinarySearchTree
{
private:
    Node *root_;
    void insert(Node *node, int key);
    void preOrder(Node *node);
    void postOrder(Node *node);
    void inOrder(Node *node);
    void levelOrder(Node *node);
    void destroy(Node *node);
    Node * search(Node *node,int key);
    Node * minValueNode(Node *node);
    Node * maxValueNode(Node *node);
    Node * Delete(Node *node, int key);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(int key);
    void preOrder();
    void postOrder();
    void inOrder();
    void levelOrder();
    Node * search(int key);
    Node * minValue();
    Node * maxValue();
    void Delete(int key);
};

#endif
