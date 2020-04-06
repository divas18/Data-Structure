#include "bst.h"

void options();
void works();

int main()
{
    works();
}

void options()
{
    cout << " -------------------------------------------------------------------\n";
    cout << " 0.  Exit\n";
    cout << " 1.  Insert\n";
    cout << " 2.  Delete\n";
    cout << " 3.  Inorder Traversal\n";
    cout << " 4.  Preorder Traversal\n";
    cout << " 5.  Postorder Traversal\n";
    cout << " 6.  Levelorder Traversal\n";
    cout << " 7.  Height\n";
    cout << " 8.  Max value\n";
    cout << " 9.  Min value\n";
    cout << " 10. Search\n";
    cout << " 11. Successor\n";
    cout << " 12. Predecessor\n";
    cout << " 50. Print Option\n";
    cout << " -------------------------------------------------------------------\n";
}

void works()
{
    BinarySearchTree bst;
    options();
    int op, key;
    Node *temp;
    while(1)
    {
        cout << " Option : ";
        cin >> op;
        switch(op)
        {
            case 0:
                exit(0);
            case 1:
                cout << " Key : ";
                cin >> key;
                bst.insert(key);
                break;
            case 2:
                cout << " Key : ";
                cin >> key;
                bst.Delete(key);
                break;
            case 3:
                bst.inorder();
                break;
            case 4:
                bst.preorder();
                break;
            case 5:
                bst.postorder();
                break;
            case 6:
                bst.levelorder();
                break;
            case 7:
                cout << " Height : " << bst.height() << "\n";
                break;
            case 8:
                temp = bst.maxNode();
                temp ? cout << " Max value : " << temp->data << "\n" : cout << " Tree is empty.\n";
                break;
            case 9:
                temp = bst.minNode();
                temp ? cout << " Min value : " << temp->data << "\n" : cout << " Tree is empty.\n";
                break;
            case 10:
                cout << " Key : ";
                cin >> key;
                temp = bst.search(key);
                temp ? cout << " " << key << " found at memory location " << temp << "\n":cout << " Tree is empty.\n";
                break;
            case 11:
                cout << " Key : ";
                cin >> key;
                temp = bst.successor(key);
                temp ? cout << " Successor of " << key << " : " << temp->data << "\n" : cout << " Tree is empty or successor does not exit\n";
                break;
            case 12:
                cout << " Key : ";
                cin >> key;
                temp = bst.predecessor(key);
                temp ? cout << " Predecessor of " << key << " : " << temp->data << "\n" : cout << " Tree is empty or predecessor does not exit\n";
                break;
            case 50:
            default:
                options();
                break;
        }
    }
}
