#include "binary_search_tree.hpp"

int main()
{
    BinarySearchTree b;
    Node *temp_node;
    int key, option, n, temp;
    //List inOrder, postOrder, preOrder;
    cout << " Lets create Binary Tree using insertion\n";
    cout << " Enter 0 to stop inserting\n";
    while(1)
    {
        cout << " :";
        cin >> key;
        if(!key)
            break;
        b.insert(key);
    }

    while(1)
    {
        cout << " 0.\tExit\n";
        cout << " 1.\tInsert\n";
        cout << " 2.\tpreOrder\n";
        cout << " 3.\tinOrder\n";
        cout << " 4.\tpostOrder\n";
        cout << " 5.\tlevelOrder\n";
        cout << " 6.\tSearch\n";
        cout << " 7.\tMinvalue\n";
        cout << " 8.\tMaxValue\n";
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
                cout << " Key to search : ";
                cin >> key;
                b.search(key);
                break;
            case 7:
                temp_node = b.minValue();
                if(temp_node)
                    cout << " Minimum value : " << temp_node->data << "\n";
                else
                    cout << " Empty Tree\n";
                break;
            case 8:
                temp_node = b.maxValue();
                if(temp_node)
                    cout << " Maximum value : " << temp_node->data << "\n";
                else
                    cout << " Empty Tree\n";
                break;
            default:
                cout <<"\n";
                break;
        }
    }

}
