#include "bst.h"

int main()
{
    BinarySearchTree bst;
    int n;
    cout << " : ";
    cin >> n;
    while(n)
    {
        bst.insert(n);
        cout << " : ";
        cin >> n;
    }
    bst.inorder();
    bst.preorder();
    bst.postorder();
    bst.levelorder();
    cout << bst.height() << "\n";
    cout << bst.minNode()->data << "\n";
    cout << bst.maxNode()->data << "\n";
    cout << bst.search(20) << "\n";
}
