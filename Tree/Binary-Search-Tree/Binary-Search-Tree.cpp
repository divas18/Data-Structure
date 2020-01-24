/**
 * @Author: ADITYA KUMAR SINGH <martian>
 * @Date:   2020-01-19T16:52:55+05:30
 * @Email:  cr7.aditya.cs@gmail.com
 * @Last modified by:   martian
 */

#include <iostream>
#include "../Helper/List.h"
#include <stack>
#include <queue>
#include <new>
using namespace std;

struct node
{
    int key;
    node *left, *right;
};

class BinarySearchTree
{
private:
    node *root;
    void insert(int key, node *leaf);
    void preorder(node *leaf);
    void inorder(node *leaf);
    void postorder(node *leaf);
    void destroy_tree(node *leaf);
    void levelorder(node *leaf);
    node * in_pre_tree(ListNode *in, ListNode *pre, int n);
    node * in_post_tree(ListNode *in, ListNode *post, int n);
    int count(node *leaf);
    int height(node *leaf);
    node * search(node *leaf,int key);
    node * MinValueNode(node *leaf);
    node * MaxValueNode(node *leaf);
    node * Delete(node *leaf, int key);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(int key);
    void preorder();
    void inorder();
    void postorder();
    void levelorder();
    void in_pre_to_tree(ListNode *in, ListNode *pre, int n);
    void in_post_to_tree(ListNode *in, ListNode *post, int n);
    int count();
    int height();
    node * search(int key);
    int MinValue();
    int MaxValue();
    void Delete(int key);
};

int main()
{
    BinarySearchTree b;
    int key, option, n, temp;
    List inorder, postorder, preorder;
    cout << " Lets create Binary Search Tree\n";
    cout << " 1.\tUsing insertion (BinarySearchTree will be created)\n";
    cout << " 2.\tUsing preorder and inorder\n";
    cout << " 3.\tUsing postorder and inorder\n";
    cout << " Option: ";
    cin >> option;
    switch(option)
    {
        case 1 :
            cout << " Enter 0 to stop inserting\n";
            while(1)
            {
                cout << " :";
                cin >> key;
                if(!key)
                    break;
                b.insert(key);
            }
            break;
        case 2:
            cout << " Size of tree : ";
            cin >> n;
            cout << " Enter Inorder\n :";
            for(int i = 0; i < n; i++)
            {
                cin >> temp;
                inorder.create(temp);
            }
            cout << " Enter Preorder\n :";
            for(int i = 0; i < n; i++)
            {
                cin >> temp;
                preorder.create(temp);
            }
            b.in_pre_to_tree(inorder.head, preorder.head, n);
            break;
        case 3:
            cout << " Size of tree : ";
            cin >> n;
            cout << " Enter Inorder\n :";
            for(int i = 0; i < n; i++)
            {
                cin >> temp;
                inorder.create(temp);
            }
            cout << " Enter Postorder\n :";
            for(int i = 0; i < n; i++)
            {
                cin >> temp;
                postorder.create(temp);
            }
            b.in_post_to_tree(inorder.head, postorder.head, n);
            break;
    }
    while(1)
    {
        cout << " 0.\tExit\n";
        cout << " 1.\tInsert\n";
        cout << " 2.\tPreorder\n";
        cout << " 3.\tInorder\n";
        cout << " 4.\tPostorder\n";
        cout << " 5.\tLevelorder\n";
        cout << " 6.\tNo of nodes\n";
        cout << " 7.\tHeight of tree\n";
        cout << " 8.\tSearch\n";
        cout << " 9.\tMinimum value in Tree\n";
        cout << " 10.\tMaximum value in Tree\n";
        cout << " 11.\tDelete\n";
        cout << " Option: ";
        cin >> option;
        switch(option)
        {
            case 0:
                exit(0);
            case 1:
                cout << " data to insert : ";
                cin >> key;
                b.insert(key);
                cout << "\n";
                break;
            case 2:
                b.preorder();
                cout << "\n";
                break;
            case 3:
                b.inorder();
                cout << "\n";
                break;
            case 4:
                b.postorder();
                cout <<"\n";
                break;
            case 5:
                b.levelorder();
                cout << "\n";
                break;
            case 6:
                cout << " No of nodes : " << b.count() << "\n";
                break;
            case 7:
                cout << " Height of Tree : " << b.height() << "\n";
                break;
            case 8:
                cout << " Data to search : ";
                cin >> key;
                cout << " Found at " << b.search(key) << "\n";
                break;
            case 9:
                cout << " Minimum value in tree : " << b.MinValue() << "\n";
                break;
            case 10:
                cout << " Maximum value in tree : " << b.MaxValue() << "\n";
                break;
            case 11:
                cout << " Data to delete : ";
                cin >> key;
                b.Delete(key);
                break;
            default:
                cout <<"\n";
                break;
        }
    }

}
//private function
void BinarySearchTree::destroy_tree(node *leaf)
{
    if(leaf)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}
