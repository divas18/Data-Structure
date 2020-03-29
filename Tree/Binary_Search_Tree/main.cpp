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
    cout << " Height : " << bst.height() << "\n";
    cout << " Width : " << bst.width() << "\n";
    cout << " Min : " << bst.minNode()->data << "\n";
    cout << " Max : " << bst.maxNode()->data << "\n";

    cout << " n = ";
    cin >> n;
    while(n)
    {
    cout << " n found at " << bst.search(n) << "\n";
    cout << " Predecessor : " << bst.predecessor(n) << "\n";
    cout << " Successor : " << bst.successor(n) << "\n";
    cout << " n = ";
    cin >> n;
}
}
