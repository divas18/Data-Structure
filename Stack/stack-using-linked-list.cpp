/**
 * @Author: Aditya Kumar Singh <martian>
 * @Email:  cr7.aditya.cs@gmail.com
 * @Filename: stack-using-linked-list.cpp
 * @Last modified by:   martian
 */
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class stack
{
private:
    node *top;
public:
    stack()
    {
        top = NULL;
    }
    ~stack()
    {
        node *temp;
        while(top)
        {
            temp = top;
            top = top->next;
            delete temp;
        }
    }
    void push(int x)
    {
        node *temp = new node;
        temp->data = x;
        temp->next = top;
        top = temp;
    }
    void pop()
    {
        if(isempty())
        {
            cout << " Stack is empty\n";
            return;
        }
        node *temp = top;
        top = top->next;
        delete temp;
    }
    bool isempty()
    {
        return top == NULL;
    }
    void Top()
    {
        if(isempty())
        {
            cout << " Stack is empty\n";
            return;
        }
        cout << " Top element : " << top->data << "\n";
    }
    void display()
    {
        node *ptr = top;
        if(isempty())
        {
            cout << " Stack is empty\n";
            return;
        }
        cout << " Stack:\n";
        while(ptr)
        {
            cout << " " << ptr->data << "\n";
            ptr = ptr->next;
        }
    }
};


int main()
{
    stack s;
    int option, data;
    while(1)
    {
        cout << "\n";
        cout << " 0.\tExit\n";
        cout << " 1.\tPush\n";
        cout << " 2.\tPop\n";
        cout << " 3.\tIs empty\n";
        cout << " 4.\tTop element\n";
        cout << " 5.\tDisplay\n";
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
                s.Top();
                break;
            case 5:
                s.display();
                break;
        }
    }
}
