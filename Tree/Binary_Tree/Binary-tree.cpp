#include "Binary-tree.hpp"

int main()
{
    BinaryTree b;
    int key, option, n, temp;
    //List inOrder, postOrder, preOrder;
    cout << " Lets create Binary Tree\n";
    cout << " 1.\tUsing insertion (BST will be created)\n";
    cout << " 2.\tUsing preOrder and inOrder\n";
    cout << " 3.\tUsing postOrder and inOrder\n";
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
        /*case 2:
            cout << " Size of tree : ";
            cin >> n;
            cout << " Enter inOrder\n :";
            for(int i = 0; i < n; i++)
            {
                cin >> temp;
                inOrder.create(temp);
            }
            cout << " Enter preOrder\n :";
            for(int i = 0; i < n; i++)
            {
                cin >> temp;
                preOrder.create(temp);
            }
            b.in_pre_to_tree(inOrder.head, preOrder.head, n);
            break;
        case 3:
            cout << " Size of tree : ";
            cin >> n;
            cout << " Enter inOrder\n :";
            for(int i = 0; i < n; i++)
            {
                cin >> temp;
                inOrder.create(temp);
            }
            cout << " Enter postOrder\n :";
            for(int i = 0; i < n; i++)
            {
                cin >> temp;
                postOrder.create(temp);
            }
            b.in_post_to_tree(inOrder.head, postOrder.head, n);
            break;*/
    }
    while(1)
    {
        cout << " 0.\tExit\n";
        cout << " 1.\tInsert\n";
        cout << " 2.\tpreOrder\n";
        cout << " 3.\tinOrder\n";
        cout << " 4.\tpostOrder\n";
        cout << " 5.\tlevelOrder\n";
        cout << " 6.\tNon Recursive Inorder\n";
        cout << " 7.\tNon Recursive Preorder\n";
        cout << " 8.\tNon Recursive Postorder\n";
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
                b.preOrder();
                cout << "\n";
                break;
            case 3:
                b.inOrder();
                cout << "\n";
                break;
            case 4:
                b.postOrder();
                cout <<"\n";
                break;
            case 5:
                b.levelOrder();
                cout << "\n";
                break;
            case 6:
                b.nonRecInOrder();
                cout << "\n";
                break;
            case 7:
                b.nonRecPreOrder();
                cout << "\n";
                break;
            case 8:
                b.nonRecPostOrder();
                cout << "\n";
                break;
            default:
                cout <<"\n";
                break;
        }
    }

}
