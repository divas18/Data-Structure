/**
 * @Author: Aditya Kumar Singh
 * @Email:  cr7.aditya.cs@gmail.com
 * @Filename: doubly-linked-list.cpp
 * @Last modified by:   martian
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
    void insert_at_beg(int info)
    {
        node *temp = new node;
        temp->data = info;
        temp->prev = NULL;
        if(head == NULL)
        {
            temp->next = NULL;
            tail = temp;
            head = temp;

            return;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
        
    }
    void insert_at_end(int info)
    {
        if(head == NULL)
        {
            insert_at_beg(info);
            return;
        }
        node *temp = new node;
        temp->data =  info;
        temp->prev = tail;
        tail->next = temp;
        temp->next = NULL;
        tail = temp;

    }
    void insert_before(int info, int info2)
    {
        node *ptr = head, *temp;
        if(head->data == info2)
        {
            insert_at_beg(info);
            return;
        }
        while(ptr)
        {
            if(ptr->data == info2)
            {
                temp = new node;
                temp->data = info;
                ptr->prev->next = temp;
                temp->prev = ptr->prev;
                temp->next = ptr;
                ptr->prev = temp;

                return;
            }
            ptr = ptr->next;
        }
        cout << " " << info2 << " is not present in the list.\n";
    }
    void insert_after(int info, int info2)
    {
        node *temp, *ptr = head;
        while(ptr)
        {
            if(ptr->data == info2)
            {
                temp = new node;
                temp->data = info;
                temp->prev = ptr;
                temp->next = ptr->next;
                if(ptr->next)
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
        cout << " " << info2 << " is not present in list.\n";
    }
    void display()
    {
        node *ptr = head;
        while(ptr)
        {
            cout <<  ptr->data << " ";
            ptr = ptr->next;
        }
    }
    void display_rec()
    {
        recursive_display(head);
    }
    void recursive_display(node *ptr)
    {
        if(ptr)
        {
            recursive_display(ptr->next);
            cout << " " << ptr->data;
        }
    }
    void Delete(int info)
    {
        if(head==NULL)
        {
            cout << " List is empty.\n";
            return;
        }
        if(head->data == info && head->next == NULL)//deletion of only node
        {
            free(head);
            head = NULL;
            tail = NULL;

            return;
        }
        node *ptr;
        if(head->data == info)//deletion of first node
        {
            ptr = head;
            head = head->next;
            head->prev = NULL;
            delete ptr;

            return;
        }
        ptr = head;
        while(ptr->next)
        {
            if(ptr->data == info)
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                delete ptr;

                return;
            }
            ptr = ptr->next;
        }
        if(ptr->data == info)
        {
            ptr->prev->next = NULL;
            tail = ptr->prev;
            delete ptr;

            return;
        }
        cout << " " << info << " is not present in List.\n";
    }
    void reverse()
    {
        node *p , *q;
        p = head;
        tail = head;
        while(p)
        {
            if(p->next == NULL)
            {
                head = p;
            }
            q = p->next;
            p->next = p->prev;
            p->prev = q;
            p = q;
        }

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
                cout << " List in reverse\n :";
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
