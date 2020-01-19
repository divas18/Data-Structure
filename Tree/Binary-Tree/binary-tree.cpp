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

class binaryTree
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
public:
    binaryTree();
    ~binaryTree();
    void insert(int key);
    void preorder();
    void inorder();
    void postorder();
    void levelorder();
    void in_pre_to_tree(ListNode *in, ListNode *pre, int n);
    void in_post_to_tree(ListNode *in, ListNode *post, int n);
};

int main()
{
    binaryTree b;
    int key, option, n, temp;
    List inorder, postorder, preorder;
    cout << " Lets create Binary Tree\n";
    cout << " 1.\tUsing insertion (BST will be created)\n";
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
            default:
                cout <<"\n";
                break;
        }
    }

}
//private function
void binaryTree::destroy_tree(node *leaf)
{
    if(leaf)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}
void binaryTree::insert(int key, node *leaf)
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
void binaryTree::preorder(node *leaf)
{
    if(leaf)
    {
        cout << " " << leaf->key;
        preorder(leaf->left);
        preorder(leaf->right);
    }
}
void binaryTree::inorder(node *leaf)
{
    if(leaf)
    {
        inorder(leaf->left);
        cout << " " << leaf->key;
        inorder(leaf->right);
    }
}
void binaryTree::postorder(node *leaf)
{
    if(leaf)
    {
        postorder(leaf->left);
        postorder(leaf->right);
        cout << " " << leaf->key;
    }
}
void binaryTree::levelorder(node *leaf)
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
node * binaryTree::in_pre_tree(ListNode *in, ListNode *pre, int n)
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
node * binaryTree::in_post_tree(ListNode *in, ListNode *post, int n)
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


//public function
binaryTree::binaryTree()
{
    root = NULL;
}
binaryTree::~binaryTree()
{
    destroy_tree(root);
}
void binaryTree::insert(int key)
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
void binaryTree::preorder()
{
    if(!root)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << " Preorder\n :";
    preorder(root);
}
void binaryTree::inorder()
{
    if(!root)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << " Inorder\n :";
    inorder(root);
}
void binaryTree::postorder()
{
    if(!root)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << " Postordere\n :";
    postorder(root);
}
void binaryTree::levelorder()
{
    if(!root)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << " Levelorder\n :";
    levelorder(root);
}
void binaryTree::in_pre_to_tree(ListNode *in, ListNode *pre, int n)
{
    root = in_pre_tree(in,pre,n);
}
void binaryTree::in_post_to_tree(ListNode *in, ListNode *post, int n)
{
    root = in_post_tree(in, post, n);
}
