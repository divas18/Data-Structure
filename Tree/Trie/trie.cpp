#include <iostream>
#define ALPHABET_SIZE 26
using namespace std;


struct Node
{
    Node * child[ALPHABET_SIZE];
    bool leaf;
    Node()
    {
        leaf = false;
        for(int i = 0; i < ALPHABET_SIZE; i++)
        {
            child[i] = NULL;
        }
    }
};

class Trie
{
private:
    Node * root_;
    void display(Node *ptr, char str[], int level);
public:
    Trie();
    void insert(string key);
    bool search(string key);
    void display();
};

int main()
{
    string keys[8] = {"the", "a", "there", "answer", "any", "by", "bye", "their" };

    int n = 8;

    Trie tree;

    for (int i = 0; i < n; i++)
        tree.insert(keys[i]);

    tree.search("a")? cout << "Yes\n" : cout << "No\n";
    tree.search("the")? cout << "Yes\n" : cout << "No\n";
    tree.search("any")? cout << "Yes\n" : cout << "No\n";
    tree.display();
    return 0;
}



Trie :: Trie()
{
    root_ = new Node;
}

void Trie :: insert(string key)
{
    Node *ptr = root_;
    int index;
    for(int i = 0; i < key.size(); i++)
    {
        index = key[i] - 'a';
        if(!ptr->child[index])
            ptr->child[index] = new Node();
        ptr = ptr->child[index];
    }
    ptr->leaf = true;
}

bool Trie :: search(string key)
{
    Node *ptr = root_;
    int index;

    for(int i = 0; i < key.size(); i++)
    {
        index = key[i] - 'a';
        if(!ptr->child[index])
            return false;
        ptr = ptr->child[index];
    }
    return ptr && ptr->leaf;
}

void Trie :: display()
{
    char str[80];
    display(root_, str, 0);
}

void Trie :: display(Node *ptr, char str[], int level)
{
    if(ptr->leaf)
    {
        str[level] = '\0';
        cout << str << "\n";
    }

    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        if(ptr->child[i])
        {
            str[level] = 'a' + i;
            display(ptr->child[i], str, level+1);
        }
    }
}
