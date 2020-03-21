#include <iostream>
using namespace std;

struct node
{
        node *left;
        int key;
        node *right;
        int height;
        node(int x)
        {
                left = right = NULL;
                key = x;
                height = 1;
        }
};

class AVLTree {
private:
node *root;
int height(node *leaf);
node * rightRotate(node *leaf);
node * leftRotate(node *leaf);
int getBalance(node *leaf);
node * insert(node *leaf, int key);
void preorder(node *leaf);
void postorder(node *leaf);
void inorder(node *leaf);
public:
AVLTree()
{
        root= NULL;
}
void insert(int key);
void preorder();
void postorder();
void inorder();
};

int main()
{
        AVLTree tree;
        int option, key;
        while(1)
        {
                cout << " 0.\tExit\n";
                cout << " 1.\tPreorder\n";
                cout << " 2.\tInorder\n";
                cout << " 3.\tPostorder\n";
                cout << " 4.\tInsert\n";
                cout << " Option : ";
                cin >> option;

                switch(option)
                {
                case 0:
                        exit(0);
                case 1:
                        tree.preorder();
                        break;
                case 2:
                        tree.inorder();
                        break;
                case 3:
                        tree.postorder();
                        break;
                case 4:
                        cout << " Data to insert : ";
                        cin >> key;
                        tree.insert(key);
                        break;
                }
        }
}

int AVLTree::height(node *leaf)
{
        if(!leaf)
                return 0;
        return leaf->height;
}
node * AVLTree::rightRotate(node *leaf)
{
        node *temp = leaf->left;
        leaf->left = temp->right;
        temp->right = leaf;
        leaf->height = max(height(leaf->left), height(leaf->right)) + 1;
        temp->height = max(height(temp->left), height(temp->right)) + 1;
        return temp;
}
node * AVLTree::leftRotate(node *leaf)
{
        node *temp = leaf->right;
        leaf->right = temp->left;
        temp->left = leaf;
        leaf->height = max(height(leaf->left), height(leaf->right)) + 1;
        temp->height = max(height(temp->left), height(temp->right)) + 1;
        return temp;
}
int AVLTree::getBalance(node *leaf)
{
        if(!leaf)
                return 0;
        return height(leaf->left) - height(leaf->right);
}
node * AVLTree::insert(node *leaf, int key)
{
        if(!leaf)
        {
                node *temp = new node(key);
                return temp;
        }
        if(key < leaf->key)
        {
                leaf->left = insert(leaf->left,key);
        }
        else if(key > leaf->key)
        {
                leaf->right = insert(leaf->right, key);
        }
        else
                return leaf;
        leaf->height = max(height(leaf->left), height(leaf->right)) + 1;
        int balance = getBalance(leaf);

        if(balance > 1 && key < leaf->left->key)
                return rightRotate(leaf);
        if(balance < -1 && key > leaf->right->key)
                return leftRotate(leaf);
        if(balance > 1 && key > leaf->left->key)
        {
                leaf->left = leftRotate(leaf->left);
                return rightRotate(leaf);
        }
        if(balance < -1 && key < leaf->right->key)
        {
                leaf->right = rightRotate(leaf->right);
                return leftRotate(leaf);
        }
        return leaf;
}
void AVLTree::preorder(node *leaf)
{
        if(!leaf)
                return;
        cout << leaf->key <<" ";
        preorder(leaf->left);
        preorder(leaf->right);
}
void AVLTree::postorder(node *leaf)
{
        if(!leaf)
                return;
        postorder(leaf->left);
        postorder(leaf->right);
        cout << leaf->key << " ";
}
void AVLTree::inorder(node *leaf)
{
        if(!leaf)
                return;
        inorder(leaf->left);
        cout << leaf->key << " ";
        inorder(leaf->right);
}

void AVLTree::insert(int key)
{
        root = insert(root, key);
}
void AVLTree::preorder()
{
        if(!root)
        {
                cout << " Tree is empty.\n";
                return;
        }
        cout << " Preorder:\n ";
        preorder(root);
        cout << "\n";
}
void AVLTree::postorder()
{
        if(!root)
        {
                cout << " Tree is empty.\n";
                return;
        }
        cout << " Postorder:\n ";
        postorder(root);
        cout << "\n";
}
void AVLTree::inorder()
{
        if(!root)
        {
                cout << " Tree is empty.\n";
                return;
        }
        cout << " Inorder:\n ";
        inorder(root);
        cout << "\n";
}
