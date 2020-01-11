/**
 * @Author: Aditya Kumar Singh <martian>
 * @Email:  cr7.aditya.cs@gmail.com
 * @Filename: queue-using-array.cpp
 * @Last modified by:   martian
 */
#include <iostream>
using namespace std;

class queue
{
private:
    int front;
    int rare;
    int size;
    int *array; //dynamic array
public:
    queue(){}
    ~queue()
    {
        delete []array;
    }
    queue(int n)
    {
        front = -1;
        rare = -1;
        size = n;
        array = new int[size];
    }
    bool isEmpty()
    {
        return rare == -1;
    }
    bool isFull()
    {
        return rare == size-1;
    }
    void enqueue(int data)
    {
        if(isFull())
        {
            cout << " Queue is full.\n";
            return;
        }
        if(isEmpty())
        {
            front++;
            array[++rare] = data;
            return;
        }
        array[++rare] = data;
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout << " queue is empty\n";
            return;
        }
        int x = array[front];
        if(rare == front)
        {
            rare = -1;
            front = -1;
        }
        else
        {
            front++;
        }
        cout << " " << x << " is dequeued\n";
    }
    void display()
    {
        if(isEmpty())
        {
            cout << " Queue is empty.\n";
            return;
        }
        cout << " Queue\n :";
        for(int i = front; i <= rare; i++)
        {
            cout << " " << array[i];
        }
        cout << "\n";
    }
};

int main()
{
    int n;
    cout << " Enter the size of queue : ";
    cin >> n;
    queue q(n);
    int option, data;
    while(1)
    {
        cout << " 0.\tExit\n";
        cout << " 1.\tEnqueue\n";
        cout << " 2.\tDequeue\n";
        cout << " 3.\tisFull\n";
        cout << " 4.\tisEmpty\n";
        cout << " 5.\tDisplay\n";
        cout << " Enter your choice : ";
        cin >> option;

        switch(option)
        {
            case 0:
                exit(0);
            case 1:
                cout << " Enter the element to enqueue : ";
                cin >> data;
                q.enqueue(data);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                if(q.isFull())
                    cout << " Queue is full.\n";
                else
                    cout << " Queue is not full\n";
                break;
            case 4:
                if(q.isEmpty())
                    cout << " Queue is empty.\n";
                else
                    cout << " Queue is not empty.\n";
                break;
            case 5:
                q.display();
                break;
        }
    }
}
