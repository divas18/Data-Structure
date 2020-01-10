/**
 * @Author: Aditya Kumar Singh
 * @Email:  cr7.aditya.cs@gmail.com
 * @Filename: stack-using-array.cpp
 * @Last modified by:   martian
 */
#include <iostream>
using namespace std;

class stack
{
private:
    int top;
    int size;
    int *array; //dynamic array
public:
    stack()
    {
        top = -1;
    }
    ~stack()
    {
        delete []array;
    }
    stack(int n)
    {
        top = -1;
        size = n;
        array = new int[size];
    }
    bool isempty()
    {
        return top == -1;
    }
    bool isfull()
    {
        return top == size - 1;
    }
    void push(int x)
    {
        if(isfull())
        {
            cout << " stack is full.\n";
            return;
        }
        array[++top] = x;
    }
    void pop()
    {
        if(isempty())
        {
            cout << " stack is empty.\n";
            return;
        }
        top--;
    }
    void peek(int index)
    {
        if(index < 0 || index > top)
        {
            cout << " Invalid index\n";
            return;
        }
        cout << " " << array[index] << " is at " << index <<"\n";
    }
    void display()
    {
        if(isempty())
        {
            cout << " stack is empty.\n";
            return;
        }
        cout << " stack : \n";
        for(int i = top; i >= 0; i--)
        {
            cout << " " << array[i] << "\n";
        }
    }
};

int main()
{
    int n;
    cout << " Enter the size of stack : ";
    cin >> n;
    stack s(n);
    int option, data;
    while(1)
    {
        cout << "\n";
        cout << " 0.\tExit\n";
        cout << " 1.\tPush\n";
        cout << " 2.\tPop\n";
        cout << " 3.\tIs empty\n";
        cout << " 4.\tIs full\n";
        cout << " 5.\tPeek\n";
        cout << " 6.\tDisplay\n";
        cout << " Enter your option : ";
        cin >> option;

        switch(option)
        {
            case 0:
                exit(0);
            case 1:
                cout << " Element to push : ";
                cin >> data;
                s.push(data);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                if(s.isempty())
                    cout << " stack is empty\n";
                else
                    cout << " stack is not empty\n";
                break;
            case 4:
                if(s.isfull())
                    cout << " stack is full\n";
                else
                    cout << " stack is not full\n";
                break;
            case 5:
                cout << " Index : ";
                cin >> data;
                s.peek(data);
                break;
            case 6:
                s.display();
                break;
        }
    }
}
