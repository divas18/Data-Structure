/**
 * @Author: Aditya Kumar Singh
 * @Email:  cr7.aditya.cs@gmail.com
 * @Filename: doubly-linked-list.cpp
 * @Last modified by:   Aditya Kumar Singh
 */

#include <iostream>
#include <new>
using namespace std;

struct node
{
    node *prev;
    int data;
    node * next;
};

class doublyLinkedList
{
private:
    node * head, *tail;
public:
    doublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    ~doublyLinkedList(){
            node *temp, *ptr;
            ptr = head;
            while(ptr)
            {
                temp = ptr;
                ptr = ptr->next;
                delete temp;
            }
    }
    void create_node(int info)
    {
        node *temp = new node;
        temp->data = info;
        temp->prev = NULL;
        temp->next = NULL;
    }
    void insert_at_beg(int info)
    {
        node *temp = new node;
        temp->data = info;
        temp->prev = NULL;
        temp->next = head;
        head = temp;
        if(tail == NULL)
        {
            tail = temp;
        }
    }
    void insert_at_end(int info)
    {
        node *temp, *ptr;
        if(head == NULL)
        {
            insert_at_beg(info);
            return;
        }
        ptr = head;
        while(ptr->next)
        {
            ptr = ptr->next;
        }
        temp = new node;
        temp->data = info;
        temp->prev = ptr;
        ptr->next = temp;
        temp->next = NULL;
        tail = temp;
    }
    void insert_before(int info, int info2) // info2 before which we want to insert node
    {
        if(head->data == info2)
        {
            insert_at_beg(info);
            return;
        }
        node *temp, *ptr = head->next;
        while(ptr)
        {
            if(ptr->data == info2)
            {
                temp = new node;
                temp->prev = ptr->prev;
                ptr->prev->next = temp;
                temp->data = info;
                temp->next = ptr;
                ptr->prev = temp;
                return;
            }
            ptr = ptr->next;
        }
        cout << " " << info2 << " is not present in the list\n";
    }
    void insert_after(int info, int info2)
    {
        node *temp, *ptr;
        ptr = head;
        while(ptr)
        {
            if(ptr->data == info2)
            {
                temp = new node;
                temp->prev = ptr;
                temp->data = info;
                temp->next = ptr->next;
                if(ptr->next) //when temp is not going to be last node
                {
                    ptr->next->prev = temp;
                }
                else
                {
                    tail = temp;
                }
                ptr->next = temp;
                return;
            }
            ptr = ptr->next;
        }
        cout << " " << info2 << " is not present in the list.\n";
    }
    void display()
    {
        if(head == NULL)
        {
            cout << " List is empty\n";
            return;
        }
        node *ptr = head;
        while(ptr)
        {
            cout << ptr->data <<" ";
            ptr = ptr->next;
        }
    }
    void Delete(int info)
    {
        if(!head)
        {
            cout << " List is empty.\n";
            return;
        }
        //deletion of only node
        if(head == tail)
        {
            head = NULL;
            delete tail;
            tail = NULL;
            return;
        }
        node * temp, *ptr;
        //deletion of first node
        if(head->data == info)
        {
            temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            return;
        }
        //deletion in middle and end
        ptr = head;
        while(ptr)
        {
            if(ptr->data == info)
            {
                temp = ptr;
                ptr->prev->next = ptr->next;
                if(ptr->next) //when not deleting tail
                {
                    ptr->next->prev = ptr->prev;
                }
                else
                {
                    tail = ptr->prev;
                }
                delete temp;
                return;
            }
            ptr = ptr->next;
        }
        cout << " " << info << " is not present in the list.\n";
    }
    void display_rec()
    {
        recursive_display(head);
    }
    void recursive_display(node *Node)
    {
        if(Node)
        {
            recursive_display(Node->next);
            cout << Node->data << " ";
        }
    }
    void reverse()
    {
        node *prev, *next, *ptr;
        ptr = head;
        prev = NULL;
        tail = head;
        while(ptr)
        {
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        head = prev;
        cout << " Task completed\n";
    }
};

int main()
{
    doublyLinkedList list;
    int option, info, temp;
    while(1)
    {
        cout << "\n";
        cout << " 0.\tExit\n";
        cout << " 1.\tInsert at the begining\n";
        cout << " 2.\tInsert at the end\n";
        cout << " 3.\tInsert before\n";
        cout << " 4.\tInsert after\n";
        cout << " 5.\tDisplay\n";
        cout << " 6.\tRecursive display\n";
        cout << " 7.\tDelete\n";
        cout << " 8.\tReverse\n";
        cout << "\v Enter your choice : ";
        cin >> option;
        switch(option)
        {
            case 0:
                exit(0);
            case 1:
                cout << " Enter the element to insert : ";
                cin >> info;
                list.insert_at_beg(info);
                break;
            case 2:
                cout << " Enter the element to insert : ";
                cin >> info;
                list.insert_at_end(info);
                break;
            case 3:
                cout << " Enter the element to insert : ";
                cin >> info;
                cout << " Enter the element before which you want to insert : ";
                cin >> temp;
                list.insert_before(info, temp);
                break;
            case 4:
                cout << " Enter the element to insert : ";
                cin >> info;
                cout << " Enter the element after which you want to insert : ";
                cin >> temp;
                list.insert_after(info, temp);
                break;
            case 5:
                cout << " List\n : ";
                list.display();
                cout << "\n";
                break;
            case 6:
                cout << " List in reverse\n : ";
                list.display_rec();
                cout << "\n";
                break;
            case 7:
                cout << " Enter the element to delete : ";
                cin >> info;
                list.Delete(info);
                break;
            case 8:
                list.reverse();
                break;
        }
    }
}
