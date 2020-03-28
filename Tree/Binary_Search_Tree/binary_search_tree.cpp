// Binary Tree
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//Node
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

class Binary
{
private:
    Node * root_;
    void inorder(Node *ptr);
    void preorder(Node *ptr);
    void postorder(Node *ptr);
    void insert(Node *ptr, int key);
    Node * search(Node *ptr, int key);
	int height(Node *ptr);
	Node *minNode(Node *ptr);
	Node *maxNode(Node *ptr);
	void successorAndPredecessor(Node *ptr, Node *&suc, Node *&pre, int key);
public:
    Binary();
    void inorder();
    void preorder();
    void postorder();
    void levelorder();
	void preorderNonRecursive();
	void inorderNonRecursive();
	void postorderNonRecursive();
    void insert(int key);
    Node * search(int key);
	int height();
	Node *minNode();
	Node *maxNode();
	int successor(int key);
	int predecessor(int key);
};

int main()
{
    int n;
    Binary bst;
    cout << " : ";
    cin >> n;
    while(n)
    {
        bst.insert(n);
        cout << " : ";
        cin >> n;
    }
	cout << " Height : " << bst.height() << "\n";
	//bst.inorderNonRecursive();
    bst.inorder();
	//bst.preorderNonRecursive();
    bst.preorder();
    bst.postorder();
	bst.levelorder();
	cout << "\n";
    cout << " Found 60 : " << bst.search(60) << "\n";
	Node *ptr;
	ptr = bst.minNode();
	if(ptr)
		cout << " Min Node : " << ptr << "\n Min data : " << ptr->data << "\n";
	ptr = bst.maxNode();
	if(ptr)
		cout << " Max Node : " << ptr << "\n Max data : " << ptr->data << "\n";

	cout << " successor and predecessor of n : ";
	cin >> n;
	while(n)
	{
		cout << bst.successor(n) << " " << bst.predecessor(n) << "\n";
		cout << " : ";
		cin >> n;
	}
}

Binary :: Binary()
{
    root_ = NULL;
}

void Binary :: insert(int key)
{
    if(!root_)
    {
        root_ = new Node(key);
        return;
    }
    insert(root_, key);
}

void Binary :: insert(Node *ptr, int key)
{
    if(key < ptr->data)
    {
        if(ptr->left)
            insert(ptr->left, key);
        else
            ptr->left = new Node(key);
    }
    else if(key > ptr->data)
    {
        if(ptr->right)
            insert(ptr->right, key);
        else
            ptr->right = new Node(key);
    }
}

void Binary :: inorder()
{
    if(!root_)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << "\n ---Inorder---\n :";
    inorder(root_);
    cout << "\n";
}

void Binary :: inorder(Node *ptr)
{
    if(ptr)
    {
        inorder(ptr->left);
        cout << " " << ptr->data;
        inorder(ptr->right);
    }
}

void Binary :: inorderNonRecursive()
{
	if(!root_)
	{
		cout << " Tree is empty.\n";
		return;
	}

	cout << " --- Inorder Non-Recursive---\n :";
	stack<Node *> st;
	Node *ptr = root_;

	while(ptr)
	{
		while(ptr)
		{
			if(ptr->right)
				st.push(ptr->right);
			st.push(ptr);
			ptr = ptr->left;
		}
		ptr = st.top();
		st.pop();
		while(!st.empty() && ptr->right == NULL)
		{
			cout << " " << ptr->data;
			ptr = st.top();
			st.pop();
		}

		cout << " " << ptr->data;
		if(st.empty())
			ptr = NULL;
		else
		{
			ptr = st.top();
			st.pop();
		}
	}
	cout << "\n";
}

void Binary :: preorder()
{
    if(!root_)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << "\n ---Preorder---\n :";
    preorder(root_);
    cout << "\n";
}

void Binary :: preorder(Node *ptr)
{
    if(ptr)
    {
        cout << " " << ptr->data;
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void Binary :: preorderNonRecursive()
{
	if(!root_)
	{
		cout << " Tree is empty\n";
		return;
	}
	cout << "\n ---Preorder Non-Recursive---\n : ";
	stack<Node *> st;
	st.push(root_);
	Node *ptr;

	while(!st.empty())
	{
		ptr = st.top();
		st.pop();
		cout << ptr->data << " ";
		if(ptr->right)
		st.push(ptr->right);
		if(ptr->left)
		st.push(ptr->left);
	}
	cout << "\n";
}
void Binary :: postorder()
{
    if(!root_)
    {
        cout << " Tree is empty\n";
        return;
    }
    cout << "\n ---Postorder---\n :";
    postorder(root_);
    cout << "\n";
}

void Binary :: postorder(Node *ptr)
{
    if(ptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << " " << ptr->data;
    }
}

//void postorderNonRecursive();

void Binary :: levelorder()
{
	if(!root_)
	{
		cout << " Tree is empty\n";
		return;
	}
	cout << "\n ---Levelorder---\n :";
	queue<Node *> qu;
	qu.push(root_);
	Node *ptr;

	while(!qu.empty())
	{
		ptr = qu.front();
		qu.pop();
		cout << " " << ptr->data;
		if(ptr->left)
			qu.push(ptr->left);
		if(ptr->right)
			qu.push(ptr->right);
	}
	cout << "\n";
}


Node * Binary :: search(int key)
{
    return search(root_, key);
}

Node * Binary :: search(Node *ptr, int key)
{
    if(!ptr)
        return NULL;
    if(key < ptr->data)
        return search(ptr->left, key);
    if(key > ptr->data)
        return search(ptr->right, key);
    return ptr;
}

int Binary :: height()
{
	return height(root_);
}

int Binary :: height(Node *ptr)
{
	if(!ptr)
		return 0;
	int h1 = height(ptr->left);
	int h2 = height(ptr->right);

	if(h1 < h2)
	return 1 + h2;
	return 1 + h1;
}

Node * Binary :: minNode()
{
	return minNode(root_);
}

Node * Binary :: minNode(Node *ptr)
{
	if(ptr->left)
		return minNode(ptr->left);
	return ptr;
}

Node * Binary :: maxNode()
{
	return maxNode(root_);
}

Node * Binary :: maxNode(Node *ptr)
{
	if(ptr->right)
		return maxNode(ptr->right);
	return ptr;
}

int Binary :: successor(int key)
{
	Node *succ, *pre;
	successorAndPredecessor(root_, succ, pre, key);
	return succ ? succ->data : -1;
}
int Binary :: predecessor(int key)
{
	Node *succ, *pre;
	successorAndPredecessor(root_, succ, pre, key);
	return pre ? pre->data : -1;
}

void Binary :: successorAndPredecessor(Node *ptr, Node *&suc, Node *&pre, int key)
{
	if(!ptr)
		return;

	if(ptr->data == key)
	{
		//Smallest
		if(ptr->right)
			suc = minNode(ptr->right);

		if(ptr->left)
			pre = maxNode(ptr->left);
		return;
	}

	if(ptr->data > key)
	{
		suc = ptr;
		successorAndPredecessor(ptr->left, suc, pre, key);
	}
	else
	{
		pre = ptr;
		successorAndPredecessor(ptr->right, suc, pre, key);
	}
}