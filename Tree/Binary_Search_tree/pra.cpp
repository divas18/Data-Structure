#include <iostream>
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

class Tree
{
private:
    Node *root_;
    void insert(Node *ptr, int key);
    void preorder(Node *ptr);
    void postorder(Node *ptr);
    void inorder(Node *ptr);
    Node * search(Node *ptr, int key);
    Node * Delete(Node *ptr, int key);
    Node * minValueNode(Node *ptr);
public:
    Tree();
    void insert(int key);
    void preorder();
    void postorder();
    void inorder();
    Node *  search(int key);
    void Delete(int key);
    Node * minValueNode();
};

int main()
{
    int n;
    Tree binary;
    while(1)
    {
        cout << " : ";
        cin >> n;
        if(!n)
            break;
        binary.insert(n);
    }
    binary.inorder();
    binary.preorder();
    binary.postorder();
    while(1)
    {
        cout << " : ";
        cin >> n;
        if(!n)
            break;
        cout << " " << binary.search(n) << "\n";
    }

    while(1)
    {
        cout << " : ";
        cin >> n ;
        if(!n)
            break;
        binary.inorder();
        binary.Delete(n);
        binary.inorder();
    }
}

Tree :: Tree()
{
    root_ = NULL;
}

void Tree :: insert(int key)
{
    if(root_ == NULL)
    {
        root_ = new Node(key);
        cout << " Success!!!\n";
        return;
    }
    insert(root_, key);
}
void Tree :: insert(Node *ptr, int key)
{
    if(ptr->data == key)
    {
        cout << " Unsuccessful!!!\n";
    }
    if(ptr->data > key)
    {
        if(ptr->left)
            insert(ptr->left, key);
        else
        {
            Node *temp = new Node(key);
            ptr->left = temp;
            cout << " Success!!!\n";
        }
    }
    else if(ptr->data < key)
    {
        if(ptr->right)
            insert(ptr->right, key);
        else
        {
            Node *temp = new Node(key);
            ptr->right = temp;
            cout << " Success!!!\n";
        }
    }
}

void Tree :: preorder()
{
    if(!root_)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << " Preorder\n :";
    preorder(root_);
    cout << "\n\n";
}
void Tree :: postorder()
{
    if(!root_)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << " Postorder\n :";
    postorder(root_);
    cout << "\n\n";
}
void Tree :: inorder()
{
    if(!root_)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << " Inorder\n :";
    inorder(root_);
    cout << "\n\n";
}
void Tree :: preorder(Node *ptr)
{
    if(ptr)
    {
        cout << " " << ptr->data;
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void Tree :: postorder(Node *ptr)
{
    if(ptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << " " << ptr->data;
    }
}
void Tree :: inorder(Node * ptr)
{
    if(ptr)
    {
        inorder(ptr->left);
        cout << " " << ptr->data;
        inorder(ptr->right);
    }
}
Node * Tree :: search(int key)
{
    if(!root_)
    {
        cout << " Unsuccessful!!!\n";
        return NULL;
    }
    return search(root_, key);
}
Node * Tree :: search(Node *ptr, int key)
{
    if(!ptr)
    {
        cout << " Unsuccessful!!!\n";
        return NULL;
    }
    if(ptr->data == key)
    {
        cout << " Successful\n";
        return ptr;
    }
    if(ptr->data < key)
    {
        return search(ptr->right, key);
    }
    return search(ptr->left, key);
}

void Tree :: Delete(int key)
{
    if(!root_)
    {
        cout << " Unsuccessful!!!\n";
        return;
    }
    Delete(root_, key);
}

Node * Tree :: Delete(Node *ptr, int key)
{
    if(!ptr)
    {
        cout << " Unsuccessful!!!\n";
        return NULL;
    }
    if(ptr->data < key)
    {
        ptr->right = Delete(ptr->right, key);
    }
    else if(ptr->data > key)
    {
        ptr->left = Delete(ptr->left, key);
    }
    else
    {
        if(ptr->left == NULL)
        {
            Node *temp = ptr->right;
            delete ptr;
            return temp;
        }
        else if(ptr->right == NULL)
        {
            Node *temp = ptr->left;
            delete ptr;
            return temp;
        }
        Node *temp = minValueNode(ptr->right);
        ptr->data = temp->data;
        ptr->right = Delete(ptr->right, temp->data);
    }
    return ptr;
}
Node * Tree :: minValueNode()
{
    return minValueNode(root_);
}
Node * Tree :: minValueNode(Node *ptr)
{
    if(ptr->left)
        minValueNode(ptr->left);
    return ptr;
}
