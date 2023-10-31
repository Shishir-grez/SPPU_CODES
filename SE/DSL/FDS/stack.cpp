#include <iostream>
#include <stdio.h>
#define MAX 100
using namespace std;

class stack
{
    int top;
    int data[MAX];
    public:
    stack()
    {
        top = -1;
    }

    bool is_empty()
    {
        if(top == -1)
        {
            return true;
        }
        return false;
    }

    bool is_full()
    {
        if(top == MAX - 1)
        {
            return true;
        }
        return false;
    }

    void push(int x)
    {
        if(is_empty())
        {
            top = 0;
            data[top] = x;
        }
        else
        {
            if(is_full())
            {
                cout << "Stack Overflow!!" << endl;
            }
            else
            {
                top = top + 1;
                data[top] = x;
            }
        }
    }

    void pop()
    {
        if(is_empty())
        {
            cout << "Stack Underflow!!" << endl;
        }
        else
        {
            cout << data[top] << endl;
            top--;
        }
    }
    void display()
    {
        for(int i=top;i>=0;i--)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    stack a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.display();
    a.pop();
    a.display();
    return 0;
}