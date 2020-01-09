/**
 * @Author: Aditya Kumar Singh <martian>
 * @Date:   2020-01-07T16:21:20+05:30
 * @Email:  cr7.aditya.cs@gmail.com
 * @Filename: singly-linked-list.cpp
 * @Last modified by:   martian
 * @Last modified time: 2020-01-07T22:27:10+05:30
 */

/*
Topic Remaining

concatenation
Merging
Insertion sort
 */
#include <iostream>
#include <new>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

class singlyLinkedList
{
private:
    struct node * head, *tail;
public:
    singlyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    ~singlyLinkedList(){
            struct node *temp, *ptr;
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
        struct node *temp = new struct node[1];
        temp->data = info;
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
            temp = NULL;
        }
    }
    void insert_at_beg(int info)
    {
        struct node *temp = new struct node[1];
        temp->data = info;
        temp->next = head;
        head = temp;
        if(tail == NULL)
        {
            tail = temp;
        }
    }
    void insert_before(int info, int info2) // info2 before which we want to insert node
    {
        struct node *temp, *ptr;
        ptr = head;
        if(head->data == info2)
        {
            insert_at_beg(info);
            return;
        }
        while(ptr)/* code */
        {
            if(ptr->next && ptr->next->data == info2)
            {
                temp = new struct node[1];
                temp->data = info;
                temp->next = ptr->next;
                ptr->next = temp;
                return;
            }
            ptr = ptr->next;
        }
        cout << " " << info2 << " is not present in the list\n";
    }
    void insert_after(int info, int info2)
    {
        struct node *temp, *ptr;
        ptr = head;
        while(ptr)
        {
            if(ptr->data == info2)
            {
                temp = new struct node[1];
                temp->data = info;
                temp->next = ptr->next;
                ptr->next = temp;
                if(temp->next==NULL)
                {
                    tail = temp;
                }
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
        struct node *ptr = head;
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
        struct node * temp, *ptr, *p;
        //deletion of first node
        if(head->data == info)
        {
            temp = head;
            head = head->next;
            delete temp;
            return;
        }
        //deletion in middle and end
        ptr = head;
        p = NULL;
        while(ptr)
        {
            if(ptr->data == info)
            {
                p->next = ptr->next;
                delete ptr;
                if(ptr->next == NULL)
                {
                    tail = p;
                }
                return;
            }
            p = ptr;
            ptr = ptr->next;
        }
        cout << " " << info << " is not present in the list.\n";
    }
    void display_rec()
    {
        recursive_display(head);
    }
    void recursive_display(struct node *Node)
    {
        if(Node)
        {
            recursive_display(Node->next);
            cout << Node->data << " ";
        }
    }
    void reverse()
    {
        struct node *prev, *next, *ptr;
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
    }
    singlyLinkedList concatenate(singlyLinkedList list)
    {
        singlyLinkedList temp;
        temp.head = head;
        temp.tail = tail;
        temp.tail->next = list.head;
        temp.tail = list.tail;
        return temp;
    }
};

int main()
{
    int n;
    cout << " How many list you want : ";
    cin >> n;
    singlyLinkedList list[n+1];
    int option, info, temp,i;
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
        cout << " 9.\tConcatinate\n";
        cout << "\v Enter your choice : ";
        cin >> option;
        cout << " Enter the list number you want to operate : ";
        cin >> i;
        switch(option)
        {
            case 0:
                //exit(0);
                goto ab;
            case 1:
                cout << " Enter the element to insert : ";
                cin >> info;
                list[i].insert_at_beg(info);
                break;
            case 2:
                cout << " Enter the element to insert : ";
                cin >> info;
                list[i].create_node(info);
                break;
            case 3:
                cout << " Enter the element to insert : ";
                cin >> info;
                cout << " Enter the element before which you want to insert : ";
                cin >> temp;
                list[i].insert_before(info, temp);
                break;
            case 4:
                cout << " Enter the element to insert : ";
                cin >> info;
                cout << " Enter the element after which you want to insert : ";
                cin >> temp;
                list[i].insert_after(info, temp);
                break;
            case 5:
                cout << " List " << i <<"\n :";
                list[i].display();
                break;
            case 6:
                cout << " List " << i <<"\n :";
                list[i].display_rec();
                break;
            case 7:
                cout << " Enter the element to delete : ";
                cin >> info;
                list[i].Delete(info);
            case 8:
                list[i].reverse();
                break;
            case 9:
                cout << " Enter the list which you want to concatenate : ";
                cin >> temp;
                list[1].concatenate(list[temp]);
                break;
        }
    }
    ab:;
    singlyLinkedList a = list[0].concatenate(list[1]);
    a.display();
}
