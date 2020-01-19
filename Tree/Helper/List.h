#ifndef List_h
#define List_h
#include <iostream>
#include <new>
using namespace std;

struct ListNode
{
    int data;
    ListNode * next;
};

class List
{
public:
    ListNode * head, *tail;
    List()
    {
        head = NULL;
        tail = NULL;
    }
    ~List(){
            ListNode *temp, *ptr;
            ptr = head;
            while(ptr)
            {
                temp = ptr;
                ptr = ptr->next;
                delete temp;
            }
    }
    void create(int data)
    {
        ListNode *temp = new ListNode;
        temp->data = data;
        temp->next = NULL;
        if(head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void display()
    {
        if(head == NULL)
        {
            cout << " List is empty\n";
            return;
        }
        ListNode *ptr = head;
        while(ptr)
        {
            cout << ptr->data <<" ";
            ptr = ptr->next;
        }
    }
};
#endif
