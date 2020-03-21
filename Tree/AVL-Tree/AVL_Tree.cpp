#include <iostream>
using namespace std;


struct Node
{
    Node *left, *right;
    int data;
    int height;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

class AVL
{
private:
    Node *  root_;
    Node *  insert(Node *ptr, int key);
    int     height(Node *ptr);
    Node *  leftRotate(Node *ptr);
    Node *  rightRotate(Node *ptr);
    int     balanceFactor(Node *ptr);
    void    inorder(Node *ptr);
    void    preorder(Node *ptr);
    void    postorder(Node *ptr);
public:
    AVL();
    void    insert(int key);
    void    Delete(int key);
    int     height();
    void    inorder();
    void    preorder();
    void    postorder();
};

int main()
{
    AVL tree;
    int n;
    while(1)
    {
        cout << " : ";
        cin >> n;
        if(!n)
            break;
        tree.insert(n);
    }

    tree.inorder();
    tree.preorder();
    tree.postorder();
}


AVL :: AVL()
{
    root_ = NULL;
}
void AVL :: inorder()
{
    if(!root_)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << " Inorder\t: ";
    inorder(root_);
    cout << "\n\n";
}

void AVL :: inorder(Node *ptr)
{
    if(ptr)
    {
        inorder(ptr->left);
        cout << " " << ptr->data;
        inorder(ptr->right);
    }
}

void  AVL ::  preorder()
{
    if(!root_)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << " Preorder\t: ";
    preorder(root_);
    cout << "\n\n";
}
void AVL :: preorder(Node *ptr)
{
    if(ptr)
    {
        cout << " " << ptr->data;
        inorder(ptr->left);
        inorder(ptr->right);
    }
}

void  AVL ::  postorder()
{
    if(!root_)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << " Postorder\t: ";
    postorder(root_);
    cout << "\n\n";
}
void  AVL ::  postorder(Node *ptr)
{
    if(ptr)
    {
        inorder(ptr->left);
        inorder(ptr->right);
        cout << " " << ptr->data;
    }
}

int AVL :: height()
{
    return height(root_);
}

int AVL :: height(Node *ptr)
{
    if(!ptr)
        return 0;
    return ptr->height;
}

Node * AVL :: leftRotate(Node *ptr)
{
    Node *temp = ptr->right;
    ptr->right = temp->left;
    temp->left = ptr;
    return temp;
}
Node * AVL :: rightRotate(Node *ptr)
{
    Node *temp = ptr->left;
    ptr->left = temp->right;
    temp->right = ptr;
    return temp;
}

int AVL :: balanceFactor(Node *ptr)
{
    if (ptr == NULL)
    return 0;
    return height(ptr->left) - height(ptr->right);
}

void AVL :: insert(int key)
{
    root_ = insert(root_, key);
}

Node *  AVL :: insert(Node *ptr, int key)
{
    if(!ptr)
    {
        return new Node(key);
    }
    if(key < ptr->data)
        ptr->left = insert(ptr->left, key);
    else if(key > ptr->data)
        ptr->right = insert(ptr->right, key);
    else
        return ptr;


    ptr->height = 1 + max(height(ptr->left), height(ptr->right));

    int balance = balanceFactor(ptr);

    //LL Case
    if(balance > 1 && key < ptr->left->data)
        return rightRotate(ptr);

    //RR Case
    if(balance < -1 && key >  ptr->right->data)
        return leftRotate(ptr);

    //LR Case
    if(balance > 1 && key > ptr->left->data)
    {
        ptr->left = leftRotate(ptr->left);
        return rightRotate(ptr);
    }

    //RL Case
    if(balance < -1 && key < ptr->right->data)
    {
        ptr->right = rightRotate(ptr->right);
        return leftRotate(ptr);
    }

    return ptr;
}
