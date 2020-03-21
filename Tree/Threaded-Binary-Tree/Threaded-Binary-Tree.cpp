#include <iostream>
#include <new>;
using namespace std;

struct node
{
    node *left;
    bool leftThread;
    int key;
    bool rightThread;
    node *right;
    node(x)
    {
        left = right = NULL;
        leftThread = rightThread = false;
        key = x;
    }
};

class TreadedBinaryTree
{
private:
    node *root;
public:
    
}

int main()
{

}
