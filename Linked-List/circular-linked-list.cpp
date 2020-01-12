/**
 * @Author: Aditya Kumar Singh <martian>
 * @Email:  cr7.aditya.cs@gmail.com
 * @Filename: circular-linked-list.cpp
 * @Last modified by:   martian
 */
#include <iostream>
#include <new>
using namespace std;

struct node
{
    int data;
    node *next;
};

class circularLinkedList
{
private:
    node *head;
public:
    circularLinkedList()
    {
        head = NULL;
    }
    ~circularLinkedList(){};
    void insert(int x)
    {
        node *temp = new node;
        temp->data = x;
        if(head == NULL)
        {
            temp->next = temp;
            head = temp;
            return;
        }
        temp->next = head->next;
        head->next = temp;
        head = temp;
    }
    void insert_before(int x, int info)
    {
        node *ptr = head;
        do
        {
            if(ptr->next->data == info)
            {
                node *temp = new node;
                temp->data = x;
                temp->next = ptr->next;
                ptr->next = temp;
                return;
            }
            ptr = ptr->next;
        } while(ptr != head);
        cout << " " << info << " is not present in the list.\n";
    }
    void insert_after(int x, int info)
    {
        node *ptr = head;
        do
        {
            if(ptr->data == info)
            {
                node *temp = new node;
                temp->data = x;
                temp->next = ptr->next;
                ptr->next = temp;
                if(ptr == head)
                {
                    head = temp;
                }
                return;
            }
            ptr = ptr->next;
        }while(ptr != head);
        cout << " " << info << " is not present in the list.\n";
    }
    void Delete(int x)
    {
        if(!head)
        {
            cout << " List is empty.\n";
            return;
        }
        if(head->data == x && head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }
        node *ptr = head, *temp;
        do
        {
            if(ptr->next->data == x)
            {
                temp = ptr->next;
                ptr->next = temp->next;
                if(temp == head)
                {
                    head = ptr;
                }
                delete temp;
                return;
            }
            ptr = ptr->next;
        }while(ptr != head);
        cout << " " << x << " is not present in the list.\n";
    }
    void reverse()
    {
        if(!head)
        {
            cout << " List is empty.\n";
            return;
        }
        if(head->next==head)
        {
            return;
        }
        head = head->next;
        node *ptr, *prev, *next;
        ptr = head->next;
        prev = head;
        while(ptr != head)
        {
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        head->next = prev;
        cout << " Done\n";
    }
    void display()
    {
        if(!head)
        {
            cout << " List is empty.\n";
            return;
        }
        cout << " List\n :";
        node * ptr = head->next;
        while(ptr != head)
        {
            cout << " " << ptr->data;
            ptr = ptr->next;
        }
        cout << " " << head->data << "\n";
    }
};


int main()
{
    circularLinkedList list;
    int option, info, temp;
    while(1)
    {
        cout << "\n";
        cout << " 0.\tExit\n";
        cout << " 1.\tInsert\n";
        cout << " 2.\tInsert before\n";
        cout << " 3.\tInsert after\n";
        cout << " 4.\tDisplay\n";
        cout << " 5.\tDelete\n";
        cout << " 6.\tReverse\n";
        cout << "\v Enter your choice : ";
        cin >> option;
        switch(option)
        {
            case 0:
                exit(0);
            case 1:
                cout << " Enter the element to insert : ";
                cin >> info;
                list.insert(info);
                break;
            case 2:
                cout << " Enter the element to insert : ";
                cin >> info;
                cout << " Enter the element before which you want to insert : ";
                cin >> temp;
                list.insert_before(info, temp);
                break;
            case 3:
                cout << " Enter the element to insert : ";
                cin >> info;
                cout << " Enter the element after which you want to insert : ";
                cin >> temp;
                list.insert_after(info, temp);
                break;
            case 4:
                list.display();
                break;
            case 5:
                cout << " Enter the element to delete : ";
                cin >> info;
                list.Delete(info);
                break;
            case 6:
                list.reverse();
                break;
        }
    }
}