void BinarySearchTree::insert(int key, node *leaf)
{
    if(key < leaf->key)
    {
        if(leaf->left)
            insert(key, leaf->left);
        else
        {
            node *temp = new node;
            temp->key = key;
            temp->left = NULL;
            temp->right = NULL;
            leaf->left = temp;
        }
    }
    else if(key > leaf->key)
    {
        if(leaf->right)
            insert(key, leaf->right);
        else
        {
            node *temp = new node;
            temp->key = key;
            temp->left = NULL;
            temp->right = NULL;
            leaf->right = temp;
        }
    }
}
void BinarySearchTree::preorder(node *leaf)
{
    if(leaf)
    {
        cout << " " << leaf->key;
        preorder(leaf->left);
        preorder(leaf->right);
    }
}
void BinarySearchTree::inorder(node *leaf)
{
    if(leaf)
    {
        inorder(leaf->left);
        cout << " " << leaf->key;
        inorder(leaf->right);
    }
}
void BinarySearchTree::postorder(node *leaf)
{
    if(leaf)
    {
        postorder(leaf->left);
        postorder(leaf->right);
        cout << " " << leaf->key;
    }
}
void BinarySearchTree::levelorder(node *leaf)
{
        queue<node*> q;
        q.push(leaf);
        node *temp;
        while(!q.empty())
        {
            temp = q.front();
            cout << " " << temp->key;
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
}
node * BinarySearchTree::in_pre_tree(ListNode *in, ListNode *pre, int n)
{
    if(n==0)
        return NULL;
    node *temp = new node;
    temp->key = pre->data;
    temp->left =  NULL;
    temp->right = NULL;
    if(n == 1)
        return temp;
    ListNode *q = in;
    int i;
    for(i = 0; q->data != pre->data; i++)
        q = q->next;
    temp->left = in_pre_tree(in, pre->next, i);
    for(int j = 1; j <= i+1; j++)
        pre = pre->next;
    temp->right = in_pre_tree(q->next, pre, n-i-1);
    return temp;
}
node * BinarySearchTree::in_post_tree(ListNode *in, ListNode *post, int n)
{
    if(n==0)
        return NULL;
    ListNode *ptr, *q;
    int i,j;
    ptr = post;
    for(i=1;i<n;i++)
        ptr = ptr->next;
    node *temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->key = ptr->data;
    if(n==1)
        return temp;
    q = in;
    for(i = 0; q->data != ptr->data; i++)
        q = q->next;
    temp->left = in_post_tree(in, post, i);
    for(j = 1; j <= i; j++)
        post = post->next;
    temp->right = in_post_tree(q->next, post, n-i-1);
    return temp;
}
int BinarySearchTree::count(node *leaf)
{
    if(!leaf)
        return 0;
    return 1 + count(leaf->left) + count(leaf->right);
}
int BinarySearchTree::height(node *leaf)
{
    if(!leaf)
        return 0;
    int x = height(leaf->left);
    int y = height(leaf->right);
    if(x > y)
        return x + 1;
    return y + 1;
}
node * BinarySearchTree::search(node *leaf, int key)
{
    if(!leaf)
        return NULL;
    if(leaf->key == key)
        return leaf;
    if(leaf->key < key)
        return search(leaf->right, key);
    return search(leaf->left, key);
}
node * BinarySearchTree::MinValueNode(node *leaf)
{
    if(leaf->left == NULL)
        return leaf;
    return MinValueNode(leaf->left);
}
node * BinarySearchTree::MaxValueNode(node *leaf)
{
    if(leaf->right == NULL)
        return leaf;
    return MaxValueNode(leaf->right);
}
node * BinarySearchTree::Delete(node *leaf, int key)
{
    if(!leaf)
        return NULL;
    if(leaf->key > key)
         leaf->left = Delete(leaf->left, key);
    else if(leaf->key < key)
         leaf->right = Delete(leaf->right, key);
    else
    {
        if(leaf->left == NULL)
        {
            node *temp = leaf->right;
            delete leaf;
            return temp;
        }
        else if(leaf->right == NULL)
        {
            node *temp = leaf->left;
            delete leaf;
            return temp;
        }
        node *temp = MinValueNode(leaf->right);
        leaf->key = temp->key;
        leaf->right =Delete(leaf->right, leaf->key);

    }
    return leaf;
}
//public function
BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}
BinarySearchTree::~BinarySearchTree()
{
    destroy_tree(root);
}
void BinarySearchTree::insert(int key)
{
    if(root)
        insert(key, root);
    else
    {
        root = new node;
        root->key = key;
        root->left = NULL;
        root->right = NULL;
    }
}
void BinarySearchTree::preorder()
{
    if(!root)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << " Preorder\n :";
    preorder(root);
}
void BinarySearchTree::inorder()
{
    if(!root)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << " Inorder\n :";
    inorder(root);
}
void BinarySearchTree::postorder()
{
    if(!root)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << " Postordere\n :";
    postorder(root);
}
void BinarySearchTree::levelorder()
{
    if(!root)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << " Levelorder\n :";
    levelorder(root);
}
void BinarySearchTree::in_pre_to_tree(ListNode *in, ListNode *pre, int n)
{
    root = in_pre_tree(in,pre,n);
}
void BinarySearchTree::in_post_to_tree(ListNode *in, ListNode *post, int n)
{
    root = in_post_tree(in, post, n);
}
int BinarySearchTree::count()
{
    return count(root);
}
int BinarySearchTree::height()
{
    return height(root);
}
node * BinarySearchTree::search(int key)
{
    return search(root, key);
}
int BinarySearchTree::MinValue()
{
    if(!root)
        return -1;
    return MinValueNode(root)->key;
}
int BinarySearchTree::MaxValue()
{
    if(!root)
        return -1;
    return MaxValueNode(root)->key;
}
void BinarySearchTree::Delete(int key)
{
    root = Delete(root,key);
}
