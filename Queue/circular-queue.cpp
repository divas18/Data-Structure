#include <iostream>
#include <new>
using namespace std;

class queue{
private:
    int size;
    int front, rare;
    int *array;
public:
    queue(int n)
    {
        size = n;
        front = -1, rare = -1;
        array = new int[n];
    }
    ~queue()
    {
        delete []array;
    }
    bool isFull()
    {
        return (rare + 1)%size == front;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    void enqueue(int data)
    {
        if(isFull())
        {
            cout << " Queue is full.\n";
            return;
        }
        rare = (1+rare)%size;
        array[rare] = data;
        if(isEmpty())
        {
            front++;
        }
        cout << " Task completed\n";
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout << " Queue is empty.\n";
            return;
        }
        if(front == rare)
            front = rare = -1;
        else
            front = (front + 1) % size;
        cout << " Task completed\n";
    }
    void display()
    {
        if(isEmpty())
        {
            cout << " Queue is empty.\n";
            return;
        }
        cout << " Queue\n :";
        if(front <= rare)
            for(int i = front; i <= rare; i++)
                cout << " " << array[i];
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
    cout << " Size of queue : ";
    cin >> data;
    queue  q(data);

    while(1)
    {
        cout << " 0.\tExit\n";
        cout << " 1.\tEnqueue\n";
        cout << " 2.\tDequeue\n";
        cout << " 3.\tDisplay\n";
        cout << " 4.\tisFull\n";
        cout << " 5.\tisEmpty\n";
        cout << " your option : ";
        cin >> option;

        switch(option)
        {
            case 0:
                exit(0);
            case 1:
                cout << " Data to enqeue: ";
                cin >> data;
                q.enqueue(data);
                cout << "\n";
                break;
            case 2:
                q.dequeue();
                cout << "\n";
                break;
            case 3:
                q.display();
                cout << "\n";
                break;
            case 4:
                if(q.isFull())
                    cout << " Queue is full.\n";
                else
                    cout << " Queue is not full.\n";
                cout << "\n";
                break;
            case 5:
                if(q.isEmpty())
                    cout << " Queue is empty.\n";
                else
                    cout << " Queue is not empty.\n";
                cout << "\n";
                break;
            default:
                cout << "\n";
        }
    }
}
