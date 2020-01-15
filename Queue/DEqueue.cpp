/**
 * @Author: Aditya Kumar Singh <martian>
 * @Email:  cr7.aditya.cs@gmail.com
 * @Filename: DEqueue.cpp
 * @Last modified by:   martian
 */


#include <iostream>
#include <new>
using namespace std;

struct queue
{
private:
    int size;
    int rare, front;
    int *array;
public:
    queue(int size)
    {
        this->size = size;
        rare = front = -1;
        array = new int[size];
    }
    ~queue()
    {
        delete []array;
    }
    bool isFull()
    {
        return (rare+1)%size == front;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    void add_at_front(int data)
    {
        if(isFull())
        {
            cout << " Queue is full.\n";
            return;
        }
        if(front == -1)
            front = 0, rare = 0;
        else if(front == 0)
            front = size - 1;
        else
            front--;
        array[front] = data;
        cout << " Task completed\n";
    }
    void add_at_rare(int data)
    {
        if(isFull())
        {
            cout << " Queue is full.\n";
            return;
        }
        if(rare == -1)
            rare = 0, front = 0;
        else
            rare = (rare + 1) % size;
        array[rare] = data;
        cout << " Task completed\n";
    }
    void delete_from_front()
    {
        if(isEmpty())
        {
            cout << " Queue is empty.\n";
            return;
        }
        cout << " " << array[front] << " dequeued\n";
        if(front==rare)
            front = rare = -1;
        else
            front = (front+1)%size;
    }
    void delete_from_rare()
    {
        if(isEmpty())
        {
            cout << " Queue is empty.\n";
            return;
        }
        cout << " " << array[rare] << " dequeued\n";
        if(front == rare)
            front = rare = -1;
        else if(rare == 0)
            rare = size-1;
        else
            rare--;
    }
    void display()
    {
        if(isEmpty())
        {
            cout << " Queue is empty.\n";
            return;
        }
        cout << " Queue\n : ";
        if(front <= rare)
        {
            for(int i = front; i <= rare; i++)
                cout << " " << array[i];
        }
        else
        {
            for(int i = front; i < size; i++)
                cout << " " << array[i];
            for(int i = 0; i <= rare; i++)
                cout << " " << array[i];
        }
        cout << "\n";
    }
};

int main()
{
    int option, data;
    cout << " Queue size : ";
    cin >> data;
    queue q(data);
    while(1)
    {
        cout << " 0.\tExit\n";
        cout << " 1.\tAdd at front\n";
        cout << " 2.\tAdd at rare\n";
        cout << " 3.\tdisplay\n";
        cout << " 4.\tDelete from front\n";
        cout << " 5.\tDelete from rare\n";
        cout << " 6.\tis Full\n";
        cout << " 7.\tis Empty\n";
        cout << " your option : ";
        cin >> option;

        switch(option)
        {
            case 0:
                exit(0);
            case 1:
                cout << " data to insert : ";
                cin >> data;
                q.add_at_front(data);
                cout << "\n";
                break;
            case 2:
                cout << " data to insert : ";
                cin >> data;
                q.add_at_rare(data);
                cout << "\n";
                break;
            case 3:
                q.display();
                cout << "\n";
                break;
            case 4:
                q.delete_from_front();
                cout << "\n";
                break;
            case 5:
                q.delete_from_rare();
                cout << "\n";
                break;
            case 6:
                if(q.isFull())
                    cout << " Queue is full.\n";
                else
                    cout << " Queue is not full.\n";
                cout << "\n";
                break;
            case 7:
                if(q.isEmpty())
                    cout << " Queue is empty.\n";
                else
                    cout << " Queue is not empty\n";
                cout << "\n";
                break;
            default:
                cout << "\n";
        }
    }
}
