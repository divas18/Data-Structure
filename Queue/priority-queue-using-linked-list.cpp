#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    int priority;
    node(int x, int y)
    {
        data = x;
        priority = y;
        next = NULL;
    }
};

class priorityQueue
{
private:
    node *front;
public:
    priorityQueue()
    {
        front = NULL;
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    void enqueue(int data, int pri)
    {
        node * temp = new node(data, pri);
        if(!front)
        {
            front = temp;
            return;
        }
        else if(front->priority < pri)
        {
            temp->next = front;
            front =temp;
            return;
        }
        node *ptr = front;
        while(ptr->next && ptr->next->priority >= pri)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout << " Queue is empty.\n";
            return;
        }
        node * temp = front;
        front = front->next;
        delete temp;
    }
    void display()
    {
        if(isEmpty())
        {
            cout << " Queue is empty.\n";
            return;
        }
        cout << " Queue : \n";
        node *ptr = front;
        while(ptr)
        {
            cout << " priority : " << ptr->priority << "\tData : " << ptr->data << "\n";
            ptr = ptr->next;
        }
    }
};

int main()
{
    priorityQueue pq;
    int op, data, priority;
    while(1)
    {
        cout << " 0.\tExit\n";
        cout << " 1.\tEnqueue\n";
        cout << " 2.\tDequque\n";
        cout << " 3.\tDisplay\n";
        cout << " Option : ";
        cin >> op;

        switch(op)
        {
            case 0:
                exit(0);
            case 1:
                cout << " Data to insert : ";
                cin >> data;
                cout << " priority : ";
                cin >> priority;
                pq.enqueue(data, priority);
                break;
            case 2:
                pq.dequeue();
                break;
            case 3:
                pq.display();
                break;
        }
    }
}
