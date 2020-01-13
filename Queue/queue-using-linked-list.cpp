/**
 * @Author: Aditya Kumar Singh <martian>
 * @Email:  cr7.aditya.cs@gmail.com
 * @Filename: queue-using-linked-list.cpp
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

class queue
{
private:
    node *front, *rare;
public:
    queue()
    {
        front = NULL;
        rare = NULL;
    }
    ~queue()
    {
        node *temp;
        while(front != rare)
        {
            temp = front;
            front = front->next;
            delete temp;
        }
    }
    bool isempty()
    {
        return front == NULL;
    }

    void enqueue(int x)
    {
        node *temp = new node;
        temp->data = x;
        if(front==NULL)
        {
            front = temp;
            rare = temp;
        }
        else
        {
            rare->next = temp;
            rare = temp;
        }
        cout << " Task completed.\n";
    }

    void dequeue()
    {
        if(isempty())
        {
            cout << " Queue is empty\n";
            return;
        }
        if(front == rare)
        {
            delete front;
            front = rare = NULL;
            cout << " Task completed.\n";
            return;
        }
        node *temp = front;
        front = front->next;
        delete temp;
        cout << " Task completed.\n";
    }
    void display()
    {
        if(isempty())
        {
            cout << " Queue is empty.\n";
            return;
        }
        node *temp = front;
        cout << " Queue\n :";
        while(temp)
        {
            cout << " " << temp->data;
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    queue q;
    int option,data;
    while(1)
    {
        cout << " 0.\tExit\n";
        cout << " 1.\tEnqueue\n";
        cout << " 2.\tDequeue\n";
        cout << " 3.\tIsempty\n";
        cout << " 4.\tDisplay\n";
        cout << " Enter your option : ";
        cin >> option;

        switch(option)
        {
            case 0:
                exit(0);
            case 1:
                cout << " Element to insert : ";
                cin >> data;
                q.enqueue(data);
                cout << "\n";
                break;
            case 2:
                q.dequeue();
                cout << "\n";
                break;
            case 3:
                if(q.isempty())
                    cout << " Queue is empty.\n";
                else
                    cout << " Queue is not empty.\n";
                cout << "\n";
                break;
            case 4:
                q.display();
                cout << "\n";
                break;
        }
    }
}
